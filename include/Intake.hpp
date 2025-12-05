#include "../include/main.h"
#include "pros/motor_group.hpp"
#include "pros/motors.h"
#ifndef INTAKE_HPP
#define INTAKE_HPP

#include <cstdint>
#include <vector>

class Intake{
public:
    Intake();
    pros::Motor motor1;
    pros::Motor motor2;
    pros::Motor motor3;
    Intake(int, int, int, pros::v5::MotorGears);
    void initialize();
    void eating();
    void shitting();
    void stop();
};

#endif
