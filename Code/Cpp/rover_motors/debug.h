#ifndef DEBUG_H
#define DEBUG_H

#include <Arduino.h>

void flash_beams(uint8_t count = 3, uint16_t delay_ms = 150);
void run_hardware_diagnostics();

#endif // DEBUG_H