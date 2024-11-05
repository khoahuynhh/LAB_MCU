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

extern int button1_long_pressed[10];
extern int button1_pressed[10];
extern int button1_flag[10];
extern int KeyReg0[10];
extern int KeyReg1[10];
extern int KeyReg2[10];
extern int KeyReg3[10];
extern int TimeOutForKeyPress;

void getKeyInput();
int isButton1Pressed(int index);
int isButton1LongPressed(int index);
void subKeyProcess(int index);

#endif /* INC_BUTTON_H_ */
