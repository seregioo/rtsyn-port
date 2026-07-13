/**
 * @file rtsyn/internal/port/value/float.h
 * @author Sergio Hidalgo (sergiohg.dev@gmail.com)
 * @brief Internal header file for the RTSyn Port Value for float.
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 * @copyright Copyright (c) Sergio Hidalgo 2026
 */
#ifndef RTSYN_INTERNAL_PORT_VALUE_FLOAT_H
#define RTSYN_INTERNAL_PORT_VALUE_FLOAT_H
#include "rtsyn/port/value/float.h"

/**
 * @brief Constructor for the float pointer.
 *
 * @return float allocated in memory.
 */
float *
rtsyn_port_value_float_create();

/**
 * @brief Destructor for the float pointer.
 *
 * @param float_value float to be destroyed.
 */
void
rtsyn_port_value_float_destroy(float *float_value);

/**
 * @brief Getter for the size of the float data.
 *
 * @return The size of the data type.
 */
size_t
rtsyn_port_value_float_size_get();

#endif /* RTSYN_INTERNAL_PORT_VALUE_FLOAT_H */
