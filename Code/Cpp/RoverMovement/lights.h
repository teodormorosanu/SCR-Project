#ifndef LIGHTS_H
#define LIGHTS_H

#include <Arduino.h>

const uint8_t PIN_BEAM_LEFT  = A0;
const uint8_t PIN_BEAM_RIGHT = A1;

void setup_beams();
void beam_left(bool mode);
void beam_right(bool mode);
void set_beams(bool mode);

#endif // LIGHTS_H