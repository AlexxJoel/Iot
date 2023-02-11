// Photoresistance variables
#define analogPin A0
int light; // to save the ilumination
int voltage;

void setup()
{
  Serial.begin(9600);
}

void loop()
{
  voltage = analogRead(analogPin);
  light = ((long)voltage * 1000 * 10) / ((long)15 * 10 * (1024 - voltage)); // operation to come voltage to ligth

  if (light > 99)
  {
    Serial.println("Day -> " + String(light));
  }
  else
  {
    Serial.println("Nigth -> " + String(light));
  }
  delay(1000);
}

//------------------------------------------------------------------------------------------------

// Ultrasonic variables
const int dEcho = 2;
const int dTrigger = 3;
long time, distance;

void setup()
{
  Serial.begin(9600);
  pinMode(dTrigger, OUTPUT);
  pinMode(dEcho, INPUT);
  digitalWrite(dTrigger, LOW);
}

void loop()
{

  digitalWrite(dTrigger, HIGH);
  delayMicroseconds(10);
  digitalWrite(dTrigger, LOW);

  time = pulseIn(dEcho, HIGH);
  distance = (time / 59);

  Serial.println("Distance -> " + String(distance) + " cm ");

  delay(1500);
}

//-------------------------------------------------------------------

// temperature variables
const int analogPinTemperature = A1;
float volts, celsius, valueAdc;

void setup()
{
  Serial.begin(9600);
}

void loop()
{
  valueAdc = analogRead(analogPinTemperature);
  volts = (valueAdc / 1023.0) * 5;
  celsius = volts * 100.00;
  Serial.println(String(celsius) + " C");
  delay(1000);
}

//-----------------------------------------------------------------------------

// humidity variable
int SensorPin = A2;

void setup()
{
  Serial.begin(9600);
}
void loop()
{
  int value = analogRead(SensorPin);
  int humedad = map(value, 0, 1023, 100, 0);
  Serial.println("Map " + String(humedad) + " Normal " + String(value));
  delay(1000);
}

//-----------------------------------------------------------------------

// Include library
#include <Servo.h>
const int dServoMotor = 4;
// variable to use
Servo servoMotor;

void setup()
{
  Serial.begin(9600);
  servoMotor.attach(dServoMotor);
}

void loop()
{

  servoMotor.write(0);
  delay(1000);
  servoMotor.write(90);
  delay(1000);
  servoMotor.write(180);
  delay(1000);
  servoMotor.write(90);
  delay(1000);
}

//----------------------------------------------------------------------------------
// releeey
int rele = 5;
void setup()
{
  Serial.begin(9600);
  pinMode(rele, OUTPUT);
}
void loop()
{
  digitalWrite(rele, LOW);
  delay(2000);
  digitalWrite(rele, HIGH);
  delay(2000);
}

//----------------------------------------------------------------------------------
// led rgb

int pinR = 13;
int pinG = 12;
int pinB = 11;

void setup()
{
  pinMode(pinR, OUTPUT);
  pinMode(pinG, OUTPUT);
  pinMode(pinB, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  // rand()% (DESDE - HASTA +1)+DESDE
  int i = (rand() % 255 - 1) + 1;
  int j = (rand() % 255 - 1) + 1;
  int k = (rand() % 255 - 1) + 1;
  color(i, j, k);

  delay(500);
  Serial.println(String(i) + "  " + String(j) + "  " + String(k));

  // color(255,0,0);
  // delay(500);
  // color(0,0,255);
  // delay(500);
  // color(0,255,0);
  // delay(500);
  // color(255,255,255);
  // delay(500);
  // color(0,0,0);
  // delay(500);
}

void color(int R, int G, int B)
{

  analogWrite(pinR, R);
  analogWrite(pinG, G);
  analogWrite(pinB, B);
}

//-----------------------------------------------------
