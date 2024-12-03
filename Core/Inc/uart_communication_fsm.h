/*
 * uart_communication_fsm.h
 *
 *  Created on: Nov 28, 2024
 *      Author: Admin
 */

#include "stdio.h"
#include "command_parser_fsm.h"
#include "software_timer.h"

#ifndef INC_UART_COMMUNICATION_FSM_H_
#define INC_UART_COMMUNICATION_FSM_H_

extern uint32_t ADC_value;
extern char str[30];
extern uint8_t countdown_state;
extern uint32_t previous_tick;

void uart_communication_fsm_run();
void send_uart_message(char *msg);

#endif /* INC_UART_COMMUNICATION_FSM_H_ */
