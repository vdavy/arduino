#define LOWBAT     3.65 // battery low voltage threshold in V - objenious level !

#ifndef LOWBAT
#define LOWBAT     3.1 // battery low voltage threshold in V
#endif
#define VF         1.2 // SML-P11VT forward voltage in V (under current adjusted)
#define USB_MIDDLE_COMP 500

boolean usbPlugged() {
  return getVUSB() > USB_MIDDLE_COMP ? true:false;
}

float batteryLevel() {
  return 3.3 * getVBAT() / 1024 + VF;
}

boolean isBatteryLow() {
  return batteryLevel() < LOWBAT;
}

boolean isCharged() {
  return digitalRead(NCHG);
}

int getVUSB() {
  return analogRead(VUSB);
}

int getVBAT() {
  return analogRead(VBAT);
}

