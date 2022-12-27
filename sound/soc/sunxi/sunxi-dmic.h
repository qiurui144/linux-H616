/*
 * sound\soc\sunxi\sunxi_dmic.h
 * (C) Copyright 2010-2016
 * Allwinner Technology Co., Ltd. <www.allwinnertech.com>
 * Wolfgang huang <huangjinhui@allwinnertech.com>
 *
 * some simple description for this code
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; either version 2 of
 * the License, or (at your option) any later version.
 *
 */

#ifndef __SUNXI_DMIC_H
#define __SUNXI_DMIC_H

#if defined(CONFIG_ARCH_SUN8IW18) || defined(CONFIG_ARCH_SUN50IW9)
#define DMIC_PLL_AUDIO_X4
#else
#undef DMIC_PLL_AUDIO_X4
#endif

/*------------------DMIC register definition--------------------*/
#define SUNXI_DMIC_EN			0x00
#define SUNXI_DMIC_SR			0x04
#define SUNXI_DMIC_CTR			0x08
#define SUNXI_DMIC_DATA			0x10
#define SUNXI_DMIC_INTC			0x14
#define SUNXI_DMIC_INTS			0x18
#define SUNXI_DMIC_FIFO_CTR		0x1c
#define SUNXI_DMIC_FIFO_STA		0x20
#define SUNXI_DMIC_CH_NUM		0x24
#define SUNXI_DMIC_CH_MAP		0x28
#define SUNXI_DMIC_CNT			0x2c
#define SUNXI_DMIC_DATA0_1_VOL		0x30
#define SUNXI_DMIC_DATA2_3_VOL		0x34
#define	SUNXI_DMIC_HPF_CTRL		0x38
#define	SUNXI_DMIC_HPF_COEF		0x3C
#define	SUNXI_DMIC_HPF_GAIN		0x40
#define SUNXI_DMIC_REV			0x50

/*0x00:SUNXI_DMIC_EN*/
#ifdef CONFIG_SND_SUNXI_MAD
#define DMIC_MAD_DATA_EN		31
#endif
#define DMIC_RX_SYNC_EN			29
#define DMIC_RX_EN_MUX			28
#define GLOBE_EN			8
#define DATA3_CHR_EN			7
#define DATA3_CHL_EN			6
#define DATA2_CHR_EN			5
#define DATA2_CHL_EN			4
#define DATA1_CHR_EN			3
#define DATA1_CHL_EN			2
#define DATA0_CHR_EN			1
#define DATA0_CHL_EN			0
#define DATA_CH_EN			0

/*SUNXI_DMIC_SR:0x04*/
#define DMIC_SR				0

/*SUNXI_DMIC_CTR:0x08*/
#define DMICFDT				9
#define DMICDFEN			8
#define DATA3_LR_SWEEP_EN		7
#define DATA2_LR_SWEEP_EN		6
#define DATA1_LR_SWEEP_EN		5
#define DATA0_LR_SWEEP_EN		4
#define DMIC_OVERSAMPLE_RATE		0

/*SUNXI_DMIC_DATA:0x10*/
#define DMIC_DATA			0

/*SUNXI_DMIC_INTC:0x14*/
#define FIFO_DRQ_EN			2
#define FIFO_OVERRUN_IRQ_EN		1
#define DATA_IRQ_EN			0

/*SUNXI_DMIC_INTS:0x18*/
#define FIFO_OVERRUN_IRQ_PENDING	1
#define FIFO_DATA_IRQ_PENDING		0

/*SUNXI_DMIC_FIFO_CTR:0x1c*/
#define DMIC_FIFO_FLUSH			31
#define DMIC_FIFO_MODE			9
#define DMIC_SAMPLE_RESOLUTION		8
#define FIFO_TRG_LEVEL			0

/*SUNXI_DMIC_FIFO_STA:0x20*/
#ifdef CONFIG_SND_SUNXI_MAD
#define DMIC_MAD_DATA_ALIGN		8
#endif
#define DMIC_DATA_CNT			0

/*SUNXI_DMIC_CH_NUM:0x24*/
#define DMIC_CH_NUM			0

/*SUNXI_DMIC_CH_MAP:0x28*/
#define DMIC_CH7_MAP			28
#define DMIC_CH6_MAP			24
#define DMIC_CH5_MAP			20
#define DMIC_CH4_MAP			16
#define DMIC_CH3_MAP			12
#define DMIC_CH2_MAP			8
#define DMIC_CH1_MAP			4
#define DMIC_CH0_MAP			0
#define DMIC_CHANMAP_DEFAULT		(0x76543210)
/*SUNXI_DMIC_CNT:0x2c*/
#define DMIC_CNT			0

/*SUNXI_DMIC_DATA0_1_VOL:0x30*/
#define DATA1L_VOL			24
#define DATA1R_VOL			16
#define DATA0L_VOL			8
#define DATA0R_VOL			0

/*SUNXI_DMIC_DATA2_3_VOL:0x34*/
#define DATA3L_VOL			24
#define DATA3R_VOL			16
#define DATA2L_VOL			8
#define DATA2R_VOL			0
#define	DMIC_DEFAULT_VOL		0xB0B0B0B0

/*SUNXI_DMIC_HPF_EN_CTR:0x38*/
#define HPF_DATA3_CHR_EN		7
#define HPF_DATA3_CHL_EN		6
#define HPF_DATA2_CHR_EN		5
#define HPF_DATA2_CHL_EN		4
#define HPF_DATA1_CHR_EN		3
#define HPF_DATA1_CHL_EN		2
#define HPF_DATA0_CHR_EN		1
#define HPF_DATA0_CHL_EN		0

/*SUNXI_DMIC_HPF_COEF:0x3C*/
#define HPF_COEF			0

/*SUNXI_DMIC_HPF_GAIN:0x40*/
#define HPF_GAIN			0

struct sunxi_dmic_reg_label {
	const char *name;
	int value;
};

#define SUNXI_DMIC_REG_LABEL(constant)				\
{						\
	#constant, constant			\
}

#define SUNXI_DMIC_REG_LABEL_END				\
{						\
	NULL, -1				\
}

struct sunxi_dmic_info {
	void __iomem *membase;
	struct resource *memregion;
	struct regmap   *regmap;
	struct regulator *power_supply;
	struct clk *pllclk;
#ifdef DMIC_PLL_AUDIO_X4
	struct clk *pllclkx4;
#endif
	struct clk *moduleclk;
	int moduleclk_en;
	struct device *dev;
	struct snd_soc_dai_driver dai;
	struct sunxi_dma_params capture_dma_param;
	struct pinctrl *pinctrl;
	struct pinctrl_state  *pinstate;
	struct pinctrl_state  *pinstate_sleep;
	bool capture_en;
#ifdef CONFIG_SND_SUNXI_MAD
	struct resource res;
	unsigned int mad_bind;
	unsigned int mad_suspend;
	unsigned int lpsd_chan_sel;
	unsigned int mad_standby_chan_sel;
	unsigned int audio_src_chan_num;
#endif
	u32 chanmap;
};

#endif /* SUNXI_DMIC_H */
