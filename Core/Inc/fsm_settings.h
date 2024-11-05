/*
 * fsm_settings.h
 *
 *  Created on: Oct 29, 2024
 *      Author: Admin
 */

#ifndef INC_FSM_SETTINGS_H_
#define INC_FSM_SETTINGS_H_

#include "global.h"
#include "led7_segment.h"
#include "light_traffic.h"

void fsm_settings_run();
int const_time_red_new;
int const_time_green_new;
int const_time_yellow_new;

#endif /* INC_FSM_SETTINGS_H_ */
