#ifndef JOYSTICK_CONFIG_H
#define JOYSTICK_CONFIG_H

#include <Joystick.h>

Joystick_ Joystick(
  JOYSTICK_DEFAULT_REPORT_ID, 
  JOYSTICK_TYPE_JOYSTICK,
  12,     // buttonCount - 12 botões
  0,      // hatSwitchCount - 0 hats
  true,   // includeXAxis - Ailerons
  true,   // includeYAxis - Elevador
  true,   // includeZAxis - Leme
  false,  // includeRxAxis
  false,  // includeRyAxis
  false,  // includeRzAxis
  true,   // includeThrottle - Acelerador
  true,   // includeRudder -
  false,  // includeAccelerator
  false,  // includeBrake
  false   // includeSteering
);

#endif
