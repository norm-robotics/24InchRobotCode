#include "../include/main.h"
#include "pros/motor_group.hpp"
#ifndef XDRIVEBASE_HPP
#define XDRIVEBASE_HPP

#include <cstdint>
#include <vector>

enum unit{
    rotations,
    inches,
    seconds,
    degrees
};
enum errors{
    success,
    NoUnitDefined
};
class Xdrivebase {
public:
    pros::MotorGroup frontRightMotors;
    pros::MotorGroup frontLeftMotors;
    pros::MotorGroup rearLeftMotors;
    pros::MotorGroup rearRightMotors;
    Xdrivebase(std::vector<int8_t>, std::vector<int8_t>, std::vector<int8_t>, std::vector<int8_t>, pros::v5::MotorGears);
    void initialize();
    void moveJoystick(int32_t, int32_t, int32_t);
    void moveForward(float, unit);
    void stop();
};

#endif

