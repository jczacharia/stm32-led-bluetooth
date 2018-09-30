/*
 * ws2812b.c
 *
 *  Created on: Apr 18, 2018
 *      Author: jeremy
 */

#include <ws2812.h>
#include "stm32f1xx_hal.h"

uint8_t LEDbuffer[LED_BUFFER_SIZE];
extern TIM_HandleTypeDef htim2;


void ws2812_init(void)
{
	LED_black_out();

	/* Start PWM signal generation in DMA mode */
	dma_start();
}

void dma_stop()
{
	HAL_TIM_PWM_Stop_DMA(&htim2, TIM_CHANNEL_2);
}

void dma_start()
{
	HAL_TIM_Base_Start(&htim2);
	HAL_TIM_PWM_Start(&htim2,TIM_CHANNEL_2);
	HAL_TIM_PWM_Start_DMA(&htim2, TIM_CHANNEL_2, (uint32_t *)LEDbuffer,
	LED_BUFFER_SIZE);
}

void setLEDcolor(uint32_t LEDnumber, uint8_t RED, uint8_t GREEN, uint8_t BLUE)
{
	uint8_t tempBuffer[24];
	uint32_t i;
	uint32_t LEDindex;
	LEDindex = LEDnumber % LED_NUM;

	for (i = 0; i < 8; i++) // GREEN data
		tempBuffer[i] = ((GREEN << i) & 0x80) ? WS2812_1 : WS2812_0;
	for (i = 0; i < 8; i++) // RED
		tempBuffer[8 + i] = ((RED << i) & 0x80) ? WS2812_1 : WS2812_0;
	for (i = 0; i < 8; i++) // BLUE
		tempBuffer[16 + i] = ((BLUE << i) & 0x80) ? WS2812_1 : WS2812_0;

	for (i = 0; i < 24; i++)
		LEDbuffer[RESET_SLOTS_BEGIN + (LEDindex * 24) + i] = tempBuffer[i];
}

void setStripColor(uint8_t RED, uint8_t GREEN, uint8_t BLUE)
{
	uint32_t i;
	for(i = 0; i < LED_NUM; i++)
		setLEDcolor(i, RED, GREEN, BLUE);
}

void LED_black_out(void)
{
	/*Fill LED buffer - ALL OFF*/
	uint32_t index, buffIndex;
	buffIndex = 0;

	for (index = 0; index < RESET_SLOTS_BEGIN; index++) {
		LEDbuffer[buffIndex] = WS2812_RESET;
		buffIndex++;
	}
	for (index = 0; index < LED_DATA_SIZE; index++) {
		LEDbuffer[buffIndex] = WS2812_0;
		buffIndex++;
	}
	LEDbuffer[buffIndex] = WS2812_0;
	buffIndex++;
	for (index = 0; index < RESET_SLOTS_END; index++) {
		LEDbuffer[buffIndex] = 0;
		buffIndex++;
	}
}

void LED_white_out(void)
{
	/*Fill LED buffer - ALL ON*/
	uint32_t index, buffIndex;
	buffIndex = 0;

	for (index = 0; index < RESET_SLOTS_BEGIN; index++) {
		LEDbuffer[buffIndex] = WS2812_RESET;
		buffIndex++;
	}
	for (index = 0; index < LED_DATA_SIZE; index++) {
		LEDbuffer[buffIndex] = WS2812_1;
		buffIndex++;
	}
	LEDbuffer[buffIndex] = WS2812_0;
	buffIndex++;
	for (index = 0; index < RESET_SLOTS_END; index++) {
		LEDbuffer[buffIndex] = 0;
		buffIndex++;
	}
}
