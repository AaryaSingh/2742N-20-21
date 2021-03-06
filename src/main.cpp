#include "main.h"

/**
 * A callback function for LLEMU's center button.
 *
 * When this callback is fired, it will toggle line 2 of the LCD text between
 * "I was pressed!" and nothing.
 */
void on_center_button() {
	static bool pressed = false;
	pressed = !pressed;
	if (pressed) {
		pros::lcd::set_text(2, "I was pressed!");
	} else {
		pros::lcd::clear_line(2);
	}
}

/**T
 * Runs initialization code. This occurs as soon as the program is started.
 *
 * All other competition modes are blocked by initialize; it is recommended
 * to keep execution time for this mode under a few seconds.
 */
void initialize() {
	pros::lcd::initialize();
	pros::lcd::set_text(1, "Hello PROS 2742N Team!");//line number, text
	//pros::lcd::register_btn1_cb(on_center_button);

  driveLeftBack.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
  driveLeftFront.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
  driveRightBack.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
  driveRightFront.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
	launcher.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
	indexer.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
	intakeLeft.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
	intakeRight.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
}

/**
 * Runs while the robot is in the disabled state of Field Management System or
 * the VEX Competition Switch, following either autonomous or opcontrol. When
 * the robot is enabled, this task will exit.
 */
void disabled() {}

/**
 * Runs after initialize(), and before autonomous when connected to the Field
 * Management System or the VEX Competition Switch. This is intended for
 * competition-specific initialization routines, such as an autonomous selector
 * on the LCD.
 *
 * This task will exit when the robot is enabled and autonomous or opcontrol
 * starts.
 */
void competition_initialize() {
	//initializeIMU();
	InertialA.reset();
	while(InertialA.is_calibrating()){
		pros::delay(20);
	}
	pros::delay(20);
}

