#define LED_RED 2
#define BTN_RED 3
#define SERIAL_ARDUINO 9600
#define HALF_SECOND 500

void setup() {
  // put your setup code here, to run once:
  Serial.begin(SERIAL_ARDUINO);
  pinMode(LED_RED, OUTPUT);
  pinMode(BTN_RED, INPUT_PULLUP);

  digitalWrite(LED_RED, HIGH);
  delay(HALF_SECOND);
  digitalWrite(LED_RED, LOW);
  
}

void loop() {
  // put your main code here, to run repeatedly:
      int btnState = digitalRead(BTN_RED);
      Serial.println(btnState);
      delay(HALF_SECOND);

//      if(btnState == LOW){
//        digitalWrite(LED_RED, HIGH);
//        delay(HALF_SECOND);
//        digitalWrite(LED_RED, LOW);
//      }
}
