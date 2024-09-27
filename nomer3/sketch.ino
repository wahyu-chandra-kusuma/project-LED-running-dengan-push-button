
const int ledPins[] = {2, 3, 4};  
const int button1Pin = 5;          
const int button2Pin = 6;          
const int button3Pin = 7;         

int buttonState1 = HIGH;
int buttonState2 = HIGH;
int buttonState3 = HIGH;

void setup() {
  
  for (int i = 0; i < 3; i++) {
    pinMode(ledPins[i], OUTPUT);
  }
  
  
  pinMode(button1Pin, INPUT_PULLUP);
  pinMode(button2Pin, INPUT_PULLUP);
  pinMode(button3Pin, INPUT_PULLUP);
}

void loop() {
  
  buttonState1 = digitalRead(button1Pin);
  buttonState2 = digitalRead(button2Pin);
  buttonState3 = digitalRead(button3Pin);

  
  if (buttonState1 == LOW) {
    runLeftToRight();
  }
  
  
  if (buttonState2 == LOW) {
    runRightToLeft();
  }
  
  
  if (buttonState3 == LOW) {
    runLeftToRight();
    runRightToLeft();
  }
}


void runLeftToRight() {
  for (int i = 0; i < 3; i++) {
    digitalWrite(ledPins[i], HIGH);
    delay(200);                     
    digitalWrite(ledPins[i], LOW);
  }
}


void runRightToLeft() {
  for (int i = 2; i >= 0; i--) {
    digitalWrite(ledPins[i], HIGH);
    delay(200);                     
    digitalWrite(ledPins[i], LOW);
  }
}
