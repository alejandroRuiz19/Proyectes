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
  ScrollingRainbow (20,75,5);
}

void ScrollingRainbow (uint8_t wait, uint8_t whiteSpeed, uint8_t whiteLength) {
  if (whiteLength >= strip.numPixels ()) whiteLength = strip.numPixels () - 1;
  int head = whiteLength - 1, tail = 0, loops = 3, loopNum = 0;
  static unsigned long lastTime = 0;
  while (true) {
    for (int j = 0; j < 256; j++) {
      for (uint16_t i = 0; i < strip.numPixels (); i++) {
        if ((i >= tail && i <= head) || (tail > head && i >= tail) || (tail > head && i <= head)) strip.setPixelColor (i, strip.Color (0, 0, 0, 255));
        else strip.setPixelColor (i, Wheel (((i * 256 / strip.numPixels ()) + j) & 255));
      }
      if (millis () - lastTime > whiteSpeed) {
        head++;
        tail++;
        if (head == strip.numPixels ()) loopNum++;
        lastTime = millis ();
      }
      if (loopNum == loops) return;
      head %= strip.numPixels ();
      tail %= strip.numPixels ();
      strip.show ();
      delay (wait);
    }
  }
}

uint32_t Wheel (byte WheelPos) {
  WheelPos = 255 - WheelPos;
  if (WheelPos < 85) return strip.Color (255 - WheelPos * 3, 0, WheelPos * 3,0);
  if(WheelPos < 170) {
    WheelPos -= 85;
    return strip.Color (0, WheelPos * 3, 255 - WheelPos * 3,0);
  }
  WheelPos -= 170;
  return strip.Color (WheelPos * 3, 255 - WheelPos * 3, 0,0);
}
