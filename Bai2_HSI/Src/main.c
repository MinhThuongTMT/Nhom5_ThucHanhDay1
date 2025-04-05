#include <stdint.h>

#define RCC_BASE_ADDR							0x40023800UL
#define RCC_CFGR_REG_OFFSET						0x08UL
#define RCC_CFGR_REG_ADDR						(RCC_BASE_ADDR  +  RCC_CFGR_REG_OFFSET)
#define GPIOA_BASE_ADDR							0x40020000UL

int main(void)
{
	uint32_t *pRccCfgrReg =  (uint32_t *) RCC_CFGR_REG_ADDR;

	*pRccCfgrReg &= ~(0x3 << 21);
	*pRccCfgrReg |= ( 1 << 25);
	*pRccCfgrReg |= ( 1 << 26);

	uint32_t *pRccAhb1Enr = (uint32_t *)(RCC_CFGR_REG_ADDR + 0x3);
	*pRccAhb1Enr |= ( 1 << 0);

	uint32_t *pGPIOAModeReg = (uint32_t*)(GPIOA_BASE_ADDR + 00);
	*pGPIOAModeReg &= ~( 0x3 << 16);
	*pGPIOAModeReg |= ( 0x2 << 16);

	uint32_t *pGPIOAAltFunHighReg = (uint32_t*)(GPIOA_BASE_ADDR + 0x24);
	*pGPIOAAltFunHighReg &= ~( 0xf << 0);

	for(;;);
}
