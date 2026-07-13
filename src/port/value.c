/**
 * @file port/value.c
 * @author Sergio Hidalgo (sergiohg.dev@gmail.com)
 * @brief Compile unit for the RTSyn Runtime Port Value
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 * @copyright Copyright (c) Sergio Hidalgo 2026
 */
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#include "rtsyn/internal/port/value.h"
#include "rtsyn/internal/port/value/double.h"
#include "rtsyn/internal/port/value/float.h"
#include "rtsyn/internal/port/value/int.h"
#include "rtsyn/internal/port/value/str.h"
#include "rtsyn/internal/port/value/uint.h"

static const rtsyn_port_value_initializer_t
    RTSYN_PORT_VALUE_INITIALIZER_TABLE[RTSYN_PORT_VALUE_COUNT] = {
        RTSYN_PORT_VALUE_INITIALIZER_TBL_ENTRY(
            RTSYN_PORT_VALUE_FLOAT, rtsyn_port_value_float_create, rtsyn_port_value_float_destroy,
            rtsyn_port_value_float_get, rtsyn_port_value_float_size_get,
            rtsyn_port_value_float_set),
        RTSYN_PORT_VALUE_INITIALIZER_TBL_ENTRY(
            RTSYN_PORT_VALUE_DOUBLE, rtsyn_port_value_double_create,
            rtsyn_port_value_double_destroy, rtsyn_port_value_double_get,
            rtsyn_port_value_double_size_get, rtsyn_port_value_double_set),
        RTSYN_PORT_VALUE_INITIALIZER_TBL_ENTRY(
            RTSYN_PORT_VALUE_INT, rtsyn_port_value_int_create, rtsyn_port_value_int_destroy,
            rtsyn_port_value_int_get, rtsyn_port_value_int_size_get, rtsyn_port_value_int_set),
        RTSYN_PORT_VALUE_INITIALIZER_TBL_ENTRY(
            RTSYN_PORT_VALUE_UINT, rtsyn_port_value_uint_create, rtsyn_port_value_uint_destroy,
            rtsyn_port_value_uint_get, rtsyn_port_value_uint_size_get, rtsyn_port_value_uint_set),
        RTSYN_PORT_VALUE_INITIALIZER_TBL_ENTRY(
            RTSYN_PORT_VALUE_STR, rtsyn_port_value_str_create, rtsyn_port_value_str_destroy,
            rtsyn_port_value_str_get, rtsyn_port_value_str_size_get, rtsyn_port_value_str_set),
};

rtsyn_port_value_t *
rtsyn_port_value_create(rtsyn_port_value_type_t value_type)
{
    rtsyn_port_value_t *port_value = (rtsyn_port_value_t *)malloc(sizeof(rtsyn_port_value_t));

    if (!port_value || rtsyn_port_value_validate_type(value_type) == RTSYN_PORT_VALUE_INVALID)
    {
        return nullptr;
    }

    port_value->value_type = value_type;

    port_value->value_data = RTSYN_PORT_VALUE_INITIALIZER_TABLE[value_type].data_constructor();
    port_value->data_destructor = RTSYN_PORT_VALUE_INITIALIZER_TABLE[value_type].data_destructor;
    port_value->data_setter = RTSYN_PORT_VALUE_INITIALIZER_TABLE[value_type].data_setter;
    port_value->data_getter = RTSYN_PORT_VALUE_INITIALIZER_TABLE[value_type].data_getter;
    port_value->data_size = RTSYN_PORT_VALUE_INITIALIZER_TABLE[value_type].data_size_getter();

    if (!port_value->value_data)
    {
        free(port_value);
        return nullptr;
    }

    return port_value;
}

void
rtsyn_port_value_destroy(rtsyn_port_value_t *port_value)
{
    if (!port_value)
    {
        return;
    }

    port_value->data_destructor(port_value->value_data);
    free(port_value);
}

rtsyn_port_value_type_t
rtsyn_port_value_type_get(const rtsyn_port_value_t *port_value)
{
    if (!port_value)
    {
        return RTSYN_PORT_VALUE_INVALID;
    }
    return port_value->value_type;
}

bool
rtsyn_port_value_is_type(const rtsyn_port_value_t *port_value, rtsyn_port_value_type_t value_type)
{
    return (port_value->value_type == value_type);
}

rtsyn_port_value_type_t
rtsyn_port_value_validate_type(rtsyn_port_value_type_t value_type)
{
    if (value_type == RTSYN_PORT_VALUE_INVALID || value_type >= RTSYN_PORT_VALUE_COUNT)
    {
        return RTSYN_PORT_VALUE_INVALID;
    }

    return value_type;
}

bool
rtsyn_port_value_get(const rtsyn_port_value_t *port_value, void *contained_value)
{
    if (!port_value || !contained_value)
    {
        return false;
    }

    return port_value->data_getter(port_value, contained_value);
}

size_t
rtsyn_port_value_size_get(const rtsyn_port_value_t *port_value)
{
    if (!port_value)
    {
        return 0;
    }

    return port_value->data_size;
}

bool
rtsyn_port_value_set(rtsyn_port_value_t *port_value, void *new_value)
{
    if (!port_value || !new_value)
    {
        return false;
    }

    return port_value->data_setter(port_value, new_value);
}
