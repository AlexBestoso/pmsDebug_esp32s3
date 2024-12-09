struct pms_apb_peripheral_access_0_reg{
	uint32_t val = 0;
	uint16_t base = 0x0008;

	bool pms_apb_peripheral_access_lock = false;
	int pms_apb_peripheral_access_lock_pos = 0;

};
struct pms_apb_peripheral_access_1_reg{
	uint32_t val = 0;
	uint16_t base = 0x000c;

	bool pms_apb_peripheral_access_split_burst = true;
	int pms_apb_peripheral_access_split_burst_pos = 0;

};
struct pms_internal_sram_usage_0_reg{
	uint32_t val = 0;
	uint16_t base = 0x0010;

	bool pms_internal_sram_usage_lock = false;
	int pms_internal_sram_usage_lock_pos = 0;

};
struct pms_internal_sram_usage_1_reg{
	uint32_t val = 0;
	uint16_t base = 0x0014;

	uint32_t pms_internal_sram_cpu_usage = 0x7f;
	int pms_internal_sram_cpu_usage_x = 4;
	int pms_internal_sram_cpu_usage_y = 10;

	uint32_t pms_internal_sram_dcache_usage = 0x3;
	int pms_internal_sram_dcache_usage_x = 2;
	int pms_internal_sram_dcache_usage_y = 3;

	uint32_t pms_internal_sram_icache_usage = 0x3;
	int pms_internal_sram_icache_usage_x = 0;
	int pms_internal_sram_icache_usage_y = 1;

};
struct pms_internal_sram_usage_2_reg{
	uint32_t val = 0;
	uint16_t base = 0x0018;

	uint32_t pms_internal_sram_core1_trace_alloc = 0;
	int pms_internal_sram_core1_trace_alloc_x = 16;
	int pms_internal_sram_core1_trace_alloc_y = 17;

	uint32_t pms_internal_sram_core0_trace_alloc = 0;
	int pms_internal_sram_core0_trace_alloc_x = 14;
	int pms_internal_sram_core0_trace_alloc_y = 15;

	uint32_t pms_internal_sram_core1_trace_usage = 0;
	int pms_internal_sram_core1_trace_usage_x = 7;
	int pms_internal_sram_core1_trace_usage_y = 13;

	uint32_t pms_internal_sram_core0_trace_usage = 0;
	int pms_internal_sram_core0_trace_usage_x = 0;
	int pms_internal_sram_core0_trace_usage_y = 6;

};
struct pms_dma_apbperi_spi2_pms_constrain_0_reg{
	uint32_t val = 0;
	uint16_t base = 0x0038;

	bool pms_dma_apbperi_spi2_pms_constrain_lock = false;
	int pms_dma_apbperi_spi2_pms_constrain_lock_pos = 0;

};
struct pms_dma_apbperi_spi2_pms_constrain_1_reg{
	uint32_t val = 0;
	uint16_t base = 0x003c;

	uint32_t pms_dma_apbperi_spi2_pms_constrain_sram_cachedataarray_pms_1 = 0x3;
	int pms_dma_apbperi_spi2_pms_constrain_sram_cachedataarray_pms_1_x = 10;
	int pms_dma_apbperi_spi2_pms_constrain_sram_cachedataarray_pms_1_y = 11;

	uint32_t pms_dma_apbperi_spi2_pms_constrain_sram_cachedataarray_pms_0 = 0x3;
	int pms_dma_apbperi_spi2_pms_constrain_sram_cachedataarray_pms_0_x = 8;
	int pms_dma_apbperi_spi2_pms_constrain_sram_cachedataarray_pms_0_y = 9;

	uint32_t pms_dma_apbperi_spi2_pms_constrain_sram_pms_3 = 0x3;
	int pms_dma_apbperi_spi2_pms_constrain_sram_pms_3_x = 6;
	int pms_dma_apbperi_spi2_pms_constrain_sram_pms_3_y = 7;

	uint32_t pms_dma_apbperi_spi2_pms_constrain_sram_pms_2 = 0x3;
	int pms_dma_apbperi_spi2_pms_constrain_sram_pms_2_x = 4;
	int pms_dma_apbperi_spi2_pms_constrain_sram_pms_2_y = 5;

	uint32_t pms_dma_apbperi_spi2_pms_constrain_sram_pms_1 = 0x3;
	int pms_dma_apbperi_spi2_pms_constrain_sram_pms_1_x = 2;
	int pms_dma_apbperi_spi2_pms_constrain_sram_pms_1_y = 3;

	uint32_t pms_dma_apbperi_spi2_pms_constrain_sram_pms_0 = 0x3;
	int pms_dma_apbperi_spi2_pms_constrain_sram_pms_0_x = 0;
	int pms_dma_apbperi_spi2_pms_constrain_sram_pms_0_y = 1;

};
struct pms_dma_apbperi_spi3_pms_constrain_0_reg{
	uint32_t val = 0;
	uint16_t base = 0x0040;

	bool pms_dma_apbperi_spi3_pms_constrain_lock = false;
	int pms_dma_apbperi_spi3_pms_constrain_lock_pos = 0;

};
struct pms_dma_apbperi_spi3_pms_constrain_1_reg{
	uint32_t val = 0;
	uint16_t base = 0x0044;

	uint32_t pms_dma_apbperi_spi3_pms_constrain_sram_cachedataarray_pms_1 = 0x3;
	int pms_dma_apbperi_spi3_pms_constrain_sram_cachedataarray_pms_1_x = 10;
	int pms_dma_apbperi_spi3_pms_constrain_sram_cachedataarray_pms_1_y = 11;

	uint32_t pms_dma_apbperi_spi3_pms_constrain_sram_cachedataarray_pms_0 = 0x3;
	int pms_dma_apbperi_spi3_pms_constrain_sram_cachedataarray_pms_0_x = 8;
	int pms_dma_apbperi_spi3_pms_constrain_sram_cachedataarray_pms_0_y = 9;

	uint32_t pms_dma_apbperi_spi3_pms_constrain_sram_pms_3 = 0x3;
	int pms_dma_apbperi_spi3_pms_constrain_sram_pms_3_x = 6;
	int pms_dma_apbperi_spi3_pms_constrain_sram_pms_3_y = 7;

	uint32_t pms_dma_apbperi_spi3_pms_constrain_sram_pms_2 = 0x3;
	int pms_dma_apbperi_spi3_pms_constrain_sram_pms_2_x = 4;
	int pms_dma_apbperi_spi3_pms_constrain_sram_pms_2_y = 5;

	uint32_t pms_dma_apbperi_spi3_pms_constrain_sram_pms_1 = 0x3;
	int pms_dma_apbperi_spi3_pms_constrain_sram_pms_1_x = 2;
	int pms_dma_apbperi_spi3_pms_constrain_sram_pms_1_y = 3;

	uint32_t pms_dma_apbperi_spi3_pms_constrain_sram_pms_0 = 0x3;
	int pms_dma_apbperi_spi3_pms_constrain_sram_pms_0_x = 0;
	int pms_dma_apbperi_spi3_pms_constrain_sram_pms_0_y = 1;

};
struct pms_dma_apbperi_uhci0_pms_constrain_0_reg{
	uint32_t val = 0;
	uint16_t base = 0x0048;

	bool pms_dma_apbperi_uhci0_pms_constrain_lock = false;
	int pms_dma_apbperi_uhci0_pms_constrain_lock_pos = 0;

};
struct pms_dma_apbperi_uhci0_pms_constrain_1_reg{
	uint32_t val = 0;
	uint16_t base = 0x004c;

	uint32_t pms_dma_apbperi_uhci0_pms_constrain_sram_cachedataarray_pms_1 = 0x3;
	int pms_dma_apbperi_uhci0_pms_constrain_sram_cachedataarray_pms_1_x = 10;
	int pms_dma_apbperi_uhci0_pms_constrain_sram_cachedataarray_pms_1_y = 11;

	uint32_t pms_dma_apbperi_uhci0_pms_constrain_sram_cachedataarray_pms_0 = 0x3;
	int pms_dma_apbperi_uhci0_pms_constrain_sram_cachedataarray_pms_0_x = 8;
	int pms_dma_apbperi_uhci0_pms_constrain_sram_cachedataarray_pms_0_y = 9;

	uint32_t pms_dma_apbperi_uhci0_pms_constrain_sram_pms_3 = 0x3;
	int pms_dma_apbperi_uhci0_pms_constrain_sram_pms_3_x = 6;
	int pms_dma_apbperi_uhci0_pms_constrain_sram_pms_3_y = 7;

	uint32_t pms_dma_apbperi_uhci0_pms_constrain_sram_pms_2 = 0x3;
	int pms_dma_apbperi_uhci0_pms_constrain_sram_pms_2_x = 4;
	int pms_dma_apbperi_uhci0_pms_constrain_sram_pms_2_y = 5;

	uint32_t pms_dma_apbperi_uhci0_pms_constrain_sram_pms_1 = 0x3;
	int pms_dma_apbperi_uhci0_pms_constrain_sram_pms_1_x = 2;
	int pms_dma_apbperi_uhci0_pms_constrain_sram_pms_1_y = 3;

	uint32_t pms_dma_apbperi_uhci0_pms_constrain_sram_pms_0 = 0x3;
	int pms_dma_apbperi_uhci0_pms_constrain_sram_pms_0_x = 0;
	int pms_dma_apbperi_uhci0_pms_constrain_sram_pms_0_y = 1;

};
struct pms_dma_apbperi_i2s0_pms_constrain_0_reg{
	uint32_t val = 0;
	uint16_t base = 0x0050;

	bool pms_dma_apbperi_i2s0_pms_constrain_lock = false;
	int pms_dma_apbperi_i2s0_pms_constrain_lock_pos = 0;

};
struct pms_dma_apbperi_i2s0_pms_constrain_1_reg{
	uint32_t val = 0;
	uint16_t base = 0x0054;

	uint32_t pms_dma_apbperi_i2s0_pms_constrain_sram_cachedataarray_pms_1 = 0x3;
	int pms_dma_apbperi_i2s0_pms_constrain_sram_cachedataarray_pms_1_x = 10;
	int pms_dma_apbperi_i2s0_pms_constrain_sram_cachedataarray_pms_1_y = 11;

	uint32_t pms_dma_apbperi_i2s0_pms_constrain_sram_cachedataarray_pms_0 = 0x3;
	int pms_dma_apbperi_i2s0_pms_constrain_sram_cachedataarray_pms_0_x = 8;
	int pms_dma_apbperi_i2s0_pms_constrain_sram_cachedataarray_pms_0_y = 9;

	uint32_t pms_dma_apbperi_i2s0_pms_constrain_sram_pms_3 = 0x3;
	int pms_dma_apbperi_i2s0_pms_constrain_sram_pms_3_x = 6;
	int pms_dma_apbperi_i2s0_pms_constrain_sram_pms_3_y = 7;

	uint32_t pms_dma_apbperi_i2s0_pms_constrain_sram_pms_2 = 0x3;
	int pms_dma_apbperi_i2s0_pms_constrain_sram_pms_2_x = 4;
	int pms_dma_apbperi_i2s0_pms_constrain_sram_pms_2_y = 5;

