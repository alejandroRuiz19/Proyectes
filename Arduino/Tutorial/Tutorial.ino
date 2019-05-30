#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
  #include <avr/power.h>
#endif

Adafruit_NeoPixel strip = Adafruit_NeoPixel (60, 6, NEO_GRB + NEO_KHZ800);

void setup () {
  strip.begin ();
  strip.setBrightness (10);
  strip.show ();
}

void loop () {
  for (int i = 0; i < strip.numPixels (); ++i) {
    strip.setPixelColor (i, strip.Color (random (255), random (255), random (255)));
    strip.show ();
  }
}

/*
Commands

  strip.setPixelColor (n, red, green, blue);
    - Sets a RGB color to the n LED
  
  strip.setPixelColor (n, color);
    - Alternative way to set a color to a LED
  
  strip.Color (red, green, blue);
    - Change RGB color
  
  strip.setBrightness (n);
    - Changes brightness (0-255)
  
  strip.getPixelColor (n);
    - Returns color of the n pixel as uint32_t

  strip.numPixels ();
    - Returns number of LEDS as uint16_t

  strip.show ();
    - Updates everything, including brightness



Variables

  To save colors: 
    uint32_t magenta = strip.Color (255, 0, 255);
      - Saves a pre-made color
    uint32_t color = strip.getPixelColor (0);
      - Saves color of first LED
      
  To save strip size: 
    uint16_t size = strip.numPixels ();
      - Use this function or 60
*/
