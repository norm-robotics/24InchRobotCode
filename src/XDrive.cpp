#include "../include/main.h"
#include "../include/XDrive.hpp"
#include <cstdint>
#include <vector>

Xdrivebase::Xdrivebase(
        std::vector<int8_t> frontRightMotorPorts,
        std::vector<int8_t> rearRightMotorPorts,
        std::vector<int8_t> frontLeftMotorPorts,
        std::vector<int8_t> rearLeftMotorPorts,
        pros::v5::MotorGears gearset) :
    frontRightMotors(frontRightMotorPorts, gearset),
    frontLeftMotors(frontLeftMotorPorts, gearset),
    rearRightMotors(rearRightMotorPorts, gearset),
    rearLeftMotors(rearLeftMotorPorts, gearset)
    {
        frontLeftMotors.set_reversed(true);
        rearRightMotors.set_reversed(true);

    }
void Xdrivebase::moveJoystick(int32_t joystickInputY, int32_t joystickInputX, int32_t joystickInputTurn){ 
    // the source of these four lines are https://www.vexforum.com/t/holonomic-drives-2-0-a-video-tutorial-by-cody/27052
    int frontRightMotorMove = joystickInputY - joystickInputX - joystickInputTurn;
    int frontLeftMotorMove = -joystickInputY - joystickInputX - joystickInputTurn;
    int rearRightMotorMove = joystickInputY + joystickInputX - joystickInputTurn;
    int rearLeftMotorMove = -joystickInputY + joystickInputX - joystickInputTurn;
    frontRightMotors.move(frontRightMotorMove);
    frontLeftMotors.move(frontLeftMotorMove);
    rearRightMotors.move(rearRightMotorMove);
    rearLeftMotors.move(rearLeftMotorMove);
    pros::delay(20);

}
void Xdrivebase::stop(){
}
