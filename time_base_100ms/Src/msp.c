/*
 * msp.c
 *
 *  Created on: Nov 25, 2020
 *      Author: Gustavo
 */

#include "stm32f4xx_hal.h"

/* MSP (Microcontroller Support Package */
void HAL_MspInit(void) {
	/* The following settings depend on the type
	 * of application being developed */

	// 1. Set up the priority grouping of the arm cortex mx processor
	HAL_NVIC_SetPriorityGrouping(NVIC_PRIORITYGROUP_4);

	// 2. Enable the required system exceptions of the arm cortex mx processor
	SCB->SHCSR |= 0x7 << 16; /*usg fault, mem fault and bus fault - Cortex manual */

	// 3. Configure the priority for the system exceptions
	// Note: By default exceptions are the highest priority (0),
	// so this step is optional. Priority range 0-15, 0 is highest.
	HAL_NVIC_SetPriority(MemoryManagement_IRQn, 0, 0);
	HAL_NVIC_SetPriority(BusFault_IRQn, 0, 0);
	HAL_NVIC_SetPriority(UsageFault_IRQn, 0, 0);
}