	uint32_t pms_dma_apbperi_i2s0_pms_constrain_sram_pms_1 = 0x3;
	int pms_dma_apbperi_i2s0_pms_constrain_sram_pms_1_x = 2;
	int pms_dma_apbperi_i2s0_pms_constrain_sram_pms_1_y = 3;

	uint32_t pms_dma_apbperi_i2s0_pms_constrain_sram_pms_0 = 0x3;
	int pms_dma_apbperi_i2s0_pms_constrain_sram_pms_0_x = 0;
	int pms_dma_apbperi_i2s0_pms_constrain_sram_pms_0_y = 1;

};
struct pms_dma_apbperi_i2s1_pms_constrain_0_reg{
	uint32_t val = 0;
	uint16_t base = 0x0058;

	bool pms_dma_apbperi_i2s1_pms_constrain_lock = false;
	int pms_dma_apbperi_i2s1_pms_constrain_lock_pos = 0;

};
struct pms_dma_apbperi_i2s1_pms_constrain_1_reg{
	uint32_t val = 0;
	uint16_t base = 0x005c;

	uint32_t pms_dma_apbperi_i2s1_pms_constrain_sram_cachedataarray_pms_1 = 0x3;
	int pms_dma_apbperi_i2s1_pms_constrain_sram_cachedataarray_pms_1_x = 10;
	int pms_dma_apbperi_i2s1_pms_constrain_sram_cachedataarray_pms_1_y = 11;

	uint32_t pms_dma_apbperi_i2s1_pms_constrain_sram_cachedataarray_pms_0 = 0x3;
	int pms_dma_apbperi_i2s1_pms_constrain_sram_cachedataarray_pms_0_x = 8;
	int pms_dma_apbperi_i2s1_pms_constrain_sram_cachedataarray_pms_0_y = 9;

	uint32_t pms_dma_apbperi_i2s1_pms_constrain_sram_pms_3 = 0x3;
	int pms_dma_apbperi_i2s1_pms_constrain_sram_pms_3_x = 6;
	int pms_dma_apbperi_i2s1_pms_constrain_sram_pms_3_y = 7;

	uint32_t pms_dma_apbperi_i2s1_pms_constrain_sram_pms_2 = 0x3;
	int pms_dma_apbperi_i2s1_pms_constrain_sram_pms_2_x = 4;
	int pms_dma_apbperi_i2s1_pms_constrain_sram_pms_2_y = 5;

	uint32_t pms_dma_apbperi_i2s1_pms_constrain_sram_pms_1 = 0x3;
	int pms_dma_apbperi_i2s1_pms_constrain_sram_pms_1_x = 2;
	int pms_dma_apbperi_i2s1_pms_constrain_sram_pms_1_y = 3;

	uint32_t pms_dma_apbperi_i2s1_pms_constrain_sram_pms_0 = 0x3;
	int pms_dma_apbperi_i2s1_pms_constrain_sram_pms_0_x = 0;
	int pms_dma_apbperi_i2s1_pms_constrain_sram_pms_0_y = 1;

};
struct pms_dma_apbperi_aes_pms_constrain_0_reg{
	uint32_t val = 0;
	uint16_t base = 0x0070;

	bool pms_dma_apbperi_aes_pms_constrain_lock = false;
	int pms_dma_apbperi_aes_pms_constrain_lock_pos = 0;

};
struct pms_dma_apbperi_aes_pms_constrain_1_reg{
	uint32_t val = 0;
	uint16_t base = 0x0074;

	uint32_t pms_dma_apbperi_aes_pms_constrain_sram_cachedataarray_pms_1 = 0x3;
	int pms_dma_apbperi_aes_pms_constrain_sram_cachedataarray_pms_1_x = 10;
	int pms_dma_apbperi_aes_pms_constrain_sram_cachedataarray_pms_1_y = 11;

	uint32_t pms_dma_apbperi_aes_pms_constrain_sram_cachedataarray_pms_0 = 0x3;
	int pms_dma_apbperi_aes_pms_constrain_sram_cachedataarray_pms_0_x = 8;
	int pms_dma_apbperi_aes_pms_constrain_sram_cachedataarray_pms_0_y = 9;

	uint32_t pms_dma_apbperi_aes_pms_constrain_sram_pms_3 = 0x3;
	int pms_dma_apbperi_aes_pms_constrain_sram_pms_3_x = 6;
	int pms_dma_apbperi_aes_pms_constrain_sram_pms_3_y = 7;

	uint32_t pms_dma_apbperi_aes_pms_constrain_sram_pms_2 = 0x3;
	int pms_dma_apbperi_aes_pms_constrain_sram_pms_2_x = 4;
	int pms_dma_apbperi_aes_pms_constrain_sram_pms_2_y = 5;

	uint32_t pms_dma_apbperi_aes_pms_constrain_sram_pms_1 = 0x3;
	int pms_dma_apbperi_aes_pms_constrain_sram_pms_1_x = 2;
	int pms_dma_apbperi_aes_pms_constrain_sram_pms_1_y = 3;

	uint32_t pms_dma_apbperi_aes_pms_constrain_sram_pms_0 = 0x3;
	int pms_dma_apbperi_aes_pms_constrain_sram_pms_0_x = 0;
	int pms_dma_apbperi_aes_pms_constrain_sram_pms_0_y = 1;

};
struct pms_dma_apbperi_sha_pms_constrain_0_reg{
	uint32_t val = 0;
	uint16_t base = 0x0078;

	bool pms_dma_apbperi_sha_pms_constrain_lock = false;
	int pms_dma_apbperi_sha_pms_constrain_lock_pos = 0;

};
struct pms_dma_apbperi_sha_pms_constrain_1_reg{
	uint32_t val = 0;
	uint16_t base = 0x007c;

	uint32_t pms_dma_apbperi_sha_pms_constrain_sram_cachedataarray_pms_1 = 0x3;
	int pms_dma_apbperi_sha_pms_constrain_sram_cachedataarray_pms_1_x = 10;
	int pms_dma_apbperi_sha_pms_constrain_sram_cachedataarray_pms_1_y = 11;

	uint32_t pms_dma_apbperi_sha_pms_constrain_sram_cachedataarray_pms_0 = 0x3;
	int pms_dma_apbperi_sha_pms_constrain_sram_cachedataarray_pms_0_x = 8;
	int pms_dma_apbperi_sha_pms_constrain_sram_cachedataarray_pms_0_y = 9;

	uint32_t pms_dma_apbperi_sha_pms_constrain_sram_pms_3 = 0x3;
	int pms_dma_apbperi_sha_pms_constrain_sram_pms_3_x = 6;
	int pms_dma_apbperi_sha_pms_constrain_sram_pms_3_y = 7;

	uint32_t pms_dma_apbperi_sha_pms_constrain_sram_pms_2 = 0x3;
	int pms_dma_apbperi_sha_pms_constrain_sram_pms_2_x = 4;
	int pms_dma_apbperi_sha_pms_constrain_sram_pms_2_y = 5;

	uint32_t pms_dma_apbperi_sha_pms_constrain_sram_pms_1 = 0x3;
	int pms_dma_apbperi_sha_pms_constrain_sram_pms_1_x = 2;
	int pms_dma_apbperi_sha_pms_constrain_sram_pms_1_y = 3;

	uint32_t pms_dma_apbperi_sha_pms_constrain_sram_pms_0 = 0x3;
	int pms_dma_apbperi_sha_pms_constrain_sram_pms_0_x = 0;
	int pms_dma_apbperi_sha_pms_constrain_sram_pms_0_y = 1;

};
struct pms_dma_apbperi_adc_dac_pms_constrain_0_reg{
	uint32_t val = 0;
	uint16_t base = 0x0080;

	bool pms_dma_apbperi_adc_dac_pms_constrain_lock = false;
	int pms_dma_apbperi_adc_dac_pms_constrain_lock_pos = 0;

};
struct pms_dma_apbperi_adc_dac_pms_constrain_1_reg{
	uint32_t val = 0;
	uint16_t base = 0x0084;

	uint32_t pms_dma_apbperi_adc_dac_pms_constrain_sram_cachedataarray_pms_1 = 0x3;
	int pms_dma_apbperi_adc_dac_pms_constrain_sram_cachedataarray_pms_1_x = 10;
	int pms_dma_apbperi_adc_dac_pms_constrain_sram_cachedataarray_pms_1_y = 11;

	uint32_t pms_dma_apbperi_adc_dac_pms_constrain_sram_cachedataarray_pms_0 = 0x3;
	int pms_dma_apbperi_adc_dac_pms_constrain_sram_cachedataarray_pms_0_x = 8;
	int pms_dma_apbperi_adc_dac_pms_constrain_sram_cachedataarray_pms_0_y = 9;

	uint32_t pms_dma_apbperi_adc_dac_pms_constrain_sram_pms_3 = 0x3;
	int pms_dma_apbperi_adc_dac_pms_constrain_sram_pms_3_x = 6;
	int pms_dma_apbperi_adc_dac_pms_constrain_sram_pms_3_y = 7;

	uint32_t pms_dma_apbperi_adc_dac_pms_constrain_sram_pms_2 = 0x3;
	int pms_dma_apbperi_adc_dac_pms_constrain_sram_pms_2_x = 4;
	int pms_dma_apbperi_adc_dac_pms_constrain_sram_pms_2_y = 5;

	uint32_t pms_dma_apbperi_adc_dac_pms_constrain_sram_pms_1 = 0x3;
	int pms_dma_apbperi_adc_dac_pms_constrain_sram_pms_1_x = 2;
	int pms_dma_apbperi_adc_dac_pms_constrain_sram_pms_1_y = 3;

	uint32_t pms_dma_apbperi_adc_dac_pms_constrain_sram_pms_0 = 0x3;
	int pms_dma_apbperi_adc_dac_pms_constrain_sram_pms_0_x = 0;
	int pms_dma_apbperi_adc_dac_pms_constrain_sram_pms_0_y = 1;

};
struct pms_dma_apbperi_rmt_pms_constrain_0_reg{
	uint32_t val = 0;
	uint16_t base = 0x0088;

	bool pms_dma_apbperi_rmt_pms_constrain_lock = false;
	int pms_dma_apbperi_rmt_pms_constrain_lock_pos = 0;

};
struct pms_dma_apbperi_rmt_pms_constrain_1_reg{
	uint32_t val = 0;
	uint16_t base = 0x008c;

	uint32_t pms_dma_apbperi_rmt_pms_constrain_sram_cachedataarray_pms_1 = 0x3;
	int pms_dma_apbperi_rmt_pms_constrain_sram_cachedataarray_pms_1_x = 10;
	int pms_dma_apbperi_rmt_pms_constrain_sram_cachedataarray_pms_1_y = 11;

	uint32_t pms_dma_apbperi_rmt_pms_constrain_sram_cachedataarray_pms_0 = 0x3;
	int pms_dma_apbperi_rmt_pms_constrain_sram_cachedataarray_pms_0_x = 8;
	int pms_dma_apbperi_rmt_pms_constrain_sram_cachedataarray_pms_0_y = 9;

	uint32_t pms_dma_apbperi_rmt_pms_constrain_sram_pms_3 = 0x3;
	int pms_dma_apbperi_rmt_pms_constrain_sram_pms_3_x = 6;
	int pms_dma_apbperi_rmt_pms_constrain_sram_pms_3_y = 7;

