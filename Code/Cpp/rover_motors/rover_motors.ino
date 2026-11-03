#include "lights.h"
#include "motors.h"

// Comenteaza linia de mai jos daca nu vrei autotestul cu flash-uri la pornire
#define DEBUG_MODE

#ifdef DEBUG_MODE
  #include "debug.h"
#endif

// Proceseaza fiecare comanda primita pe seriala de la Raspberry Pi
void handleCommand(char cmd) {
  switch (cmd) {
    // Comenzi de miscare
    case 'F': driveForward();  break;
    case 'B': driveBackward(); break;
    case 'L': turnLeft();      break;
    case 'R': turnRight();     break;

    // Oprire de urgenta
    case 'E':
      stopMotors();
      break;

    // Trepte PWM de viteza
    case '1': set_motors(0, SPEED_SLOW);   break;
    case '2': set_motors(0, SPEED_NORMAL); break;
    case '3': set_motors(0, SPEED_FAST);   break;

    // Control faruri
    case 'H': set_beams(true);  break;
    case 'h': set_beams(false); break;

    #ifdef DEBUG_MODE
    case 'X': flash_beams(3, 150); break;
    #endif

    default:
      break;
  }
}

void setup() {
  Serial.begin(9600);[cite: 1]
  setup_motors();
  setup_beams();

  #ifdef DEBUG_MODE
    run_hardware_diagnostics();
  #endif
}

void loop() {
  if (Serial.available() > 0) {[cite: 1]
    char incomingChar = Serial.read();[cite: 1]
    handleCommand(incomingChar);
  }
}