from math import *
import imageio

leds_position = {
    1: -15,
    2: -14,
    3: -13,
    4: -12,
    5: -11,
    6: -10,
    7: -9,
    8: -8,
    9: -7,
    10: -6,
    11: -5,
    12: -4,
    13: -3,
    14: -2,
    15: -1,
    16: 1,
    17: 2,
    18: 3,
    19: 4,
    20: 5,
    21: 6,
    22: 7,
    23: 8,
    24: 9,
    25: 10,
    26: 11,
    27: 12,
    28: 13,
    29: 14,
    30: 15
}

output = open ("Animation_data.txt", "w")
frames = 5
for frame in range (frames):
    frame_name = str (frame) + ".png"
    image = imageio.imread (frame_name, as_gray = False, pilmode = "RGBA")
    if image.shape [0] != 31 and image.shape [1] != 31:
        print ("Image is not 31 x 31 pixels")
    else:
        for degrees in range (0, 180):
            c = cos (degrees * pi / 180)
            s = sin (degrees * pi / 180)
            for leds in leds_position:
                x = leds_position[leds] * c
                x = round (x)
                x += 15
                y = leds_position[leds] * s
                y = round (y)
                y += 15
                pixel = image [y, x]
                if (pixel [3] == 255): output.write (str ((pixel [0] << 16) | (pixel [1] <<  8) | pixel [2]) + " ")
                else: output.write ("0 ")
            output.write ("\n")
    output.write ("\n\n\n")
output.close ()
