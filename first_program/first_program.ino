void setup() {

  // 13 is the PIN that the LED light is identified as

  // set LED pin to output - turned the LED off
  pinMode(13, OUTPUT); 

  // input perma turns the LED on
  // pinMode(13, INPUT); 

}

void loop() {
  // turned the LED on
  digitalWrite(13, HIGH);
  delay(1000);
  // turned the LED off
  digitalWrite(13, LOW);
  delay(1000);


  digitalWrite(13, HIGH);
  delay(250);
  digitalWrite(13, LOW);
  delay(250);

  digitalWrite(13, HIGH);
  delay(250);
  digitalWrite(13, LOW);
  delay(1000);


}
