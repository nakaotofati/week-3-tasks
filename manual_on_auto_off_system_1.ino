
int npnPin = 6;
int buttonPin = 7;

int buttonState = HIGH;
int npnState = LOW;
int LBS = HIGH;
long LCT = 0 ;
void setup() 
{
   pinMode(buttonPin,INPUT);    // Relay Signal Pin
   pinMode(npnPin,OUTPUT);     // buzzer & LED  (start with buzzer on)
   digitalWrite(npnPin,npnState);
   Serial.begin(9600);



     // shutdown the circuit
   
}

void loop() 
{
int nowButtonState = digitalRead(buttonPin);
  if(buttonState != LBS){
    LCT = millis();
  }
  if(millis() - LCT > 10){
    if(buttonState != nowButtonState){
      buttonState = nowButtonState;
      if(buttonState == LOW){
        npnState = !npnState;
        digitalWrite(npnPin,npnState);
        Serial.println("the BUtton is PRESSED!");
      }
      else{
        digitalWrite(npnPin,HIGH);
        delay(2000);
        for(int i=0;i<3;i++){
          digitalWrite(npnPin,HIGH);
          delay(80);
          digitalWrite(npnPin,LOW);
          delay(600);}
        digitalWrite(npnPin,HIGH);
        delay(1000);
        digitalWrite(npnPin,LOW);
        Serial.println("the Button is RELEASED!");
      }
    }
  }
  LBS= nowButtonState; 
}