/**
 * Runs the user autonomous code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the autonomous
 * mode. Alternatively, this function may be called in initialize or opcontrol
 * for non-competition testing purposes.
 *
 * If the robot is disabled or communications is lost, the autonomous task
 * will be stopped. Re-enabling the robot will restart the task, not re-start it
 * from where it left off.
 */
 void redLeftCorner(){
	rotate(90, 60);
 	//ctranslate(48, 60, 90);
 }

 void skillsAuton(){
	launcher.move_voltage(-12000);
	setDrive(-80, -80);
	pros::delay(250);
	setDrive(0, 0);
	setStrafe(127);
	pros::delay(350);
	launcher.move_voltage(0);
	setStrafe(0);
	pros::delay(250);
	stranslate(-13, 100, true);

	setIntake(127);
	indexer.move_voltage(12000);
	translate2(20, 127, true);
	indexer.move_voltage(0);
	ctranslate(25, 127, 35, 95);
	setDrive(100, 100);
	shoot(100);
	pros::delay(250);
	setDrive(0, 0);
	pros::delay(500);
	shoot(0);
	setIntake(0);
	pros::delay(250);

  //move back and turn
	rotate(45, 80);
	setIntake(100);
	shoot(-100);
	dtranslate(-15, 127, false);
	setIntake(-127);
	pros::delay(250);
	shoot(0);
	rotate(-269, 65);
	setIntake(0);

	//straight and intake
	setIntake(127);
  indexer.move_voltage(10000);
	dtranslate(48, 120, false);
	rotate(359, 80);
	indexer.move_voltage(0);
	setIntake(120);
  translate2(4, 120, true);
	setIntake(-100);
	setDrive(100, 100);
	pros::delay(150);
	setDrive(0, 0);
  pros::delay(100);
	//shoot
	shoot(127);
	pros::delay(500);
	shoot(0);

  //back out and turn
	dtranslate(-8, 80, true);
	rotate(179, 70);
	setIntake(100);

	//go towards mid
	indexer.move_voltage(10000);
	translate2(18, 80, false);
 	stranslate(-3, 95, false);
	setIntake(0);

	//descore
	ctranslate(16, 127, 180, 15);
	translate2(-7, 60, true);
	translate2(8, 127, false);

  //angle and shoot in mid
	indexer.move_voltage(10000);
	rotate(210, 60);
	setDrive(100, 100);
	pros::delay(250);
	setDrive(0, 0);
	pros::delay(200);
	shoot(127);
	pros::delay(700);
	shoot(0);

	//back out and move to ball
	dtranslate(-9, 80, false);
	rotate(288, 70);
	setIntake(127);
	dtranslate(61, 127, false);

	//turn to corner goal
	indexer.move_voltage(10000);
	setIntake(100);
	rotate(324, 60);
	indexer.move_voltage(0);
  translate2(23, 127, false);

  //shoot into corner
	shoot(127);
	setDrive(100, 100);
	pros::delay(100);
	setDrive(0, 0);
	pros::delay(500);
	setIntake(0);
	shoot(0);

	//back out
	pros::delay(100);

	setIntake(-100);
	dtranslate(-12, 100, false);

	//shoot to release excess ball
	shoot(100);
	pros::delay(200);
	setIntake(100);

	//go to ball
	indexer.move_voltage(10000);
	rotate(147, 60);
	launcher.move_voltage(0);
	indexer.move_voltage(0);
	dtranslate(58, 127, false);
	pros::delay(250);


	//turn and move to side
	rotate(270, 60);
	indexer.move_voltage(10000);
	pros::delay(250);
	launcher.move_voltage(0);
	indexer.move_voltage(0);
  translate2(29, 127, false);

	//shoot at side goal
	setIntake(0);
	indexer.move_voltage(10000);
	launcher.move_voltage(10000);
	pros::delay(700);
	indexer.move_voltage(0);
	launcher.move_voltage(0);

	//back out and turn
	translate2(-3, 80, false);
	setIntake(-100);
	rotate(-180, 60);


	//straight
	setIntake(100);
	indexer.move_voltage(10000);
	dtranslate(41, 127, false);


	//move towards corner goal and shoot
	rotate(210, 60);
	indexer.move_voltage(0);
	setIntake(0);
	translate2(12, 127, false);
	setDrive(100, 100);
	pros::delay(200);
	setDrive(0, 0);
	shoot(100);
	pros::delay(700);
	shoot(0);

	rotate(225, 60);
	setIntake(100);
	dtranslate(-14, 120, false);
	setIntake(-127);
	rotate(-90, 60);
	setIntake(100);
	indexer.move_voltage(10000);
	dtranslate(48, 120, false);
	rotate(180, 80);

  setIntake(100);
	translate2(5, 127, false);
	shoot(127);
	setIntake(0);
	pros::delay(700);
	shoot(0);
	setIntake(100);
	translate2(-5, 127, false);
	setIntake(0);
 }
 void redRightCorner(){
	 //flipout
	 launcher.move_voltage(10000);

	 //start; drive forward
	 intakeLeft.move_voltage(10000);
	 intakeRight.move_voltage(10000);
	 pros::delay(100);
	 launcher.move_voltage(0);
	 translate2(27, 80, false);

	 //turn right; heading 135
	 intakeLeft.move_voltage(0);
	 intakeRight.move_voltage(0);
	 rotate(135, 60);

	 //move to goal
	 indexer.move_voltage(5000);
	 pros::delay(500);
	 indexer.move_voltage(0);
	 intakeLeft.move_voltage(10000);
	 intakeRight.move_voltage(10000);
	 translate2(30, 80, true);

	 //shoot
	 launcher.move_voltage(10000);
	 indexer.move_voltage(10000);
	 pros::delay(250);
   indexer.move_voltage(0);
	 pros::delay(250);
	 intakeLeft.move_voltage(0);
	 intakeRight.move_voltage(0);
	 pros::delay(500);
	 launcher.move_voltage(0);
	 launcher.move_voltage(-10000);
	 pros::delay(250);
	 launcher.move_voltage(0);

	 //go back
	 translate2(-28, 80, false);
	 intakeLeft.move_voltage(-10000);
	 intakeRight.move_voltage(-10000);
	 pros::delay(750);
	 intakeLeft.move_voltage(0);
	 intakeRight.move_voltage(0);

	 //turn
	 rotate(-1, 60);
	 translate2(29, 50, false);

	 //turn to mid
	 rotate(-270, 80);
	 intakeLeft.move_voltage(10000);
	 intakeRight.move_voltage(10000);
	 indexer.move_voltage(10000);
	 translate2(26, 60, false);
	 pros::delay(1000);
	 indexer.move_voltage(0);
	 intakeLeft.move_voltage(0);
   intakeRight.move_voltage(0);
	 translate2(-5, 80, false);
	 translate2(6, 80, false);
	 rotate(290, 60);
	 indexer.move_voltage(10000);
	 launcher.move_voltage(10000);
	 pros::delay(250);
	 indexer.move_voltage(0);
	 pros::delay(250);
	 launcher.move_voltage(0);

	 translate2(-10, 80, false);
	 rotate(1, 60);
	 translate2(24, 50, false);
	 rotate(-300, 60);
	 intakeLeft.move_voltage(10000);
	 intakeRight.move_voltage(10000);
	 indexer.move_voltage(5000);
	 translate2(92, 80, false);
	 launcher.move_voltage(10000);
	 pros::delay(750);
	 indexer.move_voltage(0);
	 pros::delay(250);
	 launcher.move_voltage(0);

	 intakeLeft.move_voltage(0);
	 intakeRight.move_voltage(0);
    translate2(-10, 80, false);


 }
 void redMatchAuton(){
	 //strafe out and rotate to goal; start intakes

	rotate(-333, 50);
	shoot(-127);
	pros::delay(500);
	launcher.move_voltage(0);

	setIntake(127);
	launcher.move_voltage(-12000);
	ctranslate(20, 120, 0, 40);
	launcher.move_voltage(0);
	ctranslate(21, 127, 45, 71);
	setDrive(120, 120);
	shoot(100);
	pros::delay(250);
	setDrive(0, 0);
 	setIntake(0);

 	pros::delay(1000);
 	setIntake(-127);
 	shoot(0);

	dtranslate(-18, 127, false);
	setIntake(0);
	rotate(180, 70);
	dtranslate(61, 127, false);

	setIntake(127);
	indexer.move_voltage(12000);
	ctranslate(37, 127, -135, 52);

	setDrive(127, 127);
	pros::delay(750);
	setDrive(0, 0);
	shoot(127);
	setIntake(0);
	pros::delay(750);
	shoot(0);

}

 void blueMatchAuton(){
	 //strafe out and rotate to goal; start intakes

  rotate(-333, 50);
	shoot(-127);
	pros::delay(300);
 	launcher.move_voltage(0);

 	setIntake(127);
 	launcher.move_voltage(-12000);
 	ctranslate(20, 120, 0, 40);
 	launcher.move_voltage(0);
 	ctranslate(21, 127, 45, 73);
	setDrive(120, 120);
	shoot(100);
	pros::delay(250);
	setDrive(0, 0);
 	setIntake(0);

 	pros::delay(1000);
 	setIntake(-127);
 	shoot(0);

 	dtranslate(-18, 127, false);
 	setIntake(0);
 	rotate(179, 80);
	dtranslate(62, 127, false);

 	setIntake(127);
 	indexer.move_voltage(12000);
 	ctranslate(37, 127, -135, 55);

 	setDrive(127, 127);
 	pros::delay(750);
 	setDrive(0, 0);
	shoot(127);
 	setIntake(0);
 	pros::delay(750);
 	shoot(0);

}

