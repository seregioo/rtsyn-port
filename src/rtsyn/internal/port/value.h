/**
 * @file rtsyn/internal/port/value.h
 * @author Sergio Hidalgo (sergiohg.dev@gmail.com)
 * @brief Header file that contains the private type definitions for RTSync Runtime Port Value.
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 * @copyright Copyright (c) Sergio Hidalgo 2026
 */
#ifndef RTSYN_INTERNAL_PORT_VALUE_H
#define RTSYN_INTERNAL_PORT_VALUE_H
#include "rtsyn/port/value.h"

/**
 * @brief Node Port Value data constructor.
 *
 * Allocates memory for the data.
 */
typedef void *(*rtsyn_port_value_data_constructor_fn)(void);

/**
 * @brief Node Port Value data destructor.
 *
 * Frees memory for the data.
 */
typedef void (*rtsyn_port_value_data_destructor_fn)(void *);

/**
 * @brief Node Port Value data setter.
 *
 * Changes the value of the data.
 */
typedef bool (*rtsyn_port_value_data_setter_fn)(rtsyn_port_value_t *, void *);

/**
 * @brief Node Port Value data getter.
 *
 * Retrieves the value of the data.
 */
typedef bool (*rtsyn_port_value_data_getter_fn)(const rtsyn_port_value_t *, void *);

typedef size_t (*rtsyn_port_value_data_size_getter_fn)(void);

/**
 * @brief Node Port Value initializer.
 *
 * Structure that aggregates the functions needed to initialize the value.
 */
typedef struct rtsyn_port_value_initializer_s {
    rtsyn_port_value_data_constructor_fn data_constructor;
    rtsyn_port_value_data_destructor_fn data_destructor;
    rtsyn_port_value_data_getter_fn data_getter;
    rtsyn_port_value_data_size_getter_fn data_size_getter;
    rtsyn_port_value_data_setter_fn data_setter;
} rtsyn_port_value_initializer_t;

/**
 * @brief Node Port Value definition.
 */
struct rtsyn_port_value_s {
    rtsyn_port_value_type_t value_type;                  /**< The port value type. */
    void *value_data;                                    /**< The port void pointer to the data. */
    rtsyn_port_value_data_destructor_fn data_destructor; /**< The constructor for the data. */
    rtsyn_port_value_data_setter_fn data_setter;         /**< The destructor for the data. */
    rtsyn_port_value_data_getter_fn data_getter;         /**< The destructor for the data. */
    size_t data_size;                                    /**< The size of the data. */
};

/**
 * @brief Defines an initializer entry for the port value initializer.
 *
 * Expands to a designated initializer for one port value table entry, indexed by @p value_type.
 *
 * @param value_type The value type identifier used as the array index.
 * @param data_constructor Function used to build the data.
 * @param data_destructor Function used to destroy the data.
 * @param data_getter Function used to get the data value.
 * @param data_size_getter Function used to get the data size.
 * @param data_setter Function used to set the data value.
 */
#define RTSYN_PORT_VALUE_INITIALIZER_TBL_ENTRY(value_type, data_constructor, data_destructor,      \
                                               data_getter, data_size_getter, data_setter)         \
    [value_type] = {(rtsyn_port_value_data_constructor_fn)data_constructor,                        \
                    (rtsyn_port_value_data_destructor_fn)data_destructor,                          \
                    (rtsyn_port_value_data_getter_fn)data_getter,                                  \
                    (rtsyn_port_value_data_size_getter_fn)data_size_getter,                        \
                    (rtsyn_port_value_data_setter_fn)data_setter}

#endif /* RTSYN_INTERNAL_PORT_VALUE_H */
