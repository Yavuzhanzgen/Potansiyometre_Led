const int potansiyometre = A0;
const int led1 = 2;
const int led2 = 3;
const int led3 = 4;
const int led4 = 5;
const int led5 = 6;

void setup() {
  pinMode(potansiyometre, INPUT);
  
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  pinMode(led5, OUTPUT);

  Serial.begin(9600);
}

void loop() {
  int pot_deger = analogRead(potansiyometre);
  
  Serial.print("Potansiyometre Değeri: ");
  Serial.println(pot_deger);

  int sure = map(pot_deger, 0, 1023, 0, 10); 

  if (sure >= 1 && sure <= 10) {
    Serial.println("Zaman");

    digitalWrite(led1, sure >= 1 ? HIGH : LOW);
    digitalWrite(led2, sure >= 2 ? HIGH : LOW);
    digitalWrite(led3, sure >= 3 ? HIGH : LOW);
    digitalWrite(led4, sure >= 4 ? HIGH : LOW);
    digitalWrite(led5, sure >= 5 ? HIGH : LOW);
  } else {
    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
    digitalWrite(led3, LOW);
    digitalWrite(led4, LOW);
    digitalWrite(led5, LOW);
  }

  delay(1000); // 1 saniye bekle
}