void avoidAuton(){
	//strafe out and rotate to goal; start intakes
 shoot(-127);
 rotate(-332, 50);
 launcher.move_voltage(0);

 setIntake(127);
 launcher.move_voltage(-12000);
 ctranslate(20, 120, 0, 35);
 launcher.move_voltage(0);
 ctranslate(21, 127, 45, 70);
 setDrive(120, 120);
 pros::delay(500);
 setDrive(0, 0);
 setIntake(0);

 shoot(100);
 pros::delay(1000);
 pros::delay(250);
 setIntake(-127);
 shoot(0);

 dtranslate(-34, 127, false);
 setIntake(0);
 rotate(178, 85);
 dtranslate(53, 127, false);

 setIntake(127);
 indexer.move_voltage(12000);
 ctranslate(36, 127, -135, 55);

 setDrive(120, 120);
 pros::delay(750);
 setDrive(0, 0);
 shoot(127);
 setIntake(0);
 pros::delay(750);
 shoot(0);
 setIntake(-127);
 translate2(-6, 40, false);
 setIntake(0);

}

void triangleAuton(){
	shoot(-127);
  rotate(-340, 50);
  launcher.move_voltage(0);

  setIntake(127);
  launcher.move_voltage(-12000);
  ctranslate(20, 120, 0, 30);
  launcher.move_voltage(0);
  ctranslate(21, 127, 45, 70);
  setDrive(120, 120);
  pros::delay(500);
  setDrive(0, 0);
  setIntake(0);

  shoot(100);
  pros::delay(1000);
  pros::delay(250);
  setIntake(-127);
  shoot(0);

	dtranslate(-50, 127, false);
	rotate(-267, 80);

	setIntake(127);
	translate2(40, 110, false);

	setDrive(120, 120);
  pros::delay(750);
  setDrive(0, 0);
  shoot(127);
  setIntake(0);
  pros::delay(750);
  shoot(0);
  setIntake(-127);
  translate2(-6, 40, false);
  setIntake(0);
}
void twoball(){
	//strafe out and rotate to goal; start intakes
 shoot(-127);
 rotate(-332, 50);
 launcher.move_voltage(0);

 setIntake(127);
 launcher.move_voltage(-12000);
 ctranslate(20, 120, 0, 35);
 launcher.move_voltage(0);
 ctranslate(21, 127, 45, 70);
 setDrive(120, 120);
 pros::delay(500);
 setDrive(0, 0);
 setIntake(100);

 shoot(100);
 pros::delay(1000);
 setDrive(-100, -100);
 pros::delay(250);
 setDrive(120, 120);
 pros::delay(300);
 setDrive(0, 0);
 pros::delay(750);
 shoot(0);
 setIntake(0);
 translate2(-10, 127, false);



}

