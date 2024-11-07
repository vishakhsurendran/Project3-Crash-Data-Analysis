//
// Created by Vishakh Surendran on 11/6/2024.
//

#include "Crash.h"
#include "../data/Motor_Vehicle_Collisions.csv"

std::vector<Crash> parseData() {
    std::vector<Crash> data;
    std::ifstream collisions("Motor_Vehicle_Collisions");
    std::string line;

    if (!collisions.is_open()) {
        return data;
    }

    std::getline(collisions, line);

    while (std::getline(collisions, line)) {
        std::istringstream stream(line);
        Crash crash;

        std::getline()
    }
}