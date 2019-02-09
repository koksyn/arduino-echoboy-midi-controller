
#include "Button.h"

  Button btn;

void setup() {
  //start serial connection
  Serial.begin(9600);

  btn.turnOn();
}

void loop() {
  
  Serial.println(btn.isDown());

  delay(500);
}
