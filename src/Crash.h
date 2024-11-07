//
// Created by Vishakh Surendran on 11/6/2024.
//

#ifndef CRASH_H
#define CRASH_H

#include <iostream>
#include <string>
#include <vector>

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

#endif //CRASH_H
