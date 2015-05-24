//serial input from python script
int serIn = 0;
//scanner motor variables
int scanEnable = 10;
int scanPulPin = 9;
int scanDirPin = 8;
//table motor variables
int tableEnable = 7;
int tablePulPin = 6;
int tableDirPin = 5;
//pwm enable variables
int scanOn = 0;
int tableOn = 0;

void setup(){ 
//  initialize serial input 
  Serial.begin(9600);
//  initialize scanner motor pins
  pinMode(scanEnable, OUTPUT);  
  pinMode(scanPulPin, OUTPUT);
  pinMode(scanDirPin, OUTPUT);
  digitalWrite(scanEnable, HIGH);
  digitalWrite(scanPulPin, LOW);
  digitalWrite(scanDirPin, HIGH);
//  initialize table motor pins
  pinMode(tableEnable, OUTPUT);  
  pinMode(tablePulPin, OUTPUT);
  pinMode(tableDirPin, OUTPUT);
  digitalWrite(tableEnable, HIGH);
  digitalWrite(tablePulPin, LOW);
  digitalWrite(tableDirPin, HIGH);
}

void loop() {
    serIn = Serial.read()-'0';
    if(serIn == 0){
      scanOn = 0;
      digitalWrite(scanEnable, LOW);
    }else if(serIn == 1){
      scanOn = 1;
      digitalWrite(scanEnable, HIGH);
      digitalWrite(scanDirPin, HIGH);
    }else if(serIn == 2){
      scanOn = 1;
      digitalWrite(scanEnable, HIGH);
      digitalWrite(scanDirPin, LOW);
    }else if(serIn == 3){
      tableOn = 1;
      digitalWrite(tableEnable, HIGH);

    }else if(serIn == 4){
      tableOn = 0;
      digitalWrite(tableEnable, LOW);
    }   
//  enable pwm
    if(scanOn == 1){
      digitalWrite(scanPulPin, HIGH);
      delayMicroseconds(10);
      digitalWrite(scanPulPin, LOW);
      delayMicroseconds(10);
    }else if(tableOn == 1){
      digitalWrite(tablePulPin, HIGH);
      delayMicroseconds(10);
      digitalWrite(tablePulPin, LOW);
      delayMicroseconds(10);    
    }
}
