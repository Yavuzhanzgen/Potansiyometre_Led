#define LED_PIN 5
#define BUTTON_PIN 2

int blinkDelay = 1000; /
int buttonCount = 0; 
unsigned long lastButtonPressTime = 0;
bool setupMode = false; 

unsigned long previousMillis = 0;  
const long interval = 1000;  

void buttonPress() {
  static unsigned long lastDebounceTime = 0;  
  unsigned long debounceDelay = 200;  

  

  if ((millis() - lastDebounceTime) > debounceDelay) {
    if (setupMode) {  
      buttonCount++;
      Serial.print("Button pressed: ");
      Serial.println(buttonCount);
    }
    lastDebounceTime = millis();  
  }
}
void setup() {
  pinMode(LED_PIN, OUTPUT);
  pinMode(BUTTON_PIN, INPUT);
  
  Serial.begin(9600);

 
  attachInterrupt(digitalPinToInterrupt(BUTTON_PIN), buttonPress, RISING);  
}

void loop() {
  
  unsigned long currentMillis = millis();
  
  if (currentMillis - previousMillis >= blinkDelay) {
    previousMillis = currentMillis;
    
 
    digitalWrite(LED_PIN, !digitalRead(LED_PIN));  
  }

  
  if (!setupMode) {
    int buttonState = digitalRead(BUTTON_PIN);

    if (buttonState == HIGH) {
      setupMode = true; 
      buttonCount = 0;  
      lastButtonPressTime = millis();
      Serial.println("Setup mode active. You have 10 seconds to press the button...");

 
      while (millis() - lastButtonPressTime < 10000) {
    
      }

   
      if (buttonCount > 0 && buttonCount <= 5) {
        blinkDelay = buttonCount * 1000;
      }

      Serial.print("New Blink Delay: ");
      Serial.print(blinkDelay);
      Serial.println(" ms");

      setupMode = false; 
      Serial.println("SETUP MODE: Inactive");
      delay(500); 
    }
  }
}
