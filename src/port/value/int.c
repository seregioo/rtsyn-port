#include <stdlib.h>

#include "rtsyn/internal/port/value.h"
#include "rtsyn/port/value/int.h"

rtsyn_port_value_t *
rtsyn_port_value_create_int()
{
    return rtsyn_port_value_create(RTSYN_PORT_VALUE_INT);
}

int *
rtsyn_port_value_int_create()
{
    return (int *)calloc(1, sizeof(int));
}

void
rtsyn_port_value_int_destroy(int *int_value)
{
    free(int_value);
}

bool
rtsyn_port_value_int_get(const rtsyn_port_value_t *port_value, int *out)
{
    if (!port_value || !rtsyn_port_value_is_type(port_value, RTSYN_PORT_VALUE_INT) || !out)
    {
        return false;
    }

    *out = *(int *)port_value->value_data;
    return true;
}

size_t
rtsyn_port_value_int_size_get()
{
    return sizeof(int);
}

bool
rtsyn_port_value_int_set(rtsyn_port_value_t *port_value, int *new_value)
{
    if (!port_value || !rtsyn_port_value_is_type(port_value, RTSYN_PORT_VALUE_INT) || !new_value)
    {
        return false;
    }

    *(int *)port_value->value_data = *new_value;
    return true;
}
