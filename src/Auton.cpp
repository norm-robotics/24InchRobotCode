#include "../include/main.h"
#include "../include/Auton.hpp"
#include <cstdint>
#include <vector>

Auton::Auton(Xdrivebase& drivebase, Intake& intake): drive(drivebase), intake(intake){
    pros::lcd::print(0, "Works");
}
void Auton::BlueSide(){
    drive.moveY(6, inches, 100);   
    drive.moveX(24, inches, 100);   
    intake.eating();
    drive.moveY(-4, inches, 100);
    pros::c::delay(500);
    intake.stop();
    drive.moveY(24, inches, 100);   
    intake.eating();
    pros::c::delay(500);
    intake.stop();
    drive.moveY(-2, inches, 100);
    drive.moveX(4, square, 100);
    intake.eating();
    drive.moveY(-24, inches, 100);
    pros::c::delay(500);
    intake.stop();
    drive.moveY(24, inches, 100);
    intake.eating();
    pros::c::delay(500);
    intake.stop();
}
void Auton::stop(){
    drive.stop();
    intake.stop();
}
