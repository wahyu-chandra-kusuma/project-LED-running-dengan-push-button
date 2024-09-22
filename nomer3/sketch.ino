// Definisi pin LED dan tombol
const int ledPins[] = {2, 3, 4};   // LED terhubung ke pin 2, 3, dan 4
const int button1Pin = 5;          // Tombol 1 di pin 5
const int button2Pin = 6;          // Tombol 2 di pin 6
const int button3Pin = 7;          // Tombol 3 di pin 7

int buttonState1 = HIGH;
int buttonState2 = HIGH;
int buttonState3 = HIGH;

void setup() {
  // Set LED sebagai output
  for (int i = 0; i < 3; i++) {
    pinMode(ledPins[i], OUTPUT);
  }
  
  // Set tombol sebagai input dengan pullup internal
  pinMode(button1Pin, INPUT_PULLUP);
  pinMode(button2Pin, INPUT_PULLUP);
  pinMode(button3Pin, INPUT_PULLUP);
}

void loop() {
  // Baca status tombol
  buttonState1 = digitalRead(button1Pin);
  buttonState2 = digitalRead(button2Pin);
  buttonState3 = digitalRead(button3Pin);

  // Jika tombol 1 ditekan, LED running dari kiri ke kanan
  if (buttonState1 == LOW) {
    runLeftToRight();
  }
  
  // Jika tombol 2 ditekan, LED running dari kanan ke kiri
  if (buttonState2 == LOW) {
    runRightToLeft();
  }
  
  // Jika tombol 3 ditekan, LED running dari kiri ke kanan lalu kanan ke kiri
  if (buttonState3 == LOW) {
    runLeftToRight();
    runRightToLeft();
  }
}

// Fungsi untuk LED running dari kiri ke kanan
void runLeftToRight() {
  for (int i = 0; i < 3; i++) {
    digitalWrite(ledPins[i], HIGH);
    delay(200);                     // Delay 200ms antar LED
    digitalWrite(ledPins[i], LOW);
  }
}

// Fungsi untuk LED running dari kanan ke kiri
void runRightToLeft() {
  for (int i = 2; i >= 0; i--) {
    digitalWrite(ledPins[i], HIGH);
    delay(200);                     // Delay 200ms antar LED
    digitalWrite(ledPins[i], LOW);
  }
}
