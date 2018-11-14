#include <SoftwareSerial.h>
SoftwareSerial BT(7,8);
int RELE_GATE = 13;

void setup() {  
  Serial.begin(9600);
  BT.begin(9600);
  pinMode(RELE_GATE, OUTPUT);
  Serial.println("Program loaded");
}

void loop() {  
  /*if(BT.available())
    Serial.write(BT.read());
    
  //read from the Serial and print to the HM-10
  if(Serial.available())
    BT.write(Serial.read());
  */
  if(BT.available()>0){
    char s = BT.read();
    if(s=='1'){
      Serial.println("Sending signal");
      digitalWrite(RELE_GATE, HIGH); 
      delay(500);
      digitalWrite(RELE_GATE, LOW); 
    }
  }
}