	uint32_t pms_dma_apbperi_rmt_pms_constrain_sram_pms_2 = 0x3;
	int pms_dma_apbperi_rmt_pms_constrain_sram_pms_2_x = 4;
	int pms_dma_apbperi_rmt_pms_constrain_sram_pms_2_y = 5;

	uint32_t pms_dma_apbperi_rmt_pms_constrain_sram_pms_1 = 0x3;
	int pms_dma_apbperi_rmt_pms_constrain_sram_pms_1_x = 2;
	int pms_dma_apbperi_rmt_pms_constrain_sram_pms_1_y = 3;

	uint32_t pms_dma_apbperi_rmt_pms_constrain_sram_pms_0 = 0x3;
	int pms_dma_apbperi_rmt_pms_constrain_sram_pms_0_x = 0;
	int pms_dma_apbperi_rmt_pms_constrain_sram_pms_0_y = 1;

};
struct pms_dma_apbperi_lcd_cam_pms_constrain_0_reg{
	uint32_t val = 0;
	uint16_t base = 0x0090;

	bool pms_dma_apbperi_lcd_cam_pms_constrain_lock = false;
	int pms_dma_apbperi_lcd_cam_pms_constrain_lock_pos = 0;

};
struct pms_dma_apbperi_lcd_cam_pms_constrain_1_reg{
	uint32_t val = 0;
	uint16_t base = 0x0094;

	uint32_t pms_dma_apbperi_lcd_cam_pms_constrain_sram_cachedataarray_pms_1 = 0x3;
	int pms_dma_apbperi_lcd_cam_pms_constrain_sram_cachedataarray_pms_1_x = 10;
	int pms_dma_apbperi_lcd_cam_pms_constrain_sram_cachedataarray_pms_1_y = 11;

	uint32_t pms_dma_apbperi_lcd_cam_pms_constrain_sram_cachedataarray_pms_0 = 0x3;
	int pms_dma_apbperi_lcd_cam_pms_constrain_sram_cachedataarray_pms_0_x = 8;
	int pms_dma_apbperi_lcd_cam_pms_constrain_sram_cachedataarray_pms_0_y = 9;

	uint32_t pms_dma_apbperi_lcd_cam_pms_constrain_sram_pms_3 = 0x3;
	int pms_dma_apbperi_lcd_cam_pms_constrain_sram_pms_3_x = 6;
	int pms_dma_apbperi_lcd_cam_pms_constrain_sram_pms_3_y = 7;

	uint32_t pms_dma_apbperi_lcd_cam_pms_constrain_sram_pms_2 = 0x3;
	int pms_dma_apbperi_lcd_cam_pms_constrain_sram_pms_2_x = 4;
	int pms_dma_apbperi_lcd_cam_pms_constrain_sram_pms_2_y = 5;

	uint32_t pms_dma_apbperi_lcd_cam_pms_constrain_sram_pms_1 = 0x3;
	int pms_dma_apbperi_lcd_cam_pms_constrain_sram_pms_1_x = 2;
	int pms_dma_apbperi_lcd_cam_pms_constrain_sram_pms_1_y = 3;

	uint32_t pms_dma_apbperi_lcd_cam_pms_constrain_sram_pms_0 = 0x3;
	int pms_dma_apbperi_lcd_cam_pms_constrain_sram_pms_0_x = 0;
	int pms_dma_apbperi_lcd_cam_pms_constrain_sram_pms_0_y = 1;

};
struct pms_dma_apbperi_usb_pms_constrain_0_reg{
	uint32_t val = 0;
	uint16_t base = 0x0098;

	bool pms_dma_apbperi_usb_pms_constrain_lock = false;
	int pms_dma_apbperi_usb_pms_constrain_lock_pos = 0;

};
struct pms_dma_apbperi_usb_pms_constrain_1_reg{
	uint32_t val = 0;
	uint16_t base = 0x009c;

	uint32_t pms_dma_apbperi_usb_pms_constrain_sram_cachedataarray_pms_1 = 0x3;
	int pms_dma_apbperi_usb_pms_constrain_sram_cachedataarray_pms_1_x = 10;
	int pms_dma_apbperi_usb_pms_constrain_sram_cachedataarray_pms_1_y = 11;

	uint32_t pms_dma_apbperi_usb_pms_constrain_sram_cachedataarray_pms_0 = 0x3;
	int pms_dma_apbperi_usb_pms_constrain_sram_cachedataarray_pms_0_x = 8;
	int pms_dma_apbperi_usb_pms_constrain_sram_cachedataarray_pms_0_y = 9;

	uint32_t pms_dma_apbperi_usb_pms_constrain_sram_pms_3 = 0x3;
	int pms_dma_apbperi_usb_pms_constrain_sram_pms_3_x = 6;
	int pms_dma_apbperi_usb_pms_constrain_sram_pms_3_y = 7;

	uint32_t pms_dma_apbperi_usb_pms_constrain_sram_pms_2 = 0x3;
	int pms_dma_apbperi_usb_pms_constrain_sram_pms_2_x = 4;
	int pms_dma_apbperi_usb_pms_constrain_sram_pms_2_y = 5;

	uint32_t pms_dma_apbperi_usb_pms_constrain_sram_pms_1 = 0x3;
	int pms_dma_apbperi_usb_pms_constrain_sram_pms_1_x = 2;
	int pms_dma_apbperi_usb_pms_constrain_sram_pms_1_y = 3;

	uint32_t pms_dma_apbperi_usb_pms_constrain_sram_pms_0 = 0x3;
	int pms_dma_apbperi_usb_pms_constrain_sram_pms_0_x = 0;
	int pms_dma_apbperi_usb_pms_constrain_sram_pms_0_y = 1;

};
struct pms_dma_apbperi_sdio_pms_constrain_0_reg{
	uint32_t val = 0;
	uint16_t base = 0x00a8;

	bool pms_dma_apbperi_sdio_pms_constrain_lock = false;
	int pms_dma_apbperi_sdio_pms_constrain_lock_pos = 0;

};
struct pms_dma_apbperi_sdio_pms_constrain_1_reg{
	uint32_t val = 0;
	uint16_t base = 0x00ac;

	uint32_t pms_dma_apbperi_sdio_pms_constrain_sram_cachedataarray_pms_1 = 0x3;
	int pms_dma_apbperi_sdio_pms_constrain_sram_cachedataarray_pms_1_x = 10;
	int pms_dma_apbperi_sdio_pms_constrain_sram_cachedataarray_pms_1_y = 11;

	uint32_t pms_dma_apbperi_sdio_pms_constrain_sram_cachedataarray_pms_0 = 0x3;
	int pms_dma_apbperi_sdio_pms_constrain_sram_cachedataarray_pms_0_x = 8;
	int pms_dma_apbperi_sdio_pms_constrain_sram_cachedataarray_pms_0_y = 9;

	uint32_t pms_dma_apbperi_sdio_pms_constrain_sram_pms_3 = 0x3;
	int pms_dma_apbperi_sdio_pms_constrain_sram_pms_3_x = 6;
	int pms_dma_apbperi_sdio_pms_constrain_sram_pms_3_y = 7;

	uint32_t pms_dma_apbperi_sdio_pms_constrain_sram_pms_2 = 0x3;
	int pms_dma_apbperi_sdio_pms_constrain_sram_pms_2_x = 4;
	int pms_dma_apbperi_sdio_pms_constrain_sram_pms_2_y = 5;

	uint32_t pms_dma_apbperi_sdio_pms_constrain_sram_pms_1 = 0x3;
	int pms_dma_apbperi_sdio_pms_constrain_sram_pms_1_x = 2;
	int pms_dma_apbperi_sdio_pms_constrain_sram_pms_1_y = 3;

	uint32_t pms_dma_apbperi_sdio_pms_constrain_sram_pms_0 = 0x3;
	int pms_dma_apbperi_sdio_pms_constrain_sram_pms_0_x = 0;
	int pms_dma_apbperi_sdio_pms_constrain_sram_pms_0_y = 1;

};
struct pms_dma_apbperi_pms_monitor_0_reg{
	uint32_t val = 0;
	uint16_t base = 0x00b0;

	bool pms_dma_apbperi_pms_monitor_lock = false;
	int pms_dma_apbperi_pms_monitor_lock_pos = 0;

};
struct pms_dma_apbperi_pms_monitor_1_reg{
	uint32_t val = 0;
	uint16_t base = 0x00b4;

	bool pms_dma_apbperi_pms_monitor_violate_en = true;
	int pms_dma_apbperi_pms_monitor_violate_en_pos = 1;

	bool pms_dma_apbperi_pms_monitor_violate_clr = true;
	int pms_dma_apbperi_pms_monitor_violate_clr_pos = 0;

};
struct pms_dma_apbperi_pms_monitor_2_reg{
	uint32_t val = 0;
	uint16_t base = 0x00b8;

	uint32_t pms_dma_apbperi_pms_monitor_violate_status_addr = 0;
	int pms_dma_apbperi_pms_monitor_violate_status_addr_x = 3;
	int pms_dma_apbperi_pms_monitor_violate_status_addr_y = 24;

	uint32_t pms_dma_apbperi_pms_monitor_violate_status_world = 0;
	int pms_dma_apbperi_pms_monitor_violate_status_world_x = 1;
	int pms_dma_apbperi_pms_monitor_violate_status_world_y = 2;

	bool pms_dma_apbperi_pms_monitor_violate_intr = false;
	int pms_dma_apbperi_pms_monitor_violate_intr_pos = 0;

};
struct pms_dma_apbperi_pms_monitor_3_reg{
	uint32_t val = 0;
	uint16_t base = 0x00bc;

	uint32_t pms_dma_apbperi_pms_monitor_violate_status_byteen = 0;
	int pms_dma_apbperi_pms_monitor_violate_status_byteen_x = 1;
	int pms_dma_apbperi_pms_monitor_violate_status_byteen_y = 16;

	bool pms_dma_apbperi_pms_monitor_violate_status_wr = false;
	int pms_dma_apbperi_pms_monitor_violate_status_wr_pos = 0;

};
struct pms_core_x_iram0_dram0_dma_split_line_constrain_0_reg{
	uint32_t val = 0;
	uint16_t base = 0x00c0;

	bool pms_core_x_iram0_dram0_dma_split_line_constrain_lock = false;
	int pms_core_x_iram0_dram0_dma_split_line_constrain_lock_pos = 0;

};
struct pms_core_x_iram0_dram0_dma_split_line_constrain_1_reg{
	uint32_t val = 0;
	uint16_t base = 0x00c4;

	uint32_t pms_core_x_iram0_dram0_dma_sram_splitaddr = 0;
	int pms_core_x_iram0_dram0_dma_sram_splitaddr_x = 14;
	int pms_core_x_iram0_dram0_dma_sram_splitaddr_y = 21;

	uint32_t pms_core_x_iram0_dram0_dma_sram_category_6 = 0;
	int pms_core_x_iram0_dram0_dma_sram_category_6_x = 12;
	int pms_core_x_iram0_dram0_dma_sram_category_6_y = 13;

	uint32_t pms_core_x_iram0_dram0_dma_sram_category_5 = 0;
	int pms_core_x_iram0_dram0_dma_sram_category_5_x = 10;
	int pms_core_x_iram0_dram0_dma_sram_category_5_y = 11;

