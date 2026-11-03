# --- LIBRARIES --- #

from picamera2 import Picamera2
import numpy as np
import cv2

# --- GLOBAL VARIABLES --- #

# Connecting camera
picam2 = Picamera2()
picam2.start()
time.sleep(1)

# --- FUNCTIONS --- #

# Processing image function
# Please add adjacent functions for the image processing function
def process_image():
    # Can return something like "Box", "Cylinder", "Sebi", etc. or someting
    # else that is needed for further movement instructions.
    return ""

# Getting the object rough dimensions ([x, y, z])
# Please add adjacent functions for the object dimensions function
def object_dimensions():
    dimensions = [0, 0, 0]
    return dimensions

