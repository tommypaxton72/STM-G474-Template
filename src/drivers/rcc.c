#include "rcc.h"



void rcc_Init() {

}

void rcc_Enable_gpio(GPIO_Typedef *port) {
    if (port == GPIOA) RCC->AHB2ENR |= RCC_AHB2ENR_GPIOAEN;
    else if (port == GPIOB) RCC->AHB2ENR |= RCC_AHB2ENR_GPIOBEN;
    else if (port == GPIOC) RCC->AHB2ENR |= RCC_AHB2ENR_GPIOCEN;
    else if (port == GPIOD) RCC->AHB2ENR |= RCC_AHB2ENR_GPIODEN;
    else if (port == GPIOE) RCC->AHB2ENR |= RCC_AHB2ENR_GPIOEEN;
}
