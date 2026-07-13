/**
 * @file rtsyn/port/value/str.h
 * @author Sergio Hidalgo (sergiohg.dev@gmail.com)
 * @brief Header file for the RTSyn Port Value for str.
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 * @copyright Copyright (c) Sergio Hidalgo 2026
 */
#ifndef RTSYN_PORT_VALUE_STR_H
#define RTSYN_PORT_VALUE_STR_H
#include "rtsyn/port/value.h"

/**
 * @brief Opaque object for the RTSyn string.
 */
typedef struct rtsyn_str_s rtsyn_str_t;

/**
 * @brief Constructor for the str RTSyn Port Value.
 *
 * @return A RTSyn Port Value.
 */
rtsyn_port_value_t *
rtsyn_port_value_create_str();

/**
 * @brief Getter for RTSyn Port Value of type str.
 *
 * This getter assumes that the buffer passed through @p out is big enough to contain the whole
 * string.
 *
 * @param port_value The port value pointer.
 * @param out The str value pointer to be retrieved.
 *
 * @return true and the value inside out if its a valid pointer from this type, false otherwhise.
 */
bool
rtsyn_port_value_str_get(const rtsyn_port_value_t *port_value, char *out);

/**
 * @brief Getter for RTSyn Port Value of type str.
 *
 * @param port_value The port value pointer.
 * @param new_value Pointer to the str value.
 *
 * @return true if setted, false otherwhise.
 */
bool
rtsyn_port_value_str_set(rtsyn_port_value_t *port_value, const char *new_value);

#endif /* RTSYN_PORT_VALUE_STR_H */
