/*
 * button.h
 *
 *  Created on: Nov 22, 2022
 *      Author: khuon
 */

#ifndef INC_BUTTON_H_
#define INC_BUTTON_H_

#include "main.h"

#define NORMAL_STATE	GPIO_PIN_SET
#define PRESSED_STATE	GPIO_PIN_RESET

extern int button_flag;

int isPressedButton();

void getKeyInput();

#endif /* INC_BUTTON_H_ */
