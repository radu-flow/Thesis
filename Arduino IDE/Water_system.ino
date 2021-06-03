// if soil sensor reads a value under this value, then start watering
const int dry = 300;

const int pumpPin = 5;
const int soilSensor = A1;

void setup() {
  pinMode(pumpPin, OUTPUT);
  pinMode(soilSensor, INPUT);
  Serial.begin(9600);
  delay(1000);
}

void loop() {
  // read current moisture
  int moisture = analogRead(soilSensor);
  Serial.println(moisture);
  delay(1000);
  
  if (moisture >= dry) {
    Serial.println("Watering starts now..moisture is " + String(moisture));
    digitalWrite(pumpPin, LOW);

    // keep watering for 3 sec
    delay(3000);

    // turn off the pump, stop watering
    digitalWrite(pumpPin, HIGH);
    Serial.println("Done watering.");
  } 
  else {
    // if the soil is not dry
    Serial.println("Moisture is adequate. No watering needed " + String(moisture));
  }
}
