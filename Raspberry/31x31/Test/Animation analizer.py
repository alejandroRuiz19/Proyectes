from math import *
import imageio

left_leds_position = {
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
    15: -1
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
    15: 15
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
            output.write ("{ ")
            c = cos (degrees * pi / 180)
            s = sin (degrees * pi / 180)
            for leds in left_leds_position:
                x = left_leds_position[leds] * c
                x = round (x)
                x += 15
                y = left_leds_position[leds] * s
                y = round (y)
                y += 15
                pixel = image [y, x]
                if (pixel [3] == 255): output.write (str ((pixel [0] << 16) | (pixel [1] <<  8) | pixel [2]))
                else: output.write ("0")
                if (leds != 15): output.write (",")
            if (degrees != 179): output.write (" },\n")
            else: output.write (" }")
        output.write ("\n\n")
        for degrees in range (0, 180):
            output.write ("{ ")
            c = cos (degrees * pi / 180)
            s = sin (degrees * pi / 180)
            for leds in right_leds_position:
                x = right_leds_position[leds] * c
                x = round (x)
                x += 15
                y = right_leds_position[leds] * s
                y = round (y)
                y += 15
                pixel = image [y, x]
                if (pixel [3] == 255): output.write (str ((pixel [0] << 16) | (pixel [1] <<  8) | pixel [2]))
                else: output.write ("0")
                if (leds != 15): output.write (",")
            if (degrees != 179): output.write (" },\n")
            else: output.write (" }")
    output.write ("\n\n---------------\n\n")
output.close ()
