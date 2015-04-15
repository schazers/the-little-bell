#include <Adafruit_NeoPixel.h>
#include <avr/power.h>

// Which pin on the Arduino is connected to the NeoPixels?
// On a Trinket or Gemma we suggest changing this to 1
#define PIN            6

// NUM LED STRANDS
#define NUMSTRANDS    6
#define NUMPIXELS      (60 * NUMSTRANDS)

// Note that for older NeoPixel strips we might need to change the third parameter--see the strandtest
// example for more information on possible values.
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

// delay in milliseconds
int delayval = 5; 

void setup() {
  pixels.begin(); // init NeoPixel lib
}

void loop() {

  // how many lights to skip between lit-up ones on the strand
  int gapSize = 2;
  
  // the max brightness per r, g, or b. we do this to 
  // limit the overall amount of current to the strand
  int maxBrightness = (150 / NUMSTRANDS) * gapSize;
  
  for(int i = 0; i < NUMPIXELS; ++i) {
    
    if (i % 2 == 0) {
      pixels.setPixelColor(i, pixels.Color(rand() % maxBrightness, rand() % maxBrightness, rand() % maxBrightness));
    } else {
      pixels.setPixelColor(i, pixels.Color(0, 0, 0));
    }

    pixels.show();

    delay(delayval);
  }
}
