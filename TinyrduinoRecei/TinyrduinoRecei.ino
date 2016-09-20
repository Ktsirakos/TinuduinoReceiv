#include "RHReliableDatagram.h"
#include "RHHardwareSPI.h"
#include "RHGenericDriver.h"
#include "RHDatagram.h"
#include "RHSPIDriver.h"
#include "RadioHead.h"
#include "RH_RF22.h"
#include "RHGenericSPI.h"

#define SERVER_ADDRESS 2

RH_RF22 driver(7,3);
RHReliableDatagram manager(driver , SERVER_ADDRESS);

uint8_t buf[RH_RF22_MAX_MESSAGE_LEN];

void setup() {
  Serial.begin(9600);
  
  if(!manager.init()){
    Serial.println("init failed");
  }
}

void loop() {
  while(manager.available()){
    
  uint8_t len = sizeof(buf);
  uint8_t from;
  
  if(manager.recvfromAck(buf, &len)){
    char* textMessage[] = {(char*)buf};
    String Text = (String)textMessage[0];
    Serial.println(Text);
    }
  }
}
