// SPDX-License-Identifier: GPL-2.0+
/*
 * Qualcomm sm8350 pinctrl
 *
 * (C) Copyright 2026 fwlta <monkeyfwlta@protonmail.com>
 */

#include <dm.h>

#include "pinctrl-qcom.h"

#define MAX_PIN_NAME_LEN 32
static char pin_name[MAX_PIN_NAME_LEN] __section(".data");

static const struct pinctrl_function msm_pinctrl_functions[] = {
	{ "qup3", 1 },
	{ "gpio", 0 },
};

#define SDC_PINGROUP(pg_name, ctl, pull, drv)		\
	{						\
		.name = pg_name,			\
		.ctl_reg = ctl,			\
		.io_reg = 0,				\
		.pull_bit = pull,			\
		.drv_bit = drv,				\
		.oe_bit = -1,				\
		.in_bit = -1,				\
		.out_bit = -1,				\
	}

#define UFS_RESET(pg_name, offset)			\
	{						\
		.name = pg_name,			\
		.ctl_reg = offset,			\
		.io_reg = offset + 0x4,			\
		.pull_bit = 3,				\
		.drv_bit = 0,				\
		.oe_bit = -1,				\
		.in_bit = -1,				\
		.out_bit = 0,				\
	}

static const struct msm_special_pin_data sm8350_special_pins_data[] = {
	[0] = UFS_RESET("ufs_reset", 0xd8000),
	[1] = SDC_PINGROUP("sdc2_clk", 0xcf000, 14, 6),
	[2] = SDC_PINGROUP("sdc2_cmd", 0xcf000, 11, 3),
	[3] = SDC_PINGROUP("sdc2_data", 0xcf000, 9, 0),
};

