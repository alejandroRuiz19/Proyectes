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
  ChangingRainbow (25);
}

void ChangingRainbow (uint8_t wait) {
  for (int j = 0; j < 256; j++) {
    for (int i = 0; i < strip.numPixels (); i++) {
      strip.setPixelColor (i, Wheel ((i+j) & 255));
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
