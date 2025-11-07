#include "../include/main.h"
#include "../include/XDrive.hpp"
#include <cstdint>
using namespace pros;

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
    c::motor_move(frontRightMotor, joystickInputY);
    c::motor_move(frontLeftMotor, (-1*joystickInputY));
    c::motor_move(rearRightMotor, joystickInputY);
    c::motor_move(rearLeftMotor, (-1*joystickInputY));
}
void Xdrivebase::moveX(int32_t joystickInputX){ //This moves the robot forward and back
    c::motor_move(frontRightMotor, joystickInputX);
    c::motor_move(frontLeftMotor, joystickInputX);
    c::motor_move(rearRightMotor, (-1*joystickInputX));
    c::motor_move(rearLeftMotor, (-1*joystickInputX));
}
void Xdrivebase::rotate(int32_t joystickInputTurn){
    c::motor_move(frontRightMotor, joystickInputTurn);
    c::motor_move(frontLeftMotor, joystickInputTurn);
    c::motor_move(rearRightMotor, joystickInputTurn);
    c::motor_move(rearLeftMotor, joystickInputTurn);
}
void Xdrivebase::stop(){
    for (int8_t motor : motors) {
        pros::c::motor_brake(motor); 
    }
}
