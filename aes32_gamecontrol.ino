#include <BleKeyboard.h>

const int buttonPinI = 19;      
const int buttonPinJ = 22;      
const int buttonPinK = 23;
const int buttonPinL = 21; 

const int joystickPinX =35; 
const int joystickPinY = 34; 

BleKeyboard bleKeyboard;
void setup() {
  bleKeyboard.begin();
  Serial.begin(115200);
  pinMode(buttonPinI, INPUT_PULLUP);
  pinMode(buttonPinJ, INPUT_PULLUP);
  pinMode(buttonPinK, INPUT_PULLUP);
  pinMode(buttonPinL, INPUT_PULLUP);

}

void loop() {
  
  // if (analogRead(joystickPinX) < 400) {
  //   if (analogRead(joystickPinY) < 400) {
  //     // Diagonal: Up-Left
  //     bleKeyboard.write(119); // "w"
  //     bleKeyboard.write(97);  // "a"
  //   } else if (analogRead(joystickPinY) > 600) {
  //     // Diagonal: Down-Left
  //     bleKeyboard.write(115); // "s"
  //     bleKeyboard.write(97);  // "a"
  //   } else {
  //     // Left
  //     bleKeyboard.write(97);  // "a"
  //     bleKeyboard.release(119);
  //     bleKeyboard.release(97);
  //   }
  // } else if (xValue > 600) {
  //   if (yValue < 400) {
  //     // Diagonal: Up-Right
  //     bleKeyboard.write(119); // "w"
  //     bleKeyboard.write(100); // "d"
  //   } else if (yValue > 600) {
  //     // Diagonal: Down-Right
  //     bleKeyboard.write(115); // "s"
  //     bleKeyboard.write(100); // "d"
  //   } else {
  //     // Right
  //     bleKeyboard.write(100); // "d"
  //     bleKeyboard.release(119);
  //     bleKeyboard.release(115);
  //   }
  // } else {
  //   if (yValue < 400) {
  //     // Up
  //     bleKeyboard.write(119); // "w"
  //     bleKeyboard.release(97);
  //     bleKeyboard.release(100);
  //   } else if (yValue > 600) {
  //     // Down
  //     bleKeyboard.write(115); // "s"
  //     bleKeyboard.release(97);
  //     bleKeyboard.release(100);
  //   } else {
  //     // Default position, no movement
  //     bleKeyboard.releaseAll();
  //   }
  // }


  while(analogRead(joystickPinX) > 3000 && (analogRead(joystickPinY) > 900 || analogRead(joystickPinY) < 2500)){
    bleKeyboard.press(100); // "d"
  }
  bleKeyboard.releaseAll();
  while(analogRead(joystickPinX) < 300 && (analogRead(joystickPinY) > 900 || analogRead(joystickPinY) < 2500)){
    bleKeyboard.press(97);  // "a"
  }
  bleKeyboard.releaseAll();
  while(analogRead(joystickPinY) > 3000 && (analogRead(joystickPinX) > 900 || analogRead(joystickPinX) < 2500)){
    bleKeyboard.press(119); // "w"
  }
  bleKeyboard.releaseAll();
  while(analogRead(joystickPinY) < 300 && (analogRead(joystickPinX) > 900 || analogRead(joystickPinX) < 2500)){
    bleKeyboard.press(115); // "s"
  }
  bleKeyboard.releaseAll();
  while(analogRead(joystickPinX)>3000 && analogRead(joystickPinY)>3000){
    // bleKeyboard.press(119); //w
    // bleKeyboard.press(100); // "d"
    bleKeyboard.print("WA");
  }bleKeyboard.releaseAll();
  while(analogRead(joystickPinX)<300 && analogRead(joystickPinY)>300){
    bleKeyboard.press(115); // "s"
    bleKeyboard.press(97);  // "a"
  }bleKeyboard.releaseAll();
  while(analogRead(joystickPinX)>3000 && analogRead(joystickPinY)<300){
     bleKeyboard.press(115); // "s"
    bleKeyboard.press(100); // "d"
  }bleKeyboard.releaseAll();
  while(analogRead(joystickPinX)<300 && analogRead(joystickPinY)>3000){
    bleKeyboard.press(119); //w
    bleKeyboard.press(97);  // "a"
  }bleKeyboard.releaseAll();


  
  if (digitalRead(buttonPinI) != 1   ) {
    Serial.println("Button I pressed");
    bleKeyboard.write(105);
  }
  if (digitalRead(buttonPinJ) !=1) {
    Serial.println("Button J pressed");
    bleKeyboard.write(106);

  }
  if (digitalRead(buttonPinK) !=1) {
    Serial.println("Button K pressed");
    bleKeyboard.write(107);

  }
  if (digitalRead(buttonPinL) !=1) {
    Serial.println("Button L pressed");
    bleKeyboard.write(108);

  }
  delay(75);
}
