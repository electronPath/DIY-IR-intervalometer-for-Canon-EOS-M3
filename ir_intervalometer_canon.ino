#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels

// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

//
const int buttonDown = 4;      //the the number of the pushbutton pin for Down
const int buttonSelect = 5;     // the number of the pushbutton pin for Select
const int ledPin =  7;      // the number of the LED pin

// variables will change:
int menu;

//
void setup() {
  Serial.begin(115200);
  
  // initialize the pushbutton pin as an input:
  pinMode(buttonDown, INPUT);
  pinMode(buttonSelect, INPUT);
   // initialize the LED pin as an output:
  pinMode(ledPin, OUTPUT);
  
  
  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { // Address 0x3C for 128x64
    Serial.println(F("SSD1306 allocation failed"));
    for(;;);
  }
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE);
  updateMenu();  
}

void loop() {
  
  if (digitalRead(buttonDown)){
    menu++;
    updateMenu();
    delay(150);
    while (digitalRead(buttonDown));
  }

   if (digitalRead(buttonSelect)){
    executeAction();
    updateMenu();
    delay(150);
    while (digitalRead(buttonSelect));
  }
  
}


void updateMenu(){
    switch(menu){
      case 0:
        menu = 1;
        display.display();
      case 1:
        display.clearDisplay();
        display.setCursor(15, 0);
        display.println(F("IR remote (Canon)"));
        display.drawFastHLine(0, 11, 128, WHITE);
        display.setCursor(2, 17);
        display.println(F("> trigger now       <"));
        display.setCursor(2, 26);
        display.println(F("  trigger in 5s."));
        display.setCursor(2, 35);
        display.println(F("  every 5s."));
        display.setCursor(2, 44);
        display.println(F("  every 10s."));
        display.setCursor(2, 53);
        display.println(F("  every 15s."));
        display.display(); 
        break;
     case 2:
        display.clearDisplay();
        display.setCursor(15, 0);
        display.println(F("IR remote (Canon)"));
        display.drawFastHLine(0, 11, 128, WHITE);
        display.setCursor(2, 17);
        display.println(F("  trigger now"));
        display.setCursor(2, 26);
        display.println(F("> trigger in 5s.    <"));
        display.setCursor(2, 35);
        display.println(F("  every 5s."));
        display.setCursor(2, 44);
        display.println(F("  every 10s."));
        display.setCursor(2, 53);
        display.println(F("  every 15s."));
        display.display(); 
        break; 
     case 3:
        display.clearDisplay();
        display.setCursor(15, 0);
        display.println(F("IR INTERVALOMETER"));
        display.drawFastHLine(0, 11, 128, WHITE);
        display.setCursor(2, 17);
        display.println(F("  trigger now"));
        display.setCursor(2, 26);
        display.println(F("  trigger in 5s."));
        display.setCursor(2, 35);
        display.println(F("> every 5s.         <"));
        display.setCursor(2, 44);
        display.println(F("  every 10s."));
        display.setCursor(2, 53);
        display.println(F("  every 15s."));
        display.display(); 
        break; 
     case 4:
        display.clearDisplay();
        display.setCursor(15, 0);
        display.println(F("IR INTERVALOMETER"));
        display.drawFastHLine(0, 11, 128, WHITE);
        display.setCursor(2, 17);
        display.println(F("  trigger now"));
        display.setCursor(2, 26);
        display.println(F("  trigger in 5s."));
        display.setCursor(2, 35);
        display.println(F("  every 5s."));
        display.setCursor(2, 44);
        display.println(F("> every 10s.        <"));
        display.setCursor(2, 53);
        display.println(F("  every 15s."));
        display.display(); 
        break;     
     case 5:
        display.clearDisplay();
        display.setCursor(15, 0);
        display.println(F("IR INTERVALOMETER"));
        display.drawFastHLine(0, 11, 128, WHITE);
        display.setCursor(2, 17);
        display.println(F("  trigger now"));
        display.setCursor(2, 26);
        display.println(F("  trigger in 5s."));
        display.setCursor(2, 35);
        display.println(F("  every 5s."));
        display.setCursor(2, 44);
        display.println(F("  every 10s."));
        display.setCursor(2, 53);
        display.println(F("> every 15s.        <"));
        display.display(); 
        break; 
     case 6:
        display.clearDisplay();
        display.setCursor(15, 0);
        display.println(F("IR INTERVALOMETER"));
        display.drawFastHLine(0, 11, 128, WHITE);
        display.setCursor(2, 17);
        display.println(F("> every 20s.        <"));
        display.setCursor(2, 26);
        display.println(F("  every 30s."));
        display.setCursor(2, 35);
        display.println(F("  every 45s."));
        display.setCursor(2, 44);
        display.println(F("  every 1 min."));
        display.setCursor(2, 53);
        display.println(F("  every 2 min."));
        display.display();
        break; 
     case 7:
        display.clearDisplay();
        display.setCursor(15, 0);
        display.println(F("IR INTERVALOMETER"));
        display.drawFastHLine(0, 11, 128, WHITE);
        display.setCursor(2, 17);
        display.println(F("  every 20s."));
        display.setCursor(2, 26);
        display.println(F("> every 30s.        <"));
        display.setCursor(2, 35);
        display.println(F("  every 45s."));
        display.setCursor(2, 44);
        display.println(F("  every 1 min."));
        display.setCursor(2, 53);
        display.println(F("  every 2 min."));
        display.display();
        break;    
     case 8:
        display.clearDisplay();
        display.setCursor(15, 0);
        display.println(F("IR INTERVALOMETER"));
        display.drawFastHLine(0, 11, 128, WHITE);
        display.setCursor(2, 17);
        display.println(F("  every 20s."));
        display.setCursor(2, 26);
        display.println(F("  every 30s."));
        display.setCursor(2, 35);
        display.println(F("> every 45s.        <"));
        display.setCursor(2, 44);
        display.println(F("  every 1 min."));
        display.setCursor(2, 53);
        display.println(F("  every 2 min."));
        display.display();
        break;  
     case 9:
        display.clearDisplay();
        display.setCursor(15, 0);
        display.println(F("IR INTERVALOMETER"));
        display.drawFastHLine(0, 11, 128, WHITE);
        display.setCursor(2, 17);
        display.println(F("  every 20s."));
        display.setCursor(2, 26);
        display.println(F("  every 30s."));
        display.setCursor(2, 35);
        display.println(F("  every 45s."));
        display.setCursor(2, 44);
        display.println(F("> every 1 min.      <"));
        display.setCursor(2, 53);
        display.println(F("  every 2 min."));
        display.display();
        break;  
     case 10:
        display.clearDisplay();
        display.setCursor(15, 0);
        display.println(F("IR INTERVALOMETER"));
        display.drawFastHLine(0, 11, 128, WHITE);
        display.setCursor(2, 17);
        display.println(F("  every 20s."));
        display.setCursor(2, 26);
        display.println(F("  every 30s."));
        display.setCursor(2, 35);
        display.println(F("  every 45s."));
        display.setCursor(2, 44);
        display.println(F("  every 1 min."));
        display.setCursor(2, 53);
        display.println(F("> every 2 min.      <"));
        display.display();
        break;     
    default:
       menu = 0;
       break;
       
   }
}