	uint32_t pms_core_x_iram0_dram0_dma_sram_category_4 = 0;
	int pms_core_x_iram0_dram0_dma_sram_category_4_x = 8;
	int pms_core_x_iram0_dram0_dma_sram_category_4_y = 9;

	uint32_t pms_core_x_iram0_dram0_dma_sram_category_3 = 0;
	int pms_core_x_iram0_dram0_dma_sram_category_3_x = 6;
	int pms_core_x_iram0_dram0_dma_sram_category_3_y = 7;

	uint32_t pms_core_x_iram0_dram0_dma_sram_category_2 = 0;
	int pms_core_x_iram0_dram0_dma_sram_category_2_x = 4;
	int pms_core_x_iram0_dram0_dma_sram_category_2_y = 5;

	uint32_t pms_core_x_iram0_dram0_dma_sram_category_1 = 0;
	int pms_core_x_iram0_dram0_dma_sram_category_1_x = 2;
	int pms_core_x_iram0_dram0_dma_sram_category_1_y = 3;

	uint32_t pms_core_x_iram0_dram0_dma_sram_category_0 = 0;
	int pms_core_x_iram0_dram0_dma_sram_category_0_x = 0;
	int pms_core_x_iram0_dram0_dma_sram_category_0_y = 1;

};
struct pms_core_x_iram0_dram0_dma_split_line_constrain_2_reg{
	uint32_t val = 0;
	uint16_t base = 0x00c8;

	uint32_t pms_core_x_iram0_sram_line_0_splitaddr = 0;
	int pms_core_x_iram0_sram_line_0_splitaddr_x = 14;
	int pms_core_x_iram0_sram_line_0_splitaddr_y = 21;

	uint32_t pms_core_x_iram0_sram_line_0_category_6 = 0;
	int pms_core_x_iram0_sram_line_0_category_6_x = 12;
	int pms_core_x_iram0_sram_line_0_category_6_y = 13;

	uint32_t pms_core_x_iram0_sram_line_0_category_5 = 0;
	int pms_core_x_iram0_sram_line_0_category_5_x = 10;
	int pms_core_x_iram0_sram_line_0_category_5_y = 11;

	uint32_t pms_core_x_iram0_sram_line_0_category_4 = 0;
	int pms_core_x_iram0_sram_line_0_category_4_x = 8;
	int pms_core_x_iram0_sram_line_0_category_4_y = 9;

	uint32_t pms_core_x_iram0_sram_line_0_category_3 = 0;
	int pms_core_x_iram0_sram_line_0_category_3_x = 6;
	int pms_core_x_iram0_sram_line_0_category_3_y = 7;

	uint32_t pms_core_x_iram0_sram_line_0_category_2 = 0;
	int pms_core_x_iram0_sram_line_0_category_2_x = 4;
	int pms_core_x_iram0_sram_line_0_category_2_y = 5;

	uint32_t pms_core_x_iram0_sram_line_0_category_1 = 0;
	int pms_core_x_iram0_sram_line_0_category_1_x = 2;
	int pms_core_x_iram0_sram_line_0_category_1_y = 3;

	uint32_t pms_core_x_iram0_sram_line_0_category_0 = 0;
	int pms_core_x_iram0_sram_line_0_category_0_x = 0;
	int pms_core_x_iram0_sram_line_0_category_0_y = 1;

};
struct pms_core_x_iram0_dram0_dma_split_line_constrain_3_reg{
	uint32_t val = 0;
	uint16_t base = 0x00cc;

	uint32_t pms_core_x_iram0_sram_line_1_splitaddr = 0;
	int pms_core_x_iram0_sram_line_1_splitaddr_x = 14;
	int pms_core_x_iram0_sram_line_1_splitaddr_y = 21;

	uint32_t pms_core_x_iram0_sram_line_1_category_6 = 0;
	int pms_core_x_iram0_sram_line_1_category_6_x = 12;
	int pms_core_x_iram0_sram_line_1_category_6_y = 13;

	uint32_t pms_core_x_iram0_sram_line_1_category_5 = 0;
	int pms_core_x_iram0_sram_line_1_category_5_x = 10;
	int pms_core_x_iram0_sram_line_1_category_5_y = 11;

	uint32_t pms_core_x_iram0_sram_line_1_category_4 = 0;
	int pms_core_x_iram0_sram_line_1_category_4_x = 8;
	int pms_core_x_iram0_sram_line_1_category_4_y = 9;

	uint32_t pms_core_x_iram0_sram_line_1_category_3 = 0;
	int pms_core_x_iram0_sram_line_1_category_3_x = 6;
	int pms_core_x_iram0_sram_line_1_category_3_y = 7;

	uint32_t pms_core_x_iram0_sram_line_1_category_2 = 0;
	int pms_core_x_iram0_sram_line_1_category_2_x = 4;
	int pms_core_x_iram0_sram_line_1_category_2_y = 5;

	uint32_t pms_core_x_iram0_sram_line_1_category_1 = 0;
	int pms_core_x_iram0_sram_line_1_category_1_x = 2;
	int pms_core_x_iram0_sram_line_1_category_1_y = 3;

	uint32_t pms_core_x_iram0_sram_line_1_category_0 = 0;
	int pms_core_x_iram0_sram_line_1_category_0_x = 0;
	int pms_core_x_iram0_sram_line_1_category_0_y = 1;

};
struct pms_core_x_iram0_dram0_dma_split_line_constrain_4_reg{
	uint32_t val = 0;
	uint16_t base = 0x00d0;

	uint32_t pms_core_x_dram0_dma_sram_line_0_splitaddr = 0;
	int pms_core_x_dram0_dma_sram_line_0_splitaddr_x = 14;
	int pms_core_x_dram0_dma_sram_line_0_splitaddr_y = 21;

	uint32_t pms_core_x_dram0_dma_sram_line_0_category_6 = 0;
	int pms_core_x_dram0_dma_sram_line_0_category_6_x = 12;
	int pms_core_x_dram0_dma_sram_line_0_category_6_y = 13;

	uint32_t pms_core_x_dram0_dma_sram_line_0_category_5 = 0;
	int pms_core_x_dram0_dma_sram_line_0_category_5_x = 10;
	int pms_core_x_dram0_dma_sram_line_0_category_5_y = 11;

	uint32_t pms_core_x_dram0_dma_sram_line_0_category_4 = 0;
	int pms_core_x_dram0_dma_sram_line_0_category_4_x = 8;
	int pms_core_x_dram0_dma_sram_line_0_category_4_y = 9;

	uint32_t pms_core_x_dram0_dma_sram_line_0_category_3 = 0;
	int pms_core_x_dram0_dma_sram_line_0_category_3_x = 6;
	int pms_core_x_dram0_dma_sram_line_0_category_3_y = 7;

	uint32_t pms_core_x_dram0_dma_sram_line_0_category_2 = 0;
	int pms_core_x_dram0_dma_sram_line_0_category_2_x = 4;
	int pms_core_x_dram0_dma_sram_line_0_category_2_y = 5;

	uint32_t pms_core_x_dram0_dma_sram_line_0_category_1 = 0;
	int pms_core_x_dram0_dma_sram_line_0_category_1_x = 2;
	int pms_core_x_dram0_dma_sram_line_0_category_1_y = 3;

	uint32_t pms_core_x_dram0_dma_sram_line_0_category_0 = 0;
	int pms_core_x_dram0_dma_sram_line_0_category_0_x = 0;
	int pms_core_x_dram0_dma_sram_line_0_category_0_y = 1;

};
struct pms_core_x_iram0_dram0_dma_split_line_constrain_5_reg{
	uint32_t val = 0;
	uint16_t base = 0x00d4;

	uint32_t pms_core_x_dram0_dma_sram_line_1_splitaddr = 0;
	int pms_core_x_dram0_dma_sram_line_1_splitaddr_x = 14;
	int pms_core_x_dram0_dma_sram_line_1_splitaddr_y = 21;

	uint32_t pms_core_x_dram0_dma_sram_line_1_category_6 = 0;
	int pms_core_x_dram0_dma_sram_line_1_category_6_x = 12;
	int pms_core_x_dram0_dma_sram_line_1_category_6_y = 13;

	uint32_t pms_core_x_dram0_dma_sram_line_1_category_5 = 0;
	int pms_core_x_dram0_dma_sram_line_1_category_5_x = 10;
	int pms_core_x_dram0_dma_sram_line_1_category_5_y = 11;

	uint32_t pms_core_x_dram0_dma_sram_line_1_category_4 = 0;
	int pms_core_x_dram0_dma_sram_line_1_category_4_x = 8;
	int pms_core_x_dram0_dma_sram_line_1_category_4_y = 9;

	uint32_t pms_core_x_dram0_dma_sram_line_1_category_3 = 0;
	int pms_core_x_dram0_dma_sram_line_1_category_3_x = 6;
	int pms_core_x_dram0_dma_sram_line_1_category_3_y = 7;

	uint32_t pms_core_x_dram0_dma_sram_line_1_category_2 = 0;
	int pms_core_x_dram0_dma_sram_line_1_category_2_x = 4;
	int pms_core_x_dram0_dma_sram_line_1_category_2_y = 5;

	uint32_t pms_core_x_dram0_dma_sram_line_1_category_1 = 0;
	int pms_core_x_dram0_dma_sram_line_1_category_1_x = 2;
	int pms_core_x_dram0_dma_sram_line_1_category_1_y = 3;

	uint32_t pms_core_x_dram0_dma_sram_line_1_category_0 = 0;
	int pms_core_x_dram0_dma_sram_line_1_category_0_x = 0;
	int pms_core_x_dram0_dma_sram_line_1_category_0_y = 1;

};
struct pms_core_x_iram0_pms_constrain_0_reg{
	uint32_t val = 0;
	uint16_t base = 0x00d8;

	bool pms_core_x_iram0_pms_constrain_lock = false;
	int pms_core_x_iram0_pms_constrain_lock_pos = 0;

};
struct pms_core_x_iram0_pms_constrain_1_reg{
	uint32_t val = 0;
	uint16_t base = 0x00dc;

	uint32_t pms_core_x_iram0_pms_constrain_rom_world_1_pms = 0x7;
	int pms_core_x_iram0_pms_constrain_rom_world_1_pms_x = 18;
	int pms_core_x_iram0_pms_constrain_rom_world_1_pms_y = 20;

	uint32_t pms_core_x_iram0_pms_constrain_sram_world_1_cachedataarray_pms_1 = 0x7;
	int pms_core_x_iram0_pms_constrain_sram_world_1_cachedataarray_pms_1_x = 15;
	int pms_core_x_iram0_pms_constrain_sram_world_1_cachedataarray_pms_1_y = 17;

	uint32_t pms_core_x_iram0_pms_constrain_sram_world_1_cachedataarray_pms_0 = 0x7;
	int pms_core_x_iram0_pms_constrain_sram_world_1_cachedataarray_pms_0_x = 12;
	int pms_core_x_iram0_pms_constrain_sram_world_1_cachedataarray_pms_0_y = 14;

