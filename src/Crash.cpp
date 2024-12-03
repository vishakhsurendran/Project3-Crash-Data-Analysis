//
// Created by Vishakh Surendran on 11/6/2024.
//
#include <algorithm>
#include <iostream>
#include "Crash.h"
//Map Implemented by Conner 11/30/2024
std::multimap<std::string, Crash> parseToMap(){
 std::multimap<std::string,Crash> crashes;
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
        std::string temp;
        std::getline(stream, crash.crash_date, ',');
        std::getline(stream, crash.crash_time, ',');
        std::getline(stream, crash.borough, ',');
        std::getline(stream, crash.zip_code, ',');
        std::getline(stream, crash.latitude, ',');
        if (crash.latitude == ""){
            crash.latitude = "0";
        }
        std::getline(stream, crash.longitude, ',');
        if (crash.longitude == " "){
            crash.longitude = "0";
        }
        //gets location data from latitude and longitude
        crash.location = "("+crash.latitude+", "+crash.longitude+")";
        //skips extra two columns from location data section
        std::getline(stream, temp, ',');
        std::getline(stream, temp, ',');
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
         crashes.insert(std::make_pair(crash.location,crash));
        if (crash.vehicle1 != ""){
            crash.num_vehicles_involved =1;
            if (crash.vehicle2 != ""){
            crash.num_vehicles_involved +=1;
                if (crash.vehicle3 != ""){
                crash.num_vehicles_involved +=1;
                    if (crash.vehicle4 != ""){
                    crash.num_vehicles_involved +=1;
                        if (crash.vehicle5 != ""){
                        crash.num_vehicles_involved +=1;
                        }
                    }
                }
            }
        }
    }
    collisions.close();
    return crashes;



}



void print_crash(Crash crash){
    std::cout << "Borough: " << crash.borough<< std::endl;
    std::cout << "Date: "<<crash.crash_date<< std::endl;
    std::cout << "Time: " << crash.crash_time<< std::endl;
    std::cout << "Zip Code: "<<crash.zip_code<< std::endl;
    std::cout << "Number of people injured: "<<crash.num_persons_injured<< std::endl;
    std::cout << "Number of people killed: "<< crash.num_persons_killed<< std::endl;
    std::cout << "Number of vehicles involved: "<< crash.num_vehicles_involved << std::endl;
}
void search_Location(std::string location, std::multimap<std::string,Crash> crashes){
    auto range = crashes.equal_range(location);
    for(auto iter = range.first; iter !=range.second; ++iter)
    print_crash(iter->second);
}



void totals_borough(std::string borough, std::multimap<std::string,Crash> crashes){
    std::transform(borough.begin(), borough.end(), borough.begin(), ::toupper);
    int total_accidents = 0;
    int total_injured = 0;
    int total_killed = 0;
    for(auto iter = crashes.begin(); iter != crashes.end(); ++iter){
        if (iter->second.borough == borough){
            total_accidents += 1;
            try{
                total_injured += std::stoi(iter->second.num_persons_injured);
            }   catch (const std::exception&) {
                continue;
            }
            try{
               total_killed += std::stoi(iter->second.num_persons_killed);
            }   catch (const std::exception&) {
                continue;
            }   
                
        }
    }
    std::cout << "Total Accidents: " << total_accidents << std::endl;
    std::cout << "Total Injured: " << total_injured <<std::endl;
    std::cout << "Total Killed: " << total_killed<<std::endl;
}