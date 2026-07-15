
#include "rtsyn/port/descriptor.h"

void
rtsyn_port_descriptor_init(rtsyn_abi_port_descriptor_t *descriptor)
{
    *descriptor = (rtsyn_abi_port_descriptor_t){"", RTSYN_ABI_VALUE_INVALID,
                                                RTSYN_ABI_PORT_DIRECTION_INVALID};
}

bool
rtsyn_port_descriptor_set(rtsyn_abi_port_descriptor_t *descriptor, const char *name,
                          rtsyn_abi_value_type_t value_type, rtsyn_abi_port_direction_t direction)
{
    if (!descriptor || !name || !rtsyn_abi_value_is_valid(value_type)
        || !rtsyn_abi_port_direction_is_valid(direction))
    {
        return false;
    }

    *descriptor = (rtsyn_abi_port_descriptor_t){name, value_type, direction};

    return true;
}

const char *
rtsyn_port_descriptor_get_name(const rtsyn_abi_port_descriptor_t *descriptor)
{
    if (!descriptor)
    {
        return nullptr;
    }
    return descriptor->name;
}

rtsyn_abi_port_direction_t
rtsyn_port_descriptor_get_direction(const rtsyn_abi_port_descriptor_t *descriptor)
{
    if (!descriptor)
    {
        return RTSYN_ABI_PORT_DIRECTION_INVALID;
    }
    return descriptor->direction;
}
