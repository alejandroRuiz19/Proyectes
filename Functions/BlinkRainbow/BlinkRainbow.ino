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

void loop () {
  BlinkRainbow (25);
}

void BlinkRainbow (uint8_t wait) {
  for (int j = 0; j < 256; j++) {
    for (int q = 0; q < 3; q++) {
      for (uint16_t i = 0; i < strip.numPixels (); i += 3) {
        strip.setPixelColor (i + q, Wheel ((i + j) % 255));
      }
      strip.show ();
      delay (wait);
      for (uint16_t i = 0; i < strip.numPixels (); i += 3) {
        strip.setPixelColor (i + q, 0);
      }
    }
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
