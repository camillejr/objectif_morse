// ARDUINO: MEASURING SIGNAL TIMES

const int analogInPin = A0;
int sensorValue = 0;
int sensorMean = 0;
int sensorThres;
boolean prevSignal = false;
int timeDuration = 0;
int timePrev = 0;

void setup()
{

  Serial.begin(9600);

  // Calibration
  for(int i=0; i<10; ++i)
  {
    sensorValue += analogRead(analogInPin);
    delay(100);
  }
  sensorMean = sensorValue / 10;
  sensorThres = sensorMean + 20;
}

void loop() {

  sensorValue = analogRead(analogInPin);

  // Signal changing from Low to High
  if (sensorValue > sensorThres && !prevSignal)
  {
    timeDuration = millis() - timePrev;
    timePrev = millis();
    Serial.print("\nL ");
    Serial.print(timeDuration);
    prevSignal = true;
  }

  // Signal changing from High to Low
  if (sensorValue - sensorMean < 10 && prevSignal)
  {
    timeDuration = millis() - timePrev;
    timePrev = millis();
    Serial.print("\nH ");
    Serial.print(timeDuration);
    prevSignal = false;
  }
}
