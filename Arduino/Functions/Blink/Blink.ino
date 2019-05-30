#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
  #include <avr/power.h>
#endif

Adafruit_NeoPixel strip = Adafruit_NeoPixel (30, 2, NEO_GRB + NEO_KHZ800);

uint32_t color = strip.Color (255, 0, 0);

void setup () {;
  strip.begin ();
  strip.show ();
}

void loop () {
  Blink (strip.Color (255, 255, 255), 50);
}

void Blink (uint32_t c, uint8_t wait) {
  for (int j = 0; j < 10; j++) {
    for (int q = 0; q < 3; q++) {
      for (uint16_t i = 0; i < strip.numPixels (); i += 3) {
        strip.setPixelColor (i + q, c);
      }
      strip.show ();
      delay (wait);
      for (uint16_t i = 0; i < strip.numPixels (); i += 3) {
        strip.setPixelColor (i + q, 0);
      }
    }
  }
}
