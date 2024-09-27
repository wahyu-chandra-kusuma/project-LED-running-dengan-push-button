
const int led1 = 2;
const int led2 = 3;
const int led3 = 4;


const int tombol1 = 5;
const int tombol2 = 6;


int statusTombol1 = 0;
int statusTombol2 = 0;

void setup() {
 
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);

  
  pinMode(tombol1, INPUT);
  pinMode(tombol2, INPUT);
}

void loop() {
  
  statusTombol1 = digitalRead(tombol1);
  statusTombol2 = digitalRead(tombol2);

 
  if (statusTombol1 == HIGH) {
    digitalWrite(led1, HIGH);
    delay(300);
    digitalWrite(led1, LOW);
    digitalWrite(led2, HIGH);
    delay(300);
    digitalWrite(led2, LOW);
    digitalWrite(led3, HIGH);
    delay(300);
    digitalWrite(led3, LOW);
  }

  
  if (statusTombol2 == HIGH) {
    digitalWrite(led3, HIGH);
    delay(300);
    digitalWrite(led3, LOW);
    digitalWrite(led2, HIGH);
    delay(300);
    digitalWrite(led2, LOW);
    digitalWrite(led1, HIGH);
    delay(300);
    digitalWrite(led1, LOW);
  }
}
