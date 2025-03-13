const int potansiyometre = A0;
const int Led = 5;

void setup() {
  pinMode(potansiyometre, INPUT);
  pinMode(Led, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int pot_deger = analogRead(potansiyometre);
  
  int ledBlinkCount = map(pot_deger, 0, 1023, 1, 5);
  
  Serial.print("Potansiyometre Değeri: ");
  Serial.print(pot_deger);
  Serial.print(" - Yanıp Sönme Sayısı: ");
  Serial.println(ledBlinkCount);
  
  for (int i = 0; i < ledBlinkCount; i++) {
    digitalWrite(Led, HIGH);
    delay(50);
    digitalWrite(Led, LOW);
    delay(50);
  }

  delay(500);
}
