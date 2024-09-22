// Definisikan pin untuk LED
const int led1 = 2;
const int led2 = 3;
const int led3 = 4;

// Definisikan pin untuk tombol
const int tombol1 = 5;
const int tombol2 = 6;

// Variabel untuk menyimpan status tombol
int statusTombol1 = 0;
int statusTombol2 = 0;

void setup() {
  // Inisialisasi pin LED sebagai output
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);

  // Inisialisasi pin tombol sebagai input
  pinMode(tombol1, INPUT);
  pinMode(tombol2, INPUT);
}

void loop() {
  // Baca status tombol
  statusTombol1 = digitalRead(tombol1);
  statusTombol2 = digitalRead(tombol2);

  // Jika tombol 1 ditekan, LED berjalan dari kiri ke kanan
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

  // Jika tombol 2 ditekan, LED berjalan dari kanan ke kiri
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