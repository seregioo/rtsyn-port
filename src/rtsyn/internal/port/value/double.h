/**
 * @file rtsyn/internal/port/value/double.h
 * @author Sergio Hidalgo (sergiohg.dev@gmail.com)
 * @brief Internal header file for the RTSyn Port Value for double.
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 * @copyright Copyright (c) Sergio Hidalgo 2026
 */
#ifndef RTSYN_INTERNAL_PORT_VALUE_DOUBLE_H
#define RTSYN_INTERNAL_PORT_VALUE_DOUBLE_H
#include "rtsyn/port/value/double.h"

/**
 * @brief Constructor for the double pointer.
 *
 * @return double allocated in memory.
 */
double *
rtsyn_port_value_double_create();

/**
 * @brief Destructor for the double pointer.
 *
 * @param double_value double to be destroyed.
 */
void
rtsyn_port_value_double_destroy(double *double_value);

/**
 * @brief Getter for the size of the double data.
 *
 * @return The size of the data type.
 */
size_t
rtsyn_port_value_double_size_get();

#endif /* RTSYN_INTERNAL_PORT_VALUE_DOUBLE_H */
