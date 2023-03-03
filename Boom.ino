#include <LiquidCrystal_I2C.h>
#include <IRremote.h>
#define IR_RECEIVE_PIN 2
#define IR_BUTTON_1 12
#define IR_BUTTON_2 24
#define IR_BUTTON_3 94
#define IR_BUTTON_4 8
#define IR_BUTTON_5 28
#define IR_BUTTON_6 90
#define IR_BUTTON_7 66
#define IR_BUTTON_8 82
#define IR_BUTTON_9 74
#define IR_BUTTON_0 22
#define IR_BUTTON_s 25
#define IR_BUTTON_u 13
LiquidCrystal_I2C lcd(0x27, 20, 4);
int val = 7;
int ledPin = 13;
int state = 0;
int time = 10;
int buttonpin = 3;
void setup() {
  lcd.init();
  lcd.backlight();
  lcd.print("Detonation in:");
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, LOW);
  Serial.begin(9600);
  IrReceiver.begin(IR_RECEIVE_PIN);
  pinMode (buttonpin, INPUT) ;
  pinMode(val, OUTPUT); 
}
void loop() {
  val = digitalRead (buttonpin) ;
  Serial.println(val);
  IrReceiver.decode();
  IrReceiver.resume();
  int command = IrReceiver.decodedIRData.command;
  if (command != 0) {
     switch (command) {
      case IR_BUTTON_1:{
          time = 60;
          lcd.setCursor(0, 1);
          lcd.print(time - millis() / 1000);
          time = time - millis() / 1000;
          lcd.print(" Segundos");
          if (time == 0) {
            digitalWrite(ledPin, HIGH);
            delay(100);
            digitalWrite(ledPin, LOW);
          }
          break;
        }
        case IR_BUTTON_2:{
          time = 120;
          lcd.setCursor(0, 1);
          lcd.print(time - millis() / 1000);
          time = time - millis() / 1000;
          lcd.print(" Segundos");
          if (time == 0) {
            digitalWrite(ledPin, HIGH);
            delay(100);
            digitalWrite(ledPin, LOW);
          }
          break;
        }
        case IR_BUTTON_3:{
          time = 180;
          lcd.setCursor(0, 1);
          lcd.print(time - millis() / 1000);
          time = time - millis() / 1000;
          lcd.print(" Segundos");
          if (time == 0) {
            digitalWrite(ledPin, HIGH);
            delay(100);
            digitalWrite(ledPin, LOW);
          }
          break;
        }
        case IR_BUTTON_4:{
          time = 240;
          lcd.setCursor(0, 1);
          lcd.print(time - millis() / 1000);
          time = time - millis() / 1000;
          lcd.print(" Segundos");
          if (time == 0) {
            digitalWrite(ledPin, HIGH);
            delay(100);
            digitalWrite(ledPin, LOW);
          }
          break;
        }
        case IR_BUTTON_5:{
          time = 300;
          lcd.setCursor(0, 1);
          lcd.print(time - millis() / 1000);
          time = time - millis() / 1000;
          lcd.print(" Segundos");
          if (time == 0) {
            digitalWrite(ledPin, HIGH);
            delay(100);
            digitalWrite(ledPin, LOW);
          }
          break;
        }
        case IR_BUTTON_6:{
          time = 360;
          lcd.setCursor(0, 1);
          lcd.print(time - millis() / 1000);
          time = time - millis() / 1000;
          lcd.print(" Segundos");
          if (time == 0) {
            digitalWrite(ledPin, HIGH);
            delay(100);
            digitalWrite(ledPin, LOW);
          }
          break;
        }
        case IR_BUTTON_7:{
          time = 420;
          lcd.setCursor(0, 1);
          lcd.print(time - millis() / 1000);
          time = time - millis() / 1000;
          lcd.print(" Segundos");
          if (time == 0) {
            digitalWrite(ledPin, HIGH);
            delay(100);
            digitalWrite(ledPin, LOW);
          }
          break;
        }
        case IR_BUTTON_8:{
          time = 480;
          lcd.setCursor(0, 1);
          lcd.print(time - millis() / 1000);
          time = time - millis() / 1000;
          lcd.print(" Segundos");
          if (time == 0) {
            digitalWrite(ledPin, HIGH);
            delay(100);
            digitalWrite(ledPin, LOW);
          }
          break;
        }
        case IR_BUTTON_9:{
          time = 1140;
          lcd.setCursor(0, 1);
          lcd.print(time - millis() / 1000);
          time = time - millis() / 1000;
          lcd.print(" Segundos");
          if (time == 0) {
            digitalWrite(ledPin, HIGH);
            delay(100);
            digitalWrite(ledPin, LOW);
          }
          break;
        }
        case IR_BUTTON_0:{
          time = 10;
          lcd.setCursor(0, 1);
          lcd.print(time - millis() / 1000);
          time = time - millis() / 1000;
          lcd.print(" Segundos");
          if (time == 0) {
            digitalWrite(ledPin, HIGH);
            delay(100);
            digitalWrite(ledPin, LOW);
          }
          break;
        }
        case IR_BUTTON_s:{
          time = 15;
          lcd.setCursor(0, 1);
          lcd.print(time - millis() / 1000);
          time = time - millis() / 1000;
          lcd.print(" Segundos");
          if (time == 0) {
            digitalWrite(ledPin, HIGH);
            delay(100);
            digitalWrite(ledPin, LOW);
          }
          break;
        }
        case IR_BUTTON_u:{
          time = 30;
          lcd.setCursor(0, 1);
          lcd.print(time - millis() / 1000);
          time = time - millis() / 1000;
          lcd.print(" Segundos");
          if (time == 0) {
            digitalWrite(ledPin, HIGH);
            delay(100);
            digitalWrite(ledPin, LOW);
          }
          break;
        }
      default:
        {
          digitalWrite(ledPin, HIGH);
          lcd.setCursor(0, 1);
          lcd.print("Boom!");
        }
    }
  } else if (Serial.available() > 0) {
    state = Serial.read();
  }
  if (state == '0') {
    digitalWrite(ledPin, LOW);
    Serial.println("LED: off");
    lcd.setCursor(0, 1);
    lcd.print("I'll be back!   ");
  } else if (state == '1' || val == HIGH) {
    lcd.setCursor(0, 1);
    lcd.print("Hastalavistababy");
    digitalWrite(ledPin, HIGH);
  }
  if (val == LOW) {
    digitalWrite (ledPin, LOW);
  }
}