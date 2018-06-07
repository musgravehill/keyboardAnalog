/*
  -----------GND VCC OUT ------------
  ------------- * * * ---------------
  -----723 ------------------- 0 ----
  --------------- 131 ---------------
  -----488 ------------------ 321 ---
*/



int sensorPin = A0;    // select the input pin for the potentiometer

int sensorValue = 0;  // variable to store the value coming from the sensor

void setup() {
  Serial.begin(9600);
}

void loop() {
  // read the value from the sensor:
  sensorValue = key();
  delay(500);
  Serial.println(sensorValue, DEC);
}

byte key(){  
  int val = analogRead(0);
    if (val < 50) return 1;
    else if (val < 150) return 2;
    else if (val < 350) return 3;
    else if (val < 500) return 4;
    else if (val < 800) return 5;
    else return 0;  
}
