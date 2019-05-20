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
  for (byte led = 0; led < strip.numPixels (); ++led) {
    strip.setPixelColor (led, strip.Color (0, 255, 0));
    strip.show ();
  }
}
