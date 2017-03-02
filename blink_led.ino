#define RED_LED 2
#define ONE_SECOND 1000
#define HALF_SECOND 500

void setup() {
  // put your setup code here, to run once:
  pinMode(RED_LED, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  blinkLed(RED_LED);
}

void blinkLed(int ledPort){ 
  digitalWrite(ledPort, HIGH);
  delay(ONE_SECOND);
  digitalWrite(ledPort, LOW);
  delay(HALF_SECOND);
}
