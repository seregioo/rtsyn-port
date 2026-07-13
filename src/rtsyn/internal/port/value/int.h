/**
 * @file rtsyn/internal/port/value/int.h
 * @author Sergio Hidalgo (sergiohg.dev@gmail.com)
 * @brief Internal header file for the RTSyn Port Value for int.
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 * @copyright Copyright (c) Sergio Hidalgo 2026
 */
#ifndef RTSYN_INTERNAL_PORT_VALUE_INT_H
#define RTSYN_INTERNAL_PORT_VALUE_INT_H
#include "rtsyn/port/value/int.h"

/**
 * @brief Constructor for the int pointer.
 *
 * @return int allocated in memory.
 */
int *
rtsyn_port_value_int_create();

/**
 * @brief Destructor for the int pointer.
 *
 * @param int_value int to be destroyed.
 */
void
rtsyn_port_value_int_destroy(int *int_value);

/**
 * @brief Getter for the size of the int data.
 *
 * @return The size of the data type.
 */
size_t
rtsyn_port_value_int_size_get();

#endif /* RTSYN_INTERNAL_PORT_VALUE_INT_H */
