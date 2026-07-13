/**
 * @file port.cpp
 * @author Sergio Hidalgo (sergiohg.dev@gmail.com)
 * @brief Test file for the port logic
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 * @copyright Copyright (c) Sergio Hidalgo 2026
 */
#include <gtest/gtest.h>

extern "C" {
#include <rtsyn/value.h>

#include "rtsyn/port.h"
#include "rtsyn/port/descriptor.h"
}

class PortTest : public ::testing::Test {
  protected:
    void
    SetUp() override
    {
    }

    void
    TearDown() override
    {
    }
};

TEST_F(PortTest, Createport)
{
    rtsyn_abi_port_descriptor_t descriptor;
    EXPECT_TRUE(rtsyn_port_descriptor_set(&descriptor, "port", RTSYN_ABI_VALUE_F64,
                                          RTSYN_ABI_PORT_DIRECTION_OUT));
    rtsyn_port_t *port = rtsyn_port_create(&descriptor, 0);

    ASSERT_NE(port, nullptr);

    rtsyn_port_destroy(port);
}

TEST_F(PortTest, CheckCoherenceDouble)
{
    rtsyn_abi_port_descriptor_t descriptor;
    EXPECT_TRUE(rtsyn_port_descriptor_set(&descriptor, "port", RTSYN_ABI_VALUE_F64,
                                          RTSYN_ABI_PORT_DIRECTION_OUT));
    rtsyn_port_t *port = rtsyn_port_create(&descriptor, 0);

    ASSERT_NE(port, nullptr);

    double value = 0.34;

    EXPECT_TRUE(rtsyn_port_set_internal_value_by_ptr(port, &value));

    double out;

    ASSERT_TRUE(rtsyn_value_get(rtsyn_port_get_internal_value(port), &out));
    EXPECT_EQ(out, value);

    rtsyn_port_destroy(port);
}

TEST_F(PortTest, CheckCoherenceFloat)
{
    rtsyn_abi_port_descriptor_t descriptor;
    EXPECT_TRUE(rtsyn_port_descriptor_set(&descriptor, "port", RTSYN_ABI_VALUE_F32,
                                          RTSYN_ABI_PORT_DIRECTION_OUT));
    rtsyn_port_t *port = rtsyn_port_create(&descriptor, 0);

    ASSERT_NE(port, nullptr);

    float value = 0.34;

    EXPECT_TRUE(rtsyn_port_set_internal_value_by_ptr(port, &value));

    float out;

    ASSERT_TRUE(rtsyn_value_get(rtsyn_port_get_internal_value(port), &out));
    EXPECT_EQ(out, value);

    rtsyn_port_destroy(port);
}

TEST_F(PortTest, CheckCoherenceInt)
{
    rtsyn_abi_port_descriptor_t descriptor;
    EXPECT_TRUE(rtsyn_port_descriptor_set(&descriptor, "port", RTSYN_ABI_VALUE_I64,
                                          RTSYN_ABI_PORT_DIRECTION_OUT));
    rtsyn_port_t *port = rtsyn_port_create(&descriptor, 0);

    ASSERT_NE(port, nullptr);

    int value = -9;

    EXPECT_TRUE(rtsyn_port_set_internal_value_by_ptr(port, &value));

    int out;
    ASSERT_TRUE(rtsyn_value_get(rtsyn_port_get_internal_value(port), &out));
    EXPECT_EQ(out, value);

    value = 10;

    rtsyn_port_set_internal_value_by_ptr(port, &value);

    ASSERT_TRUE(rtsyn_value_get(rtsyn_port_get_internal_value(port), &out));
    EXPECT_EQ(out, value);

    rtsyn_port_destroy(port);
}

TEST_F(PortTest, CheckCoherenceUInt)
{
    rtsyn_abi_port_descriptor_t descriptor;
    rtsyn_port_descriptor_set(&descriptor, "port", RTSYN_ABI_VALUE_U64,
                              RTSYN_ABI_PORT_DIRECTION_OUT);
    rtsyn_port_t *port = rtsyn_port_create(&descriptor, 0);

    ASSERT_NE(port, nullptr);

    uint64_t value = 8;

    EXPECT_TRUE(rtsyn_port_set_internal_value_by_ptr(port, &value));

    uint64_t out;

    ASSERT_TRUE(rtsyn_value_get(rtsyn_port_get_internal_value(port), &out));
    EXPECT_EQ(out, value);

    rtsyn_port_destroy(port);
}

TEST_F(PortTest, CheckByPtrRejectNullPtr)
{
    rtsyn_abi_port_descriptor_t descriptor;
    EXPECT_TRUE(rtsyn_port_descriptor_set(&descriptor, "port", RTSYN_ABI_VALUE_STRING,
                                          RTSYN_ABI_PORT_DIRECTION_OUT));
    rtsyn_port_t *port = rtsyn_port_create(&descriptor, 0);

    ASSERT_NE(port, nullptr);

    EXPECT_FALSE(rtsyn_port_set_internal_value_by_ptr(port, nullptr));

    rtsyn_port_destroy(port);
}

TEST_F(PortTest, CheckByValueRejectDifferentValueType)
{
    rtsyn_abi_port_descriptor_t descriptor;
    EXPECT_TRUE(rtsyn_port_descriptor_set(&descriptor, "port", RTSYN_ABI_VALUE_STRING,
                                          RTSYN_ABI_PORT_DIRECTION_OUT));
    rtsyn_port_t *port = rtsyn_port_create(&descriptor, 0);

    ASSERT_NE(port, nullptr);

    rtsyn_value_t *value_float = rtsyn_value_create(RTSYN_ABI_VALUE_F32);

    ASSERT_NE(value_float, nullptr);

    EXPECT_FALSE(rtsyn_port_set_internal_value_by_value(port, value_float));

    rtsyn_value_destroy(value_float);
    rtsyn_port_destroy(port);
}
