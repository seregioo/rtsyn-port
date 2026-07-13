/**
 * @file rtsyn/port/value/uint.h
 * @author Sergio Hidalgo (sergiohg.dev@gmail.com)
 * @brief Header file for the RTSyn Port Value for uint.
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 * @copyright Copyright (c) Sergio Hidalgo 2026
 */
#ifndef RTSYN_PORT_VALUE_UINT_H
#define RTSYN_PORT_VALUE_UINT_H
#include <stdint.h>

#include "rtsyn/port/value.h"

/**
 * @brief Constructor for the double RTSyn Port Value.
 *
 * @return A RTSyn Port Value.
 */
rtsyn_port_value_t *
rtsyn_port_value_create_double();

/**
 * @brief Getter for RTSyn Port Value of type uint.
 *
 * @param port_value The port value pointer.
 * @param out The uint value pointer to be retrieved.
 *
 * @return true and the value inside out if its a valid pointer from this type, false otherwhise.
 */
bool
rtsyn_port_value_uint_get(const rtsyn_port_value_t *port_value, uint64_t *out);

/**
 * @brief Getter for RTSyn Port Value of type uint.
 *
 * @param port_value The port value pointer.
 * @param new_value Pointer to the uint value.
 *
 * @return true if setted, false otherwhise.
 */
bool
rtsyn_port_value_uint_set(rtsyn_port_value_t *port_value, uint64_t *new_value);

#endif /* RTSYN_PORT_VALUE_UINT_H */
