
int led = D4;        // used for ESP8266
int Gas_analog = A0;    // used for ESP8266
int Gas_digital = D0;   // used for ESP8266


void setup() {
  Serial.begin(9600);
  pinMode(led, OUTPUT);      
  pinMode(Gas_digital, INPUT);
}

void loop() {
  int gassensorAnalog = analogRead(Gas_analog);
  int gassensorDigital = digitalRead(Gas_digital);

  Serial.print("Gas Sensor: ");
  Serial.print(gassensorAnalog);
  Serial.print("\t");
  Serial.print("Gas Class: ");
  Serial.print(gassensorDigital);
  Serial.print("\t");
  Serial.print("\t");
  
  if (gassensorAnalog > 500) {
    Serial.println("Gas");
    
    digitalWrite (led, LOW) ; //send tone
    delay(350);
    digitalWrite (led, HIGH) ;  //no tone
  }
  else {
    Serial.println("No Gas");
  }
  delay(100);
}
