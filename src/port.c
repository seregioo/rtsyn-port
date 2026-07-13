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

rtsyn_port_t *
rtsyn_port_create(const rtsyn_abi_port_descriptor_t *descriptor, rtsyn_port_id_t id)
{

    if (!descriptor || !descriptor->name || id == RTSYN_PORT_ID_INVALID
        || !rtsyn_abi_port_direction_is_valid(descriptor->direction)
        || !rtsyn_abi_value_is_valid(descriptor->value_type))
    {
        return nullptr;
    }

    char *port_name_aux = (char *)malloc(strlen(descriptor->name) + 1);
    if (!port_name_aux)
    {
        return nullptr;
    }
    strcpy(port_name_aux, descriptor->name);

    rtsyn_value_t *port_value = rtsyn_value_create(descriptor->value_type);
    if (!port_value)
    {
        free(port_name_aux);
        return nullptr;
    }

    rtsyn_port_t *port = (rtsyn_port_t *)malloc(sizeof(rtsyn_port_t));
    if (!port)
    {
        rtsyn_value_destroy(port_value);
        free(port_name_aux);
        return nullptr;
    }

    port->port_name = port_name_aux;
    port->dir_type = descriptor->direction;
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

    rtsyn_value_destroy(rtsyn_port->port_value);
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

const rtsyn_value_t *
rtsyn_port_get_internal_value(const rtsyn_port_t *rtsyn_port)
{
    if (!rtsyn_port)
    {
        return nullptr;
    }

    return rtsyn_port->port_value;
}

rtsyn_abi_value_type_t
rtsyn_port_get_internal_value_type(const rtsyn_port_t *rtsyn_port)
{
    if (!rtsyn_port)
    {
        return RTSYN_ABI_VALUE_INVALID;
    }

    return rtsyn_value_type_get(rtsyn_port->port_value);
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
    return rtsyn_value_set(rtsyn_port->port_value, value_ptr);
}

bool
rtsyn_port_set_internal_value_by_value(rtsyn_port_t *rtsyn_port, const rtsyn_value_t *port_value)
{
    if (!rtsyn_port || !port_value)
    {
        return false;
    }
    return rtsyn_value_copy(rtsyn_port->port_value, port_value);
}

rtsyn_abi_port_direction_t
rtsyn_port_get_direction(const rtsyn_port_t *rtsyn_port)
{
    if (!rtsyn_port)
    {
        return RTSYN_ABI_PORT_DIRECTION_INVALID;
    }

    return rtsyn_port->dir_type;
}
