/*
**
**
**
**
*/


#include "gpio.h"



// Mode Register
void GPIO_SetMode(GPIO_Typedef *port, uint8_t gpio_pin, gpio_mode mode) {
    if (port == GPIOA) {
        GPIOA->MODER &= ~(0x3 << (gpio_pin * 2)); // Set all to 0
        GPIOA->MODER |= (mode << (gpio_pin * 2)); // Set to mode
    } else
    if (port == GPIOB) {
        GPIOB->MODER &= ~(0x3 << (gpio_pin * 2)); // Set all to 0
        GPIOB->MODER |= (mode << (gpio_pin * 2)); // Set to mode
    } else
    if (port == GPIOC) {
        GPIOC->MODER &= ~(0x3 << (gpio_pin * 2)); // Set all to 0
        GPIOC->MODER |= (mode << (gpio_pin * 2)); // Set to mode
    } else
    if (port == GPIOD) {
        GPIOD->MODER &= ~(0x3 << (gpio_pin * 2)); // Set all to 0
        GPIOD->MODER |= (mode << (gpio_pin * 2)); // Set to mode
    } else
    if (port == GPIOE) {
        GPIOE->MODER &= ~(0x3 << (gpio_pin * 2)); // Set all to 0
        GPIOE->MODER |= (mode << (gpio_pin * 2)); // Set to mode
    }
}

// Output Type
void GPIOA_SetOutputType() {

}


// Output Speed
void GPIOA_SetOutputSpeed() {

}


// Pull up/down
void GPIOA_SetResistor() {

}

// Input Data Register
void GPIOA_ReadInput() {

}

// Output Data Register
void GPIOA_ReadOutput() {

}

// Bit Set and Reset Register
void GPIOA_High(uint8_t pin) {

}

void GPIOA_Low(uint8_t pin) {

}
