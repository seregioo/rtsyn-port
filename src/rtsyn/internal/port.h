/**
 * @file rtsyn/internal/port.h
 * @author Sergio Hidalgo (sergiohg.dev@gmail.com)
 * @brief Header file that contains the private type definitions for RTSync Runtime Node
 * Port.
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 * @copyright Copyright (c) Sergio Hidalgo 2026
 */
#ifndef RTSYN_INTERNAL_PORT_H
#define RTSYN_INTERNAL_PORT_H
#include "rtsyn/port.h"

/**
 * @brief Node Port definition.
 */
struct rtsyn_port_s {
    rtsyn_port_value_t *port_value;
    rtsyn_port_direction_type_t dir_type;
    rtsyn_port_id_t port_id;
    char *port_name;
};

#define RTSYN_PORT_COPY_VALUE(port, src_value, c_type, get_fn, valid)                              \
    do                                                                                             \
    {                                                                                              \
        c_type value;                                                                              \
        valid = get_fn((src_value), &value);                                                       \
        if (valid)                                                                                 \
        {                                                                                          \
            rtsyn_port_set_internal_value_by_ptr((port), &value);                                  \
        }                                                                                          \
    } while (false)

#endif /* RTSYN_INTERNAL_PORT_H */
