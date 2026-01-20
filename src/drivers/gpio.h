/*
**
**
**
** 
*/
#ifndef GPIO_H
#define GPIO_H
#include <stdint.h>
#include <stdbool.h>
#include "stm32g474xx.h"


#ifdef __cplusplus
extern c {
#endif

typedef enum {
INPUT = 0x0,
OUTPUT = 0x1,
AF = 0x2,
ANALOG = 0x3,
} gpio_mode;


// PUPDR
// 00 = No Pull
// 01 = Pull up
// 10 = Pull down
// 11 = Reserved
typedef enum {
NOPULL = 0x0,
PULLUP = 0x1,
PULLDOWN = 0x2,
} pupd_mode;

void GPIO_SetMode(GPIO_TypeDef *port, uint8_t pin, gpio_mode mode);


void GPIO_SetPull(GPIO_TypeDef *port, uint8_t pin, pupd_mode pupd);
bool GPIO_ReadInput(GPIO_TypeDef *port, uint8_t pin);






void GPIO_High(GPIO_TypeDef *port, uint8_t pin);
void GPIO_Low(GPIO_TypeDef *port, uint8_t pin);



#ifdef __cplusplus
}
#endif

#endif
