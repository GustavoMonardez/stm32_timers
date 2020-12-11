/*
 * main.c
 *
 *  Created on: Nov 25, 2020
 *      Author: Gustavo
 */


#include "stm32f4xx_hal.h"
#include "main.h"
#include <string.h>

void SystemClockConfig(void);
void Error_handler(void);

int main(void) {
	HAL_Init();
	SystemClockConfig();

	while(1);
	return 0;
}

void SystemClockConfig(void) {
	// By default the system clock is already set up
}

void Error_handler(void) {
	while(1);
}