#include <Joystick.h>

Joystick_ Joystick(
  0x04,
  JOYSTICK_TYPE_GAMEPAD,
  16, 1,
  true, true,
  false, false,
  false, false,
  false, false,
  false, false, false
);

const int pitchPin = A1;
const int rollPin = A0;

void setup() {
  pinMode(pitchPin, INPUT);
  pinMode(rollPin, INPUT);
  Joystick.begin();
  delay(1000);
}

void loop() {
  int pitchRaw = analogRead(pitchPin);
  int rollRaw = analogRead(rollPin);
  
  // Eliminar ruído mínimo (3-1020)
  pitchRaw = constrain(pitchRaw, 3, 1020);
  rollRaw = constrain(rollRaw, 3, 1020);
  
  // Enviar valores diretamente - sem map desnecessário
  Joystick.setYAxis(pitchRaw);
  Joystick.setXAxis(rollRaw);

  delay(10);
}
