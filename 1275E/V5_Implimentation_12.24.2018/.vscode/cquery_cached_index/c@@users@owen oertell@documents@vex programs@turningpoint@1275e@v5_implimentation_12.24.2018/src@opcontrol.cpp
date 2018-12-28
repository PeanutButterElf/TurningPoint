// These are some prepocesser definitions so ports are defined:
#define FRONT_LEFT_MOTOR 1
#define BACK_LEFT_MOTOR 2
#define FRONT_RIGHT_MOTOR 3
#define BACK_RIGHT_MOTOR 4
#define FLIPPER 7
#define ROLLER 8

#include "main.h"
#include "tasks.h"

using namespace std;

int rollerMovement = 0;
int rollerOnOffToggle = 0;

void opcontrol() {
// Controller Definition
	pros::Controller master(pros::E_CONTROLLER_MASTER);

	// Motor definitions
	pros::Motor frontLeftMotor (FRONT_LEFT_MOTOR);
  pros::Motor frontRightMotor (FRONT_RIGHT_MOTOR, true);
	pros::Motor backLeftMotor (BACK_LEFT_MOTOR);
  pros::Motor backRightMotor (BACK_RIGHT_MOTOR, true);
	pros::Motor flipper (FLIPPER, true);
	pros::Motor roller (ROLLER);
	pros::Motor leftCatapultMotor (CATAPULT_LEFT);
	pros::Motor rightCatapultMotor (CATAPULT_RIGHT);

	while (true) {
		// Tank Control
		frontRightMotor.move(master.get_analog(ANALOG_LEFT_Y));
    frontLeftMotor.move(master.get_analog(ANALOG_RIGHT_Y));
		backLeftMotor.move(master.get_analog(ANALOG_LEFT_Y));
    backRightMotor.move(master.get_analog(ANALOG_RIGHT_Y));

		// Descore Bar Control
		if (master.get_digital(pros::E_CONTROLLER_DIGITAL_L1)) {
			flipper.move(127);
		} else if (master.get_digital(pros::E_CONTROLLER_DIGITAL_L2)) {
			flipper.move(-127);
		} else {
			flipper.move(0);
		}

		// Rollers
		if (master.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_Y)) {
			rollerMovement = (rollerOnOffToggle) ? 0 : 127;
			rollerOnOffToggle = (rollerOnOffToggle) ? 0 : 1;
		} else if (master.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_X)) {
			rollerMovement = (rollerOnOffToggle) ? 0 : -127;
			rollerOnOffToggle = (rollerOnOffToggle) ? 0 : 1;
		}
		roller.move(rollerMovement);
		// Catapult
		if (master.get_digital(pros::E_CONTROLLER_DIGITAL_R1)) {
			std::string autoShootOutput("PROS");
			pros::Task autoShootTask(autoShoot, &autoShootOutput);
		}

		pros::delay(2);
	}
}
