/*
 * light_traffic.c
 *
 *  Created on: Oct 29, 2024
 *      Author: Admin
 */

#include "light_traffic.h"
#include "main.h"

void init() {
	HAL_GPIO_WritePin(LED_12_GPIO_Port, LED_12_Pin, RESET);
	HAL_GPIO_WritePin(LED_1_GPIO_Port, LED_1_Pin, RESET);
	HAL_GPIO_WritePin(LED_11_GPIO_Port, LED_11_Pin, RESET);
}

void led_yellow() {
	HAL_GPIO_WritePin(LED_12_GPIO_Port, LED_12_Pin, SET);
	HAL_GPIO_WritePin(LED_1_GPIO_Port, LED_1_Pin, RESET);
	HAL_GPIO_WritePin(LED_11_GPIO_Port, LED_11_Pin, RESET);
}

void led_green() {
	HAL_GPIO_WritePin(LED_12_GPIO_Port, LED_12_Pin, RESET);
	HAL_GPIO_WritePin(LED_1_GPIO_Port, LED_1_Pin, SET);
	HAL_GPIO_WritePin(LED_11_GPIO_Port, LED_11_Pin, RESET);
}

void led_red() {
	HAL_GPIO_WritePin(LED_12_GPIO_Port, LED_12_Pin, RESET);
	HAL_GPIO_WritePin(LED_1_GPIO_Port, LED_1_Pin, RESET);
	HAL_GPIO_WritePin(LED_11_GPIO_Port, LED_11_Pin, SET);
}

void led_red_and_green() {
	//TODO
}

void led_red_and_yellow() {
	//TODO
}

void led_green_and_red() {
//TODO
//HAL_GPIO_WritePin(GPIOx, GPIO_Pin, PinState);
}
void led_yellow_and_red() {
//TO DO
//HAL_GPIO_WritePin(GPIOx, GPIO_Pin, PinState);
}
