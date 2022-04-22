#include "BlynkGO_Duino.h"

#define RELAY_ON     LOW                  // Relay แบบ ACTIVE LOW
#define RELAY_OFF    HIGH 

GTimerDuino Serial2_RX;

uint8_t relay_pin[] = { 3,4,5,6,7,8 };    // กำหนดค่า pin ให้ relay

void setup() {
  Serial.begin(115200); Serial.println();
  Serial2.begin(9600);
  for(int i=0; i < 6; i++){
    pinMode(relay_pin[i], OUTPUT);
    digitalWrite( relay_pin[i], RELAY_OFF);
  }

  Serial2_RX.setInterval(100,[](){
    String esp32_cmd = Serial2.readStringUntil('\n');
    if(!esp32_cmd.startsWith("SW")) return;
    uint8_t cmd    =  esp32_cmd.substring(2).toInt();
    uint8_t pin_id =  cmd/10;
    bool    state  =  cmd%10? RELAY_ON : RELAY_OFF;
    if(pin_id < 6 ) digitalWrite(relay_pin[ pin_id ],  state);
  });
}

void loop() {
  Serial2_RX.run();
}
