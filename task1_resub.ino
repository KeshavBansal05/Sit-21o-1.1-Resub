// Define pin connections and Morse code settings
const int ledPin = LED_BUILTIN; // Built-in LED pin
const int buttonPin = 2;        // Button connected to D2
bool buttonPressed = false;     // Flag to toggle Morse code blinking

// Morse code timing parameters (in milliseconds)
const int dotDuration = 250;    // Duration of a dot blink
const int dashDuration = 750;   // Duration of a dash blink
const int letterGap = 1000;     // Delay between letters
const int partGap = 250;        // Delay between parts of a letter

void setup() {
  pinMode(ledPin, OUTPUT);      // Set the LED pin as an output
  pinMode(buttonPin, INPUT_PULLUP); // Set the button pin as input with internal pull-up
}

void loop() {
  // Check if the button is pressed
  if (digitalRead(buttonPin) == LOW) { // Button pressed (LOW state due to pull-up)
    buttonPressed = !buttonPressed; // Toggle Morse code blinking on/off
    delay(500); // Debounce delay to avoid repeated toggling
  }
  
  // If Morse code blinking is enabled, call the function to blink code
  if (buttonPressed) {
    blinkMorseCode();
  }
}

// Function to blink the word "KESHAV" in Morse code
void blinkMorseCode() {
  // Blink "K" (-.-)
  dash(); dot(); dash();
  delay(letterGap);

  // Blink "E" (.)
  dot();
  delay(letterGap);

  // Blink "S" (...)
  dot(); dot(); dot();
  delay(letterGap);

  // Blink "H" (....)
  dot(); dot(); dot(); dot();
  delay(letterGap);

  // Blink "A" (.-)
  dot(); dash();
  delay(letterGap);

  // Blink "V" (...-)
  dot(); dot(); dot(); dash();
  delay(letterGap);
}

// Function to blink a dot in Morse code
void dot() {
  digitalWrite(ledPin, HIGH); // Turn on LED
  delay(dotDuration);         // Wait for dot duration
  digitalWrite(ledPin, LOW);  // Turn off LED
  delay(partGap);             // Wait between parts of the letter
}

// Function to blink a dash in Morse code
void dash() {
  digitalWrite(ledPin, HIGH); // Turn on LED
  delay(dashDuration);        // Wait for dash duration
  digitalWrite(ledPin, LOW);  // Turn off LED
  delay(partGap);             // Wait between parts of the letter
}
