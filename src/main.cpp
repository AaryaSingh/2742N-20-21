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

  //initializeIMU();
	InertialA.reset();
	pros::delay(3000);
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
 	ctranslate(48, 60, 90);
 }

 void skillsAuton(){
	//strafe and move to goal
	launcher.move_voltage(-10000);
 	stranslate(-12, 80, false);
	launcher.move_voltage(0);
	rotate(45, 60);
	intakeLeft.move_voltage(5000);
	intakeRight.move_voltage(5000);
	translate2(10, 80, true);
	intakeLeft.move_voltage(0);
	intakeRight.move_voltage(0);
	//shoot
	launcher.move_voltage(10000);
	indexer.move_voltage(10000);
	pros::delay(500);
	indexer.move_voltage(0);
	launcher.move_voltage(0);

  //move back and turn
	translate2(-12, 80, false);
	rotate(-270, 40);

	//straight and intake
	intakeLeft.move_voltage(10000);
	intakeRight.move_voltage(10000);
	translate2(45, 80, false);
	rotate(359, 60);
	indexer.move_voltage(10000);
	intakeLeft.move_voltage(0);
	intakeRight.move_voltage(0);
  translate2(8, 80, false);

	//shoot
	launcher.move_voltage(10000);
	pros::delay(500);
	indexer.move_voltage(0);
	launcher.move_voltage(0);

	translate2(-8, 80, false);
	rotate(180, 60);
	intakeLeft.move_voltage(10000);
	intakeRight.move_voltage(10000);
	translate2(22, 80, false);
 	stranslate(-3, 80, false);
	intakeLeft.move_voltage(0);
	intakeRight.move_voltage(0);
	translate2(16, 80, false);

	indexer.move_voltage(10000);
	rotate(200, 60);
	launcher.move_voltage(7500);
	pros::delay(500);
	indexer.move_voltage(0);
	launcher.move_voltage(0);


	translate2(-8, 80, false);
	rotate(290, 60);

	intakeLeft.move_voltage(10000);
	intakeRight.move_voltage(10000);
	translate2(60, 80, false);

	indexer.move_voltage(5000);
	intakeLeft.move_voltage(5000);
	intakeRight.move_voltage(5000);
	rotate(325, 60);
	intakeLeft.move_voltage(0);
	intakeRight.move_voltage(0);
  translate2(20, 80, false);

  //shoot
	indexer.move_voltage(10000);
	launcher.move_voltage(7500);
	pros::delay(500);
	indexer.move_voltage(0);
	launcher.move_voltage(0);

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
	 /*intakeLeft.move_voltage(10000);
   intakeRight.move_voltage(10000);
	 translate2(110, 80, false);
	 indexer.move_voltage(10000);
	 launcher.move_voltage(10000);
	 pros::delay(2000);
	 intakeLeft.move_voltage(0);
   intakeRight.move_voltage(0);
	 indexer.move_voltage(0);
	 launcher.move_voltage(0);*/
	 /*indexer.move_voltage(0);
	 intakeLeft.move_voltage(-10000);
	 intakeRight.move_voltage(-10000);
	 pros::delay(3000);
	 intakeLeft.move_voltage(0);
	 intakeRight.move_voltage(0);
	 indexer.move_voltage(10000);
	 launcher.move_voltage(10000);
	 pros::delay(1500);
	 indexer.move_voltage(0);
	 launcher.move_voltage(0);*/

 }
 void matchAuton(){
	//strafe out and rotate to goal; start intakes
	launcher.move_voltage(-10000);
  stranslate(-20, 100, true);
	launcher.move_voltage(0);
  rotate(45, 80);
	intakeLeft.move_voltage(10000);
	intakeRight.move_voltage(10000);

	//move to goal
	translate2(22, 100, false);
	pros::delay(500);
	intakeLeft.move_voltage(0);
	intakeRight.move_voltage(0);

	// stranslate(-2, 100, true);
	// intakeLeft.move_voltage(10000);
  // intakeRight.move_voltage(10000);
  // translate2(14, 100, false);
	// rotate(45, 80);
	// translate2(2, 100, false);
	// intakeLeft.move_voltage(0);
	// intakeRight.move_voltage(0);

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

	//move out
	intakeLeft.move_voltage(-10000);
	intakeRight.move_voltage(-10000);
	pros::delay(250);
	translate2(-11, 100, true);
	pros::delay(250);
	intakeLeft.move_voltage(0);
	intakeRight.move_voltage(0);

	//turn and strafe to middle home row
	rotate(90, 80);
  stranslate(44, 110, true);

	//move to goal
  translate2(5, 127, false);

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


 }
void autonomous() {
//	redLeftCorner();
//	redRightCorner();
	skillsAuton();
//	matchAuton();

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

		//control intakes
		setIntakeMotors();

		//shoot (spins indexer and launcher)
		//shoot();

		//outtakes and reverses intakes
		//cycleOut();
		//
 		// //reverses launcher
		// reverseLauncher();

		pros::delay(10);

	}
}