static const unsigned int sm8350_pin_offsets[] = {
	[0] = 0x0,
	[1] = 0x1000,
	[2] = 0x2000,
	[3] = 0x3000,
	[4] = 0x4000,
	[5] = 0x5000,
	[6] = 0x6000,
	[7] = 0x7000,
	[8] = 0x8000,
	[9] = 0x9000,
	[10] = 0xa000,
	[11] = 0xb000,
	[12] = 0xc000,
	[13] = 0xd000,
	[14] = 0xe000,
	[15] = 0xf000,
	[16] = 0x10000,
	[17] = 0x11000,
	[18] = 0x12000,
	[19] = 0x13000,
	[20] = 0x14000,
	[21] = 0x15000,
	[22] = 0x16000,
	[23] = 0x17000,
	[24] = 0x18000,
	[25] = 0x19000,
	[26] = 0x1a000,
	[27] = 0x1b000,
	[28] = 0x1c000,
	[29] = 0x1d000,
	[30] = 0x1e000,
	[31] = 0x1f000,
	[32] = 0x20000,
	[33] = 0x21000,
	[34] = 0x22000,
	[35] = 0x23000,
	[36] = 0x24000,
	[37] = 0x25000,
	[38] = 0x26000,
	[39] = 0x27000,
	[40] = 0x28000,
	[41] = 0x29000,
	[42] = 0x2a000,
	[43] = 0x2b000,
	[44] = 0x2c000,
	[45] = 0x2d000,
	[46] = 0x2e000,
	[47] = 0x2f000,
	[48] = 0x30000,
	[49] = 0x31000,
	[50] = 0x32000,
	[51] = 0x33000,
	[52] = 0x34000,
	[53] = 0x35000,
	[54] = 0x36000,
	[55] = 0x37000,
	[56] = 0x38000,
	[57] = 0x39000,
	[58] = 0x3a000,
	[59] = 0x3b000,
	[60] = 0x3c000,
	[61] = 0x3d000,
	[62] = 0x3e000,
	[63] = 0x3f000,
	[64] = 0x40000,
	[65] = 0x41000,
	[66] = 0x42000,
	[67] = 0x43000,
	[68] = 0x44000,
	[69] = 0x45000,
	[70] = 0x46000,
	[71] = 0x47000,
	[72] = 0x48000,
	[73] = 0x49000,
	[74] = 0x4a000,
	[75] = 0x4b000,
	[76] = 0x4c000,
	[77] = 0x4d000,
	[78] = 0x4e000,
	[79] = 0x4f000,
	[80] = 0x50000,
	[81] = 0x51000,
	[82] = 0x52000,
	[83] = 0x53000,
	[84] = 0x54000,
	[85] = 0x55000,
	[86] = 0x56000,
	[87] = 0x57000,
	[88] = 0x58000,
	[89] = 0x59000,
	[90] = 0x5a000,
	[91] = 0x5b000,
	[92] = 0x5c000,
	[93] = 0x5d000,
	[94] = 0x5e000,
	[95] = 0x5f000,
	[96] = 0x60000,
	[97] = 0x61000,
	[98] = 0x62000,
	[99] = 0x63000,
	[100] = 0x64000,
	[101] = 0x65000,
	[102] = 0x66000,
	[103] = 0x67000,
	[104] = 0x68000,
	[105] = 0x69000,
	[106] = 0x6a000,
	[107] = 0x6b000,
	[108] = 0x6c000,
	[109] = 0x6d000,
	[110] = 0x6e000,
	[111] = 0x6f000,
	[112] = 0x70000,
	[113] = 0x71000,
	[114] = 0x72000,
	[115] = 0x73000,
	[116] = 0x74000,
	[117] = 0x75000,
	[118] = 0x76000,
	[119] = 0x77000,
	[120] = 0x78000,
	[121] = 0x79000,
	[122] = 0x7a000,
	[123] = 0x7b000,
	[124] = 0x7c000,
	[125] = 0x7d000,
	[126] = 0x7e000,
	[127] = 0x7f000,
	[128] = 0x80000,
	[129] = 0x81000,
	[130] = 0x82000,
	[131] = 0x83000,
	[132] = 0x84000,
	[133] = 0x85000,
	[134] = 0x86000,
	[135] = 0x87000,
	[136] = 0x88000,
	[137] = 0x89000,
	[138] = 0x8a000,
	[139] = 0x8b000,
	[140] = 0x8c000,
	[141] = 0x8d000,
	[142] = 0x8e000,
	[143] = 0x8f000,
	[144] = 0x90000,
	[145] = 0x91000,
	[146] = 0x92000,
	[147] = 0x93000,
	[148] = 0x94000,
	[149] = 0x95000,
	[150] = 0x96000,
	[151] = 0x97000,
	[152] = 0x98000,
	[153] = 0x99000,
	[154] = 0x9a000,
	[155] = 0x9b000,
	[156] = 0x9c000,
	[157] = 0x9d000,
	[158] = 0x9e000,
	[159] = 0x9f000,
	[160] = 0xa0000,
	[161] = 0xa1000,
	[162] = 0xa2000,
	[163] = 0xa3000,
	[164] = 0xa4000,
	[165] = 0xa5000,
	[166] = 0xa6000,
	[167] = 0xa7000,
	[168] = 0xa8000,
	[169] = 0xa9000,
	[170] = 0xaa000,
	[171] = 0xab000,
	[172] = 0xac000,
	[173] = 0xad000,
	[174] = 0xae000,
	[175] = 0xaf000,
	[176] = 0xb0000,
	[177] = 0xb1000,
	[178] = 0xb2000,
	[179] = 0xb3000,
	[180] = 0xb4000,
	[181] = 0xb5000,
	[182] = 0xb6000,
	[183] = 0xb7000,
	[184] = 0xb8000,
	[185] = 0xb9000,
	[186] = 0xba000,
	[187] = 0xbb000,
	[188] = 0xbc000,
	[189] = 0xbd000,
	[190] = 0xbe000,
	[191] = 0xbf000,
	[192] = 0xc0000,
	[193] = 0xc1000,
	[194] = 0xc2000,
	[195] = 0xc3000,
	[196] = 0xc4000,
	[197] = 0xc5000,
	[198] = 0xc6000,
	[199] = 0xc7000,
	[200] = 0xc8000,
	[201] = 0xc9000,
	[202] = 0xca000,
};

static const char *sm8350_get_function_name(struct udevice *dev, unsigned int selector)
{
	return msm_pinctrl_functions[selector].name;
}

static const char *sm8350_get_pin_name(struct udevice *dev, unsigned int selector)
{
	if (selector >= 203 && selector <= 206)
		snprintf(pin_name, MAX_PIN_NAME_LEN,
			 sm8350_special_pins_data[selector - 203].name);
	else
		snprintf(pin_name, MAX_PIN_NAME_LEN, "gpio%u", selector);

	return pin_name;
}

static int sm8350_get_function_mux(__maybe_unused unsigned int pin, unsigned int selector)
{
	return msm_pinctrl_functions[selector].val;
}

static struct msm_pinctrl_data sm8350_data = {
	.pin_data = {
		.pin_offsets = sm8350_pin_offsets,
		.pin_count = 207,
		.special_pins_start = 203,
		.special_pins_data = sm8350_special_pins_data,
	},
	.functions_count = ARRAY_SIZE(msm_pinctrl_functions),
	.get_function_name = sm8350_get_function_name,
	.get_function_mux = sm8350_get_function_mux,
	.get_pin_name = sm8350_get_pin_name,
};

static const struct udevice_id msm_pinctrl_ids[] = {
	{
		.compatible = "qcom,sm8350-tlmm",
		.data = (ulong)&sm8350_data
	},
	{ /* Sentinel */ } };

U_BOOT_DRIVER(pinctrl_sm8350) = {
	.name = "pinctrl_sm8350",
	.id = UCLASS_NOP,
	.of_match = msm_pinctrl_ids,
	.ops = &msm_pinctrl_ops,
	.bind = msm_pinctrl_bind,
};
