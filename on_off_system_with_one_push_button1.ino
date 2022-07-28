int npnPin = 6;    
int buttonPin = 7;   

int buttonState = HIGH;   
int npnState = LOW;       
int LBS = HIGH; 
long LCT = 0;  

void setup() {
  pinMode(buttonPin, INPUT);  
  pinMode(npnPin, OUTPUT);  
  digitalWrite(npnPin, npnState); 
  Serial.begin(9600);                
}

void loop() {
  int nowButtonState = digitalRead(buttonPin); 
  if (nowButtonState != LBS) {
    LCT = millis();
  }
  // If button state changes, and stays stable for a while, then it should have skipped the bounce area
  if (millis() - LCT > 10) {
    if (buttonState != nowButtonState) {  // Confirm button state has changed
      buttonState = nowButtonState;
      if (buttonState == LOW) {     // Low level indicates the button is pressed
        npnState = !npnState;           // Reverse relay state
        digitalWrite(npnPin, npnState); // Update relay state
        Serial.println("Button is Pressed!");
      }
      else {                        // High level indicates the button is released
        Serial.println("Button is Released!");
      }
    }
  }
  LBS = nowButtonState; // Save the state of last button
}
