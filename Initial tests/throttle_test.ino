#include <Joystick.h>

Joystick_ Joystick(
  0x04,
  JOYSTICK_TYPE_GAMEPAD,
  6, 0,
  true, true,
  true, false,
  false, false,
  false, false,
  false, false, false
);

const int pitchPin = A1;
const int rollPin = A0;
const int botao1 = 2;
const int throttlePin = A2;
int throttleValue = 1;
int lastThrottleValue = -1;

void setup() {

  pinMode(botao1, INPUT_PULLUP);
  pinMode(pitchPin, INPUT);
  pinMode(rollPin, INPUT);
  Joystick.setZAxisRange(0, 1023);
  Joystick.begin();
  delay(1000);
}

void loop() {
  int pitchRaw = analogRead(pitchPin);
  int rollRaw = analogRead(rollPin);
  
  // Eliminar ruído mínimo (3-1020)
  pitchRaw = constrain(pitchRaw, 3, 1020);
  rollRaw = constrain(rollRaw, 3, 1020);
  
  //throttle
  throttleValue = analogRead(throttlePin);

  if(throttleValue != lastThrottleValue){
    Joystick.setZAxis(throttleValue);
    lastThrottleValue = throttleValue;
  }
  Serial.println(throttleValue);

  // Enviar valores diretamente - sem map desnecessário
  Joystick.setYAxis(pitchRaw);
  Joystick.setXAxis(rollRaw);

  if(digitalRead(botao1) == LOW) {
    Serial.println("botao pressionado");
  }

  delay(10);
}
