#include  "main.h"

//HELPER FUNCTIONS
void setIntake(int power){
  intakeLeft = power;
  intakeRight = power;
}

void setIndexer(int power){
  indexer = power;
}

void setLauncher(int power){
    launcher = power;
}

//DRIVER CONTROL FUNCTIONS
void setIntakeMotors(){
  //bottom trigger intakes, top trigger outtakes
  int intakePower = 127*(controller.get_digital(pros::E_CONTROLLER_DIGITAL_L1)-controller.get_digital(pros::E_CONTROLLER_DIGITAL_L2));
  setIntake(intakePower);
}

void shoot(){
  int voltage = 0;
  if(controller.get_digital(DIGITAL_R1))
    voltage = 127;
  else voltage = 0;
  setIndexer(voltage);
  setLauncher(voltage);
}

void cycleOut(){
  int voltage = 0;
  if(controller.get_digital(DIGITAL_R2))
    voltage = -127;
  else voltage = 0;
  setIndexer(voltage);
  setIntake(voltage);
}

void reverseLauncher(){
  if(controller.get_digital(DIGITAL_R2))
    setLauncher(-127);
  else setLauncher(0);
}
