#include <stdint.h>
#include "stm32g4xx.h"
#include "system_stm32g4xx.h"
#include "nucleo_g474.h"
#include "rcc.h"
#include "gpio.h"


// Timer
void Delay(uint16_t time) {
    for (uint16_t i = 0; i < time; i++) {
        for (volatile uint32_t j = 0; j < 1000; j++);
    }
}



int main(void) {
    SystemInit();                 // Initialize system from STM
    BoardInit();



    while(1) {
        // Blinky
        //GPIO_High(GPIOA, 5); // Set pin 5 high
        //Delay(50000);         // Delay
        //GPIO_Low(GPIOA, 5);  // Set pin 5 low
        //Delay(50000);
        // User button toggle
        GPIO_Low(GPIOA, 5);
        GPIO_High(GPIOA, 6);

        if (GPIO_ReadInput(GPIOB, 6)) {
        GPIO_High(GPIOA, 5);
        }

        if (GPIO_ReadInput(GPIOA, 9)) {
        GPIO_High(GPIOA, 5);
        }

        if (GPIO_ReadInput(GPIOC, 7)) {
        GPIO_High(GPIOA, 5);
        }
        if (GPIO_ReadInput(GPIOC, 13) == true) {
        GPIO_High(GPIOA, 5);
        }
    }  
}