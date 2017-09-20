/* Basic Arduino tutorial
 
 18-220 S13
 
 */

// Declare identifiers for pins for neater/readable code.
// These variables will not change.
const int LEDA = 8;     // digital pin LEDA is connected to
const int LEDB = 9;     // digital pin LEDB is connected to
const int buttonA = 10; // digital pin buttonA is connected to
const int buttonB = 11; // digital pin buttonB is connected to
const int buzzer = 5;   // PWM pin the buzzer is connected to

// analog pin we'll read potentiometer value from (A0)
// attach the center pin of the pot to pin A0, and the outside pins to +5V and ND
const int analogIn = 0; 

// Declare variables that will change
int buttonAState = 0;   // digital state of buttonA (will be 0 or 1)
int buttonBState = 0;   // digital state of buttonB (will be 0 or 1)
int potValue = 0;       // analog value of potentiometer (will be 0-1023)

// setup routine; runs each time the Arduino is reset
void setup() {
  // declare which pins are inputs, which are outputs
  pinMode(LEDA, OUTPUT);   // we'll be writing values to the LED, so it's an output
  pinMode(LEDB, OUTPUT);   // we'll be writing values to the LED, so it's an output
  pinMode(buttonA, INPUT); // we'll be reading values from the button, so it's an input
  pinMode(buttonB, INPUT); // we'll be reading values from the button, so it's an input
  pinMode(buzzer, OUTPUT); // we'll be writing a square wave to the buzzer, so it's an output
  pinMode(analogIn, INPUT);// we'll be reading values from the analog input, so declare it as such
  Serial.begin(9600);      // initialize serial communication at 9600 bits per second for analogRead
}

// loop routine; runs over and over until Arduino is reset or powered off
void loop() {

  /**********************************************************************
   * Lighting an LED
   ***********************************************************************/

  // Read state of buttonA
  // The digitalRead function will return 0 or 1 depending on whether a
  // low or high voltage is read on the buttonA pin
  buttonAState = digitalRead(buttonA);

  // if buttonA state is high, turn LEDA on; else, turn it off
  if(buttonAState == HIGH) { // HIGH is the voltage level for logic 1; it is a pre-defined constant
    digitalWrite(LEDA, HIGH); // turn the LED on by writing HIGH
  }
  else {
    digitalWrite(LEDA, LOW); // turn the LED off by writing LOW
  }

  // delay three seconds
  delay(3000); // units are in milliseconds

  // shut the LED off
  digitalWrite(LEDA, LOW);

  /**********************************************************************
   * Blinking an LED
   ***********************************************************************/
  // read state of buttonB
  buttonBState = digitalRead(buttonB);
  // If buttonB state is high, manually blink LEDB on/off with a delay of one second.
  // You could do this in other ways!
  if(buttonBState == HIGH) {
    digitalWrite(LEDB, HIGH);  // turn the LED on by writing a HIGH voltage to the LEDB pin
    delay(1000);               // delay one second
    
    digitalWrite(LEDB, LOW);   // turn the LED off by writing a LOW voltage to the LEDB pin
    delay(1000);               // delay one second
    
    digitalWrite(LEDB, HIGH);  // turn the LED on by writing a HIGH voltage to the LEDB pin
    delay(1000);               // delay one second
    
    digitalWrite(LEDB, LOW);   // turn the LED off by writing a LOW voltage to the LEDB pin
    delay(1000);               // delay one second
    
    digitalWrite(LEDB, HIGH);  // turn the LED on by writing a HIGH voltage to the LEDB pin
    delay(1000);               // delay one second
    
    digitalWrite(LEDB, LOW);   // turn the LED off by writing a LOW voltage to the LEDB pin
    delay(1000);               // delay one second
  }
  else {
    digitalWrite(LEDB, LOW); // write a LOW voltage to the LEDB pin 
  }

  delay(3000); // delay three seconds

  /**********************************************************************
   * Sending a tone to a buzzer
   ***********************************************************************/
  tone(buzzer,1000); // output a 5 kHz, 50% duty cycle square wave to the buzzer pin
  delay(3000);       // delay three seconds
  
  noTone(buzzer);    // shuts the tone off;
  delay(3000);       // delay three seconds

  /**********************************************************************
   * Reading an analog input and printing to the serial monitor
   ***********************************************************************/
  potValue = analogRead(analogIn);         // read the analog value on the proper pin
  Serial.println("Potentiometer value: "); // print string to serial monitor
  Serial.println(potValue);                // print the value to the serial monitor

}

