#include <Adafruit_NeoPixel.h>
/* 
 * Quite simple: uses a 8 pixel long WS2812 strip mounted inside the chassis to a Digispark on an internal USB (header) port.
 * It normally fades blue in and out along the length of the strip.
 * When the +5V rail goes below ~3V or so, the if case switches to the "else" case and blinks white slowly. This is normally
 * while the computer is in standby mode.
 */
 
/* WS2812 data pin */
#define PIN            0
#define NUMPIXELS      8
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_RGB + NEO_KHZ800);

int atxVoltage = 0;

void setup() {
  pixels.begin();
  pinMode(2,INPUT);
}

void loop() {
  atxVoltage = analogRead(1);
  if (atxVoltage > 600) {
    for(int i=0;i<NUMPIXELS;i++){
      pixels.setPixelColor(i, pixels.Color(0,0,0));
      pixels.show();
      delay(50);
    }
    for(int i=NUMPIXELS-1;i>0;i--){
      pixels.setPixelColor(i, pixels.Color(0,0,150));
      pixels.show();
      delay(50);
    }
  } else {
    for(int i=0;i<NUMPIXELS;i++){
      pixels.setPixelColor(i, pixels.Color(0,0,0));
      pixels.show();
      delay(200);
    }
    for(int i=NUMPIXELS-1;i>0;i--){
      pixels.setPixelColor(i, pixels.Color(10,10,10));
      pixels.show();
      delay(100);
    }
  }
}
