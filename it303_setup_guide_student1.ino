void setup() {
  pinMode(2, INPUT);
  pinMode(13, OUTPUT);
  
  digitalWrite(13, LOW);

  Serial.begin(9600);
}

void loop() {
  int buttonState =
digitalRead(2);
  
  if(buttonState == HIGH){
    digitalWrite(13, HIGH);
    Serial.println("Button: PRESSED | LED ON");
  }
  else{
    digitalWrite(13, LOW);
    Serial.println("Button:RELEASED | LED:OFF");
  }
  
  delay(200);
}
  
  
    
