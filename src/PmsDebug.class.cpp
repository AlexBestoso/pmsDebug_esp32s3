#include <Arduino.h>
#include <cstdint>
#include "./PmsDebug.class.h"

PmsDebug::PmsDebug(void){

}

PmsDebug::~PmsDebug(){

}

/* Private */
void PmsDebug::regWrite(bool sensitive, uint32_t reg, uint32_t val){
        reg = reg;
	if(sensitive)
	        DBG_SENSITIVE_WRITE(reg, val);
	else
		DBG_APB_WRITE(reg, val);
}
uint32_t PmsDebug::regRead(bool sensitive,uint32_t reg){
        reg = reg;
	if(sensitive)
	        return DBG_SENSITIVE_READ(reg);
	else
		return DBG_APB_READ(reg);
}

// Helps isoltate fields within the 32 bit registers.
bool PmsDebug::regGet(uint32_t val, int pos){
        int grabber = 1 << pos;
        int result = (val & grabber) >> pos;
        return result == 1 ? true : false;
}
int PmsDebug::regGet(uint32_t val, int x, int y){
        int retSize = (y-x)+1;
        int grabber = 0;
        for(int i=0; i<retSize;i++)
                grabber = (grabber <<1)+1;
        int result = (val & (grabber << x)) >> x;
        return result;
}

// Helps convert register structs into single register values
uint32_t PmsDebug::regSet(uint32_t reg, bool val, int pos){
        int v = val ? 1 : 0;
        reg &= ~(1<<pos);
        reg += (v<<pos);
        return reg;
}

uint32_t PmsDebug::regSet(uint32_t reg, int val, int x, int y){
        int s = y - x;
        int g = 0;
        for(int i=0; i<s; i++)
                g = (g << 1) + 1;
        val &= g;
        reg &= ~(1<<x);
        reg += (val << x);
        return reg;
}