	uint32_t pms_core_x_iram0_pms_constrain_sram_world_1_pms_3 = 0x7;
	int pms_core_x_iram0_pms_constrain_sram_world_1_pms_3_x = 9;
	int pms_core_x_iram0_pms_constrain_sram_world_1_pms_3_y = 11;

	uint32_t pms_core_x_iram0_pms_constrain_sram_world_1_pms_2 = 0x7;
	int pms_core_x_iram0_pms_constrain_sram_world_1_pms_2_x = 6;
	int pms_core_x_iram0_pms_constrain_sram_world_1_pms_2_y = 8;

	uint32_t pms_core_x_iram0_pms_constrain_sram_world_1_pms_1 = 0x7;
	int pms_core_x_iram0_pms_constrain_sram_world_1_pms_1_x = 3;
	int pms_core_x_iram0_pms_constrain_sram_world_1_pms_1_y = 5;

	uint32_t pms_core_x_iram0_pms_constrain_sram_world_1_pms_0 = 0x7;
	int pms_core_x_iram0_pms_constrain_sram_world_1_pms_0_x = 0;
	int pms_core_x_iram0_pms_constrain_sram_world_1_pms_0_y = 2;

};
struct pms_core_x_iram0_pms_constrain_2_reg{
	uint32_t val = 0;
	uint16_t base = 0x00e0;

	uint32_t pms_core_x_iram0_pms_constrain_rom_world_0_pms = 0x7;
	int pms_core_x_iram0_pms_constrain_rom_world_0_pms_x = 18;
	int pms_core_x_iram0_pms_constrain_rom_world_0_pms_y = 20;

	uint32_t pms_core_x_iram0_pms_constrain_sram_world_0_cachedataarray_pms_1 = 0x7;
	int pms_core_x_iram0_pms_constrain_sram_world_0_cachedataarray_pms_1_x = 15;
	int pms_core_x_iram0_pms_constrain_sram_world_0_cachedataarray_pms_1_y = 17;

	uint32_t pms_core_x_iram0_pms_constrain_sram_world_0_cachedataarray_pms_0 = 0x7;
	int pms_core_x_iram0_pms_constrain_sram_world_0_cachedataarray_pms_0_x = 12;
	int pms_core_x_iram0_pms_constrain_sram_world_0_cachedataarray_pms_0_y = 14;

	uint32_t pms_core_x_iram0_pms_constrain_sram_world_0_pms_3 = 0x7;
	int pms_core_x_iram0_pms_constrain_sram_world_0_pms_3_x = 9;
	int pms_core_x_iram0_pms_constrain_sram_world_0_pms_3_y = 11;

	uint32_t pms_core_x_iram0_pms_constrain_sram_world_0_pms_2 = 0x7;
	int pms_core_x_iram0_pms_constrain_sram_world_0_pms_2_x = 6;
	int pms_core_x_iram0_pms_constrain_sram_world_0_pms_2_y = 8;

	uint32_t pms_core_x_iram0_pms_constrain_sram_world_0_pms_1 = 0x7;
	int pms_core_x_iram0_pms_constrain_sram_world_0_pms_1_x = 3;
	int pms_core_x_iram0_pms_constrain_sram_world_0_pms_1_y = 5;

	uint32_t pms_core_x_iram0_pms_constrain_sram_world_0_pms_0 = 0x7;
	int pms_core_x_iram0_pms_constrain_sram_world_0_pms_0_x = 0;
	int pms_core_x_iram0_pms_constrain_sram_world_0_pms_0_y = 2;

};
struct pms_core_0_iram0_pms_monitor_0_reg{
	uint32_t val = 0;
	uint16_t base = 0x00e4;

	bool pms_core_0_iram0_pms_monitor_lock = false;
	int pms_core_0_iram0_pms_monitor_lock_pos = 0;

};
struct pms_core_0_iram0_pms_monitor_1_reg{
	uint32_t val = 0;
	uint16_t base = 0x00e8;

	bool pms_core_0_iram0_pms_monitor_violate_en = true;
	int pms_core_0_iram0_pms_monitor_violate_en_pos = 1;

	bool pms_core_0_iram0_pms_monitor_violate_clr = true;
	int pms_core_0_iram0_pms_monitor_violate_clr_pos = 0;

};
struct pms_core_x_dram0_pms_constrain_0_reg{
	uint32_t val = 0;
	uint16_t base = 0x00fc;

	bool pms_core_x_dram0_pms_constrain_lock = false;
	int pms_core_x_dram0_pms_constrain_lock_pos = 0;

};
struct pms_core_x_dram0_pms_constrain_1_reg{
	uint32_t val = 0;
	uint16_t base = 0x0100;

	uint32_t pms_core_x_dram0_pms_constrain_rom_world_1_pms = 0x3;
	int pms_core_x_dram0_pms_constrain_rom_world_1_pms_x = 26;
	int pms_core_x_dram0_pms_constrain_rom_world_1_pms_y = 27;

	uint32_t pms_core_x_dram0_pms_constrain_rom_world_0_pms = 0x3;
	int pms_core_x_dram0_pms_constrain_rom_world_0_pms_x = 24;
	int pms_core_x_dram0_pms_constrain_rom_world_0_pms_y = 25;

	uint32_t pms_core_x_dram0_pms_constrain_sram_world_1_cachedataarray_pms_1 = 0x3;
	int pms_core_x_dram0_pms_constrain_sram_world_1_cachedataarray_pms_1_x = 22;
	int pms_core_x_dram0_pms_constrain_sram_world_1_cachedataarray_pms_1_y = 23;

	uint32_t pms_core_x_dram0_pms_constrain_sram_world_1_cachedataarray_pms_0 = 0x3;
	int pms_core_x_dram0_pms_constrain_sram_world_1_cachedataarray_pms_0_x = 20;
	int pms_core_x_dram0_pms_constrain_sram_world_1_cachedataarray_pms_0_y = 21;

	uint32_t pms_core_x_dram0_pms_constrain_sram_world_1_pms_3 = 0x3;
	int pms_core_x_dram0_pms_constrain_sram_world_1_pms_3_x = 18;
	int pms_core_x_dram0_pms_constrain_sram_world_1_pms_3_y = 19;

	uint32_t pms_core_x_dram0_pms_constrain_sram_world_1_pms_2 = 0x3;
	int pms_core_x_dram0_pms_constrain_sram_world_1_pms_2_x = 16;
	int pms_core_x_dram0_pms_constrain_sram_world_1_pms_2_y = 17;

	uint32_t pms_core_x_dram0_pms_constrain_sram_world_1_pms_1 = 0x3;
	int pms_core_x_dram0_pms_constrain_sram_world_1_pms_1_x = 14;
	int pms_core_x_dram0_pms_constrain_sram_world_1_pms_1_y = 15;

	uint32_t pms_core_x_dram0_pms_constrain_sram_world_1_pms_0 = 0x3;
	int pms_core_x_dram0_pms_constrain_sram_world_1_pms_0_x = 12;
	int pms_core_x_dram0_pms_constrain_sram_world_1_pms_0_y = 13;

	uint32_t pms_core_x_dram0_pms_constrain_sram_world_0_cachedataarray_pms_1 = 0x3;
	int pms_core_x_dram0_pms_constrain_sram_world_0_cachedataarray_pms_1_x = 10;
	int pms_core_x_dram0_pms_constrain_sram_world_0_cachedataarray_pms_1_y = 11;

	uint32_t pms_core_x_dram0_pms_constrain_sram_world_0_cachedataarray_pms_0 = 0x3;
	int pms_core_x_dram0_pms_constrain_sram_world_0_cachedataarray_pms_0_x = 8;
	int pms_core_x_dram0_pms_constrain_sram_world_0_cachedataarray_pms_0_y = 9;

	uint32_t pms_core_x_dram0_pms_constrain_sram_world_0_pms_3 = 0x3;
	int pms_core_x_dram0_pms_constrain_sram_world_0_pms_3_x = 6;
	int pms_core_x_dram0_pms_constrain_sram_world_0_pms_3_y = 7;

	uint32_t pms_core_x_dram0_pms_constrain_sram_world_0_pms_2 = 0x3;
	int pms_core_x_dram0_pms_constrain_sram_world_0_pms_2_x = 4;
	int pms_core_x_dram0_pms_constrain_sram_world_0_pms_2_y = 5;

	uint32_t pms_core_x_dram0_pms_constrain_sram_world_0_pms_1 = 0x3;
	int pms_core_x_dram0_pms_constrain_sram_world_0_pms_1_x = 2;
	int pms_core_x_dram0_pms_constrain_sram_world_0_pms_1_y = 3;

	uint32_t pms_core_x_dram0_pms_constrain_sram_world_0_pms_0 = 0x3;
	int pms_core_x_dram0_pms_constrain_sram_world_0_pms_0_x = 0;
	int pms_core_x_dram0_pms_constrain_sram_world_0_pms_0_y = 1;

};
struct pms_core_0_dram0_pms_monitor_0_reg{
	uint32_t val = 0;
	uint16_t base = 0x0104;

	bool pms_core_0_dram0_pms_monitor_lock = false;
	int pms_core_0_dram0_pms_monitor_lock_pos = 0;

};
struct pms_core_0_dram0_pms_monitor_1_reg{
	uint32_t val = 0;
	uint16_t base = 0x0108;

	bool pms_core_0_dram0_pms_monitor_violate_en = true;
	int pms_core_0_dram0_pms_monitor_violate_en_pos = 1;

	bool pms_core_0_dram0_pms_monitor_violate_clr = true;
	int pms_core_0_dram0_pms_monitor_violate_clr_pos = 0;

};
struct pms_core_0_pif_pms_constrain_0_reg{
	uint32_t val = 0;
	uint16_t base = 0x0124;

	bool pms_core_0_pif_pms_constrain_lock = false;
	int pms_core_0_pif_pms_constrain_lock_pos = 0;

};
struct pms_core_0_pif_pms_constrain_n_reg{
	uint32_t val = 0;
	uint16_t base = 0x0128;

	uint32_t pms_core_0_pif_pms_constrain_world_0_uart1 = 0x3;
	int pms_core_0_pif_pms_constrain_world_0_uart1_x = 30;
	int pms_core_0_pif_pms_constrain_world_0_uart1_y = 31;

	uint32_t pms_core_0_pif_pms_constrain_world_0_i2s0 = 0x3;
	int pms_core_0_pif_pms_constrain_world_0_i2s0_x = 28;
	int pms_core_0_pif_pms_constrain_world_0_i2s0_y = 29;

	uint32_t pms_core_0_pif_pms_constrain_world_0_io_mux = 0x3;
	int pms_core_0_pif_pms_constrain_world_0_io_mux_x = 16;
	int pms_core_0_pif_pms_constrain_world_0_io_mux_y = 17;

	uint32_t pms_core_0_pif_pms_constrain_world_0_rtc = 0x3;
	int pms_core_0_pif_pms_constrain_world_0_rtc_x = 14;
	int pms_core_0_pif_pms_constrain_world_0_rtc_y = 15;

	uint32_t pms_core_0_pif_pms_constrain_world_0_gpio = 0x3;
	int pms_core_0_pif_pms_constrain_world_0_gpio_x = 6;
	int pms_core_0_pif_pms_constrain_world_0_gpio_y = 7;

