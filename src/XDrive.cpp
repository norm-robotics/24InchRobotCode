#include "../include/main.h"
#include "../include/XDrive.hpp"
#include <cstdint>
using namespace std;

Xdrivebase::Xdrivebase(int8_t frontRightMotorPort, int8_t frontLeftMotorPort, int8_t rearRightMotorPort, int8_t rearLeftMotorPort){
    frontRightMotor = frontRightMotorPort;
    frontLeftMotor = frontLeftMotorPort;
    rearRightMotor = rearRightMotorPort;
    rearLeftMotor = rearLeftMotorPort;
    motors[0] = frontRightMotor;
    motors[1] = frontLeftMotor;
    motors[2] = rearRightMotor;
    motors[3] = rearLeftMotor;

}
void Xdrivebase::moveY(int32_t joystickInputY){ //This moves the robot up and down
    pros::c::motor_move(frontRightMotor, joystickInputY);
    pros::c::motor_move(frontLeftMotor, (-1*joystickInputY));
    pros::c::motor_move(rearRightMotor, joystickInputY);
    pros::c::motor_move(rearLeftMotor, (-1*joystickInputY));
}
void Xdrivebase::moveX(int32_t joystickInputX){ //This moves the robot forward and back
    pros::c::motor_move(frontRightMotor, joystickInputX);
    pros::c::motor_move(frontLeftMotor, joystickInputX);
    pros::c::motor_move(rearRightMotor, (-1*joystickInputX));
    pros::c::motor_move(rearLeftMotor, (-1*joystickInputX));
}
void Xdrivebase::rotate(int32_t joystickInputTurn){
    pros::c::motor_move(frontRightMotor, joystickInputTurn);
    pros::c::motor_move(frontLeftMotor, joystickInputTurn);
    pros::c::motor_move(rearRightMotor, joystickInputTurn);
    pros::c::motor_move(rearLeftMotor, joystickInputTurn);
}
void Xdrivebase::stop(){
    for (int8_t motor : motors) {
        pros::c::motor_brake(motor); 
    }
}
