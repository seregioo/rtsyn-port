
#include "rtsyn/port/spec.h"

void
rtsyn_port_spec_init(rtsyn_port_spec_t *port_spec)
{
    *port_spec = (rtsyn_port_spec_t){"", RTSYN_PORT_VALUE_INVALID};
}

bool
rtsyn_port_spec_set(rtsyn_port_spec_t *port_spec, const char *name,
                    rtsyn_port_value_type_t value_type)
{
    if (!port_spec || !name || !value_type
        || rtsyn_port_value_validate_type(value_type) == RTSYN_PORT_VALUE_INVALID)
    {
        return false;
    }

    *port_spec = (rtsyn_port_spec_t){name, value_type};

    return true;
}
