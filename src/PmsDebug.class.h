#include <Arduino.h>
#include <cstdint>
#define DBG_SENSITIVE_BASE 	0x600C1000
#define DBG_APB_BASE 		0x60026000
#define DBG_SENSITIVE_READ(reg) (*(volatile uint32_t *)(DBG_SENSITIVE_BASE+reg))
#define DBG_SENSITIVE_WRITE(reg, val) ((*(volatile uint32_t *)(DBG_SENSITIVE_BASE+reg)) = (val))
#define DBG_APB_READ(reg) (*(volatile uint32_t *)(DBG_APB_BASE+reg))
#define DBG_APB_WRITE(reg, val) ((*(volatile uint32_t *)(DBG_APB_BASE+reg)) = (val))


#include "./PmsDebug.struct.h"

class PmsDebug{
	private:

		void regWrite(bool sensitive, uint32_t reg, uint32_t val);
		uint32_t regRead(bool sensitive, uint32_t reg);
		
		bool regGet(uint32_t val, int pos);
		int regGet(uint32_t val, int x, int y);
		
		uint32_t regSet(uint32_t reg, bool val, int pos);
		uint32_t regSet(uint32_t reg, int val, int x, int y);

	public:

		PmsDebug(void);
		~PmsDebug();

		struct pms_apb_peripheral_access_0_reg apb_peripheral_access_0;
		struct pms_apb_peripheral_access_1_reg apb_peripheral_access_1;
		struct pms_internal_sram_usage_0_reg internal_sram_usage_0;
		struct pms_internal_sram_usage_1_reg internal_sram_usage_1;
		struct pms_internal_sram_usage_2_reg internal_sram_usage_2;
		struct pms_dma_apbperi_spi2_pms_constrain_0_reg dma_apbperi_spi2_pms_constrain_0;
		struct pms_dma_apbperi_spi2_pms_constrain_1_reg dma_apbperi_spi2_pms_constrain_1;
		struct pms_dma_apbperi_spi3_pms_constrain_0_reg dma_apbperi_spi3_pms_constrain_0;
		struct pms_dma_apbperi_spi3_pms_constrain_1_reg dma_apbperi_spi3_pms_constrain_1;
		struct pms_dma_apbperi_uhci0_pms_constrain_0_reg dma_apbperi_uhci0_pms_constrain_0;
		struct pms_dma_apbperi_uhci0_pms_constrain_1_reg dma_apbperi_uhci0_pms_constrain_1;
		struct pms_dma_apbperi_i2s0_pms_constrain_0_reg dma_apbperi_i2s0_pms_constrain_0;
		struct pms_dma_apbperi_i2s0_pms_constrain_1_reg dma_apbperi_i2s0_pms_constrain_1;
		struct pms_dma_apbperi_i2s1_pms_constrain_0_reg dma_apbperi_i2s1_pms_constrain_0;
		struct pms_dma_apbperi_i2s1_pms_constrain_1_reg dma_apbperi_i2s1_pms_constrain_1;
		struct pms_dma_apbperi_aes_pms_constrain_0_reg dma_apbperi_aes_pms_constrain_0;
		struct pms_dma_apbperi_aes_pms_constrain_1_reg dma_apbperi_aes_pms_constrain_1;
		struct pms_dma_apbperi_sha_pms_constrain_0_reg dma_apbperi_sha_pms_constrain_0;
		struct pms_dma_apbperi_sha_pms_constrain_1_reg dma_apbperi_sha_pms_constrain_1;
		struct pms_dma_apbperi_adc_dac_pms_constrain_0_reg dma_apbperi_adc_dac_pms_constrain_0;
		struct pms_dma_apbperi_adc_dac_pms_constrain_1_reg dma_apbperi_adc_dac_pms_constrain_1;
		struct pms_dma_apbperi_rmt_pms_constrain_0_reg dma_apbperi_rmt_pms_constrain_0;
		struct pms_dma_apbperi_rmt_pms_constrain_1_reg dma_apbperi_rmt_pms_constrain_1;
		struct pms_dma_apbperi_lcd_cam_pms_constrain_0_reg dma_apbperi_lcd_cam_pms_constrain_0;
		struct pms_dma_apbperi_lcd_cam_pms_constrain_1_reg dma_apbperi_lcd_cam_pms_constrain_1;
		struct pms_dma_apbperi_usb_pms_constrain_0_reg dma_apbperi_usb_pms_constrain_0;
		struct pms_dma_apbperi_usb_pms_constrain_1_reg dma_apbperi_usb_pms_constrain_1;
		struct pms_dma_apbperi_sdio_pms_constrain_0_reg dma_apbperi_sdio_pms_constrain_0;
		struct pms_dma_apbperi_sdio_pms_constrain_1_reg dma_apbperi_sdio_pms_constrain_1;
		struct pms_dma_apbperi_pms_monitor_0_reg dma_apbperi_pms_monitor_0;
		struct pms_dma_apbperi_pms_monitor_1_reg dma_apbperi_pms_monitor_1;
		struct pms_dma_apbperi_pms_monitor_2_reg dma_apbperi_pms_monitor_2;
		struct pms_dma_apbperi_pms_monitor_3_reg dma_apbperi_pms_monitor_3;
		struct pms_core_x_iram0_dram0_dma_split_line_constrain_0_reg core_x_iram0_dram0_dma_split_line_constrain_0;
		struct pms_core_x_iram0_dram0_dma_split_line_constrain_1_reg core_x_iram0_dram0_dma_split_line_constrain_1;
		struct pms_core_x_iram0_dram0_dma_split_line_constrain_2_reg core_x_iram0_dram0_dma_split_line_constrain_2;
		struct pms_core_x_iram0_dram0_dma_split_line_constrain_3_reg core_x_iram0_dram0_dma_split_line_constrain_3;
		struct pms_core_x_iram0_dram0_dma_split_line_constrain_4_reg core_x_iram0_dram0_dma_split_line_constrain_4;
		struct pms_core_x_iram0_dram0_dma_split_line_constrain_5_reg core_x_iram0_dram0_dma_split_line_constrain_5;
		struct pms_core_x_iram0_pms_constrain_0_reg core_x_iram0_pms_constrain_0;
		struct pms_core_x_iram0_pms_constrain_1_reg core_x_iram0_pms_constrain_1;
		struct pms_core_x_iram0_pms_constrain_2_reg core_x_iram0_pms_constrain_2;
		struct pms_core_0_iram0_pms_monitor_0_reg core_0_iram0_pms_monitor_0;
		struct pms_core_0_iram0_pms_monitor_1_reg core_0_iram0_pms_monitor_1;
		struct pms_core_x_dram0_pms_constrain_0_reg core_x_dram0_pms_constrain_0;
		struct pms_core_x_dram0_pms_constrain_1_reg core_x_dram0_pms_constrain_1;
		struct pms_core_0_dram0_pms_monitor_0_reg core_0_dram0_pms_monitor_0;
		struct pms_core_0_dram0_pms_monitor_1_reg core_0_dram0_pms_monitor_1;
		struct pms_core_0_pif_pms_constrain_0_reg core_0_pif_pms_constrain_0;
		struct pms_core_0_pif_pms_constrain_n_reg core_0_pif_pms_constrain_n;
		struct pms_core_0_pif_pms_constrain_9_reg core_0_pif_pms_constrain_9;
		struct pms_core_0_pif_pms_constrain_10_reg core_0_pif_pms_constrain_10;
		struct pms_core_0_pif_pms_constrain_11_reg core_0_pif_pms_constrain_11;
		struct pms_core_0_pif_pms_constrain_12_reg core_0_pif_pms_constrain_12;
		struct pms_core_0_pif_pms_constrain_13_reg core_0_pif_pms_constrain_13;
		struct pms_core_0_pif_pms_constrain_14_reg core_0_pif_pms_constrain_14;
		struct pms_core_0_region_pms_constrain_0_reg core_0_region_pms_constrain_0;
		struct pms_core_0_region_pms_constrain_1_reg core_0_region_pms_constrain_1;
		struct pms_core_0_region_pms_constrain_2_reg core_0_region_pms_constrain_2;
		struct pms_core_0_region_pms_constrain_n_reg  core_0_region_pms_constrain_n;
		struct pms_core_0_pif_pms_monitor_0_reg core_0_pif_pms_monitor_0;
		struct pms_core_0_pif_pms_monitor_1_reg core_0_pif_pms_monitor_1;
		struct pms_core_0_pif_pms_monitor_4_reg core_0_pif_pms_monitor_4;
		struct pms_core_0_vecbase_override_lock_reg core_0_vecbase_override_lock;
		struct pms_core_0_vecbase_override_0_reg core_0_vecbase_override_0;
		struct pms_core_0_vecbase_override_1_reg core_0_vecbase_override_1;
		struct pms_core_0_vecbase_override_2_reg core_0_vecbase_override_2;
		struct pms_edma_boundary_lock_reg edma_boundary_lock;
		struct pms_edma_boundary_0_reg edma_boundary_0;
		struct pms_edma_boundary_1_reg edma_boundary_1;
		struct pms_edma_boundary_2_reg edma_boundary_2;
		struct pms_edma_pms_spi2_lock_reg edma_pms_spi2_lock;
		struct pms_edma_pms_spi2_reg edma_pms_spi2;
		struct pms_edma_pms_spi3_lock_reg edma_pms_spi3_lock;
		struct pms_edma_pms_spi3_reg edma_pms_spi3;
		struct pms_edma_pms_uhci0_lock_reg edma_pms_uhci0_lock;
		struct pms_edma_pms_uhci0_reg edma_pms_uhci0;
		struct pms_edma_pms_i2s0_lock_reg edma_pms_i2s0_lock;
		struct pms_edma_pms_i2s0_reg edma_pms_i2s0;
		struct pms_edma_pms_i2s1_lock_reg edma_pms_i2s1_lock;
		struct pms_edma_pms_i2s1_reg edma_pms_i2s1;
		struct pms_edma_pms_lcd_cam_lock_reg edma_pms_lcd_cam_lock;
		struct pms_edma_pms_lcd_cam_reg edma_pms_lcd_cam;
		struct pms_edma_pms_aes_lock_reg edma_pms_aes_lock;
		struct pms_edma_pms_aes_reg edma_pms_aes;
		struct pms_edma_pms_sha_lock_reg edma_pms_sha_lock;
		struct pms_edma_pms_sha_reg edma_pms_sha;
		struct pms_edma_pms_adc_dac_lock_reg edma_pms_adc_dac_lock;
		struct pms_edma_pms_adc_dac_reg edma_pms_adc_dac;
		struct pms_edma_pms_rmt_lock_reg edma_pms_rmt_lock;
		struct pms_edma_pms_rmt_reg edma_pms_rmt;
		struct pms_clock_gate_reg clock_gate;
		struct pms_core_0_iram0_pms_monitor_2_reg core_0_iram0_pms_monitor_2;
		struct pms_core_0_dram0_pms_monitor_2_reg core_0_dram0_pms_monitor_2;
		struct pms_core_0_dram0_pms_monitor_3_reg core_0_dram0_pms_monitor_3;
		struct pms_core_0_pif_pms_monitor_2_reg core_0_pif_pms_monitor_2;
		struct pms_core_0_pif_pms_monitor_3_reg core_0_pif_pms_monitor_3;
		struct pms_core_0_pif_pms_monitor_5_reg core_0_pif_pms_monitor_5;
		struct pms_core_0_pif_pms_monitor_6_reg core_0_pif_pms_monitor_6;
		struct pms_date_reg date;

