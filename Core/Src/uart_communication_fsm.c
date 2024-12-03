/*
 * uart_communication_fsm.c
 *
 *  Created on: Nov 28, 2024
 *      Author: Admin
 */

#include "uart_communication_fsm.h"

char str[30];
uint32_t ADC_value = 0;
uint8_t resend = 0;

void send_uart_message(char *msg) {
	HAL_UART_Transmit(&huart2, (uint8_t*) msg, strlen(msg), 1000);
}

void uart_communication_fsm_run() {
	if (cmd_rst == 1) {
		HAL_ADC_Start(&hadc1);
		if (HAL_ADC_PollForConversion(&hadc1, HAL_MAX_DELAY) == HAL_OK) {
			ADC_value = HAL_ADC_GetValue(&hadc1);
			HAL_UART_Transmit(&huart2, (void*) str,
					sprintf(str, "!ADC=%lu#\n", ADC_value), 1000);
		}
		setTimer(0, 3000);
		resend = 1;
		cmd_rst = 0;
	} else if (cmd_ok == 1) {
		send_uart_message("Communication ended.\n");
		resend = 0;
		cmd_ok = 0;
	} else if (resend == 1 && timer_flag[0] == 1) {
		send_uart_message(str);
		timer_flag[0] = 0;
		resend = 0;
	}
}
