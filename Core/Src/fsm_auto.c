/*
 * fsm_auto.c
 *
 *  Created on: Oct 29, 2024
 *      Author: Admin
 */

#include "fsm_auto.h"
#include "light_traffic.h"

void fsm_auto_run() {
	switch (status) {
	case INIT:
		init();
		status = AUTO_RED;
		setTimer(0, 5000);
		break;
	case AUTO_RED:
		led_red();
		if (timer_flag[0] == 1) {
			status = AUTO_GREEN;
			setTimer(0, 3000);
		}
		break;
	case AUTO_GREEN:
		led_green();
		if (timer_flag[0] == 1) {
			status = AUTO_YELLOW;
			setTimer(0, 2000);
		}
		break;
	case AUTO_YELLOW:
		led_yellow();
		if (timer_flag[0] == 1) {
			status = AUTO_RED;
			setTimer(0, 5000);
		}
		break;
	default:
		break;
	}
}
