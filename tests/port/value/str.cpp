/**
 * @file port.cpp
 * @author Sergio Hidalgo (sergiohg.dev@gmail.com)
 * @brief Test file for the port value str logic
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 * @copyright Copyright (c) Sergio Hidalgo 2026
 */
#include <gtest/gtest.h>

extern "C" {
#include "rtsyn/port.h"
#include "rtsyn/port/spec.h"
#include "rtsyn/port/value/str.h"
}

class PortValueStrTest : public ::testing::Test {
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

TEST_F(PortValueStrTest, CheckCoherence)
{
    rtsyn_port_spec_t port_spec;
    rtsyn_port_spec_set(&port_spec, "port", RTSYN_PORT_VALUE_STR);
    rtsyn_port_t *port = rtsyn_port_create(&port_spec, RTSYN_PORT_DIRECTION_OUT, 0);

    ASSERT_NE(port, nullptr);

    const char *value = "hi";

    rtsyn_port_set_internal_value_by_ptr(port, (void *)value);

    char out[RTSYN_PORT_VALUE_STRING_MAX_SIZE] = {0};

    ASSERT_TRUE(rtsyn_port_value_str_get(rtsyn_port_get_internal_value(port), out));
    EXPECT_STREQ(out, value);

    rtsyn_port_destroy(port);
}

TEST_F(PortValueStrTest, CheckByValueCorrectness)
{
    rtsyn_port_spec_t port_spec = {"port", RTSYN_PORT_VALUE_STR};
    rtsyn_port_t *port = rtsyn_port_create(&port_spec, RTSYN_PORT_DIRECTION_OUT, 0);

    ASSERT_NE(port, nullptr);

    const char *value = "hi";
    rtsyn_port_value_t *port_value = rtsyn_port_value_create_str();

    ASSERT_NE(port_value, nullptr);

    EXPECT_TRUE(rtsyn_port_value_set(port_value, (void *)value));

    EXPECT_TRUE(rtsyn_port_set_internal_value_by_value(port, port_value));

    char out[RTSYN_PORT_VALUE_STRING_MAX_SIZE] = {0};

    const rtsyn_port_value_t *port_internal_value = rtsyn_port_get_internal_value(port);
    ASSERT_NE(port_internal_value, nullptr);
    EXPECT_TRUE(rtsyn_port_value_get(port_internal_value, (void *)&out));

    EXPECT_STREQ(value, out);

    EXPECT_TRUE(rtsyn_port_value_get(port_value, (void *)out));

    EXPECT_STREQ(value, out);

    rtsyn_port_value_destroy(port_value);
    rtsyn_port_destroy(port);
}
