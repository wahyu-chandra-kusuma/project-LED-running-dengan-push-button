
int red1 = 2;
int yellow1 = 3;
int green1 = 4;


int red2 = 5;
int yellow2 = 6;
int green2 = 7;


int red3 = 8;
int yellow3 = 9;
int green3 = 10;


unsigned long redTime = 10000;   
unsigned long yellowTime = 3000;  
unsigned long greenTime = 10000;  

unsigned long previousMillis = 0; 

int state = 0; 

void setup() {
  
  pinMode(red1, OUTPUT);
  pinMode(yellow1, OUTPUT);
  pinMode(green1, OUTPUT);

  pinMode(red2, OUTPUT);
  pinMode(yellow2, OUTPUT);
  pinMode(green2, OUTPUT);

  pinMode(red3, OUTPUT);
  pinMode(yellow3, OUTPUT);
  pinMode(green3, OUTPUT);

  
  setTrafficLights(0);
}

void loop() {
  unsigned long currentMillis = millis();

  if (state == 0 && currentMillis - previousMillis >= greenTime) {
    previousMillis = currentMillis;
    state = 1; 
    setTrafficLights(1);
  } 
  else if (state == 1 && currentMillis - previousMillis >= yellowTime) {
    previousMillis = currentMillis;
    state = 2; 
    setTrafficLights(2);
  } 
  else if (state == 2 && currentMillis - previousMillis >= greenTime) {
    previousMillis = currentMillis;
    state = 3; 
    setTrafficLights(3);
  } 
  else if (state == 3 && currentMillis - previousMillis >= yellowTime) {
    previousMillis = currentMillis;
    state = 4; 
    setTrafficLights(4);
  } 
  else if (state == 4 && currentMillis - previousMillis >= greenTime) {
    previousMillis = currentMillis;
    state = 5; 
    setTrafficLights(5);
  } 
  else if (state == 5 && currentMillis - previousMillis >= yellowTime) {
    previousMillis = currentMillis;
    state = 0; 
    setTrafficLights(0);
  }
}


void setTrafficLights(int state) {
  
  digitalWrite(red1, LOW);
  digitalWrite(yellow1, LOW);
  digitalWrite(green1, LOW);

  digitalWrite(red2, LOW);
  digitalWrite(yellow2, LOW);
  digitalWrite(green2, LOW);

  digitalWrite(red3, LOW);
  digitalWrite(yellow3, LOW);
  digitalWrite(green3, LOW);

 
  if (state == 0) {
   
    digitalWrite(green1, HIGH);
    digitalWrite(red2, HIGH);
    digitalWrite(red3, HIGH);
  } 
  else if (state == 1) {
   
    digitalWrite(yellow1, HIGH);
    digitalWrite(red2, HIGH);
    digitalWrite(red3, HIGH);
  } 
  else if (state == 2) {
   
    digitalWrite(red1, HIGH);
    digitalWrite(green2, HIGH);
    digitalWrite(red3, HIGH);
  } 
  else if (state == 3) {
    
    digitalWrite(red1, HIGH);
    digitalWrite(yellow2, HIGH);
    digitalWrite(red3, HIGH);
  } 
  else if (state == 4) {
    
    digitalWrite(red1, HIGH);
    digitalWrite(red2, HIGH);
    digitalWrite(green3, HIGH);
  } 
  else if (state == 5) {
    
    digitalWrite(red1, HIGH);
    digitalWrite(red2, HIGH);
    digitalWrite(yellow3, HIGH);
  }
}
