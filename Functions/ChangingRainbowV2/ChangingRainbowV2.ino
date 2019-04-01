#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
  #include <avr/power.h>
#endif

Adafruit_NeoPixel strip = Adafruit_NeoPixel (60, 6, NEO_GRB + NEO_KHZ800);

uint32_t color = strip.Color (255, 0, 0);

void setup () {;
  strip.begin ();
  strip.setBrightness (10);
  strip.show ();
}

void loop () {
  rainbowCycle (5);
}

void rainbowCycle (uint8_t wait) {
  uint16_t i, j;
  for (j = 0; j < 256 * 5; j++) {
    for (i = 0; i < strip.numPixels (); i++) {
      strip.setPixelColor (i, Wheel (((i * 256 / strip.numPixels ()) + j) & 255));
    }
    strip.show ();
    delay (wait);
  }
}

uint32_t Wheel (byte WheelPos) {
  WheelPos = 255 - WheelPos;
  if (WheelPos < 85) return strip.Color (255 - WheelPos * 3, 0, WheelPos * 3,0);
  if (WheelPos < 170) {
    WheelPos -= 85;
    return strip.Color (0, WheelPos * 3, 255 - WheelPos * 3,0);
  }
  WheelPos -= 170;
  return strip.Color (WheelPos * 3, 255 - WheelPos * 3, 0,0);
}