		struct apb_ctrl_ext_mem_pms_lock_reg ctrl_ext_mem_pms_lock;
		struct apb_ctrl_flash_acen_attr_reg ctrl_flash_acen_attr;
		struct apb_ctrl_flash_acen_addr_reg ctrl_flash_acen_addr;
		struct apb_ctrl_flash_acen_size_reg ctrl_flash_acen_size;
		struct apb_ctrl_sram_acen_attr_reg ctrl_sram_acen_attr;
		struct apb_ctrl_sram_acen_addr_reg ctrl_sram_acen_addr;
		struct apb_ctrl_sram_acen_size_reg ctrl_sram_acen_size;
		struct apb_ctrl_spi_mem_pms_ctrl_reg ctrl_spi_mem_pms_ctrl;
		struct apb_ctrl_spi_mem_reject_addr_reg ctrl_spi_mem_reject_addr;
		
		/*
		 * init functions
		 * */
		void init(void);
		void init_apb_peripheral_access_0(void);
		void init_apb_peripheral_access_1(void);
		void init_internal_sram_usage_0(void);
		void init_internal_sram_usage_1(void);
		void init_internal_sram_usage_2(void);
		void init_dma_apbperi_spi2_pms_constrain_0(void);
		void init_dma_apbperi_spi2_pms_constrain_1(void);
		void init_dma_apbperi_spi3_pms_constrain_0(void);
		void init_dma_apbperi_spi3_pms_constrain_1(void);
		void init_dma_apbperi_uhci0_pms_constrain_0(void);
		void init_dma_apbperi_uhci0_pms_constrain_1(void);
		void init_dma_apbperi_i2s0_pms_constrain_0(void);
		void init_dma_apbperi_i2s0_pms_constrain_1(void);
		void init_dma_apbperi_i2s1_pms_constrain_0(void);
		void init_dma_apbperi_i2s1_pms_constrain_1(void);
		void init_dma_apbperi_aes_pms_constrain_0(void);
		void init_dma_apbperi_aes_pms_constrain_1(void);
		void init_dma_apbperi_sha_pms_constrain_0(void);
		void init_dma_apbperi_sha_pms_constrain_1(void);
		void init_dma_apbperi_adc_dac_pms_constrain_0(void);
		void init_dma_apbperi_adc_dac_pms_constrain_1(void);
		void init_dma_apbperi_rmt_pms_constrain_0(void);
		void init_dma_apbperi_rmt_pms_constrain_1(void);
		void init_dma_apbperi_lcd_cam_pms_constrain_0(void);
		void init_dma_apbperi_lcd_cam_pms_constrain_1(void);
		void init_dma_apbperi_usb_pms_constrain_0(void);
		void init_dma_apbperi_usb_pms_constrain_1(void);
		void init_dma_apbperi_sdio_pms_constrain_0(void);
		void init_dma_apbperi_sdio_pms_constrain_1(void);
		void init_dma_apbperi_pms_monitor_0(void);
		void init_dma_apbperi_pms_monitor_1(void);
		void init_dma_apbperi_pms_monitor_2(void);
		void init_dma_apbperi_pms_monitor_3(void);
		void init_core_x_iram0_dram0_dma_split_line_constrain_0(void);
		void init_core_x_iram0_dram0_dma_split_line_constrain_1(void);
		void init_core_x_iram0_dram0_dma_split_line_constrain_2(void);
		void init_core_x_iram0_dram0_dma_split_line_constrain_3(void);
		void init_core_x_iram0_dram0_dma_split_line_constrain_4(void);
		void init_core_x_iram0_dram0_dma_split_line_constrain_5(void);
		void init_core_x_iram0_pms_constrain_0(void);
		void init_core_x_iram0_pms_constrain_1(void);
		void init_core_x_iram0_pms_constrain_2(void);
		void init_core_0_iram0_pms_monitor_0(void);
		void init_core_0_iram0_pms_monitor_1(void);
		void init_core_x_dram0_pms_constrain_0(void);
		void init_core_x_dram0_pms_constrain_1(void);
		void init_core_0_dram0_pms_monitor_0(void);
		void init_core_0_dram0_pms_monitor_1(void);
		void init_core_0_pif_pms_constrain_0(void);
		void init_core_0_pif_pms_constrain_n(void);
		void init_core_0_pif_pms_constrain_9(void);
		void init_core_0_pif_pms_constrain_10(void);
		void init_core_0_pif_pms_constrain_11(void);
		void init_core_0_pif_pms_constrain_12(void);
		void init_core_0_pif_pms_constrain_13(void);
		void init_core_0_pif_pms_constrain_14(void);
		void init_core_0_region_pms_constrain_0(void);
		void init_core_0_region_pms_constrain_1(void);
		void init_core_0_region_pms_constrain_2(void);
		void init_core_0_region_pms_constrain_n(void);
		void init_core_0_pif_pms_monitor_0(void);
		void init_core_0_pif_pms_monitor_1(void);
		void init_core_0_pif_pms_monitor_4(void);
		void init_core_0_vecbase_override_lock(void);
		void init_core_0_vecbase_override_0(void);
		void init_core_0_vecbase_override_1(void);
		void init_core_0_vecbase_override_2(void);
		void init_edma_boundary_lock(void);
		void init_edma_boundary_0(void);
		void init_edma_boundary_1(void);
		void init_edma_boundary_2(void);
		void init_edma_pms_spi2_lock(void);
		void init_edma_pms_spi2(void);
		void init_edma_pms_spi3_lock(void);
		void init_edma_pms_spi3(void);
		void init_edma_pms_uhci0_lock(void);
		void init_edma_pms_uhci0(void);
		void init_edma_pms_i2s0_lock(void);
		void init_edma_pms_i2s0(void);
		void init_edma_pms_i2s1_lock(void);
		void init_edma_pms_i2s1(void);
		void init_edma_pms_lcd_cam_lock(void);
		void init_edma_pms_lcd_cam(void);
		void init_edma_pms_aes_lock(void);
		void init_edma_pms_aes(void);
		void init_edma_pms_sha_lock(void);
		void init_edma_pms_sha(void);
		void init_edma_pms_adc_dac_lock(void);
		void init_edma_pms_adc_dac(void);
		void init_edma_pms_rmt_lock(void);
		void init_edma_pms_rmt(void);
		void init_clock_gate(void);
		void init_core_0_iram0_pms_monitor_2(void);
		void init_core_0_dram0_pms_monitor_2(void);
		void init_core_0_dram0_pms_monitor_3(void);
		void init_core_0_pif_pms_monitor_2(void);
		void init_core_0_pif_pms_monitor_3(void);
		void init_core_0_pif_pms_monitor_5(void);
		void init_core_0_pif_pms_monitor_6(void);
		void init_date(void);
		void init_ctrl_ext_mem_pms_lock(void);
		void init_ctrl_flash_acen_attr(void);
		void init_ctrl_flash_acen_addr(void);
		void init_ctrl_flash_acen_size(void);
		void init_ctrl_sram_acen_attr(void);
		void init_ctrl_sram_acen_addr(void);
		void init_ctrl_sram_acen_size(void);
		void init_ctrl_spi_mem_pms_ctrl(void);
		void init_ctrl_spi_mem_reject_addr(void);
};
