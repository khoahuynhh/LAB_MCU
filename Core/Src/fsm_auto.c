/*
 * fsm_auto.c
 *
 *  Created on: Oct 29, 2024
 *      Author: Admin
 */

#include "fsm_auto.h"
#include "led7_segment.h"
#include "light_traffic.h"

void fsm_auto_run() {
	switch (status) {
	case INIT:
		init();
		init_time();
		status = AUTO_RED;
		setTimer(0, 1000);
		setTimer(1, 250);
		break;
	case AUTO_RED:
		led_red_and_green();
		if (timer_flag[0] == 1) {
			time_green--;
			time_red--;
			if (time_green == 0) {
				status = AUTO_YELLOW;
			}
			setTimer(0, 1000);
		}
		if (timer_flag[1] == 1) {
			displaySettingX(time_green);
			displaySetting(time_red);
			setTimer(1, 250);
		}
		if (isButton1Pressed(0) == 1) {
			init();
			status = MAN_RED;
			setTimer(0, 100000);
			setTimer(2, 500);
			setTimer(3, 250);
		}
		break;
	case AUTO_GREEN:
		led_green_and_red();
		if (timer_flag[0] == 1) {
			time_green--;
			time_red--;
			if (time_green == 0) {
				status = AUTO_YELLOW_MAIN;
			}
			setTimer(0, 1000);
		}
		if (timer_flag[1] == 1) {
			displaySettingX(time_red);
			displaySetting(time_green);
			setTimer(1, 250);
		}
		break;
	case AUTO_YELLOW_MAIN:
		led_yellow_and_red();
		if (timer_flag[0] == 1) {
			time_red--;
			time_yellow--;
			if (time_red == 0) {
				init_time();
				status = AUTO_RED;
			}
			setTimer(0, 1000);
		}
		if (timer_flag[1] == 1) {
			displaySettingX(time_red);
			displaySetting(time_yellow);
			setTimer(1, 250);
		}
		break;
	case AUTO_YELLOW:
		led_red_and_yellow();
		if (timer_flag[0] == 1) {
			time_red--;
			time_yellow--;
			if (time_red == 0) {
				init_time();
				status = AUTO_GREEN;
			}
			setTimer(0, 1000);
		}
		if (timer_flag[1] == 1) {
			displaySettingX(time_yellow);
			displaySetting(time_red);
			setTimer(1, 250);
		}
		break;
	default:
		break;
	}
}