	uint32_t pms_core_0_pif_pms_constrain_world_0_g0spi_0 = 0x3;
	int pms_core_0_pif_pms_constrain_world_0_g0spi_0_x = 4;
	int pms_core_0_pif_pms_constrain_world_0_g0spi_0_y = 5;

	uint32_t pms_core_0_pif_pms_constrain_world_0_g0spi_1 = 0x3;
	int pms_core_0_pif_pms_constrain_world_0_g0spi_1_x = 2;
	int pms_core_0_pif_pms_constrain_world_0_g0spi_1_y = 3;

	uint32_t pms_core_0_pif_pms_constrain_world_0_uart = 0x3;
	int pms_core_0_pif_pms_constrain_world_0_uart_x = 0;
	int pms_core_0_pif_pms_constrain_world_0_uart_y = 1;

};
struct pms_core_0_pif_pms_constrain_9_reg{
	uint32_t val = 0;
	uint16_t base = 0x0148;

	uint32_t pms_core_0_pif_pms_constrain_rtcfast_spltaddr_world_1 = 0x7ff;
	int pms_core_0_pif_pms_constrain_rtcfast_spltaddr_world_1_x = 11;
	int pms_core_0_pif_pms_constrain_rtcfast_spltaddr_world_1_y = 21;

	uint32_t pms_core_0_pif_pms_constrain_rtcfast_spltaddr_world_0 = 0x7ff;
	int pms_core_0_pif_pms_constrain_rtcfast_spltaddr_world_0_x = 0;
	int pms_core_0_pif_pms_constrain_rtcfast_spltaddr_world_0_y = 10;

};
struct pms_core_0_pif_pms_constrain_10_reg{
	uint32_t val = 0;
	uint16_t base = 0x014c;

	uint32_t pms_core_0_pif_pms_constrain_rtcfast_world_1_h = 0x7;
	int pms_core_0_pif_pms_constrain_rtcfast_world_1_h_x = 9;
	int pms_core_0_pif_pms_constrain_rtcfast_world_1_h_y = 11;

	uint32_t pms_core_0_pif_pms_constrain_rtcfast_world_1_l = 0x7;
	int pms_core_0_pif_pms_constrain_rtcfast_world_1_l_x = 6;
	int pms_core_0_pif_pms_constrain_rtcfast_world_1_l_y = 8;

	uint32_t pms_core_0_pif_pms_constrain_rtcfast_world_0_h = 0x7;
	int pms_core_0_pif_pms_constrain_rtcfast_world_0_h_x = 3;
	int pms_core_0_pif_pms_constrain_rtcfast_world_0_h_y = 5;

	uint32_t pms_core_0_pif_pms_constrain_rtcfast_world_0_l = 0x7;
	int pms_core_0_pif_pms_constrain_rtcfast_world_0_l_x = 0;
	int pms_core_0_pif_pms_constrain_rtcfast_world_0_l_y = 2;

};
struct pms_core_0_pif_pms_constrain_11_reg{
	uint32_t val = 0;
	uint16_t base = 0x0150;

	uint32_t pms_core_0_pif_pms_constrain_rtcslow_0_spltaddr_world_1 = 0x7ff;
	int pms_core_0_pif_pms_constrain_rtcslow_0_spltaddr_world_1_x = 11;
	int pms_core_0_pif_pms_constrain_rtcslow_0_spltaddr_world_1_y = 21;

	uint32_t pms_core_0_pif_pms_constrain_rtcslow_0_spltaddr_world_0 = 0x7ff;
	int pms_core_0_pif_pms_constrain_rtcslow_0_spltaddr_world_0_x = 0;
	int pms_core_0_pif_pms_constrain_rtcslow_0_spltaddr_world_0_y = 10;

};
struct pms_core_0_pif_pms_constrain_12_reg{
	uint32_t val = 0;
	uint16_t base = 0x0154;

	uint32_t pms_core_0_pif_pms_constrain_rtcslow_0_world_1_h = 0x7;
	int pms_core_0_pif_pms_constrain_rtcslow_0_world_1_h_x = 9;
	int pms_core_0_pif_pms_constrain_rtcslow_0_world_1_h_y = 11;

	uint32_t pms_core_0_pif_pms_constrain_rtcslow_0_world_1_l = 0x7;
	int pms_core_0_pif_pms_constrain_rtcslow_0_world_1_l_x = 6;
	int pms_core_0_pif_pms_constrain_rtcslow_0_world_1_l_y = 8;

	uint32_t pms_core_0_pif_pms_constrain_rtcslow_0_world_0_h = 0x7;
	int pms_core_0_pif_pms_constrain_rtcslow_0_world_0_h_x = 3;
	int pms_core_0_pif_pms_constrain_rtcslow_0_world_0_h_y = 5;

	uint32_t pms_core_0_pif_pms_constrain_rtcslow_0_world_0_l = 0x7;
	int pms_core_0_pif_pms_constrain_rtcslow_0_world_0_l_x = 0;
	int pms_core_0_pif_pms_constrain_rtcslow_0_world_0_l_y = 2;

};
struct pms_core_0_pif_pms_constrain_13_reg{
	uint32_t val = 0;
	uint16_t base = 0x0158;

	uint32_t pms_core_0_pif_pms_constrain_rtcslow_1_spltaddr_world_1 = 0x7ff;
	int pms_core_0_pif_pms_constrain_rtcslow_1_spltaddr_world_1_x = 11;
	int pms_core_0_pif_pms_constrain_rtcslow_1_spltaddr_world_1_y = 21;

	uint32_t pms_core_0_pif_pms_constrain_rtcslow_1_spltaddr_world_0 = 0x7ff;
	int pms_core_0_pif_pms_constrain_rtcslow_1_spltaddr_world_0_x = 0;
	int pms_core_0_pif_pms_constrain_rtcslow_1_spltaddr_world_0_y = 10;

};
struct pms_core_0_pif_pms_constrain_14_reg{
	uint32_t val = 0;
	uint16_t base = 0x015c;

	uint32_t pms_core_0_pif_pms_constrain_rtcslow_1_world_1_h = 0x7;
	int pms_core_0_pif_pms_constrain_rtcslow_1_world_1_h_x = 9;
	int pms_core_0_pif_pms_constrain_rtcslow_1_world_1_h_y = 11;

	uint32_t pms_core_0_pif_pms_constrain_rtcslow_1_world_1_l = 0x7;
	int pms_core_0_pif_pms_constrain_rtcslow_1_world_1_l_x = 6;
	int pms_core_0_pif_pms_constrain_rtcslow_1_world_1_l_y = 8;

	uint32_t pms_core_0_pif_pms_constrain_rtcslow_1_world_0_h = 0x7;
	int pms_core_0_pif_pms_constrain_rtcslow_1_world_0_h_x = 3;
	int pms_core_0_pif_pms_constrain_rtcslow_1_world_0_h_y = 5;

	uint32_t pms_core_0_pif_pms_constrain_rtcslow_1_world_0_l = 0x7;
	int pms_core_0_pif_pms_constrain_rtcslow_1_world_0_l_x = 0;
	int pms_core_0_pif_pms_constrain_rtcslow_1_world_0_l_y = 2;

};
struct pms_core_0_region_pms_constrain_0_reg{
	uint32_t val = 0;
	uint16_t base = 0x0160;

	bool pms_core_0_region_pms_constrain_lock = false;
	int pms_core_0_region_pms_constrain_lock_pos = 0;

};
struct pms_core_0_region_pms_constrain_1_reg{
	uint32_t val = 0;
	uint16_t base = 0x0164;

	uint32_t pms_core_0_region_pms_constrain_world_0_area_10 = 0x3;
	int pms_core_0_region_pms_constrain_world_0_area_10_x = 20;
	int pms_core_0_region_pms_constrain_world_0_area_10_y = 21;

	uint32_t pms_core_0_region_pms_constrain_world_0_area_9 = 0x3;
	int pms_core_0_region_pms_constrain_world_0_area_9_x = 18;
	int pms_core_0_region_pms_constrain_world_0_area_9_y = 19;

	uint32_t pms_core_0_region_pms_constrain_world_0_area_8 = 0x3;
	int pms_core_0_region_pms_constrain_world_0_area_8_x = 16;
	int pms_core_0_region_pms_constrain_world_0_area_8_y = 17;

	uint32_t pms_core_0_region_pms_constrain_world_0_area_7 = 0x3;
	int pms_core_0_region_pms_constrain_world_0_area_7_x = 14;
	int pms_core_0_region_pms_constrain_world_0_area_7_y = 15;

	uint32_t pms_core_0_region_pms_constrain_world_0_area_6 = 0x3;
	int pms_core_0_region_pms_constrain_world_0_area_6_x = 12;
	int pms_core_0_region_pms_constrain_world_0_area_6_y = 13;

	uint32_t pms_core_0_region_pms_constrain_world_0_area_5 = 0x3;
	int pms_core_0_region_pms_constrain_world_0_area_5_x = 10;
	int pms_core_0_region_pms_constrain_world_0_area_5_y = 11;

	uint32_t pms_core_0_region_pms_constrain_world_0_area_4 = 0x3;
	int pms_core_0_region_pms_constrain_world_0_area_4_x = 8;
	int pms_core_0_region_pms_constrain_world_0_area_4_y = 9;

	uint32_t pms_core_0_region_pms_constrain_world_0_area_3 = 0x3;
	int pms_core_0_region_pms_constrain_world_0_area_3_x = 6;
	int pms_core_0_region_pms_constrain_world_0_area_3_y = 7;

	uint32_t pms_core_0_region_pms_constrain_world_0_area_2 = 0x3;
	int pms_core_0_region_pms_constrain_world_0_area_2_x = 4;
	int pms_core_0_region_pms_constrain_world_0_area_2_y = 5;

	uint32_t pms_core_0_region_pms_constrain_world_0_area_1 = 0x3;
	int pms_core_0_region_pms_constrain_world_0_area_1_x = 2;
	int pms_core_0_region_pms_constrain_world_0_area_1_y = 3;

	uint32_t pms_core_0_region_pms_constrain_world_0_area_0 = 0x3;
	int pms_core_0_region_pms_constrain_world_0_area_0_x = 0;
	int pms_core_0_region_pms_constrain_world_0_area_0_y = 1;

};
struct pms_core_0_region_pms_constrain_2_reg{
	uint32_t val = 0;
	uint16_t base = 0x0168;

	uint32_t pms_core_0_region_pms_constrain_world_1_area_10 = 0x3;
	int pms_core_0_region_pms_constrain_world_1_area_10_x = 20;
	int pms_core_0_region_pms_constrain_world_1_area_10_y = 21;

	uint32_t pms_core_0_region_pms_constrain_world_1_area_9 = 0x3;
	int pms_core_0_region_pms_constrain_world_1_area_9_x = 18;
	int pms_core_0_region_pms_constrain_world_1_area_9_y = 19;

	uint32_t pms_core_0_region_pms_constrain_world_1_area_8 = 0x3;
	int pms_core_0_region_pms_constrain_world_1_area_8_x = 16;
	int pms_core_0_region_pms_constrain_world_1_area_8_y = 17;

	uint32_t pms_core_0_region_pms_constrain_world_1_area_7 = 0x3;
	int pms_core_0_region_pms_constrain_world_1_area_7_x = 14;
	int pms_core_0_region_pms_constrain_world_1_area_7_y = 15;

