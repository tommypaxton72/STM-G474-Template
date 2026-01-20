#include <stdint.h>
#include "stm32g474xx.h"

#ifndef RCC_H
#define RCC_H


#ifdef __cplusplus
extern "C" {
#endif


/*
**
**
**
**
*/


void rcc_Init();
void rcc_Enable_gpio(GPIO_TypeDef *port);
































#ifdef __cplusplus
}
#endif

#endif
