/*
 * Copyright 2014 Freescale Semiconductor
 *
 * SPDX-License-Identifier:	GPL-2.0+
 */

#ifndef __LS2_EMU_H
#define __LS2_EMU_H

#include "ls2080a_common.h"

#define CONFIG_IDENT_STRING		" EMU"
#define CONFIG_BOOTP_VCI_STRING		"U-boot-EMU"

#define CONFIG_SYS_CLK_FREQ	100000000
#define CONFIG_DDR_CLK_FREQ	133333333

#define CONFIG_SYS_MXC_I2C1_SPEED	40000000
#define CONFIG_SYS_MXC_I2C2_SPEED	40000000

#define CONFIG_DDR_SPD
#define CONFIG_SYS_FSL_DDR_EMU		/* Support emulator */
#define SPD_EEPROM_ADDRESS1	0x51
#define SPD_EEPROM_ADDRESS2	0x52
#define SPD_EEPROM_ADDRESS3	0x53
#define SPD_EEPROM_ADDRESS	SPD_EEPROM_ADDRESS1
#define CONFIG_SYS_SPD_BUS_NUM	0	/* SPD on I2C bus 0 */
#define CONFIG_DIMM_SLOTS_PER_CTLR		1
#define CONFIG_CHIP_SELECTS_PER_CTRL		4
#ifdef CONFIG_SYS_FSL_HAS_DP_DDR
#define CONFIG_DP_DDR_DIMM_SLOTS_PER_CTLR	1
#endif

#define CONFIG_FSL_DDR_SYNC_REFRESH

#define CONFIG_SYS_NOR0_CSPR_EXT	(0x0)
#define CONFIG_SYS_NOR_AMASK	IFC_AMASK(128*1024*1024)
/*
 * NOR Flash Timing Params
 */
#define CONFIG_SYS_NOR0_CSPR					\
	(CSPR_PHYS_ADDR(CONFIG_SYS_FLASH_BASE_PHYS)		| \
	CSPR_PORT_SIZE_16					| \
	CSPR_MSEL_NOR						| \
	CSPR_V)
#define CONFIG_SYS_NOR0_CSPR_EARLY				\
	(CSPR_PHYS_ADDR(CONFIG_SYS_FLASH_BASE_PHYS_EARLY)	| \
	CSPR_PORT_SIZE_16					| \
	CSPR_MSEL_NOR						| \
	CSPR_V)
#define CONFIG_SYS_NOR_CSOR	CSOR_NOR_ADM_SHIFT(12)
#define CONFIG_SYS_NOR_FTIM0	(FTIM0_NOR_TACSE(0x1) | \
				FTIM0_NOR_TEADC(0x1) | \
				FTIM0_NOR_TEAHC(0x1))
#define CONFIG_SYS_NOR_FTIM1	(FTIM1_NOR_TACO(0x1) | \
				FTIM1_NOR_TRAD_NOR(0x1))
#define CONFIG_SYS_NOR_FTIM2	(FTIM2_NOR_TCS(0x0) | \
				FTIM2_NOR_TCH(0x0) | \
				FTIM2_NOR_TWP(0x1))
#define CONFIG_SYS_NOR_FTIM3	0x04000000
#define CONFIG_SYS_IFC_CCR	0x01000000

#define CONFIG_SYS_CSPR0_EXT		CONFIG_SYS_NOR0_CSPR_EXT
#define CONFIG_SYS_CSPR0		CONFIG_SYS_NOR0_CSPR_EARLY
#define CONFIG_SYS_CSPR0_FINAL		CONFIG_SYS_NOR0_CSPR
#define CONFIG_SYS_AMASK0		CONFIG_SYS_NOR_AMASK
#define CONFIG_SYS_CSOR0		CONFIG_SYS_NOR_CSOR
#define CONFIG_SYS_CS0_FTIM0		CONFIG_SYS_NOR_FTIM0
#define CONFIG_SYS_CS0_FTIM1		CONFIG_SYS_NOR_FTIM1
#define CONFIG_SYS_CS0_FTIM2		CONFIG_SYS_NOR_FTIM2
#define CONFIG_SYS_CS0_FTIM3		CONFIG_SYS_NOR_FTIM3

/* Debug Server firmware */
#define CONFIG_SYS_DEBUG_SERVER_FW_IN_NOR
#define CONFIG_SYS_DEBUG_SERVER_FW_ADDR	0x580C00000ULL

/*
 * This trick allows users to load MC images into DDR directly without
 * copying from NOR flash. It dramatically improves speed.
 */
#define CONFIG_SYS_LS_MC_FW_IN_DDR
#define CONFIG_SYS_LS_MC_DPL_IN_DDR
#define CONFIG_SYS_LS_MC_DPC_IN_DDR

#define CONFIG_SYS_LS_MC_BOOT_TIMEOUT_MS 200000

/* Store environment at top of flash */
#define CONFIG_ENV_IS_NOWHERE		1
#define CONFIG_ENV_SIZE			0x1000

#endif /* __LS2_EMU_H */
