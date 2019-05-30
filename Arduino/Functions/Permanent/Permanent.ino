#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
  #include <avr/power.h>
#endif

Adafruit_NeoPixel strip = Adafruit_NeoPixel (30, 2, NEO_GRB + NEO_KHZ800);

void setup () {
  strip.begin ();
  for (int i = 0; i < strip.numPixels (); i++) {
    strip.setPixelColor (i, strip.Color (255, 255, 255));
  }
  strip.show ();
}

void loop () {
}
