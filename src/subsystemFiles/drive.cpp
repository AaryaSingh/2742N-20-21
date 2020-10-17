#include  "main.h"

pros::Imu InertialA(4);
pros::ADIEncoder encRight('E', 'F', false);
pros::ADIEncoder encLeft('G', 'H', false);

//HELPER FUNCTIONS
void setDrive(int left, int right){
  driveLeftBack = left;
  driveLeftFront = left;
  driveRightBack = right;
  driveRightFront = right;
}

void resetDriveEncoders(){
  driveLeftBack.tare_position();
  driveLeftFront.tare_position();
  driveRightBack.tare_position();
  driveRightFront.tare_position();
}

void resetQuadEncoders(){
  printf("Enter resetQuadEncoders\n");
  encRight.reset();
  pros::delay(100);
  encLeft.reset();
  printf("Exit resetQuadEncoders\n");
}

float avgQuadEncoderValue(){
  int rightVal = encRight.get_value();
  int leftVal = encLeft.get_value();
  printf("rb:%d lb:%d\n", rightVal, leftVal);
  float avg = (encLeft.get_value() + encRight.get_value())/2;
  return avg;
}

double avgDriveEncoderValue(){
  //printf("In avgDriveEncoderValue\n");
   double lb = fabs(driveLeftBack.get_position());
   double rb = fabs(driveRightBack.get_position());
  printf("lb:%f rb:%f\n", lb, rb);

  return (lb+rb)/2;

}

int get_quad(double angle){
  int ret = 1;
  if((angle>270) && (angle <=360)){
    ret = 4;
  }else if((angle>180) && (angle <=270)){
    ret = 3;
  }else if((angle>90) && (angle <=180)){
    ret = 2;
  }
  printf("In get_quad %d\n",ret);
  return ret;
}

//DRIVER CONTROL FUNCTIONS
void driverControl(){
  int leftJoystick = controller.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y);
  int rightJoystick = controller.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_Y);
  if(abs(leftJoystick) < 10){leftJoystick = 0;}
  if(abs(rightJoystick) < 10){rightJoystick = 0;}
  setDrive(leftJoystick, rightJoystick);
}

void constantDrive(){
  int voltage = 80;
  int val = (controller.get_digital(pros::E_CONTROLLER_DIGITAL_UP)-controller.get_digital(pros::E_CONTROLLER_DIGITAL_DOWN))*voltage;
  setDrive(val, val);
}

//AUTONOMOUS FUNCTIONS
void translate(int units, int voltage){
  printf("In translate %d %d\n",units, voltage);
  int direction = abs(units)/units;
  //reset motor encoders
  resetDriveEncoders();
  printf("reset encoders\n");
  //drive forward until units are reached
  float tickDistInch = avgDriveEncoderValue()*(12.57/900);
  while(tickDistInch < abs(units)){
    setDrive(voltage*direction, voltage*direction);
    pros::delay(5);
    tickDistInch = avgDriveEncoderValue()*(12.57/900);
  }
  //brief set_brake_mode
  setDrive(-10 * direction, -10 * direction);
  pros::delay(50);
  //set drive back to neutral
  setDrive(0,0);
}

void translate2(int units, int voltage, bool correction){
  double initHeading = InertialA.get_heading();
  printf("In translate2 %d %d\n",units, voltage);
  int direction = abs(units)/units;
  //reset encoders
  resetQuadEncoders();
  printf("reset encoders\n");
  //drive forward until units are reached
  float tickDistInch = avgQuadEncoderValue()*(9.3/360);
  printf("set tickdistinch\n");
  while(fabs(tickDistInch) < abs(units)){
    printf("avg val %f\n", tickDistInch);
    setDrive(voltage*direction, voltage*direction);
    pros::delay(10);
    tickDistInch = avgQuadEncoderValue()*(9.3/360);
  }
  printf("exit while\n");
  //brief set_brake_mode
  setDrive(-10 * direction, -10 * direction);
  pros::delay(50);
  //set drive back to neutral
  setDrive(0,0);

  if(correction){
    double newHeading = InertialA.get_heading();
    int init_quad = get_quad(initHeading);
    int final_quad = get_quad(newHeading);

    if(init_quad==1 && final_quad==4){
      direction = 1; //clockwise;
    }else if(init_quad==4 && final_quad==1){
      direction = -1; //counter;
    }else{
      direction = (initHeading - newHeading)/fabs(initHeading - newHeading);
    }
    printf("Correction direction %d\n",direction);

    double botAngle = InertialA.get_heading();
    while((botAngle<initHeading-1) || (botAngle>initHeading+1)){
      setDrive(30*direction, -30*direction);
      botAngle = InertialA.get_heading();
      pros::delay(10);
    }
    setDrive(0,0);
  }
}

void initializeIMU(){
  InertialA.reset();

  int time = pros::millis();
  int iter = 0;
  while (InertialA.is_calibrating()) {
    printf("IMU calibrating... %d\n", iter);
    iter += 10;
    pros::delay(10);
  }
  // should print about 2000 ms
  printf("IMU is done calibrating (took %d ms)\n", iter - time);
  pros::delay(2500);
}

void rotate(int degrees, int voltage){
  //define out direction , based on the units provided
  int direction = abs(degrees)/degrees;
  double botAngle = InertialA.get_heading();

  //turn until units are reached video tutorial 4,

  setDrive(voltage * direction, -voltage * direction);
  //while(!((fabs(botAngle)>abs(degrees)-0.2) && (fabs(botAngle)<abs(degrees)+0.2))){
 while((fabs(botAngle)<abs(degrees)-1) || (fabs(botAngle)>abs(degrees)+1)){
    pros::delay(10);
    botAngle = InertialA.get_heading();
    printf("while1 %f\n", botAngle);

  }
  pros::delay(100);
  //check if it overshot
/*  botAngle = InertialA.get_heading();
  if(fabs(botAngle) > abs(degrees)){
    setDrive(-0.5*voltage*direction, 0.5 * voltage * direction);
    while(fabs(botAngle) > abs(degrees)){
      pros::delay(10);
      botAngle = InertialA.get_heading();
      printf("while2 %f\n", botAngle);
    }
  }else if(fabs(botAngle) < abs(degrees )){
    setDrive(0.5*-voltage*direction, 0.5 * voltage * direction);
    while(fabs(gyro.get_value()) > abs(degrees * 10)){
       pros::delay(10);
    }
  }*/
  double newHeading = InertialA.get_heading();
  int init_quad = get_quad(abs(degrees));
  int final_quad = get_quad(newHeading);

  if(init_quad==1 && final_quad==4){
    direction = 1; //clockwise
  }else if(init_quad==4 && final_quad==1){
    direction = -1; //counter
  }else{
    direction = (abs(degrees) - newHeading)/fabs(abs(degrees) - newHeading);
  }

  double correctAngle = InertialA.get_heading();
  while((correctAngle<abs(degrees)-1) || (correctAngle>abs(degrees)+1)){
     setDrive(30*direction, -30*direction);
     pros::delay(10);
     correctAngle = InertialA.get_heading();
   }

  //reset drive to zero
  setDrive(0,0);
}
