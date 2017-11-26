/******************************************************************
 This is an example for the Adafruit RA8875 Driver board for TFT displays
 ---------------> http://www.adafruit.com/products/1590
 The RA8875 is a TFT driver for up to 800x480 dotclock'd displays
 It is tested to work with displays in the Adafruit shop. Other displays
 may need timing adjustments and are not guanteed to work.
 
 Adafruit invests time and resources providing this open
 source code, please support Adafruit and open-source hardware
 by purchasing products from Adafruit!
 
 Written by Limor Fried/Ladyada for Adafruit Industries.
 BSD license, check license.txt for more information.
 All text above must be included in any redistribution.
 ******************************************************************/

#include <SPI.h>
#include "Adafruit_GFX.h"
#include "Adafruit_RA8875.h"


// Library only supports hardware SPI at this time
// Connect SCLK to UNO Digital #13 (Hardware SPI clock)
// Connect MISO to UNO Digital #12 (Hardware SPI MISO)
// Connect MOSI to UNO Digital #11 (Hardware SPI MOSI)
#define RA8875_INT 3
#define RA8875_CS 10
#define RA8875_RESET 9

Adafruit_RA8875 tft = Adafruit_RA8875(RA8875_CS, RA8875_RESET);
uint16_t tx, ty;

// constants won't change. They're used here to set pin numbers:
const int buttonPin1 = 4;     // the number of the pushbutton pin
const int buttonPin2 = 5;
const int buttonPin3 = 6;
const int buttonPin4 = 7;

const int ledPin =  8;      // the number of the LED pin

// variables will change:
int buttonState1 = 0;         // variable for reading the pushbutton status
int buttonState2 = 0; 
int buttonState3 = 0; 
int buttonState4 = 0; 

void setup() 
{
  // initialize the LED pin as an output:
  pinMode(ledPin, OUTPUT);
  // initialize the pushbutton pin as an input:
  pinMode(buttonPin1, INPUT);
  pinMode(buttonPin2, INPUT);
  pinMode(buttonPin3, INPUT);
  pinMode(buttonPin4, INPUT);
  
  Serial.begin(9600);
  Serial.println("RA8875 start");

  /* Initialise the display using 'RA8875_480x272' or 'RA8875_800x480' */
  if (!tft.begin(RA8875_800x480)) {
    Serial.println("RA8875 Not Found!");
    while (1);
  }

  Serial.println("Found RA8875");

  tft.displayOn(true);
  tft.GPIOX(true);      // Enable TFT - display enable tied to GPIOX
  tft.PWM1config(true, RA8875_PWM_CLK_DIV1024); // PWM output for backlight
  tft.PWM1out(255);

  // With hardware accelleration this is instant
  tft.fillScreen(RA8875_WHITE);

  // Play with PWM
  for (uint8_t i=255; i!=0; i-=5 ) 
  {
    tft.PWM1out(i); 
    delay(10);
  }  
  for (uint8_t i=0; i!=255; i+=5 ) 
  {
    tft.PWM1out(i); 
    delay(10);
  }
  tft.PWM1out(255); 
  
  tft.fillScreen(RA8875_RED);
  delay(500);
  tft.fillScreen(RA8875_YELLOW);
  delay(500);
  tft.fillScreen(RA8875_GREEN);
  delay(500);
  tft.fillScreen(RA8875_CYAN);
  delay(500);
  tft.fillScreen(RA8875_MAGENTA);
  delay(500);
  tft.fillScreen(RA8875_BLACK);
  
  // Try some GFX acceleration!
  tft.drawCircle(100, 100, 50, RA8875_BLACK);
  tft.fillCircle(100, 100, 49, RA8875_GREEN);
  
  tft.fillRect(11, 11, 398, 198, RA8875_BLUE);
  tft.drawRect(10, 10, 400, 200, RA8875_GREEN);
  tft.fillRoundRect(200, 10, 200, 100, 10, RA8875_RED);
  tft.drawPixel(10,10,RA8875_BLACK);
  tft.drawPixel(11,11,RA8875_BLACK);
  tft.drawLine(10, 10, 200, 100, RA8875_RED);
  tft.drawTriangle(200, 15, 250, 100, 150, 125, RA8875_BLACK);
  tft.fillTriangle(200, 16, 249, 99, 151, 124, RA8875_YELLOW);
  tft.drawEllipse(300, 100, 100, 40, RA8875_BLACK);
  tft.fillEllipse(300, 100, 98, 38, RA8875_GREEN);
  // Argument 5 (curvePart) is a 2-bit value to control each corner (select 0, 1, 2, or 3)
  tft.drawCurve(50, 100, 80, 40, 2, RA8875_BLACK);  
  tft.fillCurve(50, 100, 78, 38, 2, RA8875_WHITE);
  
  pinMode(RA8875_INT, INPUT);
  digitalWrite(RA8875_INT, HIGH);
  
  tft.touchEnable(true);
    
  Serial.print("Status: "); Serial.println(tft.readStatus(), HEX);
  Serial.println("Waiting for touch events ...");
}

void loop() 
{
  // read the state of the pushbutton value:
  buttonState1 = digitalRead(buttonPin1);
  buttonState2 = digitalRead(buttonPin2);
  buttonState3 = digitalRead(buttonPin3);
  buttonState4 = digitalRead(buttonPin4);

  // check if the pushbutton is pressed. If it is, the buttonState is HIGH:
  if (buttonState1 == HIGH) {
    // turn LED on:
    digitalWrite(ledPin, HIGH);
  } else {
    // turn LED off:
    digitalWrite(ledPin, LOW);
  }

  if (buttonState2 == HIGH) {
    // turn LED on:
    digitalWrite(ledPin, HIGH);
  } else {
    // turn LED off:
    digitalWrite(ledPin, LOW);
  }

  if (buttonState3 == HIGH) {
    // turn LED on:
    digitalWrite(ledPin, HIGH);
  } else {
    // turn LED off:
    digitalWrite(ledPin, LOW);
  }

  if (buttonState4 == HIGH) {
    // turn LED on:
    digitalWrite(ledPin, HIGH);
  } else {
    // turn LED off:
    digitalWrite(ledPin, LOW);
  }
}
