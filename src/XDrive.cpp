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
        switch (gearset) {
            case pros::MotorGears::blue:
                maxVel = 600;
                break;
            case pros::MotorGears::green:
                maxVel = 200;
                break;
            case pros::MotorGears::red:
                maxVel = 100;
                break;
        }
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
void Xdrivebase::moveY(float distance, unit units, int16_t vel){
    float velocityF = (maxVel/100.0)*vel;
    int16_t velocity = std::round(velocityF);
    switch (units) {
        case rotations:{
            double rotations = 360*distance;
            frontRightMotors.move_relative(rotations, velocity);
            frontLeftMotors.move_relative(-rotations, velocity);
            rearRightMotors.move_relative(rotations, velocity);
            rearLeftMotors.move_relative(-rotations, velocity);
            pros::delay(500*distance);
            } break;
        case inches: {
            double inches = (1.0/7.5)*distance;
            inches = 360*inches;
            frontRightMotors.move_relative(inches, velocity);
            frontLeftMotors.move_relative(-inches, velocity);
            rearRightMotors.move_relative(inches, velocity);
            rearLeftMotors.move_relative(-inches, velocity);
            pros::delay(100*distance);
            } break;
        case seconds: {
            frontRightMotors.move_velocity(velocity);
            frontLeftMotors.move_velocity(-velocity);
            rearRightMotors.move_velocity(velocity);
            rearLeftMotors.move_velocity(-velocity);
            pros::c::delay(distance*1000);
            frontLeftMotors.brake();
            frontRightMotors.brake();
            rearLeftMotors.brake();
            rearRightMotors.brake();
            } break;
        case degrees: {
            frontRightMotors.move_relative(distance, velocity);
            frontLeftMotors.move_relative(-distance, velocity);
            rearRightMotors.move_relative(distance, velocity);
            rearLeftMotors.move_relative(-distance, velocity);
            } break;
        default:
            throw NoUnitDefined;
            break;
    }
}
void Xdrivebase::moveX(float distance, unit units, int16_t vel){
    float velocityF = (maxVel/100.0)*vel;
    int16_t velocity = std::round(velocityF);
    switch (units) {
        case rotations:{
            double rotations = 360*distance;
            frontRightMotors.move_relative(rotations, velocity);
            frontLeftMotors.move_relative(-rotations, velocity);
            rearRightMotors.move_relative(-rotations, velocity);
            rearLeftMotors.move_relative(rotations, velocity);
            pros::delay(500*distance);
            } break;
        case inches: {
            double inches = (1.0/7.5)*distance;
            inches = 360*inches;
            std::cout << inches << std::endl;
            frontRightMotors.move_relative(inches, velocity);
            frontLeftMotors.move_relative(-inches, velocity);
            rearRightMotors.move_relative(-inches, velocity);
            rearLeftMotors.move_relative(inches, velocity);
            pros::delay(100*distance);
            } break;
        case seconds: {
            frontRightMotors.move_velocity(velocity);
            frontLeftMotors.move_velocity(-velocity);
            rearRightMotors.move_velocity(-velocity);
            rearLeftMotors.move_velocity(velocity);
            pros::c::delay(distance*1000);
            frontLeftMotors.brake();
            frontRightMotors.brake();
            rearLeftMotors.brake();
            rearRightMotors.brake();
            } break;
        case degrees: {
            frontRightMotors.move_relative(distance, velocity);
            frontLeftMotors.move_relative(-distance, velocity);
            rearRightMotors.move_relative(-distance, velocity);
            rearLeftMotors.move_relative(distance, velocity);
            } break;
        default:
            throw NoUnitDefined;
            break;
    }
}
void Xdrivebase::rotate(float degrees, int16_t vel){
    float velocityF = (maxVel/100.0)*vel;
    int16_t velocity = std::round(velocityF);
    degrees = (360*degrees)/45;
    frontRightMotors.move_relative(rotations, velocity);
    frontLeftMotors.move_relative(rotations, velocity);
    rearRightMotors.move_relative(rotations, velocity);
    rearLeftMotors.move_relative(rotations, velocity);
    pros::delay(100*degrees);
}
void Xdrivebase::stop(){
    frontLeftMotors.brake();
    frontRightMotors.brake();
    rearLeftMotors.brake();
    rearRightMotors.brake();
    pros::delay(20);
}
