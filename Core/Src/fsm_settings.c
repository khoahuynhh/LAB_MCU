/*
 * fsm_manual.c
 *
 *  Created on: Oct 29, 2024
 *      Author: Admin
 */

#include "fsm_settings.h"

void fsm_settings_run() {
	switch (status) {
	case MAN_RED:
		set_7SEG_X(LEDS_7SEG_state[2]);
		if (timer_flag[0] == 1) {
			init();
			init_time();
			status = AUTO_RED;
			setTimer(0, 1000);
		}
		if (timer_flag[2] == 1) {
			blinking_led_red();
			setTimer(2, 500);
		}
		if (timer_flag[3] == 1) {
			displaySetting(count);
			setTimer(3, 250);
		}
		if (isButton1Pressed(0) == 1) {
			time_red_update = count;
			count = 1;
			init();
			status = MAN_GREEN;
		}
		if (isButton1Pressed(1) == 1) {
			if (count > 99) {
				count = 1;
			}
			count++;
		}
		break;
	case MAN_GREEN:
		set_7SEG_X(LEDS_7SEG_state[3]);
		if (timer_flag[2] == 1) {
			blinking_led_green();
			setTimer(2, 500);
		}
		if (timer_flag[3] == 1) {
			displaySetting(count);
			setTimer(3, 250);
		}
		if (isButton1Pressed(0) == 1) {
			time_green_update = count;
			count = 1;
			init();
			status = MAN_YELLOW;
		}
		if (isButton1Pressed(1) == 1) {
			if (count > 99) {
				count = 1;
			}
			count++;
		}
		break;
	case MAN_YELLOW:
		set_7SEG_X(LEDS_7SEG_state[4]);
		if (timer_flag[2] == 1) {
			blinking_led_yellow();
			setTimer(2, 500);
		}
		if (timer_flag[3] == 1) {
			displaySetting(count);
			setTimer(3, 250);
		}
		if (isButton1Pressed(0) == 1) {
			count = 1;
			init();
			time_red = 5;
			time_green = 3;
			time_yellow = 2;
			status = AUTO_RED;
			setTimer(0, 1000);
		}
		if (isButton1Pressed(1) == 1) {
			if (count > 99) {
				count = 1;
			}
			count++;
		}
		if (isButton1Pressed(2) == 1) {
			time_yellow_update = count;
			init_time();
			status = AUTO_RED;
			setTimer(0, 1000);
		}
		break;
	default:
		break;
	}
}
