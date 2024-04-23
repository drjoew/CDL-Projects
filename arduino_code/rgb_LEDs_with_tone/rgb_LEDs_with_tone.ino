#include <Adafruit_NeoPixel.h>

const int numPixels = 12;
const int pixelPin = 2;
int sensorPin = A0;   // select the input pin for the potentiometer
int sensorValue = 0;  // variable to store the value coming from the sensor

Adafruit_NeoPixel ring = Adafruit_NeoPixel(numPixels, pixelPin);
uint32_t foreground = ring.Color(0x00, 0x00, 0x33); // r, g, b - blue
uint32_t background = ring.Color(0x00, 0x33, 0x00); // 
uint32_t tail1 = ring.Color(0x33, 0x00, 0x00); // 
uint32_t tail2 = ring.Color(0x16, 0x16, 0x00); // 

void setup() {
  ring.begin(); // start the NeoPixel display
  //Serial.begin(9600); // open the serial port at 9600 bps:
}

void loop() {
  //set background color to start
  for (int i = 0; i < numPixels; i++) {ring.setPixelColor(i, background);}
    
  //now set up rotating colors
  
  for (int i = 0; i < numPixels; i++) {
    // read the value from the sensor:
    sensorValue = analogRead(sensorPin);
    if(sensorValue<12)sensorValue=12;
    if (i>2){
    ring.setPixelColor(i, foreground); // set pixel i to foreground
    ring.setPixelColor(i-1, tail1);
    ring.setPixelColor(i-2, tail2);
    ring.setPixelColor(i-3, background);
    
    }
    if (i==0){
      ring.setPixelColor(i, foreground);
      ring.setPixelColor(numPixels-1,   tail1);
      ring.setPixelColor(numPixels-2, tail2);
      ring.setPixelColor(numPixels-3, background);
      ring.setPixelColor(numPixels-4, background);
    }
    if (i==1){
      ring.setPixelColor(i, foreground);
      ring.setPixelColor(i-1,   tail1);
      ring.setPixelColor(numPixels-1,   tail2);
      ring.setPixelColor(numPixels-2, background);
      ring.setPixelColor(numPixels-3, background);
    }
    if (i==2){
      ring.setPixelColor(i, foreground);
      ring.setPixelColor(i-1,   tail1);
      ring.setPixelColor(i-2,   tail2);
      ring.setPixelColor(numPixels-1, background);
      ring.setPixelColor(numPixels-2, background);
    }
    ring.show();                       // actually display it
    tone(A5, sensorValue*4, sensorValue);
    delay(sensorValue);                         // milliseconds 
    //Serial.print(sensorValue);
    //Serial.print("\n");
    ring.setPixelColor(i, background); // set pixel to background before moving on
    
    ring.show(); 
  }
}
