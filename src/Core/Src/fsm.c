#include "fsm.h"
#include "common.h"

void fsmstep1(int incPressed, int decPressed, int resetPressed) {
    enum State {
        IDLE,
        INC_COUNTER,
        DEC_COUNTER,
        RESET_COUNTER
    };
    static enum State state = IDLE;
    switch (state) {
        case IDLE: 
            if (incPressed) {
                state = INC_COUNTER;
            } else if (decPressed) {
                state = DEC_COUNTER;
            } else if (resetPressed) {
                state = RESET_COUNTER;
            }
            break;
        case INC_COUNTER: 
            counter = (counter + 1) % 10;
            state = IDLE;
            break;
        case DEC_COUNTER: 
            counter = (counter + 9) % 10;
            state = IDLE;
            break;
        case RESET_COUNTER:
            counter = 0;
            state = IDLE;
            break;
        default: 
            state = IDLE;
    }
}

void fsmstep2(int incLongPressed, int decLongPressed) {
    
    enum State {
        IDLE,
        INC_COUNTER,
        DEC_COUNTER
    };

    static enum State state = IDLE;

    switch (state) {
        case IDLE: 
            if (incLongPressed) {
                state = INC_COUNTER;
            }
            else if (decLongPressed) {
                state = DEC_COUNTER;
            }
            break;
        case INC_COUNTER: 
            counter = (counter + 1) % 10;
            state = IDLE;
            break;
        case DEC_COUNTER:
            counter = (counter + 9) % 10;
            state = IDLE;
            break;
        default: state = IDLE;
    }
}

void fsmstep3(int timer10Flag) {
    enum State {
        IDLE,
        COUNTDOWN_STEP
    };
    static enum State state = IDLE;
    switch (state) {
        case IDLE: {
            if (timer10Flag && counter > 0) {
                state = COUNTDOWN_STEP;
            }
        }
        break;
        case COUNTDOWN_STEP:
            --counter; 
            state = IDLE; 
        break;
        default: state = IDLE;
    }
}