void mid(){
	launcher.move_voltage(-12000);
	dtranslate(55, 127, false);
	launcher.move_voltage(0);
	setDrive(100, -100);
	pros::delay(75);
	setDrive(0, 0);
	stranslate(6, 127, false);
}

void corner(){
  launcher.move_voltage(-12000);
	stranslate(-24, 127, true);
	launcher.move_voltage(0);
	rotate(45, 60);
	translate2(26, 127, false);
	setDrive(120, 120);
  pros::delay(250);
  setDrive(0, 0);
  setIntake(127);

  shoot(127);
  pros::delay(1000);
  pros::delay(500);
  shoot(0);
  setIntake(0);
  translate2(-10, 127, false);


}

void otherCorner(){
  launcher.move_voltage(-12000);
	stranslate(24, 127, true);
	launcher.move_voltage(0);
	rotate(-315, 60);
	translate2(26, 127, false);
	setDrive(120, 120);
  pros::delay(250);
  setDrive(0, 0);
  setIntake(127);

  shoot(127);
  pros::delay(1000);
  pros::delay(500);
  shoot(0);
  setIntake(0);
  translate2(-10, 127, false);


}

void autonomous() {
//	redLeftCorner();
//	redRightCorner();
//	skillsAuton();
	redMatchAuton();
//testing();
 //blueMatchAuton();
//avoidAuton();
//twoball();
//mid();
//corner();

//otherCorner();
}

/**
 * Runs the operator control code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the operator
 * control mode.
 *
 * If no competition control is connected, this function will run immediately
 * following initialize().
 *
 * If the robot is disabled or communications is lost, the
 * operator control task will be stopped. Re-enabling the robot will restart the
 * task, not resume it from where it left off.

void opcontrol() {
	pros::Controller master(pros::E_CONTROLLER_MASTER);
	pros::Motor left_mtr(1);
	pros::Motor right_mtr(2);

	while (true) {
		pros::lcd::print(0, "%d %d %d", (pros::lcd::read_buttons() & LCD_BTN_LEFT) >> 2,
		                 (pros::lcd::read_buttons() & LCD_BTN_CENTER) >> 1,
		                 (pros::lcd::read_buttons() & LCD_BTN_RIGHT) >> 0);
		int left = master.get_analog(ANALOG_LEFT_Y);
		int right = master.get_analog(ANALOG_RIGHT_Y);

		left_mtr = left;
		right_mtr = right;
		pros::delay(20);
	}
}*/

void opcontrol(){
	printf("In opcontrol\n");

	while(true){

		//some code to control the drive
		driveControl();
		arrows();

		//control intakes
		setIntakeMotors();

		//shoot (spins indexer and launcher)
		//shoot();
// lol u good 2/?
		//outtakes and reverses intakes
		//cycleOut();
		//
 		// //reverses launcher
		// reverseLauncher();

		pros::delay(10);

	}
}
