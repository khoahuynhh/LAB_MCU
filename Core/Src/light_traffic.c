/*
 * light_traffic.c
 *
 *  Created on: Oct 29, 2024
 *      Author: Admin
 */

#include "light_traffic.h"
#include "global.h"
#include "main.h"

GPIO_TypeDef *LED_PORTS[12] = { LED_1_GPIO_Port, LED_2_GPIO_Port,
LED_3_GPIO_Port, LED_4_GPIO_Port, LED_5_GPIO_Port, LED_6_GPIO_Port,
LED_7_GPIO_Port, LED_8_GPIO_Port, LED_9_GPIO_Port, LED_10_GPIO_Port,
LED_11_GPIO_Port, LED_12_GPIO_Port };

uint16_t LED_PINS[12] = { LED_1_Pin, LED_2_Pin, LED_3_Pin, LED_4_Pin, LED_5_Pin,
LED_6_Pin, LED_7_Pin, LED_8_Pin, LED_9_Pin, LED_10_Pin, LED_11_Pin,
LED_12_Pin };

GPIO_PinState LEDS_state[4][12] = { { 1, 1, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0 }, { 0,
		1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1 },
		{ 0, 0, 0, 1, 1, 0, 0, 0, 0, 1, 1, 0 }, { 0, 0, 1, 0, 1, 0, 0, 0, 1, 0,
				1, 0 } };

void set_LEDS(const GPIO_PinState *state) {
	for (int i = 0; i < 12; i++) {
		HAL_GPIO_WritePin(LED_PORTS[i], LED_PINS[i], state[i]);
	}
}

void init_time() {
	time_red = 5;
	time_green = 3;
	time_yellow = 2;
}

void init() {
	for (int i = 0; i < 12; i++) {
		HAL_GPIO_WritePin(LED_PORTS[i], LED_PINS[i], RESET);
	}
}

void led_red_and_green() {
	set_LEDS(LEDS_state[2]);
}

void led_red_and_yellow() {
	set_LEDS(LEDS_state[3]);
}

void led_green_and_red() {
	set_LEDS(LEDS_state[0]);
}

void led_yellow_and_red() {
	set_LEDS(LEDS_state[1]);
}

void blinking_led_red() {
	HAL_GPIO_TogglePin(LED_2_GPIO_Port, LED_2_Pin);
	HAL_GPIO_TogglePin(LED_5_GPIO_Port, LED_5_Pin);
	HAL_GPIO_TogglePin(LED_8_GPIO_Port, LED_8_Pin);
	HAL_GPIO_TogglePin(LED_11_GPIO_Port, LED_11_Pin);
}

void blinking_led_green() {
	HAL_GPIO_TogglePin(LED_1_GPIO_Port, LED_1_Pin);
	HAL_GPIO_TogglePin(LED_4_GPIO_Port, LED_4_Pin);
	HAL_GPIO_TogglePin(LED_7_GPIO_Port, LED_7_Pin);
	HAL_GPIO_TogglePin(LED_10_GPIO_Port, LED_10_Pin);
}

void blinking_led_yellow() {
	HAL_GPIO_TogglePin(LED_3_GPIO_Port, LED_3_Pin);
	HAL_GPIO_TogglePin(LED_6_GPIO_Port, LED_6_Pin);
	HAL_GPIO_TogglePin(LED_9_GPIO_Port, LED_9_Pin);
	HAL_GPIO_TogglePin(LED_12_GPIO_Port, LED_12_Pin);
}

