#include <Arduino.h>
#include <cstdint>
#include <src/PmsDebug.class.h>

PmsDebug pmsdebug;
void setup(void){
  Serial.begin(115200);
  
  pmsdebug.init();

  
  pmsdebug.internal_sram_usage_1.pms_internal_sram_cpu_usage = 0x55;   
  // Setting to true will break your device, don't do it :)
  pmsdebug.patch_internal_sram_usage_1(false);
}

void loop(void){
  Serial.printf("============\nVAL : 0x%x\n", pmsdebug.internal_sram_usage_1.val);
  Serial.printf("CPU Usage : 0x%x\n", pmsdebug.internal_sram_usage_1.pms_internal_sram_cpu_usage);
  Serial.printf("DCACHE Usage : 0x%x\n", pmsdebug.internal_sram_usage_1.pms_internal_sram_dcache_usage);
  Serial.printf("ICACHE Usage : 0x%x\n", pmsdebug.internal_sram_usage_1.pms_internal_sram_icache_usage);
  delay(2000);
}