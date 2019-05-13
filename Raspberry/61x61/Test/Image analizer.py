from math import *
import imageio

left_leds_position = {
    1: -30,
    2: -29,
    3: -28,
    4: -27,
    5: -26,
    6: -25,
    7: -24,
    8: -23,
    9: -22,
    10: -21,
    11: -20,
    12: -19,
    13: -18,
    14: -17,
    15: -16,
    16: -15,
    17: -14,
    18: -13,
    19: -12,
    20: -11,
    21: -10,
    22: -9,
    23: -8,
    24: -7,
    25: -6,
    26: -5,
    27: -4,
    28: -3,
    29: -2,
    30: -1
}

right_leds_position = {
    1: 1,
    2: 2,
    3: 3,
    4: 4,
    5: 5,
    6: 6,
    7: 7,
    8: 8,
    9: 9,
    10: 10,
    11: 11,
    12: 12,
    13: 13,
    14: 14,
    15: 15,
    16: 16,
    17: 17,
    18: 18,
    19: 19,
    20: 20,
    21: 21,
    22: 22,
    23: 23,
    24: 24,
    25: 25,
    26: 26,
    27: 27,
    28: 28,
    29: 29,
    30: 30
}

image = imageio.imread ("Image.png", as_gray = False, pilmode = "RGBA")

if image.shape [0] != 61 and image.shape [1] != 61:
    print ("Image is not 61 x 61 pixels")
else:
    output = open ("Image_data.txt", "w")
    for degrees in range (0, -180, -1):
        output.write ("{ ")
        c = cos (degrees * pi / 180)
        s = sin (degrees * pi / 180)
        for leds in left_leds_position:
            x = left_leds_position[leds] * c
            x = round (x)
            x += 30
            y = left_leds_position[leds] * s
            y = round (y)
            y += 30
            pixel = image [y, x]
            if (pixel [3] == 255): output.write (str ((pixel [0] << 16) | (pixel [1] <<  8) | pixel [2]))
            else: output.write ("0")
            if (leds != 60): output.write (",")
        if (degrees != -179): output.write (" },\n")
        else: output.write (" }")
    output.write ("\n\n")
    for degrees in range (0, -180, -1):
        output.write ("{ ")
        c = cos (degrees * pi / 180)
        s = sin (degrees * pi / 180)
        for leds in right_leds_position:
            x = right_leds_position[leds] * c
            x = round (x)
            x += 30
            y = right_leds_position[leds] * s
            y = round (y)
            y += 30
            pixel = image [y, x]
            if (pixel [3] == 255): output.write (str ((pixel [0] << 16) | (pixel [1] <<  8) | pixel [2]))
            else: output.write ("0")
            if (leds != 60): output.write (",")
        if (degrees != -179): output.write (" },\n")
        else: output.write (" }")
    output.close ()
