#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
  #include <avr/power.h>
#endif

Adafruit_NeoPixel strip = Adafruit_NeoPixel (60, 6, NEO_GRB + NEO_KHZ800);

void setup () {;
  strip.begin ();
  strip.setBrightness (10);
  strip.show ();
}

void loop() {
  colorWipe (strip.Color (255, 0, 0), 50);
}

void colorWipe (uint32_t c, uint8_t wait) {
  for (int i = 0; i < strip.numPixels (); i++) {
    strip.setPixelColor (i, c);
    strip.show ();
    delay (wait);
  }
}
