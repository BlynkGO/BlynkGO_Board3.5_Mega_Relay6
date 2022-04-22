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
    uint8_t sw3d_state = Serial2.readStringUntil('\n').toInt();
    if(sw3d_state == 0) return;
    for(int i=0; i< 6; i++){
      digitalWrite( relay_pin[i], bitRead(sw3d_state, i) ? RELAY_ON : RELAY_OFF);
    }
  });
}

void loop() {
  Serial2_RX.run();
}
