#include "button.h"

int button_flag = 0;

int keyReg1 = NORMAL_STATE;
int keyReg2 = NORMAL_STATE;
int keyReg3 = NORMAL_STATE;
int keyReg4 = NORMAL_STATE;

int timeOut = 100;

//int isPressedButton() {
//	if (button_flag == 1) {
//		button_flag = 0;
//		return 1;
//	}
//	return 0;
//}

void subKeyProcess() {
	HAL_GPIO_TogglePin(LED_RED_GPIO_Port, LED_RED_Pin);
}

void getKeyInput() {
	keyReg1 = keyReg2;
	keyReg2 = keyReg3;
	keyReg3 = HAL_GPIO_ReadPin(button_GPIO_Port, button_Pin);

	if ((keyReg1 == keyReg2) && (keyReg2 == keyReg3)) {
		if (keyReg3 != keyReg4) {
			keyReg4 = keyReg3;
			if (keyReg4 == PRESSED_STATE)
			subKeyProcess();
			timeOut = 100;
		} else {
			timeOut--;
			if (timeOut <= 0) {
				keyReg4 = NORMAL_STATE;
			}
		}
	}
}
