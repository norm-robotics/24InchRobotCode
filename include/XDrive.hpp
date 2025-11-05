#include "../include/main.h"
#ifndef XDRIVEBASE_HPP
#define XDRIVEBASE_HPP

#include <cstdint>

class Xdrivebase {
public:
    Xdrivebase(int8_t frontRightMotorPort, int8_t frontLeftMotorPort, int8_t rearRightMotorPort, int8_t rearLeftMotorPort);
    void moveY(int32_t joystickInputY);
    void moveX(int32_t joystickInputX);
    void rotate(int32_t joystickInputTurn);
    void stop();

private:
    int8_t frontRightMotor;
    int8_t frontLeftMotor;
    int8_t rearRightMotor;
    int8_t rearLeftMotor;
    int8_t motors[4];
};

#endif

