/*
 * @file port.c
 * @author Sergio Hidalgo (sergiohg.dev@gmail.com)
 * @brief Compile unit for the RTSyn Port
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 * @copyright Copyright (c) Sergio Hidalgo 2026
 */
#include <stdlib.h>
#include <string.h>

#include "rtsyn/internal/port.h"
#include "rtsyn/port/value/double.h"
#include "rtsyn/port/value/float.h"
#include "rtsyn/port/value/int.h"
#include "rtsyn/port/value/str.h"
#include "rtsyn/port/value/uint.h"

rtsyn_port_t *
rtsyn_port_create(const rtsyn_port_spec_t *port_spec, rtsyn_port_direction_type_t direction_type,
                  rtsyn_port_id_t id)
{

    if (!port_spec || !port_spec->name || id == RTSYN_PORT_ID_INVALID
        || rtsyn_port_validate_direction(direction_type) == RTSYN_PORT_DIRECTION_INVALID)
    {
        return nullptr;
    }

    char *port_name_aux = (char *)malloc(strlen(port_spec->name) + 1);
    if (!port_name_aux)
    {
        return nullptr;
    }
    strcpy(port_name_aux, port_spec->name);

    rtsyn_port_value_t *port_value = rtsyn_port_value_create(port_spec->value_type);
    if (!port_value)
    {
        free(port_name_aux);
        return nullptr;
    }

    rtsyn_port_t *port = (rtsyn_port_t *)malloc(sizeof(rtsyn_port_t));
    if (!port)
    {
        rtsyn_port_value_destroy(port_value);
        free(port_name_aux);
        return nullptr;
    }

    port->port_name = port_name_aux;
    port->dir_type = direction_type;
    port->port_value = port_value;
    port->port_id = id;

    return port;
}

void
rtsyn_port_destroy(rtsyn_port_t *rtsyn_port)
{
    if (!rtsyn_port)
    {
        return;
    }

    rtsyn_port_value_destroy(rtsyn_port->port_value);
    free(rtsyn_port->port_name);
    free(rtsyn_port);
}

rtsyn_port_id_t
rtsyn_port_get_id(const rtsyn_port_t *rtsyn_port)
{
    if (!rtsyn_port)
    {
        return 0;
    }

    return rtsyn_port->port_id;
}

const char *
rtsyn_port_get_name(const rtsyn_port_t *rtsyn_port)
{
    if (!rtsyn_port)
    {
        return nullptr;
    }

    return rtsyn_port->port_name;
}

const rtsyn_port_value_t *
rtsyn_port_get_internal_value(const rtsyn_port_t *rtsyn_port)
{
    if (!rtsyn_port)
    {
        return nullptr;
    }

    return rtsyn_port->port_value;
}

rtsyn_port_value_type_t
rtsyn_port_get_internal_value_type(const rtsyn_port_t *rtsyn_port)
{
    if (!rtsyn_port)
    {
        return RTSYN_PORT_VALUE_INVALID;
    }

    return rtsyn_port_value_type_get(rtsyn_port->port_value);
}

rtsyn_port_direction_type_t
rtsyn_port_validate_direction(rtsyn_port_direction_type_t port_direction)
{
    if (port_direction == RTSYN_PORT_DIRECTION_INVALID
        || port_direction >= RTSYN_PORT_DIRECTION_COUNT)
    {
        return RTSYN_PORT_DIRECTION_INVALID;
    }

    return port_direction;
}

bool
rtsyn_port_cmp(rtsyn_port_t *port_a, rtsyn_port_t *port_b)
{
    return port_a->dir_type == port_b->dir_type && port_a->port_id == port_b->port_id
           && strcmp(port_a->port_name, port_b->port_name) == 0;
}

bool
rtsyn_port_set_internal_value_by_ptr(rtsyn_port_t *rtsyn_port, void *value_ptr)
{
    return rtsyn_port_value_set(rtsyn_port->port_value, value_ptr);
}

bool
rtsyn_port_set_internal_value_by_value(rtsyn_port_t *rtsyn_port,
                                       const rtsyn_port_value_t *port_value)
{
    bool valid = false;
    if (!rtsyn_port || !port_value)
    {
        return valid;
    }

    const rtsyn_port_value_type_t value_type = rtsyn_port_value_type_get(port_value);
    const rtsyn_port_value_type_t port_type = rtsyn_port_get_internal_value_type(rtsyn_port);

    if (value_type != port_type)
    {
        return valid;
    }

    size_t data_size = rtsyn_port_value_size_get(port_value);

    if (data_size == 0)
    {
        return valid;
    }

    void *value = malloc(data_size);

    valid = rtsyn_port_value_get(port_value, value);
    if (valid)
    {
        rtsyn_port_set_internal_value_by_ptr(rtsyn_port, value);
    }

    free(value);

    return valid;
}

rtsyn_port_direction_type_t
rtsyn_port_get_direction(const rtsyn_port_t *rtsyn_port)
{
    if (!rtsyn_port)
    {
        return RTSYN_PORT_DIRECTION_INVALID;
    }

    return rtsyn_port->dir_type;
}
