#include <stdlib.h>

#include "rtsyn/internal/port/value.h"
#include "rtsyn/internal/port/value/uint.h"

rtsyn_port_value_t *
rtsyn_port_value_create_uint()
{
    return rtsyn_port_value_create(RTSYN_PORT_VALUE_UINT);
}

uint64_t *
rtsyn_port_value_uint_create()
{
    return (uint64_t *)calloc(1, sizeof(uint64_t));
}

void
rtsyn_port_value_uint_destroy(uint64_t *uint_value)
{
    free(uint_value);
}

bool
rtsyn_port_value_uint_get(const rtsyn_port_value_t *port_value, uint64_t *out)
{
    if (!port_value || !rtsyn_port_value_is_type(port_value, RTSYN_PORT_VALUE_UINT) || !out)
    {
        return false;
    }

    *out = *(uint64_t *)port_value->value_data;
    return true;
}

size_t
rtsyn_port_value_uint_size_get()
{
    return sizeof(uint64_t);
}

bool
rtsyn_port_value_uint_set(rtsyn_port_value_t *port_value, uint64_t *new_value)
{
    if (!port_value || !rtsyn_port_value_is_type(port_value, RTSYN_PORT_VALUE_UINT) || !new_value)
    {
        return false;
    }

    *(uint64_t *)port_value->value_data = *new_value;
    return true;
}
