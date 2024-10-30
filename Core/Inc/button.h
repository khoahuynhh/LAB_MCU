/*
 * button.h
 *
 *  Created on: Oct 22, 2024
 *      Author: Admin
 */

#ifndef INC_BUTTON_H_
#define INC_BUTTON_H_

#include "main.h"

#define NORMAL_STATE SET
#define PRESSED_STATE RESET

extern int button1_flag[10];

void getKeyInput();

#endif /* INC_BUTTON_H_ */
