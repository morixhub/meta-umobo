/*
 * Copyright (C) 2018
 * Author: Morix Dev <morix.dev@gmail.com>
 *
 * Configuration settings for the Aesys Apollo board
 *
 * based on mx6*sabre*.h which are :
 * Copyright (C) 2012 Freescale Semiconductor, Inc.
 *
 * SPDX-License-Identifier:	GPL-2.0+
 */

#ifndef __APOLLOBOARD_CONFIG_H
#define __APOLLOBOARD_CONFIG_H

#define CONFIG_MXC_UART
#define CONFIG_MXC_UART_BASE	UART4_BASE
#define CONSOLE_DEV		"ttymxc3"

#define PHYS_SDRAM_SIZE		(512u * 1024 * 1024)

#define CONFIG_IMX_THERMAL

/* Size of malloc() pool */
#define CONFIG_SYS_MALLOC_LEN		(10 * SZ_1M)

/* I2C Configs */
#define CONFIG_SYS_I2C
#define CONFIG_SYS_I2C_MXC
#define CONFIG_SYS_I2C_MXC_I2C1		/* enable I2C bus 1 */
#define CONFIG_SYS_I2C_MXC_I2C2		/* enable I2C bus 2 */
#define CONFIG_SYS_I2C_MXC_I2C3		/* enable I2C bus 3 */
#define CONFIG_SYS_I2C_SPEED		100000

/* USB Configs */
#define CONFIG_USB_MAX_CONTROLLER_COUNT 2
#define CONFIG_EHCI_HCD_INIT_AFTER_RESET
#define CONFIG_MXC_USB_PORTSC	(PORT_PTS_UTMI | PORT_PTS_PTW)
#define CONFIG_MXC_USB_FLAGS	0

/* MMC Configs */
#define CONFIG_SYS_FSL_ESDHC_ADDR      0

#define CONFIG_FEC_MXC
#define CONFIG_MII
#define IMX_FEC_BASE			ENET_BASE_ADDR
#define CONFIG_FEC_XCV_TYPE		RGMII
#define CONFIG_ETHPRIME			"FEC"
#define CONFIG_FEC_MXC_PHYADDR		4

#define CONFIG_PHY_ATHEROS

#ifdef CONFIG_CMD_SF
#define CONFIG_SF_DEFAULT_BUS		0
#define CONFIG_SF_DEFAULT_CS		0
#define CONFIG_SF_DEFAULT_SPEED		20000000
#define CONFIG_SF_DEFAULT_MODE		SPI_MODE_0
#endif

#define CONFIG_ARP_TIMEOUT     200UL

#define CONFIG_SYS_MEMTEST_START       0x10000000
#define CONFIG_SYS_MEMTEST_END         0x10010000
#define CONFIG_SYS_MEMTEST_SCRATCH     0x10800000

/* Physical Memory Map */
#define CONFIG_NR_DRAM_BANKS           1
#define PHYS_SDRAM                     MMDC0_ARB_BASE_ADDR

#define CONFIG_SYS_SDRAM_BASE          PHYS_SDRAM
#define CONFIG_SYS_INIT_RAM_ADDR       IRAM_BASE_ADDR
#define CONFIG_SYS_INIT_RAM_SIZE       IRAM_SIZE

#define CONFIG_SYS_INIT_SP_OFFSET \
	(CONFIG_SYS_INIT_RAM_SIZE - GENERATED_GBL_DATA_SIZE)
#define CONFIG_SYS_INIT_SP_ADDR \
	(CONFIG_SYS_INIT_RAM_ADDR + CONFIG_SYS_INIT_SP_OFFSET)

/* Environment organization */
#define CONFIG_ENV_SIZE			(8 * 1024)

