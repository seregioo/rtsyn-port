/**
 * @file rtsyn/internal/port/value/str.h
 * @author Sergio Hidalgo (sergiohg.dev@gmail.com)
 * @brief Internal header file for the RTSyn Port Value for str.
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 * @copyright Copyright (c) Sergio Hidalgo 2026
 */
#ifndef RTSYN_INTERNAL_PORT_VALUE_STR_H
#define RTSYN_INTERNAL_PORT_VALUE_STR_H
#include "rtsyn/port/value/str.h"

/**
 * @brief Definition of the RTSyn string.
 */
struct rtsyn_str_s {
    char *string;            /**< The string pointer. */
    uint32_t str_max_size;    /**< The string max capacity. */
    uint32_t str_actual_len; /**< The string actual length. */
};

/**
 * @brief Constructor for the RTSyn string value.
 *
 * @return RTSyn string allocated in memory.
 */
rtsyn_str_t *
rtsyn_port_value_str_create();

/**
 * @brief Destructor for the RTSyn string pointer.
 *
 * @param str_value RTSyn string to be destroyed.
 */
void
rtsyn_port_value_str_destroy(rtsyn_str_t *str_value);

/**
 * @brief Getter for the size of the RTSyn string data.
 *
 * @return The size of the data type.
 */
size_t
rtsyn_port_value_str_size_get();

#endif /* RTSYN_INTERNAL_PORT_VALUE_STR_H */
