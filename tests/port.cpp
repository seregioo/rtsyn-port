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
#include "rtsyn/port.h"
#include "rtsyn/port/spec.h"
#include "rtsyn/port/value.h"
#include "rtsyn/port/value/double.h"
#include "rtsyn/port/value/float.h"
#include "rtsyn/port/value/int.h"
#include "rtsyn/port/value/str.h"
#include "rtsyn/port/value/uint.h"
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
    rtsyn_port_spec_t port_spec = {"port", RTSYN_PORT_VALUE_DOUBLE};
    rtsyn_port_t *port = rtsyn_port_create(&port_spec, RTSYN_PORT_DIRECTION_OUT, 0);

    ASSERT_NE(port, nullptr);

    rtsyn_port_destroy(port);
}

TEST_F(PortTest, CheckCoherenceDouble)
{
    rtsyn_port_spec_t port_spec;
    rtsyn_port_spec_set(&port_spec, "port", RTSYN_PORT_VALUE_DOUBLE);
    rtsyn_port_t *port = rtsyn_port_create(&port_spec, RTSYN_PORT_DIRECTION_OUT, 0);

    ASSERT_NE(port, nullptr);

    double value = 0.34;

    rtsyn_port_set_internal_value_by_ptr(port, &value);

    double out;

    ASSERT_TRUE(rtsyn_port_value_double_get(rtsyn_port_get_internal_value(port), &out));
    EXPECT_EQ(out, value);

    rtsyn_port_destroy(port);
}

TEST_F(PortTest, CheckCoherenceFloat)
{
    rtsyn_port_spec_t port_spec;
    rtsyn_port_spec_set(&port_spec, "port", RTSYN_PORT_VALUE_FLOAT);
    rtsyn_port_t *port = rtsyn_port_create(&port_spec, RTSYN_PORT_DIRECTION_OUT, 0);

    ASSERT_NE(port, nullptr);

    float value = 0.34;

    rtsyn_port_set_internal_value_by_ptr(port, &value);

    float out;

    ASSERT_TRUE(rtsyn_port_value_float_get(rtsyn_port_get_internal_value(port), &out));
    EXPECT_EQ(out, value);

    rtsyn_port_destroy(port);
}

TEST_F(PortTest, CheckCoherenceInt)
{
    rtsyn_port_spec_t port_spec;
    rtsyn_port_spec_set(&port_spec, "port", RTSYN_PORT_VALUE_INT);
    rtsyn_port_t *port = rtsyn_port_create(&port_spec, RTSYN_PORT_DIRECTION_OUT, 0);

    ASSERT_NE(port, nullptr);

    int value = -9;

    rtsyn_port_set_internal_value_by_ptr(port, &value);

    int out;
    ASSERT_TRUE(rtsyn_port_value_int_get(rtsyn_port_get_internal_value(port), &out));
    EXPECT_EQ(out, value);

    value = 10;

    rtsyn_port_set_internal_value_by_ptr(port, &value);

    ASSERT_TRUE(rtsyn_port_value_int_get(rtsyn_port_get_internal_value(port), &out));
    EXPECT_EQ(out, value);

    rtsyn_port_destroy(port);
}

TEST_F(PortTest, CheckCoherenceUInt)
{
    rtsyn_port_spec_t port_spec;
    rtsyn_port_spec_set(&port_spec, "port", RTSYN_PORT_VALUE_UINT);
    rtsyn_port_t *port = rtsyn_port_create(&port_spec, RTSYN_PORT_DIRECTION_OUT, 0);

    ASSERT_NE(port, nullptr);

    uint64_t value = 8;

    rtsyn_port_set_internal_value_by_ptr(port, &value);

    uint64_t out;

    ASSERT_TRUE(rtsyn_port_value_uint_get(rtsyn_port_get_internal_value(port), &out));
    EXPECT_EQ(out, value);

    rtsyn_port_destroy(port);
}

TEST_F(PortTest, CheckByPtrRejectNullPtr)
{
    rtsyn_port_spec_t port_spec;
    rtsyn_port_spec_set(&port_spec, "port", RTSYN_PORT_VALUE_STR);
    rtsyn_port_t *port = rtsyn_port_create(&port_spec, RTSYN_PORT_DIRECTION_OUT, 0);

    ASSERT_NE(port, nullptr);

    EXPECT_FALSE(rtsyn_port_set_internal_value_by_ptr(port, nullptr));

    rtsyn_port_destroy(port);
}

TEST_F(PortTest, CheckByValueRejectDifferentValueType)
{
    rtsyn_port_spec_t port_spec;
    rtsyn_port_spec_set(&port_spec, "port", RTSYN_PORT_VALUE_STR);
    rtsyn_port_t *port = rtsyn_port_create(&port_spec, RTSYN_PORT_DIRECTION_OUT, 0);

    ASSERT_NE(port, nullptr);

    rtsyn_port_value_t *value_float = rtsyn_port_value_create_float();

    EXPECT_FALSE(rtsyn_port_set_internal_value_by_value(port, value_float));

    rtsyn_port_value_destroy(value_float);
    rtsyn_port_destroy(port);
}