	uint32_t pms_core_0_region_pms_constrain_world_1_area_6 = 0x3;
	int pms_core_0_region_pms_constrain_world_1_area_6_x = 12;
	int pms_core_0_region_pms_constrain_world_1_area_6_y = 13;

	uint32_t pms_core_0_region_pms_constrain_world_1_area_5 = 0x3;
	int pms_core_0_region_pms_constrain_world_1_area_5_x = 10;
	int pms_core_0_region_pms_constrain_world_1_area_5_y = 11;

	uint32_t pms_core_0_region_pms_constrain_world_1_area_4 = 0x3;
	int pms_core_0_region_pms_constrain_world_1_area_4_x = 8;
	int pms_core_0_region_pms_constrain_world_1_area_4_y = 9;

	uint32_t pms_core_0_region_pms_constrain_world_1_area_3 = 0x3;
	int pms_core_0_region_pms_constrain_world_1_area_3_x = 6;
	int pms_core_0_region_pms_constrain_world_1_area_3_y = 7;

	uint32_t pms_core_0_region_pms_constrain_world_1_area_2 = 0x3;
	int pms_core_0_region_pms_constrain_world_1_area_2_x = 4;
	int pms_core_0_region_pms_constrain_world_1_area_2_y = 5;

	uint32_t pms_core_0_region_pms_constrain_world_1_area_1 = 0x3;
	int pms_core_0_region_pms_constrain_world_1_area_1_x = 2;
	int pms_core_0_region_pms_constrain_world_1_area_1_y = 3;

	uint32_t pms_core_0_region_pms_constrain_world_1_area_0 = 0x3;
	int pms_core_0_region_pms_constrain_world_1_area_0_x = 0;
	int pms_core_0_region_pms_constrain_world_1_area_0_y = 1;

};
struct pms_core_0_region_pms_constrain_n_reg{
	uint32_t val = 0;
	uint16_t base = 0x016c;

	uint32_t pms_core_0_region_pms_constrain_addr_0 = 0;
	int pms_core_0_region_pms_constrain_addr_0_x = 0;
	int pms_core_0_region_pms_constrain_addr_0_y = 29;

};
struct pms_core_0_pif_pms_monitor_0_reg{
	uint32_t val = 0;
	uint16_t base = 0x019c;

	bool pms_core_0_pif_pms_monitor_lock = false;
	int pms_core_0_pif_pms_monitor_lock_pos = 0;

};
struct pms_core_0_pif_pms_monitor_1_reg{
	uint32_t val = 0;
	uint16_t base = 0x01a0;

	bool pms_core_0_pif_pms_monitor_violate_en = true;
	int pms_core_0_pif_pms_monitor_violate_en_pos = 1;

	bool pms_core_0_pif_pms_monitor_violate_clr = true;
	int pms_core_0_pif_pms_monitor_violate_clr_pos = 0;

};
struct pms_core_0_pif_pms_monitor_4_reg{
	uint32_t val = 0;
	uint16_t base = 0x01ac;

	bool pms_core_0_pif_pms_monitor_nonword_violate_en = true;
	int pms_core_0_pif_pms_monitor_nonword_violate_en_pos = 1;

	bool pms_core_0_pif_pms_monitor_nonword_violate_clr = true;
	int pms_core_0_pif_pms_monitor_nonword_violate_clr_pos = 0;

};
struct pms_core_0_vecbase_override_lock_reg{
	uint32_t val = 0;
	uint16_t base = 0x01b8;

	bool pms_core_0_vecbase_override_lock = false;
	int pms_core_0_vecbase_override_lock_pos = 0;

};
struct pms_core_0_vecbase_override_0_reg{
	uint32_t val = 0;
	uint16_t base = 0x01bc;

	bool pms_core_0_vecbase_world_mask = true;
	int pms_core_0_vecbase_world_mask_pos = 0;

};
struct pms_core_0_vecbase_override_1_reg{
	uint32_t val = 0;
	uint16_t base = 0x01c0;

	uint32_t pms_core_0_vecbase_override_sel = 0;
	int pms_core_0_vecbase_override_sel_x = 22;
	int pms_core_0_vecbase_override_sel_y = 23;

	uint32_t pms_core_0_vecbase_override_world0_value = 0;
	int pms_core_0_vecbase_override_world0_value_x = 0;
	int pms_core_0_vecbase_override_world0_value_y = 21;

};
struct pms_core_0_vecbase_override_2_reg{
	uint32_t val = 0;
	uint16_t base = 0x01c4;

	uint32_t pms_core_0_vecbase_override_world1_value = 0;
	int pms_core_0_vecbase_override_world1_value_x = 0;
	int pms_core_0_vecbase_override_world1_value_y = 21;

};
struct pms_edma_boundary_lock_reg{
	uint32_t val = 0;
	uint16_t base = 0x02a8;

	bool pms_edma_boundary_lock = false;
	int pms_edma_boundary_lock_pos = 0;

};
struct pms_edma_boundary_0_reg{
	uint32_t val = 0;
	uint16_t base = 0x02ac;

	uint32_t pms_edma_boundary_0 = 0;
	int pms_edma_boundary_0_x = 0;
	int pms_edma_boundary_0_y = 13;

};
struct pms_edma_boundary_1_reg{
	uint32_t val = 0;
	uint16_t base = 0x02b0;

	uint32_t pms_edma_boundary_1 = 0x2000;
	int pms_edma_boundary_1_x = 0;
	int pms_edma_boundary_1_y = 13;

};
struct pms_edma_boundary_2_reg{
	uint32_t val = 0;
	uint16_t base = 0x02b4;

	uint32_t pms_edma_boundary_2 = 0x2000;
	int pms_edma_boundary_2_x = 0;
	int pms_edma_boundary_2_y = 13;

};
struct pms_edma_pms_spi2_lock_reg{
	uint32_t val = 0;
	uint16_t base = 0x02b8;

	bool pms_edma_pms_spi2_lock = false;
	int pms_edma_pms_spi2_lock_pos = 0;

};
struct pms_edma_pms_spi2_reg{
	uint32_t val = 0;
	uint16_t base = 0x02bc;

	uint32_t pms_edma_pms_spi2_attr2 = 3;
	int pms_edma_pms_spi2_attr2_x = 2;
	int pms_edma_pms_spi2_attr2_y = 3;

	uint32_t pms_edma_pms_spi2_attr1 = 3;
	int pms_edma_pms_spi2_attr1_x = 0;
	int pms_edma_pms_spi2_attr1_y = 1;

};
struct pms_edma_pms_spi3_lock_reg{
	uint32_t val = 0;
	uint16_t base = 0x02c0;

	bool pms_edma_pms_spi3_lock = false;
	int pms_edma_pms_spi3_lock_pos = 0;

};
struct pms_edma_pms_spi3_reg{
	uint32_t val = 0;
	uint16_t base = 0x02c4;

	uint32_t pms_edma_pms_spi3_attr2 = 3;
	int pms_edma_pms_spi3_attr2_x = 2;
	int pms_edma_pms_spi3_attr2_y = 3;

	uint32_t pms_edma_pms_spi3_attr1 = 3;
	int pms_edma_pms_spi3_attr1_x = 0;
	int pms_edma_pms_spi3_attr1_y = 1;

};
struct pms_edma_pms_uhci0_lock_reg{
	uint32_t val = 0;
	uint16_t base = 0x02c8;

	bool pms_edma_pms_uhci0_lock = false;
	int pms_edma_pms_uhci0_lock_pos = 0;

};
struct pms_edma_pms_uhci0_reg{
	uint32_t val = 0;
	uint16_t base = 0x02cc;

	uint32_t pms_edma_pms_uhci0_attr2 = 3;
	int pms_edma_pms_uhci0_attr2_x = 2;
	int pms_edma_pms_uhci0_attr2_y = 3;

	uint32_t pms_edma_pms_uhci0_attr1 = 3;
	int pms_edma_pms_uhci0_attr1_x = 0;
	int pms_edma_pms_uhci0_attr1_y = 1;

};
struct pms_edma_pms_i2s0_lock_reg{
	uint32_t val = 0;
	uint16_t base = 0x02d0;

	bool pms_edma_pms_i2s0_lock = false;
	int pms_edma_pms_i2s0_lock_pos = 0;

};
struct pms_edma_pms_i2s0_reg{
	uint32_t val = 0;
	uint16_t base = 0x02d4;

	uint32_t pms_edma_pms_i2s0_attr2 = 3;
	int pms_edma_pms_i2s0_attr2_x = 2;
	int pms_edma_pms_i2s0_attr2_y = 3;

	uint32_t pms_edma_pms_i2s0_attr1 = 3;
	int pms_edma_pms_i2s0_attr1_x = 0;
	int pms_edma_pms_i2s0_attr1_y = 1;

};
struct pms_edma_pms_i2s1_lock_reg{
	uint32_t val = 0;
	uint16_t base = 0x02d8;

	bool pms_edma_pms_i2s1_lock = false;
	int pms_edma_pms_i2s1_lock_pos = 0;

};
struct pms_edma_pms_i2s1_reg{
	uint32_t val = 0;
	uint16_t base = 0x02dc;

	uint32_t pms_edma_pms_i2s1_attr2 = 3;
	int pms_edma_pms_i2s1_attr2_x = 2;
	int pms_edma_pms_i2s1_attr2_y = 3;

	uint32_t pms_edma_pms_i2s1_attr1 = 3;
	int pms_edma_pms_i2s1_attr1_x = 0;
	int pms_edma_pms_i2s1_attr1_y = 1;

};
struct pms_edma_pms_lcd_cam_lock_reg{
	uint32_t val = 0;
	uint16_t base = 0x02e0;

	bool pms_edma_pms_lcd_cam_lock = false;
	int pms_edma_pms_lcd_cam_lock_pos = 0;

};
struct pms_edma_pms_lcd_cam_reg{
	uint32_t val = 0;
	uint16_t base = 0x02e4;

	uint32_t pms_edma_pms_lcd_cam_attr2 = 3;
	int pms_edma_pms_lcd_cam_attr2_x = 2;
	int pms_edma_pms_lcd_cam_attr2_y = 3;

	uint32_t pms_edma_pms_lcd_cam_attr1 = 3;
	int pms_edma_pms_lcd_cam_attr1_x = 0;
	int pms_edma_pms_lcd_cam_attr1_y = 1;

};
struct pms_edma_pms_aes_lock_reg{
	uint32_t val = 0;
	uint16_t base = 0x02e8;

	bool pms_edma_pms_aes_lock = false;
	int pms_edma_pms_aes_lock_pos = 0;

};
struct pms_edma_pms_aes_reg{
	uint32_t val = 0;
	uint16_t base = 0x02ec;

	uint32_t pms_edma_pms_aes_attr2 = 3;
	int pms_edma_pms_aes_attr2_x = 2;
	int pms_edma_pms_aes_attr2_y = 3;

	uint32_t pms_edma_pms_aes_attr1 = 3;
	int pms_edma_pms_aes_attr1_x = 0;
	int pms_edma_pms_aes_attr1_y = 1;

};
struct pms_edma_pms_sha_lock_reg{
	uint32_t val = 0;
	uint16_t base = 0x02f0;

