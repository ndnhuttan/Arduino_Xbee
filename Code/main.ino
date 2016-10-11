#include <SoftwareSerial.h>
SoftwareSerial xb(2, 3); // RX, TX
#include "XBeePro.h"
XBeePro xBeeObject;

String myID = "40F1ED40";
//String myID = "40F1ED02";
String confirmChar = "O";
String data = "(Thu 23/9/16 0:20:42,123,27,82,29,1023,2,6,7,1)";

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);          //enable the hardware serial port
  xBeeObject.setupXbee();
}

void loop() {
  // put your main code here, to run repeatedly:
     xBeeObject.sendData(data);
     delay(2000);
  if(xBeeObject.checkAvailable())
   {
      String receiveData = xBeeObject.receiveData();
      Serial.println(receiveData);//for debugging
      delay(2000);
      if(receiveData == myID){
        xBeeObject.sendData(confirmChar);
        delay(1000);
        String commandValue = xBeeObject.receiveData();
        Serial.println(commandValue);//for debugging
        }
    }
}
