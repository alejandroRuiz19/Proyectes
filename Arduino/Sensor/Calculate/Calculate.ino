#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
  #include <avr/power.h>
#endif

#define sensor 3

Adafruit_NeoPixel strip = Adafruit_NeoPixel (30, 2, NEO_GRB + NEO_KHZ800);

bool lap_wait = true, first_lap = true, second_lap = false, color_wait = true;
unsigned long execution_time, lap_time, colors_time;

void setup () {
  strip.begin ();
  strip.show ();
  pinMode (sensor, INPUT);
  delay (10000);
}

void loop () {
  if (lap_wait) {
    if (first_lap && digitalRead (sensor)) {
      first_lap = false;
      second_lap = true;
      execution_time = millis ();
    }
    else if (second_lap && digitalRead (sensor)) {
      second_lap = false;
      lap_wait = false;
      lap_time = millis () - execution_time;
    }
  }
  else if (color_wait) {
    execution_time = millis ();
    for (byte led = 0; led < strip.numPixels (); ++led) {
      strip.setPixelColor (led, 16711680);
      strip.show ();
    }
    colors_time = millis () - execution_time;
    color_wait = false;
  }
}
