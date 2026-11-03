#include "lights.h"

void setup_beams() {
  pinMode(PIN_BEAM_LEFT, OUTPUT);
  pinMode(PIN_BEAM_RIGHT, OUTPUT);
  digitalWrite(PIN_BEAM_LEFT, LOW);
  digitalWrite(PIN_BEAM_RIGHT, LOW);
}

void beam_left(bool mode) {
  digitalWrite(PIN_BEAM_LEFT, mode ? HIGH : LOW);
}

void beam_right(bool mode) {
  digitalWrite(PIN_BEAM_RIGHT, mode ? HIGH : LOW);
}

void set_beams(bool mode) {
  digitalWrite(PIN_BEAM_LEFT, mode ? HIGH : LOW);
  digitalWrite(PIN_BEAM_RIGHT, mode ? HIGH : LOW);
}