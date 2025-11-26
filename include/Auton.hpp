#include "../include/main.h"
#include "pros/motor_group.hpp"
#include "pros/motors.h"
#ifndef AUTON_HPP
#define AUTON_HPP
#include "./XDrive.hpp"
#include "./Intake.hpp"

#include <cstdint>
#include <vector>

class Auton {
    public:
        Auton(Xdrivebase&, Intake&);
        void stop();
};

#endif
