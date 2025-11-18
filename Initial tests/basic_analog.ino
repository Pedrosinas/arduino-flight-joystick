#include <Joystick.h>

Joystick_ Joystick(JOYSTICK_DEFAULT_REPORT_ID,
JOYSTICK_TYPE_JOYSTICK,
0,
0,
true,
true,
false,
false, false, false, false, false, false);

int pitchPin = A1;
int rollPin = A0;

void setup() {
  Joystick.begin();
  pinMode(pitchPin, INPUT);
  pinMode(rollPin, INPUT);
}

void loop() {
  int pitchRaw = analogRead(pitchPin);
  
  int rollRaw = analogRead(rollPin);
  
  pitchRaw = constrain(pitchRaw, 50, 973);
  int pitchMapped = map(pitchRaw,50,973,0,65535);
  rollRaw = constrain(rollRaw, 50, 973);
  int rollMapped = map(rollRaw,50,973,0,65535);

  Joystick.setYAxis(pitchRaw);
  Joystick.setXAxis(rollRaw);

  delay(10);(10);
}
