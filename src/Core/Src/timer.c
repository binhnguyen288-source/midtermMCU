#include "timer.h"
#include <stdint.h>
static int timer1 = 100;
static int timer1_flag = 0;
int isTimer1Flag() {
    int ret = timer1_flag;
    timer1_flag = 0;
    return ret;
}

void runTimer1() {
    --timer1;
    if (timer1 == 0) {
        timer1_flag = 1;
        timer1 = 100;
    }
}


static int timer10_flag = 0;
static int timer10 = 1000;

int isTimer10Flag() {
    int ret = timer10_flag;
    timer10_flag = 0;
    return ret;
}

void runTimer10() {
    --timer10;
    if (timer10 == 0) {
        timer10_flag = 1;
        timer10 = 100;
    }
}

void resetTimer10() {
    timer10 = 1000;
    timer10_flag = 0;
}