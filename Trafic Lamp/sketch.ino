// Traffic Light 1 Pins
int red1 = 2;
int yellow1 = 3;
int green1 = 4;

// Traffic Light 2 Pins
int red2 = 5;
int yellow2 = 6;
int green2 = 7;

// Traffic Light 3 Pins
int red3 = 8;
int yellow3 = 9;
int green3 = 10;

// Timing for each state (in milliseconds)
unsigned long redTime = 10000;    // 10 seconds for red light
unsigned long yellowTime = 3000;  // 3 seconds for yellow light
unsigned long greenTime = 10000;  // 10 seconds for green light

unsigned long previousMillis = 0; // To track time

int state = 0; // To track the current state of the lights

void setup() {
  // Set all LED pins as OUTPUT
  pinMode(red1, OUTPUT);
  pinMode(yellow1, OUTPUT);
  pinMode(green1, OUTPUT);

  pinMode(red2, OUTPUT);
  pinMode(yellow2, OUTPUT);
  pinMode(green2, OUTPUT);

  pinMode(red3, OUTPUT);
  pinMode(yellow3, OUTPUT);
  pinMode(green3, OUTPUT);

  // Start with Traffic Light 1 green, Traffic Light 2 and 3 red
  setTrafficLights(0);
}

void loop() {
  unsigned long currentMillis = millis();

  if (state == 0 && currentMillis - previousMillis >= greenTime) {
    previousMillis = currentMillis;
    state = 1; // Change Traffic Light 1 to yellow
    setTrafficLights(1);
  } 
  else if (state == 1 && currentMillis - previousMillis >= yellowTime) {
    previousMillis = currentMillis;
    state = 2; // Change Traffic Light 1 to red and Traffic Light 2 to green
    setTrafficLights(2);
  } 
  else if (state == 2 && currentMillis - previousMillis >= greenTime) {
    previousMillis = currentMillis;
    state = 3; // Change Traffic Light 2 to yellow
    setTrafficLights(3);
  } 
  else if (state == 3 && currentMillis - previousMillis >= yellowTime) {
    previousMillis = currentMillis;
    state = 4; // Change Traffic Light 2 to red and Traffic Light 3 to green
    setTrafficLights(4);
  } 
  else if (state == 4 && currentMillis - previousMillis >= greenTime) {
    previousMillis = currentMillis;
    state = 5; // Change Traffic Light 3 to yellow
    setTrafficLights(5);
  } 
  else if (state == 5 && currentMillis - previousMillis >= yellowTime) {
    previousMillis = currentMillis;
    state = 0; // Change Traffic Light 3 to red and Traffic Light 1 to green
    setTrafficLights(0);
  }
}

// Function to control the traffic lights based on the current state
void setTrafficLights(int state) {
  // Reset all lights to OFF
  digitalWrite(red1, LOW);
  digitalWrite(yellow1, LOW);
  digitalWrite(green1, LOW);

  digitalWrite(red2, LOW);
  digitalWrite(yellow2, LOW);
  digitalWrite(green2, LOW);

  digitalWrite(red3, LOW);
  digitalWrite(yellow3, LOW);
  digitalWrite(green3, LOW);

  // Set the lights based on the current state
  if (state == 0) {
    // Traffic Light 1 green, Traffic Light 2 and 3 red
    digitalWrite(green1, HIGH);
    digitalWrite(red2, HIGH);
    digitalWrite(red3, HIGH);
  } 
  else if (state == 1) {
    // Traffic Light 1 yellow, Traffic Light 2 and 3 red
    digitalWrite(yellow1, HIGH);
    digitalWrite(red2, HIGH);
    digitalWrite(red3, HIGH);
  } 
  else if (state == 2) {
    // Traffic Light 1 red, Traffic Light 2 green, Traffic Light 3 red
    digitalWrite(red1, HIGH);
    digitalWrite(green2, HIGH);
    digitalWrite(red3, HIGH);
  } 
  else if (state == 3) {
    // Traffic Light 1 red, Traffic Light 2 yellow, Traffic Light 3 red
    digitalWrite(red1, HIGH);
    digitalWrite(yellow2, HIGH);
    digitalWrite(red3, HIGH);
  } 
  else if (state == 4) {
    // Traffic Light 1 red, Traffic Light 2 red, Traffic Light 3 green
    digitalWrite(red1, HIGH);
    digitalWrite(red2, HIGH);
    digitalWrite(green3, HIGH);
  } 
  else if (state == 5) {
    // Traffic Light 1 red, Traffic Light 2 red, Traffic Light 3 yellow
    digitalWrite(red1, HIGH);
    digitalWrite(red2, HIGH);
    digitalWrite(yellow3, HIGH);
  }
}