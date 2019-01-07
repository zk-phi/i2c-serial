#include <Wire.h>

void setup() {
  Wire.begin();
  Serial.begin(9600);
}

void loop() {
  Wire.requestFrom(0x0A, 4);

  Serial.println("read: ");

  while (Wire.available()) {
    byte lsb = Wire.read();
    byte msb = Wire.read();
    Serial.println((unsigned int)msb << 8 | lsb);
  }

  delay(500);
}
