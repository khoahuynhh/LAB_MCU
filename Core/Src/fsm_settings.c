/*
 * fsm_settings.c
 *
 *  Created on: Oct 29, 2024
 *      Author: Admin
 */

#include "fsm_settings.h"

void fsm_settings_run() {
	switch (status) {
	case SET_INIT:
		init();
		const_time_red_new = time_red_new;
		const_time_green_new = time_green_new;
		const_time_yellow_new = time_yellow_new;
		status = SET_RED;
		setTimer(3, 1000);
		setTimer(4, 250);
	case SET_RED:
		led_red_and_green();
		if (timer_flag[3] == 1) {
			time_green_new--;
			time_red_new--;
			if (time_green_new == 0) {
				status = SET_YELLOW;
			}
			setTimer(3, 1000);
		}
		if (timer_flag[4] == 1) {
			displaySettingX(time_green_new);
			displaySetting(time_red_new);
			setTimer(4, 250);
		}
		break;
	case SET_GREEN:
		led_green_and_red();
		if (timer_flag[3] == 1) {
			time_green_new--;
			time_red_new--;
			if (time_green_new == 0) {
				status = SET_YELLOW_MAIN;
			}
			setTimer(3, 1000);
		}
		if (timer_flag[4] == 1) {
			displaySettingX(time_red_new);
			displaySetting(time_green_new);
			setTimer(4, 250);
		}
		break;
	case SET_YELLOW_MAIN:
		led_yellow_and_red();
		if (timer_flag[3] == 1) {
			time_red_new--;
			time_yellow_new--;
			if (time_red_new == 0) {
				time_red_new = const_time_red_new;
				time_green_new = const_time_green_new;
				time_yellow_new = const_time_yellow_new;
				status = SET_RED;
			}
			setTimer(3, 1000);
		}
		if (timer_flag[4] == 1) {
			displaySettingX(time_red_new);
			displaySetting(time_yellow_new);
			setTimer(4, 250);
		}
		break;
	case SET_YELLOW:
		led_red_and_yellow();
		if (timer_flag[3] == 1) {
			time_red_new--;
			time_yellow_new--;
			if (time_red_new == 0) {
				time_red_new = const_time_red_new;
				time_green_new = const_time_green_new;
				time_yellow_new = const_time_yellow_new;
				status = SET_GREEN;
			}
			setTimer(3, 1000);
		}
		if (timer_flag[4] == 1) {
			displaySettingX(time_yellow_new);
			displaySetting(time_red_new);
			setTimer(4, 250);
		}
		break;
	default:
		break;
	}
}

