const int LED = 13;
const int OFF = 0;
const int ON = 255;

void setup() {
  pinMode(LED, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  allume();
  clignote();
  variation();
  stop();
}


void allume() {
  Serial.println("Allumé - 2486739");
  analogWrite(LED, ON);
  delay(2000);
}

void clignote() {
  Serial.println("Clignotement - 2486739");
  for (int i = 1; i <= 3; i++) {
    analogWrite(LED, ON);
    delay(250);
    analogWrite(LED, OFF);
    delay(250);
  }
}

void variation() {
  const int TIME_TAKEN = 2048;
  const int JUMPS = 15;
  const int FADE = (ON + 1) / JUMPS;
  const int DELAY_VARIATION = TIME_TAKEN / JUMPS;
  int fading_variable = 255;

  Serial.println("Variation - 2486739");

  for (fading_variable = 255; fading_variable >= OFF; fading_variable -= FADE) {
    analogWrite(LED, fading_variable);
    delay(DELAY_VARIATION);
  }
}

void stop() {
  Serial.println("Éteint - 2486739");
  analogWrite(LED, OFF);
  delay(2000);
}