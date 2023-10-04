const int ledPin = 12; // Pin number for the LED

// Morse code definitions for each alphanumeric character
const String alphabet = "abcdefghijklmnopqrstuvwxyz0123456789";
const String morse[] = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", 
                         ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", 
                         "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--..", 
                         "-----", ".----", "..---", "...--", "....-", ".....", 
                         "-....", "--...", "---..", "----."};

void setup() {
  pinMode(ledPin, OUTPUT); // Initialize the LED pin as an output
  Serial.begin(9600);      // Initialize serial communication
}

void loop() {
  if (Serial.available() > 0) { // Check if data is available to read
    String input = Serial.readString(); // Read the input string from the serial port
    for (int i = 0; i < input.length(); i++) { // Loop through each character in the string
      if (input[i] == ' ') { // Check for space
        delay(700); // 7 unit delay for a space between words
      } 
      else {
        int index = alphabet.indexOf(input[i]); // Find the index of the character in the alphabet string
        if (index >= 0) {
          for (char c : morse[index]) { // Loop through each dot/dash in the Morse code
            digitalWrite(ledPin, HIGH); // Turn on the LED
            delay(c == '.' ? 100 : 300); // If it's a dot, delay 100ms; if it's a dash, delay 300ms
            digitalWrite(ledPin, LOW);   // Turn off the LED
            delay(100); // 1 unit delay between dots/dashes
          }
          delay(200); // 2 unit delay between letters
        }
      }
      String toprint = String(input[i]) + " = " + morse[alphabet.indexOf(input[i])];
      Serial.println(toprint);

    }
    delay(700); // 7 unit delay between words
  }
}
