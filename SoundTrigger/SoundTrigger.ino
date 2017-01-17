int sensorValue;
int sensorLow = 1023;
int sensorHigh = 0;
int dialValue;
bool hitted = false;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  
  sensorValue = analogRead(A0);
  while(millis() < 100) {
    if (sensorValue > sensorHigh) {
      sensorHigh = sensorValue;
    }
    if (sensorValue < sensorLow) {
      sensorLow = sensorValue; 
    }
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  sensorValue = analogRead(A0);
  dialValue = analogRead(A1);
  if (sensorValue > sensorHigh) {
    sensorHigh = sensorValue;
  }
  if (sensorValue < sensorLow) {
    sensorLow = sensorValue; 
  }
//  Serial.print("Sensor Value : ");
//  Serial.println(map(dialValue, 0, 1023, 100, 800));
//  Serial.print("\tMapped:");
//  Serial.println(map(sensorValue, sensorLow, sensorHigh, 50, 4000));
  if(sensorValue < map(dialValue, 0, 1023, 100, 800)) {
    if (not hitted) {
      hitted = true;
      Serial.println("T");
    }
  } else {
    hitted = false;
  }
  delay(40);
}
