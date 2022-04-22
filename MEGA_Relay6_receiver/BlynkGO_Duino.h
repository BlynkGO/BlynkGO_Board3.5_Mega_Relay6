#ifndef __BLYNKGO_MEGA_H__
#define __BLYNKGO_MEGA_H__

#include <Arduino.h>
#include "src/GTimerDuino.h"

namespace LOADCELL {  
  void init(); 
  void reset(); 
  void read();
}

namespace LCD      {  
  void clear_line(uint8_t line);
  void displayFormula();
  void displayTime();
  void displayGardBand();
  void displayLoadCell();
}






#endif // __BLYNKGO_MEGA_H__
