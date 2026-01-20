/*
**
**
**
**
*/

#include "gpio.h"



// Mode Register
void GPIO_SetMode(GPIO_TypeDef *port, uint8_t gpio_pin, gpio_mode mode) {
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
void GPIO_SetOutputType() {

}


// Output Speed
void GPIO_SetOutputSpeed() {

}


// Pull up/down
void GPIO_SetPull(GPIO_TypeDef *port, uint8_t pin, pupd_mode pupd) {
    port->PUPDR &= ~(0x3 << (pin * 2));
    port->PUPDR |= (pupd << (pin * 2));
}

// Input Data Register
// Bits 0-15 read only
// Each bit corresponds to a pin if the pin exists
bool GPIO_ReadInput(GPIO_TypeDef *port, uint8_t pin) {
    return (port->IDR & (1 << pin)) != 0;
}

// Output Data Register
void GPIO_ReadOutput() {

}

// Bit Set and Reset Register
//
// Can just use port->BSRR
void GPIO_High(GPIO_TypeDef *port, uint8_t pin) {
    if (port == GPIOA) {
        GPIOA->BSRR = (1U << pin);
    }
    else if (port == GPIOB) {
        GPIOB->BSRR = (1U << pin);
    }
    else if (port == GPIOC) {
        GPIOC->BSRR = (1U << pin);
    }
    else if (port == GPIOD) {
        GPIOD->BSRR = (1U << pin);
    }
    else if (port == GPIOE) {
        GPIOE->BSRR = (1U << pin);
    }
}

void GPIO_Low(GPIO_TypeDef *port, uint8_t pin) {
    if (port == GPIOA) {
        GPIOA->BSRR = (1U << (pin + 16));
    }
    else if (port == GPIOB) {
        GPIOB->BSRR = (1U << (pin + 16));
    }
    else if (port == GPIOC) {
        GPIOC->BSRR = (1U << (pin + 16));
    }
    else if (port == GPIOD) {
        GPIOD->BSRR = (1U << (pin + 16));
    }
    else if (port == GPIOE) {
        GPIOE->BSRR = (1U << (pin + 16));
    }
}
