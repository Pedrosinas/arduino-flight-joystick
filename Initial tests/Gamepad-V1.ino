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
// int throttleValue = 1;
// int lastThrottleValue = -1;

void setup() {

  pinMode(botao1, INPUT_PULLUP);
  pinMode(pitchPin, INPUT);
  pinMode(rollPin, INPUT);
  // Joystick.setZAxisRange(0, 1023);

  Joystick.setXAxisRange(0, 65535);
  Joystick.setYAxisRange(0, 65535);

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
  // throttleValue = analogRead(throttlePin);

  // if(throttleValue != lastThrottleValue){
  //   Joystick.setZAxis(throttleValue);
  //   lastThrottleValue = throttleValue;
  // }
  // Serial.println(throttleValue);

  // Ajuste para 16 bits
  Joystick.setYAxis((uint32_t)(pitchRaw * 65535UL / 1023));
  Joystick.setXAxis((uint32_t)(rollRaw * 65535UL / 1023));

  Joystick.setButton(0, digitalRead(botao1) == LOW);

  if(digitalRead(botao1) == LOW) {
    Serial.println("botao apertado");
  }

  delay(10);
}
