#include <stdlib.h>

#include "rtsyn/internal/port/value.h"
#include "rtsyn/internal/port/value/double.h"

rtsyn_port_value_t *
rtsyn_port_value_create_double()
{
    return rtsyn_port_value_create(RTSYN_PORT_VALUE_DOUBLE);
}

double *
rtsyn_port_value_double_create()
{
    return (double *)calloc(1, sizeof(double));
}

void
rtsyn_port_value_double_destroy(double *double_value)
{
    free(double_value);
}

bool
rtsyn_port_value_double_get(const rtsyn_port_value_t *port_value, double *out)
{
    if (!port_value || !rtsyn_port_value_is_type(port_value, RTSYN_PORT_VALUE_DOUBLE) || !out)
    {
        return false;
    }

    *out = *(double *)port_value->value_data;
    return true;
}

size_t
rtsyn_port_value_double_size_get()
{
    return sizeof(double);
}

bool
rtsyn_port_value_double_set(rtsyn_port_value_t *port_value, double *new_value)
{
    if (!port_value || !rtsyn_port_value_is_type(port_value, RTSYN_PORT_VALUE_DOUBLE) || !new_value)
    {
        return false;
    }

    *(double *)port_value->value_data = *new_value;
    return true;
}
