#include <AltSoftSerial.h>
AltSoftSerial BTserial; 

#define RELE_PIN 3
 
void setup() 
{
    Serial.begin(9600);
    Serial.print("Sketch:   ");   Serial.println(__FILE__);
    Serial.print("Uploaded: ");   Serial.println(__DATE__);
    Serial.println(" "); 
    BTserial.begin(9600);  
    Serial.println("BTserial started at 9600");        
    pinMode(RELE_PIN, OUTPUT);
}
void pushButton(){  
  Serial.println("push button");
  digitalWrite(RELE_PIN, HIGH);   //relé1 rozepnuto
  delay(1000);                     //1 s čekání
  digitalWrite(RELE_PIN, LOW);    //relé1 sepnuto
  delay(1000);  
}

bool static connected;
void loop()
{    
    BTserial.write("AT+DISC?");   
    delay(5000);
      
    if (BTserial.available())
    {
        String s = BTserial.readString();
        //Serial.println(s);    
        if(!connected && s.indexOf('001585149C09')>0) {
          connected = true;
          pushButton();
        }
        else if(connected && s.indexOf('001585149C09')<1) {
          connected = false;
          pushButton();
        }
    }
    delay(5000);
}
