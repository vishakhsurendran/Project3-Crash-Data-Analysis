//
// Created by Vishakh Surendran on 11/6/2024.
//

#include <iomanip>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "Crash.h"

using namespace std;

struct Crash {
    std::string crash_date;
    std::string crash_time;
    std::string borough;
    std::string zip_code;
    std::string latitude;
    std::string longitude;
    std::string location;
    std::string on_street_name;
    std::string cross_street_name;
    std::string off_street_name;
    std::string num_persons_injured;
    std::string num_persons_killed;
    std::string num_pedestrians_injured;
    std::string num_pedestrians_killed;
    std::string num_cyclists_injured;
    std::string num_cyclists_killed;
    std::string num_motorists_injured;
    std::string num_motorists_killed;
    std::string vehicle1;
    std::string vehicle2;
    std::string vehicle3;
    std::string vehicle4;
    std::string vehicle5;
    std::string collision_ID;
    std::string vehicle1_type;
    std::string vehicle2_type;
    std::string vehicle3_type;
    std::string vehicle4_type;
    std::string vehicle5_type;
};

std::vector<Crash> parseData() {
    std::vector<Crash> crashes;
    std::ifstream collisions("Motor_Vehicle_Collisions.csv");
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

int main() {
    auto crashes = parseData();

    if (crashes.size() > 1) {
        std::cout << "Crash Date: " << (crashes[1].crash_date) << std::endl;
    }
    else {
        std::cerr << "Not enough data in file" << std::endl;
    }

    return 0;
}
