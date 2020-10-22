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
void competition_initialize() {}

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
	 //Go to first corner- Can we make function of these steps?
	 //Step-1 : go straight to white line.
	 //step-2 : Turn 135 degrees
	 //step-3 : grab the red ball and shoot that in
	 //Step-4 : remove red ball and shoot it back
	 //step-5 : remove blue ball and discard
   translate(24, 100);
	 rotate(135, 11);
	 //setIntakeMotors(127);
 }

 void blueLeftCorner(){

 }
 void redRightCorner(){
	 //printheading();
		/*intakeLeft.move_voltage(-10000);
		intakeRight.move_voltage(-10000);
	 pros::delay(1000);
	 intakeLeft.move_voltage(0);
		intakeRight.move_voltage(0);
		pros::delay(1000);*/
	 intakeLeft.move_voltage(10000);
	 intakeRight.move_voltage(10000);
	 //pros::delay(1000);
	 translate2(22, 80, false);
	 intakeLeft.move_voltage(0);
	 intakeRight.move_voltage(0);
	 rotate(135, 60);
	 indexer.move_voltage(5000);
	 translate2(26, 80, true);
	 indexer.move_voltage(10000);
	 launcher.move_voltage(10000);
	 pros::delay(1000);
	 indexer.move_voltage(0);
	 launcher.move_voltage(0);
	 translate2(-26, 80, false);
	 rotate(-1, 60);
	 translate2(30, 80, false);
	 rotate(-270, 60);
	 indexer.move_voltage(10000);
	 intakeLeft.move_voltage(10000);
	 intakeRight.move_voltage(10000);
	 translate2(26, 80, false);
	 indexer.move_voltage(0);
	 intakeLeft.move_voltage(-10000);
	 intakeRight.move_voltage(-10000);
	 pros::delay(3000);
	 intakeLeft.move_voltage(0);
	 intakeRight.move_voltage(0);
	 indexer.move_voltage(10000);
	 launcher.move_voltage(10000);
	 pros::delay(1500);
	 indexer.move_voltage(0);
	 launcher.move_voltage(0);

 }
 void blueRightCorner(){

 }
void autonomous() {
//	redLeftCorner();
	redRightCorner();
//	blueLeftCorner();
//	blueRightCorner();

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
		//some code to control thr drive
		driverControl();
		//constantDrive();
		//control intake
		//setIntakeMotors();
		//Control lift
		//setLiftMotors();
		//Control angle
		//setAnglerMotor();

		pros::delay(20);
	}
}
