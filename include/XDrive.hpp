#include "../include/main.h"
#include "pros/motor_group.hpp"
#include "pros/motors.h"
#ifndef XDRIVEBASE_HPP
#define XDRIVEBASE_HPP

#include <cstdint>
#include <vector>

class Xdrivebase {
public:
    pros::MotorGroup frontRightMotors;
    pros::MotorGroup frontLeftMotors;
    pros::MotorGroup rearLeftMotors;
    pros::MotorGroup rearRightMotors;
    Xdrivebase(std::vector<int8_t>, std::vector<int8_t>, std::vector<int8_t>, std::vector<int8_t>, pros::v5::MotorGears);
    void moveJoystick(int32_t, int32_t, int32_t);
    void stop();
};

#endif

