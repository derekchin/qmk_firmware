#ifndef ERGODOX_EZ_H
#define ERGODOX_EZ_H

#include "quantum.h"
#include <stdint.h>
#include <stdbool.h>
#include "i2cmaster.h"
#include <util/delay.h>

#define CPU_PRESCALE(n) (CLKPR = 0x80, CLKPR = (n))
#define CPU_16MHz       0x00

// I2C aliases and register addresses (see "mcp23018.md")
#define I2C_ADDR        0b0100000
#define I2C_ADDR_WRITE  ( (I2C_ADDR<<1) | I2C_WRITE )
#define I2C_ADDR_READ   ( (I2C_ADDR<<1) | I2C_READ  )
#define IODIRA          0x00            // i/o direction register
#define IODIRB          0x01
#define GPPUA           0x0C            // GPIO pull-up resistor register
#define GPPUB           0x0D
#define GPIOA           0x12            // general purpose i/o port register (write modifies OLAT)
#define GPIOB           0x13
#define OLATA           0x14            // output latch register
#define OLATB           0x15

extern uint8_t mcp23018_status;

void init_ergodox(void);
void ergodox_blink_all_leds(void);
uint8_t init_mcp23018(void);
uint8_t ergodox_left_leds_update(void);

#ifndef LED_BRIGHTNESS_LO
#define LED_BRIGHTNESS_LO       15
#endif
#ifndef LED_BRIGHTNESS_LO
#define LED_BRIGHTNESS_HI       255
#endif


inline void ergodox_board_led_on(void)      { DDRD |=  (1<<6); PORTD |=  (1<<6); }
inline void ergodox_right_led_1_on(void)    { DDRB |=  (1<<5); PORTB |=  (1<<5); }
inline void ergodox_right_led_2_on(void)    { DDRB |=  (1<<6); PORTB |=  (1<<6); }
inline void ergodox_right_led_3_on(void)    { DDRB |=  (1<<7); PORTB |=  (1<<7); }
inline void ergodox_right_led_on(uint8_t led) { DDRB |= (1<<(led+4)); PORTB |= (1<<(led+4)); }

inline void ergodox_board_led_off(void)     { DDRD &= ~(1<<6); PORTD &= ~(1<<6); }
inline void ergodox_right_led_1_off(void)   { DDRB &= ~(1<<5); PORTB &= ~(1<<5); }
inline void ergodox_right_led_2_off(void)   { DDRB &= ~(1<<6); PORTB &= ~(1<<6); }
inline void ergodox_right_led_3_off(void)   { DDRB &= ~(1<<7); PORTB &= ~(1<<7); }
inline void ergodox_right_led_off(uint8_t led) { DDRB &= ~(1<<(led+4)); PORTB &= ~(1<<(led+4)); }

#ifdef LEFT_LEDS
bool ergodox_left_led_1;
bool ergodox_left_led_2;
bool ergodox_left_led_3;

inline void ergodox_left_led_1_on(void)    { ergodox_left_led_1 = 1; }
inline void ergodox_left_led_2_on(void)    { ergodox_left_led_2 = 1; }
inline void ergodox_left_led_3_on(void)    { ergodox_left_led_3 = 1; }

inline void ergodox_left_led_1_off(void)    { ergodox_left_led_1 = 0; }
inline void ergodox_left_led_2_off(void)    { ergodox_left_led_2 = 0; }
inline void ergodox_left_led_3_off(void)    { ergodox_left_led_3 = 0; }
#endif // LEFT_LEDS

inline void ergodox_led_all_on(void)
{
    ergodox_board_led_on();
    ergodox_right_led_1_on();
    ergodox_right_led_2_on();
    ergodox_right_led_3_on();
#ifdef LEFT_LEDS
    ergodox_left_led_1_on();
    ergodox_left_led_2_on();
    ergodox_left_led_3_on();
#endif // LEFT_LEDS
}

inline void ergodox_led_all_off(void)
{
    ergodox_board_led_off();
    ergodox_right_led_1_off();
    ergodox_right_led_2_off();
    ergodox_right_led_3_off();
#ifdef LEFT_LEDS
    ergodox_left_led_1_off();
    ergodox_left_led_2_off();
    ergodox_left_led_3_off();
#endif // LEFT_LEDS
}

inline void ergodox_right_led_1_set(uint8_t n)    { OCR1A = n; }
inline void ergodox_right_led_2_set(uint8_t n)    { OCR1B = n; }
inline void ergodox_right_led_3_set(uint8_t n)    { OCR1C = n; }
inline void ergodox_right_led_set(uint8_t led, uint8_t n)  {
    (led == 1) ? (OCR1A = n) :
    (led == 2) ? (OCR1B = n) :
                 (OCR1C = n);
}

inline void ergodox_led_all_set(uint8_t n)
{
    ergodox_right_led_1_set(n);
    ergodox_right_led_2_set(n);
    ergodox_right_led_3_set(n);
}

#define KEYMAP(                                                 \
                                                                \
    /* left hand, spatial positions */                          \
    k00,k01,k02,k03,k04,k05,k06,                                    \
    k10,k11,k12,k13,k14,k15,k16,                                    \
    k20,k21,k22,k23,k24,k25,k26,                                    \
    k30,k31,k32,k33,k34,k35,k36,                                    \
            k42,k43,k44,k45,                                    \
/* in the next two lines the order is not following the logic, magic */ \
                    k52,k55,                                    \
                    k53,k54,                                    \
                                                                \
    /* right hand, spatial positions */                         \
            k07,k08,k09,k0A,k0B,k0C,k0D,                            \
            k17,k18,k19,k1A,k1B,k1C,k1D,                            \
            k27,k28,k29,k2A,k2B,k2C,k2D,                            \
            k37,k38,k39,k3A,k3B,k3C,k3D,                            \
/* in the next line the order is not following the logic, whatever */ \
                k4A,k4B,k48,k49,                                    \
                k58,k5B,                                            \
                k59,k5A          					\
    )                                                           \
                                                                \
   /* matrix positions */                                       \
   {                                                            \
    { KC_NO, k10, k20, k30, KC_NO, KC_NO },   \
    { KC_NO, k11, k21, k31, KC_NO, KC_NO },   \
    { KC_NO, k12, k22, k32, k42, k52 },   \
    { KC_NO, k13, k23, k33, k43, k53 },   \
    { KC_NO, k14, k24, k34, k44, k54 },   \
    { KC_NO, k15, k25, k35, k45, k55 },   \
    { KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO },   \
                                                            \
    { KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO  },   \
    { KC_NO, k18, k28, k38, k48, k58 },   \
    { KC_NO, k19, k29, k39, k49, k59 },   \
    { KC_NO, k1A, k2A, k3A, k4A, k5A },   \
    { KC_NO, k1B, k2B, k3B, k4B, k5B },   \
    { KC_NO, k1C, k2C, k3C, KC_NO, KC_NO },   \
    { KC_NO, k1D, k2D, k3D, KC_NO, KC_NO }    \
   }


#define LAYOUT_ergodox KEYMAP

#endif
