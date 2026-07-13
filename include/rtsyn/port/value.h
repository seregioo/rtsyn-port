/**
 * @file rtsyn/port/value.h
 * @author Sergio Hidalgo (sergiohg.dev@gmail.com)
 * @brief Header file for the RTSyn Port Value.
 *
 * The RTSyn Port Value abstracts the values through portst so they can be transparent to the RTSyn
 * Ports.
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 * @copyright Copyright (c) Sergio Hidalgo 2026
 */
#ifndef RTSYN_PORT_VALUE_H
#define RTSYN_PORT_VALUE_H
#include <stddef.h>
#include <stdint.h>

/**
 * @brief Max length for the string.
 */
#define RTSYN_PORT_VALUE_STRING_MAX_SIZE 256

/**
 * @brief Opaque Node Port Value.
 *
 * The caller is responsible to ensure that the value is coherent with the type
 */
typedef struct rtsyn_port_value_s rtsyn_port_value_t;

/**
 * @brief Identifiers for RTSyn Port Value.
 */
typedef enum rtsyn_port_value_type_e {
    RTSYN_PORT_VALUE_INVALID = 0, /**< Invalid node port type. */
    RTSYN_PORT_VALUE_FLOAT,       /**< Float type. */
    RTSYN_PORT_VALUE_DOUBLE,      /**< Double type. */
    RTSYN_PORT_VALUE_INT,         /**< Int type. */
    RTSYN_PORT_VALUE_UINT,        /**< Uint type. */
    RTSYN_PORT_VALUE_STR,         /**< Str type. */
    RTSYN_PORT_VALUE_COUNT        /**< Number of types. */
} rtsyn_port_value_type_t;

/**
 * @brief Create an RTSyn Port Value.
 *
 * @param value_type value type.
 * @return Pointer to the created Node Port Value, or NULL if creation fails.
 */
rtsyn_port_value_t *
rtsyn_port_value_create(rtsyn_port_value_type_t value_type);

/**
 * @brief Destroy an RTSyn Port Value.
 *
 * @param port_value Port Value to be destroyed.
 */
void
rtsyn_port_value_destroy(rtsyn_port_value_t *port_value);

/**
 * @brief Getter for the port value type.
 *
 * @param port_value Port Value to query.
 */
rtsyn_port_value_type_t
rtsyn_port_value_type_get(const rtsyn_port_value_t *port_value);

/**
 * @brief Checks if a port value is a value type.
 *
 * @param port_value Port Value to query.
 * @param value_type Value type to check.
 * @return true if its type, false otherwise.
 */
bool
rtsyn_port_value_is_type(const rtsyn_port_value_t *port_value, rtsyn_port_value_type_t value_type);

rtsyn_port_value_type_t
rtsyn_port_value_validate_type(rtsyn_port_value_type_t value_type);

/**
 * @brief Getter for the port value.
 *
 * @param port_value Port Value to get.
 * @param new_value Pointer to the value to get.
 * @return true if its valid and stored in @p new_value, false otherwise.
 */
bool
rtsyn_port_value_get(const rtsyn_port_value_t *port_value, void *new_value);

size_t
rtsyn_port_value_size_get(const rtsyn_port_value_t *port_value);

/**
 * @brief Setter for the port value.
 *
 * @param port_value Port Value to set.
 * @param new_value Pointer to the value to set.
 * @return true if its set to @p new_value, false otherwise.
 */
bool
rtsyn_port_value_set(rtsyn_port_value_t *port_value, void *new_value);

#endif /* RTSYN_PORT_VALUE_H */
