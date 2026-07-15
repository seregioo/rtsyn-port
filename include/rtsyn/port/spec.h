/**
 * @file rtsyn/port/spec.h
 * @author Sergio Hidalgo (sergiohg.dev@gmail.com)
 * @brief Header file for the RTSyn Port Spec.
 *
 * The RTSyn Port Spect structure aggregates information of about the port that is not set by the
 * owner.
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 * @copyright Copyright (c) Sergio Hidalgo 2026
 */
#ifndef RTSYN_PORT_SPEC_H
#define RTSYN_PORT_SPEC_H
#include "rtsyn/port/value.h"

/*
 * @brief Specification needed for creating a port.
 * */
typedef struct rtsyn_port_spec_s rtsyn_port_spec_t;

/*
 * @brief Specification struct definition.
 * */
struct rtsyn_port_spec_s {
    const char *name;                   /**< Port name. */
    rtsyn_port_value_type_t value_type; /**< Type of port. */
};

/**
 * @brief Initializes the port specification.
 *
 * Expects the memory direction to be already allocated/valid.
 *
 * @param port_spec Initialized port specification.
 */
void
rtsyn_port_spec_init(rtsyn_port_spec_t *port_spec);

/**
 * @brief Sets the port specification.
 *
 * @param port_spec Port specification.
 * @param name The port name.
 * @param value_type The port value.
 * @return true if arguments are valid, false if not.
 */
bool
rtsyn_port_spec_set(rtsyn_port_spec_t *port_spec, const char *name,
                    rtsyn_port_value_type_t value_type);

#endif /* RTSYN_PORT_SPEC_H */
