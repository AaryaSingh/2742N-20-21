#include  "main.h"

//MOTORS
pros::Motor launcher(12, pros::E_MOTOR_GEARSET_06, true,pros::E_MOTOR_ENCODER_COUNTS);
pros::Motor indexer(13, pros::E_MOTOR_GEARSET_06, false,pros::E_MOTOR_ENCODER_COUNTS);
pros::Motor intakeLeft(9, pros::E_MOTOR_GEARSET_06, false,pros::E_MOTOR_ENCODER_COUNTS);
pros::Motor intakeRight(14, pros::E_MOTOR_GEARSET_06, true,pros::E_MOTOR_ENCODER_COUNTS);
pros::Motor driveLeftBack(10, pros::E_MOTOR_GEARSET_18, false,pros::E_MOTOR_ENCODER_COUNTS);
pros::Motor driveLeftFront(20, pros::E_MOTOR_GEARSET_18, false,pros::E_MOTOR_ENCODER_COUNTS);
pros::Motor driveRightBack(3, pros::E_MOTOR_GEARSET_18, true,pros::E_MOTOR_ENCODER_COUNTS);
pros::Motor driveRightFront(11, pros::E_MOTOR_GEARSET_18, true,pros::E_MOTOR_ENCODER_COUNTS);

//CONTROLLER
pros::Controller controller(pros::E_CONTROLLER_MASTER);