/* PUBLIC */
void PmsDebug::init(void){
	 this->init_apb_peripheral_access_0();
	 this->init_apb_peripheral_access_1();
	 this->init_internal_sram_usage_0();
	 this->init_internal_sram_usage_1();
	 this->init_internal_sram_usage_2();
	 this->init_dma_apbperi_spi2_pms_constrain_0();
	 this->init_dma_apbperi_spi2_pms_constrain_1();
	 this->init_dma_apbperi_spi3_pms_constrain_0();
	 this->init_dma_apbperi_spi3_pms_constrain_1();
	 this->init_dma_apbperi_uhci0_pms_constrain_0();
	 this->init_dma_apbperi_uhci0_pms_constrain_1();
	 this->init_dma_apbperi_i2s0_pms_constrain_0();
	 this->init_dma_apbperi_i2s0_pms_constrain_1();
	 this->init_dma_apbperi_i2s1_pms_constrain_0();
	 this->init_dma_apbperi_i2s1_pms_constrain_1();
	 this->init_dma_apbperi_aes_pms_constrain_0();
	 this->init_dma_apbperi_aes_pms_constrain_1();
	 this->init_dma_apbperi_sha_pms_constrain_0();
	 this->init_dma_apbperi_sha_pms_constrain_1();
	 this->init_dma_apbperi_adc_dac_pms_constrain_0();
	 this->init_dma_apbperi_adc_dac_pms_constrain_1();
	 this->init_dma_apbperi_rmt_pms_constrain_0();
	 this->init_dma_apbperi_rmt_pms_constrain_1();
	 this->init_dma_apbperi_lcd_cam_pms_constrain_0();
	 this->init_dma_apbperi_lcd_cam_pms_constrain_1();
	 this->init_dma_apbperi_usb_pms_constrain_0();
	 this->init_dma_apbperi_usb_pms_constrain_1();
	 this->init_dma_apbperi_sdio_pms_constrain_0();
	 this->init_dma_apbperi_sdio_pms_constrain_1();
	 this->init_dma_apbperi_pms_monitor_0();
	 this->init_dma_apbperi_pms_monitor_1();
	 this->init_dma_apbperi_pms_monitor_2();
	 this->init_dma_apbperi_pms_monitor_3();
	 this->init_core_x_iram0_dram0_dma_split_line_constrain_0();
	 this->init_core_x_iram0_dram0_dma_split_line_constrain_1();
	 this->init_core_x_iram0_dram0_dma_split_line_constrain_2();
	 this->init_core_x_iram0_dram0_dma_split_line_constrain_3();
	 this->init_core_x_iram0_dram0_dma_split_line_constrain_4();
	 this->init_core_x_iram0_dram0_dma_split_line_constrain_5();
	 this->init_core_x_iram0_pms_constrain_0();
	 this->init_core_x_iram0_pms_constrain_1();
	 this->init_core_x_iram0_pms_constrain_2();
	 this->init_core_0_iram0_pms_monitor_0();
	 this->init_core_0_iram0_pms_monitor_1();
	 this->init_core_x_dram0_pms_constrain_0();
	 this->init_core_x_dram0_pms_constrain_1();
	 this->init_core_0_dram0_pms_monitor_0();
	 this->init_core_0_dram0_pms_monitor_1();
	 this->init_core_0_pif_pms_constrain_0();
	 this->init_core_0_pif_pms_constrain_n();
	 this->init_core_0_pif_pms_constrain_9();
	 this->init_core_0_pif_pms_constrain_10();
	 this->init_core_0_pif_pms_constrain_11();
	 this->init_core_0_pif_pms_constrain_12();
	 this->init_core_0_pif_pms_constrain_13();
	 this->init_core_0_pif_pms_constrain_14();
	 this->init_core_0_region_pms_constrain_0();
	 this->init_core_0_region_pms_constrain_1();
	 this->init_core_0_region_pms_constrain_2();
	 this->init_core_0_region_pms_constrain_n();
	 this->init_core_0_pif_pms_monitor_0();
	 this->init_core_0_pif_pms_monitor_1();
	 this->init_core_0_pif_pms_monitor_4();
	 this->init_core_0_vecbase_override_lock();
	 this->init_core_0_vecbase_override_0();
	 this->init_core_0_vecbase_override_1();
	 this->init_core_0_vecbase_override_2();
	 this->init_edma_boundary_lock();
	 this->init_edma_boundary_0();
	 this->init_edma_boundary_1();
	 this->init_edma_boundary_2();
	 this->init_edma_pms_spi2_lock();
	 this->init_edma_pms_spi2();
	 this->init_edma_pms_spi3_lock();
	 this->init_edma_pms_spi3();
	 this->init_edma_pms_uhci0_lock();
	 this->init_edma_pms_uhci0();
	 this->init_edma_pms_i2s0_lock();
	 this->init_edma_pms_i2s0();
	 this->init_edma_pms_i2s1_lock();
	 this->init_edma_pms_i2s1();
	 this->init_edma_pms_lcd_cam_lock();
	 this->init_edma_pms_lcd_cam();
	 this->init_edma_pms_aes_lock();
	 this->init_edma_pms_aes();
	 this->init_edma_pms_sha_lock();
	 this->init_edma_pms_sha();
	 this->init_edma_pms_adc_dac_lock();
	 this->init_edma_pms_adc_dac();
	 this->init_edma_pms_rmt_lock();
	 this->init_edma_pms_rmt();
	 this->init_clock_gate();
	 this->init_core_0_iram0_pms_monitor_2();
	 this->init_core_0_dram0_pms_monitor_2();
	 this->init_core_0_dram0_pms_monitor_3();
	 this->init_core_0_pif_pms_monitor_2();
	 this->init_core_0_pif_pms_monitor_3();
	 this->init_core_0_pif_pms_monitor_5();
	 this->init_core_0_pif_pms_monitor_6();
	 this->init_date();
	 this->init_ctrl_ext_mem_pms_lock();
	 this->init_ctrl_flash_acen_attr();
	 this->init_ctrl_flash_acen_addr();
	 this->init_ctrl_flash_acen_size();
	 this->init_ctrl_sram_acen_attr();
	 this->init_ctrl_sram_acen_addr();
	 this->init_ctrl_sram_acen_size();
	 this->init_ctrl_spi_mem_pms_ctrl();
	 this->init_ctrl_spi_mem_reject_addr();
	
}
void PmsDebug::init_apb_peripheral_access_0(void){
	uint16_t base = this->apb_peripheral_access_0.base;
	this->apb_peripheral_access_0.val = this->regRead(true, base);
	this->apb_peripheral_access_0.pms_apb_peripheral_access_lock = this->regGet(
		this->apb_peripheral_access_0.val,
		this->apb_peripheral_access_0.pms_apb_peripheral_access_lock_pos
	);
}
void PmsDebug::init_apb_peripheral_access_1(void){
	uint16_t base = this->apb_peripheral_access_1.base;
	this->apb_peripheral_access_1.val = this->regRead(true, base);
	this->apb_peripheral_access_1.pms_apb_peripheral_access_split_burst = this->regGet(
		this->apb_peripheral_access_1.val,
		this->apb_peripheral_access_1.pms_apb_peripheral_access_split_burst_pos
	);
}
void PmsDebug::init_internal_sram_usage_0(void){
	uint16_t base = this->internal_sram_usage_0.base;
	this->internal_sram_usage_0.val = this->regRead(true, base);
	this->internal_sram_usage_0.pms_internal_sram_usage_lock = this->regGet(
		this->internal_sram_usage_0.val,
		this->internal_sram_usage_0.pms_internal_sram_usage_lock_pos
	);
}
void PmsDebug::init_internal_sram_usage_1(void){
	uint16_t base = this->internal_sram_usage_1.base;
	this->internal_sram_usage_1.val = this->regRead(true, base);
	this->internal_sram_usage_1.pms_internal_sram_cpu_usage = this->regGet(
		this->internal_sram_usage_1.val,
		this->internal_sram_usage_1.pms_internal_sram_cpu_usage_x,
		this->internal_sram_usage_1.pms_internal_sram_cpu_usage_y
	);
	this->internal_sram_usage_1.pms_internal_sram_dcache_usage = this->regGet(
		this->internal_sram_usage_1.val,
		this->internal_sram_usage_1.pms_internal_sram_dcache_usage_x,
		this->internal_sram_usage_1.pms_internal_sram_dcache_usage_y
	);
	this->internal_sram_usage_1.pms_internal_sram_icache_usage = this->regGet(
		this->internal_sram_usage_1.val,
		this->internal_sram_usage_1.pms_internal_sram_icache_usage_x,
		this->internal_sram_usage_1.pms_internal_sram_icache_usage_y
	);
}
void PmsDebug::init_internal_sram_usage_2(void){
	uint16_t base = this->internal_sram_usage_2.base;
	this->internal_sram_usage_2.val = this->regRead(true, base);
	this->internal_sram_usage_2.pms_internal_sram_core1_trace_alloc = this->regGet(
		this->internal_sram_usage_2.val,
		this->internal_sram_usage_2.pms_internal_sram_core1_trace_alloc_x,
		this->internal_sram_usage_2.pms_internal_sram_core1_trace_alloc_y
	);
	this->internal_sram_usage_2.pms_internal_sram_core0_trace_alloc = this->regGet(
		this->internal_sram_usage_2.val,
		this->internal_sram_usage_2.pms_internal_sram_core0_trace_alloc_x,
		this->internal_sram_usage_2.pms_internal_sram_core0_trace_alloc_y
	);
	this->internal_sram_usage_2.pms_internal_sram_core1_trace_usage = this->regGet(
		this->internal_sram_usage_2.val,
		this->internal_sram_usage_2.pms_internal_sram_core1_trace_usage_x,
		this->internal_sram_usage_2.pms_internal_sram_core1_trace_usage_y
	);
	this->internal_sram_usage_2.pms_internal_sram_core0_trace_usage = this->regGet(
		this->internal_sram_usage_2.val,
		this->internal_sram_usage_2.pms_internal_sram_core0_trace_usage_x,
		this->internal_sram_usage_2.pms_internal_sram_core0_trace_usage_y
	);
}
void PmsDebug::init_dma_apbperi_spi2_pms_constrain_0(void){
	uint16_t base = this->dma_apbperi_spi2_pms_constrain_0.base;
	this->dma_apbperi_spi2_pms_constrain_0.val = this->regRead(true, base);
	this->dma_apbperi_spi2_pms_constrain_0.pms_dma_apbperi_spi2_pms_constrain_lock = this->regGet(
		this->dma_apbperi_spi2_pms_constrain_0.val,
		this->dma_apbperi_spi2_pms_constrain_0.pms_dma_apbperi_spi2_pms_constrain_lock_pos
	);
}
void PmsDebug::init_dma_apbperi_spi2_pms_constrain_1(void){
	uint16_t base = this->dma_apbperi_spi2_pms_constrain_1.base;
	this->dma_apbperi_spi2_pms_constrain_1.val = this->regRead(true, base);
	this->dma_apbperi_spi2_pms_constrain_1.pms_dma_apbperi_spi2_pms_constrain_sram_cachedataarray_pms_1 = this->regGet(
		this->dma_apbperi_spi2_pms_constrain_1.val,
		this->dma_apbperi_spi2_pms_constrain_1.pms_dma_apbperi_spi2_pms_constrain_sram_cachedataarray_pms_1_x,
		this->dma_apbperi_spi2_pms_constrain_1.pms_dma_apbperi_spi2_pms_constrain_sram_cachedataarray_pms_1_y
	);
	this->dma_apbperi_spi2_pms_constrain_1.pms_dma_apbperi_spi2_pms_constrain_sram_cachedataarray_pms_0 = this->regGet(
		this->dma_apbperi_spi2_pms_constrain_1.val,
		this->dma_apbperi_spi2_pms_constrain_1.pms_dma_apbperi_spi2_pms_constrain_sram_cachedataarray_pms_0_x,
		this->dma_apbperi_spi2_pms_constrain_1.pms_dma_apbperi_spi2_pms_constrain_sram_cachedataarray_pms_0_y
	);
	this->dma_apbperi_spi2_pms_constrain_1.pms_dma_apbperi_spi2_pms_constrain_sram_pms_3 = this->regGet(
		this->dma_apbperi_spi2_pms_constrain_1.val,
		this->dma_apbperi_spi2_pms_constrain_1.pms_dma_apbperi_spi2_pms_constrain_sram_pms_3_x,
		this->dma_apbperi_spi2_pms_constrain_1.pms_dma_apbperi_spi2_pms_constrain_sram_pms_3_y
	);
	this->dma_apbperi_spi2_pms_constrain_1.pms_dma_apbperi_spi2_pms_constrain_sram_pms_2 = this->regGet(
		this->dma_apbperi_spi2_pms_constrain_1.val,
		this->dma_apbperi_spi2_pms_constrain_1.pms_dma_apbperi_spi2_pms_constrain_sram_pms_2_x,
		this->dma_apbperi_spi2_pms_constrain_1.pms_dma_apbperi_spi2_pms_constrain_sram_pms_2_y
	);
	this->dma_apbperi_spi2_pms_constrain_1.pms_dma_apbperi_spi2_pms_constrain_sram_pms_1 = this->regGet(
		this->dma_apbperi_spi2_pms_constrain_1.val,
		this->dma_apbperi_spi2_pms_constrain_1.pms_dma_apbperi_spi2_pms_constrain_sram_pms_1_x,
		this->dma_apbperi_spi2_pms_constrain_1.pms_dma_apbperi_spi2_pms_constrain_sram_pms_1_y
	);
	this->dma_apbperi_spi2_pms_constrain_1.pms_dma_apbperi_spi2_pms_constrain_sram_pms_0 = this->regGet(
		this->dma_apbperi_spi2_pms_constrain_1.val,
		this->dma_apbperi_spi2_pms_constrain_1.pms_dma_apbperi_spi2_pms_constrain_sram_pms_0_x,
		this->dma_apbperi_spi2_pms_constrain_1.pms_dma_apbperi_spi2_pms_constrain_sram_pms_0_y
	);
}
void PmsDebug::init_dma_apbperi_spi3_pms_constrain_0(void){
	uint16_t base = this->dma_apbperi_spi3_pms_constrain_0.base;
	this->dma_apbperi_spi3_pms_constrain_0.val = this->regRead(true, base);
	this->dma_apbperi_spi3_pms_constrain_0.pms_dma_apbperi_spi3_pms_constrain_lock = this->regGet(
		this->dma_apbperi_spi3_pms_constrain_0.val,
		this->dma_apbperi_spi3_pms_constrain_0.pms_dma_apbperi_spi3_pms_constrain_lock_pos
	);
}
void PmsDebug::init_dma_apbperi_spi3_pms_constrain_1(void){
	uint16_t base = this->dma_apbperi_spi3_pms_constrain_1.base;
	this->dma_apbperi_spi3_pms_constrain_1.val = this->regRead(true, base);
	this->dma_apbperi_spi3_pms_constrain_1.pms_dma_apbperi_spi3_pms_constrain_sram_cachedataarray_pms_1 = this->regGet(
		this->dma_apbperi_spi3_pms_constrain_1.val,
		this->dma_apbperi_spi3_pms_constrain_1.pms_dma_apbperi_spi3_pms_constrain_sram_cachedataarray_pms_1_x,
		this->dma_apbperi_spi3_pms_constrain_1.pms_dma_apbperi_spi3_pms_constrain_sram_cachedataarray_pms_1_y
	);
	this->dma_apbperi_spi3_pms_constrain_1.pms_dma_apbperi_spi3_pms_constrain_sram_cachedataarray_pms_0 = this->regGet(
		this->dma_apbperi_spi3_pms_constrain_1.val,
		this->dma_apbperi_spi3_pms_constrain_1.pms_dma_apbperi_spi3_pms_constrain_sram_cachedataarray_pms_0_x,
		this->dma_apbperi_spi3_pms_constrain_1.pms_dma_apbperi_spi3_pms_constrain_sram_cachedataarray_pms_0_y
	);
	this->dma_apbperi_spi3_pms_constrain_1.pms_dma_apbperi_spi3_pms_constrain_sram_pms_3 = this->regGet(
		this->dma_apbperi_spi3_pms_constrain_1.val,
		this->dma_apbperi_spi3_pms_constrain_1.pms_dma_apbperi_spi3_pms_constrain_sram_pms_3_x,
		this->dma_apbperi_spi3_pms_constrain_1.pms_dma_apbperi_spi3_pms_constrain_sram_pms_3_y
	);
	this->dma_apbperi_spi3_pms_constrain_1.pms_dma_apbperi_spi3_pms_constrain_sram_pms_2 = this->regGet(
		this->dma_apbperi_spi3_pms_constrain_1.val,
		this->dma_apbperi_spi3_pms_constrain_1.pms_dma_apbperi_spi3_pms_constrain_sram_pms_2_x,
		this->dma_apbperi_spi3_pms_constrain_1.pms_dma_apbperi_spi3_pms_constrain_sram_pms_2_y
	);
	this->dma_apbperi_spi3_pms_constrain_1.pms_dma_apbperi_spi3_pms_constrain_sram_pms_1 = this->regGet(
		this->dma_apbperi_spi3_pms_constrain_1.val,
		this->dma_apbperi_spi3_pms_constrain_1.pms_dma_apbperi_spi3_pms_constrain_sram_pms_1_x,
		this->dma_apbperi_spi3_pms_constrain_1.pms_dma_apbperi_spi3_pms_constrain_sram_pms_1_y
	);
	this->dma_apbperi_spi3_pms_constrain_1.pms_dma_apbperi_spi3_pms_constrain_sram_pms_0 = this->regGet(
		this->dma_apbperi_spi3_pms_constrain_1.val,
		this->dma_apbperi_spi3_pms_constrain_1.pms_dma_apbperi_spi3_pms_constrain_sram_pms_0_x,
		this->dma_apbperi_spi3_pms_constrain_1.pms_dma_apbperi_spi3_pms_constrain_sram_pms_0_y
	);
}
void PmsDebug::init_dma_apbperi_uhci0_pms_constrain_0(void){
	uint16_t base = this->dma_apbperi_uhci0_pms_constrain_0.base;
	this->dma_apbperi_uhci0_pms_constrain_0.val = this->regRead(true, base);
	this->dma_apbperi_uhci0_pms_constrain_0.pms_dma_apbperi_uhci0_pms_constrain_lock = this->regGet(
		this->dma_apbperi_uhci0_pms_constrain_0.val,
		this->dma_apbperi_uhci0_pms_constrain_0.pms_dma_apbperi_uhci0_pms_constrain_lock_pos
	);
}
void PmsDebug::init_dma_apbperi_uhci0_pms_constrain_1(void){
	uint16_t base = this->dma_apbperi_uhci0_pms_constrain_1.base;
	this->dma_apbperi_uhci0_pms_constrain_1.val = this->regRead(true, base);
	this->dma_apbperi_uhci0_pms_constrain_1.pms_dma_apbperi_uhci0_pms_constrain_sram_cachedataarray_pms_1 = this->regGet(
		this->dma_apbperi_uhci0_pms_constrain_1.val,
		this->dma_apbperi_uhci0_pms_constrain_1.pms_dma_apbperi_uhci0_pms_constrain_sram_cachedataarray_pms_1_x,
		this->dma_apbperi_uhci0_pms_constrain_1.pms_dma_apbperi_uhci0_pms_constrain_sram_cachedataarray_pms_1_y
	);
	this->dma_apbperi_uhci0_pms_constrain_1.pms_dma_apbperi_uhci0_pms_constrain_sram_cachedataarray_pms_0 = this->regGet(
		this->dma_apbperi_uhci0_pms_constrain_1.val,
		this->dma_apbperi_uhci0_pms_constrain_1.pms_dma_apbperi_uhci0_pms_constrain_sram_cachedataarray_pms_0_x,
		this->dma_apbperi_uhci0_pms_constrain_1.pms_dma_apbperi_uhci0_pms_constrain_sram_cachedataarray_pms_0_y
	);
	this->dma_apbperi_uhci0_pms_constrain_1.pms_dma_apbperi_uhci0_pms_constrain_sram_pms_3 = this->regGet(
		this->dma_apbperi_uhci0_pms_constrain_1.val,
		this->dma_apbperi_uhci0_pms_constrain_1.pms_dma_apbperi_uhci0_pms_constrain_sram_pms_3_x,
		this->dma_apbperi_uhci0_pms_constrain_1.pms_dma_apbperi_uhci0_pms_constrain_sram_pms_3_y
	);
	this->dma_apbperi_uhci0_pms_constrain_1.pms_dma_apbperi_uhci0_pms_constrain_sram_pms_2 = this->regGet(
		this->dma_apbperi_uhci0_pms_constrain_1.val,
		this->dma_apbperi_uhci0_pms_constrain_1.pms_dma_apbperi_uhci0_pms_constrain_sram_pms_2_x,
		this->dma_apbperi_uhci0_pms_constrain_1.pms_dma_apbperi_uhci0_pms_constrain_sram_pms_2_y
	);
	this->dma_apbperi_uhci0_pms_constrain_1.pms_dma_apbperi_uhci0_pms_constrain_sram_pms_1 = this->regGet(
		this->dma_apbperi_uhci0_pms_constrain_1.val,
		this->dma_apbperi_uhci0_pms_constrain_1.pms_dma_apbperi_uhci0_pms_constrain_sram_pms_1_x,
		this->dma_apbperi_uhci0_pms_constrain_1.pms_dma_apbperi_uhci0_pms_constrain_sram_pms_1_y
	);
	this->dma_apbperi_uhci0_pms_constrain_1.pms_dma_apbperi_uhci0_pms_constrain_sram_pms_0 = this->regGet(
		this->dma_apbperi_uhci0_pms_constrain_1.val,
		this->dma_apbperi_uhci0_pms_constrain_1.pms_dma_apbperi_uhci0_pms_constrain_sram_pms_0_x,
		this->dma_apbperi_uhci0_pms_constrain_1.pms_dma_apbperi_uhci0_pms_constrain_sram_pms_0_y
	);
}
void PmsDebug::init_dma_apbperi_i2s0_pms_constrain_0(void){
	uint16_t base = this->dma_apbperi_i2s0_pms_constrain_0.base;
	this->dma_apbperi_i2s0_pms_constrain_0.val = this->regRead(true, base);
	this->dma_apbperi_i2s0_pms_constrain_0.pms_dma_apbperi_i2s0_pms_constrain_lock = this->regGet(
		this->dma_apbperi_i2s0_pms_constrain_0.val,
		this->dma_apbperi_i2s0_pms_constrain_0.pms_dma_apbperi_i2s0_pms_constrain_lock_pos
	);
}
void PmsDebug::init_dma_apbperi_i2s0_pms_constrain_1(void){
	uint16_t base = this->dma_apbperi_i2s0_pms_constrain_1.base;
	this->dma_apbperi_i2s0_pms_constrain_1.val = this->regRead(true, base);
	this->dma_apbperi_i2s0_pms_constrain_1.pms_dma_apbperi_i2s0_pms_constrain_sram_cachedataarray_pms_1 = this->regGet(
		this->dma_apbperi_i2s0_pms_constrain_1.val,
		this->dma_apbperi_i2s0_pms_constrain_1.pms_dma_apbperi_i2s0_pms_constrain_sram_cachedataarray_pms_1_x,
		this->dma_apbperi_i2s0_pms_constrain_1.pms_dma_apbperi_i2s0_pms_constrain_sram_cachedataarray_pms_1_y
	);
	this->dma_apbperi_i2s0_pms_constrain_1.pms_dma_apbperi_i2s0_pms_constrain_sram_cachedataarray_pms_0 = this->regGet(
		this->dma_apbperi_i2s0_pms_constrain_1.val,
		this->dma_apbperi_i2s0_pms_constrain_1.pms_dma_apbperi_i2s0_pms_constrain_sram_cachedataarray_pms_0_x,
		this->dma_apbperi_i2s0_pms_constrain_1.pms_dma_apbperi_i2s0_pms_constrain_sram_cachedataarray_pms_0_y
	);
	this->dma_apbperi_i2s0_pms_constrain_1.pms_dma_apbperi_i2s0_pms_constrain_sram_pms_3 = this->regGet(
		this->dma_apbperi_i2s0_pms_constrain_1.val,
		this->dma_apbperi_i2s0_pms_constrain_1.pms_dma_apbperi_i2s0_pms_constrain_sram_pms_3_x,
		this->dma_apbperi_i2s0_pms_constrain_1.pms_dma_apbperi_i2s0_pms_constrain_sram_pms_3_y
	);
	this->dma_apbperi_i2s0_pms_constrain_1.pms_dma_apbperi_i2s0_pms_constrain_sram_pms_2 = this->regGet(
		this->dma_apbperi_i2s0_pms_constrain_1.val,
		this->dma_apbperi_i2s0_pms_constrain_1.pms_dma_apbperi_i2s0_pms_constrain_sram_pms_2_x,
		this->dma_apbperi_i2s0_pms_constrain_1.pms_dma_apbperi_i2s0_pms_constrain_sram_pms_2_y
	);
	this->dma_apbperi_i2s0_pms_constrain_1.pms_dma_apbperi_i2s0_pms_constrain_sram_pms_1 = this->regGet(
		this->dma_apbperi_i2s0_pms_constrain_1.val,
		this->dma_apbperi_i2s0_pms_constrain_1.pms_dma_apbperi_i2s0_pms_constrain_sram_pms_1_x,
		this->dma_apbperi_i2s0_pms_constrain_1.pms_dma_apbperi_i2s0_pms_constrain_sram_pms_1_y
	);
	this->dma_apbperi_i2s0_pms_constrain_1.pms_dma_apbperi_i2s0_pms_constrain_sram_pms_0 = this->regGet(
		this->dma_apbperi_i2s0_pms_constrain_1.val,
		this->dma_apbperi_i2s0_pms_constrain_1.pms_dma_apbperi_i2s0_pms_constrain_sram_pms_0_x,
		this->dma_apbperi_i2s0_pms_constrain_1.pms_dma_apbperi_i2s0_pms_constrain_sram_pms_0_y
	);
}
void PmsDebug::init_dma_apbperi_i2s1_pms_constrain_0(void){
	uint16_t base = this->dma_apbperi_i2s1_pms_constrain_0.base;
	this->dma_apbperi_i2s1_pms_constrain_0.val = this->regRead(true, base);
	this->dma_apbperi_i2s1_pms_constrain_0.pms_dma_apbperi_i2s1_pms_constrain_lock = this->regGet(
		this->dma_apbperi_i2s1_pms_constrain_0.val,
		this->dma_apbperi_i2s1_pms_constrain_0.pms_dma_apbperi_i2s1_pms_constrain_lock_pos
	);
}
void PmsDebug::init_dma_apbperi_i2s1_pms_constrain_1(void){
	uint16_t base = this->dma_apbperi_i2s1_pms_constrain_1.base;
	this->dma_apbperi_i2s1_pms_constrain_1.val = this->regRead(true, base);
	this->dma_apbperi_i2s1_pms_constrain_1.pms_dma_apbperi_i2s1_pms_constrain_sram_cachedataarray_pms_1 = this->regGet(
		this->dma_apbperi_i2s1_pms_constrain_1.val,
		this->dma_apbperi_i2s1_pms_constrain_1.pms_dma_apbperi_i2s1_pms_constrain_sram_cachedataarray_pms_1_x,
		this->dma_apbperi_i2s1_pms_constrain_1.pms_dma_apbperi_i2s1_pms_constrain_sram_cachedataarray_pms_1_y
	);
	this->dma_apbperi_i2s1_pms_constrain_1.pms_dma_apbperi_i2s1_pms_constrain_sram_cachedataarray_pms_0 = this->regGet(
		this->dma_apbperi_i2s1_pms_constrain_1.val,
		this->dma_apbperi_i2s1_pms_constrain_1.pms_dma_apbperi_i2s1_pms_constrain_sram_cachedataarray_pms_0_x,
		this->dma_apbperi_i2s1_pms_constrain_1.pms_dma_apbperi_i2s1_pms_constrain_sram_cachedataarray_pms_0_y
	);
	this->dma_apbperi_i2s1_pms_constrain_1.pms_dma_apbperi_i2s1_pms_constrain_sram_pms_3 = this->regGet(
		this->dma_apbperi_i2s1_pms_constrain_1.val,
		this->dma_apbperi_i2s1_pms_constrain_1.pms_dma_apbperi_i2s1_pms_constrain_sram_pms_3_x,
		this->dma_apbperi_i2s1_pms_constrain_1.pms_dma_apbperi_i2s1_pms_constrain_sram_pms_3_y
	);
	this->dma_apbperi_i2s1_pms_constrain_1.pms_dma_apbperi_i2s1_pms_constrain_sram_pms_2 = this->regGet(
		this->dma_apbperi_i2s1_pms_constrain_1.val,
		this->dma_apbperi_i2s1_pms_constrain_1.pms_dma_apbperi_i2s1_pms_constrain_sram_pms_2_x,
		this->dma_apbperi_i2s1_pms_constrain_1.pms_dma_apbperi_i2s1_pms_constrain_sram_pms_2_y
	);
	this->dma_apbperi_i2s1_pms_constrain_1.pms_dma_apbperi_i2s1_pms_constrain_sram_pms_1 = this->regGet(
		this->dma_apbperi_i2s1_pms_constrain_1.val,
		this->dma_apbperi_i2s1_pms_constrain_1.pms_dma_apbperi_i2s1_pms_constrain_sram_pms_1_x,
		this->dma_apbperi_i2s1_pms_constrain_1.pms_dma_apbperi_i2s1_pms_constrain_sram_pms_1_y
	);
	this->dma_apbperi_i2s1_pms_constrain_1.pms_dma_apbperi_i2s1_pms_constrain_sram_pms_0 = this->regGet(
		this->dma_apbperi_i2s1_pms_constrain_1.val,
		this->dma_apbperi_i2s1_pms_constrain_1.pms_dma_apbperi_i2s1_pms_constrain_sram_pms_0_x,
		this->dma_apbperi_i2s1_pms_constrain_1.pms_dma_apbperi_i2s1_pms_constrain_sram_pms_0_y
	);
}
void PmsDebug::init_dma_apbperi_aes_pms_constrain_0(void){
	uint16_t base = this->dma_apbperi_aes_pms_constrain_0.base;
	this->dma_apbperi_aes_pms_constrain_0.val = this->regRead(true, base);
	this->dma_apbperi_aes_pms_constrain_0.pms_dma_apbperi_aes_pms_constrain_lock = this->regGet(
		this->dma_apbperi_aes_pms_constrain_0.val,
		this->dma_apbperi_aes_pms_constrain_0.pms_dma_apbperi_aes_pms_constrain_lock_pos
	);
}
void PmsDebug::init_dma_apbperi_aes_pms_constrain_1(void){
	uint16_t base = this->dma_apbperi_aes_pms_constrain_1.base;
	this->dma_apbperi_aes_pms_constrain_1.val = this->regRead(true, base);
	this->dma_apbperi_aes_pms_constrain_1.pms_dma_apbperi_aes_pms_constrain_sram_cachedataarray_pms_1 = this->regGet(
		this->dma_apbperi_aes_pms_constrain_1.val,
		this->dma_apbperi_aes_pms_constrain_1.pms_dma_apbperi_aes_pms_constrain_sram_cachedataarray_pms_1_x,
		this->dma_apbperi_aes_pms_constrain_1.pms_dma_apbperi_aes_pms_constrain_sram_cachedataarray_pms_1_y
	);
	this->dma_apbperi_aes_pms_constrain_1.pms_dma_apbperi_aes_pms_constrain_sram_cachedataarray_pms_0 = this->regGet(
		this->dma_apbperi_aes_pms_constrain_1.val,
		this->dma_apbperi_aes_pms_constrain_1.pms_dma_apbperi_aes_pms_constrain_sram_cachedataarray_pms_0_x,
		this->dma_apbperi_aes_pms_constrain_1.pms_dma_apbperi_aes_pms_constrain_sram_cachedataarray_pms_0_y
	);
	this->dma_apbperi_aes_pms_constrain_1.pms_dma_apbperi_aes_pms_constrain_sram_pms_3 = this->regGet(
		this->dma_apbperi_aes_pms_constrain_1.val,
		this->dma_apbperi_aes_pms_constrain_1.pms_dma_apbperi_aes_pms_constrain_sram_pms_3_x,
		this->dma_apbperi_aes_pms_constrain_1.pms_dma_apbperi_aes_pms_constrain_sram_pms_3_y
	);
	this->dma_apbperi_aes_pms_constrain_1.pms_dma_apbperi_aes_pms_constrain_sram_pms_2 = this->regGet(
		this->dma_apbperi_aes_pms_constrain_1.val,
		this->dma_apbperi_aes_pms_constrain_1.pms_dma_apbperi_aes_pms_constrain_sram_pms_2_x,
		this->dma_apbperi_aes_pms_constrain_1.pms_dma_apbperi_aes_pms_constrain_sram_pms_2_y
	);
	this->dma_apbperi_aes_pms_constrain_1.pms_dma_apbperi_aes_pms_constrain_sram_pms_1 = this->regGet(
		this->dma_apbperi_aes_pms_constrain_1.val,
		this->dma_apbperi_aes_pms_constrain_1.pms_dma_apbperi_aes_pms_constrain_sram_pms_1_x,
		this->dma_apbperi_aes_pms_constrain_1.pms_dma_apbperi_aes_pms_constrain_sram_pms_1_y
	);
	this->dma_apbperi_aes_pms_constrain_1.pms_dma_apbperi_aes_pms_constrain_sram_pms_0 = this->regGet(
		this->dma_apbperi_aes_pms_constrain_1.val,
		this->dma_apbperi_aes_pms_constrain_1.pms_dma_apbperi_aes_pms_constrain_sram_pms_0_x,
		this->dma_apbperi_aes_pms_constrain_1.pms_dma_apbperi_aes_pms_constrain_sram_pms_0_y
	);
}
void PmsDebug::init_dma_apbperi_sha_pms_constrain_0(void){
	uint16_t base = this->dma_apbperi_sha_pms_constrain_0.base;
	this->dma_apbperi_sha_pms_constrain_0.val = this->regRead(true, base);
	this->dma_apbperi_sha_pms_constrain_0.pms_dma_apbperi_sha_pms_constrain_lock = this->regGet(
		this->dma_apbperi_sha_pms_constrain_0.val,
		this->dma_apbperi_sha_pms_constrain_0.pms_dma_apbperi_sha_pms_constrain_lock_pos
	);
}
void PmsDebug::init_dma_apbperi_sha_pms_constrain_1(void){
	uint16_t base = this->dma_apbperi_sha_pms_constrain_1.base;
	this->dma_apbperi_sha_pms_constrain_1.val = this->regRead(true, base);
	this->dma_apbperi_sha_pms_constrain_1.pms_dma_apbperi_sha_pms_constrain_sram_cachedataarray_pms_1 = this->regGet(
		this->dma_apbperi_sha_pms_constrain_1.val,
		this->dma_apbperi_sha_pms_constrain_1.pms_dma_apbperi_sha_pms_constrain_sram_cachedataarray_pms_1_x,
		this->dma_apbperi_sha_pms_constrain_1.pms_dma_apbperi_sha_pms_constrain_sram_cachedataarray_pms_1_y
	);
	this->dma_apbperi_sha_pms_constrain_1.pms_dma_apbperi_sha_pms_constrain_sram_cachedataarray_pms_0 = this->regGet(
		this->dma_apbperi_sha_pms_constrain_1.val,
		this->dma_apbperi_sha_pms_constrain_1.pms_dma_apbperi_sha_pms_constrain_sram_cachedataarray_pms_0_x,
		this->dma_apbperi_sha_pms_constrain_1.pms_dma_apbperi_sha_pms_constrain_sram_cachedataarray_pms_0_y
	);
	this->dma_apbperi_sha_pms_constrain_1.pms_dma_apbperi_sha_pms_constrain_sram_pms_3 = this->regGet(
		this->dma_apbperi_sha_pms_constrain_1.val,
		this->dma_apbperi_sha_pms_constrain_1.pms_dma_apbperi_sha_pms_constrain_sram_pms_3_x,
		this->dma_apbperi_sha_pms_constrain_1.pms_dma_apbperi_sha_pms_constrain_sram_pms_3_y
	);
	this->dma_apbperi_sha_pms_constrain_1.pms_dma_apbperi_sha_pms_constrain_sram_pms_2 = this->regGet(
		this->dma_apbperi_sha_pms_constrain_1.val,
		this->dma_apbperi_sha_pms_constrain_1.pms_dma_apbperi_sha_pms_constrain_sram_pms_2_x,
		this->dma_apbperi_sha_pms_constrain_1.pms_dma_apbperi_sha_pms_constrain_sram_pms_2_y
	);
	this->dma_apbperi_sha_pms_constrain_1.pms_dma_apbperi_sha_pms_constrain_sram_pms_1 = this->regGet(
		this->dma_apbperi_sha_pms_constrain_1.val,
		this->dma_apbperi_sha_pms_constrain_1.pms_dma_apbperi_sha_pms_constrain_sram_pms_1_x,
		this->dma_apbperi_sha_pms_constrain_1.pms_dma_apbperi_sha_pms_constrain_sram_pms_1_y
	);
	this->dma_apbperi_sha_pms_constrain_1.pms_dma_apbperi_sha_pms_constrain_sram_pms_0 = this->regGet(
		this->dma_apbperi_sha_pms_constrain_1.val,
		this->dma_apbperi_sha_pms_constrain_1.pms_dma_apbperi_sha_pms_constrain_sram_pms_0_x,
		this->dma_apbperi_sha_pms_constrain_1.pms_dma_apbperi_sha_pms_constrain_sram_pms_0_y
	);
}
void PmsDebug::init_dma_apbperi_adc_dac_pms_constrain_0(void){
	uint16_t base = this->dma_apbperi_adc_dac_pms_constrain_0.base;
	this->dma_apbperi_adc_dac_pms_constrain_0.val = this->regRead(true, base);
	this->dma_apbperi_adc_dac_pms_constrain_0.pms_dma_apbperi_adc_dac_pms_constrain_lock = this->regGet(
		this->dma_apbperi_adc_dac_pms_constrain_0.val,
		this->dma_apbperi_adc_dac_pms_constrain_0.pms_dma_apbperi_adc_dac_pms_constrain_lock_pos
	);
}
void PmsDebug::init_dma_apbperi_adc_dac_pms_constrain_1(void){
	uint16_t base = this->dma_apbperi_adc_dac_pms_constrain_1.base;
	this->dma_apbperi_adc_dac_pms_constrain_1.val = this->regRead(true, base);
	this->dma_apbperi_adc_dac_pms_constrain_1.pms_dma_apbperi_adc_dac_pms_constrain_sram_cachedataarray_pms_1 = this->regGet(
		this->dma_apbperi_adc_dac_pms_constrain_1.val,
		this->dma_apbperi_adc_dac_pms_constrain_1.pms_dma_apbperi_adc_dac_pms_constrain_sram_cachedataarray_pms_1_x,
		this->dma_apbperi_adc_dac_pms_constrain_1.pms_dma_apbperi_adc_dac_pms_constrain_sram_cachedataarray_pms_1_y
	);
	this->dma_apbperi_adc_dac_pms_constrain_1.pms_dma_apbperi_adc_dac_pms_constrain_sram_cachedataarray_pms_0 = this->regGet(
		this->dma_apbperi_adc_dac_pms_constrain_1.val,
		this->dma_apbperi_adc_dac_pms_constrain_1.pms_dma_apbperi_adc_dac_pms_constrain_sram_cachedataarray_pms_0_x,
		this->dma_apbperi_adc_dac_pms_constrain_1.pms_dma_apbperi_adc_dac_pms_constrain_sram_cachedataarray_pms_0_y
	);
	this->dma_apbperi_adc_dac_pms_constrain_1.pms_dma_apbperi_adc_dac_pms_constrain_sram_pms_3 = this->regGet(
		this->dma_apbperi_adc_dac_pms_constrain_1.val,
		this->dma_apbperi_adc_dac_pms_constrain_1.pms_dma_apbperi_adc_dac_pms_constrain_sram_pms_3_x,
		this->dma_apbperi_adc_dac_pms_constrain_1.pms_dma_apbperi_adc_dac_pms_constrain_sram_pms_3_y
	);
	this->dma_apbperi_adc_dac_pms_constrain_1.pms_dma_apbperi_adc_dac_pms_constrain_sram_pms_2 = this->regGet(
		this->dma_apbperi_adc_dac_pms_constrain_1.val,
		this->dma_apbperi_adc_dac_pms_constrain_1.pms_dma_apbperi_adc_dac_pms_constrain_sram_pms_2_x,
		this->dma_apbperi_adc_dac_pms_constrain_1.pms_dma_apbperi_adc_dac_pms_constrain_sram_pms_2_y
	);
	this->dma_apbperi_adc_dac_pms_constrain_1.pms_dma_apbperi_adc_dac_pms_constrain_sram_pms_1 = this->regGet(
		this->dma_apbperi_adc_dac_pms_constrain_1.val,
		this->dma_apbperi_adc_dac_pms_constrain_1.pms_dma_apbperi_adc_dac_pms_constrain_sram_pms_1_x,
		this->dma_apbperi_adc_dac_pms_constrain_1.pms_dma_apbperi_adc_dac_pms_constrain_sram_pms_1_y
	);
	this->dma_apbperi_adc_dac_pms_constrain_1.pms_dma_apbperi_adc_dac_pms_constrain_sram_pms_0 = this->regGet(
		this->dma_apbperi_adc_dac_pms_constrain_1.val,
		this->dma_apbperi_adc_dac_pms_constrain_1.pms_dma_apbperi_adc_dac_pms_constrain_sram_pms_0_x,
		this->dma_apbperi_adc_dac_pms_constrain_1.pms_dma_apbperi_adc_dac_pms_constrain_sram_pms_0_y
	);
}
void PmsDebug::init_dma_apbperi_rmt_pms_constrain_0(void){
	uint16_t base = this->dma_apbperi_rmt_pms_constrain_0.base;
	this->dma_apbperi_rmt_pms_constrain_0.val = this->regRead(true, base);
	this->dma_apbperi_rmt_pms_constrain_0.pms_dma_apbperi_rmt_pms_constrain_lock = this->regGet(
		this->dma_apbperi_rmt_pms_constrain_0.val,
		this->dma_apbperi_rmt_pms_constrain_0.pms_dma_apbperi_rmt_pms_constrain_lock_pos
	);
}
void PmsDebug::init_dma_apbperi_rmt_pms_constrain_1(void){
	uint16_t base = this->dma_apbperi_rmt_pms_constrain_1.base;
	this->dma_apbperi_rmt_pms_constrain_1.val = this->regRead(true, base);
	this->dma_apbperi_rmt_pms_constrain_1.pms_dma_apbperi_rmt_pms_constrain_sram_cachedataarray_pms_1 = this->regGet(
		this->dma_apbperi_rmt_pms_constrain_1.val,
		this->dma_apbperi_rmt_pms_constrain_1.pms_dma_apbperi_rmt_pms_constrain_sram_cachedataarray_pms_1_x,
		this->dma_apbperi_rmt_pms_constrain_1.pms_dma_apbperi_rmt_pms_constrain_sram_cachedataarray_pms_1_y
	);
	this->dma_apbperi_rmt_pms_constrain_1.pms_dma_apbperi_rmt_pms_constrain_sram_cachedataarray_pms_0 = this->regGet(
		this->dma_apbperi_rmt_pms_constrain_1.val,
		this->dma_apbperi_rmt_pms_constrain_1.pms_dma_apbperi_rmt_pms_constrain_sram_cachedataarray_pms_0_x,
		this->dma_apbperi_rmt_pms_constrain_1.pms_dma_apbperi_rmt_pms_constrain_sram_cachedataarray_pms_0_y
	);
	this->dma_apbperi_rmt_pms_constrain_1.pms_dma_apbperi_rmt_pms_constrain_sram_pms_3 = this->regGet(
		this->dma_apbperi_rmt_pms_constrain_1.val,
		this->dma_apbperi_rmt_pms_constrain_1.pms_dma_apbperi_rmt_pms_constrain_sram_pms_3_x,
		this->dma_apbperi_rmt_pms_constrain_1.pms_dma_apbperi_rmt_pms_constrain_sram_pms_3_y
	);
	this->dma_apbperi_rmt_pms_constrain_1.pms_dma_apbperi_rmt_pms_constrain_sram_pms_2 = this->regGet(
		this->dma_apbperi_rmt_pms_constrain_1.val,
		this->dma_apbperi_rmt_pms_constrain_1.pms_dma_apbperi_rmt_pms_constrain_sram_pms_2_x,
		this->dma_apbperi_rmt_pms_constrain_1.pms_dma_apbperi_rmt_pms_constrain_sram_pms_2_y
	);
	this->dma_apbperi_rmt_pms_constrain_1.pms_dma_apbperi_rmt_pms_constrain_sram_pms_1 = this->regGet(
		this->dma_apbperi_rmt_pms_constrain_1.val,
		this->dma_apbperi_rmt_pms_constrain_1.pms_dma_apbperi_rmt_pms_constrain_sram_pms_1_x,
		this->dma_apbperi_rmt_pms_constrain_1.pms_dma_apbperi_rmt_pms_constrain_sram_pms_1_y
	);
	this->dma_apbperi_rmt_pms_constrain_1.pms_dma_apbperi_rmt_pms_constrain_sram_pms_0 = this->regGet(
		this->dma_apbperi_rmt_pms_constrain_1.val,
		this->dma_apbperi_rmt_pms_constrain_1.pms_dma_apbperi_rmt_pms_constrain_sram_pms_0_x,
		this->dma_apbperi_rmt_pms_constrain_1.pms_dma_apbperi_rmt_pms_constrain_sram_pms_0_y
	);
}
void PmsDebug::init_dma_apbperi_lcd_cam_pms_constrain_0(void){
	uint16_t base = this->dma_apbperi_lcd_cam_pms_constrain_0.base;
	this->dma_apbperi_lcd_cam_pms_constrain_0.val = this->regRead(true, base);
	this->dma_apbperi_lcd_cam_pms_constrain_0.pms_dma_apbperi_lcd_cam_pms_constrain_lock = this->regGet(
		this->dma_apbperi_lcd_cam_pms_constrain_0.val,
		this->dma_apbperi_lcd_cam_pms_constrain_0.pms_dma_apbperi_lcd_cam_pms_constrain_lock_pos
	);
}
void PmsDebug::init_dma_apbperi_lcd_cam_pms_constrain_1(void){
	uint16_t base = this->dma_apbperi_lcd_cam_pms_constrain_1.base;
	this->dma_apbperi_lcd_cam_pms_constrain_1.val = this->regRead(true, base);
	this->dma_apbperi_lcd_cam_pms_constrain_1.pms_dma_apbperi_lcd_cam_pms_constrain_sram_cachedataarray_pms_1 = this->regGet(
		this->dma_apbperi_lcd_cam_pms_constrain_1.val,
		this->dma_apbperi_lcd_cam_pms_constrain_1.pms_dma_apbperi_lcd_cam_pms_constrain_sram_cachedataarray_pms_1_x,
		this->dma_apbperi_lcd_cam_pms_constrain_1.pms_dma_apbperi_lcd_cam_pms_constrain_sram_cachedataarray_pms_1_y
	);
	this->dma_apbperi_lcd_cam_pms_constrain_1.pms_dma_apbperi_lcd_cam_pms_constrain_sram_cachedataarray_pms_0 = this->regGet(
		this->dma_apbperi_lcd_cam_pms_constrain_1.val,
		this->dma_apbperi_lcd_cam_pms_constrain_1.pms_dma_apbperi_lcd_cam_pms_constrain_sram_cachedataarray_pms_0_x,
		this->dma_apbperi_lcd_cam_pms_constrain_1.pms_dma_apbperi_lcd_cam_pms_constrain_sram_cachedataarray_pms_0_y
	);
	this->dma_apbperi_lcd_cam_pms_constrain_1.pms_dma_apbperi_lcd_cam_pms_constrain_sram_pms_3 = this->regGet(
		this->dma_apbperi_lcd_cam_pms_constrain_1.val,
		this->dma_apbperi_lcd_cam_pms_constrain_1.pms_dma_apbperi_lcd_cam_pms_constrain_sram_pms_3_x,
		this->dma_apbperi_lcd_cam_pms_constrain_1.pms_dma_apbperi_lcd_cam_pms_constrain_sram_pms_3_y
	);
	this->dma_apbperi_lcd_cam_pms_constrain_1.pms_dma_apbperi_lcd_cam_pms_constrain_sram_pms_2 = this->regGet(
		this->dma_apbperi_lcd_cam_pms_constrain_1.val,
		this->dma_apbperi_lcd_cam_pms_constrain_1.pms_dma_apbperi_lcd_cam_pms_constrain_sram_pms_2_x,
		this->dma_apbperi_lcd_cam_pms_constrain_1.pms_dma_apbperi_lcd_cam_pms_constrain_sram_pms_2_y
	);
	this->dma_apbperi_lcd_cam_pms_constrain_1.pms_dma_apbperi_lcd_cam_pms_constrain_sram_pms_1 = this->regGet(
		this->dma_apbperi_lcd_cam_pms_constrain_1.val,
		this->dma_apbperi_lcd_cam_pms_constrain_1.pms_dma_apbperi_lcd_cam_pms_constrain_sram_pms_1_x,
		this->dma_apbperi_lcd_cam_pms_constrain_1.pms_dma_apbperi_lcd_cam_pms_constrain_sram_pms_1_y
	);
	this->dma_apbperi_lcd_cam_pms_constrain_1.pms_dma_apbperi_lcd_cam_pms_constrain_sram_pms_0 = this->regGet(
		this->dma_apbperi_lcd_cam_pms_constrain_1.val,
		this->dma_apbperi_lcd_cam_pms_constrain_1.pms_dma_apbperi_lcd_cam_pms_constrain_sram_pms_0_x,
		this->dma_apbperi_lcd_cam_pms_constrain_1.pms_dma_apbperi_lcd_cam_pms_constrain_sram_pms_0_y
	);
}
void PmsDebug::init_dma_apbperi_usb_pms_constrain_0(void){
	uint16_t base = this->dma_apbperi_usb_pms_constrain_0.base;
	this->dma_apbperi_usb_pms_constrain_0.val = this->regRead(true, base);
	this->dma_apbperi_usb_pms_constrain_0.pms_dma_apbperi_usb_pms_constrain_lock = this->regGet(
		this->dma_apbperi_usb_pms_constrain_0.val,
		this->dma_apbperi_usb_pms_constrain_0.pms_dma_apbperi_usb_pms_constrain_lock_pos
	);
}
void PmsDebug::init_dma_apbperi_usb_pms_constrain_1(void){
	uint16_t base = this->dma_apbperi_usb_pms_constrain_1.base;
	this->dma_apbperi_usb_pms_constrain_1.val = this->regRead(true, base);
	this->dma_apbperi_usb_pms_constrain_1.pms_dma_apbperi_usb_pms_constrain_sram_cachedataarray_pms_1 = this->regGet(
		this->dma_apbperi_usb_pms_constrain_1.val,
		this->dma_apbperi_usb_pms_constrain_1.pms_dma_apbperi_usb_pms_constrain_sram_cachedataarray_pms_1_x,
		this->dma_apbperi_usb_pms_constrain_1.pms_dma_apbperi_usb_pms_constrain_sram_cachedataarray_pms_1_y
	);
	this->dma_apbperi_usb_pms_constrain_1.pms_dma_apbperi_usb_pms_constrain_sram_cachedataarray_pms_0 = this->regGet(
		this->dma_apbperi_usb_pms_constrain_1.val,
		this->dma_apbperi_usb_pms_constrain_1.pms_dma_apbperi_usb_pms_constrain_sram_cachedataarray_pms_0_x,
		this->dma_apbperi_usb_pms_constrain_1.pms_dma_apbperi_usb_pms_constrain_sram_cachedataarray_pms_0_y
	);
	this->dma_apbperi_usb_pms_constrain_1.pms_dma_apbperi_usb_pms_constrain_sram_pms_3 = this->regGet(
		this->dma_apbperi_usb_pms_constrain_1.val,
		this->dma_apbperi_usb_pms_constrain_1.pms_dma_apbperi_usb_pms_constrain_sram_pms_3_x,
		this->dma_apbperi_usb_pms_constrain_1.pms_dma_apbperi_usb_pms_constrain_sram_pms_3_y
	);
	this->dma_apbperi_usb_pms_constrain_1.pms_dma_apbperi_usb_pms_constrain_sram_pms_2 = this->regGet(
		this->dma_apbperi_usb_pms_constrain_1.val,
		this->dma_apbperi_usb_pms_constrain_1.pms_dma_apbperi_usb_pms_constrain_sram_pms_2_x,
		this->dma_apbperi_usb_pms_constrain_1.pms_dma_apbperi_usb_pms_constrain_sram_pms_2_y
	);
	this->dma_apbperi_usb_pms_constrain_1.pms_dma_apbperi_usb_pms_constrain_sram_pms_1 = this->regGet(
		this->dma_apbperi_usb_pms_constrain_1.val,
		this->dma_apbperi_usb_pms_constrain_1.pms_dma_apbperi_usb_pms_constrain_sram_pms_1_x,
		this->dma_apbperi_usb_pms_constrain_1.pms_dma_apbperi_usb_pms_constrain_sram_pms_1_y
	);
	this->dma_apbperi_usb_pms_constrain_1.pms_dma_apbperi_usb_pms_constrain_sram_pms_0 = this->regGet(
		this->dma_apbperi_usb_pms_constrain_1.val,
		this->dma_apbperi_usb_pms_constrain_1.pms_dma_apbperi_usb_pms_constrain_sram_pms_0_x,
		this->dma_apbperi_usb_pms_constrain_1.pms_dma_apbperi_usb_pms_constrain_sram_pms_0_y
	);
}
void PmsDebug::init_dma_apbperi_sdio_pms_constrain_0(void){
	uint16_t base = this->dma_apbperi_sdio_pms_constrain_0.base;
	this->dma_apbperi_sdio_pms_constrain_0.val = this->regRead(true, base);
	this->dma_apbperi_sdio_pms_constrain_0.pms_dma_apbperi_sdio_pms_constrain_lock = this->regGet(
		this->dma_apbperi_sdio_pms_constrain_0.val,
		this->dma_apbperi_sdio_pms_constrain_0.pms_dma_apbperi_sdio_pms_constrain_lock_pos
	);
}
void PmsDebug::init_dma_apbperi_sdio_pms_constrain_1(void){
	uint16_t base = this->dma_apbperi_sdio_pms_constrain_1.base;
	this->dma_apbperi_sdio_pms_constrain_1.val = this->regRead(true, base);
	this->dma_apbperi_sdio_pms_constrain_1.pms_dma_apbperi_sdio_pms_constrain_sram_cachedataarray_pms_1 = this->regGet(
		this->dma_apbperi_sdio_pms_constrain_1.val,
		this->dma_apbperi_sdio_pms_constrain_1.pms_dma_apbperi_sdio_pms_constrain_sram_cachedataarray_pms_1_x,
		this->dma_apbperi_sdio_pms_constrain_1.pms_dma_apbperi_sdio_pms_constrain_sram_cachedataarray_pms_1_y
	);
	this->dma_apbperi_sdio_pms_constrain_1.pms_dma_apbperi_sdio_pms_constrain_sram_cachedataarray_pms_0 = this->regGet(
		this->dma_apbperi_sdio_pms_constrain_1.val,
		this->dma_apbperi_sdio_pms_constrain_1.pms_dma_apbperi_sdio_pms_constrain_sram_cachedataarray_pms_0_x,
		this->dma_apbperi_sdio_pms_constrain_1.pms_dma_apbperi_sdio_pms_constrain_sram_cachedataarray_pms_0_y
	);
	this->dma_apbperi_sdio_pms_constrain_1.pms_dma_apbperi_sdio_pms_constrain_sram_pms_3 = this->regGet(
		this->dma_apbperi_sdio_pms_constrain_1.val,
		this->dma_apbperi_sdio_pms_constrain_1.pms_dma_apbperi_sdio_pms_constrain_sram_pms_3_x,
		this->dma_apbperi_sdio_pms_constrain_1.pms_dma_apbperi_sdio_pms_constrain_sram_pms_3_y
	);
	this->dma_apbperi_sdio_pms_constrain_1.pms_dma_apbperi_sdio_pms_constrain_sram_pms_2 = this->regGet(
		this->dma_apbperi_sdio_pms_constrain_1.val,
		this->dma_apbperi_sdio_pms_constrain_1.pms_dma_apbperi_sdio_pms_constrain_sram_pms_2_x,
		this->dma_apbperi_sdio_pms_constrain_1.pms_dma_apbperi_sdio_pms_constrain_sram_pms_2_y
	);
	this->dma_apbperi_sdio_pms_constrain_1.pms_dma_apbperi_sdio_pms_constrain_sram_pms_1 = this->regGet(
		this->dma_apbperi_sdio_pms_constrain_1.val,
		this->dma_apbperi_sdio_pms_constrain_1.pms_dma_apbperi_sdio_pms_constrain_sram_pms_1_x,
		this->dma_apbperi_sdio_pms_constrain_1.pms_dma_apbperi_sdio_pms_constrain_sram_pms_1_y
	);
	this->dma_apbperi_sdio_pms_constrain_1.pms_dma_apbperi_sdio_pms_constrain_sram_pms_0 = this->regGet(
		this->dma_apbperi_sdio_pms_constrain_1.val,
		this->dma_apbperi_sdio_pms_constrain_1.pms_dma_apbperi_sdio_pms_constrain_sram_pms_0_x,
		this->dma_apbperi_sdio_pms_constrain_1.pms_dma_apbperi_sdio_pms_constrain_sram_pms_0_y
	);
}
void PmsDebug::init_dma_apbperi_pms_monitor_0(void){
	uint16_t base = this->dma_apbperi_pms_monitor_0.base;
	this->dma_apbperi_pms_monitor_0.val = this->regRead(true, base);
	this->dma_apbperi_pms_monitor_0.pms_dma_apbperi_pms_monitor_lock = this->regGet(
		this->dma_apbperi_pms_monitor_0.val,
		this->dma_apbperi_pms_monitor_0.pms_dma_apbperi_pms_monitor_lock_pos
	);
}
void PmsDebug::init_dma_apbperi_pms_monitor_1(void){
	uint16_t base = this->dma_apbperi_pms_monitor_1.base;
	this->dma_apbperi_pms_monitor_1.val = this->regRead(true, base);
	this->dma_apbperi_pms_monitor_1.pms_dma_apbperi_pms_monitor_violate_en = this->regGet(
		this->dma_apbperi_pms_monitor_1.val,
		this->dma_apbperi_pms_monitor_1.pms_dma_apbperi_pms_monitor_violate_en_pos
	);
	this->dma_apbperi_pms_monitor_1.pms_dma_apbperi_pms_monitor_violate_clr = this->regGet(
		this->dma_apbperi_pms_monitor_1.val,
		this->dma_apbperi_pms_monitor_1.pms_dma_apbperi_pms_monitor_violate_clr_pos
	);
}
void PmsDebug::init_dma_apbperi_pms_monitor_2(void){
	uint16_t base = this->dma_apbperi_pms_monitor_2.base;
	this->dma_apbperi_pms_monitor_2.val = this->regRead(true, base);
	this->dma_apbperi_pms_monitor_2.pms_dma_apbperi_pms_monitor_violate_status_addr = this->regGet(
		this->dma_apbperi_pms_monitor_2.val,
		this->dma_apbperi_pms_monitor_2.pms_dma_apbperi_pms_monitor_violate_status_addr_x,
		this->dma_apbperi_pms_monitor_2.pms_dma_apbperi_pms_monitor_violate_status_addr_y
	);
	this->dma_apbperi_pms_monitor_2.pms_dma_apbperi_pms_monitor_violate_status_world = this->regGet(
		this->dma_apbperi_pms_monitor_2.val,
		this->dma_apbperi_pms_monitor_2.pms_dma_apbperi_pms_monitor_violate_status_world_x,
		this->dma_apbperi_pms_monitor_2.pms_dma_apbperi_pms_monitor_violate_status_world_y
	);
	this->dma_apbperi_pms_monitor_2.pms_dma_apbperi_pms_monitor_violate_intr = this->regGet(
		this->dma_apbperi_pms_monitor_2.val,
		this->dma_apbperi_pms_monitor_2.pms_dma_apbperi_pms_monitor_violate_intr_pos
	);
}
void PmsDebug::init_dma_apbperi_pms_monitor_3(void){
	uint16_t base = this->dma_apbperi_pms_monitor_3.base;
	this->dma_apbperi_pms_monitor_3.val = this->regRead(true, base);
	this->dma_apbperi_pms_monitor_3.pms_dma_apbperi_pms_monitor_violate_status_byteen = this->regGet(
		this->dma_apbperi_pms_monitor_3.val,
		this->dma_apbperi_pms_monitor_3.pms_dma_apbperi_pms_monitor_violate_status_byteen_x,
		this->dma_apbperi_pms_monitor_3.pms_dma_apbperi_pms_monitor_violate_status_byteen_y
	);
	this->dma_apbperi_pms_monitor_3.pms_dma_apbperi_pms_monitor_violate_status_wr = this->regGet(
		this->dma_apbperi_pms_monitor_3.val,
		this->dma_apbperi_pms_monitor_3.pms_dma_apbperi_pms_monitor_violate_status_wr_pos
	);
}
void PmsDebug::init_core_x_iram0_dram0_dma_split_line_constrain_0(void){
	uint16_t base = this->core_x_iram0_dram0_dma_split_line_constrain_0.base;
	this->core_x_iram0_dram0_dma_split_line_constrain_0.val = this->regRead(true, base);
	this->core_x_iram0_dram0_dma_split_line_constrain_0.pms_core_x_iram0_dram0_dma_split_line_constrain_lock = this->regGet(
		this->core_x_iram0_dram0_dma_split_line_constrain_0.val,
		this->core_x_iram0_dram0_dma_split_line_constrain_0.pms_core_x_iram0_dram0_dma_split_line_constrain_lock_pos
	);
}
void PmsDebug::init_core_x_iram0_dram0_dma_split_line_constrain_1(void){
	uint16_t base = this->core_x_iram0_dram0_dma_split_line_constrain_1.base;
	this->core_x_iram0_dram0_dma_split_line_constrain_1.val = this->regRead(true, base);
	this->core_x_iram0_dram0_dma_split_line_constrain_1.pms_core_x_iram0_dram0_dma_sram_splitaddr = this->regGet(
		this->core_x_iram0_dram0_dma_split_line_constrain_1.val,
		this->core_x_iram0_dram0_dma_split_line_constrain_1.pms_core_x_iram0_dram0_dma_sram_splitaddr_x,
		this->core_x_iram0_dram0_dma_split_line_constrain_1.pms_core_x_iram0_dram0_dma_sram_splitaddr_y
	);
	this->core_x_iram0_dram0_dma_split_line_constrain_1.pms_core_x_iram0_dram0_dma_sram_category_6 = this->regGet(
		this->core_x_iram0_dram0_dma_split_line_constrain_1.val,
		this->core_x_iram0_dram0_dma_split_line_constrain_1.pms_core_x_iram0_dram0_dma_sram_category_6_x,
		this->core_x_iram0_dram0_dma_split_line_constrain_1.pms_core_x_iram0_dram0_dma_sram_category_6_y
	);
	this->core_x_iram0_dram0_dma_split_line_constrain_1.pms_core_x_iram0_dram0_dma_sram_category_5 = this->regGet(
		this->core_x_iram0_dram0_dma_split_line_constrain_1.val,
		this->core_x_iram0_dram0_dma_split_line_constrain_1.pms_core_x_iram0_dram0_dma_sram_category_5_x,
		this->core_x_iram0_dram0_dma_split_line_constrain_1.pms_core_x_iram0_dram0_dma_sram_category_5_y
	);
	this->core_x_iram0_dram0_dma_split_line_constrain_1.pms_core_x_iram0_dram0_dma_sram_category_4 = this->regGet(
		this->core_x_iram0_dram0_dma_split_line_constrain_1.val,
		this->core_x_iram0_dram0_dma_split_line_constrain_1.pms_core_x_iram0_dram0_dma_sram_category_4_x,
		this->core_x_iram0_dram0_dma_split_line_constrain_1.pms_core_x_iram0_dram0_dma_sram_category_4_y
	);
	this->core_x_iram0_dram0_dma_split_line_constrain_1.pms_core_x_iram0_dram0_dma_sram_category_3 = this->regGet(
		this->core_x_iram0_dram0_dma_split_line_constrain_1.val,
		this->core_x_iram0_dram0_dma_split_line_constrain_1.pms_core_x_iram0_dram0_dma_sram_category_3_x,
		this->core_x_iram0_dram0_dma_split_line_constrain_1.pms_core_x_iram0_dram0_dma_sram_category_3_y
	);
	this->core_x_iram0_dram0_dma_split_line_constrain_1.pms_core_x_iram0_dram0_dma_sram_category_2 = this->regGet(
		this->core_x_iram0_dram0_dma_split_line_constrain_1.val,
		this->core_x_iram0_dram0_dma_split_line_constrain_1.pms_core_x_iram0_dram0_dma_sram_category_2_x,
		this->core_x_iram0_dram0_dma_split_line_constrain_1.pms_core_x_iram0_dram0_dma_sram_category_2_y
	);
	this->core_x_iram0_dram0_dma_split_line_constrain_1.pms_core_x_iram0_dram0_dma_sram_category_1 = this->regGet(
		this->core_x_iram0_dram0_dma_split_line_constrain_1.val,
		this->core_x_iram0_dram0_dma_split_line_constrain_1.pms_core_x_iram0_dram0_dma_sram_category_1_x,
		this->core_x_iram0_dram0_dma_split_line_constrain_1.pms_core_x_iram0_dram0_dma_sram_category_1_y
	);
	this->core_x_iram0_dram0_dma_split_line_constrain_1.pms_core_x_iram0_dram0_dma_sram_category_0 = this->regGet(
		this->core_x_iram0_dram0_dma_split_line_constrain_1.val,
		this->core_x_iram0_dram0_dma_split_line_constrain_1.pms_core_x_iram0_dram0_dma_sram_category_0_x,
		this->core_x_iram0_dram0_dma_split_line_constrain_1.pms_core_x_iram0_dram0_dma_sram_category_0_y
	);
}
void PmsDebug::init_core_x_iram0_dram0_dma_split_line_constrain_2(void){
	uint16_t base = this->core_x_iram0_dram0_dma_split_line_constrain_2.base;
	this->core_x_iram0_dram0_dma_split_line_constrain_2.val = this->regRead(true, base);
	this->core_x_iram0_dram0_dma_split_line_constrain_2.pms_core_x_iram0_sram_line_0_splitaddr = this->regGet(
		this->core_x_iram0_dram0_dma_split_line_constrain_2.val,
		this->core_x_iram0_dram0_dma_split_line_constrain_2.pms_core_x_iram0_sram_line_0_splitaddr_x,
		this->core_x_iram0_dram0_dma_split_line_constrain_2.pms_core_x_iram0_sram_line_0_splitaddr_y
	);
	this->core_x_iram0_dram0_dma_split_line_constrain_2.pms_core_x_iram0_sram_line_0_category_6 = this->regGet(
		this->core_x_iram0_dram0_dma_split_line_constrain_2.val,
		this->core_x_iram0_dram0_dma_split_line_constrain_2.pms_core_x_iram0_sram_line_0_category_6_x,
		this->core_x_iram0_dram0_dma_split_line_constrain_2.pms_core_x_iram0_sram_line_0_category_6_y
	);
	this->core_x_iram0_dram0_dma_split_line_constrain_2.pms_core_x_iram0_sram_line_0_category_5 = this->regGet(
		this->core_x_iram0_dram0_dma_split_line_constrain_2.val,
		this->core_x_iram0_dram0_dma_split_line_constrain_2.pms_core_x_iram0_sram_line_0_category_5_x,
		this->core_x_iram0_dram0_dma_split_line_constrain_2.pms_core_x_iram0_sram_line_0_category_5_y
	);
	this->core_x_iram0_dram0_dma_split_line_constrain_2.pms_core_x_iram0_sram_line_0_category_4 = this->regGet(
		this->core_x_iram0_dram0_dma_split_line_constrain_2.val,
		this->core_x_iram0_dram0_dma_split_line_constrain_2.pms_core_x_iram0_sram_line_0_category_4_x,
		this->core_x_iram0_dram0_dma_split_line_constrain_2.pms_core_x_iram0_sram_line_0_category_4_y
	);
	this->core_x_iram0_dram0_dma_split_line_constrain_2.pms_core_x_iram0_sram_line_0_category_3 = this->regGet(
		this->core_x_iram0_dram0_dma_split_line_constrain_2.val,
		this->core_x_iram0_dram0_dma_split_line_constrain_2.pms_core_x_iram0_sram_line_0_category_3_x,
		this->core_x_iram0_dram0_dma_split_line_constrain_2.pms_core_x_iram0_sram_line_0_category_3_y
	);
	this->core_x_iram0_dram0_dma_split_line_constrain_2.pms_core_x_iram0_sram_line_0_category_2 = this->regGet(
		this->core_x_iram0_dram0_dma_split_line_constrain_2.val,
		this->core_x_iram0_dram0_dma_split_line_constrain_2.pms_core_x_iram0_sram_line_0_category_2_x,
		this->core_x_iram0_dram0_dma_split_line_constrain_2.pms_core_x_iram0_sram_line_0_category_2_y
	);
	this->core_x_iram0_dram0_dma_split_line_constrain_2.pms_core_x_iram0_sram_line_0_category_1 = this->regGet(
		this->core_x_iram0_dram0_dma_split_line_constrain_2.val,
		this->core_x_iram0_dram0_dma_split_line_constrain_2.pms_core_x_iram0_sram_line_0_category_1_x,
		this->core_x_iram0_dram0_dma_split_line_constrain_2.pms_core_x_iram0_sram_line_0_category_1_y
	);
	this->core_x_iram0_dram0_dma_split_line_constrain_2.pms_core_x_iram0_sram_line_0_category_0 = this->regGet(
		this->core_x_iram0_dram0_dma_split_line_constrain_2.val,
		this->core_x_iram0_dram0_dma_split_line_constrain_2.pms_core_x_iram0_sram_line_0_category_0_x,
		this->core_x_iram0_dram0_dma_split_line_constrain_2.pms_core_x_iram0_sram_line_0_category_0_y
	);
}
void PmsDebug::init_core_x_iram0_dram0_dma_split_line_constrain_3(void){
	uint16_t base = this->core_x_iram0_dram0_dma_split_line_constrain_3.base;
	this->core_x_iram0_dram0_dma_split_line_constrain_3.val = this->regRead(true, base);
	this->core_x_iram0_dram0_dma_split_line_constrain_3.pms_core_x_iram0_sram_line_1_splitaddr = this->regGet(
		this->core_x_iram0_dram0_dma_split_line_constrain_3.val,
		this->core_x_iram0_dram0_dma_split_line_constrain_3.pms_core_x_iram0_sram_line_1_splitaddr_x,
		this->core_x_iram0_dram0_dma_split_line_constrain_3.pms_core_x_iram0_sram_line_1_splitaddr_y
	);
	this->core_x_iram0_dram0_dma_split_line_constrain_3.pms_core_x_iram0_sram_line_1_category_6 = this->regGet(
		this->core_x_iram0_dram0_dma_split_line_constrain_3.val,
		this->core_x_iram0_dram0_dma_split_line_constrain_3.pms_core_x_iram0_sram_line_1_category_6_x,
		this->core_x_iram0_dram0_dma_split_line_constrain_3.pms_core_x_iram0_sram_line_1_category_6_y
	);
	this->core_x_iram0_dram0_dma_split_line_constrain_3.pms_core_x_iram0_sram_line_1_category_5 = this->regGet(
		this->core_x_iram0_dram0_dma_split_line_constrain_3.val,
		this->core_x_iram0_dram0_dma_split_line_constrain_3.pms_core_x_iram0_sram_line_1_category_5_x,
		this->core_x_iram0_dram0_dma_split_line_constrain_3.pms_core_x_iram0_sram_line_1_category_5_y
	);
	this->core_x_iram0_dram0_dma_split_line_constrain_3.pms_core_x_iram0_sram_line_1_category_4 = this->regGet(
		this->core_x_iram0_dram0_dma_split_line_constrain_3.val,
		this->core_x_iram0_dram0_dma_split_line_constrain_3.pms_core_x_iram0_sram_line_1_category_4_x,
		this->core_x_iram0_dram0_dma_split_line_constrain_3.pms_core_x_iram0_sram_line_1_category_4_y
	);
	this->core_x_iram0_dram0_dma_split_line_constrain_3.pms_core_x_iram0_sram_line_1_category_3 = this->regGet(
		this->core_x_iram0_dram0_dma_split_line_constrain_3.val,
		this->core_x_iram0_dram0_dma_split_line_constrain_3.pms_core_x_iram0_sram_line_1_category_3_x,
		this->core_x_iram0_dram0_dma_split_line_constrain_3.pms_core_x_iram0_sram_line_1_category_3_y
	);
	this->core_x_iram0_dram0_dma_split_line_constrain_3.pms_core_x_iram0_sram_line_1_category_2 = this->regGet(
		this->core_x_iram0_dram0_dma_split_line_constrain_3.val,
		this->core_x_iram0_dram0_dma_split_line_constrain_3.pms_core_x_iram0_sram_line_1_category_2_x,
		this->core_x_iram0_dram0_dma_split_line_constrain_3.pms_core_x_iram0_sram_line_1_category_2_y
	);
	this->core_x_iram0_dram0_dma_split_line_constrain_3.pms_core_x_iram0_sram_line_1_category_1 = this->regGet(
		this->core_x_iram0_dram0_dma_split_line_constrain_3.val,
		this->core_x_iram0_dram0_dma_split_line_constrain_3.pms_core_x_iram0_sram_line_1_category_1_x,
		this->core_x_iram0_dram0_dma_split_line_constrain_3.pms_core_x_iram0_sram_line_1_category_1_y
	);
	this->core_x_iram0_dram0_dma_split_line_constrain_3.pms_core_x_iram0_sram_line_1_category_0 = this->regGet(
		this->core_x_iram0_dram0_dma_split_line_constrain_3.val,
		this->core_x_iram0_dram0_dma_split_line_constrain_3.pms_core_x_iram0_sram_line_1_category_0_x,
		this->core_x_iram0_dram0_dma_split_line_constrain_3.pms_core_x_iram0_sram_line_1_category_0_y
	);
}
void PmsDebug::init_core_x_iram0_dram0_dma_split_line_constrain_4(void){
	uint16_t base = this->core_x_iram0_dram0_dma_split_line_constrain_4.base;
	this->core_x_iram0_dram0_dma_split_line_constrain_4.val = this->regRead(true, base);
	this->core_x_iram0_dram0_dma_split_line_constrain_4.pms_core_x_dram0_dma_sram_line_0_splitaddr = this->regGet(
		this->core_x_iram0_dram0_dma_split_line_constrain_4.val,
		this->core_x_iram0_dram0_dma_split_line_constrain_4.pms_core_x_dram0_dma_sram_line_0_splitaddr_x,
		this->core_x_iram0_dram0_dma_split_line_constrain_4.pms_core_x_dram0_dma_sram_line_0_splitaddr_y
	);
	this->core_x_iram0_dram0_dma_split_line_constrain_4.pms_core_x_dram0_dma_sram_line_0_category_6 = this->regGet(
		this->core_x_iram0_dram0_dma_split_line_constrain_4.val,
		this->core_x_iram0_dram0_dma_split_line_constrain_4.pms_core_x_dram0_dma_sram_line_0_category_6_x,
		this->core_x_iram0_dram0_dma_split_line_constrain_4.pms_core_x_dram0_dma_sram_line_0_category_6_y
	);
	this->core_x_iram0_dram0_dma_split_line_constrain_4.pms_core_x_dram0_dma_sram_line_0_category_5 = this->regGet(
		this->core_x_iram0_dram0_dma_split_line_constrain_4.val,
		this->core_x_iram0_dram0_dma_split_line_constrain_4.pms_core_x_dram0_dma_sram_line_0_category_5_x,
		this->core_x_iram0_dram0_dma_split_line_constrain_4.pms_core_x_dram0_dma_sram_line_0_category_5_y
	);
	this->core_x_iram0_dram0_dma_split_line_constrain_4.pms_core_x_dram0_dma_sram_line_0_category_4 = this->regGet(
		this->core_x_iram0_dram0_dma_split_line_constrain_4.val,
		this->core_x_iram0_dram0_dma_split_line_constrain_4.pms_core_x_dram0_dma_sram_line_0_category_4_x,
		this->core_x_iram0_dram0_dma_split_line_constrain_4.pms_core_x_dram0_dma_sram_line_0_category_4_y
	);
	this->core_x_iram0_dram0_dma_split_line_constrain_4.pms_core_x_dram0_dma_sram_line_0_category_3 = this->regGet(
		this->core_x_iram0_dram0_dma_split_line_constrain_4.val,
		this->core_x_iram0_dram0_dma_split_line_constrain_4.pms_core_x_dram0_dma_sram_line_0_category_3_x,
		this->core_x_iram0_dram0_dma_split_line_constrain_4.pms_core_x_dram0_dma_sram_line_0_category_3_y
	);
	this->core_x_iram0_dram0_dma_split_line_constrain_4.pms_core_x_dram0_dma_sram_line_0_category_2 = this->regGet(
		this->core_x_iram0_dram0_dma_split_line_constrain_4.val,
		this->core_x_iram0_dram0_dma_split_line_constrain_4.pms_core_x_dram0_dma_sram_line_0_category_2_x,
		this->core_x_iram0_dram0_dma_split_line_constrain_4.pms_core_x_dram0_dma_sram_line_0_category_2_y
	);
	this->core_x_iram0_dram0_dma_split_line_constrain_4.pms_core_x_dram0_dma_sram_line_0_category_1 = this->regGet(
		this->core_x_iram0_dram0_dma_split_line_constrain_4.val,
		this->core_x_iram0_dram0_dma_split_line_constrain_4.pms_core_x_dram0_dma_sram_line_0_category_1_x,
		this->core_x_iram0_dram0_dma_split_line_constrain_4.pms_core_x_dram0_dma_sram_line_0_category_1_y
	);
	this->core_x_iram0_dram0_dma_split_line_constrain_4.pms_core_x_dram0_dma_sram_line_0_category_0 = this->regGet(
		this->core_x_iram0_dram0_dma_split_line_constrain_4.val,
		this->core_x_iram0_dram0_dma_split_line_constrain_4.pms_core_x_dram0_dma_sram_line_0_category_0_x,
		this->core_x_iram0_dram0_dma_split_line_constrain_4.pms_core_x_dram0_dma_sram_line_0_category_0_y
	);
}
void PmsDebug::init_core_x_iram0_dram0_dma_split_line_constrain_5(void){
	uint16_t base = this->core_x_iram0_dram0_dma_split_line_constrain_5.base;
	this->core_x_iram0_dram0_dma_split_line_constrain_5.val = this->regRead(true, base);
	this->core_x_iram0_dram0_dma_split_line_constrain_5.pms_core_x_dram0_dma_sram_line_1_splitaddr = this->regGet(
		this->core_x_iram0_dram0_dma_split_line_constrain_5.val,
		this->core_x_iram0_dram0_dma_split_line_constrain_5.pms_core_x_dram0_dma_sram_line_1_splitaddr_x,
		this->core_x_iram0_dram0_dma_split_line_constrain_5.pms_core_x_dram0_dma_sram_line_1_splitaddr_y
	);
	this->core_x_iram0_dram0_dma_split_line_constrain_5.pms_core_x_dram0_dma_sram_line_1_category_6 = this->regGet(
		this->core_x_iram0_dram0_dma_split_line_constrain_5.val,
		this->core_x_iram0_dram0_dma_split_line_constrain_5.pms_core_x_dram0_dma_sram_line_1_category_6_x,
		this->core_x_iram0_dram0_dma_split_line_constrain_5.pms_core_x_dram0_dma_sram_line_1_category_6_y
	);
	this->core_x_iram0_dram0_dma_split_line_constrain_5.pms_core_x_dram0_dma_sram_line_1_category_5 = this->regGet(
		this->core_x_iram0_dram0_dma_split_line_constrain_5.val,
		this->core_x_iram0_dram0_dma_split_line_constrain_5.pms_core_x_dram0_dma_sram_line_1_category_5_x,
		this->core_x_iram0_dram0_dma_split_line_constrain_5.pms_core_x_dram0_dma_sram_line_1_category_5_y
	);
	this->core_x_iram0_dram0_dma_split_line_constrain_5.pms_core_x_dram0_dma_sram_line_1_category_4 = this->regGet(
		this->core_x_iram0_dram0_dma_split_line_constrain_5.val,
		this->core_x_iram0_dram0_dma_split_line_constrain_5.pms_core_x_dram0_dma_sram_line_1_category_4_x,
		this->core_x_iram0_dram0_dma_split_line_constrain_5.pms_core_x_dram0_dma_sram_line_1_category_4_y
	);
	this->core_x_iram0_dram0_dma_split_line_constrain_5.pms_core_x_dram0_dma_sram_line_1_category_3 = this->regGet(
		this->core_x_iram0_dram0_dma_split_line_constrain_5.val,
		this->core_x_iram0_dram0_dma_split_line_constrain_5.pms_core_x_dram0_dma_sram_line_1_category_3_x,
		this->core_x_iram0_dram0_dma_split_line_constrain_5.pms_core_x_dram0_dma_sram_line_1_category_3_y
	);
	this->core_x_iram0_dram0_dma_split_line_constrain_5.pms_core_x_dram0_dma_sram_line_1_category_2 = this->regGet(
		this->core_x_iram0_dram0_dma_split_line_constrain_5.val,
		this->core_x_iram0_dram0_dma_split_line_constrain_5.pms_core_x_dram0_dma_sram_line_1_category_2_x,
		this->core_x_iram0_dram0_dma_split_line_constrain_5.pms_core_x_dram0_dma_sram_line_1_category_2_y
	);
	this->core_x_iram0_dram0_dma_split_line_constrain_5.pms_core_x_dram0_dma_sram_line_1_category_1 = this->regGet(
		this->core_x_iram0_dram0_dma_split_line_constrain_5.val,
		this->core_x_iram0_dram0_dma_split_line_constrain_5.pms_core_x_dram0_dma_sram_line_1_category_1_x,
		this->core_x_iram0_dram0_dma_split_line_constrain_5.pms_core_x_dram0_dma_sram_line_1_category_1_y
	);
	this->core_x_iram0_dram0_dma_split_line_constrain_5.pms_core_x_dram0_dma_sram_line_1_category_0 = this->regGet(
		this->core_x_iram0_dram0_dma_split_line_constrain_5.val,
		this->core_x_iram0_dram0_dma_split_line_constrain_5.pms_core_x_dram0_dma_sram_line_1_category_0_x,
		this->core_x_iram0_dram0_dma_split_line_constrain_5.pms_core_x_dram0_dma_sram_line_1_category_0_y
	);
}
void PmsDebug::init_core_x_iram0_pms_constrain_0(void){
	uint16_t base = this->core_x_iram0_pms_constrain_0.base;
	this->core_x_iram0_pms_constrain_0.val = this->regRead(true, base);
	this->core_x_iram0_pms_constrain_0.pms_core_x_iram0_pms_constrain_lock = this->regGet(
		this->core_x_iram0_pms_constrain_0.val,
		this->core_x_iram0_pms_constrain_0.pms_core_x_iram0_pms_constrain_lock_pos
	);
}
void PmsDebug::init_core_x_iram0_pms_constrain_1(void){
	uint16_t base = this->core_x_iram0_pms_constrain_1.base;
	this->core_x_iram0_pms_constrain_1.val = this->regRead(true, base);
	this->core_x_iram0_pms_constrain_1.pms_core_x_iram0_pms_constrain_rom_world_1_pms = this->regGet(
		this->core_x_iram0_pms_constrain_1.val,
		this->core_x_iram0_pms_constrain_1.pms_core_x_iram0_pms_constrain_rom_world_1_pms_x,
		this->core_x_iram0_pms_constrain_1.pms_core_x_iram0_pms_constrain_rom_world_1_pms_y
	);
	this->core_x_iram0_pms_constrain_1.pms_core_x_iram0_pms_constrain_sram_world_1_cachedataarray_pms_1 = this->regGet(
		this->core_x_iram0_pms_constrain_1.val,
		this->core_x_iram0_pms_constrain_1.pms_core_x_iram0_pms_constrain_sram_world_1_cachedataarray_pms_1_x,
		this->core_x_iram0_pms_constrain_1.pms_core_x_iram0_pms_constrain_sram_world_1_cachedataarray_pms_1_y
	);
	this->core_x_iram0_pms_constrain_1.pms_core_x_iram0_pms_constrain_sram_world_1_cachedataarray_pms_0 = this->regGet(
		this->core_x_iram0_pms_constrain_1.val,
		this->core_x_iram0_pms_constrain_1.pms_core_x_iram0_pms_constrain_sram_world_1_cachedataarray_pms_0_x,
		this->core_x_iram0_pms_constrain_1.pms_core_x_iram0_pms_constrain_sram_world_1_cachedataarray_pms_0_y
	);
	this->core_x_iram0_pms_constrain_1.pms_core_x_iram0_pms_constrain_sram_world_1_pms_3 = this->regGet(
		this->core_x_iram0_pms_constrain_1.val,
		this->core_x_iram0_pms_constrain_1.pms_core_x_iram0_pms_constrain_sram_world_1_pms_3_x,
		this->core_x_iram0_pms_constrain_1.pms_core_x_iram0_pms_constrain_sram_world_1_pms_3_y
	);
	this->core_x_iram0_pms_constrain_1.pms_core_x_iram0_pms_constrain_sram_world_1_pms_2 = this->regGet(
		this->core_x_iram0_pms_constrain_1.val,
		this->core_x_iram0_pms_constrain_1.pms_core_x_iram0_pms_constrain_sram_world_1_pms_2_x,
		this->core_x_iram0_pms_constrain_1.pms_core_x_iram0_pms_constrain_sram_world_1_pms_2_y
	);
	this->core_x_iram0_pms_constrain_1.pms_core_x_iram0_pms_constrain_sram_world_1_pms_1 = this->regGet(
		this->core_x_iram0_pms_constrain_1.val,
		this->core_x_iram0_pms_constrain_1.pms_core_x_iram0_pms_constrain_sram_world_1_pms_1_x,
		this->core_x_iram0_pms_constrain_1.pms_core_x_iram0_pms_constrain_sram_world_1_pms_1_y
	);
	this->core_x_iram0_pms_constrain_1.pms_core_x_iram0_pms_constrain_sram_world_1_pms_0 = this->regGet(
		this->core_x_iram0_pms_constrain_1.val,
		this->core_x_iram0_pms_constrain_1.pms_core_x_iram0_pms_constrain_sram_world_1_pms_0_x,
		this->core_x_iram0_pms_constrain_1.pms_core_x_iram0_pms_constrain_sram_world_1_pms_0_y
	);
}
void PmsDebug::init_core_x_iram0_pms_constrain_2(void){
	uint16_t base = this->core_x_iram0_pms_constrain_2.base;
	this->core_x_iram0_pms_constrain_2.val = this->regRead(true, base);
	this->core_x_iram0_pms_constrain_2.pms_core_x_iram0_pms_constrain_rom_world_0_pms = this->regGet(
		this->core_x_iram0_pms_constrain_2.val,
		this->core_x_iram0_pms_constrain_2.pms_core_x_iram0_pms_constrain_rom_world_0_pms_x,
		this->core_x_iram0_pms_constrain_2.pms_core_x_iram0_pms_constrain_rom_world_0_pms_y
	);
	this->core_x_iram0_pms_constrain_2.pms_core_x_iram0_pms_constrain_sram_world_0_cachedataarray_pms_1 = this->regGet(
		this->core_x_iram0_pms_constrain_2.val,
		this->core_x_iram0_pms_constrain_2.pms_core_x_iram0_pms_constrain_sram_world_0_cachedataarray_pms_1_x,
		this->core_x_iram0_pms_constrain_2.pms_core_x_iram0_pms_constrain_sram_world_0_cachedataarray_pms_1_y
	);
	this->core_x_iram0_pms_constrain_2.pms_core_x_iram0_pms_constrain_sram_world_0_cachedataarray_pms_0 = this->regGet(
		this->core_x_iram0_pms_constrain_2.val,
		this->core_x_iram0_pms_constrain_2.pms_core_x_iram0_pms_constrain_sram_world_0_cachedataarray_pms_0_x,
		this->core_x_iram0_pms_constrain_2.pms_core_x_iram0_pms_constrain_sram_world_0_cachedataarray_pms_0_y
	);
	this->core_x_iram0_pms_constrain_2.pms_core_x_iram0_pms_constrain_sram_world_0_pms_3 = this->regGet(
		this->core_x_iram0_pms_constrain_2.val,
		this->core_x_iram0_pms_constrain_2.pms_core_x_iram0_pms_constrain_sram_world_0_pms_3_x,
		this->core_x_iram0_pms_constrain_2.pms_core_x_iram0_pms_constrain_sram_world_0_pms_3_y
	);
	this->core_x_iram0_pms_constrain_2.pms_core_x_iram0_pms_constrain_sram_world_0_pms_2 = this->regGet(
		this->core_x_iram0_pms_constrain_2.val,
		this->core_x_iram0_pms_constrain_2.pms_core_x_iram0_pms_constrain_sram_world_0_pms_2_x,
		this->core_x_iram0_pms_constrain_2.pms_core_x_iram0_pms_constrain_sram_world_0_pms_2_y
	);
	this->core_x_iram0_pms_constrain_2.pms_core_x_iram0_pms_constrain_sram_world_0_pms_1 = this->regGet(
		this->core_x_iram0_pms_constrain_2.val,
		this->core_x_iram0_pms_constrain_2.pms_core_x_iram0_pms_constrain_sram_world_0_pms_1_x,
		this->core_x_iram0_pms_constrain_2.pms_core_x_iram0_pms_constrain_sram_world_0_pms_1_y
	);
	this->core_x_iram0_pms_constrain_2.pms_core_x_iram0_pms_constrain_sram_world_0_pms_0 = this->regGet(
		this->core_x_iram0_pms_constrain_2.val,
		this->core_x_iram0_pms_constrain_2.pms_core_x_iram0_pms_constrain_sram_world_0_pms_0_x,
		this->core_x_iram0_pms_constrain_2.pms_core_x_iram0_pms_constrain_sram_world_0_pms_0_y
	);
}
void PmsDebug::init_core_0_iram0_pms_monitor_0(void){
	uint16_t base = this->core_0_iram0_pms_monitor_0.base;
	this->core_0_iram0_pms_monitor_0.val = this->regRead(true, base);
	this->core_0_iram0_pms_monitor_0.pms_core_0_iram0_pms_monitor_lock = this->regGet(
		this->core_0_iram0_pms_monitor_0.val,
		this->core_0_iram0_pms_monitor_0.pms_core_0_iram0_pms_monitor_lock_pos
	);
}
void PmsDebug::init_core_0_iram0_pms_monitor_1(void){
	uint16_t base = this->core_0_iram0_pms_monitor_1.base;
	this->core_0_iram0_pms_monitor_1.val = this->regRead(true, base);
	this->core_0_iram0_pms_monitor_1.pms_core_0_iram0_pms_monitor_violate_en = this->regGet(
		this->core_0_iram0_pms_monitor_1.val,
		this->core_0_iram0_pms_monitor_1.pms_core_0_iram0_pms_monitor_violate_en_pos
	);
	this->core_0_iram0_pms_monitor_1.pms_core_0_iram0_pms_monitor_violate_clr = this->regGet(
		this->core_0_iram0_pms_monitor_1.val,
		this->core_0_iram0_pms_monitor_1.pms_core_0_iram0_pms_monitor_violate_clr_pos
	);
}
void PmsDebug::init_core_x_dram0_pms_constrain_0(void){
	uint16_t base = this->core_x_dram0_pms_constrain_0.base;
	this->core_x_dram0_pms_constrain_0.val = this->regRead(true, base);
	this->core_x_dram0_pms_constrain_0.pms_core_x_dram0_pms_constrain_lock = this->regGet(
		this->core_x_dram0_pms_constrain_0.val,
		this->core_x_dram0_pms_constrain_0.pms_core_x_dram0_pms_constrain_lock_pos
	);
}
void PmsDebug::init_core_x_dram0_pms_constrain_1(void){
	uint16_t base = this->core_x_dram0_pms_constrain_1.base;
	this->core_x_dram0_pms_constrain_1.val = this->regRead(true, base);
	this->core_x_dram0_pms_constrain_1.pms_core_x_dram0_pms_constrain_rom_world_1_pms = this->regGet(
		this->core_x_dram0_pms_constrain_1.val,
		this->core_x_dram0_pms_constrain_1.pms_core_x_dram0_pms_constrain_rom_world_1_pms_x,
		this->core_x_dram0_pms_constrain_1.pms_core_x_dram0_pms_constrain_rom_world_1_pms_y
	);
	this->core_x_dram0_pms_constrain_1.pms_core_x_dram0_pms_constrain_rom_world_0_pms = this->regGet(
		this->core_x_dram0_pms_constrain_1.val,
		this->core_x_dram0_pms_constrain_1.pms_core_x_dram0_pms_constrain_rom_world_0_pms_x,
		this->core_x_dram0_pms_constrain_1.pms_core_x_dram0_pms_constrain_rom_world_0_pms_y
	);
	this->core_x_dram0_pms_constrain_1.pms_core_x_dram0_pms_constrain_sram_world_1_cachedataarray_pms_1 = this->regGet(
		this->core_x_dram0_pms_constrain_1.val,
		this->core_x_dram0_pms_constrain_1.pms_core_x_dram0_pms_constrain_sram_world_1_cachedataarray_pms_1_x,
		this->core_x_dram0_pms_constrain_1.pms_core_x_dram0_pms_constrain_sram_world_1_cachedataarray_pms_1_y
	);
	this->core_x_dram0_pms_constrain_1.pms_core_x_dram0_pms_constrain_sram_world_1_cachedataarray_pms_0 = this->regGet(
		this->core_x_dram0_pms_constrain_1.val,
		this->core_x_dram0_pms_constrain_1.pms_core_x_dram0_pms_constrain_sram_world_1_cachedataarray_pms_0_x,
		this->core_x_dram0_pms_constrain_1.pms_core_x_dram0_pms_constrain_sram_world_1_cachedataarray_pms_0_y
	);
	this->core_x_dram0_pms_constrain_1.pms_core_x_dram0_pms_constrain_sram_world_1_pms_3 = this->regGet(
		this->core_x_dram0_pms_constrain_1.val,
		this->core_x_dram0_pms_constrain_1.pms_core_x_dram0_pms_constrain_sram_world_1_pms_3_x,
		this->core_x_dram0_pms_constrain_1.pms_core_x_dram0_pms_constrain_sram_world_1_pms_3_y
	);
	this->core_x_dram0_pms_constrain_1.pms_core_x_dram0_pms_constrain_sram_world_1_pms_2 = this->regGet(
		this->core_x_dram0_pms_constrain_1.val,
		this->core_x_dram0_pms_constrain_1.pms_core_x_dram0_pms_constrain_sram_world_1_pms_2_x,
		this->core_x_dram0_pms_constrain_1.pms_core_x_dram0_pms_constrain_sram_world_1_pms_2_y
	);
	this->core_x_dram0_pms_constrain_1.pms_core_x_dram0_pms_constrain_sram_world_1_pms_1 = this->regGet(
		this->core_x_dram0_pms_constrain_1.val,
		this->core_x_dram0_pms_constrain_1.pms_core_x_dram0_pms_constrain_sram_world_1_pms_1_x,
		this->core_x_dram0_pms_constrain_1.pms_core_x_dram0_pms_constrain_sram_world_1_pms_1_y
	);
	this->core_x_dram0_pms_constrain_1.pms_core_x_dram0_pms_constrain_sram_world_1_pms_0 = this->regGet(
		this->core_x_dram0_pms_constrain_1.val,
		this->core_x_dram0_pms_constrain_1.pms_core_x_dram0_pms_constrain_sram_world_1_pms_0_x,
		this->core_x_dram0_pms_constrain_1.pms_core_x_dram0_pms_constrain_sram_world_1_pms_0_y
	);
	this->core_x_dram0_pms_constrain_1.pms_core_x_dram0_pms_constrain_sram_world_0_cachedataarray_pms_1 = this->regGet(
		this->core_x_dram0_pms_constrain_1.val,
		this->core_x_dram0_pms_constrain_1.pms_core_x_dram0_pms_constrain_sram_world_0_cachedataarray_pms_1_x,
		this->core_x_dram0_pms_constrain_1.pms_core_x_dram0_pms_constrain_sram_world_0_cachedataarray_pms_1_y
	);
	this->core_x_dram0_pms_constrain_1.pms_core_x_dram0_pms_constrain_sram_world_0_cachedataarray_pms_0 = this->regGet(
		this->core_x_dram0_pms_constrain_1.val,
		this->core_x_dram0_pms_constrain_1.pms_core_x_dram0_pms_constrain_sram_world_0_cachedataarray_pms_0_x,
		this->core_x_dram0_pms_constrain_1.pms_core_x_dram0_pms_constrain_sram_world_0_cachedataarray_pms_0_y
	);
	this->core_x_dram0_pms_constrain_1.pms_core_x_dram0_pms_constrain_sram_world_0_pms_3 = this->regGet(
		this->core_x_dram0_pms_constrain_1.val,
		this->core_x_dram0_pms_constrain_1.pms_core_x_dram0_pms_constrain_sram_world_0_pms_3_x,
		this->core_x_dram0_pms_constrain_1.pms_core_x_dram0_pms_constrain_sram_world_0_pms_3_y
	);
	this->core_x_dram0_pms_constrain_1.pms_core_x_dram0_pms_constrain_sram_world_0_pms_2 = this->regGet(
		this->core_x_dram0_pms_constrain_1.val,
		this->core_x_dram0_pms_constrain_1.pms_core_x_dram0_pms_constrain_sram_world_0_pms_2_x,
		this->core_x_dram0_pms_constrain_1.pms_core_x_dram0_pms_constrain_sram_world_0_pms_2_y
	);
	this->core_x_dram0_pms_constrain_1.pms_core_x_dram0_pms_constrain_sram_world_0_pms_1 = this->regGet(
		this->core_x_dram0_pms_constrain_1.val,
		this->core_x_dram0_pms_constrain_1.pms_core_x_dram0_pms_constrain_sram_world_0_pms_1_x,
		this->core_x_dram0_pms_constrain_1.pms_core_x_dram0_pms_constrain_sram_world_0_pms_1_y
	);
	this->core_x_dram0_pms_constrain_1.pms_core_x_dram0_pms_constrain_sram_world_0_pms_0 = this->regGet(
		this->core_x_dram0_pms_constrain_1.val,
		this->core_x_dram0_pms_constrain_1.pms_core_x_dram0_pms_constrain_sram_world_0_pms_0_x,
		this->core_x_dram0_pms_constrain_1.pms_core_x_dram0_pms_constrain_sram_world_0_pms_0_y
	);
}
void PmsDebug::init_core_0_dram0_pms_monitor_0(void){
	uint16_t base = this->core_0_dram0_pms_monitor_0.base;
	this->core_0_dram0_pms_monitor_0.val = this->regRead(true, base);
	this->core_0_dram0_pms_monitor_0.pms_core_0_dram0_pms_monitor_lock = this->regGet(
		this->core_0_dram0_pms_monitor_0.val,
		this->core_0_dram0_pms_monitor_0.pms_core_0_dram0_pms_monitor_lock_pos
	);
}
void PmsDebug::init_core_0_dram0_pms_monitor_1(void){
	uint16_t base = this->core_0_dram0_pms_monitor_1.base;
	this->core_0_dram0_pms_monitor_1.val = this->regRead(true, base);
	this->core_0_dram0_pms_monitor_1.pms_core_0_dram0_pms_monitor_violate_en = this->regGet(
		this->core_0_dram0_pms_monitor_1.val,
		this->core_0_dram0_pms_monitor_1.pms_core_0_dram0_pms_monitor_violate_en_pos
	);
	this->core_0_dram0_pms_monitor_1.pms_core_0_dram0_pms_monitor_violate_clr = this->regGet(
		this->core_0_dram0_pms_monitor_1.val,
		this->core_0_dram0_pms_monitor_1.pms_core_0_dram0_pms_monitor_violate_clr_pos
	);
}
void PmsDebug::init_core_0_pif_pms_constrain_0(void){
	uint16_t base = this->core_0_pif_pms_constrain_0.base;
	this->core_0_pif_pms_constrain_0.val = this->regRead(true, base);
	this->core_0_pif_pms_constrain_0.pms_core_0_pif_pms_constrain_lock = this->regGet(
		this->core_0_pif_pms_constrain_0.val,
		this->core_0_pif_pms_constrain_0.pms_core_0_pif_pms_constrain_lock_pos
	);
}
void PmsDebug::init_core_0_pif_pms_constrain_n(void){
	uint16_t base = this->core_0_pif_pms_constrain_n.base;
	this->core_0_pif_pms_constrain_n.val = this->regRead(true, base);
	this->core_0_pif_pms_constrain_n.pms_core_0_pif_pms_constrain_world_0_uart1 = this->regGet(
		this->core_0_pif_pms_constrain_n.val,
		this->core_0_pif_pms_constrain_n.pms_core_0_pif_pms_constrain_world_0_uart1_x,
		this->core_0_pif_pms_constrain_n.pms_core_0_pif_pms_constrain_world_0_uart1_y
	);
	this->core_0_pif_pms_constrain_n.pms_core_0_pif_pms_constrain_world_0_i2s0 = this->regGet(
		this->core_0_pif_pms_constrain_n.val,
		this->core_0_pif_pms_constrain_n.pms_core_0_pif_pms_constrain_world_0_i2s0_x,
		this->core_0_pif_pms_constrain_n.pms_core_0_pif_pms_constrain_world_0_i2s0_y
	);
	this->core_0_pif_pms_constrain_n.pms_core_0_pif_pms_constrain_world_0_io_mux = this->regGet(
		this->core_0_pif_pms_constrain_n.val,
		this->core_0_pif_pms_constrain_n.pms_core_0_pif_pms_constrain_world_0_io_mux_x,
		this->core_0_pif_pms_constrain_n.pms_core_0_pif_pms_constrain_world_0_io_mux_y
	);
	this->core_0_pif_pms_constrain_n.pms_core_0_pif_pms_constrain_world_0_rtc = this->regGet(
		this->core_0_pif_pms_constrain_n.val,
		this->core_0_pif_pms_constrain_n.pms_core_0_pif_pms_constrain_world_0_rtc_x,
		this->core_0_pif_pms_constrain_n.pms_core_0_pif_pms_constrain_world_0_rtc_y
	);
	this->core_0_pif_pms_constrain_n.pms_core_0_pif_pms_constrain_world_0_gpio = this->regGet(
		this->core_0_pif_pms_constrain_n.val,
		this->core_0_pif_pms_constrain_n.pms_core_0_pif_pms_constrain_world_0_gpio_x,
		this->core_0_pif_pms_constrain_n.pms_core_0_pif_pms_constrain_world_0_gpio_y
	);
	this->core_0_pif_pms_constrain_n.pms_core_0_pif_pms_constrain_world_0_g0spi_0 = this->regGet(
		this->core_0_pif_pms_constrain_n.val,
		this->core_0_pif_pms_constrain_n.pms_core_0_pif_pms_constrain_world_0_g0spi_0_x,
		this->core_0_pif_pms_constrain_n.pms_core_0_pif_pms_constrain_world_0_g0spi_0_y
	);
	this->core_0_pif_pms_constrain_n.pms_core_0_pif_pms_constrain_world_0_g0spi_1 = this->regGet(
		this->core_0_pif_pms_constrain_n.val,
		this->core_0_pif_pms_constrain_n.pms_core_0_pif_pms_constrain_world_0_g0spi_1_x,
		this->core_0_pif_pms_constrain_n.pms_core_0_pif_pms_constrain_world_0_g0spi_1_y
	);
	this->core_0_pif_pms_constrain_n.pms_core_0_pif_pms_constrain_world_0_uart = this->regGet(
		this->core_0_pif_pms_constrain_n.val,
		this->core_0_pif_pms_constrain_n.pms_core_0_pif_pms_constrain_world_0_uart_x,
		this->core_0_pif_pms_constrain_n.pms_core_0_pif_pms_constrain_world_0_uart_y
	);
}
void PmsDebug::init_core_0_pif_pms_constrain_9(void){
	uint16_t base = this->core_0_pif_pms_constrain_9.base;
	this->core_0_pif_pms_constrain_9.val = this->regRead(true, base);
	this->core_0_pif_pms_constrain_9.pms_core_0_pif_pms_constrain_rtcfast_spltaddr_world_1 = this->regGet(
		this->core_0_pif_pms_constrain_9.val,
		this->core_0_pif_pms_constrain_9.pms_core_0_pif_pms_constrain_rtcfast_spltaddr_world_1_x,
		this->core_0_pif_pms_constrain_9.pms_core_0_pif_pms_constrain_rtcfast_spltaddr_world_1_y
	);
	this->core_0_pif_pms_constrain_9.pms_core_0_pif_pms_constrain_rtcfast_spltaddr_world_0 = this->regGet(
		this->core_0_pif_pms_constrain_9.val,
		this->core_0_pif_pms_constrain_9.pms_core_0_pif_pms_constrain_rtcfast_spltaddr_world_0_x,
		this->core_0_pif_pms_constrain_9.pms_core_0_pif_pms_constrain_rtcfast_spltaddr_world_0_y
	);
}
void PmsDebug::init_core_0_pif_pms_constrain_10(void){
	uint16_t base = this->core_0_pif_pms_constrain_10.base;
	this->core_0_pif_pms_constrain_10.val = this->regRead(true, base);
	this->core_0_pif_pms_constrain_10.pms_core_0_pif_pms_constrain_rtcfast_world_1_h = this->regGet(
		this->core_0_pif_pms_constrain_10.val,
		this->core_0_pif_pms_constrain_10.pms_core_0_pif_pms_constrain_rtcfast_world_1_h_x,
		this->core_0_pif_pms_constrain_10.pms_core_0_pif_pms_constrain_rtcfast_world_1_h_y
	);
	this->core_0_pif_pms_constrain_10.pms_core_0_pif_pms_constrain_rtcfast_world_1_l = this->regGet(
		this->core_0_pif_pms_constrain_10.val,
		this->core_0_pif_pms_constrain_10.pms_core_0_pif_pms_constrain_rtcfast_world_1_l_x,
		this->core_0_pif_pms_constrain_10.pms_core_0_pif_pms_constrain_rtcfast_world_1_l_y
	);
	this->core_0_pif_pms_constrain_10.pms_core_0_pif_pms_constrain_rtcfast_world_0_h = this->regGet(
		this->core_0_pif_pms_constrain_10.val,
		this->core_0_pif_pms_constrain_10.pms_core_0_pif_pms_constrain_rtcfast_world_0_h_x,
		this->core_0_pif_pms_constrain_10.pms_core_0_pif_pms_constrain_rtcfast_world_0_h_y
	);
	this->core_0_pif_pms_constrain_10.pms_core_0_pif_pms_constrain_rtcfast_world_0_l = this->regGet(
		this->core_0_pif_pms_constrain_10.val,
		this->core_0_pif_pms_constrain_10.pms_core_0_pif_pms_constrain_rtcfast_world_0_l_x,
		this->core_0_pif_pms_constrain_10.pms_core_0_pif_pms_constrain_rtcfast_world_0_l_y
	);
}
void PmsDebug::init_core_0_pif_pms_constrain_11(void){
	uint16_t base = this->core_0_pif_pms_constrain_11.base;
	this->core_0_pif_pms_constrain_11.val = this->regRead(true, base);
	this->core_0_pif_pms_constrain_11.pms_core_0_pif_pms_constrain_rtcslow_0_spltaddr_world_1 = this->regGet(
		this->core_0_pif_pms_constrain_11.val,
		this->core_0_pif_pms_constrain_11.pms_core_0_pif_pms_constrain_rtcslow_0_spltaddr_world_1_x,
		this->core_0_pif_pms_constrain_11.pms_core_0_pif_pms_constrain_rtcslow_0_spltaddr_world_1_y
	);
	this->core_0_pif_pms_constrain_11.pms_core_0_pif_pms_constrain_rtcslow_0_spltaddr_world_0 = this->regGet(
		this->core_0_pif_pms_constrain_11.val,
		this->core_0_pif_pms_constrain_11.pms_core_0_pif_pms_constrain_rtcslow_0_spltaddr_world_0_x,
		this->core_0_pif_pms_constrain_11.pms_core_0_pif_pms_constrain_rtcslow_0_spltaddr_world_0_y
	);
}
void PmsDebug::init_core_0_pif_pms_constrain_12(void){
	uint16_t base = this->core_0_pif_pms_constrain_12.base;
	this->core_0_pif_pms_constrain_12.val = this->regRead(true, base);
	this->core_0_pif_pms_constrain_12.pms_core_0_pif_pms_constrain_rtcslow_0_world_1_h = this->regGet(
		this->core_0_pif_pms_constrain_12.val,
		this->core_0_pif_pms_constrain_12.pms_core_0_pif_pms_constrain_rtcslow_0_world_1_h_x,
		this->core_0_pif_pms_constrain_12.pms_core_0_pif_pms_constrain_rtcslow_0_world_1_h_y
	);
	this->core_0_pif_pms_constrain_12.pms_core_0_pif_pms_constrain_rtcslow_0_world_1_l = this->regGet(
		this->core_0_pif_pms_constrain_12.val,
		this->core_0_pif_pms_constrain_12.pms_core_0_pif_pms_constrain_rtcslow_0_world_1_l_x,
		this->core_0_pif_pms_constrain_12.pms_core_0_pif_pms_constrain_rtcslow_0_world_1_l_y
	);
	this->core_0_pif_pms_constrain_12.pms_core_0_pif_pms_constrain_rtcslow_0_world_0_h = this->regGet(
		this->core_0_pif_pms_constrain_12.val,
		this->core_0_pif_pms_constrain_12.pms_core_0_pif_pms_constrain_rtcslow_0_world_0_h_x,
		this->core_0_pif_pms_constrain_12.pms_core_0_pif_pms_constrain_rtcslow_0_world_0_h_y
	);
	this->core_0_pif_pms_constrain_12.pms_core_0_pif_pms_constrain_rtcslow_0_world_0_l = this->regGet(
		this->core_0_pif_pms_constrain_12.val,
		this->core_0_pif_pms_constrain_12.pms_core_0_pif_pms_constrain_rtcslow_0_world_0_l_x,
		this->core_0_pif_pms_constrain_12.pms_core_0_pif_pms_constrain_rtcslow_0_world_0_l_y
	);
}
void PmsDebug::init_core_0_pif_pms_constrain_13(void){
	uint16_t base = this->core_0_pif_pms_constrain_13.base;
	this->core_0_pif_pms_constrain_13.val = this->regRead(true, base);
	this->core_0_pif_pms_constrain_13.pms_core_0_pif_pms_constrain_rtcslow_1_spltaddr_world_1 = this->regGet(
		this->core_0_pif_pms_constrain_13.val,
		this->core_0_pif_pms_constrain_13.pms_core_0_pif_pms_constrain_rtcslow_1_spltaddr_world_1_x,
		this->core_0_pif_pms_constrain_13.pms_core_0_pif_pms_constrain_rtcslow_1_spltaddr_world_1_y
	);
	this->core_0_pif_pms_constrain_13.pms_core_0_pif_pms_constrain_rtcslow_1_spltaddr_world_0 = this->regGet(
		this->core_0_pif_pms_constrain_13.val,
		this->core_0_pif_pms_constrain_13.pms_core_0_pif_pms_constrain_rtcslow_1_spltaddr_world_0_x,
		this->core_0_pif_pms_constrain_13.pms_core_0_pif_pms_constrain_rtcslow_1_spltaddr_world_0_y
	);
}
void PmsDebug::init_core_0_pif_pms_constrain_14(void){
	uint16_t base = this->core_0_pif_pms_constrain_14.base;
	this->core_0_pif_pms_constrain_14.val = this->regRead(true, base);
	this->core_0_pif_pms_constrain_14.pms_core_0_pif_pms_constrain_rtcslow_1_world_1_h = this->regGet(
		this->core_0_pif_pms_constrain_14.val,
		this->core_0_pif_pms_constrain_14.pms_core_0_pif_pms_constrain_rtcslow_1_world_1_h_x,
		this->core_0_pif_pms_constrain_14.pms_core_0_pif_pms_constrain_rtcslow_1_world_1_h_y
	);
	this->core_0_pif_pms_constrain_14.pms_core_0_pif_pms_constrain_rtcslow_1_world_1_l = this->regGet(
		this->core_0_pif_pms_constrain_14.val,
		this->core_0_pif_pms_constrain_14.pms_core_0_pif_pms_constrain_rtcslow_1_world_1_l_x,
		this->core_0_pif_pms_constrain_14.pms_core_0_pif_pms_constrain_rtcslow_1_world_1_l_y
	);
	this->core_0_pif_pms_constrain_14.pms_core_0_pif_pms_constrain_rtcslow_1_world_0_h = this->regGet(
		this->core_0_pif_pms_constrain_14.val,
		this->core_0_pif_pms_constrain_14.pms_core_0_pif_pms_constrain_rtcslow_1_world_0_h_x,
		this->core_0_pif_pms_constrain_14.pms_core_0_pif_pms_constrain_rtcslow_1_world_0_h_y
	);
	this->core_0_pif_pms_constrain_14.pms_core_0_pif_pms_constrain_rtcslow_1_world_0_l = this->regGet(
		this->core_0_pif_pms_constrain_14.val,
		this->core_0_pif_pms_constrain_14.pms_core_0_pif_pms_constrain_rtcslow_1_world_0_l_x,
		this->core_0_pif_pms_constrain_14.pms_core_0_pif_pms_constrain_rtcslow_1_world_0_l_y
	);
}
void PmsDebug::init_core_0_region_pms_constrain_0(void){
	uint16_t base = this->core_0_region_pms_constrain_0.base;
	this->core_0_region_pms_constrain_0.val = this->regRead(true, base);
	this->core_0_region_pms_constrain_0.pms_core_0_region_pms_constrain_lock = this->regGet(
		this->core_0_region_pms_constrain_0.val,
		this->core_0_region_pms_constrain_0.pms_core_0_region_pms_constrain_lock_pos
	);
}
void PmsDebug::init_core_0_region_pms_constrain_1(void){
	uint16_t base = this->core_0_region_pms_constrain_1.base;
	this->core_0_region_pms_constrain_1.val = this->regRead(true, base);
	this->core_0_region_pms_constrain_1.pms_core_0_region_pms_constrain_world_0_area_10 = this->regGet(
		this->core_0_region_pms_constrain_1.val,
		this->core_0_region_pms_constrain_1.pms_core_0_region_pms_constrain_world_0_area_10_x,
		this->core_0_region_pms_constrain_1.pms_core_0_region_pms_constrain_world_0_area_10_y
	);
	this->core_0_region_pms_constrain_1.pms_core_0_region_pms_constrain_world_0_area_9 = this->regGet(
		this->core_0_region_pms_constrain_1.val,
		this->core_0_region_pms_constrain_1.pms_core_0_region_pms_constrain_world_0_area_9_x,
		this->core_0_region_pms_constrain_1.pms_core_0_region_pms_constrain_world_0_area_9_y
	);
	this->core_0_region_pms_constrain_1.pms_core_0_region_pms_constrain_world_0_area_8 = this->regGet(
		this->core_0_region_pms_constrain_1.val,
		this->core_0_region_pms_constrain_1.pms_core_0_region_pms_constrain_world_0_area_8_x,
		this->core_0_region_pms_constrain_1.pms_core_0_region_pms_constrain_world_0_area_8_y
	);
	this->core_0_region_pms_constrain_1.pms_core_0_region_pms_constrain_world_0_area_7 = this->regGet(
		this->core_0_region_pms_constrain_1.val,
		this->core_0_region_pms_constrain_1.pms_core_0_region_pms_constrain_world_0_area_7_x,
		this->core_0_region_pms_constrain_1.pms_core_0_region_pms_constrain_world_0_area_7_y
	);
	this->core_0_region_pms_constrain_1.pms_core_0_region_pms_constrain_world_0_area_6 = this->regGet(
		this->core_0_region_pms_constrain_1.val,
		this->core_0_region_pms_constrain_1.pms_core_0_region_pms_constrain_world_0_area_6_x,
		this->core_0_region_pms_constrain_1.pms_core_0_region_pms_constrain_world_0_area_6_y
	);
	this->core_0_region_pms_constrain_1.pms_core_0_region_pms_constrain_world_0_area_5 = this->regGet(
		this->core_0_region_pms_constrain_1.val,
		this->core_0_region_pms_constrain_1.pms_core_0_region_pms_constrain_world_0_area_5_x,
		this->core_0_region_pms_constrain_1.pms_core_0_region_pms_constrain_world_0_area_5_y
	);
	this->core_0_region_pms_constrain_1.pms_core_0_region_pms_constrain_world_0_area_4 = this->regGet(
		this->core_0_region_pms_constrain_1.val,
		this->core_0_region_pms_constrain_1.pms_core_0_region_pms_constrain_world_0_area_4_x,
		this->core_0_region_pms_constrain_1.pms_core_0_region_pms_constrain_world_0_area_4_y
	);
	this->core_0_region_pms_constrain_1.pms_core_0_region_pms_constrain_world_0_area_3 = this->regGet(
		this->core_0_region_pms_constrain_1.val,
		this->core_0_region_pms_constrain_1.pms_core_0_region_pms_constrain_world_0_area_3_x,
		this->core_0_region_pms_constrain_1.pms_core_0_region_pms_constrain_world_0_area_3_y
	);
	this->core_0_region_pms_constrain_1.pms_core_0_region_pms_constrain_world_0_area_2 = this->regGet(
		this->core_0_region_pms_constrain_1.val,
		this->core_0_region_pms_constrain_1.pms_core_0_region_pms_constrain_world_0_area_2_x,
		this->core_0_region_pms_constrain_1.pms_core_0_region_pms_constrain_world_0_area_2_y
	);
	this->core_0_region_pms_constrain_1.pms_core_0_region_pms_constrain_world_0_area_1 = this->regGet(
		this->core_0_region_pms_constrain_1.val,
		this->core_0_region_pms_constrain_1.pms_core_0_region_pms_constrain_world_0_area_1_x,
		this->core_0_region_pms_constrain_1.pms_core_0_region_pms_constrain_world_0_area_1_y
	);
	this->core_0_region_pms_constrain_1.pms_core_0_region_pms_constrain_world_0_area_0 = this->regGet(
		this->core_0_region_pms_constrain_1.val,
		this->core_0_region_pms_constrain_1.pms_core_0_region_pms_constrain_world_0_area_0_x,
		this->core_0_region_pms_constrain_1.pms_core_0_region_pms_constrain_world_0_area_0_y
	);
}
void PmsDebug::init_core_0_region_pms_constrain_2(void){
	uint16_t base = this->core_0_region_pms_constrain_2.base;
	this->core_0_region_pms_constrain_2.val = this->regRead(true, base);
	this->core_0_region_pms_constrain_2.pms_core_0_region_pms_constrain_world_1_area_10 = this->regGet(
		this->core_0_region_pms_constrain_2.val,
		this->core_0_region_pms_constrain_2.pms_core_0_region_pms_constrain_world_1_area_10_x,
		this->core_0_region_pms_constrain_2.pms_core_0_region_pms_constrain_world_1_area_10_y
	);
	this->core_0_region_pms_constrain_2.pms_core_0_region_pms_constrain_world_1_area_9 = this->regGet(
		this->core_0_region_pms_constrain_2.val,
		this->core_0_region_pms_constrain_2.pms_core_0_region_pms_constrain_world_1_area_9_x,
		this->core_0_region_pms_constrain_2.pms_core_0_region_pms_constrain_world_1_area_9_y
	);
	this->core_0_region_pms_constrain_2.pms_core_0_region_pms_constrain_world_1_area_8 = this->regGet(
		this->core_0_region_pms_constrain_2.val,
		this->core_0_region_pms_constrain_2.pms_core_0_region_pms_constrain_world_1_area_8_x,
		this->core_0_region_pms_constrain_2.pms_core_0_region_pms_constrain_world_1_area_8_y
	);
	this->core_0_region_pms_constrain_2.pms_core_0_region_pms_constrain_world_1_area_7 = this->regGet(
		this->core_0_region_pms_constrain_2.val,
		this->core_0_region_pms_constrain_2.pms_core_0_region_pms_constrain_world_1_area_7_x,
		this->core_0_region_pms_constrain_2.pms_core_0_region_pms_constrain_world_1_area_7_y
	);
	this->core_0_region_pms_constrain_2.pms_core_0_region_pms_constrain_world_1_area_6 = this->regGet(
		this->core_0_region_pms_constrain_2.val,
		this->core_0_region_pms_constrain_2.pms_core_0_region_pms_constrain_world_1_area_6_x,
		this->core_0_region_pms_constrain_2.pms_core_0_region_pms_constrain_world_1_area_6_y
	);
	this->core_0_region_pms_constrain_2.pms_core_0_region_pms_constrain_world_1_area_5 = this->regGet(
		this->core_0_region_pms_constrain_2.val,
		this->core_0_region_pms_constrain_2.pms_core_0_region_pms_constrain_world_1_area_5_x,
		this->core_0_region_pms_constrain_2.pms_core_0_region_pms_constrain_world_1_area_5_y
	);
	this->core_0_region_pms_constrain_2.pms_core_0_region_pms_constrain_world_1_area_4 = this->regGet(
		this->core_0_region_pms_constrain_2.val,
		this->core_0_region_pms_constrain_2.pms_core_0_region_pms_constrain_world_1_area_4_x,
		this->core_0_region_pms_constrain_2.pms_core_0_region_pms_constrain_world_1_area_4_y
	);
	this->core_0_region_pms_constrain_2.pms_core_0_region_pms_constrain_world_1_area_3 = this->regGet(
		this->core_0_region_pms_constrain_2.val,
		this->core_0_region_pms_constrain_2.pms_core_0_region_pms_constrain_world_1_area_3_x,
		this->core_0_region_pms_constrain_2.pms_core_0_region_pms_constrain_world_1_area_3_y
	);
	this->core_0_region_pms_constrain_2.pms_core_0_region_pms_constrain_world_1_area_2 = this->regGet(
		this->core_0_region_pms_constrain_2.val,
		this->core_0_region_pms_constrain_2.pms_core_0_region_pms_constrain_world_1_area_2_x,
		this->core_0_region_pms_constrain_2.pms_core_0_region_pms_constrain_world_1_area_2_y
	);
	this->core_0_region_pms_constrain_2.pms_core_0_region_pms_constrain_world_1_area_1 = this->regGet(
		this->core_0_region_pms_constrain_2.val,
		this->core_0_region_pms_constrain_2.pms_core_0_region_pms_constrain_world_1_area_1_x,
		this->core_0_region_pms_constrain_2.pms_core_0_region_pms_constrain_world_1_area_1_y
	);
	this->core_0_region_pms_constrain_2.pms_core_0_region_pms_constrain_world_1_area_0 = this->regGet(
		this->core_0_region_pms_constrain_2.val,
		this->core_0_region_pms_constrain_2.pms_core_0_region_pms_constrain_world_1_area_0_x,
		this->core_0_region_pms_constrain_2.pms_core_0_region_pms_constrain_world_1_area_0_y
	);
}
void PmsDebug::init_core_0_region_pms_constrain_n(void){
	uint16_t base = this->core_0_region_pms_constrain_n.base;
	this->core_0_region_pms_constrain_n.val = this->regRead(true, base);
	this->core_0_region_pms_constrain_n.pms_core_0_region_pms_constrain_addr_0 = this->regGet(
		this->core_0_region_pms_constrain_n.val,
		this->core_0_region_pms_constrain_n.pms_core_0_region_pms_constrain_addr_0_x,
		this->core_0_region_pms_constrain_n.pms_core_0_region_pms_constrain_addr_0_y
	);
}
void PmsDebug::init_core_0_pif_pms_monitor_0(void){
	uint16_t base = this->core_0_pif_pms_monitor_0.base;
	this->core_0_pif_pms_monitor_0.val = this->regRead(true, base);
	this->core_0_pif_pms_monitor_0.pms_core_0_pif_pms_monitor_lock = this->regGet(
		this->core_0_pif_pms_monitor_0.val,
		this->core_0_pif_pms_monitor_0.pms_core_0_pif_pms_monitor_lock_pos
	);
}
void PmsDebug::init_core_0_pif_pms_monitor_1(void){
	uint16_t base = this->core_0_pif_pms_monitor_1.base;
	this->core_0_pif_pms_monitor_1.val = this->regRead(true, base);
	this->core_0_pif_pms_monitor_1.pms_core_0_pif_pms_monitor_violate_en = this->regGet(
		this->core_0_pif_pms_monitor_1.val,
		this->core_0_pif_pms_monitor_1.pms_core_0_pif_pms_monitor_violate_en_pos
	);
	this->core_0_pif_pms_monitor_1.pms_core_0_pif_pms_monitor_violate_clr = this->regGet(
		this->core_0_pif_pms_monitor_1.val,
		this->core_0_pif_pms_monitor_1.pms_core_0_pif_pms_monitor_violate_clr_pos
	);
}
void PmsDebug::init_core_0_pif_pms_monitor_4(void){
	uint16_t base = this->core_0_pif_pms_monitor_4.base;
	this->core_0_pif_pms_monitor_4.val = this->regRead(true, base);
	this->core_0_pif_pms_monitor_4.pms_core_0_pif_pms_monitor_nonword_violate_en = this->regGet(
		this->core_0_pif_pms_monitor_4.val,
		this->core_0_pif_pms_monitor_4.pms_core_0_pif_pms_monitor_nonword_violate_en_pos
	);
	this->core_0_pif_pms_monitor_4.pms_core_0_pif_pms_monitor_nonword_violate_clr = this->regGet(
		this->core_0_pif_pms_monitor_4.val,
		this->core_0_pif_pms_monitor_4.pms_core_0_pif_pms_monitor_nonword_violate_clr_pos
	);
}
void PmsDebug::init_core_0_vecbase_override_lock(void){
	uint16_t base = this->core_0_vecbase_override_lock.base;
	this->core_0_vecbase_override_lock.val = this->regRead(true, base);
	this->core_0_vecbase_override_lock.pms_core_0_vecbase_override_lock = this->regGet(
		this->core_0_vecbase_override_lock.val,
		this->core_0_vecbase_override_lock.pms_core_0_vecbase_override_lock_pos
	);
}
void PmsDebug::init_core_0_vecbase_override_0(void){
	uint16_t base = this->core_0_vecbase_override_0.base;
	this->core_0_vecbase_override_0.val = this->regRead(true, base);
	this->core_0_vecbase_override_0.pms_core_0_vecbase_world_mask = this->regGet(
		this->core_0_vecbase_override_0.val,
		this->core_0_vecbase_override_0.pms_core_0_vecbase_world_mask_pos
	);
}
void PmsDebug::init_core_0_vecbase_override_1(void){
	uint16_t base = this->core_0_vecbase_override_1.base;
	this->core_0_vecbase_override_1.val = this->regRead(true, base);
	this->core_0_vecbase_override_1.pms_core_0_vecbase_override_sel = this->regGet(
		this->core_0_vecbase_override_1.val,
		this->core_0_vecbase_override_1.pms_core_0_vecbase_override_sel_x,
		this->core_0_vecbase_override_1.pms_core_0_vecbase_override_sel_y
	);
	this->core_0_vecbase_override_1.pms_core_0_vecbase_override_world0_value = this->regGet(
		this->core_0_vecbase_override_1.val,
		this->core_0_vecbase_override_1.pms_core_0_vecbase_override_world0_value_x,
		this->core_0_vecbase_override_1.pms_core_0_vecbase_override_world0_value_y
	);
}
void PmsDebug::init_core_0_vecbase_override_2(void){
	uint16_t base = this->core_0_vecbase_override_2.base;
	this->core_0_vecbase_override_2.val = this->regRead(true, base);
	this->core_0_vecbase_override_2.pms_core_0_vecbase_override_world1_value = this->regGet(
		this->core_0_vecbase_override_2.val,
		this->core_0_vecbase_override_2.pms_core_0_vecbase_override_world1_value_x,
		this->core_0_vecbase_override_2.pms_core_0_vecbase_override_world1_value_y
	);
}
void PmsDebug::init_edma_boundary_lock(void){
	uint16_t base = this->edma_boundary_lock.base;
	this->edma_boundary_lock.val = this->regRead(true, base);
	this->edma_boundary_lock.pms_edma_boundary_lock = this->regGet(
		this->edma_boundary_lock.val,
		this->edma_boundary_lock.pms_edma_boundary_lock_pos
	);
}
void PmsDebug::init_edma_boundary_0(void){
	uint16_t base = this->edma_boundary_0.base;
	this->edma_boundary_0.val = this->regRead(true, base);
	this->edma_boundary_0.pms_edma_boundary_0 = this->regGet(
		this->edma_boundary_0.val,
		this->edma_boundary_0.pms_edma_boundary_0_x,
		this->edma_boundary_0.pms_edma_boundary_0_y
	);
}
void PmsDebug::init_edma_boundary_1(void){
	uint16_t base = this->edma_boundary_1.base;
	this->edma_boundary_1.val = this->regRead(true, base);
	this->edma_boundary_1.pms_edma_boundary_1 = this->regGet(
		this->edma_boundary_1.val,
		this->edma_boundary_1.pms_edma_boundary_1_x,
		this->edma_boundary_1.pms_edma_boundary_1_y
	);
}
void PmsDebug::init_edma_boundary_2(void){
	uint16_t base = this->edma_boundary_2.base;
	this->edma_boundary_2.val = this->regRead(true, base);
	this->edma_boundary_2.pms_edma_boundary_2 = this->regGet(
		this->edma_boundary_2.val,
		this->edma_boundary_2.pms_edma_boundary_2_x,
		this->edma_boundary_2.pms_edma_boundary_2_y
	);
}
void PmsDebug::init_edma_pms_spi2_lock(void){
	uint16_t base = this->edma_pms_spi2_lock.base;
	this->edma_pms_spi2_lock.val = this->regRead(true, base);
	this->edma_pms_spi2_lock.pms_edma_pms_spi2_lock = this->regGet(
		this->edma_pms_spi2_lock.val,
		this->edma_pms_spi2_lock.pms_edma_pms_spi2_lock_pos
	);
}
void PmsDebug::init_edma_pms_spi2(void){
	uint16_t base = this->edma_pms_spi2.base;
	this->edma_pms_spi2.val = this->regRead(true, base);
	this->edma_pms_spi2.pms_edma_pms_spi2_attr2 = this->regGet(
		this->edma_pms_spi2.val,
		this->edma_pms_spi2.pms_edma_pms_spi2_attr2_x,
		this->edma_pms_spi2.pms_edma_pms_spi2_attr2_y
	);
	this->edma_pms_spi2.pms_edma_pms_spi2_attr1 = this->regGet(
		this->edma_pms_spi2.val,
		this->edma_pms_spi2.pms_edma_pms_spi2_attr1_x,
		this->edma_pms_spi2.pms_edma_pms_spi2_attr1_y
	);
}
void PmsDebug::init_edma_pms_spi3_lock(void){
	uint16_t base = this->edma_pms_spi3_lock.base;
	this->edma_pms_spi3_lock.val = this->regRead(true, base);
	this->edma_pms_spi3_lock.pms_edma_pms_spi3_lock = this->regGet(
		this->edma_pms_spi3_lock.val,
		this->edma_pms_spi3_lock.pms_edma_pms_spi3_lock_pos
	);
}
void PmsDebug::init_edma_pms_spi3(void){
	uint16_t base = this->edma_pms_spi3.base;
	this->edma_pms_spi3.val = this->regRead(true, base);
	this->edma_pms_spi3.pms_edma_pms_spi3_attr2 = this->regGet(
		this->edma_pms_spi3.val,
		this->edma_pms_spi3.pms_edma_pms_spi3_attr2_x,
		this->edma_pms_spi3.pms_edma_pms_spi3_attr2_y
	);
	this->edma_pms_spi3.pms_edma_pms_spi3_attr1 = this->regGet(
		this->edma_pms_spi3.val,
		this->edma_pms_spi3.pms_edma_pms_spi3_attr1_x,
		this->edma_pms_spi3.pms_edma_pms_spi3_attr1_y
	);
}
void PmsDebug::init_edma_pms_uhci0_lock(void){
	uint16_t base = this->edma_pms_uhci0_lock.base;
	this->edma_pms_uhci0_lock.val = this->regRead(true, base);
	this->edma_pms_uhci0_lock.pms_edma_pms_uhci0_lock = this->regGet(
		this->edma_pms_uhci0_lock.val,
		this->edma_pms_uhci0_lock.pms_edma_pms_uhci0_lock_pos
	);
}
void PmsDebug::init_edma_pms_uhci0(void){
	uint16_t base = this->edma_pms_uhci0.base;
	this->edma_pms_uhci0.val = this->regRead(true, base);
	this->edma_pms_uhci0.pms_edma_pms_uhci0_attr2 = this->regGet(
		this->edma_pms_uhci0.val,
		this->edma_pms_uhci0.pms_edma_pms_uhci0_attr2_x,
		this->edma_pms_uhci0.pms_edma_pms_uhci0_attr2_y
	);
	this->edma_pms_uhci0.pms_edma_pms_uhci0_attr1 = this->regGet(
		this->edma_pms_uhci0.val,
		this->edma_pms_uhci0.pms_edma_pms_uhci0_attr1_x,
		this->edma_pms_uhci0.pms_edma_pms_uhci0_attr1_y
	);
}
void PmsDebug::init_edma_pms_i2s0_lock(void){
	uint16_t base = this->edma_pms_i2s0_lock.base;
	this->edma_pms_i2s0_lock.val = this->regRead(true, base);
	this->edma_pms_i2s0_lock.pms_edma_pms_i2s0_lock = this->regGet(
		this->edma_pms_i2s0_lock.val,
		this->edma_pms_i2s0_lock.pms_edma_pms_i2s0_lock_pos
	);
}
void PmsDebug::init_edma_pms_i2s0(void){
	uint16_t base = this->edma_pms_i2s0.base;
	this->edma_pms_i2s0.val = this->regRead(true, base);
	this->edma_pms_i2s0.pms_edma_pms_i2s0_attr2 = this->regGet(
		this->edma_pms_i2s0.val,
		this->edma_pms_i2s0.pms_edma_pms_i2s0_attr2_x,
		this->edma_pms_i2s0.pms_edma_pms_i2s0_attr2_y
	);
	this->edma_pms_i2s0.pms_edma_pms_i2s0_attr1 = this->regGet(
		this->edma_pms_i2s0.val,
		this->edma_pms_i2s0.pms_edma_pms_i2s0_attr1_x,
		this->edma_pms_i2s0.pms_edma_pms_i2s0_attr1_y
	);
}
void PmsDebug::init_edma_pms_i2s1_lock(void){
	uint16_t base = this->edma_pms_i2s1_lock.base;
	this->edma_pms_i2s1_lock.val = this->regRead(true, base);
	this->edma_pms_i2s1_lock.pms_edma_pms_i2s1_lock = this->regGet(
		this->edma_pms_i2s1_lock.val,
		this->edma_pms_i2s1_lock.pms_edma_pms_i2s1_lock_pos
	);
}
void PmsDebug::init_edma_pms_i2s1(void){
	uint16_t base = this->edma_pms_i2s1.base;
	this->edma_pms_i2s1.val = this->regRead(true, base);
	this->edma_pms_i2s1.pms_edma_pms_i2s1_attr2 = this->regGet(
		this->edma_pms_i2s1.val,
		this->edma_pms_i2s1.pms_edma_pms_i2s1_attr2_x,
		this->edma_pms_i2s1.pms_edma_pms_i2s1_attr2_y
	);
	this->edma_pms_i2s1.pms_edma_pms_i2s1_attr1 = this->regGet(
		this->edma_pms_i2s1.val,
		this->edma_pms_i2s1.pms_edma_pms_i2s1_attr1_x,
		this->edma_pms_i2s1.pms_edma_pms_i2s1_attr1_y
	);
}
void PmsDebug::init_edma_pms_lcd_cam_lock(void){
	uint16_t base = this->edma_pms_lcd_cam_lock.base;
	this->edma_pms_lcd_cam_lock.val = this->regRead(true, base);
	this->edma_pms_lcd_cam_lock.pms_edma_pms_lcd_cam_lock = this->regGet(
		this->edma_pms_lcd_cam_lock.val,
		this->edma_pms_lcd_cam_lock.pms_edma_pms_lcd_cam_lock_pos
	);
}
void PmsDebug::init_edma_pms_lcd_cam(void){
	uint16_t base = this->edma_pms_lcd_cam.base;
	this->edma_pms_lcd_cam.val = this->regRead(true, base);
	this->edma_pms_lcd_cam.pms_edma_pms_lcd_cam_attr2 = this->regGet(
		this->edma_pms_lcd_cam.val,
		this->edma_pms_lcd_cam.pms_edma_pms_lcd_cam_attr2_x,
		this->edma_pms_lcd_cam.pms_edma_pms_lcd_cam_attr2_y
	);
	this->edma_pms_lcd_cam.pms_edma_pms_lcd_cam_attr1 = this->regGet(
		this->edma_pms_lcd_cam.val,
		this->edma_pms_lcd_cam.pms_edma_pms_lcd_cam_attr1_x,
		this->edma_pms_lcd_cam.pms_edma_pms_lcd_cam_attr1_y
	);
}
void PmsDebug::init_edma_pms_aes_lock(void){
	uint16_t base = this->edma_pms_aes_lock.base;
	this->edma_pms_aes_lock.val = this->regRead(true, base);
	this->edma_pms_aes_lock.pms_edma_pms_aes_lock = this->regGet(
		this->edma_pms_aes_lock.val,
		this->edma_pms_aes_lock.pms_edma_pms_aes_lock_pos
	);
}
void PmsDebug::init_edma_pms_aes(void){
	uint16_t base = this->edma_pms_aes.base;
	this->edma_pms_aes.val = this->regRead(true, base);
	this->edma_pms_aes.pms_edma_pms_aes_attr2 = this->regGet(
		this->edma_pms_aes.val,
		this->edma_pms_aes.pms_edma_pms_aes_attr2_x,
		this->edma_pms_aes.pms_edma_pms_aes_attr2_y
	);
	this->edma_pms_aes.pms_edma_pms_aes_attr1 = this->regGet(
		this->edma_pms_aes.val,
		this->edma_pms_aes.pms_edma_pms_aes_attr1_x,
		this->edma_pms_aes.pms_edma_pms_aes_attr1_y
	);
}
void PmsDebug::init_edma_pms_sha_lock(void){
	uint16_t base = this->edma_pms_sha_lock.base;
	this->edma_pms_sha_lock.val = this->regRead(true, base);
	this->edma_pms_sha_lock.pms_edma_pms_sha_lock = this->regGet(
		this->edma_pms_sha_lock.val,
		this->edma_pms_sha_lock.pms_edma_pms_sha_lock_pos
	);
}
void PmsDebug::init_edma_pms_sha(void){
	uint16_t base = this->edma_pms_sha.base;
	this->edma_pms_sha.val = this->regRead(true, base);
	this->edma_pms_sha.pms_edma_pms_sha_attr2 = this->regGet(
		this->edma_pms_sha.val,
		this->edma_pms_sha.pms_edma_pms_sha_attr2_x,
		this->edma_pms_sha.pms_edma_pms_sha_attr2_y
	);
	this->edma_pms_sha.pms_edma_pms_sha_attr1 = this->regGet(
		this->edma_pms_sha.val,
		this->edma_pms_sha.pms_edma_pms_sha_attr1_x,
		this->edma_pms_sha.pms_edma_pms_sha_attr1_y
	);
}
void PmsDebug::init_edma_pms_adc_dac_lock(void){
	uint16_t base = this->edma_pms_adc_dac_lock.base;
	this->edma_pms_adc_dac_lock.val = this->regRead(true, base);
	this->edma_pms_adc_dac_lock.pms_edma_pms_adc_dac_lock = this->regGet(
		this->edma_pms_adc_dac_lock.val,
		this->edma_pms_adc_dac_lock.pms_edma_pms_adc_dac_lock_pos
	);
}
void PmsDebug::init_edma_pms_adc_dac(void){
	uint16_t base = this->edma_pms_adc_dac.base;
	this->edma_pms_adc_dac.val = this->regRead(true, base);
	this->edma_pms_adc_dac.pms_edma_pms_adc_dac_attr2 = this->regGet(
		this->edma_pms_adc_dac.val,
		this->edma_pms_adc_dac.pms_edma_pms_adc_dac_attr2_x,
		this->edma_pms_adc_dac.pms_edma_pms_adc_dac_attr2_y
	);
	this->edma_pms_adc_dac.pms_edma_pms_adc_dac_attr1 = this->regGet(
		this->edma_pms_adc_dac.val,
		this->edma_pms_adc_dac.pms_edma_pms_adc_dac_attr1_x,
		this->edma_pms_adc_dac.pms_edma_pms_adc_dac_attr1_y
	);
}
void PmsDebug::init_edma_pms_rmt_lock(void){
	uint16_t base = this->edma_pms_rmt_lock.base;
	this->edma_pms_rmt_lock.val = this->regRead(true, base);
	this->edma_pms_rmt_lock.pms_edma_pms_rmt_lock = this->regGet(
		this->edma_pms_rmt_lock.val,
		this->edma_pms_rmt_lock.pms_edma_pms_rmt_lock_pos
	);
}
void PmsDebug::init_edma_pms_rmt(void){
	uint16_t base = this->edma_pms_rmt.base;
	this->edma_pms_rmt.val = this->regRead(true, base);
	this->edma_pms_rmt.pms_edma_pms_rmt_attr2 = this->regGet(
		this->edma_pms_rmt.val,
		this->edma_pms_rmt.pms_edma_pms_rmt_attr2_x,
		this->edma_pms_rmt.pms_edma_pms_rmt_attr2_y
	);
	this->edma_pms_rmt.pms_edma_pms_rmt_attr1 = this->regGet(
		this->edma_pms_rmt.val,
		this->edma_pms_rmt.pms_edma_pms_rmt_attr1_x,
		this->edma_pms_rmt.pms_edma_pms_rmt_attr1_y
	);
}
void PmsDebug::init_clock_gate(void){
	uint16_t base = this->clock_gate.base;
	this->clock_gate.val = this->regRead(true, base);
	this->clock_gate.pms_reg_clk_en = this->regGet(
		this->clock_gate.val,
		this->clock_gate.pms_reg_clk_en_pos
	);
}
void PmsDebug::init_core_0_iram0_pms_monitor_2(void){
	uint16_t base = this->core_0_iram0_pms_monitor_2.base;
	this->core_0_iram0_pms_monitor_2.val = this->regRead(true, base);
	this->core_0_iram0_pms_monitor_2.pms_core_0_iram0_pms_monitor_violate_status_addr = this->regGet(
		this->core_0_iram0_pms_monitor_2.val,
		this->core_0_iram0_pms_monitor_2.pms_core_0_iram0_pms_monitor_violate_status_addr_x,
		this->core_0_iram0_pms_monitor_2.pms_core_0_iram0_pms_monitor_violate_status_addr_y
	);
	this->core_0_iram0_pms_monitor_2.pms_core_0_iram0_pms_monitor_violate_status_world = this->regGet(
		this->core_0_iram0_pms_monitor_2.val,
		this->core_0_iram0_pms_monitor_2.pms_core_0_iram0_pms_monitor_violate_status_world_x,
		this->core_0_iram0_pms_monitor_2.pms_core_0_iram0_pms_monitor_violate_status_world_y
	);
	this->core_0_iram0_pms_monitor_2.pms_core_0_iram0_pms_monitor_violate_status_loadstore = this->regGet(
		this->core_0_iram0_pms_monitor_2.val,
		this->core_0_iram0_pms_monitor_2.pms_core_0_iram0_pms_monitor_violate_status_loadstore_pos
	);
	this->core_0_iram0_pms_monitor_2.pms_core_0_iram0_pms_monitor_violate_status_wr = this->regGet(
		this->core_0_iram0_pms_monitor_2.val,
		this->core_0_iram0_pms_monitor_2.pms_core_0_iram0_pms_monitor_violate_status_wr_pos
	);
	this->core_0_iram0_pms_monitor_2.pms_core_0_iram0_pms_monitor_violate_intr = this->regGet(
		this->core_0_iram0_pms_monitor_2.val,
		this->core_0_iram0_pms_monitor_2.pms_core_0_iram0_pms_monitor_violate_intr_pos
	);
}
void PmsDebug::init_core_0_dram0_pms_monitor_2(void){
	uint16_t base = this->core_0_dram0_pms_monitor_2.base;
	this->core_0_dram0_pms_monitor_2.val = this->regRead(true, base);
	this->core_0_dram0_pms_monitor_2.pms_core_0_dram0_pms_monitor_violate_status_addr = this->regGet(
		this->core_0_dram0_pms_monitor_2.val,
		this->core_0_dram0_pms_monitor_2.pms_core_0_dram0_pms_monitor_violate_status_addr_x,
		this->core_0_dram0_pms_monitor_2.pms_core_0_dram0_pms_monitor_violate_status_addr_y
	);
	this->core_0_dram0_pms_monitor_2.pms_core_0_dram0_pms_monitor_violate_status_world = this->regGet(
		this->core_0_dram0_pms_monitor_2.val,
		this->core_0_dram0_pms_monitor_2.pms_core_0_dram0_pms_monitor_violate_status_world_x,
		this->core_0_dram0_pms_monitor_2.pms_core_0_dram0_pms_monitor_violate_status_world_y
	);
	this->core_0_dram0_pms_monitor_2.pms_core_0_dram0_pms_monitor_violate_status_lock = this->regGet(
		this->core_0_dram0_pms_monitor_2.val,
		this->core_0_dram0_pms_monitor_2.pms_core_0_dram0_pms_monitor_violate_status_lock_pos
	);
	this->core_0_dram0_pms_monitor_2.pms_core_0_dram0_pms_monitor_violate_intr = this->regGet(
		this->core_0_dram0_pms_monitor_2.val,
		this->core_0_dram0_pms_monitor_2.pms_core_0_dram0_pms_monitor_violate_intr_pos
	);
}
void PmsDebug::init_core_0_dram0_pms_monitor_3(void){
	uint16_t base = this->core_0_dram0_pms_monitor_3.base;
	this->core_0_dram0_pms_monitor_3.val = this->regRead(true, base);
	this->core_0_dram0_pms_monitor_3.pms_core_0_dram0_pms_monitor_violate_status_byteen = this->regGet(
		this->core_0_dram0_pms_monitor_3.val,
		this->core_0_dram0_pms_monitor_3.pms_core_0_dram0_pms_monitor_violate_status_byteen_x,
		this->core_0_dram0_pms_monitor_3.pms_core_0_dram0_pms_monitor_violate_status_byteen_y
	);
	this->core_0_dram0_pms_monitor_3.pms_core_0_dram0_pms_monitor_violate_status_wr = this->regGet(
		this->core_0_dram0_pms_monitor_3.val,
		this->core_0_dram0_pms_monitor_3.pms_core_0_dram0_pms_monitor_violate_status_wr_pos
	);
}
void PmsDebug::init_core_0_pif_pms_monitor_2(void){
	uint16_t base = this->core_0_pif_pms_monitor_2.base;
	this->core_0_pif_pms_monitor_2.val = this->regRead(true, base);
	this->core_0_pif_pms_monitor_2.pms_core_0_pif_pms_monitor_violate_status_hworld = this->regGet(
		this->core_0_pif_pms_monitor_2.val,
		this->core_0_pif_pms_monitor_2.pms_core_0_pif_pms_monitor_violate_status_hworld_x,
		this->core_0_pif_pms_monitor_2.pms_core_0_pif_pms_monitor_violate_status_hworld_y
	);
	this->core_0_pif_pms_monitor_2.pms_core_0_pif_pms_monitor_violate_status_hwrite = this->regGet(
		this->core_0_pif_pms_monitor_2.val,
		this->core_0_pif_pms_monitor_2.pms_core_0_pif_pms_monitor_violate_status_hwrite_pos
	);
	this->core_0_pif_pms_monitor_2.pms_core_0_pif_pms_monitor_violate_status_hsize = this->regGet(
		this->core_0_pif_pms_monitor_2.val,
		this->core_0_pif_pms_monitor_2.pms_core_0_pif_pms_monitor_violate_status_hsize_x,
		this->core_0_pif_pms_monitor_2.pms_core_0_pif_pms_monitor_violate_status_hsize_y
	);
	this->core_0_pif_pms_monitor_2.pms_core_0_pif_pms_monitor_violate_status_hport_0 = this->regGet(
		this->core_0_pif_pms_monitor_2.val,
		this->core_0_pif_pms_monitor_2.pms_core_0_pif_pms_monitor_violate_status_hport_0_pos
	);
	this->core_0_pif_pms_monitor_2.pms_core_0_pif_pms_monitor_violate_intr = this->regGet(
		this->core_0_pif_pms_monitor_2.val,
		this->core_0_pif_pms_monitor_2.pms_core_0_pif_pms_monitor_violate_intr_pos
	);
}
void PmsDebug::init_core_0_pif_pms_monitor_3(void){
	uint16_t base = this->core_0_pif_pms_monitor_3.base;
	this->core_0_pif_pms_monitor_3.val = this->regRead(true, base);
	this->core_0_pif_pms_monitor_3.pms_core_0_pif_pms_monitor_violate_status_haddr = this->regGet(
		this->core_0_pif_pms_monitor_3.val,
		this->core_0_pif_pms_monitor_3.pms_core_0_pif_pms_monitor_violate_status_haddr_x,
		this->core_0_pif_pms_monitor_3.pms_core_0_pif_pms_monitor_violate_status_haddr_y
	);
}
void PmsDebug::init_core_0_pif_pms_monitor_5(void){
	uint16_t base = this->core_0_pif_pms_monitor_5.base;
	this->core_0_pif_pms_monitor_5.val = this->regRead(true, base);
	this->core_0_pif_pms_monitor_5.pms_core_0_pif_pms_monitor_nonword_violate_status_hworld = this->regGet(
		this->core_0_pif_pms_monitor_5.val,
		this->core_0_pif_pms_monitor_5.pms_core_0_pif_pms_monitor_nonword_violate_status_hworld_x,
		this->core_0_pif_pms_monitor_5.pms_core_0_pif_pms_monitor_nonword_violate_status_hworld_y
	);
	this->core_0_pif_pms_monitor_5.pms_core_0_pif_pms_monitor_nonword_violate_status_hsize = this->regGet(
		this->core_0_pif_pms_monitor_5.val,
		this->core_0_pif_pms_monitor_5.pms_core_0_pif_pms_monitor_nonword_violate_status_hsize_x,
		this->core_0_pif_pms_monitor_5.pms_core_0_pif_pms_monitor_nonword_violate_status_hsize_y
	);
	this->core_0_pif_pms_monitor_5.pms_core_0_pif_pms_monitor_nonword_violate_intr = this->regGet(
		this->core_0_pif_pms_monitor_5.val,
		this->core_0_pif_pms_monitor_5.pms_core_0_pif_pms_monitor_nonword_violate_intr_pos
	);
}
void PmsDebug::init_core_0_pif_pms_monitor_6(void){
	uint16_t base = this->core_0_pif_pms_monitor_6.base;
	this->core_0_pif_pms_monitor_6.val = this->regRead(true, base);
	this->core_0_pif_pms_monitor_6.pms_core_0_pif_pms_monitor_nonword_violate_status_haddr = this->regGet(
		this->core_0_pif_pms_monitor_6.val,
		this->core_0_pif_pms_monitor_6.pms_core_0_pif_pms_monitor_nonword_violate_status_haddr_x,
		this->core_0_pif_pms_monitor_6.pms_core_0_pif_pms_monitor_nonword_violate_status_haddr_y
	);
}
void PmsDebug::init_date(void){
	uint16_t base = this->date.base;
	this->date.val = this->regRead(true, base);
	this->date.pms_date = this->regGet(
		this->date.val,
		this->date.pms_date_x,
		this->date.pms_date_y
	);
}
void PmsDebug::init_ctrl_ext_mem_pms_lock(void){
	uint16_t base = this->ctrl_ext_mem_pms_lock.base;
	this->ctrl_ext_mem_pms_lock.val = this->regRead(false, base);
	this->ctrl_ext_mem_pms_lock.apb_ctrl_ext_mem_pms_lock = this->regGet(
		this->ctrl_ext_mem_pms_lock.val,
		this->ctrl_ext_mem_pms_lock.apb_ctrl_ext_mem_pms_lock_pos
	);
}
void PmsDebug::init_ctrl_flash_acen_attr(void){
	uint16_t base = this->ctrl_flash_acen_attr.base;
	this->ctrl_flash_acen_attr.val = this->regRead(false, base);
	this->ctrl_flash_acen_attr.apb_ctrl_flash_acen_attr = this->regGet(
		this->ctrl_flash_acen_attr.val,
		this->ctrl_flash_acen_attr.apb_ctrl_flash_acen_attr_x,
		this->ctrl_flash_acen_attr.apb_ctrl_flash_acen_attr_y
	);
}
void PmsDebug::init_ctrl_flash_acen_addr(void){
	uint16_t base = this->ctrl_flash_acen_addr.base;
	this->ctrl_flash_acen_addr.val = this->regRead(false, base);
	this->ctrl_flash_acen_addr.apb_ctrl_flash_acen_addr_s = this->regGet(
		this->ctrl_flash_acen_addr.val,
		this->ctrl_flash_acen_addr.apb_ctrl_flash_acen_addr_s_x,
		this->ctrl_flash_acen_addr.apb_ctrl_flash_acen_addr_s_y
	);
}
void PmsDebug::init_ctrl_flash_acen_size(void){
	uint16_t base = this->ctrl_flash_acen_size.base;
	this->ctrl_flash_acen_size.val = this->regRead(false, base);
	this->ctrl_flash_acen_size.apb_ctrl_flash_acen_size = this->regGet(
		this->ctrl_flash_acen_size.val,
		this->ctrl_flash_acen_size.apb_ctrl_flash_acen_size_x,
		this->ctrl_flash_acen_size.apb_ctrl_flash_acen_size_y
	);
}
void PmsDebug::init_ctrl_sram_acen_attr(void){
	uint16_t base = this->ctrl_sram_acen_attr.base;
	this->ctrl_sram_acen_attr.val = this->regRead(false, base);
	this->ctrl_sram_acen_attr.apb_ctrl_sram_acen_attr = this->regGet(
		this->ctrl_sram_acen_attr.val,
		this->ctrl_sram_acen_attr.apb_ctrl_sram_acen_attr_x,
		this->ctrl_sram_acen_attr.apb_ctrl_sram_acen_attr_y
	);
}
void PmsDebug::init_ctrl_sram_acen_addr(void){
	uint16_t base = this->ctrl_sram_acen_addr.base;
	this->ctrl_sram_acen_addr.val = this->regRead(false, base);
	this->ctrl_sram_acen_addr.apb_ctrl_sram_acen_addr_s = this->regGet(
		this->ctrl_sram_acen_addr.val,
		this->ctrl_sram_acen_addr.apb_ctrl_sram_acen_addr_s_x,
		this->ctrl_sram_acen_addr.apb_ctrl_sram_acen_addr_s_y
	);
}
void PmsDebug::init_ctrl_sram_acen_size(void){
	uint16_t base = this->ctrl_sram_acen_size.base;
	this->ctrl_sram_acen_size.val = this->regRead(false, base);
	this->ctrl_sram_acen_size.apb_ctrl_sram_acen_size = this->regGet(
		this->ctrl_sram_acen_size.val,
		this->ctrl_sram_acen_size.apb_ctrl_sram_acen_size_x,
		this->ctrl_sram_acen_size.apb_ctrl_sram_acen_size_y
	);
}
void PmsDebug::init_ctrl_spi_mem_pms_ctrl(void){
	uint16_t base = this->ctrl_spi_mem_pms_ctrl.base;
	this->ctrl_spi_mem_pms_ctrl.val = this->regRead(false, base);
	this->ctrl_spi_mem_pms_ctrl.apb_ctrl_spi_mem_reject_cde = this->regGet(
		this->ctrl_spi_mem_pms_ctrl.val,
		this->ctrl_spi_mem_pms_ctrl.apb_ctrl_spi_mem_reject_cde_x,
		this->ctrl_spi_mem_pms_ctrl.apb_ctrl_spi_mem_reject_cde_y
	);
	this->ctrl_spi_mem_pms_ctrl.apb_ctrl_spi_mem_reject_clr = this->regGet(
		this->ctrl_spi_mem_pms_ctrl.val,
		this->ctrl_spi_mem_pms_ctrl.apb_ctrl_spi_mem_reject_clr_pos
	);
	this->ctrl_spi_mem_pms_ctrl.apb_ctrl_spi_mem_reject_int = this->regGet(
		this->ctrl_spi_mem_pms_ctrl.val,
		this->ctrl_spi_mem_pms_ctrl.apb_ctrl_spi_mem_reject_int_pos
	);
}
void PmsDebug::init_ctrl_spi_mem_reject_addr(void){
	uint16_t base = this->ctrl_spi_mem_reject_addr.base;
	this->ctrl_spi_mem_reject_addr.val = this->regRead(false, base);
	this->ctrl_spi_mem_reject_addr.apb_ctrl_spi_mem_reject_addr = this->regGet(
		this->ctrl_spi_mem_reject_addr.val,
		this->ctrl_spi_mem_reject_addr.apb_ctrl_spi_mem_reject_addr_x,
		this->ctrl_spi_mem_reject_addr.apb_ctrl_spi_mem_reject_addr_y
	);
}

