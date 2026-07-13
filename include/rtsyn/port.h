/**
 * @file rtsyn/port.h
 * @author Sergio Hidalgo (sergiohg.dev@gmail.com)
 * @brief Header file for the RTSyn Port.
 *
 * The RTSyn Runtime port abstracts the Port logic so it can be transparent to the RTSyn
 * components.
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 * @copyright Copyright (c) Sergio Hidalgo 2026
 */
#ifndef RTSYN_PORT_H
#define RTSYN_PORT_H
#include <stdint.h>

#include "rtsyn/port/spec.h"
#include "rtsyn/port/value.h"

#define RTSYN_PORT_ID_INVALID UINT32_MAX

/**
 * @brief Opaque RTSyn Port object.
 *
 * The port owns the action to be executed.
 */
typedef struct rtsyn_port_s rtsyn_port_t;

/**
 * @brief Port ID type.
 */
typedef uint32_t rtsyn_port_id_t;

/**
 * @brief Identifiers for RTSyn Port direction.
 */
typedef enum rtsyn_port_direction_type_e {
    RTSYN_PORT_DIRECTION_INVALID = 0, /**< Invalid port type. */
    RTSYN_PORT_DIRECTION_IN,          /**< Input port. */
    RTSYN_PORT_DIRECTION_OUT,         /**< Output port. */
    RTSYN_PORT_DIRECTION_COUNT        /**< Number of types. */
} rtsyn_port_direction_type_t;

/**
 * @brief Create an RTSyn Port.
 *
 * @param port_spec Port specification.
 * @param value_type Value type.
 * @param id Port id.
 * @return Pointer to the created port, or NULL if creation fails.
 */
rtsyn_port_t *
rtsyn_port_create(const rtsyn_port_spec_t *port_spec, rtsyn_port_direction_type_t direction_type,
                  rtsyn_port_id_t id);

/**
 * @brief Destroy an RTSyn Port.
 *
 * @param rtsyn_port Port to be destroyed.
 */
void
rtsyn_port_destroy(rtsyn_port_t *rtsyn_port);

/**
 * @brief Getter for the ID of the RTSyn Port.
 *
 * @param rtsyn_port The port to query the ID.
 * @return The port ID.
 */
rtsyn_port_id_t
rtsyn_port_get_id(const rtsyn_port_t *rtsyn_port);

/**
 * @brief Getter for the direction of the RTSyn Port.
 *
 * @param rtsyn_port The port to query the ID.
 * @return The port direction.
 */
rtsyn_port_direction_type_t
rtsyn_port_get_direction(const rtsyn_port_t *rtsyn_port);

/**
 * @brief Getter for the Name of the RTSyn Port.
 *
 * @param rtsyn_port The port to query the ID.
 * @return The port name.
 */
const char *
rtsyn_port_get_name(const rtsyn_port_t *rtsyn_port);

/**
 * @brief Getter for the internal value type of the RTSyn Port.
 *
 * @param rtsyn_port The port to query the ID.
 * @return The port value type.
 */
rtsyn_port_value_type_t
rtsyn_port_get_internal_value_type(const rtsyn_port_t *rtsyn_port);

/**
 * @brief Getter for the internal value of the RTSyn Port.
 *
 * @param rtsyn_port The port to query the ID
 * @return The port value
 */
const rtsyn_port_value_t *
rtsyn_port_get_internal_value(const rtsyn_port_t *rtsyn_port);

/**
 * @brief Validator for the direction type of the RTSyn Port direction.
 *
 * @param port_direction The port direction.
 * @return RTSYN_PORT_DIRECTION_INVALID if its not a valid direction, the same direction otherwise.
 */
rtsyn_port_direction_type_t
rtsyn_port_validate_direction(rtsyn_port_direction_type_t port_direction);

bool
rtsyn_port_cmp(rtsyn_port_t *port_a, rtsyn_port_t *port_b);

/**
 * @brief Setter for the internal value of the RTSyn Port via raw pointer.
 *
 * This function asumes that the caller is passing a valid pointer to the port (this means that the
 * pointer is not null and the data on that address shares type with the port). It is meant to be
 * used when heap allocation is not desired.
 *
 * @param rtsyn_port The port to modify the value.
 * @param value_ptr pointer to the value.
 * @return true if set, false otherwise.
 */
bool
rtsyn_port_set_internal_value_by_ptr(rtsyn_port_t *rtsyn_port, void *value_ptr);

/**
 * @brief Setter for the internal value of the RTSyn Port via value.
 *
 * This function is the secure version of `rtsyn_port_set_internal_value_by_ptr`.
 *
 * @param rtsyn_port The port to modify the value.
 * @param port_value The port value object which contains the value.
 * @return true if set, false otherwise.
 */
bool
rtsyn_port_set_internal_value_by_value(rtsyn_port_t *rtsyn_port,
                                       const rtsyn_port_value_t *port_value);

#endif /* RTSYN_PORT_H */
