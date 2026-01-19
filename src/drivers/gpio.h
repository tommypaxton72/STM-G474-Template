/*
**
**
**
** 
*/

#include <stdint.h>
#include "stm32g474xx.h"


#ifdef __cplusplus
extern c {
#endif

typedef enum {
INPUT = 0x0;
OUTPUT = 0x1;
AF = 0x2;
ANALOG = 0x3;
} gpio_mode;

void GPIO_SetMode(GPIO_Typedef *port,,uint8_t pin, gpio_mode mode);










void GPIOA_High(GPIO_Typedef *port, uint8_t pin)
void GPIOA_Low(GPIO_Typedef *port, uint8_t pin)



#ifdef __cplusplus
}
#endif
