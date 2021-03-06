#include <SoftwareSerial.h>
SoftwareSerial BT(8,9);

void setup() {  
  Serial.begin(9600);
  BT.begin(9600);
  Serial.println("Program loaded");
}

void loop() {  
  //read from the BT and print to Serial
  if(BT.available())
    Serial.write(BT.read());
    
  //read from the Serial and print to the HM-10
  if(Serial.available())
    BT.write(Serial.read());  
}
