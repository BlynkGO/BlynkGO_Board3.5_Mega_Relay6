#include <BlynkGOv2.h>

GContainer cont_sw3d;
  GSwitch3D sw3d[6];
  color_t   sw3d_color[6] = { TFT_RED, TFT_GREEN, TFT_BLUE, TFT_VIOLET, TFT_YELLOW, TFT_ORANGE};
  uint8_t   sw3d_state;

void setup() {
  Serial.begin(115200); Serial.println();
  BlynkGO.begin();
  Serial2.begin(9600, SERIAL_8N1, 22,25);

  cont_sw3d.opa(0);
  cont_sw3d.layout(LAYOUT_ROW_M);
  cont_sw3d.padding(0,0,0,0,2);

  bitWrite(sw3d_state,7,1);
  for(int i=0; i< 6; i++){
    sw3d[i].size(75,130);
    sw3d[i].color(sw3d_color[i]);
    sw3d[i].parent(cont_sw3d);
    sw3d[i].onValueChanged([](GWidget*widget){
      uint8_t i= (GSwitch3D*)widget-&sw3d[0];
      bitWrite(sw3d_state, i, (sw3d[i].isON()? 1 : 0) );
      Serial2.println( sw3d_state);
    });
  }
}

void loop() {
  BlynkGO.update();
}
