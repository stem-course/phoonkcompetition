/*
  Code by: www.munphurid.com
  M.Hashir

  This is a code for phoonk competition
  When you are ready press the button, and rotate the fan
  Arduino takes all the readings during 5 seconds duration

  Hardware:
  - Arduino
  - DC motor
  - Push Button

  Connections:
  Connect one leg of DC motor to GND of Arduino
  Connect other leg of DC motor to pin 11 of Arduino
  Connect one leg of push button to GND
  Connect other leg of push button to pin 13
*/


int button = 12;
int motor = A0;
int input = 0;
int maximum = 0;
void setup() {
  Serial.begin(9600);
  pinMode(button, INPUT_PULLUP);
  pinMode(motor, INPUT);

}
long previousmillis;

void loop() {
  previousmillis = millis();
  if (digitalRead(button) == LOW) {
    long currentmillis = millis();
    while (currentmillis < previousmillis + 1000) {
      input = analogRead(A0);
      if (input > maximum) {
        maximum = input;
      }
      currentmillis = millis();

    }
    Serial.print("Your reading is = ");
    Serial.println(maximum);
  }
}
