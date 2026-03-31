
#include <SoftwareSerial.h>
#include <TinyGPS++.h>
#include <Wire.h>
#include <Adafruit_MPU6050.h>

static const int RXPinGPS = 10;
static const int TXPinGPS = 7;
static const uint32_t GPSBaud = 9600;

SoftwareSerial ssGPS(RXPinGPS, TXPinGPS);
TinyGPSPlus gps;

static const int RXPinGSM = 8;
static const int TXPinGSM = 9;

SoftwareSerial ssGSM(RXPinGSM, TXPinGSM);

const char PHONE_NUMBER[] = "+919137383143";

Adafruit_MPU6050 mpu;

uint32_t lastUpdate = 0;
const uint16_t updateInterval = 1000;

bool gsmReady = false;

void setup()
{
  Serial.begin(9600);
  Wire.begin();

  if (mpu.begin())
  {
    mpu.setAccelerometerRange(MPU6050_RANGE_8_G);
    mpu.setFilterBandwidth(MPU6050_BAND_21_HZ);
  }

  ssGPS.begin(GPSBaud);

  ssGSM.begin(9600);
  delay(2000);

  ssGSM.println("AT");
  delay(100);

  ssGSM.println("AT+CMGF=1");

  gsmReady = true;

  Serial.println("READY");
}

void loop()
{
  while (ssGPS.available())
  {
    gps.encode(ssGPS.read());
  }

  if (millis() - lastUpdate >= updateInterval)
  {
    lastUpdate = millis();

    sensors_event_t a, g, temp;

    mpu.getEvent(&a, &g, &temp);

    float totalAccel = sqrt(
        a.acceleration.x * a.acceleration.x +
        a.acceleration.y * a.acceleration.y +
        a.acceleration.z * a.acceleration.z);

    if (totalAccel < 2.0 || totalAccel > 15.0)
    {
      sendEmergencySMS();
    }

    Serial.print("Acceleration: ");
    Serial.print(totalAccel);

    if (gps.location.isValid())
    {
      Serial.print("  Lat: ");
      Serial.print(gps.location.lat(), 6);
      Serial.print("  Lng: ");
      Serial.print(gps.location.lng(), 6);
    }

    Serial.println();
  }

  if (ssGSM.available())
  {
    String msg = ssGSM.readString();

    if (msg.indexOf("GETLOC") >= 0)
    {
      sendLocationSMS();
    }
  }
}

void sendEmergencySMS()
{
  if (!gsmReady)
    return;

  ssGSM.print("AT+CMGS=\"");
  ssGSM.print(PHONE_NUMBER);
  ssGSM.println("\"");

  delay(1000);

  ssGSM.println("Threat detected !! from smart shoe!");

  delay(100);

  ssGSM.write(26);

  delay(3000);
}

void sendLocationSMS()
{
  if (!gsmReady || !gps.location.isValid())
    return;

  char msg[120];

  sprintf(msg,
          "Location recorded from shoe: https://maps.google.com/?q=%.6f,%.6f",
          gps.location.lat(),
          gps.location.lng());

  ssGSM.print("AT+CMGS=\"");
  ssGSM.print(PHONE_NUMBER);
  ssGSM.println("\"");

  delay(1000);

  ssGSM.println(msg);

  delay(100);

  ssGSM.write(26);

  delay(3000);
}