void executeAction() {
  switch (menu) {
    case 1:
      action1();
      break;
    case 2:
      action2();
      break;
    case 3:
      action3();
      break;
    case 4:
      action4();
      break;
    case 5:
      action5();
      break;
    case 6:
      action6();
      break; 
    case 7:
      action7();
      break;
    case 8:
      action8();
      break;
    case 9:
      action9();
      break;
    case 10:
      action10();
      break;
  }
}

//Canon infrared LED signal
void lightLED() {
   for(int i=0; i<16; i++) { 
    digitalWrite(ledPin, HIGH);
    delayMicroseconds(11);
    digitalWrite(ledPin, LOW);
    delayMicroseconds(11);
  } 
  delayMicroseconds(7330); 

  for(int i=0; i<16; i++) { 
  digitalWrite(ledPin, HIGH);
  delayMicroseconds(11);
  digitalWrite(ledPin, LOW);
  delayMicroseconds(11);
  }
}

//trigger now action
void action1() {
  display.clearDisplay();
  display.setCursor(15, 35);
  display.println(F("> triggering now"));
  lightLED();  
  display.display();
  delay(500);
}

//trigger in 5 seconds
void action2() {
  display.clearDisplay();
  display.setCursor(15, 35);
  display.println(F("> trigger in 5s."));
  display.display();
  delay(5000);
  lightLED();
  delay(500);
}

//trigger every 5 seconds
void action3() {
  display.clearDisplay();
  display.setCursor(25, 35);
  display.println(F("> every 5s."));
  display.display();
  while (true){
    delay(5000);
    lightLED();
  }
}
//trigger every 10 seconds
void action4() {
  display.clearDisplay();
  display.setCursor(25, 35);
  display.println(F("> every 10s."));
  display.display();
  while (true){
    delay(10000);
    lightLED();
  }
}
//trigger every 15 seconds
void action5() {
  display.clearDisplay();
  display.setCursor(25, 35);
  display.println(F("> every 15s."));
  display.display();
  while (true){
    delay(15000);
    lightLED();
  }
}
//trigger every 20 seconds
void action6() {
  display.clearDisplay();
  display.setCursor(25, 35);
  display.println(F("> every 20s."));
  display.display();
  while (true){
    delay(20000);
    lightLED();
  }
}
//trigger every 30 seconds
void action7() {
  display.clearDisplay();
  display.setCursor(25, 35);
  display.println(F("> every 30s."));
  display.display();
  while (true){
    delay(30000);
    lightLED();
  }
}
//trigger every 45 seconds
void action8() {
  display.clearDisplay();
  display.setCursor(25, 35);
  display.println(F("> every 45s."));
  display.display();
  while (true){
    delay(45000);
    lightLED();
  }
}
//trigger every 1min.
void action9() {
  display.clearDisplay();
  display.setCursor(20, 35);
  display.println(F("> every 1 min."));
  display.display();
  while (true){
    delay(60000);
    lightLED();
  }
}
//trigger every 2min.
void action10() {
  display.clearDisplay();
  display.setCursor(20, 35);
  display.println(F("> every 2 min."));
  display.display();
  while (true){
    delay(120000);
    lightLED();
  }
}
