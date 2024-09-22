
const int led1 = 2;
const int led2 = 3;
const int led3 = 4;


const int buttonPin = 5;


int buttonState = 0;
int currentLED = 0;
bool running = false;

void setup() {
  
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);

  
  pinMode(buttonPin, INPUT);

  
  digitalWrite(led1, LOW);
  digitalWrite(led2, LOW);
  digitalWrite(led3, LOW);
}

void loop() {
  
  buttonState = digitalRead(buttonPin);

  
  if (buttonState == HIGH) {
    running = true;
  }

  if (running) {
    
    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
    digitalWrite(led3, LOW);

   
    if (currentLED == 0) {
      digitalWrite(led1, HIGH);
    } else if (currentLED == 1) {
      digitalWrite(led2, HIGH);
    } else if (currentLED == 2) {
      digitalWrite(led3, HIGH);
    }

    
    delay(500);

    
    currentLED++;

    
    if (currentLED > 2) {
      running = false; 
      currentLED = 0;    
    }
  }
}