#if defined(CONFIG_ENV_IS_IN_MMC)
#define CONFIG_FDTFILE	"imx6dl-apolloboard.dtb"
#define CONFIG_SYS_FSL_USDHC_NUM	2
#define CONFIG_SYS_MMC_ENV_DEV		1	/* SDHC4 */
#define CONFIG_ENV_OFFSET		(6 * 64 * 1024)
#define CONFIG_SUPPORT_EMMC_BOOT /* eMMC specific */
#endif

/* Framebuffer */
#define CONFIG_VIDEO_IPUV3
#define CONFIG_VIDEO_BMP_RLE8
#define CONFIG_SPLASH_SCREEN
#define CONFIG_SPLASH_SCREEN_ALIGN
#define CONFIG_BMP_16BPP
#define CONFIG_VIDEO_LOGO
#define CONFIG_VIDEO_BMP_LOGO
#define CONFIG_IMX_HDMI
#define CONFIG_IMX_VIDEO_SKIP

/* #include <config_distro_defaults.h> */
#include "mx6_common.h"

/* 256M RAM (minimum), 32M uncompressed kernel, 16M compressed kernel, 1M fdt,
 * 1M script, 1M pxe and the ramdisk at the end */
#define MEM_LAYOUT_ENV_SETTINGS \
	"bootm_size=0x10000000\0" \
	"kernel_addr_r=0x12000000\0" \
	"fdt_addr_r=0x13000000\0" \
	"scriptaddr=0x13100000\0" \
	"pxefile_addr_r=0x13200000\0" \
	"ramdisk_addr_r=0x13300000\0"

#define BOOT_TARGET_DEVICES(func) \
	func(MMC, mmc, 0) \
	func(MMC, mmc, 1) \
	func(MMC, mmc, 2) \
	func(PXE, pxe, na) \
	func(DHCP, dhcp, na)

        /* //!!
#define CONFIG_BOOTCOMMAND \
	"run finduuid; " \
	"run distro_bootcmd"
        */
        
        /* //!!
#define CONFIG_BOOTCOMMAND \
        "i2c mw 0x08 0x8f 0x00; " \
        "fatload mmc 1:1 12000000 zImage; " \
        "fatload mmc 1:1 18000000 apollo-1504b-imx6sdl.dtb; " \
        "setenv bootargs vt.global_cursor_default=0 vt.cur_default=1 console=ttymxc3,115200n8 root=/dev/mmcblk0p2 rootwait ro video=mxcfb0:dev=lcd,AMPIRE-AM480272MNTMQW-T00H,if=RGB24,fbpix=BGR32 video=mxcfb1:dev=hdmi,1280x720-32@60,if=RGB24 video=mxcfb2:off splash consoleblank=0 gigabit=1 hdmi_audio_enabled_default=0; " \
        "bootz 12000000 - 18000000"
        */

#define CONFIG_BOOTCOMMAND \
    "env set mmcdev ${mmcfirst}; " \
	"mmc dev ${mmcdev}; " \
	"if mmc rescan; then " \
		"if run loadlogo; then " \
			"run displaylogo; " \
		"fi; " \
		"if run loadbootscript; then " \
			"run bootscript; " \
		"else " \
			"if run loaduimage; then " \
				"run mmcboot; " \
			"else run netboot; " \
			"fi; " \
		"fi; " \
	"else " \
		"env set mmcdev ${mmcsecond}; " \
		"mmc dev ${mmcdev}; " \
		"if mmc rescan; then " \
			"if run loadlogo; then " \
				"run displaylogo; " \
			"fi; " \
			"if run loadbootscript; then " \
				"run bootscript; " \
			"else " \
				"if run loaduimage; then " \
					"run mmcboot; " \
				"else run netboot; " \
				"fi; " \
			"fi; " \
		"else " \
			"run netboot; " \
		"fi; " \
	"fi"
        
#include <config_distro_bootcmd.h>

#define CONSOLE_STDIN_SETTINGS \
	"stdin=serial\0"

#define CONSOLE_STDOUT_SETTINGS \
	"stdout=serial\0" \
	"stderr=serial\0"

