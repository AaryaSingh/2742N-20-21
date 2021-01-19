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

int volt = 100;
//DRIVER CONTROL FUNCTIONS
void setIntakeMotors(){
  //bottom trigger intakes, top trigger outtakes\

  if(controller.get_digital(pros::E_CONTROLLER_DIGITAL_L1)&&controller.get_digital(pros::E_CONTROLLER_DIGITAL_R1)){
    setLauncher(volt);
    setIndexer(volt);
    setIntake(volt);
  } else if(controller.get_digital(pros::E_CONTROLLER_DIGITAL_L1)&&controller.get_digital(pros::E_CONTROLLER_DIGITAL_L2)){
    int voltage = 127;
    setIndexer(volt);
    setIntake(volt);
  } else if(controller.get_digital(DIGITAL_R1)){
    setIndexer(volt);
    setLauncher(volt);
    pros::delay(10);
  } else if(controller.get_digital(DIGITAL_R2)){
    setIndexer(-volt);
    setIntake(-volt);
  } else if(controller.get_digital(pros::E_CONTROLLER_DIGITAL_Y)){
    setLauncher(-volt);
  } else if(controller.get_digital(pros::E_CONTROLLER_DIGITAL_L1)||controller.get_digital(pros::E_CONTROLLER_DIGITAL_L2)){
    int intakePower = volt*(controller.get_digital(pros::E_CONTROLLER_DIGITAL_L1)-controller.get_digital(pros::E_CONTROLLER_DIGITAL_L2));
    setIntake(intakePower);
    pros::delay(10);
  } else {
    setLauncher(0);
    setIndexer(0);
    setIntake(0);
  }


}

void shoot(){
  // if(controller.get_digital(DIGITAL_R1)){
  //   int voltage = 127*(controller.get_digital(DIGITAL_R1));
  //   setIndexer(voltage);
  //   setLauncher(voltage);
  //   pros::delay(10);
  // }
}

void cycleOut(){
  // if(controller.get_digital(DIGITAL_R2)){
  //   int voltage = -127*(controller.get_digital(DIGITAL_R2));
  //   setIndexer(voltage);
  //   setIntake(voltage);
  // }
}

// void reverseLauncher(){
//   if(controller.get_digital(DIGITAL_R2))
//     setLauncher(-127);
//   else setLauncher(0);
//     pros::delay(10);
// }
