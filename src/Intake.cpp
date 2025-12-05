#include "../include/main.h"
#include "../include/Intake.hpp"
#include <cstdint>
#include <vector>

Intake::Intake(
        int motor1port,
        int motor2port,
        int motor3port,
        pros::v5::MotorGears gearset):
    motor1(motor1port, gearset),
    motor2(motor2port, gearset),
    motor3(motor3port, gearset)
    {
        motor1.set_reversed(true);
        motor3.set_reversed(true);
    }

void Intake::initialize(){
}


void Intake::eating(){
        motor1.move(127);
        motor2.move(127);
        motor3.move(127);
}

void Intake::shitting(){
        motor1.move(-127);
        motor2.move(-127);
        motor3.move(-127);
}

void Intake::stop(){
    motor3.brake();
    motor2.brake();
    motor1.brake();
    pros::delay(20);
}

