# --- LIBRARIES --- #

import time
import serial
import Synapses

# --- GLOBAL VARIABLES --- #

# Connecting arduino
arduino = serial.Serial('/dev/ttyUSB0', 9600, timeout=1) 
time.sleep(3)

# --- FUNCTIONS --- #

# Sending instruction function
def send_instruction(instruction):
    arduino.write(instruction.encode())
    arduino.flush()
    time.sleep(0.05)

# Robot running cycle
def running(): 
    try:
        # Robot cycle (image recognision, drivin etc.)
        print("")
    except KeyboardInterrupt: # Pressing ctrl + c should stop the program
        # Robot emergency stop
        print("Emergency stop!")
        send_instruction('E')
    finally:
        # Ending robot running cycle
        send_instruction('S')
        picam2.stop()
        cv2.destroyAllWindows()
        arduino.close()

running()