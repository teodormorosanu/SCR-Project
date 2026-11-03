#include "lights.h"
#include "motors.h"

// Comenteaza linia de mai jos cand proiectul este finalizat:
#define DEBUG_MODE

#ifdef DEBUG_MODE
  #include "debug.h"
#endif

void setup() {
  Serial.begin(9600);
  setup_motors();
  setup_beams();

  #ifdef DEBUG_MODE
    // Executa autotestul cu flash-uri la pornire
    run_hardware_diagnostics();
  #endif
}

void loop() {
  if (Serial.available() > 0) {
    char cmd = Serial.read();

    switch (cmd) {
      case 'F': driveForward();  break;
      case 'B': driveBackward(); break;
      case 'L': turnLeft();      break;
      case 'R': turnRight();     break;

      case 'S':
      case 'E':
        stopMotors();
        break;

      case '1': set_motors(0, SPEED_SLOW);   break;
      case '2': set_motors(0, SPEED_NORMAL); break;
      case '3': set_motors(0, SPEED_FAST);   break;

      case 'H': set_beams(true);  break;
      case 'h': set_beams(false); break;

      #ifdef DEBUG_MODE
      // Comanda seriala de debug pentru flash la cerere
      case 'X':
        flash_beams(3, 150);
        break;
      #endif

      default:
        break;
    }
  }
}