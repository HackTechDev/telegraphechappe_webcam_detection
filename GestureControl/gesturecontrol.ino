#include <Servo.h>

Servo regulatorServo; 
Servo indicatorLeftServo;
Servo indicatorRightServo;

int regulatorPos = 0;
int indicatorLeftPos = 0;
int indicatorRightPos = 0;

int regulatorDelta = -3;
int indicatorLeftDelta = 5; 
int indicatorRightDelta = -13;


void setup() {
  // Regulator
  regulatorServo.attach(5);  
  indicatorLeftServo.attach(6);
  indicatorRightServo.attach(7);


  //calibration();

  allSigns();
}

void loop() {

}


/*
 * All signs
 */

void allSigns() {

  // Sign #1 or Initial position
  regulatorHorizontal();
  indicatorLeftVertical();
  indicatorRightVertical();

  // Sign #2
  delay(5000);
  indicatorLeft90to180();

  // Sign #3
  delay(5000);
  indicatorLeft180to270();

  // Initial position
  delay(5000);
  indicatorLeft270to180() ;
  indicatorLeft180to90() ;

  // Sign #4
  delay(5000);
  indicatorRight90to0();

  // Sign #5
  delay(5000);
  indicatorRight0to270();
  delay(5000);

  // Initial position  
  indicatorRight270to0();
  indicatorRight0to90();

  // Sign #6
  delay(5000);
  indicatorLeft90to180();
  indicatorRight90to0();

  // Sign #7
  delay(5000);
  indicatorLeft180to270();
  indicatorRight0to270();

  // Initial position  
  delay(5000);
  indicatorLeft270to180();
  indicatorLeft180to90();
  indicatorRight270to0();
  indicatorRight0to90();

  // Sign #8
  delay(5000);
  regulator0To45();

  // Sign 9
  delay(5000);
  indicatorLeft90to180();

  // Sign #10
  delay(5000);
  indicatorRight90to0();

  // Sign #11
  delay(5000);
  indicatorRight0to270();

  delay(5000);

  // Initial position  
  indicatorRight270to0();
  indicatorRight0to90();
  indicatorLeft180to90();
  regulator45To0();

  // Sign #12
  delay(5000);
  regulator0To315();
  
  // Sign #13
  delay(5000);
  indicatorRight90to0();

  // Sign #14
  delay(5000);
  indicatorLeft90to180();

  // Sign #15
  delay(5000);
  indicatorLeft180to270();


  // Initial position  
  delay(5000);
  regulator315To0();
  indicatorLeft270to180();
  indicatorLeft180to90();
  indicatorRight0to90();  
}


/*
 * Calibrage Regulator, indicatorLeft, indicatorRight
 */

void calibration() {
 
  regulatorHorizontal();
  delay(5000);
  regulator0To315();
  delay(5000);
  regulator315To0();
  delay(5000);
  regulator0To45();
  delay(5000);
  regulator45To0();

  indicatorLeftVertical();
  delay(5000);
  indicatorLeft90to180();
  delay(5000);
  indicatorLeft180to270();
  delay(5000);
  indicatorLeft270to180() ;
  delay(5000);
  indicatorLeft180to90() ;
  
  indicatorRightVertical();
  delay(5000);
  indicatorRight90to0();
  delay(5000);
  indicatorRight0to270();
  delay(5000);
  indicatorRight270to0();
  delay(5000);
  indicatorRight0to90();
}


/*
 * Regulator 
 * 
 */
 
void regulatorHorizontal(){
   regulatorServo.write(90+regulatorDelta);
}

void regulator0To315() {
for (regulatorPos = 90+regulatorDelta; regulatorPos >= 45; regulatorPos -= 1) { 
    
    regulatorServo.write(regulatorPos);             
    delay(15);                       
  }
  
}

void regulator315To0() {
    for (regulatorPos = 45; regulatorPos <= 90+regulatorDelta; regulatorPos += 1) { 
    
    regulatorServo.write(regulatorPos);             
    delay(15);                       
  }
}

void regulator0To45() {
   for (regulatorPos = 90+regulatorDelta; regulatorPos <= 135; regulatorPos += 1) { 
    
    regulatorServo.write(regulatorPos);             
    delay(15);                       
  }

}

void regulator45To0() {
     for (regulatorPos = 135; regulatorPos >= 90+regulatorDelta; regulatorPos -= 1) { 
    
    regulatorServo.write(regulatorPos);             
    delay(15);                       
  }

}


/*
 * Indicator Left
 */
 
void indicatorLeftVertical() {
  indicatorLeftServo.write(0+indicatorLeftDelta);
}

void indicatorLeft90to180() {
    for (indicatorLeftPos = 0; indicatorLeftPos <= 90; indicatorLeftPos += 1) { 
    
    indicatorLeftServo.write(indicatorLeftPos);             
    delay(15);                       
  }
}

void indicatorLeft180to270() {
      for (indicatorLeftPos = 90; indicatorLeftPos <= 180-indicatorLeftDelta; indicatorLeftPos += 1) { 
    
    indicatorLeftServo.write(indicatorLeftPos);             
    delay(15);                       
  }
}

void indicatorLeft270to180() {

    for (indicatorLeftPos = 180; indicatorLeftPos >= 90; indicatorLeftPos -= 1) { 
    
    indicatorLeftServo.write(indicatorLeftPos);             
    delay(15);                       
  }
}

void indicatorLeft180to90() {

    for (indicatorLeftPos = 90; indicatorLeftPos >= 0+indicatorLeftDelta; indicatorLeftPos -= 1) { 
    
    indicatorLeftServo.write(indicatorLeftPos);             
    delay(15);                       
  }
}


/*
 * Indicator Right
 */
 
void indicatorRightVertical() {
  indicatorRightServo.write(180+indicatorRightDelta);
}

void indicatorRight90to0() {
    for (indicatorRightPos = 180+indicatorRightDelta; indicatorRightPos >=90+indicatorRightDelta+5; indicatorRightPos -= 1) { 
    
    indicatorRightServo.write(indicatorRightPos);             
    delay(15);                       
  }
}

void indicatorRight0to270() {
      for (indicatorRightPos = 90+indicatorRightDelta+5; indicatorRightPos >= 0; indicatorRightPos -= 1) { 
    
    indicatorRightServo.write(indicatorRightPos);             
    delay(15);                       
  }
}

void indicatorRight270to0() {

    for (indicatorRightPos = 0; indicatorRightPos <= 90+indicatorRightDelta+5; indicatorRightPos += 1) { 
    
    indicatorRightServo.write(indicatorRightPos);             
    delay(15);                       
  }
}

void indicatorRight0to90() {

    for (indicatorRightPos = 90+indicatorRightDelta+5; indicatorRightPos <= 180+indicatorRightDelta; indicatorRightPos += 1) { 
    
    indicatorRightServo.write(indicatorRightPos);             
    delay(15);                       
  }
}
