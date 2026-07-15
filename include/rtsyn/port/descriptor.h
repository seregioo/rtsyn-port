/**
 * @file rtsyn/port/descriptor.h
 * @author Sergio Hidalgo (sergiohg.dev@gmail.com)
 * @brief Header file for the RTSyn Port Descriptor.
 *
 * The RTSyn Port Descriptor structure aggregates information of about the port that is not set by
 * the owner.
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 * @copyright Copyright (c) Sergio Hidalgo 2026
 */
#ifndef RTSYN_PORT_DESCRIPTOR_H
#define RTSYN_PORT_DESCRIPTOR_H
#include <rtsyn/abi/port/descriptor.h>
#include <rtsyn/abi/port/direction.h>
#include <rtsyn/abi/value.h>

/**
 * @brief Initializes the port specification.
 *
 * Expects the memory direction to be already allocated/valid.
 *
 * @param descriptor Initialized port specification.
 */
void
rtsyn_port_descriptor_init(rtsyn_abi_port_descriptor_t *descriptor);

/**
 * @brief Sets the port specification.
 *
 * @param descriptor Port specification.
 * @param name The port name.
 * @param value_type The port value.
 * @param direction The port direction.
 * @return true if arguments are valid, false if not.
 */
bool
rtsyn_port_descriptor_set(rtsyn_abi_port_descriptor_t *descriptor, const char *name,
                          rtsyn_abi_value_type_t value_type, rtsyn_abi_port_direction_t direction);

const char *
rtsyn_port_descriptor_get_name(const rtsyn_abi_port_descriptor_t *descriptor);

rtsyn_abi_port_direction_t
rtsyn_port_descriptor_get_direction(const rtsyn_abi_port_descriptor_t *descriptor);

#endif /* RTSYN_PORT_DESCRIPTOR_H */
