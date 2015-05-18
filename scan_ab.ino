int serIn = 0;

int scanDir = 2;
int scanStep = 3;
int scanSwitch = 5;

int tableStep = 12;
int tableDir = 8;
int tableSwitch = 4;


void setup(){                
  Serial.begin(9600);
  pinMode(scanStep, OUTPUT);
  pinMode(scanDir, OUTPUT);
  pinMode(scanSwitch, OUTPUT);
  pinMode(tableStep, OUTPUT);
  pinMode(tableDir, OUTPUT);
  pinMode(tableSwitch, OUTPUT); 
}

void loop() {
  digitalWrite(scanStep, HIGH);
  digitalWrite(tableStep, HIGH);
  delayMicroseconds(20);
  digitalWrite(scanStep, LOW);
  digitalWrite(tableStep, LOW);
  delayMicroseconds(2 0); 
  
  if(Serial.available()>0){
    serIn = Serial.read()-'0';
    // table direction
    digitalWrite(tableDir, HIGH);
    
    if(serIn == 0){
      digitalWrite(scanSwitch, LOW);
    }
    else if(serIn == 1){
      digitalWrite(scanSwitch, HIGH);
      digitalWrite(scanDir, HIGH);
    }
    else if(serIn == 2){
      digitalWrite(scanSwitch, HIGH);
      digitalWrite(scanDir, LOW);    
    }
    else if(serIn == 3){
      digitalWrite(tableSwitch, HIGH);
    }
    else if(serIn == 4){
      digitalWrite(tableSwitch, LOW);
    }
  }
}

