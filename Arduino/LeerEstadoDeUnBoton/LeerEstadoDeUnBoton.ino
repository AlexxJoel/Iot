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

