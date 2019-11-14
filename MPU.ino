void MPU() {
  Wire.beginTransmission(MPU_addr);
  Wire.write(0x3B);
  Wire.endTransmission(false);
  Wire.requestFrom(MPU_addr, 14, true);
  AcX = Wire.read() << 8 | Wire.read();
  AcY = Wire.read() << 8 | Wire.read();
  AcZ = Wire.read() << 8 | Wire.read();
  tmpx = map(AcX, -16384, 16384, -90, 90);
  tmpy = map(AcY, -16834, 16843, -90, 90);
  tmpz = map(AcZ, -16834, 16843, -90, 90);
  Serial.print("x: "); Serial.println(tmpx);
  Serial.print("Y: "); Serial.println(tmpy);
  Serial.print("Z: "); Serial.println(tmpz);
}
