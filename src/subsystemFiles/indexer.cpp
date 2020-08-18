#include  "main.h"

pros::ADIPotentiometer anglerPot('A');
//HELPER FUNCTIONS
void setIndexer(int power){
  indexer = power;
}

//DRIVER CONTROL FUNCTIONS
void setIndexerMotor(){
  //bottom trigger intakes, top trigger outtakes
  int anglerPower = 127*(controller.get_digital(pros::E_CONTROLLER_DIGITAL_UP)-controller.get_digital(pros::E_CONTROLLER_DIGITAL_DOWN));
  setIndexer(anglerPower);
}
