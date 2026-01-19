//
//
//
#include "stm32g474xx.h"
#include "rcc.h"

//
//
//
//
//


void rcc_enable_gpioa() {
    RCC ->AHB2ENR |= RCC_AHB2ENR_GPIOAEN;
}

void rcc_enable_gpiob() {
    RCC ->AHB2ENR |= RCC_AHB2ENR_GPIOBEN;
}

void rcc_enable_gpioc() {
    RCC ->AHB2ENR |= RCC_AHB2ENR_GPIOCEN;
}

void rcc_enable_gpiod() {
    RCC ->AHB2ENR |= RCC_AHB2ENR_GPIODEN;
}

void rcc_enable_gpioe() {
    RCC ->AHB2ENR |= RCC_AHB2ENR_GPIOEEN;
}
