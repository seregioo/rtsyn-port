/**
 * @file rtsyn/port/value/float.h
 * @author Sergio Hidalgo (sergiohg.dev@gmail.com)
 * @brief Header file for the RTSyn Port Value for float.
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 * @copyright Copyright (c) Sergio Hidalgo 2026
 */
#ifndef RTSYN_PORT_VALUE_FLOAT_H
#define RTSYN_PORT_VALUE_FLOAT_H
#include "rtsyn/port/value.h"

/**
 * @brief Constructor for the float RTSyn Port Value.
 *
 * @return A RTSyn Port Value.
 */
rtsyn_port_value_t *
rtsyn_port_value_create_float();

/**
 * @brief Getter for RTSyn Port Value of type float.
 *
 * @param port_value The port value pointer.
 * @param out The float value pointer to be retrieved.
 *
 * @return true and the value inside out if its a valid pointer from this type, false otherwhise.
 */
bool
rtsyn_port_value_float_get(const rtsyn_port_value_t *port_value, float *out);

/**
 * @brief Getter for RTSyn Port Value of type float.
 *
 * @param port_value The port value pointer.
 * @param new_value Pointer to the float value.
 *
 * @return true if setted, false otherwhise.
 */
bool
rtsyn_port_value_float_set(rtsyn_port_value_t *port_value, float *new_value);

#endif /* RTSYN_PORT_VALUE_FLOAT_H */
