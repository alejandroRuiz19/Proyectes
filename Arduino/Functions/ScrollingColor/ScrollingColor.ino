#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
  #include <avr/power.h>
#endif

Adafruit_NeoPixel strip = Adafruit_NeoPixel (30, 2, NEO_GRB + NEO_KHZ800);

void setup () {;
  strip.begin ();
  strip.show ();
}

void loop() {
  ScrollingColor (strip.Color (255, 0, 0), 50);
}

void ScrollingColor (uint32_t c, uint8_t wait) {
  for (int i = 0; i < strip.numPixels (); i++) {
    strip.setPixelColor (i, c);
    strip.show ();
    delay (wait);
  }
}
