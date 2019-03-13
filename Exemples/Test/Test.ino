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
  color = strip.Color(random (0, 255), random (0, 255), random (0, 255)); // ESCOLLIR COLOR
  strip.setPixelColor(0, color);  // POSAR COLOR LED
  color = strip.Color(random (1, 255), random (0, 255), random (0, 255)); // ESCOLLIR COLOR
  strip.setPixelColor(1, color);  // POSAR COLOR LED
  strip.show(); // ACTUALITZAR
  delay(1000);
}
