//
// Created by Vishakh Surendran on 11/6/2024.
//

#include <iomanip>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "Crash.h"

std::vector<Crash> parseData() {
    std::vector<Crash> crashes;
    std::ifstream collisions("Motor_Vehicle_Collisions");
    std::string line;

    if (!collisions.is_open()) {
        return crashes;
    }

    std::getline(collisions, line);

    while (std::getline(collisions, line)) {
        std::istringstream stream(line);
        Crash crash;

        std::getline(stream, crash.crash_date, ',');
        std::getline(stream, crash.crash_time, ',');
        std::getline(stream, crash.borough, ',');
        std::getline(stream, crash.zip_code, ',');
        std::getline(stream, crash.latitude, ',');
        std::getline(stream, crash.longitude, ',');
        std::getline(stream, crash.location, ',');
        std::getline(stream, crash.on_street_name, ',');
        std::getline(stream, crash.cross_street_name, ',');
        std::getline(stream, crash.off_street_name, ',');
        std::getline(stream, crash.num_persons_injured, ',');
        std::getline(stream, crash.num_persons_killed, ',');
        std::getline(stream, crash.num_pedestrians_injured, ',');
        std::getline(stream, crash.num_pedestrians_killed, ',');
        std::getline(stream, crash.num_cyclists_injured, ',');
        std::getline(stream, crash.num_cyclists_killed, ',');
        std::getline(stream, crash.num_motorists_injured, ',');
        std::getline(stream, crash.num_motorists_killed, ',');
        std::getline(stream, crash.vehicle1, ',');
        std::getline(stream, crash.vehicle2, ',');
        std::getline(stream, crash.vehicle3, ',');
        std::getline(stream, crash.vehicle4, ',');
        std::getline(stream, crash.vehicle5, ',');
        std::getline(stream, crash.collision_ID, ',');
        std::getline(stream, crash.vehicle1_type, ',');
        std::getline(stream, crash.vehicle2_type, ',');
        std::getline(stream, crash.vehicle3_type, ',');
        std::getline(stream, crash.vehicle4_type, ',');
        std::getline(stream, crash.vehicle5_type, ',');

        crashes.push_back(crash);
    }

    collisions.close();
    return crashes;
}

int main() {
    auto crashes = parseData();

    std::cout << "Crash Date: " << (crashes[1].crash_date) << std::endl;
    std::cout << "Crash Time: " << (crashes[1].crash_time) << std::endl;
    std::cout << "On Street: " << (crashes[1].on_street_name) << std::endl;

    return 0;
}
