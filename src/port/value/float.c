#include <stdlib.h>

#include "rtsyn/internal/port/value.h"
#include "rtsyn/port/value/float.h"

rtsyn_port_value_t *
rtsyn_port_value_create_float()
{
    return rtsyn_port_value_create(RTSYN_PORT_VALUE_FLOAT);
}

float *
rtsyn_port_value_float_create()
{
    return (float *)calloc(1, sizeof(float));
}

void
rtsyn_port_value_float_destroy(float *float_value)
{
    free(float_value);
}

bool
rtsyn_port_value_float_get(const rtsyn_port_value_t *port_value, float *out)
{
    if (!port_value || !rtsyn_port_value_is_type(port_value, RTSYN_PORT_VALUE_FLOAT) || !out)
    {
        return false;
    }

    *out = *(float *)port_value->value_data;
    return true;
}

size_t
rtsyn_port_value_float_size_get()
{
    return sizeof(float);
}

bool
rtsyn_port_value_float_set(rtsyn_port_value_t *port_value, float *new_value)
{
    if (!port_value || !rtsyn_port_value_is_type(port_value, RTSYN_PORT_VALUE_FLOAT) || !new_value)
    {
        return false;
    }

    *(float *)port_value->value_data = *new_value;
    return true;
}
