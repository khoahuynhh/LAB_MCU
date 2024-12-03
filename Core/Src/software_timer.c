/*
 * software_timer.h
 *
 *  Created on: Dec 3, 2024
 *      Author: Admin
 */

#ifndef SRC_SOFTWARE_TIMER_C_
#define SRC_SOFTWARE_TIMER_C_

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

#endif /* SRC_SOFTWARE_TIMER_C_ */
