#include <SoftwareSerial.h>
SoftwareSerial BT(7,8);

void setup() {  
  Serial.begin(9600);
  BT.begin(9600);
  Serial.println("Program loaded");
}

void loop() {  
  if(BT.available())
    Serial.write(BT.read());
    
  //read from the Serial and print to the HM-10
  if(Serial.available())
    BT.write(Serial.read());
  
}
