#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
  #include <avr/power.h>
#endif

void setup () {
  strip.begin ();
  strip.setBrightness (10);
  strip.show ();
}

void loop () {
  for (byte led = 0; led < strip.numPixels (); ++led) {
    strip.setPixelColor (led, strip.Color (0, 255, 0));
    strip.show ();
    delay (5000);
  }
}
