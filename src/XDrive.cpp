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
        // Validate all motor port vectors
        if (frontRightMotorPorts.empty()) {
            pros::lcd::set_text(2, "ERROR: FR motors empty!");
            throw std::runtime_error("Front Right motors vector is empty");
        }
        if (frontLeftMotorPorts.empty()) {
            pros::lcd::set_text(2, "ERROR: FL motors empty!");
            throw std::runtime_error("Front Left motors vector is empty");
        }
        if (rearRightMotorPorts.empty()) {
            pros::lcd::set_text(2, "ERROR: RR motors empty!");
            throw std::runtime_error("Rear Right motors vector is empty");
        }
        if (rearLeftMotorPorts.empty()) {
            pros::lcd::set_text(2, "ERROR: RL motors empty!");
            throw std::runtime_error("Rear Left motors vector is empty");
        }
        frontLeftMotors.set_reversed_all(true);
        rearRightMotors.set_reversed_all(true);
    }
void Xdrivebase::initialize(){
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
void Xdrivebase::moveForward(float distance, unit units){
    switch (units) {
        case rotations:
            pros::lcd::set_text(3, "Rotations");
            frontRightMotors.move_relative(360, 100);
            frontLeftMotors.move_relative(360, 100);
            rearRightMotors.move_relative(360, 100);
            rearLeftMotors.move_relative(360, 100);
            pros::delay(1000);
            break;
        case inches:
            break;
        case seconds:
            break;
        case degrees:
            break;
        default:
            throw NoUnitDefined;
            break;
    }
}
void Xdrivebase::stop(){
    frontLeftMotors.brake();
    frontRightMotors.brake();
    rearLeftMotors.brake();
    rearRightMotors.brake();
    pros::delay(20);
}
