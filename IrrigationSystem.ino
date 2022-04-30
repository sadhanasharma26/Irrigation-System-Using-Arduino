
String level;
const int dry = 598; // value for dry sensor
const int wet = 300; // value for wet sensor

int moisture_sensor_pin = A0; 

const int RELAY_PIN = 13; 

void setup() 
{
  Serial.begin(9600);
  pinMode(RELAY_PIN, OUTPUT); 
  digitalWrite(RELAY_PIN, LOW);
}
 
void loop() 
{
  int sensorVal = analogRead(moisture_sensor_pin);
  int percentageHumididy = map(sensorVal, wet, dry, 100, 0);
  delay(100);
  if(percentageHumididy>=-10 && percentageHumididy<=20)
  {
    digitalWrite(RELAY_PIN, LOW);
    level = "Low";
    }
  else if(percentageHumididy>=21 && percentageHumididy<=60)
  {
    digitalWrite(RELAY_PIN, HIGH);
    level = "Mid";
  }
  else
  {
    digitalWrite(RELAY_PIN, HIGH);
    level = "High";
  }
}
