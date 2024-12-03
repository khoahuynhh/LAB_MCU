/*
 * Command_parser_fsm.h
 *
 *  Created on: Nov 27, 2024
 *      Author: Admin
 */

#ifndef INC_COMMAND_PARSER_FSM_H_
#define INC_COMMAND_PARSER_FSM_H_

#include "string.h"
#include "main.h"

typedef enum {
	IDLE, RECEIVING, DONE
} CPS;

extern CPS state;
extern uint8_t cmd_idx;
extern uint8_t cmd_rst;
extern uint8_t cmd_ok;

void command_parser_fsm_run();

#endif /* INC_COMMAND_PARSER_FSM_H_ */
