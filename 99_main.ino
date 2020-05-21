#define PIN_TRIG 3
#define PIN_ECHO 2

void setup() {
  display_setup();
  Serial.begin(9600);
  pinMode(PIN_TRIG, OUTPUT);
  pinMode(PIN_ECHO, INPUT);
}

void loop() {
  display_resetCursor();
  digitalWrite(PIN_TRIG, LOW);
  delayMicroseconds(2);
  digitalWrite(PIN_TRIG, HIGH);
  delayMicroseconds(12);
  unsigned int echoInput = pulseIn(PIN_ECHO, HIGH);
  Serial.println("echoInput: " + String(echoInput, DEC));
  double centimeters = (echoInput / 58L);
  display_println("echo", String(echoInput, DEC));
  display_println("cm", String(centimeters, 0));
  tone(4, echoInput / 10);
  delay(70);
}
