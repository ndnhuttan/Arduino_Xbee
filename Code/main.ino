#include <SoftwareSerial.h>
SoftwareSerial xb(2, 3); // RX, TX
#include "XBeePro.h"
XBeePro xBeeObject;

//String myID = "40F1ED40";
String myID = "40F1ED40";
String confirmChar = "OOOOOOOOO";
String data = "(09:15:30,123,100,100,100,100,120)";
unsigned long time = 0;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);          //enable the hardware serial port
  xBeeObject.setupXbee();
  pinMode(8, OUTPUT);
}

void loop() {
   String commandValue = "";
  if((unsigned long)(millis() - time) > 10000){

       
  // put your main code here, to run repeatedly:
     xBeeObject.sendData(data);
   Serial.println(data);
   time = millis();
      
    }
  if(xBeeObject.checkAvailable())
   {
      String receiveData = "";
      receiveData = xBeeObject.receiveData();
      Serial.println(receiveData);
      
      if(receiveData == myID){
        commandValue = xBeeObject.receiveData();
//        if(commandValue == "000:1")
//          {
//            digitalWrite(8, HIGH);
//          }
//        else if(commandValue == "000:0")
//          {
//            digitalWrite(8, LOW);
//          }
        xBeeObject.sendData(confirmChar);
        Serial.println(commandValue + "------");
        }
    }
    
  
}

