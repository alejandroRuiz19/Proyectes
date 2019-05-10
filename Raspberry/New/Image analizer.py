from math import *
import imageio

leds_position = {
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
    30: -1,
    31: 1,
    32: 2,
    33: 3,
    34: 4,
    35: 5,
    36: 6,
    37: 7,
    38: 8,
    39: 9,
    40: 10,
    41: 11,
    42: 12,
    43: 13,
    44: 14,
    45: 15,
    46: 16,
    47: 17,
    48: 18,
    49: 19,
    50: 20,
    51: 21,
    52: 22,
    53: 23,
    54: 24,
    55: 25,
    56: 26,
    57: 27,
    58: 28,
    59: 29,
    60: 30
}

image = imageio.imread ("Image.png", as_gray = False, pilmode = "RGBA")

if image.shape [0] != 61 and image.shape [1] != 61:
    print ("Image is not 61 x 61 pixels")
else:
    output = open ("Image_data.txt", "w")
    for degrees in range (0, -360, -1):
        c = cos (degrees * pi / 180)
        s = sin (degrees * pi / 180)
        for leds in leds_position:
            x = leds_position[leds] * c
            x = round (x)
            x += 30
            y = leds_position[leds] * s
            y = round (y)
            y += 30
            pixel = image [y, x]
            if (pixel [3] == 255): output.write (str ((pixel [0] << 16) | (pixel [1] <<  8) | pixel [2]) + " ")
            else: output.write ("0 ")
        output.write ("\n")
    output.close ()
