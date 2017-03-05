#define LED_RED_1 2
#define LED_RED_3 4
#define LED_GREEN_2 3

#define ONE_SECOND 1000
#define HALF_SECOND 500

#define NUMBER_OF_LEDS 3

#define BTN_RED_1 9
#define BTN_GREEN_2 10
#define BTN_RED_3 11

#define ARDUINO_DEBUG 9600

#define UNDEFINED_BUTTON -1

int leds[NUMBER_OF_LEDS];

void setup() {
  // put your setup code here, to run once:
  Serial.begin(ARDUINO_DEBUG);
  setupLeds();
  setupButtons();
  setupVetorLeds();
//  turnOnAll();
}

void loop() {
  // put your main code here, to run repeatedly:
   int randomNumber = analogRead(0);
  randomSeed(randomNumber);
  Serial.println(randomNumber);
  for(int index = 0; index < NUMBER_OF_LEDS; index++){
    blinkLed(leds[index]);
  }
 int state = getButtonPressed();

}

int getButtonPressed() {
  if(digitalRead(BTN_RED_1) == LOW){
    return blinkLed(LED_RED_1);
  }else if(digitalRead(BTN_GREEN_2) == LOW){
    return blinkLed(LED_GREEN_2);
  }else if(digitalRead(BTN_RED_3) == LOW){
    return blinkLed(LED_RED_3);
  }else {
    return UNDEFINED_BUTTON;
  }
}

void setupLeds(){
  pinMode(LED_RED_1, OUTPUT);
  pinMode(LED_GREEN_2, OUTPUT);
  pinMode(LED_RED_3, OUTPUT);
}

void setupButtons() {
  pinMode(BTN_RED_1, INPUT_PULLUP);
  pinMode(BTN_GREEN_2, INPUT_PULLUP);
  pinMode(BTN_RED_3, INPUT_PULLUP);
}

void setupVetorLeds() {
  int randomNumber = analogRead(0);
  randomSeed(randomNumber);
  for(int index = 0; index < NUMBER_OF_LEDS; index++){
    leds[index] = sortColor();
  }
}

int sortColor(){
  return random(LED_RED_1, LED_RED_3 + 1);
}

int blinkLed(int ledPosition){
  digitalWrite(ledPosition, HIGH);
  delay(ONE_SECOND);
  digitalWrite(ledPosition, LOW);
  delay(HALF_SECOND);
  return ledPosition;
}

void turnOnAll(){
  digitalWrite(LED_RED_1, HIGH);
  digitalWrite(LED_GREEN_2, HIGH);
  digitalWrite(LED_RED_3, HIGH);
  delay(ONE_SECOND);
  digitalWrite(LED_RED_1, LOW);
  digitalWrite(LED_GREEN_2, LOW);
  digitalWrite(LED_RED_3, LOW);
  delay(HALF_SECOND);
}

