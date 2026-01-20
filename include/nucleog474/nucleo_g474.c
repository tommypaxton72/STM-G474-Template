#include "nucleo_g474.h"


static bool EnableRCC();
static void EnablePins();

void BoardInit() {
    if (EnableRCC()) {
        EnablePins();
    }
}

static bool EnableRCC() {
    rcc_Enable_gpio(GPIOA); // Enable clock for port A
    rcc_Enable_gpio(GPIOC); // Enable Clock for port C
    return true;
}

static void EnablePins() {
    GPIO_SetMode(GPIOA, 5, OUTPUT);  // User LED
    GPIO_SetMode(GPIOC, 13, INPUT);  // User Button
    GPIO_SetPull(GPIOC, 13, PULLUP); // Set Button to pull up

}
