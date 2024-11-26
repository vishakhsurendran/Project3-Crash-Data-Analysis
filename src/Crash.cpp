//
// Created by Vishakh Surendran on 11/6/2024.
//

#include "Crash.h"

std::vector<Crash> parseData() {
    std::vector<Crash> crashes;
    std::ifstream collisions("../src/Motor_Vehicle_Collisions.csv");
    std::string line;

    if (!collisions.is_open()) {
        std::cerr << "Error opening collisions file" << std::endl;
        return crashes;
    }

    std::getline(collisions, line);

    while (std::getline(collisions, line)) {
        Crash crash;
        std::istringstream stream(line);

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