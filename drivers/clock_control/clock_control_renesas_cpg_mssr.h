/*
 * Copyright (c) 2022 IoT.bzh
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef ZEPHYR_DRIVERS_RENESAS_RENESAS_CPG_MSSR_H_
#define ZEPHYR_DRIVERS_RENESAS_RENESAS_CPG_MSSR_H_

/* Software Reset Clearing Register offsets */
#define SRSTCLR(i)      (0x940 + (i) * 4)

/* CPG write protect offset */
#define CPGWPR          0x900

/* System Module Stop Control Register offsets */
static const uint16_t smstpcr[] = {
	0x130, 0x134, 0x138, 0x13C,
	0x140, 0x144, 0x148, 0x14C,
	0x990, 0x994, 0x998, 0x99C,
};

/* Software Reset Register offsets */
static const uint16_t srcr[] = {
	0x0A0, 0x0A8, 0x0B0, 0x0B8,
	0x0BC, 0x0C4, 0x1C8, 0x1CC,
	0x920, 0x924, 0x928, 0x92C,
};
#ifdef CONFIG_CPU_CORTEX_R7
/* Realtime Module Stop Control Register offsets */
#define RMSTPCR(i)	((i) < 8 ? smstpcr[i] - 0x20 : smstpcr[i] - 0x10)
#endif /* CONFIG_CPU_CORTEX_R7 */

/* CAN-FD Clock Frequency Control Register */
#define CANFDCKCR                 0x244

/* Clock stop bit */
#define CANFDCKCR_CKSTP           BIT(8)

/* CANFD Clock */
#define CANFDCKCR_PARENT_CLK_RATE 800000000
#define CANFDCKCR_DIVIDER_MASK    0x1FF

/* SCIF clock */
#define S3D4_CLK_RATE             66600000

void rcar_cpg_write(uint32_t base_address, uint32_t reg, uint32_t val);

int rcar_cpg_mstp_clock_endisable(uint32_t base_address, uint32_t bit,
				  uint32_t reg, bool enable);

#endif /* ZEPHYR_DRIVERS_RENESAS_RENESAS_CPG_MSSR_H_ */
