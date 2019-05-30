#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
  #include <avr/power.h>
#endif

#define sensor 3

Adafruit_NeoPixel strip = Adafruit_NeoPixel (30, 2, NEO_GRB + NEO_KHZ800);

void setup () {
  strip.begin ();
  strip.show ();
  pinMode (sensor, INPUT);
  digitalWrite (INPUT_PULLUP, HIGH);
  Serial.begin (9600);
}

void loop () {
  if (digitalRead (sensor) == LOW) Serial.println ("IMAN");
  if (digitalRead (sensor) == HIGH) Serial.println ("NO IMAN");
}
