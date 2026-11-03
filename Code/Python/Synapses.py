# --- LIBRARIES --- #

from picamera2 import Picamera2
import numpy as np
import cv2
import time

# --- GLOBAL VARIABLES --- #

# Calibrare la distanta fixa:
# PIXELS_PER_CM = lungimea masurata in pixeli / lungimea reala in cm.
# Exemplu: 100 pixeli / 5 cm = 20 pixeli/cm.
PIXELS_PER_CM = None

# Connecting camera
picam2 = Picamera2()
picam2.configure(
    picam2.create_preview_configuration(
        main={"size": (640, 480), "format": "RGB888"}
    )
)
picam2.start()
time.sleep(1)

# --- FUNCTIONS --- #

# Returneaza conturul celui mai mare obiect sau None.
# Necesita obiect intunecat, separat, pe fundal alb.
def process_image():
    image = picam2.capture_array("main")
    gray = cv2.cvtColor(image, cv2.COLOR_BGR2GRAY)
    gray = cv2.GaussianBlur(gray, (5, 5), 0)

    _, mask = cv2.threshold(
        gray, 0, 255, cv2.THRESH_BINARY_INV | cv2.THRESH_OTSU
    )

    contours, _ = cv2.findContours(
        mask, cv2.RETR_EXTERNAL, cv2.CHAIN_APPROX_SIMPLE
    )

    height, width = gray.shape
    objects = []

    for contour in contours:
        x, y, w, h = cv2.boundingRect(contour)

        if (
                cv2.contourArea(contour) > 500
                and x > 0
                and y > 0
                and x + w < width
                and y + h < height
        ):
            objects.append(contour)

    return max(objects, key=cv2.contourArea) if objects else None


# Getting the object rough dimensions ([x, y, z]), in cm.
# Calibrarea este valabila doar la aceeasi distanta si orientare.
def object_dimensions():
    contour = process_image()

    if contour is None:
        return [None, None, None]

    if (
            PIXELS_PER_CM is None
            or not np.isfinite(PIXELS_PER_CM)
            or PIXELS_PER_CM <= 0
    ):
        return [None, None, None]

    _, (w, h), _ = cv2.minAreaRect(contour)

    dimensions = [
        round(max(w, h) / PIXELS_PER_CM, 2),
        round(min(w, h) / PIXELS_PER_CM, 2),
        None  # Inaltimea nu poate fi determinata din aceasta imagine.
    ]

    return dimensions


# --- MAIN --- #

if __name__ == "__main__":
    try:
        print("Oprire: Ctrl+C")

        while True:
            dimensions = object_dimensions()

            if PIXELS_PER_CM is None:
                print("Calibrare necesara: completeaza PIXELS_PER_CM.")
            elif dimensions[0] is None:
                print("Nu pot determina dimensiunile obiectului.")
            else:
                print(
                    f"Lungime: {dimensions[0]} cm | "
                    f"Latime: {dimensions[1]} cm | "
                    "Inaltime: necunoscuta"
                )

            time.sleep(0.5)

    except KeyboardInterrupt:
        print("\nProgram oprit.")

    finally:
        try:
            picam2.stop()
        finally:
            picam2.close()