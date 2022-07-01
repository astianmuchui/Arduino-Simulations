
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels

// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
#define OLED_RESET     4 // Reset pin # (or -1 if sharing Arduino reset pin)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);
int bluePin = 3;
int greenPin = 5;
int redPin = 6;
int buzzer = 12;
int pushbutton = 7;

void setup() {

  pinMode(bluePin, OUTPUT);
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(buzzer, OUTPUT);

  pinMode(pushbutton, INPUT_PULLUP);

  // Pull up the button
  Serial.begin(9600);

  // SSD1306_SWITCHCAPVCC = generate display voltage from 3.3V internally
  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3D)) { // Address 0x3D for 128x64
    Serial.println(F("SSD1306 allocation failed"));
    for(;;); // Don't proceed, loop forever
  }

  // Show initial display buffer contents on the screen --
  // the library initializes this with an Adafruit splash screen.
  display.display();

    display.clearDisplay();

  display.setTextSize(1); // Draw 2X-scale text
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(10, 2);
  display.println(F("Seb"));
  display.display();      // Show initial text
  delay(100);

  delay(2000); // Pause for 2 seconds

   

  // Invert and restore display, pausing in-between
//  display.invertDisplay(true);
//   delay(1000);
//  display.invertDisplay(false);
//  delay(1000);


 
}

void loop() {

  
    display.clearDisplay();

    int val = analogRead(A0);

    display.setTextSize(0.5); // Draw 2X-scale text
    display.setTextColor(SSD1306_WHITE);
    display.setCursor(8,5);
    display.println("Potentiometer val:");

    display.setTextSize(3); // Draw 2X-scale text
    display.setCursor(20, 20);
    display.println(val);
    display.display();      // Show initial text
    delay(100);
    if(val==0){
      digitalWrite(redPin,LOW);
    }
    if(val>0 && val<300){
      digitalWrite(redPin, HIGH);
      digitalWrite(greenPin, LOW);
      digitalWrite(bluePin, LOW);

    }
    if(val>300 && val<700){
      digitalWrite(greenPin, HIGH);
    }
    if(val>700 && val<1000){
      digitalWrite(bluePin, HIGH);
    }
    if(digitalRead(pushbutton) == 0){
      digitalWrite(buzzer,HIGH);
      delay(1000);
      digitalWrite(buzzer,LOW);
    }else{
      digitalWrite(buzzer,LOW);
    }
    if(val>1000){
      digitalWrite(buzzer,HIGH);
      delay(1000);
      digitalWrite(buzzer,LOW);
      digitalWrite(redPin, HIGH);
      digitalWrite(greenPin, HIGH);
      digitalWrite(bluePin, HIGH);

    }

}
 