#define CONSOLE_ENV_SETTINGS \
	CONSOLE_STDIN_SETTINGS \
	CONSOLE_STDOUT_SETTINGS

	/* //!!
#define CONFIG_EXTRA_ENV_SETTINGS \
	CONSOLE_ENV_SETTINGS \
	MEM_LAYOUT_ENV_SETTINGS \
	"script=boot.scr\0" \
	"fdtfile=" CONFIG_FDTFILE "\0" \
	"finduuid=part uuid mmc 0:1 uuid\0" \
	"fdt_high=0xffffffff\0" \
	"initrd_high=0xffffffff\0"
	BOOTENV */
        
#define CONFIG_EXTRA_ENV_SETTINGS \
        CONSOLE_ENV_SETTINGS \
	MEM_LAYOUT_ENV_SETTINGS \
	BOOTENV \
	"logo=logo.bmp\0" \
	"script=boot.scr\0" \
	"uimage=uImage\0" \
	"console=ttymxc3\0" \
	"fdt_high=0xffffffff\0" \
	"initrd_high=0xffffffff\0" \
	"fdt_file=silverbullet.dtb\0" \
	"fdt_addr=0x18000000\0" \
	"boot_fdt=try\0" \
	"ip_dyn=yes\0" \
	"mmcfirst=1\0" \
	"mmcsecond=0\0" \
	"mmcdev=1\0" \
	"mmcpart=1\0" \
	"mmcroot=/dev/mmcblk0p2 rootwait rw\0" \
	"mmcargs=setenv bootargs console=${console},${baudrate} " \
		"root=${mmcroot}\0" \
	"loadlogo=fatload mmc ${mmcdev}:${mmcpart} ${loadaddr} ${logo};\0" \
	"displaylogo=setenv splashpos m,m; bmp display;\0" \
	"loadbootscript=" \
		"fatload mmc ${mmcdev}:${mmcpart} ${loadaddr} ${script};\0" \
	"bootscript=echo Running bootscript from mmc ...; " \
		"source\0" \
	"loaduimage=fatload mmc ${mmcdev}:${mmcpart} ${loadaddr} ${uimage}\0" \
	"loadfdt=fatload mmc ${mmcdev}:${mmcpart} ${fdt_addr} ${fdt_file}\0" \
	"mmcboot=echo Booting from mmc ...; " \
		"run mmcargs; " \
		"if test ${boot_fdt} = yes || test ${boot_fdt} = try; then " \
			"if run loadfdt; then " \
				"bootm ${loadaddr} - ${fdt_addr}; " \
			"else " \
				"if test ${boot_fdt} = try; then " \
					"bootm; " \
				"else " \
					"echo WARN: Cannot load the DT; " \
				"fi; " \
			"fi; " \
		"else " \
			"bootm; " \
		"fi;\0" \
	"netargs=setenv bootargs console=${console},${baudrate} " \
		"root=/dev/nfs " \
	"ip=dhcp nfsroot=${serverip}:${nfsroot},v3,tcp\0" \
		"netboot=echo Booting from net ...; " \
		"run netargs; " \
		"if test ${ip_dyn} = yes; then " \
			"setenv get_cmd dhcp; " \
		"else " \
			"setenv get_cmd tftp; " \
		"fi; " \
		"${get_cmd} ${uimage}; " \
		"if test ${boot_fdt} = yes || test ${boot_fdt} = try; then " \
			"if ${get_cmd} ${fdt_addr} ${fdt_file}; then " \
				"bootm ${loadaddr} - ${fdt_addr}; " \
			"else " \
				"if test ${boot_fdt} = try; then " \
					"bootm; " \
				"else " \
					"echo WARN: Cannot load the DT; " \
				"fi; " \
			"fi; " \
		"else " \
			"bootm; " \
		"fi;\0"
                
#endif                         /* __APOLLOBOARD_CONFIG_H */
