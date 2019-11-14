#include <SoftwareSerial.h>
#include <Wire.h>
//GPS
#include <TinyGPS++.h>
#include <SoftwareSerial.h>
#define RXPin 2
#define TXPin 3
#define GPSBaud 9600
String local;
TinyGPSPlus gps;
SoftwareSerial gpsSerial(RXPin, TXPin);
//===============================end GPS
const int MPU_addr = 0x68;
int16_t AcX, AcY, AcZ;
float tmpx, tmpy, tmpz;
SoftwareSerial my(10, 11); // RX, TX
byte se[] = {0x0D, 0x0A};
byte s[] = {0x1A};
void setup()
{
  Wire.begin();
  Wire.beginTransmission(MPU_addr);
  Wire.write(0x6B);
  Wire.write(0);
  Wire.endTransmission(true);
  sim.begin(9600);
  Serial.begin(9600);
  gpsSerial.begin(GPSBaud);
}
void loop() {
  MPU();
  if ((((tmpx >= -10) and (tmpx <= 10)) and ((tmpy >= -14) and (tmpy <= 10)) and (((tmpz >= 89) and (tmpz <= 95)) or ((tmpz >= -90) and (tmpz <= -80))))
      or (((tmpz > 0) and (tmpz <= 4)) and (((tmpx > 10) and (tmpx >= -25)) or ((tmpx >= 0) and (tmpx <= 70))) and (((tmpy < 90) and (tmpy > 70)) or ((tmpy >= -90) and (tmpy <= 70))))
      or ((((tmpz >= 3) and (tmpz <= 10)) and ((tmpy < 80) and (tmpy > 40)) and (tmpx > -80) and (tmpx < -20)) or (((tmpz > 6) and (tmpz < 15)) and ((tmpy < -40) and (tmpy >= -90)) and (((tmpx > 40) and (tmpx < 50)) or ((tmpx < -20) and (tmpx < -50)))))
      or ((((tmpz >= 2) and (tmpz < 5)) and ((tmpy > 30) and (tmpy < 80)) and ((tmpx < -35) and (tmpx > -85))) or (((tmpz >= 1) and (tmpz <= 4)) and ((tmpy < -60) and (tmpy >= -90)) and ((tmpx > -70) and (tmpx < -30))))
     )
  {
    Send_SMS();
  }
}
