/*
 * Copyright (c) 2021 EPAM Systems
 *
 * SPDX-License-Identifier: Apache-2.0
 */
#ifndef __XEN_HVM_H__
#define __XEN_HVM_H__

#include <kernel.h>

int hvm_set_parameter(int idx, uint64_t value);
int hvm_get_parameter(int idx, uint64_t *value);

#endif /* __XEN_HVM_H__ */
