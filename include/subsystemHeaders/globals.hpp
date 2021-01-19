#include  "main.h"

//MOTORS
extern pros::Motor launcher;
extern pros::Motor indexer;
extern pros::Motor intakeLeft;
extern pros::Motor intakeRight;
extern pros::Motor driveLeftBack;
extern pros::Motor driveLeftFront;
extern pros::Motor driveRightBack;
extern pros::Motor driveRightFront;

//CONTROLLER
extern pros::Controller controller;

//MISCELLANEOUS
#define ANGULAR
//when your gyro turns left it gives
//positive value and when it turns right it give negative value
extern pros::Imu InertialA;
extern pros::ADIEncoder encForward;
extern pros::ADIEncoder encStrafe;
