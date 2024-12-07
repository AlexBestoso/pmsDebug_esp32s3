#include <Arduino.h>
#include <cstdint>
#define DBG_SENSTIVE_BASE 	0x600C1000
#define DBG_APB_BASE 		0x60026000
#define DBG_SENSITVE_READ(reg) (*(volatile uint32_t *)(DBG_SENSITIVE_BASE+reg))
#define DBG_SENSITIVE_WRITE(reg, val) ((*(volatile uint32_t *)(DBG_SENSITIVE_BASE+reg)) = (val))
#define DBG_APB_READ(reg) (*(volatile uint32_t *)(DBG_APB_BASE+reg))
#define DBG_APB_WRITE(reg, val) ((*(volatile uint32_t *)(DBG_APB_BASE+reg)) = (val))


#include "./PmsDebug.struct.h"

class PmsDebug{
	private:

	public:
};
