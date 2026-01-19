/*
**
**
**
** 
*/

#include <stdint.h>
#include "stm32g474xx.h"


typedef enum {
INPUT = 0x0;
OUTPUT = 0x1;
AF = 0x2;
ANALOG = 0x3;
} gpio_mode;

void GPIO_SetMode(GPIO_Typedef *port,,uint8_t pin, gpio_mode mode);
