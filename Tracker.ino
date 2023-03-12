int bluePin = 0;    //IN1 on the ULN2003 Board, BLUE end of the Blue/Yellow motor coil
int pinkPin = 1;    //IN2 on the ULN2003 Board, PINK end of the Pink/Orange motor coil
int yellowPin = 3;  //IN3 on the ULN2003 Board, YELLOW end of the Blue/Yellow motor coil
int orangePin = 4;  //IN4 on the ULN2003 Board, ORANGE end of the Pink/Orange motor coil
//going up
//Keeps track of the current step.
//We'll use a zero based index. 
int currentStep = 0;
word aread;

void onestep() {
  switch(currentStep){
    case 0:
      digitalWrite(bluePin, HIGH);
      digitalWrite(pinkPin, HIGH);
      digitalWrite(yellowPin, LOW);
      digitalWrite(orangePin, LOW);

      break;
    case 1:
      digitalWrite(bluePin, LOW);
      digitalWrite(pinkPin, HIGH);
      digitalWrite(yellowPin, HIGH);
      digitalWrite(orangePin, LOW);

      break;
    case 2:
      digitalWrite(bluePin, LOW);
      digitalWrite(pinkPin, LOW);
      digitalWrite(yellowPin, HIGH);
      digitalWrite(orangePin, HIGH);
      break;
    case 3:

      digitalWrite(bluePin, HIGH);
      digitalWrite(pinkPin, LOW);
      digitalWrite(yellowPin, LOW);
      digitalWrite(orangePin, HIGH);
      break;
  }
}

void setup() {
  
  pinMode(bluePin, OUTPUT);
  pinMode(pinkPin, OUTPUT);
  pinMode(yellowPin, OUTPUT);
  pinMode(orangePin,OUTPUT);
  
  digitalWrite(bluePin, LOW);
  digitalWrite(pinkPin, LOW);
  digitalWrite(yellowPin, LOW);
  digitalWrite(orangePin, LOW);
}

void loop() {
  
  if (analogRead(A1)<400) {
  //CCW
  currentStep = (--currentStep >= 0) ? currentStep : 3;
  onestep();
  }
  else {
    if (analogRead(A1)>600){
    //CW
    currentStep = (++currentStep < 4) ? currentStep : 0;
    onestep();
    }
  else {
  digitalWrite(bluePin, LOW);
  digitalWrite(pinkPin, LOW);
  digitalWrite(yellowPin, LOW);
  digitalWrite(orangePin, LOW);
    }
  }

    //2000 microseconds, or 2 milliseconds seems to be 
  //about the shortest delay that is usable.  Anything
  //lower and the motor starts to freeze. 
  delay(15);
}