	bool pms_edma_pms_sha_lock = false;
	int pms_edma_pms_sha_lock_pos = 0;

};
struct pms_edma_pms_sha_reg{
	uint32_t val = 0;
	uint16_t base = 0x02f4;

	uint32_t pms_edma_pms_sha_attr2 = 3;
	int pms_edma_pms_sha_attr2_x = 2;
	int pms_edma_pms_sha_attr2_y = 3;

	uint32_t pms_edma_pms_sha_attr1 = 3;
	int pms_edma_pms_sha_attr1_x = 0;
	int pms_edma_pms_sha_attr1_y = 1;

};
struct pms_edma_pms_adc_dac_lock_reg{
	uint32_t val = 0;
	uint16_t base = 0x02f8;

	bool pms_edma_pms_adc_dac_lock = false;
	int pms_edma_pms_adc_dac_lock_pos = 0;

};
struct pms_edma_pms_adc_dac_reg{
	uint32_t val = 0;
	uint16_t base = 0x02fc;

	uint32_t pms_edma_pms_adc_dac_attr2 = 3;
	int pms_edma_pms_adc_dac_attr2_x = 2;
	int pms_edma_pms_adc_dac_attr2_y = 3;

	uint32_t pms_edma_pms_adc_dac_attr1 = 3;
	int pms_edma_pms_adc_dac_attr1_x = 0;
	int pms_edma_pms_adc_dac_attr1_y = 1;

};
struct pms_edma_pms_rmt_lock_reg{
	uint32_t val = 0;
	uint16_t base = 0x0300;

	bool pms_edma_pms_rmt_lock = false;
	int pms_edma_pms_rmt_lock_pos = 0;

};
struct pms_edma_pms_rmt_reg{
	uint32_t val = 0;
	uint16_t base = 0x0304;

	uint32_t pms_edma_pms_rmt_attr2 = 3;
	int pms_edma_pms_rmt_attr2_x = 2;
	int pms_edma_pms_rmt_attr2_y = 3;

	uint32_t pms_edma_pms_rmt_attr1 = 3;
	int pms_edma_pms_rmt_attr1_x = 0;
	int pms_edma_pms_rmt_attr1_y = 1;

};
struct pms_clock_gate_reg{
	uint32_t val = 0;
	uint16_t base = 0x0308;

	bool pms_reg_clk_en = true;
	int pms_reg_clk_en_pos = 0;

};
struct pms_core_0_iram0_pms_monitor_2_reg{
	uint32_t val = 0;
	uint16_t base = 0x00ec;

	uint32_t pms_core_0_iram0_pms_monitor_violate_status_addr = 0;
	int pms_core_0_iram0_pms_monitor_violate_status_addr_x = 5;
	int pms_core_0_iram0_pms_monitor_violate_status_addr_y = 28;

	uint32_t pms_core_0_iram0_pms_monitor_violate_status_world = 0;
	int pms_core_0_iram0_pms_monitor_violate_status_world_x = 3;
	int pms_core_0_iram0_pms_monitor_violate_status_world_y = 4;

	bool pms_core_0_iram0_pms_monitor_violate_status_loadstore = false;
	int pms_core_0_iram0_pms_monitor_violate_status_loadstore_pos = 2;

	bool pms_core_0_iram0_pms_monitor_violate_status_wr = false;
	int pms_core_0_iram0_pms_monitor_violate_status_wr_pos = 1;

	bool pms_core_0_iram0_pms_monitor_violate_intr = false;
	int pms_core_0_iram0_pms_monitor_violate_intr_pos = 0;

};
struct pms_core_0_dram0_pms_monitor_2_reg{
	uint32_t val = 0;
	uint16_t base = 0x010c;

	uint32_t pms_core_0_dram0_pms_monitor_violate_status_addr = 0;
	int pms_core_0_dram0_pms_monitor_violate_status_addr_x = 4;
	int pms_core_0_dram0_pms_monitor_violate_status_addr_y = 25;

	uint32_t pms_core_0_dram0_pms_monitor_violate_status_world = 0;
	int pms_core_0_dram0_pms_monitor_violate_status_world_x = 2;
	int pms_core_0_dram0_pms_monitor_violate_status_world_y = 3;

	bool pms_core_0_dram0_pms_monitor_violate_status_lock = false;
	int pms_core_0_dram0_pms_monitor_violate_status_lock_pos = 1;

	bool pms_core_0_dram0_pms_monitor_violate_intr = false;
	int pms_core_0_dram0_pms_monitor_violate_intr_pos = 0;

};
struct pms_core_0_dram0_pms_monitor_3_reg{
	uint32_t val = 0;
	uint16_t base = 0x0110;

	uint32_t pms_core_0_dram0_pms_monitor_violate_status_byteen = 0;
	int pms_core_0_dram0_pms_monitor_violate_status_byteen_x = 1;
	int pms_core_0_dram0_pms_monitor_violate_status_byteen_y = 16;

	bool pms_core_0_dram0_pms_monitor_violate_status_wr = false;
	int pms_core_0_dram0_pms_monitor_violate_status_wr_pos = 0;

};
struct pms_core_0_pif_pms_monitor_2_reg{
	uint32_t val = 0;
	uint16_t base = 0x01a4;

	uint32_t pms_core_0_pif_pms_monitor_violate_status_hworld = 0;
	int pms_core_0_pif_pms_monitor_violate_status_hworld_x = 6;
	int pms_core_0_pif_pms_monitor_violate_status_hworld_y = 7;

	bool pms_core_0_pif_pms_monitor_violate_status_hwrite = false;
	int pms_core_0_pif_pms_monitor_violate_status_hwrite_pos = 5;

	uint32_t pms_core_0_pif_pms_monitor_violate_status_hsize = 0;
	int pms_core_0_pif_pms_monitor_violate_status_hsize_x = 2;
	int pms_core_0_pif_pms_monitor_violate_status_hsize_y = 4;

	bool pms_core_0_pif_pms_monitor_violate_status_hport_0 = false;
	int pms_core_0_pif_pms_monitor_violate_status_hport_0_pos = 1;

	bool pms_core_0_pif_pms_monitor_violate_intr = false;
	int pms_core_0_pif_pms_monitor_violate_intr_pos = 0;

};
struct pms_core_0_pif_pms_monitor_3_reg{
	uint32_t val = 0;
	uint16_t base = 0x01a8;

	uint32_t pms_core_0_pif_pms_monitor_violate_status_haddr = 0;
	int pms_core_0_pif_pms_monitor_violate_status_haddr_x = 0;
	int pms_core_0_pif_pms_monitor_violate_status_haddr_y = 31;

};
struct pms_core_0_pif_pms_monitor_5_reg{
	uint32_t val = 0;
	uint16_t base = 0x01b0;

	uint32_t pms_core_0_pif_pms_monitor_nonword_violate_status_hworld = 0;
	int pms_core_0_pif_pms_monitor_nonword_violate_status_hworld_x = 3;
	int pms_core_0_pif_pms_monitor_nonword_violate_status_hworld_y = 4;

	uint32_t pms_core_0_pif_pms_monitor_nonword_violate_status_hsize = 0;
	int pms_core_0_pif_pms_monitor_nonword_violate_status_hsize_x = 1;
	int pms_core_0_pif_pms_monitor_nonword_violate_status_hsize_y = 2;

	bool pms_core_0_pif_pms_monitor_nonword_violate_intr = false;
	int pms_core_0_pif_pms_monitor_nonword_violate_intr_pos = 0;

};
struct pms_core_0_pif_pms_monitor_6_reg{
	uint32_t val = 0;
	uint16_t base = 0x01b4;

	uint32_t pms_core_0_pif_pms_monitor_nonword_violate_status_haddr = 0;
	int pms_core_0_pif_pms_monitor_nonword_violate_status_haddr_x = 0;
	int pms_core_0_pif_pms_monitor_nonword_violate_status_haddr_y = 31;

};
struct pms_date_reg{
	uint32_t val = 0;
	uint16_t base = 0x0ffc;

	uint32_t pms_date = 0x2101280;
	int pms_date_x = 0;
	int pms_date_y = 27;

};
struct apb_ctrl_ext_mem_pms_lock_reg{
	uint32_t val = 0;
	uint16_t base = 0x0020;

	bool apb_ctrl_ext_mem_pms_lock = false;
	int apb_ctrl_ext_mem_pms_lock_pos = 0;

};
struct apb_ctrl_flash_acen_attr_reg{
	uint32_t val = 0;
	uint16_t base = 0x0028;

	uint32_t apb_ctrl_flash_acen_attr = 0xff;
	int apb_ctrl_flash_acen_attr_x = 0;
	int apb_ctrl_flash_acen_attr_y = 8;

};
struct apb_ctrl_flash_acen_addr_reg{
	uint32_t val = 0;
	uint16_t base = 0x0038;

	uint32_t apb_ctrl_flash_acen_addr_s = 0x000000;
	int apb_ctrl_flash_acen_addr_s_x = 0;
	int apb_ctrl_flash_acen_addr_s_y = 31;

};
struct apb_ctrl_flash_acen_size_reg{
	uint32_t val = 0;
	uint16_t base = 0x0048;

	uint32_t apb_ctrl_flash_acen_size = 0x1000;
	int apb_ctrl_flash_acen_size_x = 0;
	int apb_ctrl_flash_acen_size_y = 15;

};
struct apb_ctrl_sram_acen_attr_reg{
	uint32_t val = 0;
	uint16_t base = 0x0058;

	uint32_t apb_ctrl_sram_acen_attr = 0xff;
	int apb_ctrl_sram_acen_attr_x = 0;
	int apb_ctrl_sram_acen_attr_y = 8;

};
struct apb_ctrl_sram_acen_addr_reg{
	uint32_t val = 0;
	uint16_t base = 0x0068;

	uint32_t apb_ctrl_sram_acen_addr_s = 0x000000;
	int apb_ctrl_sram_acen_addr_s_x = 0;
	int apb_ctrl_sram_acen_addr_s_y = 31;

};
struct apb_ctrl_sram_acen_size_reg{
	uint32_t val = 0;
	uint16_t base = 0x0078;

	uint32_t apb_ctrl_sram_acen_size = 0x1000;
	int apb_ctrl_sram_acen_size_x = 0;
	int apb_ctrl_sram_acen_size_y = 15;

};
struct apb_ctrl_spi_mem_pms_ctrl_reg{
	uint32_t val = 0;
	uint16_t base = 0x0088;

	uint32_t apb_ctrl_spi_mem_reject_cde = 0x0;
	int apb_ctrl_spi_mem_reject_cde_x = 2;
	int apb_ctrl_spi_mem_reject_cde_y = 6;

	bool apb_ctrl_spi_mem_reject_clr = false;
	int apb_ctrl_spi_mem_reject_clr_pos = 1;

	bool apb_ctrl_spi_mem_reject_int = false;
	int apb_ctrl_spi_mem_reject_int_pos = 0;

};
struct apb_ctrl_spi_mem_reject_addr_reg{
	uint32_t val = 0;
	uint16_t base = 0x008c;

	uint32_t apb_ctrl_spi_mem_reject_addr = 0x000000;
	int apb_ctrl_spi_mem_reject_addr_x = 0;
	int apb_ctrl_spi_mem_reject_addr_y = 31;

};