/*
 * Patch Functions
 * */

void PmsDebug::patch_apb_peripheral_access_0(bool writeMode){
	uint32_t r = this->apb_peripheral_access_0.val;
	r = this->regSet(r, 
		this->apb_peripheral_access_0.val,
		this->apb_peripheral_access_0.pms_apb_peripheral_access_lock_pos
	);

	if(writeMode){
		this->regWrite(true, this->apb_peripheral_access_0.base, r);
		this->init_apb_peripheral_access_0();
	}else{
		this->apb_peripheral_access_0.val = r;
	}
}
void PmsDebug::patch_apb_peripheral_access_1(bool writeMode){
	uint32_t r = this->apb_peripheral_access_1.val;
	r = this->regSet(r, 
		this->apb_peripheral_access_1.val,
		this->apb_peripheral_access_1.pms_apb_peripheral_access_split_burst_pos
	);

	if(writeMode){
		this->regWrite(true, this->apb_peripheral_access_1.base, r);
		this->init_apb_peripheral_access_1();
	}else{
		this->apb_peripheral_access_1.val = r;
	}
}
void PmsDebug::patch_internal_sram_usage_0(bool writeMode){
	uint32_t r = this->internal_sram_usage_0.val;
	r = this->regSet(r, 
		this->internal_sram_usage_0.val,
		this->internal_sram_usage_0.pms_internal_sram_usage_lock_pos
	);

	if(writeMode){
		this->regWrite(true, this->internal_sram_usage_0.base, r);
		this->init_internal_sram_usage_0();
	}else{
		this->internal_sram_usage_0.val = r;
	}
}
void PmsDebug::patch_internal_sram_usage_1(bool writeMode){
	uint32_t r = this->internal_sram_usage_1.val;
	r = this->regSet(r, 
		this->internal_sram_usage_1.val,
		this->internal_sram_usage_1.pms_internal_sram_cpu_usage_x,
		this->internal_sram_usage_1.pms_internal_sram_cpu_usage_y
	);
	r = this->regSet(r, 
		this->internal_sram_usage_1.val,
		this->internal_sram_usage_1.pms_internal_sram_dcache_usage_x,
		this->internal_sram_usage_1.pms_internal_sram_dcache_usage_y
	);
	r = this->regSet(r, 
		this->internal_sram_usage_1.val,
		this->internal_sram_usage_1.pms_internal_sram_icache_usage_x,
		this->internal_sram_usage_1.pms_internal_sram_icache_usage_y
	);

	if(writeMode){
		this->regWrite(true, this->internal_sram_usage_1.base, r);
		this->init_internal_sram_usage_1();
	}else{
		this->internal_sram_usage_1.val = r;
	}
}
void PmsDebug::patch_internal_sram_usage_2(bool writeMode){
	uint32_t r = this->internal_sram_usage_2.val;
	r = this->regSet(r, 
		this->internal_sram_usage_2.val,
		this->internal_sram_usage_2.pms_internal_sram_core1_trace_alloc_x,
		this->internal_sram_usage_2.pms_internal_sram_core1_trace_alloc_y
	);
	r = this->regSet(r, 
		this->internal_sram_usage_2.val,
		this->internal_sram_usage_2.pms_internal_sram_core0_trace_alloc_x,
		this->internal_sram_usage_2.pms_internal_sram_core0_trace_alloc_y
	);
	r = this->regSet(r, 
		this->internal_sram_usage_2.val,
		this->internal_sram_usage_2.pms_internal_sram_core1_trace_usage_x,
		this->internal_sram_usage_2.pms_internal_sram_core1_trace_usage_y
	);
	r = this->regSet(r, 
		this->internal_sram_usage_2.val,
		this->internal_sram_usage_2.pms_internal_sram_core0_trace_usage_x,
		this->internal_sram_usage_2.pms_internal_sram_core0_trace_usage_y
	);

	if(writeMode){
		this->regWrite(true, this->internal_sram_usage_2.base, r);
		this->init_internal_sram_usage_2();
	}else{
		this->internal_sram_usage_2.val = r;
	}
}
void PmsDebug::patch_dma_apbperi_spi2_pms_constrain_0(bool writeMode){
	uint32_t r = this->dma_apbperi_spi2_pms_constrain_0.val;
	r = this->regSet(r, 
		this->dma_apbperi_spi2_pms_constrain_0.val,
		this->dma_apbperi_spi2_pms_constrain_0.pms_dma_apbperi_spi2_pms_constrain_lock_pos
	);

	if(writeMode){
		this->regWrite(true, this->dma_apbperi_spi2_pms_constrain_0.base, r);
		this->init_dma_apbperi_spi2_pms_constrain_0();
	}else{
		this->dma_apbperi_spi2_pms_constrain_0.val = r;
	}
}
void PmsDebug::patch_dma_apbperi_spi2_pms_constrain_1(bool writeMode){
	uint32_t r = this->dma_apbperi_spi2_pms_constrain_1.val;
	r = this->regSet(r, 
		this->dma_apbperi_spi2_pms_constrain_1.val,
		this->dma_apbperi_spi2_pms_constrain_1.pms_dma_apbperi_spi2_pms_constrain_sram_cachedataarray_pms_1_x,
		this->dma_apbperi_spi2_pms_constrain_1.pms_dma_apbperi_spi2_pms_constrain_sram_cachedataarray_pms_1_y
	);
	r = this->regSet(r, 
		this->dma_apbperi_spi2_pms_constrain_1.val,
		this->dma_apbperi_spi2_pms_constrain_1.pms_dma_apbperi_spi2_pms_constrain_sram_cachedataarray_pms_0_x,
		this->dma_apbperi_spi2_pms_constrain_1.pms_dma_apbperi_spi2_pms_constrain_sram_cachedataarray_pms_0_y
	);
	r = this->regSet(r, 
		this->dma_apbperi_spi2_pms_constrain_1.val,
		this->dma_apbperi_spi2_pms_constrain_1.pms_dma_apbperi_spi2_pms_constrain_sram_pms_3_x,
		this->dma_apbperi_spi2_pms_constrain_1.pms_dma_apbperi_spi2_pms_constrain_sram_pms_3_y
	);
	r = this->regSet(r, 
		this->dma_apbperi_spi2_pms_constrain_1.val,
		this->dma_apbperi_spi2_pms_constrain_1.pms_dma_apbperi_spi2_pms_constrain_sram_pms_2_x,
		this->dma_apbperi_spi2_pms_constrain_1.pms_dma_apbperi_spi2_pms_constrain_sram_pms_2_y
	);
	r = this->regSet(r, 
		this->dma_apbperi_spi2_pms_constrain_1.val,
		this->dma_apbperi_spi2_pms_constrain_1.pms_dma_apbperi_spi2_pms_constrain_sram_pms_1_x,
		this->dma_apbperi_spi2_pms_constrain_1.pms_dma_apbperi_spi2_pms_constrain_sram_pms_1_y
	);
	r = this->regSet(r, 
		this->dma_apbperi_spi2_pms_constrain_1.val,
		this->dma_apbperi_spi2_pms_constrain_1.pms_dma_apbperi_spi2_pms_constrain_sram_pms_0_x,
		this->dma_apbperi_spi2_pms_constrain_1.pms_dma_apbperi_spi2_pms_constrain_sram_pms_0_y
	);

	if(writeMode){
		this->regWrite(true, this->dma_apbperi_spi2_pms_constrain_1.base, r);
		this->init_dma_apbperi_spi2_pms_constrain_1();
	}else{
		this->dma_apbperi_spi2_pms_constrain_1.val = r;
	}
}
void PmsDebug::patch_dma_apbperi_spi3_pms_constrain_0(bool writeMode){
	uint32_t r = this->dma_apbperi_spi3_pms_constrain_0.val;
	r = this->regSet(r, 
		this->dma_apbperi_spi3_pms_constrain_0.val,
		this->dma_apbperi_spi3_pms_constrain_0.pms_dma_apbperi_spi3_pms_constrain_lock_pos
	);

	if(writeMode){
		this->regWrite(true, this->dma_apbperi_spi3_pms_constrain_0.base, r);
		this->init_dma_apbperi_spi3_pms_constrain_0();
	}else{
		this->dma_apbperi_spi3_pms_constrain_0.val = r;
	}
}
void PmsDebug::patch_dma_apbperi_spi3_pms_constrain_1(bool writeMode){
	uint32_t r = this->dma_apbperi_spi3_pms_constrain_1.val;
	r = this->regSet(r, 
		this->dma_apbperi_spi3_pms_constrain_1.val,
		this->dma_apbperi_spi3_pms_constrain_1.pms_dma_apbperi_spi3_pms_constrain_sram_cachedataarray_pms_1_x,
		this->dma_apbperi_spi3_pms_constrain_1.pms_dma_apbperi_spi3_pms_constrain_sram_cachedataarray_pms_1_y
	);
	r = this->regSet(r, 
		this->dma_apbperi_spi3_pms_constrain_1.val,
		this->dma_apbperi_spi3_pms_constrain_1.pms_dma_apbperi_spi3_pms_constrain_sram_cachedataarray_pms_0_x,
		this->dma_apbperi_spi3_pms_constrain_1.pms_dma_apbperi_spi3_pms_constrain_sram_cachedataarray_pms_0_y
	);
	r = this->regSet(r, 
		this->dma_apbperi_spi3_pms_constrain_1.val,
		this->dma_apbperi_spi3_pms_constrain_1.pms_dma_apbperi_spi3_pms_constrain_sram_pms_3_x,
		this->dma_apbperi_spi3_pms_constrain_1.pms_dma_apbperi_spi3_pms_constrain_sram_pms_3_y
	);
	r = this->regSet(r, 
		this->dma_apbperi_spi3_pms_constrain_1.val,
		this->dma_apbperi_spi3_pms_constrain_1.pms_dma_apbperi_spi3_pms_constrain_sram_pms_2_x,
		this->dma_apbperi_spi3_pms_constrain_1.pms_dma_apbperi_spi3_pms_constrain_sram_pms_2_y
	);
	r = this->regSet(r, 
		this->dma_apbperi_spi3_pms_constrain_1.val,
		this->dma_apbperi_spi3_pms_constrain_1.pms_dma_apbperi_spi3_pms_constrain_sram_pms_1_x,
		this->dma_apbperi_spi3_pms_constrain_1.pms_dma_apbperi_spi3_pms_constrain_sram_pms_1_y
	);
	r = this->regSet(r, 
		this->dma_apbperi_spi3_pms_constrain_1.val,
		this->dma_apbperi_spi3_pms_constrain_1.pms_dma_apbperi_spi3_pms_constrain_sram_pms_0_x,
		this->dma_apbperi_spi3_pms_constrain_1.pms_dma_apbperi_spi3_pms_constrain_sram_pms_0_y
	);

	if(writeMode){
		this->regWrite(true, this->dma_apbperi_spi3_pms_constrain_1.base, r);
		this->init_dma_apbperi_spi3_pms_constrain_1();
	}else{
		this->dma_apbperi_spi3_pms_constrain_1.val = r;
	}
}
void PmsDebug::patch_dma_apbperi_uhci0_pms_constrain_0(bool writeMode){
	uint32_t r = this->dma_apbperi_uhci0_pms_constrain_0.val;
	r = this->regSet(r, 
		this->dma_apbperi_uhci0_pms_constrain_0.val,
		this->dma_apbperi_uhci0_pms_constrain_0.pms_dma_apbperi_uhci0_pms_constrain_lock_pos
	);

	if(writeMode){
		this->regWrite(true, this->dma_apbperi_uhci0_pms_constrain_0.base, r);
		this->init_dma_apbperi_uhci0_pms_constrain_0();
	}else{
		this->dma_apbperi_uhci0_pms_constrain_0.val = r;
	}
}
void PmsDebug::patch_dma_apbperi_uhci0_pms_constrain_1(bool writeMode){
	uint32_t r = this->dma_apbperi_uhci0_pms_constrain_1.val;
	r = this->regSet(r, 
		this->dma_apbperi_uhci0_pms_constrain_1.val,
		this->dma_apbperi_uhci0_pms_constrain_1.pms_dma_apbperi_uhci0_pms_constrain_sram_cachedataarray_pms_1_x,
		this->dma_apbperi_uhci0_pms_constrain_1.pms_dma_apbperi_uhci0_pms_constrain_sram_cachedataarray_pms_1_y
	);
	r = this->regSet(r, 
		this->dma_apbperi_uhci0_pms_constrain_1.val,
		this->dma_apbperi_uhci0_pms_constrain_1.pms_dma_apbperi_uhci0_pms_constrain_sram_cachedataarray_pms_0_x,
		this->dma_apbperi_uhci0_pms_constrain_1.pms_dma_apbperi_uhci0_pms_constrain_sram_cachedataarray_pms_0_y
	);
	r = this->regSet(r, 
		this->dma_apbperi_uhci0_pms_constrain_1.val,
		this->dma_apbperi_uhci0_pms_constrain_1.pms_dma_apbperi_uhci0_pms_constrain_sram_pms_3_x,
		this->dma_apbperi_uhci0_pms_constrain_1.pms_dma_apbperi_uhci0_pms_constrain_sram_pms_3_y
	);
	r = this->regSet(r, 
		this->dma_apbperi_uhci0_pms_constrain_1.val,
		this->dma_apbperi_uhci0_pms_constrain_1.pms_dma_apbperi_uhci0_pms_constrain_sram_pms_2_x,
		this->dma_apbperi_uhci0_pms_constrain_1.pms_dma_apbperi_uhci0_pms_constrain_sram_pms_2_y
	);
	r = this->regSet(r, 
		this->dma_apbperi_uhci0_pms_constrain_1.val,
		this->dma_apbperi_uhci0_pms_constrain_1.pms_dma_apbperi_uhci0_pms_constrain_sram_pms_1_x,
		this->dma_apbperi_uhci0_pms_constrain_1.pms_dma_apbperi_uhci0_pms_constrain_sram_pms_1_y
	);
	r = this->regSet(r, 
		this->dma_apbperi_uhci0_pms_constrain_1.val,
		this->dma_apbperi_uhci0_pms_constrain_1.pms_dma_apbperi_uhci0_pms_constrain_sram_pms_0_x,
		this->dma_apbperi_uhci0_pms_constrain_1.pms_dma_apbperi_uhci0_pms_constrain_sram_pms_0_y
	);

	if(writeMode){
		this->regWrite(true, this->dma_apbperi_uhci0_pms_constrain_1.base, r);
		this->init_dma_apbperi_uhci0_pms_constrain_1();
	}else{
		this->dma_apbperi_uhci0_pms_constrain_1.val = r;
	}
}
void PmsDebug::patch_dma_apbperi_i2s0_pms_constrain_0(bool writeMode){
	uint32_t r = this->dma_apbperi_i2s0_pms_constrain_0.val;
	r = this->regSet(r, 
		this->dma_apbperi_i2s0_pms_constrain_0.val,
		this->dma_apbperi_i2s0_pms_constrain_0.pms_dma_apbperi_i2s0_pms_constrain_lock_pos
	);

	if(writeMode){
		this->regWrite(true, this->dma_apbperi_i2s0_pms_constrain_0.base, r);
		this->init_dma_apbperi_i2s0_pms_constrain_0();
	}else{
		this->dma_apbperi_i2s0_pms_constrain_0.val = r;
	}
}
void PmsDebug::patch_dma_apbperi_i2s0_pms_constrain_1(bool writeMode){
	uint32_t r = this->dma_apbperi_i2s0_pms_constrain_1.val;
	r = this->regSet(r, 
		this->dma_apbperi_i2s0_pms_constrain_1.val,
		this->dma_apbperi_i2s0_pms_constrain_1.pms_dma_apbperi_i2s0_pms_constrain_sram_cachedataarray_pms_1_x,
		this->dma_apbperi_i2s0_pms_constrain_1.pms_dma_apbperi_i2s0_pms_constrain_sram_cachedataarray_pms_1_y
	);
	r = this->regSet(r, 
		this->dma_apbperi_i2s0_pms_constrain_1.val,
		this->dma_apbperi_i2s0_pms_constrain_1.pms_dma_apbperi_i2s0_pms_constrain_sram_cachedataarray_pms_0_x,
		this->dma_apbperi_i2s0_pms_constrain_1.pms_dma_apbperi_i2s0_pms_constrain_sram_cachedataarray_pms_0_y
	);
	r = this->regSet(r, 
		this->dma_apbperi_i2s0_pms_constrain_1.val,
		this->dma_apbperi_i2s0_pms_constrain_1.pms_dma_apbperi_i2s0_pms_constrain_sram_pms_3_x,
		this->dma_apbperi_i2s0_pms_constrain_1.pms_dma_apbperi_i2s0_pms_constrain_sram_pms_3_y
	);
	r = this->regSet(r, 
		this->dma_apbperi_i2s0_pms_constrain_1.val,
		this->dma_apbperi_i2s0_pms_constrain_1.pms_dma_apbperi_i2s0_pms_constrain_sram_pms_2_x,
		this->dma_apbperi_i2s0_pms_constrain_1.pms_dma_apbperi_i2s0_pms_constrain_sram_pms_2_y
	);
	r = this->regSet(r, 
		this->dma_apbperi_i2s0_pms_constrain_1.val,
		this->dma_apbperi_i2s0_pms_constrain_1.pms_dma_apbperi_i2s0_pms_constrain_sram_pms_1_x,
		this->dma_apbperi_i2s0_pms_constrain_1.pms_dma_apbperi_i2s0_pms_constrain_sram_pms_1_y
	);
	r = this->regSet(r, 
		this->dma_apbperi_i2s0_pms_constrain_1.val,
		this->dma_apbperi_i2s0_pms_constrain_1.pms_dma_apbperi_i2s0_pms_constrain_sram_pms_0_x,
		this->dma_apbperi_i2s0_pms_constrain_1.pms_dma_apbperi_i2s0_pms_constrain_sram_pms_0_y
	);

	if(writeMode){
		this->regWrite(true, this->dma_apbperi_i2s0_pms_constrain_1.base, r);
		this->init_dma_apbperi_i2s0_pms_constrain_1();
	}else{
		this->dma_apbperi_i2s0_pms_constrain_1.val = r;
	}
}
void PmsDebug::patch_dma_apbperi_i2s1_pms_constrain_0(bool writeMode){
	uint32_t r = this->dma_apbperi_i2s1_pms_constrain_0.val;
	r = this->regSet(r, 
		this->dma_apbperi_i2s1_pms_constrain_0.val,
		this->dma_apbperi_i2s1_pms_constrain_0.pms_dma_apbperi_i2s1_pms_constrain_lock_pos
	);

	if(writeMode){
		this->regWrite(true, this->dma_apbperi_i2s1_pms_constrain_0.base, r);
		this->init_dma_apbperi_i2s1_pms_constrain_0();
	}else{
		this->dma_apbperi_i2s1_pms_constrain_0.val = r;
	}
}
void PmsDebug::patch_dma_apbperi_i2s1_pms_constrain_1(bool writeMode){
	uint32_t r = this->dma_apbperi_i2s1_pms_constrain_1.val;
	r = this->regSet(r, 
		this->dma_apbperi_i2s1_pms_constrain_1.val,
		this->dma_apbperi_i2s1_pms_constrain_1.pms_dma_apbperi_i2s1_pms_constrain_sram_cachedataarray_pms_1_x,
		this->dma_apbperi_i2s1_pms_constrain_1.pms_dma_apbperi_i2s1_pms_constrain_sram_cachedataarray_pms_1_y
	);
	r = this->regSet(r, 
		this->dma_apbperi_i2s1_pms_constrain_1.val,
		this->dma_apbperi_i2s1_pms_constrain_1.pms_dma_apbperi_i2s1_pms_constrain_sram_cachedataarray_pms_0_x,
		this->dma_apbperi_i2s1_pms_constrain_1.pms_dma_apbperi_i2s1_pms_constrain_sram_cachedataarray_pms_0_y
	);
	r = this->regSet(r, 
		this->dma_apbperi_i2s1_pms_constrain_1.val,
		this->dma_apbperi_i2s1_pms_constrain_1.pms_dma_apbperi_i2s1_pms_constrain_sram_pms_3_x,
		this->dma_apbperi_i2s1_pms_constrain_1.pms_dma_apbperi_i2s1_pms_constrain_sram_pms_3_y
	);
	r = this->regSet(r, 
		this->dma_apbperi_i2s1_pms_constrain_1.val,
		this->dma_apbperi_i2s1_pms_constrain_1.pms_dma_apbperi_i2s1_pms_constrain_sram_pms_2_x,
		this->dma_apbperi_i2s1_pms_constrain_1.pms_dma_apbperi_i2s1_pms_constrain_sram_pms_2_y
	);
	r = this->regSet(r, 
		this->dma_apbperi_i2s1_pms_constrain_1.val,
		this->dma_apbperi_i2s1_pms_constrain_1.pms_dma_apbperi_i2s1_pms_constrain_sram_pms_1_x,
		this->dma_apbperi_i2s1_pms_constrain_1.pms_dma_apbperi_i2s1_pms_constrain_sram_pms_1_y
	);
	r = this->regSet(r, 
		this->dma_apbperi_i2s1_pms_constrain_1.val,
		this->dma_apbperi_i2s1_pms_constrain_1.pms_dma_apbperi_i2s1_pms_constrain_sram_pms_0_x,
		this->dma_apbperi_i2s1_pms_constrain_1.pms_dma_apbperi_i2s1_pms_constrain_sram_pms_0_y
	);

	if(writeMode){
		this->regWrite(true, this->dma_apbperi_i2s1_pms_constrain_1.base, r);
		this->init_dma_apbperi_i2s1_pms_constrain_1();
	}else{
		this->dma_apbperi_i2s1_pms_constrain_1.val = r;
	}
}
void PmsDebug::patch_dma_apbperi_aes_pms_constrain_0(bool writeMode){
	uint32_t r = this->dma_apbperi_aes_pms_constrain_0.val;
	r = this->regSet(r, 
		this->dma_apbperi_aes_pms_constrain_0.val,
		this->dma_apbperi_aes_pms_constrain_0.pms_dma_apbperi_aes_pms_constrain_lock_pos
	);

	if(writeMode){
		this->regWrite(true, this->dma_apbperi_aes_pms_constrain_0.base, r);
		this->init_dma_apbperi_aes_pms_constrain_0();
	}else{
		this->dma_apbperi_aes_pms_constrain_0.val = r;
	}
}
void PmsDebug::patch_dma_apbperi_aes_pms_constrain_1(bool writeMode){
	uint32_t r = this->dma_apbperi_aes_pms_constrain_1.val;
	r = this->regSet(r, 
		this->dma_apbperi_aes_pms_constrain_1.val,
		this->dma_apbperi_aes_pms_constrain_1.pms_dma_apbperi_aes_pms_constrain_sram_cachedataarray_pms_1_x,
		this->dma_apbperi_aes_pms_constrain_1.pms_dma_apbperi_aes_pms_constrain_sram_cachedataarray_pms_1_y
	);
	r = this->regSet(r, 
		this->dma_apbperi_aes_pms_constrain_1.val,
		this->dma_apbperi_aes_pms_constrain_1.pms_dma_apbperi_aes_pms_constrain_sram_cachedataarray_pms_0_x,
		this->dma_apbperi_aes_pms_constrain_1.pms_dma_apbperi_aes_pms_constrain_sram_cachedataarray_pms_0_y
	);
	r = this->regSet(r, 
		this->dma_apbperi_aes_pms_constrain_1.val,
		this->dma_apbperi_aes_pms_constrain_1.pms_dma_apbperi_aes_pms_constrain_sram_pms_3_x,
		this->dma_apbperi_aes_pms_constrain_1.pms_dma_apbperi_aes_pms_constrain_sram_pms_3_y
	);
	r = this->regSet(r, 
		this->dma_apbperi_aes_pms_constrain_1.val,
		this->dma_apbperi_aes_pms_constrain_1.pms_dma_apbperi_aes_pms_constrain_sram_pms_2_x,
		this->dma_apbperi_aes_pms_constrain_1.pms_dma_apbperi_aes_pms_constrain_sram_pms_2_y
	);
	r = this->regSet(r, 
		this->dma_apbperi_aes_pms_constrain_1.val,
		this->dma_apbperi_aes_pms_constrain_1.pms_dma_apbperi_aes_pms_constrain_sram_pms_1_x,
		this->dma_apbperi_aes_pms_constrain_1.pms_dma_apbperi_aes_pms_constrain_sram_pms_1_y
	);
	r = this->regSet(r, 
		this->dma_apbperi_aes_pms_constrain_1.val,
		this->dma_apbperi_aes_pms_constrain_1.pms_dma_apbperi_aes_pms_constrain_sram_pms_0_x,
		this->dma_apbperi_aes_pms_constrain_1.pms_dma_apbperi_aes_pms_constrain_sram_pms_0_y
	);

	if(writeMode){
		this->regWrite(true, this->dma_apbperi_aes_pms_constrain_1.base, r);
		this->init_dma_apbperi_aes_pms_constrain_1();
	}else{
		this->dma_apbperi_aes_pms_constrain_1.val = r;
	}
}
void PmsDebug::patch_dma_apbperi_sha_pms_constrain_0(bool writeMode){
	uint32_t r = this->dma_apbperi_sha_pms_constrain_0.val;
	r = this->regSet(r, 
		this->dma_apbperi_sha_pms_constrain_0.val,
		this->dma_apbperi_sha_pms_constrain_0.pms_dma_apbperi_sha_pms_constrain_lock_pos
	);

	if(writeMode){
		this->regWrite(true, this->dma_apbperi_sha_pms_constrain_0.base, r);
		this->init_dma_apbperi_sha_pms_constrain_0();
	}else{
		this->dma_apbperi_sha_pms_constrain_0.val = r;
	}
}
void PmsDebug::patch_dma_apbperi_sha_pms_constrain_1(bool writeMode){
	uint32_t r = this->dma_apbperi_sha_pms_constrain_1.val;
	r = this->regSet(r, 
		this->dma_apbperi_sha_pms_constrain_1.val,
		this->dma_apbperi_sha_pms_constrain_1.pms_dma_apbperi_sha_pms_constrain_sram_cachedataarray_pms_1_x,
		this->dma_apbperi_sha_pms_constrain_1.pms_dma_apbperi_sha_pms_constrain_sram_cachedataarray_pms_1_y
	);
	r = this->regSet(r, 
		this->dma_apbperi_sha_pms_constrain_1.val,
		this->dma_apbperi_sha_pms_constrain_1.pms_dma_apbperi_sha_pms_constrain_sram_cachedataarray_pms_0_x,
		this->dma_apbperi_sha_pms_constrain_1.pms_dma_apbperi_sha_pms_constrain_sram_cachedataarray_pms_0_y
	);
	r = this->regSet(r, 
		this->dma_apbperi_sha_pms_constrain_1.val,
		this->dma_apbperi_sha_pms_constrain_1.pms_dma_apbperi_sha_pms_constrain_sram_pms_3_x,
		this->dma_apbperi_sha_pms_constrain_1.pms_dma_apbperi_sha_pms_constrain_sram_pms_3_y
	);
	r = this->regSet(r, 
		this->dma_apbperi_sha_pms_constrain_1.val,
		this->dma_apbperi_sha_pms_constrain_1.pms_dma_apbperi_sha_pms_constrain_sram_pms_2_x,
		this->dma_apbperi_sha_pms_constrain_1.pms_dma_apbperi_sha_pms_constrain_sram_pms_2_y
	);
	r = this->regSet(r, 
		this->dma_apbperi_sha_pms_constrain_1.val,
		this->dma_apbperi_sha_pms_constrain_1.pms_dma_apbperi_sha_pms_constrain_sram_pms_1_x,
		this->dma_apbperi_sha_pms_constrain_1.pms_dma_apbperi_sha_pms_constrain_sram_pms_1_y
	);
	r = this->regSet(r, 
		this->dma_apbperi_sha_pms_constrain_1.val,
		this->dma_apbperi_sha_pms_constrain_1.pms_dma_apbperi_sha_pms_constrain_sram_pms_0_x,
		this->dma_apbperi_sha_pms_constrain_1.pms_dma_apbperi_sha_pms_constrain_sram_pms_0_y
	);

	if(writeMode){
		this->regWrite(true, this->dma_apbperi_sha_pms_constrain_1.base, r);
		this->init_dma_apbperi_sha_pms_constrain_1();
	}else{
		this->dma_apbperi_sha_pms_constrain_1.val = r;
	}
}
void PmsDebug::patch_dma_apbperi_adc_dac_pms_constrain_0(bool writeMode){
	uint32_t r = this->dma_apbperi_adc_dac_pms_constrain_0.val;
	r = this->regSet(r, 
		this->dma_apbperi_adc_dac_pms_constrain_0.val,
		this->dma_apbperi_adc_dac_pms_constrain_0.pms_dma_apbperi_adc_dac_pms_constrain_lock_pos
	);

	if(writeMode){
		this->regWrite(true, this->dma_apbperi_adc_dac_pms_constrain_0.base, r);
		this->init_dma_apbperi_adc_dac_pms_constrain_0();
	}else{
		this->dma_apbperi_adc_dac_pms_constrain_0.val = r;
	}
}
void PmsDebug::patch_dma_apbperi_adc_dac_pms_constrain_1(bool writeMode){
	uint32_t r = this->dma_apbperi_adc_dac_pms_constrain_1.val;
	r = this->regSet(r, 
		this->dma_apbperi_adc_dac_pms_constrain_1.val,
		this->dma_apbperi_adc_dac_pms_constrain_1.pms_dma_apbperi_adc_dac_pms_constrain_sram_cachedataarray_pms_1_x,
		this->dma_apbperi_adc_dac_pms_constrain_1.pms_dma_apbperi_adc_dac_pms_constrain_sram_cachedataarray_pms_1_y
	);
	r = this->regSet(r, 
		this->dma_apbperi_adc_dac_pms_constrain_1.val,
		this->dma_apbperi_adc_dac_pms_constrain_1.pms_dma_apbperi_adc_dac_pms_constrain_sram_cachedataarray_pms_0_x,
		this->dma_apbperi_adc_dac_pms_constrain_1.pms_dma_apbperi_adc_dac_pms_constrain_sram_cachedataarray_pms_0_y
	);
	r = this->regSet(r, 
		this->dma_apbperi_adc_dac_pms_constrain_1.val,
		this->dma_apbperi_adc_dac_pms_constrain_1.pms_dma_apbperi_adc_dac_pms_constrain_sram_pms_3_x,
		this->dma_apbperi_adc_dac_pms_constrain_1.pms_dma_apbperi_adc_dac_pms_constrain_sram_pms_3_y
	);
	r = this->regSet(r, 
		this->dma_apbperi_adc_dac_pms_constrain_1.val,
		this->dma_apbperi_adc_dac_pms_constrain_1.pms_dma_apbperi_adc_dac_pms_constrain_sram_pms_2_x,
		this->dma_apbperi_adc_dac_pms_constrain_1.pms_dma_apbperi_adc_dac_pms_constrain_sram_pms_2_y
	);
	r = this->regSet(r, 
		this->dma_apbperi_adc_dac_pms_constrain_1.val,
		this->dma_apbperi_adc_dac_pms_constrain_1.pms_dma_apbperi_adc_dac_pms_constrain_sram_pms_1_x,
		this->dma_apbperi_adc_dac_pms_constrain_1.pms_dma_apbperi_adc_dac_pms_constrain_sram_pms_1_y
	);
	r = this->regSet(r, 
		this->dma_apbperi_adc_dac_pms_constrain_1.val,
		this->dma_apbperi_adc_dac_pms_constrain_1.pms_dma_apbperi_adc_dac_pms_constrain_sram_pms_0_x,
		this->dma_apbperi_adc_dac_pms_constrain_1.pms_dma_apbperi_adc_dac_pms_constrain_sram_pms_0_y
	);

	if(writeMode){
		this->regWrite(true, this->dma_apbperi_adc_dac_pms_constrain_1.base, r);
		this->init_dma_apbperi_adc_dac_pms_constrain_1();
	}else{
		this->dma_apbperi_adc_dac_pms_constrain_1.val = r;
	}
}
void PmsDebug::patch_dma_apbperi_rmt_pms_constrain_0(bool writeMode){
	uint32_t r = this->dma_apbperi_rmt_pms_constrain_0.val;
	r = this->regSet(r, 
		this->dma_apbperi_rmt_pms_constrain_0.val,
		this->dma_apbperi_rmt_pms_constrain_0.pms_dma_apbperi_rmt_pms_constrain_lock_pos
	);

	if(writeMode){
		this->regWrite(true, this->dma_apbperi_rmt_pms_constrain_0.base, r);
		this->init_dma_apbperi_rmt_pms_constrain_0();
	}else{
		this->dma_apbperi_rmt_pms_constrain_0.val = r;
	}
}
void PmsDebug::patch_dma_apbperi_rmt_pms_constrain_1(bool writeMode){
	uint32_t r = this->dma_apbperi_rmt_pms_constrain_1.val;
	r = this->regSet(r, 
		this->dma_apbperi_rmt_pms_constrain_1.val,
		this->dma_apbperi_rmt_pms_constrain_1.pms_dma_apbperi_rmt_pms_constrain_sram_cachedataarray_pms_1_x,
		this->dma_apbperi_rmt_pms_constrain_1.pms_dma_apbperi_rmt_pms_constrain_sram_cachedataarray_pms_1_y
	);
	r = this->regSet(r, 
		this->dma_apbperi_rmt_pms_constrain_1.val,
		this->dma_apbperi_rmt_pms_constrain_1.pms_dma_apbperi_rmt_pms_constrain_sram_cachedataarray_pms_0_x,
		this->dma_apbperi_rmt_pms_constrain_1.pms_dma_apbperi_rmt_pms_constrain_sram_cachedataarray_pms_0_y
	);
	r = this->regSet(r, 
		this->dma_apbperi_rmt_pms_constrain_1.val,
		this->dma_apbperi_rmt_pms_constrain_1.pms_dma_apbperi_rmt_pms_constrain_sram_pms_3_x,
		this->dma_apbperi_rmt_pms_constrain_1.pms_dma_apbperi_rmt_pms_constrain_sram_pms_3_y
	);
	r = this->regSet(r, 
		this->dma_apbperi_rmt_pms_constrain_1.val,
		this->dma_apbperi_rmt_pms_constrain_1.pms_dma_apbperi_rmt_pms_constrain_sram_pms_2_x,
		this->dma_apbperi_rmt_pms_constrain_1.pms_dma_apbperi_rmt_pms_constrain_sram_pms_2_y
	);
	r = this->regSet(r, 
		this->dma_apbperi_rmt_pms_constrain_1.val,
		this->dma_apbperi_rmt_pms_constrain_1.pms_dma_apbperi_rmt_pms_constrain_sram_pms_1_x,
		this->dma_apbperi_rmt_pms_constrain_1.pms_dma_apbperi_rmt_pms_constrain_sram_pms_1_y
	);
	r = this->regSet(r, 
		this->dma_apbperi_rmt_pms_constrain_1.val,
		this->dma_apbperi_rmt_pms_constrain_1.pms_dma_apbperi_rmt_pms_constrain_sram_pms_0_x,
		this->dma_apbperi_rmt_pms_constrain_1.pms_dma_apbperi_rmt_pms_constrain_sram_pms_0_y
	);

	if(writeMode){
		this->regWrite(true, this->dma_apbperi_rmt_pms_constrain_1.base, r);
		this->init_dma_apbperi_rmt_pms_constrain_1();
	}else{
		this->dma_apbperi_rmt_pms_constrain_1.val = r;
	}
}
void PmsDebug::patch_dma_apbperi_lcd_cam_pms_constrain_0(bool writeMode){
	uint32_t r = this->dma_apbperi_lcd_cam_pms_constrain_0.val;
	r = this->regSet(r, 
		this->dma_apbperi_lcd_cam_pms_constrain_0.val,
		this->dma_apbperi_lcd_cam_pms_constrain_0.pms_dma_apbperi_lcd_cam_pms_constrain_lock_pos
	);

	if(writeMode){
		this->regWrite(true, this->dma_apbperi_lcd_cam_pms_constrain_0.base, r);
		this->init_dma_apbperi_lcd_cam_pms_constrain_0();
	}else{
		this->dma_apbperi_lcd_cam_pms_constrain_0.val = r;
	}
}
void PmsDebug::patch_dma_apbperi_lcd_cam_pms_constrain_1(bool writeMode){
	uint32_t r = this->dma_apbperi_lcd_cam_pms_constrain_1.val;
	r = this->regSet(r, 
		this->dma_apbperi_lcd_cam_pms_constrain_1.val,
		this->dma_apbperi_lcd_cam_pms_constrain_1.pms_dma_apbperi_lcd_cam_pms_constrain_sram_cachedataarray_pms_1_x,
		this->dma_apbperi_lcd_cam_pms_constrain_1.pms_dma_apbperi_lcd_cam_pms_constrain_sram_cachedataarray_pms_1_y
	);
	r = this->regSet(r, 
		this->dma_apbperi_lcd_cam_pms_constrain_1.val,
		this->dma_apbperi_lcd_cam_pms_constrain_1.pms_dma_apbperi_lcd_cam_pms_constrain_sram_cachedataarray_pms_0_x,
		this->dma_apbperi_lcd_cam_pms_constrain_1.pms_dma_apbperi_lcd_cam_pms_constrain_sram_cachedataarray_pms_0_y
	);
	r = this->regSet(r, 
		this->dma_apbperi_lcd_cam_pms_constrain_1.val,
		this->dma_apbperi_lcd_cam_pms_constrain_1.pms_dma_apbperi_lcd_cam_pms_constrain_sram_pms_3_x,
		this->dma_apbperi_lcd_cam_pms_constrain_1.pms_dma_apbperi_lcd_cam_pms_constrain_sram_pms_3_y
	);
	r = this->regSet(r, 
		this->dma_apbperi_lcd_cam_pms_constrain_1.val,
		this->dma_apbperi_lcd_cam_pms_constrain_1.pms_dma_apbperi_lcd_cam_pms_constrain_sram_pms_2_x,
		this->dma_apbperi_lcd_cam_pms_constrain_1.pms_dma_apbperi_lcd_cam_pms_constrain_sram_pms_2_y
	);
	r = this->regSet(r, 
		this->dma_apbperi_lcd_cam_pms_constrain_1.val,
		this->dma_apbperi_lcd_cam_pms_constrain_1.pms_dma_apbperi_lcd_cam_pms_constrain_sram_pms_1_x,
		this->dma_apbperi_lcd_cam_pms_constrain_1.pms_dma_apbperi_lcd_cam_pms_constrain_sram_pms_1_y
	);
	r = this->regSet(r, 
		this->dma_apbperi_lcd_cam_pms_constrain_1.val,
		this->dma_apbperi_lcd_cam_pms_constrain_1.pms_dma_apbperi_lcd_cam_pms_constrain_sram_pms_0_x,
		this->dma_apbperi_lcd_cam_pms_constrain_1.pms_dma_apbperi_lcd_cam_pms_constrain_sram_pms_0_y
	);

	if(writeMode){
		this->regWrite(true, this->dma_apbperi_lcd_cam_pms_constrain_1.base, r);
		this->init_dma_apbperi_lcd_cam_pms_constrain_1();
	}else{
		this->dma_apbperi_lcd_cam_pms_constrain_1.val = r;
	}
}
void PmsDebug::patch_dma_apbperi_usb_pms_constrain_0(bool writeMode){
	uint32_t r = this->dma_apbperi_usb_pms_constrain_0.val;
	r = this->regSet(r, 
		this->dma_apbperi_usb_pms_constrain_0.val,
		this->dma_apbperi_usb_pms_constrain_0.pms_dma_apbperi_usb_pms_constrain_lock_pos
	);

	if(writeMode){
		this->regWrite(true, this->dma_apbperi_usb_pms_constrain_0.base, r);
		this->init_dma_apbperi_usb_pms_constrain_0();
	}else{
		this->dma_apbperi_usb_pms_constrain_0.val = r;
	}
}
void PmsDebug::patch_dma_apbperi_usb_pms_constrain_1(bool writeMode){
	uint32_t r = this->dma_apbperi_usb_pms_constrain_1.val;
	r = this->regSet(r, 
		this->dma_apbperi_usb_pms_constrain_1.val,
		this->dma_apbperi_usb_pms_constrain_1.pms_dma_apbperi_usb_pms_constrain_sram_cachedataarray_pms_1_x,
		this->dma_apbperi_usb_pms_constrain_1.pms_dma_apbperi_usb_pms_constrain_sram_cachedataarray_pms_1_y
	);
	r = this->regSet(r, 
		this->dma_apbperi_usb_pms_constrain_1.val,
		this->dma_apbperi_usb_pms_constrain_1.pms_dma_apbperi_usb_pms_constrain_sram_cachedataarray_pms_0_x,
		this->dma_apbperi_usb_pms_constrain_1.pms_dma_apbperi_usb_pms_constrain_sram_cachedataarray_pms_0_y
	);
	r = this->regSet(r, 
		this->dma_apbperi_usb_pms_constrain_1.val,
		this->dma_apbperi_usb_pms_constrain_1.pms_dma_apbperi_usb_pms_constrain_sram_pms_3_x,
		this->dma_apbperi_usb_pms_constrain_1.pms_dma_apbperi_usb_pms_constrain_sram_pms_3_y
	);
	r = this->regSet(r, 
		this->dma_apbperi_usb_pms_constrain_1.val,
		this->dma_apbperi_usb_pms_constrain_1.pms_dma_apbperi_usb_pms_constrain_sram_pms_2_x,
		this->dma_apbperi_usb_pms_constrain_1.pms_dma_apbperi_usb_pms_constrain_sram_pms_2_y
	);
	r = this->regSet(r, 
		this->dma_apbperi_usb_pms_constrain_1.val,
		this->dma_apbperi_usb_pms_constrain_1.pms_dma_apbperi_usb_pms_constrain_sram_pms_1_x,
		this->dma_apbperi_usb_pms_constrain_1.pms_dma_apbperi_usb_pms_constrain_sram_pms_1_y
	);
	r = this->regSet(r, 
		this->dma_apbperi_usb_pms_constrain_1.val,
		this->dma_apbperi_usb_pms_constrain_1.pms_dma_apbperi_usb_pms_constrain_sram_pms_0_x,
		this->dma_apbperi_usb_pms_constrain_1.pms_dma_apbperi_usb_pms_constrain_sram_pms_0_y
	);

	if(writeMode){
		this->regWrite(true, this->dma_apbperi_usb_pms_constrain_1.base, r);
		this->init_dma_apbperi_usb_pms_constrain_1();
	}else{
		this->dma_apbperi_usb_pms_constrain_1.val = r;
	}
}
void PmsDebug::patch_dma_apbperi_sdio_pms_constrain_0(bool writeMode){
	uint32_t r = this->dma_apbperi_sdio_pms_constrain_0.val;
	r = this->regSet(r, 
		this->dma_apbperi_sdio_pms_constrain_0.val,
		this->dma_apbperi_sdio_pms_constrain_0.pms_dma_apbperi_sdio_pms_constrain_lock_pos
	);

	if(writeMode){
		this->regWrite(true, this->dma_apbperi_sdio_pms_constrain_0.base, r);
		this->init_dma_apbperi_sdio_pms_constrain_0();
	}else{
		this->dma_apbperi_sdio_pms_constrain_0.val = r;
	}
}
void PmsDebug::patch_dma_apbperi_sdio_pms_constrain_1(bool writeMode){
	uint32_t r = this->dma_apbperi_sdio_pms_constrain_1.val;
	r = this->regSet(r, 
		this->dma_apbperi_sdio_pms_constrain_1.val,
		this->dma_apbperi_sdio_pms_constrain_1.pms_dma_apbperi_sdio_pms_constrain_sram_cachedataarray_pms_1_x,
		this->dma_apbperi_sdio_pms_constrain_1.pms_dma_apbperi_sdio_pms_constrain_sram_cachedataarray_pms_1_y
	);
	r = this->regSet(r, 
		this->dma_apbperi_sdio_pms_constrain_1.val,
		this->dma_apbperi_sdio_pms_constrain_1.pms_dma_apbperi_sdio_pms_constrain_sram_cachedataarray_pms_0_x,
		this->dma_apbperi_sdio_pms_constrain_1.pms_dma_apbperi_sdio_pms_constrain_sram_cachedataarray_pms_0_y
	);
	r = this->regSet(r, 
		this->dma_apbperi_sdio_pms_constrain_1.val,
		this->dma_apbperi_sdio_pms_constrain_1.pms_dma_apbperi_sdio_pms_constrain_sram_pms_3_x,
		this->dma_apbperi_sdio_pms_constrain_1.pms_dma_apbperi_sdio_pms_constrain_sram_pms_3_y
	);
	r = this->regSet(r, 
		this->dma_apbperi_sdio_pms_constrain_1.val,
		this->dma_apbperi_sdio_pms_constrain_1.pms_dma_apbperi_sdio_pms_constrain_sram_pms_2_x,
		this->dma_apbperi_sdio_pms_constrain_1.pms_dma_apbperi_sdio_pms_constrain_sram_pms_2_y
	);
	r = this->regSet(r, 
		this->dma_apbperi_sdio_pms_constrain_1.val,
		this->dma_apbperi_sdio_pms_constrain_1.pms_dma_apbperi_sdio_pms_constrain_sram_pms_1_x,
		this->dma_apbperi_sdio_pms_constrain_1.pms_dma_apbperi_sdio_pms_constrain_sram_pms_1_y
	);
	r = this->regSet(r, 
		this->dma_apbperi_sdio_pms_constrain_1.val,
		this->dma_apbperi_sdio_pms_constrain_1.pms_dma_apbperi_sdio_pms_constrain_sram_pms_0_x,
		this->dma_apbperi_sdio_pms_constrain_1.pms_dma_apbperi_sdio_pms_constrain_sram_pms_0_y
	);

	if(writeMode){
		this->regWrite(true, this->dma_apbperi_sdio_pms_constrain_1.base, r);
		this->init_dma_apbperi_sdio_pms_constrain_1();
	}else{
		this->dma_apbperi_sdio_pms_constrain_1.val = r;
	}
}
void PmsDebug::patch_dma_apbperi_pms_monitor_0(bool writeMode){
	uint32_t r = this->dma_apbperi_pms_monitor_0.val;
	r = this->regSet(r, 
		this->dma_apbperi_pms_monitor_0.val,
		this->dma_apbperi_pms_monitor_0.pms_dma_apbperi_pms_monitor_lock_pos
	);

	if(writeMode){
		this->regWrite(true, this->dma_apbperi_pms_monitor_0.base, r);
		this->init_dma_apbperi_pms_monitor_0();
	}else{
		this->dma_apbperi_pms_monitor_0.val = r;
	}
}
void PmsDebug::patch_dma_apbperi_pms_monitor_1(bool writeMode){
	uint32_t r = this->dma_apbperi_pms_monitor_1.val;
	r = this->regSet(r, 
		this->dma_apbperi_pms_monitor_1.val,
		this->dma_apbperi_pms_monitor_1.pms_dma_apbperi_pms_monitor_violate_en_pos
	);
	r = this->regSet(r, 
		this->dma_apbperi_pms_monitor_1.val,
		this->dma_apbperi_pms_monitor_1.pms_dma_apbperi_pms_monitor_violate_clr_pos
	);

	if(writeMode){
		this->regWrite(true, this->dma_apbperi_pms_monitor_1.base, r);
		this->init_dma_apbperi_pms_monitor_1();
	}else{
		this->dma_apbperi_pms_monitor_1.val = r;
	}
}
void PmsDebug::patch_dma_apbperi_pms_monitor_2(bool writeMode){
	uint32_t r = this->dma_apbperi_pms_monitor_2.val;
	r = this->regSet(r, 
		this->dma_apbperi_pms_monitor_2.val,
		this->dma_apbperi_pms_monitor_2.pms_dma_apbperi_pms_monitor_violate_status_addr_x,
		this->dma_apbperi_pms_monitor_2.pms_dma_apbperi_pms_monitor_violate_status_addr_y
	);
	r = this->regSet(r, 
		this->dma_apbperi_pms_monitor_2.val,
		this->dma_apbperi_pms_monitor_2.pms_dma_apbperi_pms_monitor_violate_status_world_x,
		this->dma_apbperi_pms_monitor_2.pms_dma_apbperi_pms_monitor_violate_status_world_y
	);
	r = this->regSet(r, 
		this->dma_apbperi_pms_monitor_2.val,
		this->dma_apbperi_pms_monitor_2.pms_dma_apbperi_pms_monitor_violate_intr_pos
	);

	if(writeMode){
		this->regWrite(true, this->dma_apbperi_pms_monitor_2.base, r);
		this->init_dma_apbperi_pms_monitor_2();
	}else{
		this->dma_apbperi_pms_monitor_2.val = r;
	}
}
void PmsDebug::patch_dma_apbperi_pms_monitor_3(bool writeMode){
	uint32_t r = this->dma_apbperi_pms_monitor_3.val;
	r = this->regSet(r, 
		this->dma_apbperi_pms_monitor_3.val,
		this->dma_apbperi_pms_monitor_3.pms_dma_apbperi_pms_monitor_violate_status_byteen_x,
		this->dma_apbperi_pms_monitor_3.pms_dma_apbperi_pms_monitor_violate_status_byteen_y
	);
	r = this->regSet(r, 
		this->dma_apbperi_pms_monitor_3.val,
		this->dma_apbperi_pms_monitor_3.pms_dma_apbperi_pms_monitor_violate_status_wr_pos
	);

	if(writeMode){
		this->regWrite(true, this->dma_apbperi_pms_monitor_3.base, r);
		this->init_dma_apbperi_pms_monitor_3();
	}else{
		this->dma_apbperi_pms_monitor_3.val = r;
	}
}
void PmsDebug::patch_core_x_iram0_dram0_dma_split_line_constrain_0(bool writeMode){
	uint32_t r = this->core_x_iram0_dram0_dma_split_line_constrain_0.val;
	r = this->regSet(r, 
		this->core_x_iram0_dram0_dma_split_line_constrain_0.val,
		this->core_x_iram0_dram0_dma_split_line_constrain_0.pms_core_x_iram0_dram0_dma_split_line_constrain_lock_pos
	);

	if(writeMode){
		this->regWrite(true, this->core_x_iram0_dram0_dma_split_line_constrain_0.base, r);
		this->init_core_x_iram0_dram0_dma_split_line_constrain_0();
	}else{
		this->core_x_iram0_dram0_dma_split_line_constrain_0.val = r;
	}
}
void PmsDebug::patch_core_x_iram0_dram0_dma_split_line_constrain_1(bool writeMode){
	uint32_t r = this->core_x_iram0_dram0_dma_split_line_constrain_1.val;
	r = this->regSet(r, 
		this->core_x_iram0_dram0_dma_split_line_constrain_1.val,
		this->core_x_iram0_dram0_dma_split_line_constrain_1.pms_core_x_iram0_dram0_dma_sram_splitaddr_x,
		this->core_x_iram0_dram0_dma_split_line_constrain_1.pms_core_x_iram0_dram0_dma_sram_splitaddr_y
	);
	r = this->regSet(r, 
		this->core_x_iram0_dram0_dma_split_line_constrain_1.val,
		this->core_x_iram0_dram0_dma_split_line_constrain_1.pms_core_x_iram0_dram0_dma_sram_category_6_x,
		this->core_x_iram0_dram0_dma_split_line_constrain_1.pms_core_x_iram0_dram0_dma_sram_category_6_y
	);
	r = this->regSet(r, 
		this->core_x_iram0_dram0_dma_split_line_constrain_1.val,
		this->core_x_iram0_dram0_dma_split_line_constrain_1.pms_core_x_iram0_dram0_dma_sram_category_5_x,
		this->core_x_iram0_dram0_dma_split_line_constrain_1.pms_core_x_iram0_dram0_dma_sram_category_5_y
	);
	r = this->regSet(r, 
		this->core_x_iram0_dram0_dma_split_line_constrain_1.val,
		this->core_x_iram0_dram0_dma_split_line_constrain_1.pms_core_x_iram0_dram0_dma_sram_category_4_x,
		this->core_x_iram0_dram0_dma_split_line_constrain_1.pms_core_x_iram0_dram0_dma_sram_category_4_y
	);
	r = this->regSet(r, 
		this->core_x_iram0_dram0_dma_split_line_constrain_1.val,
		this->core_x_iram0_dram0_dma_split_line_constrain_1.pms_core_x_iram0_dram0_dma_sram_category_3_x,
		this->core_x_iram0_dram0_dma_split_line_constrain_1.pms_core_x_iram0_dram0_dma_sram_category_3_y
	);
	r = this->regSet(r, 
		this->core_x_iram0_dram0_dma_split_line_constrain_1.val,
		this->core_x_iram0_dram0_dma_split_line_constrain_1.pms_core_x_iram0_dram0_dma_sram_category_2_x,
		this->core_x_iram0_dram0_dma_split_line_constrain_1.pms_core_x_iram0_dram0_dma_sram_category_2_y
	);
	r = this->regSet(r, 
		this->core_x_iram0_dram0_dma_split_line_constrain_1.val,
		this->core_x_iram0_dram0_dma_split_line_constrain_1.pms_core_x_iram0_dram0_dma_sram_category_1_x,
		this->core_x_iram0_dram0_dma_split_line_constrain_1.pms_core_x_iram0_dram0_dma_sram_category_1_y
	);
	r = this->regSet(r, 
		this->core_x_iram0_dram0_dma_split_line_constrain_1.val,
		this->core_x_iram0_dram0_dma_split_line_constrain_1.pms_core_x_iram0_dram0_dma_sram_category_0_x,
		this->core_x_iram0_dram0_dma_split_line_constrain_1.pms_core_x_iram0_dram0_dma_sram_category_0_y
	);

	if(writeMode){
		this->regWrite(true, this->core_x_iram0_dram0_dma_split_line_constrain_1.base, r);
		this->init_core_x_iram0_dram0_dma_split_line_constrain_1();
	}else{
		this->core_x_iram0_dram0_dma_split_line_constrain_1.val = r;
	}
}
void PmsDebug::patch_core_x_iram0_dram0_dma_split_line_constrain_2(bool writeMode){
	uint32_t r = this->core_x_iram0_dram0_dma_split_line_constrain_2.val;
	r = this->regSet(r, 
		this->core_x_iram0_dram0_dma_split_line_constrain_2.val,
		this->core_x_iram0_dram0_dma_split_line_constrain_2.pms_core_x_iram0_sram_line_0_splitaddr_x,
		this->core_x_iram0_dram0_dma_split_line_constrain_2.pms_core_x_iram0_sram_line_0_splitaddr_y
	);
	r = this->regSet(r, 
		this->core_x_iram0_dram0_dma_split_line_constrain_2.val,
		this->core_x_iram0_dram0_dma_split_line_constrain_2.pms_core_x_iram0_sram_line_0_category_6_x,
		this->core_x_iram0_dram0_dma_split_line_constrain_2.pms_core_x_iram0_sram_line_0_category_6_y
	);
	r = this->regSet(r, 
		this->core_x_iram0_dram0_dma_split_line_constrain_2.val,
		this->core_x_iram0_dram0_dma_split_line_constrain_2.pms_core_x_iram0_sram_line_0_category_5_x,
		this->core_x_iram0_dram0_dma_split_line_constrain_2.pms_core_x_iram0_sram_line_0_category_5_y
	);
	r = this->regSet(r, 
		this->core_x_iram0_dram0_dma_split_line_constrain_2.val,
		this->core_x_iram0_dram0_dma_split_line_constrain_2.pms_core_x_iram0_sram_line_0_category_4_x,
		this->core_x_iram0_dram0_dma_split_line_constrain_2.pms_core_x_iram0_sram_line_0_category_4_y
	);
	r = this->regSet(r, 
		this->core_x_iram0_dram0_dma_split_line_constrain_2.val,
		this->core_x_iram0_dram0_dma_split_line_constrain_2.pms_core_x_iram0_sram_line_0_category_3_x,
		this->core_x_iram0_dram0_dma_split_line_constrain_2.pms_core_x_iram0_sram_line_0_category_3_y
	);
	r = this->regSet(r, 
		this->core_x_iram0_dram0_dma_split_line_constrain_2.val,
		this->core_x_iram0_dram0_dma_split_line_constrain_2.pms_core_x_iram0_sram_line_0_category_2_x,
		this->core_x_iram0_dram0_dma_split_line_constrain_2.pms_core_x_iram0_sram_line_0_category_2_y
	);
	r = this->regSet(r, 
		this->core_x_iram0_dram0_dma_split_line_constrain_2.val,
		this->core_x_iram0_dram0_dma_split_line_constrain_2.pms_core_x_iram0_sram_line_0_category_1_x,
		this->core_x_iram0_dram0_dma_split_line_constrain_2.pms_core_x_iram0_sram_line_0_category_1_y
	);
	r = this->regSet(r, 
		this->core_x_iram0_dram0_dma_split_line_constrain_2.val,
		this->core_x_iram0_dram0_dma_split_line_constrain_2.pms_core_x_iram0_sram_line_0_category_0_x,
		this->core_x_iram0_dram0_dma_split_line_constrain_2.pms_core_x_iram0_sram_line_0_category_0_y
	);

	if(writeMode){
		this->regWrite(true, this->core_x_iram0_dram0_dma_split_line_constrain_2.base, r);
		this->init_core_x_iram0_dram0_dma_split_line_constrain_2();
	}else{
		this->core_x_iram0_dram0_dma_split_line_constrain_2.val = r;
	}
}
void PmsDebug::patch_core_x_iram0_dram0_dma_split_line_constrain_3(bool writeMode){
	uint32_t r = this->core_x_iram0_dram0_dma_split_line_constrain_3.val;
	r = this->regSet(r, 
		this->core_x_iram0_dram0_dma_split_line_constrain_3.val,
		this->core_x_iram0_dram0_dma_split_line_constrain_3.pms_core_x_iram0_sram_line_1_splitaddr_x,
		this->core_x_iram0_dram0_dma_split_line_constrain_3.pms_core_x_iram0_sram_line_1_splitaddr_y
	);
	r = this->regSet(r, 
		this->core_x_iram0_dram0_dma_split_line_constrain_3.val,
		this->core_x_iram0_dram0_dma_split_line_constrain_3.pms_core_x_iram0_sram_line_1_category_6_x,
		this->core_x_iram0_dram0_dma_split_line_constrain_3.pms_core_x_iram0_sram_line_1_category_6_y
	);
	r = this->regSet(r, 
		this->core_x_iram0_dram0_dma_split_line_constrain_3.val,
		this->core_x_iram0_dram0_dma_split_line_constrain_3.pms_core_x_iram0_sram_line_1_category_5_x,
		this->core_x_iram0_dram0_dma_split_line_constrain_3.pms_core_x_iram0_sram_line_1_category_5_y
	);
	r = this->regSet(r, 
		this->core_x_iram0_dram0_dma_split_line_constrain_3.val,
		this->core_x_iram0_dram0_dma_split_line_constrain_3.pms_core_x_iram0_sram_line_1_category_4_x,
		this->core_x_iram0_dram0_dma_split_line_constrain_3.pms_core_x_iram0_sram_line_1_category_4_y
	);
	r = this->regSet(r, 
		this->core_x_iram0_dram0_dma_split_line_constrain_3.val,
		this->core_x_iram0_dram0_dma_split_line_constrain_3.pms_core_x_iram0_sram_line_1_category_3_x,
		this->core_x_iram0_dram0_dma_split_line_constrain_3.pms_core_x_iram0_sram_line_1_category_3_y
	);
	r = this->regSet(r, 
		this->core_x_iram0_dram0_dma_split_line_constrain_3.val,
		this->core_x_iram0_dram0_dma_split_line_constrain_3.pms_core_x_iram0_sram_line_1_category_2_x,
		this->core_x_iram0_dram0_dma_split_line_constrain_3.pms_core_x_iram0_sram_line_1_category_2_y
	);
	r = this->regSet(r, 
		this->core_x_iram0_dram0_dma_split_line_constrain_3.val,
		this->core_x_iram0_dram0_dma_split_line_constrain_3.pms_core_x_iram0_sram_line_1_category_1_x,
		this->core_x_iram0_dram0_dma_split_line_constrain_3.pms_core_x_iram0_sram_line_1_category_1_y
	);
	r = this->regSet(r, 
		this->core_x_iram0_dram0_dma_split_line_constrain_3.val,
		this->core_x_iram0_dram0_dma_split_line_constrain_3.pms_core_x_iram0_sram_line_1_category_0_x,
		this->core_x_iram0_dram0_dma_split_line_constrain_3.pms_core_x_iram0_sram_line_1_category_0_y
	);

	if(writeMode){
		this->regWrite(true, this->core_x_iram0_dram0_dma_split_line_constrain_3.base, r);
		this->init_core_x_iram0_dram0_dma_split_line_constrain_3();
	}else{
		this->core_x_iram0_dram0_dma_split_line_constrain_3.val = r;
	}
}
void PmsDebug::patch_core_x_iram0_dram0_dma_split_line_constrain_4(bool writeMode){
	uint32_t r = this->core_x_iram0_dram0_dma_split_line_constrain_4.val;
	r = this->regSet(r, 
		this->core_x_iram0_dram0_dma_split_line_constrain_4.val,
		this->core_x_iram0_dram0_dma_split_line_constrain_4.pms_core_x_dram0_dma_sram_line_0_splitaddr_x,
		this->core_x_iram0_dram0_dma_split_line_constrain_4.pms_core_x_dram0_dma_sram_line_0_splitaddr_y
	);
	r = this->regSet(r, 
		this->core_x_iram0_dram0_dma_split_line_constrain_4.val,
		this->core_x_iram0_dram0_dma_split_line_constrain_4.pms_core_x_dram0_dma_sram_line_0_category_6_x,
		this->core_x_iram0_dram0_dma_split_line_constrain_4.pms_core_x_dram0_dma_sram_line_0_category_6_y
	);
	r = this->regSet(r, 
		this->core_x_iram0_dram0_dma_split_line_constrain_4.val,
		this->core_x_iram0_dram0_dma_split_line_constrain_4.pms_core_x_dram0_dma_sram_line_0_category_5_x,
		this->core_x_iram0_dram0_dma_split_line_constrain_4.pms_core_x_dram0_dma_sram_line_0_category_5_y
	);
	r = this->regSet(r, 
		this->core_x_iram0_dram0_dma_split_line_constrain_4.val,
		this->core_x_iram0_dram0_dma_split_line_constrain_4.pms_core_x_dram0_dma_sram_line_0_category_4_x,
		this->core_x_iram0_dram0_dma_split_line_constrain_4.pms_core_x_dram0_dma_sram_line_0_category_4_y
	);
	r = this->regSet(r, 
		this->core_x_iram0_dram0_dma_split_line_constrain_4.val,
		this->core_x_iram0_dram0_dma_split_line_constrain_4.pms_core_x_dram0_dma_sram_line_0_category_3_x,
		this->core_x_iram0_dram0_dma_split_line_constrain_4.pms_core_x_dram0_dma_sram_line_0_category_3_y
	);
	r = this->regSet(r, 
		this->core_x_iram0_dram0_dma_split_line_constrain_4.val,
		this->core_x_iram0_dram0_dma_split_line_constrain_4.pms_core_x_dram0_dma_sram_line_0_category_2_x,
		this->core_x_iram0_dram0_dma_split_line_constrain_4.pms_core_x_dram0_dma_sram_line_0_category_2_y
	);
	r = this->regSet(r, 
		this->core_x_iram0_dram0_dma_split_line_constrain_4.val,
		this->core_x_iram0_dram0_dma_split_line_constrain_4.pms_core_x_dram0_dma_sram_line_0_category_1_x,
		this->core_x_iram0_dram0_dma_split_line_constrain_4.pms_core_x_dram0_dma_sram_line_0_category_1_y
	);
	r = this->regSet(r, 
		this->core_x_iram0_dram0_dma_split_line_constrain_4.val,
		this->core_x_iram0_dram0_dma_split_line_constrain_4.pms_core_x_dram0_dma_sram_line_0_category_0_x,
		this->core_x_iram0_dram0_dma_split_line_constrain_4.pms_core_x_dram0_dma_sram_line_0_category_0_y
	);

	if(writeMode){
		this->regWrite(true, this->core_x_iram0_dram0_dma_split_line_constrain_4.base, r);
		this->init_core_x_iram0_dram0_dma_split_line_constrain_4();
	}else{
		this->core_x_iram0_dram0_dma_split_line_constrain_4.val = r;
	}
}
void PmsDebug::patch_core_x_iram0_dram0_dma_split_line_constrain_5(bool writeMode){
	uint32_t r = this->core_x_iram0_dram0_dma_split_line_constrain_5.val;
	r = this->regSet(r, 
		this->core_x_iram0_dram0_dma_split_line_constrain_5.val,
		this->core_x_iram0_dram0_dma_split_line_constrain_5.pms_core_x_dram0_dma_sram_line_1_splitaddr_x,
		this->core_x_iram0_dram0_dma_split_line_constrain_5.pms_core_x_dram0_dma_sram_line_1_splitaddr_y
	);
	r = this->regSet(r, 
		this->core_x_iram0_dram0_dma_split_line_constrain_5.val,
		this->core_x_iram0_dram0_dma_split_line_constrain_5.pms_core_x_dram0_dma_sram_line_1_category_6_x,
		this->core_x_iram0_dram0_dma_split_line_constrain_5.pms_core_x_dram0_dma_sram_line_1_category_6_y
	);
	r = this->regSet(r, 
		this->core_x_iram0_dram0_dma_split_line_constrain_5.val,
		this->core_x_iram0_dram0_dma_split_line_constrain_5.pms_core_x_dram0_dma_sram_line_1_category_5_x,
		this->core_x_iram0_dram0_dma_split_line_constrain_5.pms_core_x_dram0_dma_sram_line_1_category_5_y
	);
	r = this->regSet(r, 
		this->core_x_iram0_dram0_dma_split_line_constrain_5.val,
		this->core_x_iram0_dram0_dma_split_line_constrain_5.pms_core_x_dram0_dma_sram_line_1_category_4_x,
		this->core_x_iram0_dram0_dma_split_line_constrain_5.pms_core_x_dram0_dma_sram_line_1_category_4_y
	);
	r = this->regSet(r, 
		this->core_x_iram0_dram0_dma_split_line_constrain_5.val,
		this->core_x_iram0_dram0_dma_split_line_constrain_5.pms_core_x_dram0_dma_sram_line_1_category_3_x,
		this->core_x_iram0_dram0_dma_split_line_constrain_5.pms_core_x_dram0_dma_sram_line_1_category_3_y
	);
	r = this->regSet(r, 
		this->core_x_iram0_dram0_dma_split_line_constrain_5.val,
		this->core_x_iram0_dram0_dma_split_line_constrain_5.pms_core_x_dram0_dma_sram_line_1_category_2_x,
		this->core_x_iram0_dram0_dma_split_line_constrain_5.pms_core_x_dram0_dma_sram_line_1_category_2_y
	);
	r = this->regSet(r, 
		this->core_x_iram0_dram0_dma_split_line_constrain_5.val,
		this->core_x_iram0_dram0_dma_split_line_constrain_5.pms_core_x_dram0_dma_sram_line_1_category_1_x,
		this->core_x_iram0_dram0_dma_split_line_constrain_5.pms_core_x_dram0_dma_sram_line_1_category_1_y
	);
	r = this->regSet(r, 
		this->core_x_iram0_dram0_dma_split_line_constrain_5.val,
		this->core_x_iram0_dram0_dma_split_line_constrain_5.pms_core_x_dram0_dma_sram_line_1_category_0_x,
		this->core_x_iram0_dram0_dma_split_line_constrain_5.pms_core_x_dram0_dma_sram_line_1_category_0_y
	);

	if(writeMode){
		this->regWrite(true, this->core_x_iram0_dram0_dma_split_line_constrain_5.base, r);
		this->init_core_x_iram0_dram0_dma_split_line_constrain_5();
	}else{
		this->core_x_iram0_dram0_dma_split_line_constrain_5.val = r;
	}
}
void PmsDebug::patch_core_x_iram0_pms_constrain_0(bool writeMode){
	uint32_t r = this->core_x_iram0_pms_constrain_0.val;
	r = this->regSet(r, 
		this->core_x_iram0_pms_constrain_0.val,
		this->core_x_iram0_pms_constrain_0.pms_core_x_iram0_pms_constrain_lock_pos
	);

	if(writeMode){
		this->regWrite(true, this->core_x_iram0_pms_constrain_0.base, r);
		this->init_core_x_iram0_pms_constrain_0();
	}else{
		this->core_x_iram0_pms_constrain_0.val = r;
	}
}
void PmsDebug::patch_core_x_iram0_pms_constrain_1(bool writeMode){
	uint32_t r = this->core_x_iram0_pms_constrain_1.val;
	r = this->regSet(r, 
		this->core_x_iram0_pms_constrain_1.val,
		this->core_x_iram0_pms_constrain_1.pms_core_x_iram0_pms_constrain_rom_world_1_pms_x,
		this->core_x_iram0_pms_constrain_1.pms_core_x_iram0_pms_constrain_rom_world_1_pms_y
	);
	r = this->regSet(r, 
		this->core_x_iram0_pms_constrain_1.val,
		this->core_x_iram0_pms_constrain_1.pms_core_x_iram0_pms_constrain_sram_world_1_cachedataarray_pms_1_x,
		this->core_x_iram0_pms_constrain_1.pms_core_x_iram0_pms_constrain_sram_world_1_cachedataarray_pms_1_y
	);
	r = this->regSet(r, 
		this->core_x_iram0_pms_constrain_1.val,
		this->core_x_iram0_pms_constrain_1.pms_core_x_iram0_pms_constrain_sram_world_1_cachedataarray_pms_0_x,
		this->core_x_iram0_pms_constrain_1.pms_core_x_iram0_pms_constrain_sram_world_1_cachedataarray_pms_0_y
	);
	r = this->regSet(r, 
		this->core_x_iram0_pms_constrain_1.val,
		this->core_x_iram0_pms_constrain_1.pms_core_x_iram0_pms_constrain_sram_world_1_pms_3_x,
		this->core_x_iram0_pms_constrain_1.pms_core_x_iram0_pms_constrain_sram_world_1_pms_3_y
	);
	r = this->regSet(r, 
		this->core_x_iram0_pms_constrain_1.val,
		this->core_x_iram0_pms_constrain_1.pms_core_x_iram0_pms_constrain_sram_world_1_pms_2_x,
		this->core_x_iram0_pms_constrain_1.pms_core_x_iram0_pms_constrain_sram_world_1_pms_2_y
	);
	r = this->regSet(r, 
		this->core_x_iram0_pms_constrain_1.val,
		this->core_x_iram0_pms_constrain_1.pms_core_x_iram0_pms_constrain_sram_world_1_pms_1_x,
		this->core_x_iram0_pms_constrain_1.pms_core_x_iram0_pms_constrain_sram_world_1_pms_1_y
	);
	r = this->regSet(r, 
		this->core_x_iram0_pms_constrain_1.val,
		this->core_x_iram0_pms_constrain_1.pms_core_x_iram0_pms_constrain_sram_world_1_pms_0_x,
		this->core_x_iram0_pms_constrain_1.pms_core_x_iram0_pms_constrain_sram_world_1_pms_0_y
	);

	if(writeMode){
		this->regWrite(true, this->core_x_iram0_pms_constrain_1.base, r);
		this->init_core_x_iram0_pms_constrain_1();
	}else{
		this->core_x_iram0_pms_constrain_1.val = r;
	}
}
void PmsDebug::patch_core_x_iram0_pms_constrain_2(bool writeMode){
	uint32_t r = this->core_x_iram0_pms_constrain_2.val;
	r = this->regSet(r, 
		this->core_x_iram0_pms_constrain_2.val,
		this->core_x_iram0_pms_constrain_2.pms_core_x_iram0_pms_constrain_rom_world_0_pms_x,
		this->core_x_iram0_pms_constrain_2.pms_core_x_iram0_pms_constrain_rom_world_0_pms_y
	);
	r = this->regSet(r, 
		this->core_x_iram0_pms_constrain_2.val,
		this->core_x_iram0_pms_constrain_2.pms_core_x_iram0_pms_constrain_sram_world_0_cachedataarray_pms_1_x,
		this->core_x_iram0_pms_constrain_2.pms_core_x_iram0_pms_constrain_sram_world_0_cachedataarray_pms_1_y
	);
	r = this->regSet(r, 
		this->core_x_iram0_pms_constrain_2.val,
		this->core_x_iram0_pms_constrain_2.pms_core_x_iram0_pms_constrain_sram_world_0_cachedataarray_pms_0_x,
		this->core_x_iram0_pms_constrain_2.pms_core_x_iram0_pms_constrain_sram_world_0_cachedataarray_pms_0_y
	);
	r = this->regSet(r, 
		this->core_x_iram0_pms_constrain_2.val,
		this->core_x_iram0_pms_constrain_2.pms_core_x_iram0_pms_constrain_sram_world_0_pms_3_x,
		this->core_x_iram0_pms_constrain_2.pms_core_x_iram0_pms_constrain_sram_world_0_pms_3_y
	);
	r = this->regSet(r, 
		this->core_x_iram0_pms_constrain_2.val,
		this->core_x_iram0_pms_constrain_2.pms_core_x_iram0_pms_constrain_sram_world_0_pms_2_x,
		this->core_x_iram0_pms_constrain_2.pms_core_x_iram0_pms_constrain_sram_world_0_pms_2_y
	);
	r = this->regSet(r, 
		this->core_x_iram0_pms_constrain_2.val,
		this->core_x_iram0_pms_constrain_2.pms_core_x_iram0_pms_constrain_sram_world_0_pms_1_x,
		this->core_x_iram0_pms_constrain_2.pms_core_x_iram0_pms_constrain_sram_world_0_pms_1_y
	);
	r = this->regSet(r, 
		this->core_x_iram0_pms_constrain_2.val,
		this->core_x_iram0_pms_constrain_2.pms_core_x_iram0_pms_constrain_sram_world_0_pms_0_x,
		this->core_x_iram0_pms_constrain_2.pms_core_x_iram0_pms_constrain_sram_world_0_pms_0_y
	);

	if(writeMode){
		this->regWrite(true, this->core_x_iram0_pms_constrain_2.base, r);
		this->init_core_x_iram0_pms_constrain_2();
	}else{
		this->core_x_iram0_pms_constrain_2.val = r;
	}
}
void PmsDebug::patch_core_0_iram0_pms_monitor_0(bool writeMode){
	uint32_t r = this->core_0_iram0_pms_monitor_0.val;
	r = this->regSet(r, 
		this->core_0_iram0_pms_monitor_0.val,
		this->core_0_iram0_pms_monitor_0.pms_core_0_iram0_pms_monitor_lock_pos
	);

	if(writeMode){
		this->regWrite(true, this->core_0_iram0_pms_monitor_0.base, r);
		this->init_core_0_iram0_pms_monitor_0();
	}else{
		this->core_0_iram0_pms_monitor_0.val = r;
	}
}
void PmsDebug::patch_core_0_iram0_pms_monitor_1(bool writeMode){
	uint32_t r = this->core_0_iram0_pms_monitor_1.val;
	r = this->regSet(r, 
		this->core_0_iram0_pms_monitor_1.val,
		this->core_0_iram0_pms_monitor_1.pms_core_0_iram0_pms_monitor_violate_en_pos
	);
	r = this->regSet(r, 
		this->core_0_iram0_pms_monitor_1.val,
		this->core_0_iram0_pms_monitor_1.pms_core_0_iram0_pms_monitor_violate_clr_pos
	);

	if(writeMode){
		this->regWrite(true, this->core_0_iram0_pms_monitor_1.base, r);
		this->init_core_0_iram0_pms_monitor_1();
	}else{
		this->core_0_iram0_pms_monitor_1.val = r;
	}
}
void PmsDebug::patch_core_x_dram0_pms_constrain_0(bool writeMode){
	uint32_t r = this->core_x_dram0_pms_constrain_0.val;
	r = this->regSet(r, 
		this->core_x_dram0_pms_constrain_0.val,
		this->core_x_dram0_pms_constrain_0.pms_core_x_dram0_pms_constrain_lock_pos
	);

	if(writeMode){
		this->regWrite(true, this->core_x_dram0_pms_constrain_0.base, r);
		this->init_core_x_dram0_pms_constrain_0();
	}else{
		this->core_x_dram0_pms_constrain_0.val = r;
	}
}
void PmsDebug::patch_core_x_dram0_pms_constrain_1(bool writeMode){
	uint32_t r = this->core_x_dram0_pms_constrain_1.val;
	r = this->regSet(r, 
		this->core_x_dram0_pms_constrain_1.val,
		this->core_x_dram0_pms_constrain_1.pms_core_x_dram0_pms_constrain_rom_world_1_pms_x,
		this->core_x_dram0_pms_constrain_1.pms_core_x_dram0_pms_constrain_rom_world_1_pms_y
	);
	r = this->regSet(r, 
		this->core_x_dram0_pms_constrain_1.val,
		this->core_x_dram0_pms_constrain_1.pms_core_x_dram0_pms_constrain_rom_world_0_pms_x,
		this->core_x_dram0_pms_constrain_1.pms_core_x_dram0_pms_constrain_rom_world_0_pms_y
	);
	r = this->regSet(r, 
		this->core_x_dram0_pms_constrain_1.val,
		this->core_x_dram0_pms_constrain_1.pms_core_x_dram0_pms_constrain_sram_world_1_cachedataarray_pms_1_x,
		this->core_x_dram0_pms_constrain_1.pms_core_x_dram0_pms_constrain_sram_world_1_cachedataarray_pms_1_y
	);
	r = this->regSet(r, 
		this->core_x_dram0_pms_constrain_1.val,
		this->core_x_dram0_pms_constrain_1.pms_core_x_dram0_pms_constrain_sram_world_1_cachedataarray_pms_0_x,
		this->core_x_dram0_pms_constrain_1.pms_core_x_dram0_pms_constrain_sram_world_1_cachedataarray_pms_0_y
	);
	r = this->regSet(r, 
		this->core_x_dram0_pms_constrain_1.val,
		this->core_x_dram0_pms_constrain_1.pms_core_x_dram0_pms_constrain_sram_world_1_pms_3_x,
		this->core_x_dram0_pms_constrain_1.pms_core_x_dram0_pms_constrain_sram_world_1_pms_3_y
	);
	r = this->regSet(r, 
		this->core_x_dram0_pms_constrain_1.val,
		this->core_x_dram0_pms_constrain_1.pms_core_x_dram0_pms_constrain_sram_world_1_pms_2_x,
		this->core_x_dram0_pms_constrain_1.pms_core_x_dram0_pms_constrain_sram_world_1_pms_2_y
	);
	r = this->regSet(r, 
		this->core_x_dram0_pms_constrain_1.val,
		this->core_x_dram0_pms_constrain_1.pms_core_x_dram0_pms_constrain_sram_world_1_pms_1_x,
		this->core_x_dram0_pms_constrain_1.pms_core_x_dram0_pms_constrain_sram_world_1_pms_1_y
	);
	r = this->regSet(r, 
		this->core_x_dram0_pms_constrain_1.val,
		this->core_x_dram0_pms_constrain_1.pms_core_x_dram0_pms_constrain_sram_world_1_pms_0_x,
		this->core_x_dram0_pms_constrain_1.pms_core_x_dram0_pms_constrain_sram_world_1_pms_0_y
	);
	r = this->regSet(r, 
		this->core_x_dram0_pms_constrain_1.val,
		this->core_x_dram0_pms_constrain_1.pms_core_x_dram0_pms_constrain_sram_world_0_cachedataarray_pms_1_x,
		this->core_x_dram0_pms_constrain_1.pms_core_x_dram0_pms_constrain_sram_world_0_cachedataarray_pms_1_y
	);
	r = this->regSet(r, 
		this->core_x_dram0_pms_constrain_1.val,
		this->core_x_dram0_pms_constrain_1.pms_core_x_dram0_pms_constrain_sram_world_0_cachedataarray_pms_0_x,
		this->core_x_dram0_pms_constrain_1.pms_core_x_dram0_pms_constrain_sram_world_0_cachedataarray_pms_0_y
	);
	r = this->regSet(r, 
		this->core_x_dram0_pms_constrain_1.val,
		this->core_x_dram0_pms_constrain_1.pms_core_x_dram0_pms_constrain_sram_world_0_pms_3_x,
		this->core_x_dram0_pms_constrain_1.pms_core_x_dram0_pms_constrain_sram_world_0_pms_3_y
	);
	r = this->regSet(r, 
		this->core_x_dram0_pms_constrain_1.val,
		this->core_x_dram0_pms_constrain_1.pms_core_x_dram0_pms_constrain_sram_world_0_pms_2_x,
		this->core_x_dram0_pms_constrain_1.pms_core_x_dram0_pms_constrain_sram_world_0_pms_2_y
	);
	r = this->regSet(r, 
		this->core_x_dram0_pms_constrain_1.val,
		this->core_x_dram0_pms_constrain_1.pms_core_x_dram0_pms_constrain_sram_world_0_pms_1_x,
		this->core_x_dram0_pms_constrain_1.pms_core_x_dram0_pms_constrain_sram_world_0_pms_1_y
	);
	r = this->regSet(r, 
		this->core_x_dram0_pms_constrain_1.val,
		this->core_x_dram0_pms_constrain_1.pms_core_x_dram0_pms_constrain_sram_world_0_pms_0_x,
		this->core_x_dram0_pms_constrain_1.pms_core_x_dram0_pms_constrain_sram_world_0_pms_0_y
	);

	if(writeMode){
		this->regWrite(true, this->core_x_dram0_pms_constrain_1.base, r);
		this->init_core_x_dram0_pms_constrain_1();
	}else{
		this->core_x_dram0_pms_constrain_1.val = r;
	}
}
void PmsDebug::patch_core_0_dram0_pms_monitor_0(bool writeMode){
	uint32_t r = this->core_0_dram0_pms_monitor_0.val;
	r = this->regSet(r, 
		this->core_0_dram0_pms_monitor_0.val,
		this->core_0_dram0_pms_monitor_0.pms_core_0_dram0_pms_monitor_lock_pos
	);

	if(writeMode){
		this->regWrite(true, this->core_0_dram0_pms_monitor_0.base, r);
		this->init_core_0_dram0_pms_monitor_0();
	}else{
		this->core_0_dram0_pms_monitor_0.val = r;
	}
}
void PmsDebug::patch_core_0_dram0_pms_monitor_1(bool writeMode){
	uint32_t r = this->core_0_dram0_pms_monitor_1.val;
	r = this->regSet(r, 
		this->core_0_dram0_pms_monitor_1.val,
		this->core_0_dram0_pms_monitor_1.pms_core_0_dram0_pms_monitor_violate_en_pos
	);
	r = this->regSet(r, 
		this->core_0_dram0_pms_monitor_1.val,
		this->core_0_dram0_pms_monitor_1.pms_core_0_dram0_pms_monitor_violate_clr_pos
	);

	if(writeMode){
		this->regWrite(true, this->core_0_dram0_pms_monitor_1.base, r);
		this->init_core_0_dram0_pms_monitor_1();
	}else{
		this->core_0_dram0_pms_monitor_1.val = r;
	}
}
void PmsDebug::patch_core_0_pif_pms_constrain_0(bool writeMode){
	uint32_t r = this->core_0_pif_pms_constrain_0.val;
	r = this->regSet(r, 
		this->core_0_pif_pms_constrain_0.val,
		this->core_0_pif_pms_constrain_0.pms_core_0_pif_pms_constrain_lock_pos
	);

	if(writeMode){
		this->regWrite(true, this->core_0_pif_pms_constrain_0.base, r);
		this->init_core_0_pif_pms_constrain_0();
	}else{
		this->core_0_pif_pms_constrain_0.val = r;
	}
}
void PmsDebug::patch_core_0_pif_pms_constrain_n(bool writeMode){
	uint32_t r = this->core_0_pif_pms_constrain_n.val;
	r = this->regSet(r, 
		this->core_0_pif_pms_constrain_n.val,
		this->core_0_pif_pms_constrain_n.pms_core_0_pif_pms_constrain_world_0_uart1_x,
		this->core_0_pif_pms_constrain_n.pms_core_0_pif_pms_constrain_world_0_uart1_y
	);
	r = this->regSet(r, 
		this->core_0_pif_pms_constrain_n.val,
		this->core_0_pif_pms_constrain_n.pms_core_0_pif_pms_constrain_world_0_i2s0_x,
		this->core_0_pif_pms_constrain_n.pms_core_0_pif_pms_constrain_world_0_i2s0_y
	);
	r = this->regSet(r, 
		this->core_0_pif_pms_constrain_n.val,
		this->core_0_pif_pms_constrain_n.pms_core_0_pif_pms_constrain_world_0_io_mux_x,
		this->core_0_pif_pms_constrain_n.pms_core_0_pif_pms_constrain_world_0_io_mux_y
	);
	r = this->regSet(r, 
		this->core_0_pif_pms_constrain_n.val,
		this->core_0_pif_pms_constrain_n.pms_core_0_pif_pms_constrain_world_0_rtc_x,
		this->core_0_pif_pms_constrain_n.pms_core_0_pif_pms_constrain_world_0_rtc_y
	);
	r = this->regSet(r, 
		this->core_0_pif_pms_constrain_n.val,
		this->core_0_pif_pms_constrain_n.pms_core_0_pif_pms_constrain_world_0_gpio_x,
		this->core_0_pif_pms_constrain_n.pms_core_0_pif_pms_constrain_world_0_gpio_y
	);
	r = this->regSet(r, 
		this->core_0_pif_pms_constrain_n.val,
		this->core_0_pif_pms_constrain_n.pms_core_0_pif_pms_constrain_world_0_g0spi_0_x,
		this->core_0_pif_pms_constrain_n.pms_core_0_pif_pms_constrain_world_0_g0spi_0_y
	);
	r = this->regSet(r, 
		this->core_0_pif_pms_constrain_n.val,
		this->core_0_pif_pms_constrain_n.pms_core_0_pif_pms_constrain_world_0_g0spi_1_x,
		this->core_0_pif_pms_constrain_n.pms_core_0_pif_pms_constrain_world_0_g0spi_1_y
	);
	r = this->regSet(r, 
		this->core_0_pif_pms_constrain_n.val,
		this->core_0_pif_pms_constrain_n.pms_core_0_pif_pms_constrain_world_0_uart_x,
		this->core_0_pif_pms_constrain_n.pms_core_0_pif_pms_constrain_world_0_uart_y
	);

	if(writeMode){
		this->regWrite(true, this->core_0_pif_pms_constrain_n.base, r);
		this->init_core_0_pif_pms_constrain_n();
	}else{
		this->core_0_pif_pms_constrain_n.val = r;
	}
}
void PmsDebug::patch_core_0_pif_pms_constrain_9(bool writeMode){
	uint32_t r = this->core_0_pif_pms_constrain_9.val;
	r = this->regSet(r, 
		this->core_0_pif_pms_constrain_9.val,
		this->core_0_pif_pms_constrain_9.pms_core_0_pif_pms_constrain_rtcfast_spltaddr_world_1_x,
		this->core_0_pif_pms_constrain_9.pms_core_0_pif_pms_constrain_rtcfast_spltaddr_world_1_y
	);
	r = this->regSet(r, 
		this->core_0_pif_pms_constrain_9.val,
		this->core_0_pif_pms_constrain_9.pms_core_0_pif_pms_constrain_rtcfast_spltaddr_world_0_x,
		this->core_0_pif_pms_constrain_9.pms_core_0_pif_pms_constrain_rtcfast_spltaddr_world_0_y
	);

	if(writeMode){
		this->regWrite(true, this->core_0_pif_pms_constrain_9.base, r);
		this->init_core_0_pif_pms_constrain_9();
	}else{
		this->core_0_pif_pms_constrain_9.val = r;
	}
}
void PmsDebug::patch_core_0_pif_pms_constrain_10(bool writeMode){
	uint32_t r = this->core_0_pif_pms_constrain_10.val;
	r = this->regSet(r, 
		this->core_0_pif_pms_constrain_10.val,
		this->core_0_pif_pms_constrain_10.pms_core_0_pif_pms_constrain_rtcfast_world_1_h_x,
		this->core_0_pif_pms_constrain_10.pms_core_0_pif_pms_constrain_rtcfast_world_1_h_y
	);
	r = this->regSet(r, 
		this->core_0_pif_pms_constrain_10.val,
		this->core_0_pif_pms_constrain_10.pms_core_0_pif_pms_constrain_rtcfast_world_1_l_x,
		this->core_0_pif_pms_constrain_10.pms_core_0_pif_pms_constrain_rtcfast_world_1_l_y
	);
	r = this->regSet(r, 
		this->core_0_pif_pms_constrain_10.val,
		this->core_0_pif_pms_constrain_10.pms_core_0_pif_pms_constrain_rtcfast_world_0_h_x,
		this->core_0_pif_pms_constrain_10.pms_core_0_pif_pms_constrain_rtcfast_world_0_h_y
	);
	r = this->regSet(r, 
		this->core_0_pif_pms_constrain_10.val,
		this->core_0_pif_pms_constrain_10.pms_core_0_pif_pms_constrain_rtcfast_world_0_l_x,
		this->core_0_pif_pms_constrain_10.pms_core_0_pif_pms_constrain_rtcfast_world_0_l_y
	);

	if(writeMode){
		this->regWrite(true, this->core_0_pif_pms_constrain_10.base, r);
		this->init_core_0_pif_pms_constrain_10();
	}else{
		this->core_0_pif_pms_constrain_10.val = r;
	}
}
void PmsDebug::patch_core_0_pif_pms_constrain_11(bool writeMode){
	uint32_t r = this->core_0_pif_pms_constrain_11.val;
	r = this->regSet(r, 
		this->core_0_pif_pms_constrain_11.val,
		this->core_0_pif_pms_constrain_11.pms_core_0_pif_pms_constrain_rtcslow_0_spltaddr_world_1_x,
		this->core_0_pif_pms_constrain_11.pms_core_0_pif_pms_constrain_rtcslow_0_spltaddr_world_1_y
	);
	r = this->regSet(r, 
		this->core_0_pif_pms_constrain_11.val,
		this->core_0_pif_pms_constrain_11.pms_core_0_pif_pms_constrain_rtcslow_0_spltaddr_world_0_x,
		this->core_0_pif_pms_constrain_11.pms_core_0_pif_pms_constrain_rtcslow_0_spltaddr_world_0_y
	);

	if(writeMode){
		this->regWrite(true, this->core_0_pif_pms_constrain_11.base, r);
		this->init_core_0_pif_pms_constrain_11();
	}else{
		this->core_0_pif_pms_constrain_11.val = r;
	}
}
void PmsDebug::patch_core_0_pif_pms_constrain_12(bool writeMode){
	uint32_t r = this->core_0_pif_pms_constrain_12.val;
	r = this->regSet(r, 
		this->core_0_pif_pms_constrain_12.val,
		this->core_0_pif_pms_constrain_12.pms_core_0_pif_pms_constrain_rtcslow_0_world_1_h_x,
		this->core_0_pif_pms_constrain_12.pms_core_0_pif_pms_constrain_rtcslow_0_world_1_h_y
	);
	r = this->regSet(r, 
		this->core_0_pif_pms_constrain_12.val,
		this->core_0_pif_pms_constrain_12.pms_core_0_pif_pms_constrain_rtcslow_0_world_1_l_x,
		this->core_0_pif_pms_constrain_12.pms_core_0_pif_pms_constrain_rtcslow_0_world_1_l_y
	);
	r = this->regSet(r, 
		this->core_0_pif_pms_constrain_12.val,
		this->core_0_pif_pms_constrain_12.pms_core_0_pif_pms_constrain_rtcslow_0_world_0_h_x,
		this->core_0_pif_pms_constrain_12.pms_core_0_pif_pms_constrain_rtcslow_0_world_0_h_y
	);
	r = this->regSet(r, 
		this->core_0_pif_pms_constrain_12.val,
		this->core_0_pif_pms_constrain_12.pms_core_0_pif_pms_constrain_rtcslow_0_world_0_l_x,
		this->core_0_pif_pms_constrain_12.pms_core_0_pif_pms_constrain_rtcslow_0_world_0_l_y
	);

	if(writeMode){
		this->regWrite(true, this->core_0_pif_pms_constrain_12.base, r);
		this->init_core_0_pif_pms_constrain_12();
	}else{
		this->core_0_pif_pms_constrain_12.val = r;
	}
}
void PmsDebug::patch_core_0_pif_pms_constrain_13(bool writeMode){
	uint32_t r = this->core_0_pif_pms_constrain_13.val;
	r = this->regSet(r, 
		this->core_0_pif_pms_constrain_13.val,
		this->core_0_pif_pms_constrain_13.pms_core_0_pif_pms_constrain_rtcslow_1_spltaddr_world_1_x,
		this->core_0_pif_pms_constrain_13.pms_core_0_pif_pms_constrain_rtcslow_1_spltaddr_world_1_y
	);
	r = this->regSet(r, 
		this->core_0_pif_pms_constrain_13.val,
		this->core_0_pif_pms_constrain_13.pms_core_0_pif_pms_constrain_rtcslow_1_spltaddr_world_0_x,
		this->core_0_pif_pms_constrain_13.pms_core_0_pif_pms_constrain_rtcslow_1_spltaddr_world_0_y
	);

	if(writeMode){
		this->regWrite(true, this->core_0_pif_pms_constrain_13.base, r);
		this->init_core_0_pif_pms_constrain_13();
	}else{
		this->core_0_pif_pms_constrain_13.val = r;
	}
}
void PmsDebug::patch_core_0_pif_pms_constrain_14(bool writeMode){
	uint32_t r = this->core_0_pif_pms_constrain_14.val;
	r = this->regSet(r, 
		this->core_0_pif_pms_constrain_14.val,
		this->core_0_pif_pms_constrain_14.pms_core_0_pif_pms_constrain_rtcslow_1_world_1_h_x,
		this->core_0_pif_pms_constrain_14.pms_core_0_pif_pms_constrain_rtcslow_1_world_1_h_y
	);
	r = this->regSet(r, 
		this->core_0_pif_pms_constrain_14.val,
		this->core_0_pif_pms_constrain_14.pms_core_0_pif_pms_constrain_rtcslow_1_world_1_l_x,
		this->core_0_pif_pms_constrain_14.pms_core_0_pif_pms_constrain_rtcslow_1_world_1_l_y
	);
	r = this->regSet(r, 
		this->core_0_pif_pms_constrain_14.val,
		this->core_0_pif_pms_constrain_14.pms_core_0_pif_pms_constrain_rtcslow_1_world_0_h_x,
		this->core_0_pif_pms_constrain_14.pms_core_0_pif_pms_constrain_rtcslow_1_world_0_h_y
	);
	r = this->regSet(r, 
		this->core_0_pif_pms_constrain_14.val,
		this->core_0_pif_pms_constrain_14.pms_core_0_pif_pms_constrain_rtcslow_1_world_0_l_x,
		this->core_0_pif_pms_constrain_14.pms_core_0_pif_pms_constrain_rtcslow_1_world_0_l_y
	);

	if(writeMode){
		this->regWrite(true, this->core_0_pif_pms_constrain_14.base, r);
		this->init_core_0_pif_pms_constrain_14();
	}else{
		this->core_0_pif_pms_constrain_14.val = r;
	}
}
void PmsDebug::patch_core_0_region_pms_constrain_0(bool writeMode){
	uint32_t r = this->core_0_region_pms_constrain_0.val;
	r = this->regSet(r, 
		this->core_0_region_pms_constrain_0.val,
		this->core_0_region_pms_constrain_0.pms_core_0_region_pms_constrain_lock_pos
	);

	if(writeMode){
		this->regWrite(true, this->core_0_region_pms_constrain_0.base, r);
		this->init_core_0_region_pms_constrain_0();
	}else{
		this->core_0_region_pms_constrain_0.val = r;
	}
}
void PmsDebug::patch_core_0_region_pms_constrain_1(bool writeMode){
	uint32_t r = this->core_0_region_pms_constrain_1.val;
	r = this->regSet(r, 
		this->core_0_region_pms_constrain_1.val,
		this->core_0_region_pms_constrain_1.pms_core_0_region_pms_constrain_world_0_area_10_x,
		this->core_0_region_pms_constrain_1.pms_core_0_region_pms_constrain_world_0_area_10_y
	);
	r = this->regSet(r, 
		this->core_0_region_pms_constrain_1.val,
		this->core_0_region_pms_constrain_1.pms_core_0_region_pms_constrain_world_0_area_9_x,
		this->core_0_region_pms_constrain_1.pms_core_0_region_pms_constrain_world_0_area_9_y
	);
	r = this->regSet(r, 
		this->core_0_region_pms_constrain_1.val,
		this->core_0_region_pms_constrain_1.pms_core_0_region_pms_constrain_world_0_area_8_x,
		this->core_0_region_pms_constrain_1.pms_core_0_region_pms_constrain_world_0_area_8_y
	);
	r = this->regSet(r, 
		this->core_0_region_pms_constrain_1.val,
		this->core_0_region_pms_constrain_1.pms_core_0_region_pms_constrain_world_0_area_7_x,
		this->core_0_region_pms_constrain_1.pms_core_0_region_pms_constrain_world_0_area_7_y
	);
	r = this->regSet(r, 
		this->core_0_region_pms_constrain_1.val,
		this->core_0_region_pms_constrain_1.pms_core_0_region_pms_constrain_world_0_area_6_x,
		this->core_0_region_pms_constrain_1.pms_core_0_region_pms_constrain_world_0_area_6_y
	);
	r = this->regSet(r, 
		this->core_0_region_pms_constrain_1.val,
		this->core_0_region_pms_constrain_1.pms_core_0_region_pms_constrain_world_0_area_5_x,
		this->core_0_region_pms_constrain_1.pms_core_0_region_pms_constrain_world_0_area_5_y
	);
	r = this->regSet(r, 
		this->core_0_region_pms_constrain_1.val,
		this->core_0_region_pms_constrain_1.pms_core_0_region_pms_constrain_world_0_area_4_x,
		this->core_0_region_pms_constrain_1.pms_core_0_region_pms_constrain_world_0_area_4_y
	);
	r = this->regSet(r, 
		this->core_0_region_pms_constrain_1.val,
		this->core_0_region_pms_constrain_1.pms_core_0_region_pms_constrain_world_0_area_3_x,
		this->core_0_region_pms_constrain_1.pms_core_0_region_pms_constrain_world_0_area_3_y
	);
	r = this->regSet(r, 
		this->core_0_region_pms_constrain_1.val,
		this->core_0_region_pms_constrain_1.pms_core_0_region_pms_constrain_world_0_area_2_x,
		this->core_0_region_pms_constrain_1.pms_core_0_region_pms_constrain_world_0_area_2_y
	);
	r = this->regSet(r, 
		this->core_0_region_pms_constrain_1.val,
		this->core_0_region_pms_constrain_1.pms_core_0_region_pms_constrain_world_0_area_1_x,
		this->core_0_region_pms_constrain_1.pms_core_0_region_pms_constrain_world_0_area_1_y
	);
	r = this->regSet(r, 
		this->core_0_region_pms_constrain_1.val,
		this->core_0_region_pms_constrain_1.pms_core_0_region_pms_constrain_world_0_area_0_x,
		this->core_0_region_pms_constrain_1.pms_core_0_region_pms_constrain_world_0_area_0_y
	);

	if(writeMode){
		this->regWrite(true, this->core_0_region_pms_constrain_1.base, r);
		this->init_core_0_region_pms_constrain_1();
	}else{
		this->core_0_region_pms_constrain_1.val = r;
	}
}
void PmsDebug::patch_core_0_region_pms_constrain_2(bool writeMode){
	uint32_t r = this->core_0_region_pms_constrain_2.val;
	r = this->regSet(r, 
		this->core_0_region_pms_constrain_2.val,
		this->core_0_region_pms_constrain_2.pms_core_0_region_pms_constrain_world_1_area_10_x,
		this->core_0_region_pms_constrain_2.pms_core_0_region_pms_constrain_world_1_area_10_y
	);
	r = this->regSet(r, 
		this->core_0_region_pms_constrain_2.val,
		this->core_0_region_pms_constrain_2.pms_core_0_region_pms_constrain_world_1_area_9_x,
		this->core_0_region_pms_constrain_2.pms_core_0_region_pms_constrain_world_1_area_9_y
	);
	r = this->regSet(r, 
		this->core_0_region_pms_constrain_2.val,
		this->core_0_region_pms_constrain_2.pms_core_0_region_pms_constrain_world_1_area_8_x,
		this->core_0_region_pms_constrain_2.pms_core_0_region_pms_constrain_world_1_area_8_y
	);
	r = this->regSet(r, 
		this->core_0_region_pms_constrain_2.val,
		this->core_0_region_pms_constrain_2.pms_core_0_region_pms_constrain_world_1_area_7_x,
		this->core_0_region_pms_constrain_2.pms_core_0_region_pms_constrain_world_1_area_7_y
	);
	r = this->regSet(r, 
		this->core_0_region_pms_constrain_2.val,
		this->core_0_region_pms_constrain_2.pms_core_0_region_pms_constrain_world_1_area_6_x,
		this->core_0_region_pms_constrain_2.pms_core_0_region_pms_constrain_world_1_area_6_y
	);
	r = this->regSet(r, 
		this->core_0_region_pms_constrain_2.val,
		this->core_0_region_pms_constrain_2.pms_core_0_region_pms_constrain_world_1_area_5_x,
		this->core_0_region_pms_constrain_2.pms_core_0_region_pms_constrain_world_1_area_5_y
	);
	r = this->regSet(r, 
		this->core_0_region_pms_constrain_2.val,
		this->core_0_region_pms_constrain_2.pms_core_0_region_pms_constrain_world_1_area_4_x,
		this->core_0_region_pms_constrain_2.pms_core_0_region_pms_constrain_world_1_area_4_y
	);
	r = this->regSet(r, 
		this->core_0_region_pms_constrain_2.val,
		this->core_0_region_pms_constrain_2.pms_core_0_region_pms_constrain_world_1_area_3_x,
		this->core_0_region_pms_constrain_2.pms_core_0_region_pms_constrain_world_1_area_3_y
	);
	r = this->regSet(r, 
		this->core_0_region_pms_constrain_2.val,
		this->core_0_region_pms_constrain_2.pms_core_0_region_pms_constrain_world_1_area_2_x,
		this->core_0_region_pms_constrain_2.pms_core_0_region_pms_constrain_world_1_area_2_y
	);
	r = this->regSet(r, 
		this->core_0_region_pms_constrain_2.val,
		this->core_0_region_pms_constrain_2.pms_core_0_region_pms_constrain_world_1_area_1_x,
		this->core_0_region_pms_constrain_2.pms_core_0_region_pms_constrain_world_1_area_1_y
	);
	r = this->regSet(r, 
		this->core_0_region_pms_constrain_2.val,
		this->core_0_region_pms_constrain_2.pms_core_0_region_pms_constrain_world_1_area_0_x,
		this->core_0_region_pms_constrain_2.pms_core_0_region_pms_constrain_world_1_area_0_y
	);

	if(writeMode){
		this->regWrite(true, this->core_0_region_pms_constrain_2.base, r);
		this->init_core_0_region_pms_constrain_2();
	}else{
		this->core_0_region_pms_constrain_2.val = r;
	}
}
void PmsDebug::patch_core_0_region_pms_constrain_n(bool writeMode){
	uint32_t r = this->core_0_region_pms_constrain_n.val;
	r = this->regSet(r, 
		this->core_0_region_pms_constrain_n.val,
		this->core_0_region_pms_constrain_n.pms_core_0_region_pms_constrain_addr_0_x,
		this->core_0_region_pms_constrain_n.pms_core_0_region_pms_constrain_addr_0_y
	);

	if(writeMode){
		this->regWrite(true, this->core_0_region_pms_constrain_n.base, r);
		this->init_core_0_region_pms_constrain_n();
	}else{
		this->core_0_region_pms_constrain_n.val = r;
	}
}
void PmsDebug::patch_core_0_pif_pms_monitor_0(bool writeMode){
	uint32_t r = this->core_0_pif_pms_monitor_0.val;
	r = this->regSet(r, 
		this->core_0_pif_pms_monitor_0.val,
		this->core_0_pif_pms_monitor_0.pms_core_0_pif_pms_monitor_lock_pos
	);

	if(writeMode){
		this->regWrite(true, this->core_0_pif_pms_monitor_0.base, r);
		this->init_core_0_pif_pms_monitor_0();
	}else{
		this->core_0_pif_pms_monitor_0.val = r;
	}
}
void PmsDebug::patch_core_0_pif_pms_monitor_1(bool writeMode){
	uint32_t r = this->core_0_pif_pms_monitor_1.val;
	r = this->regSet(r, 
		this->core_0_pif_pms_monitor_1.val,
		this->core_0_pif_pms_monitor_1.pms_core_0_pif_pms_monitor_violate_en_pos
	);
	r = this->regSet(r, 
		this->core_0_pif_pms_monitor_1.val,
		this->core_0_pif_pms_monitor_1.pms_core_0_pif_pms_monitor_violate_clr_pos
	);

	if(writeMode){
		this->regWrite(true, this->core_0_pif_pms_monitor_1.base, r);
		this->init_core_0_pif_pms_monitor_1();
	}else{
		this->core_0_pif_pms_monitor_1.val = r;
	}
}
void PmsDebug::patch_core_0_pif_pms_monitor_4(bool writeMode){
	uint32_t r = this->core_0_pif_pms_monitor_4.val;
	r = this->regSet(r, 
		this->core_0_pif_pms_monitor_4.val,
		this->core_0_pif_pms_monitor_4.pms_core_0_pif_pms_monitor_nonword_violate_en_pos
	);
	r = this->regSet(r, 
		this->core_0_pif_pms_monitor_4.val,
		this->core_0_pif_pms_monitor_4.pms_core_0_pif_pms_monitor_nonword_violate_clr_pos
	);

	if(writeMode){
		this->regWrite(true, this->core_0_pif_pms_monitor_4.base, r);
		this->init_core_0_pif_pms_monitor_4();
	}else{
		this->core_0_pif_pms_monitor_4.val = r;
	}
}
void PmsDebug::patch_core_0_vecbase_override_lock(bool writeMode){
	uint32_t r = this->core_0_vecbase_override_lock.val;
	r = this->regSet(r, 
		this->core_0_vecbase_override_lock.val,
		this->core_0_vecbase_override_lock.pms_core_0_vecbase_override_lock_pos
	);

	if(writeMode){
		this->regWrite(true, this->core_0_vecbase_override_lock.base, r);
		this->init_core_0_vecbase_override_lock();
	}else{
		this->core_0_vecbase_override_lock.val = r;
	}
}
void PmsDebug::patch_core_0_vecbase_override_0(bool writeMode){
	uint32_t r = this->core_0_vecbase_override_0.val;
	r = this->regSet(r, 
		this->core_0_vecbase_override_0.val,
		this->core_0_vecbase_override_0.pms_core_0_vecbase_world_mask_pos
	);

	if(writeMode){
		this->regWrite(true, this->core_0_vecbase_override_0.base, r);
		this->init_core_0_vecbase_override_0();
	}else{
		this->core_0_vecbase_override_0.val = r;
	}
}
void PmsDebug::patch_core_0_vecbase_override_1(bool writeMode){
	uint32_t r = this->core_0_vecbase_override_1.val;
	r = this->regSet(r, 
		this->core_0_vecbase_override_1.val,
		this->core_0_vecbase_override_1.pms_core_0_vecbase_override_sel_x,
		this->core_0_vecbase_override_1.pms_core_0_vecbase_override_sel_y
	);
	r = this->regSet(r, 
		this->core_0_vecbase_override_1.val,
		this->core_0_vecbase_override_1.pms_core_0_vecbase_override_world0_value_x,
		this->core_0_vecbase_override_1.pms_core_0_vecbase_override_world0_value_y
	);

	if(writeMode){
		this->regWrite(true, this->core_0_vecbase_override_1.base, r);
		this->init_core_0_vecbase_override_1();
	}else{
		this->core_0_vecbase_override_1.val = r;
	}
}
void PmsDebug::patch_core_0_vecbase_override_2(bool writeMode){
	uint32_t r = this->core_0_vecbase_override_2.val;
	r = this->regSet(r, 
		this->core_0_vecbase_override_2.val,
		this->core_0_vecbase_override_2.pms_core_0_vecbase_override_world1_value_x,
		this->core_0_vecbase_override_2.pms_core_0_vecbase_override_world1_value_y
	);

	if(writeMode){
		this->regWrite(true, this->core_0_vecbase_override_2.base, r);
		this->init_core_0_vecbase_override_2();
	}else{
		this->core_0_vecbase_override_2.val = r;
	}
}
void PmsDebug::patch_edma_boundary_lock(bool writeMode){
	uint32_t r = this->edma_boundary_lock.val;
	r = this->regSet(r, 
		this->edma_boundary_lock.val,
		this->edma_boundary_lock.pms_edma_boundary_lock_pos
	);

	if(writeMode){
		this->regWrite(true, this->edma_boundary_lock.base, r);
		this->init_edma_boundary_lock();
	}else{
		this->edma_boundary_lock.val = r;
	}
}
void PmsDebug::patch_edma_boundary_0(bool writeMode){
	uint32_t r = this->edma_boundary_0.val;
	r = this->regSet(r, 
		this->edma_boundary_0.val,
		this->edma_boundary_0.pms_edma_boundary_0_x,
		this->edma_boundary_0.pms_edma_boundary_0_y
	);

	if(writeMode){
		this->regWrite(true, this->edma_boundary_0.base, r);
		this->init_edma_boundary_0();
	}else{
		this->edma_boundary_0.val = r;
	}
}
void PmsDebug::patch_edma_boundary_1(bool writeMode){
	uint32_t r = this->edma_boundary_1.val;
	r = this->regSet(r, 
		this->edma_boundary_1.val,
		this->edma_boundary_1.pms_edma_boundary_1_x,
		this->edma_boundary_1.pms_edma_boundary_1_y
	);

	if(writeMode){
		this->regWrite(true, this->edma_boundary_1.base, r);
		this->init_edma_boundary_1();
	}else{
		this->edma_boundary_1.val = r;
	}
}
void PmsDebug::patch_edma_boundary_2(bool writeMode){
	uint32_t r = this->edma_boundary_2.val;
	r = this->regSet(r, 
		this->edma_boundary_2.val,
		this->edma_boundary_2.pms_edma_boundary_2_x,
		this->edma_boundary_2.pms_edma_boundary_2_y
	);

	if(writeMode){
		this->regWrite(true, this->edma_boundary_2.base, r);
		this->init_edma_boundary_2();
	}else{
		this->edma_boundary_2.val = r;
	}
}
void PmsDebug::patch_edma_pms_spi2_lock(bool writeMode){
	uint32_t r = this->edma_pms_spi2_lock.val;
	r = this->regSet(r, 
		this->edma_pms_spi2_lock.val,
		this->edma_pms_spi2_lock.pms_edma_pms_spi2_lock_pos
	);

	if(writeMode){
		this->regWrite(true, this->edma_pms_spi2_lock.base, r);
		this->init_edma_pms_spi2_lock();
	}else{
		this->edma_pms_spi2_lock.val = r;
	}
}
void PmsDebug::patch_edma_pms_spi2(bool writeMode){
	uint32_t r = this->edma_pms_spi2.val;
	r = this->regSet(r, 
		this->edma_pms_spi2.val,
		this->edma_pms_spi2.pms_edma_pms_spi2_attr2_x,
		this->edma_pms_spi2.pms_edma_pms_spi2_attr2_y
	);
	r = this->regSet(r, 
		this->edma_pms_spi2.val,
		this->edma_pms_spi2.pms_edma_pms_spi2_attr1_x,
		this->edma_pms_spi2.pms_edma_pms_spi2_attr1_y
	);

	if(writeMode){
		this->regWrite(true, this->edma_pms_spi2.base, r);
		this->init_edma_pms_spi2();
	}else{
		this->edma_pms_spi2.val = r;
	}
}
void PmsDebug::patch_edma_pms_spi3_lock(bool writeMode){
	uint32_t r = this->edma_pms_spi3_lock.val;
	r = this->regSet(r, 
		this->edma_pms_spi3_lock.val,
		this->edma_pms_spi3_lock.pms_edma_pms_spi3_lock_pos
	);

	if(writeMode){
		this->regWrite(true, this->edma_pms_spi3_lock.base, r);
		this->init_edma_pms_spi3_lock();
	}else{
		this->edma_pms_spi3_lock.val = r;
	}
}
void PmsDebug::patch_edma_pms_spi3(bool writeMode){
	uint32_t r = this->edma_pms_spi3.val;
	r = this->regSet(r, 
		this->edma_pms_spi3.val,
		this->edma_pms_spi3.pms_edma_pms_spi3_attr2_x,
		this->edma_pms_spi3.pms_edma_pms_spi3_attr2_y
	);
	r = this->regSet(r, 
		this->edma_pms_spi3.val,
		this->edma_pms_spi3.pms_edma_pms_spi3_attr1_x,
		this->edma_pms_spi3.pms_edma_pms_spi3_attr1_y
	);

	if(writeMode){
		this->regWrite(true, this->edma_pms_spi3.base, r);
		this->init_edma_pms_spi3();
	}else{
		this->edma_pms_spi3.val = r;
	}
}
void PmsDebug::patch_edma_pms_uhci0_lock(bool writeMode){
	uint32_t r = this->edma_pms_uhci0_lock.val;
	r = this->regSet(r, 
		this->edma_pms_uhci0_lock.val,
		this->edma_pms_uhci0_lock.pms_edma_pms_uhci0_lock_pos
	);

	if(writeMode){
		this->regWrite(true, this->edma_pms_uhci0_lock.base, r);
		this->init_edma_pms_uhci0_lock();
	}else{
		this->edma_pms_uhci0_lock.val = r;
	}
}
void PmsDebug::patch_edma_pms_uhci0(bool writeMode){
	uint32_t r = this->edma_pms_uhci0.val;
	r = this->regSet(r, 
		this->edma_pms_uhci0.val,
		this->edma_pms_uhci0.pms_edma_pms_uhci0_attr2_x,
		this->edma_pms_uhci0.pms_edma_pms_uhci0_attr2_y
	);
	r = this->regSet(r, 
		this->edma_pms_uhci0.val,
		this->edma_pms_uhci0.pms_edma_pms_uhci0_attr1_x,
		this->edma_pms_uhci0.pms_edma_pms_uhci0_attr1_y
	);

	if(writeMode){
		this->regWrite(true, this->edma_pms_uhci0.base, r);
		this->init_edma_pms_uhci0();
	}else{
		this->edma_pms_uhci0.val = r;
	}
}
void PmsDebug::patch_edma_pms_i2s0_lock(bool writeMode){
	uint32_t r = this->edma_pms_i2s0_lock.val;
	r = this->regSet(r, 
		this->edma_pms_i2s0_lock.val,
		this->edma_pms_i2s0_lock.pms_edma_pms_i2s0_lock_pos
	);

	if(writeMode){
		this->regWrite(true, this->edma_pms_i2s0_lock.base, r);
		this->init_edma_pms_i2s0_lock();
	}else{
		this->edma_pms_i2s0_lock.val = r;
	}
}
void PmsDebug::patch_edma_pms_i2s0(bool writeMode){
	uint32_t r = this->edma_pms_i2s0.val;
	r = this->regSet(r, 
		this->edma_pms_i2s0.val,
		this->edma_pms_i2s0.pms_edma_pms_i2s0_attr2_x,
		this->edma_pms_i2s0.pms_edma_pms_i2s0_attr2_y
	);
	r = this->regSet(r, 
		this->edma_pms_i2s0.val,
		this->edma_pms_i2s0.pms_edma_pms_i2s0_attr1_x,
		this->edma_pms_i2s0.pms_edma_pms_i2s0_attr1_y
	);

	if(writeMode){
		this->regWrite(true, this->edma_pms_i2s0.base, r);
		this->init_edma_pms_i2s0();
	}else{
		this->edma_pms_i2s0.val = r;
	}
}
void PmsDebug::patch_edma_pms_i2s1_lock(bool writeMode){
	uint32_t r = this->edma_pms_i2s1_lock.val;
	r = this->regSet(r, 
		this->edma_pms_i2s1_lock.val,
		this->edma_pms_i2s1_lock.pms_edma_pms_i2s1_lock_pos
	);

	if(writeMode){
		this->regWrite(true, this->edma_pms_i2s1_lock.base, r);
		this->init_edma_pms_i2s1_lock();
	}else{
		this->edma_pms_i2s1_lock.val = r;
	}
}
void PmsDebug::patch_edma_pms_i2s1(bool writeMode){
	uint32_t r = this->edma_pms_i2s1.val;
	r = this->regSet(r, 
		this->edma_pms_i2s1.val,
		this->edma_pms_i2s1.pms_edma_pms_i2s1_attr2_x,
		this->edma_pms_i2s1.pms_edma_pms_i2s1_attr2_y
	);
	r = this->regSet(r, 
		this->edma_pms_i2s1.val,
		this->edma_pms_i2s1.pms_edma_pms_i2s1_attr1_x,
		this->edma_pms_i2s1.pms_edma_pms_i2s1_attr1_y
	);

	if(writeMode){
		this->regWrite(true, this->edma_pms_i2s1.base, r);
		this->init_edma_pms_i2s1();
	}else{
		this->edma_pms_i2s1.val = r;
	}
}
void PmsDebug::patch_edma_pms_lcd_cam_lock(bool writeMode){
	uint32_t r = this->edma_pms_lcd_cam_lock.val;
	r = this->regSet(r, 
		this->edma_pms_lcd_cam_lock.val,
		this->edma_pms_lcd_cam_lock.pms_edma_pms_lcd_cam_lock_pos
	);

	if(writeMode){
		this->regWrite(true, this->edma_pms_lcd_cam_lock.base, r);
		this->init_edma_pms_lcd_cam_lock();
	}else{
		this->edma_pms_lcd_cam_lock.val = r;
	}
}
void PmsDebug::patch_edma_pms_lcd_cam(bool writeMode){
	uint32_t r = this->edma_pms_lcd_cam.val;
	r = this->regSet(r, 
		this->edma_pms_lcd_cam.val,
		this->edma_pms_lcd_cam.pms_edma_pms_lcd_cam_attr2_x,
		this->edma_pms_lcd_cam.pms_edma_pms_lcd_cam_attr2_y
	);
	r = this->regSet(r, 
		this->edma_pms_lcd_cam.val,
		this->edma_pms_lcd_cam.pms_edma_pms_lcd_cam_attr1_x,
		this->edma_pms_lcd_cam.pms_edma_pms_lcd_cam_attr1_y
	);

	if(writeMode){
		this->regWrite(true, this->edma_pms_lcd_cam.base, r);
		this->init_edma_pms_lcd_cam();
	}else{
		this->edma_pms_lcd_cam.val = r;
	}
}
void PmsDebug::patch_edma_pms_aes_lock(bool writeMode){
	uint32_t r = this->edma_pms_aes_lock.val;
	r = this->regSet(r, 
		this->edma_pms_aes_lock.val,
		this->edma_pms_aes_lock.pms_edma_pms_aes_lock_pos
	);

	if(writeMode){
		this->regWrite(true, this->edma_pms_aes_lock.base, r);
		this->init_edma_pms_aes_lock();
	}else{
		this->edma_pms_aes_lock.val = r;
	}
}
void PmsDebug::patch_edma_pms_aes(bool writeMode){
	uint32_t r = this->edma_pms_aes.val;
	r = this->regSet(r, 
		this->edma_pms_aes.val,
		this->edma_pms_aes.pms_edma_pms_aes_attr2_x,
		this->edma_pms_aes.pms_edma_pms_aes_attr2_y
	);
	r = this->regSet(r, 
		this->edma_pms_aes.val,
		this->edma_pms_aes.pms_edma_pms_aes_attr1_x,
		this->edma_pms_aes.pms_edma_pms_aes_attr1_y
	);

	if(writeMode){
		this->regWrite(true, this->edma_pms_aes.base, r);
		this->init_edma_pms_aes();
	}else{
		this->edma_pms_aes.val = r;
	}
}
void PmsDebug::patch_edma_pms_sha_lock(bool writeMode){
	uint32_t r = this->edma_pms_sha_lock.val;
	r = this->regSet(r, 
		this->edma_pms_sha_lock.val,
		this->edma_pms_sha_lock.pms_edma_pms_sha_lock_pos
	);

	if(writeMode){
		this->regWrite(true, this->edma_pms_sha_lock.base, r);
		this->init_edma_pms_sha_lock();
	}else{
		this->edma_pms_sha_lock.val = r;
	}
}
void PmsDebug::patch_edma_pms_sha(bool writeMode){
	uint32_t r = this->edma_pms_sha.val;
	r = this->regSet(r, 
		this->edma_pms_sha.val,
		this->edma_pms_sha.pms_edma_pms_sha_attr2_x,
		this->edma_pms_sha.pms_edma_pms_sha_attr2_y
	);
	r = this->regSet(r, 
		this->edma_pms_sha.val,
		this->edma_pms_sha.pms_edma_pms_sha_attr1_x,
		this->edma_pms_sha.pms_edma_pms_sha_attr1_y
	);

	if(writeMode){
		this->regWrite(true, this->edma_pms_sha.base, r);
		this->init_edma_pms_sha();
	}else{
		this->edma_pms_sha.val = r;
	}
}
void PmsDebug::patch_edma_pms_adc_dac_lock(bool writeMode){
	uint32_t r = this->edma_pms_adc_dac_lock.val;
	r = this->regSet(r, 
		this->edma_pms_adc_dac_lock.val,
		this->edma_pms_adc_dac_lock.pms_edma_pms_adc_dac_lock_pos
	);

	if(writeMode){
		this->regWrite(true, this->edma_pms_adc_dac_lock.base, r);
		this->init_edma_pms_adc_dac_lock();
	}else{
		this->edma_pms_adc_dac_lock.val = r;
	}
}
void PmsDebug::patch_edma_pms_adc_dac(bool writeMode){
	uint32_t r = this->edma_pms_adc_dac.val;
	r = this->regSet(r, 
		this->edma_pms_adc_dac.val,
		this->edma_pms_adc_dac.pms_edma_pms_adc_dac_attr2_x,
		this->edma_pms_adc_dac.pms_edma_pms_adc_dac_attr2_y
	);
	r = this->regSet(r, 
		this->edma_pms_adc_dac.val,
		this->edma_pms_adc_dac.pms_edma_pms_adc_dac_attr1_x,
		this->edma_pms_adc_dac.pms_edma_pms_adc_dac_attr1_y
	);

	if(writeMode){
		this->regWrite(true, this->edma_pms_adc_dac.base, r);
		this->init_edma_pms_adc_dac();
	}else{
		this->edma_pms_adc_dac.val = r;
	}
}
void PmsDebug::patch_edma_pms_rmt_lock(bool writeMode){
	uint32_t r = this->edma_pms_rmt_lock.val;
	r = this->regSet(r, 
		this->edma_pms_rmt_lock.val,
		this->edma_pms_rmt_lock.pms_edma_pms_rmt_lock_pos
	);

	if(writeMode){
		this->regWrite(true, this->edma_pms_rmt_lock.base, r);
		this->init_edma_pms_rmt_lock();
	}else{
		this->edma_pms_rmt_lock.val = r;
	}
}
void PmsDebug::patch_edma_pms_rmt(bool writeMode){
	uint32_t r = this->edma_pms_rmt.val;
	r = this->regSet(r, 
		this->edma_pms_rmt.val,
		this->edma_pms_rmt.pms_edma_pms_rmt_attr2_x,
		this->edma_pms_rmt.pms_edma_pms_rmt_attr2_y
	);
	r = this->regSet(r, 
		this->edma_pms_rmt.val,
		this->edma_pms_rmt.pms_edma_pms_rmt_attr1_x,
		this->edma_pms_rmt.pms_edma_pms_rmt_attr1_y
	);

	if(writeMode){
		this->regWrite(true, this->edma_pms_rmt.base, r);
		this->init_edma_pms_rmt();
	}else{
		this->edma_pms_rmt.val = r;
	}
}
void PmsDebug::patch_clock_gate(bool writeMode){
	uint32_t r = this->clock_gate.val;
	r = this->regSet(r, 
		this->clock_gate.val,
		this->clock_gate.pms_reg_clk_en_pos
	);

	if(writeMode){
		this->regWrite(true, this->clock_gate.base, r);
		this->init_clock_gate();
	}else{
		this->clock_gate.val = r;
	}
}
void PmsDebug::patch_core_0_iram0_pms_monitor_2(bool writeMode){
	uint32_t r = this->core_0_iram0_pms_monitor_2.val;
	r = this->regSet(r, 
		this->core_0_iram0_pms_monitor_2.val,
		this->core_0_iram0_pms_monitor_2.pms_core_0_iram0_pms_monitor_violate_status_addr_x,
		this->core_0_iram0_pms_monitor_2.pms_core_0_iram0_pms_monitor_violate_status_addr_y
	);
	r = this->regSet(r, 
		this->core_0_iram0_pms_monitor_2.val,
		this->core_0_iram0_pms_monitor_2.pms_core_0_iram0_pms_monitor_violate_status_world_x,
		this->core_0_iram0_pms_monitor_2.pms_core_0_iram0_pms_monitor_violate_status_world_y
	);
	r = this->regSet(r, 
		this->core_0_iram0_pms_monitor_2.val,
		this->core_0_iram0_pms_monitor_2.pms_core_0_iram0_pms_monitor_violate_status_loadstore_pos
	);
	r = this->regSet(r, 
		this->core_0_iram0_pms_monitor_2.val,
		this->core_0_iram0_pms_monitor_2.pms_core_0_iram0_pms_monitor_violate_status_wr_pos
	);
	r = this->regSet(r, 
		this->core_0_iram0_pms_monitor_2.val,
		this->core_0_iram0_pms_monitor_2.pms_core_0_iram0_pms_monitor_violate_intr_pos
	);

	if(writeMode){
		this->regWrite(true, this->core_0_iram0_pms_monitor_2.base, r);
		this->init_core_0_iram0_pms_monitor_2();
	}else{
		this->core_0_iram0_pms_monitor_2.val = r;
	}
}
void PmsDebug::patch_core_0_dram0_pms_monitor_2(bool writeMode){
	uint32_t r = this->core_0_dram0_pms_monitor_2.val;
	r = this->regSet(r, 
		this->core_0_dram0_pms_monitor_2.val,
		this->core_0_dram0_pms_monitor_2.pms_core_0_dram0_pms_monitor_violate_status_addr_x,
		this->core_0_dram0_pms_monitor_2.pms_core_0_dram0_pms_monitor_violate_status_addr_y
	);
	r = this->regSet(r, 
		this->core_0_dram0_pms_monitor_2.val,
		this->core_0_dram0_pms_monitor_2.pms_core_0_dram0_pms_monitor_violate_status_world_x,
		this->core_0_dram0_pms_monitor_2.pms_core_0_dram0_pms_monitor_violate_status_world_y
	);
	r = this->regSet(r, 
		this->core_0_dram0_pms_monitor_2.val,
		this->core_0_dram0_pms_monitor_2.pms_core_0_dram0_pms_monitor_violate_status_lock_pos
	);
	r = this->regSet(r, 
		this->core_0_dram0_pms_monitor_2.val,
		this->core_0_dram0_pms_monitor_2.pms_core_0_dram0_pms_monitor_violate_intr_pos
	);

	if(writeMode){
		this->regWrite(true, this->core_0_dram0_pms_monitor_2.base, r);
		this->init_core_0_dram0_pms_monitor_2();
	}else{
		this->core_0_dram0_pms_monitor_2.val = r;
	}
}
void PmsDebug::patch_core_0_dram0_pms_monitor_3(bool writeMode){
	uint32_t r = this->core_0_dram0_pms_monitor_3.val;
	r = this->regSet(r, 
		this->core_0_dram0_pms_monitor_3.val,
		this->core_0_dram0_pms_monitor_3.pms_core_0_dram0_pms_monitor_violate_status_byteen_x,
		this->core_0_dram0_pms_monitor_3.pms_core_0_dram0_pms_monitor_violate_status_byteen_y
	);
	r = this->regSet(r, 
		this->core_0_dram0_pms_monitor_3.val,
		this->core_0_dram0_pms_monitor_3.pms_core_0_dram0_pms_monitor_violate_status_wr_pos
	);

	if(writeMode){
		this->regWrite(true, this->core_0_dram0_pms_monitor_3.base, r);
		this->init_core_0_dram0_pms_monitor_3();
	}else{
		this->core_0_dram0_pms_monitor_3.val = r;
	}
}
void PmsDebug::patch_core_0_pif_pms_monitor_2(bool writeMode){
	uint32_t r = this->core_0_pif_pms_monitor_2.val;
	r = this->regSet(r, 
		this->core_0_pif_pms_monitor_2.val,
		this->core_0_pif_pms_monitor_2.pms_core_0_pif_pms_monitor_violate_status_hworld_x,
		this->core_0_pif_pms_monitor_2.pms_core_0_pif_pms_monitor_violate_status_hworld_y
	);
	r = this->regSet(r, 
		this->core_0_pif_pms_monitor_2.val,
		this->core_0_pif_pms_monitor_2.pms_core_0_pif_pms_monitor_violate_status_hwrite_pos
	);
	r = this->regSet(r, 
		this->core_0_pif_pms_monitor_2.val,
		this->core_0_pif_pms_monitor_2.pms_core_0_pif_pms_monitor_violate_status_hsize_x,
		this->core_0_pif_pms_monitor_2.pms_core_0_pif_pms_monitor_violate_status_hsize_y
	);
	r = this->regSet(r, 
		this->core_0_pif_pms_monitor_2.val,
		this->core_0_pif_pms_monitor_2.pms_core_0_pif_pms_monitor_violate_status_hport_0_pos
	);
	r = this->regSet(r, 
		this->core_0_pif_pms_monitor_2.val,
		this->core_0_pif_pms_monitor_2.pms_core_0_pif_pms_monitor_violate_intr_pos
	);

	if(writeMode){
		this->regWrite(true, this->core_0_pif_pms_monitor_2.base, r);
		this->init_core_0_pif_pms_monitor_2();
	}else{
		this->core_0_pif_pms_monitor_2.val = r;
	}
}
void PmsDebug::patch_core_0_pif_pms_monitor_3(bool writeMode){
	uint32_t r = this->core_0_pif_pms_monitor_3.val;
	r = this->regSet(r, 
		this->core_0_pif_pms_monitor_3.val,
		this->core_0_pif_pms_monitor_3.pms_core_0_pif_pms_monitor_violate_status_haddr_x,
		this->core_0_pif_pms_monitor_3.pms_core_0_pif_pms_monitor_violate_status_haddr_y
	);

	if(writeMode){
		this->regWrite(true, this->core_0_pif_pms_monitor_3.base, r);
		this->init_core_0_pif_pms_monitor_3();
	}else{
		this->core_0_pif_pms_monitor_3.val = r;
	}
}
void PmsDebug::patch_core_0_pif_pms_monitor_5(bool writeMode){
	uint32_t r = this->core_0_pif_pms_monitor_5.val;
	r = this->regSet(r, 
		this->core_0_pif_pms_monitor_5.val,
		this->core_0_pif_pms_monitor_5.pms_core_0_pif_pms_monitor_nonword_violate_status_hworld_x,
		this->core_0_pif_pms_monitor_5.pms_core_0_pif_pms_monitor_nonword_violate_status_hworld_y
	);
	r = this->regSet(r, 
		this->core_0_pif_pms_monitor_5.val,
		this->core_0_pif_pms_monitor_5.pms_core_0_pif_pms_monitor_nonword_violate_status_hsize_x,
		this->core_0_pif_pms_monitor_5.pms_core_0_pif_pms_monitor_nonword_violate_status_hsize_y
	);
	r = this->regSet(r, 
		this->core_0_pif_pms_monitor_5.val,
		this->core_0_pif_pms_monitor_5.pms_core_0_pif_pms_monitor_nonword_violate_intr_pos
	);

	if(writeMode){
		this->regWrite(true, this->core_0_pif_pms_monitor_5.base, r);
		this->init_core_0_pif_pms_monitor_5();
	}else{
		this->core_0_pif_pms_monitor_5.val = r;
	}
}
void PmsDebug::patch_core_0_pif_pms_monitor_6(bool writeMode){
	uint32_t r = this->core_0_pif_pms_monitor_6.val;
	r = this->regSet(r, 
		this->core_0_pif_pms_monitor_6.val,
		this->core_0_pif_pms_monitor_6.pms_core_0_pif_pms_monitor_nonword_violate_status_haddr_x,
		this->core_0_pif_pms_monitor_6.pms_core_0_pif_pms_monitor_nonword_violate_status_haddr_y
	);

	if(writeMode){
		this->regWrite(true, this->core_0_pif_pms_monitor_6.base, r);
		this->init_core_0_pif_pms_monitor_6();
	}else{
		this->core_0_pif_pms_monitor_6.val = r;
	}
}
void PmsDebug::patch_date(bool writeMode){
	uint32_t r = this->date.val;
	r = this->regSet(r, 
		this->date.val,
		this->date.pms_date_x,
		this->date.pms_date_y
	);

	if(writeMode){
		this->regWrite(true, this->date.base, r);
		this->init_date();
	}else{
		this->date.val = r;
	}
}
void PmsDebug::patch_ctrl_ext_mem_pms_lock(bool writeMode){
	uint32_t r = this->ctrl_ext_mem_pms_lock.val;
	r = this->regSet(r, 
		this->ctrl_ext_mem_pms_lock.val,
		this->ctrl_ext_mem_pms_lock.apb_ctrl_ext_mem_pms_lock_pos
	);

	if(writeMode){
		this->regWrite(false, this->ctrl_ext_mem_pms_lock.base, r);
		this->init_ctrl_ext_mem_pms_lock();
	}else{
		this->ctrl_ext_mem_pms_lock.val = r;
	}
}
void PmsDebug::patch_ctrl_flash_acen_attr(bool writeMode){
	uint32_t r = this->ctrl_flash_acen_attr.val;
	r = this->regSet(r, 
		this->ctrl_flash_acen_attr.val,
		this->ctrl_flash_acen_attr.apb_ctrl_flash_acen_attr_x,
		this->ctrl_flash_acen_attr.apb_ctrl_flash_acen_attr_y
	);

	if(writeMode){
		this->regWrite(false, this->ctrl_flash_acen_attr.base, r);
		this->init_ctrl_flash_acen_attr();
	}else{
		this->ctrl_flash_acen_attr.val = r;
	}
}
void PmsDebug::patch_ctrl_flash_acen_addr(bool writeMode){
	uint32_t r = this->ctrl_flash_acen_addr.val;
	r = this->regSet(r, 
		this->ctrl_flash_acen_addr.val,
		this->ctrl_flash_acen_addr.apb_ctrl_flash_acen_addr_s_x,
		this->ctrl_flash_acen_addr.apb_ctrl_flash_acen_addr_s_y
	);

	if(writeMode){
		this->regWrite(false, this->ctrl_flash_acen_addr.base, r);
		this->init_ctrl_flash_acen_addr();
	}else{
		this->ctrl_flash_acen_addr.val = r;
	}
}
void PmsDebug::patch_ctrl_flash_acen_size(bool writeMode){
	uint32_t r = this->ctrl_flash_acen_size.val;
	r = this->regSet(r, 
		this->ctrl_flash_acen_size.val,
		this->ctrl_flash_acen_size.apb_ctrl_flash_acen_size_x,
		this->ctrl_flash_acen_size.apb_ctrl_flash_acen_size_y
	);

	if(writeMode){
		this->regWrite(false, this->ctrl_flash_acen_size.base, r);
		this->init_ctrl_flash_acen_size();
	}else{
		this->ctrl_flash_acen_size.val = r;
	}
}
void PmsDebug::patch_ctrl_sram_acen_attr(bool writeMode){
	uint32_t r = this->ctrl_sram_acen_attr.val;
	r = this->regSet(r, 
		this->ctrl_sram_acen_attr.val,
		this->ctrl_sram_acen_attr.apb_ctrl_sram_acen_attr_x,
		this->ctrl_sram_acen_attr.apb_ctrl_sram_acen_attr_y
	);

	if(writeMode){
		this->regWrite(false, this->ctrl_sram_acen_attr.base, r);
		this->init_ctrl_sram_acen_attr();
	}else{
		this->ctrl_sram_acen_attr.val = r;
	}
}
void PmsDebug::patch_ctrl_sram_acen_addr(bool writeMode){
	uint32_t r = this->ctrl_sram_acen_addr.val;
	r = this->regSet(r, 
		this->ctrl_sram_acen_addr.val,
		this->ctrl_sram_acen_addr.apb_ctrl_sram_acen_addr_s_x,
		this->ctrl_sram_acen_addr.apb_ctrl_sram_acen_addr_s_y
	);

	if(writeMode){
		this->regWrite(false, this->ctrl_sram_acen_addr.base, r);
		this->init_ctrl_sram_acen_addr();
	}else{
		this->ctrl_sram_acen_addr.val = r;
	}
}
void PmsDebug::patch_ctrl_sram_acen_size(bool writeMode){
	uint32_t r = this->ctrl_sram_acen_size.val;
	r = this->regSet(r, 
		this->ctrl_sram_acen_size.val,
		this->ctrl_sram_acen_size.apb_ctrl_sram_acen_size_x,
		this->ctrl_sram_acen_size.apb_ctrl_sram_acen_size_y
	);

	if(writeMode){
		this->regWrite(false, this->ctrl_sram_acen_size.base, r);
		this->init_ctrl_sram_acen_size();
	}else{
		this->ctrl_sram_acen_size.val = r;
	}
}
void PmsDebug::patch_ctrl_spi_mem_pms_ctrl(bool writeMode){
	uint32_t r = this->ctrl_spi_mem_pms_ctrl.val;
	r = this->regSet(r, 
		this->ctrl_spi_mem_pms_ctrl.val,
		this->ctrl_spi_mem_pms_ctrl.apb_ctrl_spi_mem_reject_cde_x,
		this->ctrl_spi_mem_pms_ctrl.apb_ctrl_spi_mem_reject_cde_y
	);
	r = this->regSet(r, 
		this->ctrl_spi_mem_pms_ctrl.val,
		this->ctrl_spi_mem_pms_ctrl.apb_ctrl_spi_mem_reject_clr_pos
	);
	r = this->regSet(r, 
		this->ctrl_spi_mem_pms_ctrl.val,
		this->ctrl_spi_mem_pms_ctrl.apb_ctrl_spi_mem_reject_int_pos
	);

	if(writeMode){
		this->regWrite(false, this->ctrl_spi_mem_pms_ctrl.base, r);
		this->init_ctrl_spi_mem_pms_ctrl();
	}else{
		this->ctrl_spi_mem_pms_ctrl.val = r;
	}
}
void PmsDebug::patch_ctrl_spi_mem_reject_addr(bool writeMode){
	uint32_t r = this->ctrl_spi_mem_reject_addr.val;
	r = this->regSet(r, 
		this->ctrl_spi_mem_reject_addr.val,
		this->ctrl_spi_mem_reject_addr.apb_ctrl_spi_mem_reject_addr_x,
		this->ctrl_spi_mem_reject_addr.apb_ctrl_spi_mem_reject_addr_y
	);

	if(writeMode){
		this->regWrite(false, this->ctrl_spi_mem_reject_addr.base, r);
		this->init_ctrl_spi_mem_reject_addr();
	}else{
		this->ctrl_spi_mem_reject_addr.val = r;
	}
}
