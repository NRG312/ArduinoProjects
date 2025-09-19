float sensorState;
int SensorDigital = 4;
int SensorAnalog = A0;
//
int buttonState;
int relayPin = 4;
void setup() {
  Serial.begin(9600);
  pinMode(relayPin, OUTPUT);
  digitalWrite(SensorDigital, LOW);
  pinMode(2, INPUT_PULLUP);
}

void loop() {
  sensorState = analogRead(SensorAnalog);
  buttonState = digitalRead(2);
  Serial.println(buttonState);
  delay(100);
  CheckButtonState();
}
void TurnOnMotor(){
  if(buttonState == LOW){
    if(sensorState < 800){
      digitalWrite(relayPin, HIGH);
    }else{
      digitalWrite(relayPin, LOW);
    }
  }else{
    digitalWrite(relayPin, LOW);
  }
}
void CheckButtonState(){
  if(buttonState == LOW){
  TurnOnMotor();
  CheckSensorAmount();
  }
}
void CheckSensorAmount(){
  delay(5000);
  digitalWrite(SensorDigital, HIGH);
  Serial.println(sensorState);
  delay(100);
  digitalWrite(SensorDigital, LOW);
}