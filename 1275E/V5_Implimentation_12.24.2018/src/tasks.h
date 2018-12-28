#include "main.h"
#define CATAPULT_LEFT 5
#define CATAPULT_RIGHT 6

#define LIMIT_SWITCH 'a'

using namespace std;

pros::Motor leftCatapultMotor (CATAPULT_LEFT);
pros::Motor rightCatapultMotor (CATAPULT_RIGHT, true);

pros::ADIDigitalIn limitSwitch (LIMIT_SWITCH);

int motorGoal = 12;
int idlePower = 2;

void wait() {}

void autoShoot(void* param) {
  if (!limitSwitch.get_value()) {
    // The Catapult is Loaded
    leftCatapultMotor.move(127);
    rightCatapultMotor.move(127);
    // Wait untill the catapult is ready to be primed
    while(!limitSwitch.get_value()) pros::delay(2);
    // Reset Catapult Motors
    leftCatapultMotor.move(0);
    rightCatapultMotor.move(0);

    leftCatapultMotor.tare_position();
    rightCatapultMotor.tare_position();

    rightCatapultMotor.move(127);
    leftCatapultMotor.move(127);

    while(!limitSwitch.get_value() && (rightCatapultMotor.get_position() <= motorGoal || leftCatapultMotor.get_position() <= motorGoal)) pros::delay(2);

    rightCatapultMotor.move(idlePower);
    leftCatapultMotor.move(idlePower);
  } else {
    rightCatapultMotor.move(127);
    leftCatapultMotor.move(127);

    while(!limitSwitch.get_value() && (rightCatapultMotor.get_position() <= motorGoal || leftCatapultMotor.get_position() <= motorGoal)) pros::delay(2);

    rightCatapultMotor.move(idlePower);
    leftCatapultMotor.move(idlePower);
  }
}
