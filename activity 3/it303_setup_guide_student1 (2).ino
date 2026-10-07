const int buttonPin = 2;
const int led1Pin = 13;
const int led2Pin = 12;

int pressCount = 0;
int lastButtonState = LOW;
unsigned long lastDebounceTime = 0;
const unsigned long debounceDelay = 30; 

void setup() {
  pinMode(buttonPin, INPUT);
  pinMode(led1Pin, OUTPUT);
  pinMode(led2Pin, OUTPUT);
  digitalWrite(led1Pin, LOW);
  digitalWrite(led2Pin, LOW);
  Serial.begin(9600);
}

void loop() {
  int reading = digitalRead(buttonPin);

  
  digitalWrite(led1Pin, reading);

  
  if (reading == HIGH && lastButtonState == LOW) {
    
    if ((millis() - lastDebounceTime) > debounceDelay) {
      pressCount++;
      Serial.print("Press Count: ");
      Serial.println(pressCount);

      
      if (pressCount % 3 == 0) {
        digitalWrite(led2Pin, HIGH);
      } else {
        digitalWrite(led2Pin, LOW);
      }

      lastDebounceTime = millis();
    }
  }

  lastButtonState = reading;
}