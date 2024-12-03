/*
 * command_parser_fsm.c
 *
 *  Created on: Nov 27, 2024
 *      Author: Admin
 */

#include "command_parser_fsm.h"

CPS state;
uint8_t cmd_idx = 0;
uint8_t cmd_rst = 0;
uint8_t cmd_ok = 0;

void command_parser_fsm_run() {
	switch (state) {
	case IDLE:
		if (buffer[cmd_idx] == '!') {
			cmd_idx++;
			state = RECEIVING;
		}
		break;
	case RECEIVING:
		if (buffer[cmd_idx] == '#') {
			if (strncmp((char*) buffer, "!RST#", 5) == 0) {
				cmd_rst = 1;
			} else if (strncmp((char*) buffer, "!OK#", 4) == 0) {
				cmd_ok = 1;
			}
			state = DONE;
		} else {
			cmd_idx++;
		}
		break;
	case DONE:
		cmd_idx = 0;
		index_buffer = 0;
		state = IDLE;
		break;
	default:
		break;
	}
}
