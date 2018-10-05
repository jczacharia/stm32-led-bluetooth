/*
 * ws2812b.h
 *
 *  Created on: Apr 18, 2018
 *      Author: jeremy
 */

#ifndef _WS2812_H_
#define _WS2812_H_

#include <stdint.h>

#define LED_NUM             	(5)

#define TIMER_PERIOD			(45)

#define WS2812_0            	(TIMER_PERIOD / 3)
#define WS2812_1            	((TIMER_PERIOD * 2) / 3)
#define WS2812_RESET			(0)
#define LED_DATA_SIZE 			(LED_NUM * 24)
#define RESET_SLOTS_BEGIN		(50)
#define RESET_SLOTS_END			(50)
#define LED_BUFFER_SIZE			(RESET_SLOTS_BEGIN + LED_DATA_SIZE + RESET_SLOTS_END)

void LED_black_out(void);
void LED_white_out(void);
void ws2812_init(void);
void ws2812_update(void);
void dma_stop(void);
void dma_start(void);
void makeLookLikePWM(void);
void setLEDcolor(uint32_t LEDnumber, uint8_t RED, uint8_t GREEN, uint8_t BLUE);
void setStripColor(uint8_t RED, uint8_t GREEN, uint8_t BLUE);

#endif
