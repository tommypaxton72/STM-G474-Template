#include "system_stm32g4xx.h"
#include "rcc.h"
#include "gpio.h"



void Delay(uint16_t time) {
    for (uint16_t i; i > time; i++)
}



int main(void) {
    system_init();                 // Initialize system from STM
    rcc_Enable_gpio(GPIOA);        // Enable clock to GPIO bus
    GPIO_SetMode(GPIOA, 5, INPUT); // Set GPIO pin 5 to input



    while(1){
        GPIO_High(GPIOA, 5); // Set pin 5 high
        Delay(5000);         // Delay
        GPIO_Low(GPIOA, 5);  // Set pin 5 low
        Delay(2500);         // Delay
    }
}
