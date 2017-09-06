/*
 * 18220 PreLab 1
 */

const int LED = 3;
const int TRIGGER =2;
int trigState = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(LED, OUTPUT);
  pinMode(TRIGGER, INPUT);
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  trigState =  digitalRead(TRIGGER);
  if ( trigState == LOW) {
    delay(500);
    trigState =  digitalRead(TRIGGER);
    if (trigState == HIGH){
      digitalWrite(LED, HIGH);
      delay(60);
      digitalWrite(LED,LOW);
      }
  }
  delay(30);
}


