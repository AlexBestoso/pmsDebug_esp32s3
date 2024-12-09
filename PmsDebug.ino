#include <Arduino.h>
#include <cstdint>
#include <src/PmsDebug.class.h>

PmsDebug pmsdebug;
void setup(void){
  Serial.begin(115200);
  
  pmsdebug.init();

}

void loop(void){
  delay(2000);
}