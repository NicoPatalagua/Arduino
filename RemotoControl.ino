#include <IRremote.h>
#define IR_RECEIVE_PIN 2
#define IR_BUTTON_1 12
#define IR_BUTTON_2 24
#define IR_BUTTON_3 94
#define IR_BUTTON_PLAY_PAUSE 64
#define IR_BUTTON_4 8
void setup() {
  Serial.begin(9600);
  IrReceiver.begin(IR_RECEIVE_PIN);
}
void loop() {
  if (IrReceiver.decode()) {
    IrReceiver.resume();
    int command = IrReceiver.decodedIRData.command;
    switch (command) {
      case IR_BUTTON_1: {
        Serial.println("Pressed on button 1");
        break;
      }
      case IR_BUTTON_2: {
        Serial.println("Pressed on button 2");
        break;
      }
      case IR_BUTTON_3: {
        Serial.println("Pressed on button 3");
        break;
      }
      case IR_BUTTON_4: {
        Serial.println("Pressed on button 4");
        break;
      }
      case IR_BUTTON_PLAY_PAUSE: {
        Serial.println("Pressed on button play/pause");
        break;
      }
      default: {
        Serial.println("Button not recognized");
        Serial.println(command);

      }
    }
  }
}