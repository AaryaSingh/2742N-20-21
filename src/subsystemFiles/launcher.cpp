#include  "main.h"
//HELPER FUNCTIONS
void setLauncher(int power){
  launcher = power;
}

//DRIVER CONTROL FUNCTIONS
void setLauncherMotors(){
  //bottom trigger intakes, top trigger outtakes
  int intakePower = 127*(controller.get_digital(pros::E_CONTROLLER_DIGITAL_R1)-controller.get_digital(pros::E_CONTROLLER_DIGITAL_R1));
  setLauncher(intakePower);
}
