/**
 * @file rtsyn/port/value/double.h
 * @author Sergio Hidalgo (sergiohg.dev@gmail.com)
 * @brief Header file for the RTSyn Port Value for double.
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 * @copyright Copyright (c) Sergio Hidalgo 2026
 */
#ifndef RTSYN_PORT_VALUE_DOUBLE_H
#define RTSYN_PORT_VALUE_DOUBLE_H
#include "rtsyn/port/value.h"

/**
 * @brief Constructor for the double RTSyn Port Value.
 *
 * @return A RTSyn Port Value.
 */
rtsyn_port_value_t *
rtsyn_port_value_create_double();

/**
 * @brief Getter for RTSyn Port Value of type double.
 *
 * @param port_value The port value pointer.
 * @param out The double value pointer to be retrieved.
 *
 * @return true and the value inside out if its a valid pointer from this type, false otherwhise.
 */
bool
rtsyn_port_value_double_get(const rtsyn_port_value_t *port_value, double *out);

/**
 * @brief Getter for RTSyn Port Value of type double.
 *
 * @param port_value The port value pointer.
 * @param new_value Pointer to the double value.
 *
 * @return true if setted, false otherwhise.
 */
bool
rtsyn_port_value_double_set(rtsyn_port_value_t *port_value, double *new_value);

#endif /* RTSYN_PORT_VALUE_DOUBLE_H */
