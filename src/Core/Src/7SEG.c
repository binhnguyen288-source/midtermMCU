#include "7SEG.h"
#include "main.h"

#define SEG_a GPIO_PIN_0
#define SEG_b GPIO_PIN_1
#define SEG_c GPIO_PIN_2
#define SEG_d GPIO_PIN_3
#define SEG_e GPIO_PIN_4
#define SEG_f GPIO_PIN_5
#define SEG_g GPIO_PIN_6

void display7SEG(int num) {


  static const uint16_t ALL_SEGS = 0x7f;
  
  static const uint16_t LUT_SET[] = {
    SEG_g,                                // 0
    ALL_SEGS &~ (SEG_b | SEG_c),          // 1
    SEG_c | SEG_f,                        // 2
    SEG_e | SEG_f,                        // 3
    SEG_a | SEG_d | SEG_e,                // 4
    SEG_b | SEG_e,                        // 5
    SEG_b,                                // 6
    ALL_SEGS &~ (SEG_a | SEG_b | SEG_c),  // 7
    0,                                    // 8
    SEG_e                                 // 9
  };

  const uint16_t SET_SEGS = LUT_SET[num];
  
  GPIOB->BSRR = SET_SEGS | ((uint32_t)(ALL_SEGS & ~SET_SEGS) << 16u);

}