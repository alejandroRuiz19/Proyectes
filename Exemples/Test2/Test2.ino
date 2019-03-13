#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
  #include <avr/power.h>
#endif

#define PIN 6

uint32_t color;

Adafruit_NeoPixel strip = Adafruit_NeoPixel(60, PIN, NEO_GRB + NEO_KHZ800);

void setup () {
  strip.begin();
  strip.setBrightness(50);
  strip.show();
}

void loop () {
  delay (1000);
  for (int i = 0, j = 1; i <= 59; i += 2, j += 2) {
    color = strip.Color(255, 0, 0);
    strip.setPixelColor(i, color);
    color = strip.Color(0, 0, 0);
    strip.setPixelColor(j, color);
    strip.show();
  }
  delay (1000);
  for (int i = 0, j = 1; j <= 59; i += 2, j += 2) {
    color = strip.Color(0, 0, 0);
    strip.setPixelColor(i, color);
    color = strip.Color(0, 0, 255);
    strip.setPixelColor(j, color);
    strip.show();
  }
}
