/*
 * sofware_timer.c
 *
 *  Created on: Oct 11, 2024
 *      Author: Admin
 */
#include "software_timer.h"
int timer_flag[10];
int timer_counter[10];
int timer_cycle = 10;
void setTimer(int index, int counter) {
	timer_flag[index] = 0;
	timer_counter[index] = counter / timer_cycle;
}
void timerRun() {
	for (int i = 0; i < 10; i++) {
		if (timer_counter[i] > 0) {
			timer_counter[i]--;
		} else {
			timer_flag[i] = 1;
		}
	}
}

