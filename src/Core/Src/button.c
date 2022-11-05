#include "button.h"
#include "main.h"
#include "timer.h"
#define PRESSED_STATE RESET
#define NORMAL_STATE SET

static int RESET_flag = 0;
static int INC_flag = 0;
static int DEC_flag = 0;

static int INC_longpressed = 0;
static int DEC_longpressed = 0;

void getRESETInput() {
    static int KeyReg0 = NORMAL_STATE;
    static int KeyReg1 = NORMAL_STATE;
    static int KeyReg2 = NORMAL_STATE;
    static int KeyReg3 = NORMAL_STATE;
    KeyReg2 = KeyReg1;
    KeyReg1 = KeyReg0;
    KeyReg0 = HAL_GPIO_ReadPin(RESET_GPIO_Port, RESET_Pin);
    if (KeyReg2 == KeyReg1 && KeyReg1 == KeyReg0) {
        if (KeyReg3 != KeyReg2) {
            KeyReg3 = KeyReg2;
            if (KeyReg3 == PRESSED_STATE) {
                RESET_flag = 1;
                resetTimer10();
            }
        }
    }
}

void getINCInput() {
    static int pressCountdown = 300;
    static int KeyReg0 = NORMAL_STATE;
    static int KeyReg1 = NORMAL_STATE;
    static int KeyReg2 = NORMAL_STATE;
    static int KeyReg3 = NORMAL_STATE;
    KeyReg2 = KeyReg1;
    KeyReg1 = KeyReg0;
    KeyReg0 = HAL_GPIO_ReadPin(INC_GPIO_Port, INC_Pin);
    if (KeyReg2 == KeyReg1 && KeyReg1 == KeyReg0) {
        if (KeyReg3 != KeyReg2) {
            KeyReg3 = KeyReg2;
            if (KeyReg3 == PRESSED_STATE) {
                pressCountdown = 300;
                INC_flag = 1;
                resetTimer10();
            }
            else {
                INC_longpressed = 0;
            }
        }
        else {
            if (KeyReg3 == PRESSED_STATE) {
                resetTimer10();
                if (pressCountdown == 0) {
                    INC_longpressed = 1;
                    pressCountdown = 100;
                }
                else --pressCountdown;
            }
        }
    }
}

void getDECInput() { 
    static int pressCountdown = 300;
    static int KeyReg0 = NORMAL_STATE;
    static int KeyReg1 = NORMAL_STATE;
    static int KeyReg2 = NORMAL_STATE;
    static int KeyReg3 = NORMAL_STATE;
    KeyReg2 = KeyReg1;
    KeyReg1 = KeyReg0;
    KeyReg0 = HAL_GPIO_ReadPin(DEC_GPIO_Port, DEC_Pin);
    if (KeyReg2 == KeyReg1 && KeyReg1 == KeyReg0) {
        if (KeyReg3 != KeyReg2) {
            KeyReg3 = KeyReg2;
            if (KeyReg3 == PRESSED_STATE) {
                pressCountdown = 300;
                DEC_flag = 1;
                resetTimer10();
            }
            else {
                DEC_longpressed = 0;
            }
        }
        else {
            if (KeyReg3 == PRESSED_STATE) {
                resetTimer10();
                if (pressCountdown == 0) {
                    DEC_longpressed = 1;
                    pressCountdown = 100;
                }
                else --pressCountdown;
            }
        }
    }

}

int isRESETPressed() {
    int ret = RESET_flag;
    RESET_flag = 0;
    return ret;
}

int isINCPressed() {
    int ret = INC_flag;
    INC_flag = 0;
    return ret;
}

int isDECPressed() {
    int ret = DEC_flag;
    DEC_flag = 0;
    return ret;
}

int isINCLongPressed() {
    int ret = INC_longpressed;
    INC_longpressed = 0;
    return ret;
}

int isDECLongPressed() {
    int ret = DEC_longpressed;
    DEC_longpressed = 0;
    return ret;
}