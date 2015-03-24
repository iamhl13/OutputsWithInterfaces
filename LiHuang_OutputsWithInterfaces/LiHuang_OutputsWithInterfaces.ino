//pin
int motorPin = 9;// a motor
int buttonPin = 2;//a button
int tempValue = 0;// temperature
int pressValue = 0;//pressure
int debounceDelay = 3;
int tempThreshold = 10;
int buttonState = 0;
void setup() {
  Serial.begin(9600);
  pinMode(9,OUTPUT);
  pinMode(2,INPUT);
}


void loop() {
  pressValue = analogRead(A0);
  
  tempValue = analogRead(A1);
  
  
  buttonState = digitalRead(buttonPin);
  //  Serial.println(pressValue);
  // Serial.println(lightValue); 
  Serial.println(buttonState);
  if(debounce(tempValue))
     
    {
      Serial.println(tempValue);
    
    if(tempValue > tempThreshold)//if the temp sensor feels my hand
      
      {analogWrite(motorPin,tempValue*20*buttonState);}//if the button was pressed, the tempValue can be used as the rotation speed of the motor
    
    else//use my figure to press the press sensor
      {analogWrite(motorPin,pressValue);}
    
    }
}

//decoune staff
boolean debounce(int pin){
  boolean state;
  boolean previousState;
  previousState=analogRead(pin);
  for(int counter = 0; counter < debounceDelay; counter++){
    delay(1);
    state = analogRead(pin);
    if(state != previousState){
      counter = 0;
      previousState = state;
  }
  return state;
}
}

