//
// Created by Vishakh Surendran on 12/1/2024.
//

#include "HashTable.h"

HashTable::HashTable() : table(TABLE_SIZE) {}

std::vector<std::list<Crash>> HashTable::parseDataToTable() {
    std::ifstream collisions("../src/Motor_Vehicle_Collisions.csv");
    std::string line;

    if (!collisions.is_open()) {
        std::cerr << "Error opening collisions file" << std::endl;
        return table;
    }

    std::getline(collisions, line);

    while (std::getline(collisions, line)) {
        Crash crash;
        std::string temp;
        std::istringstream stream(line);

        std::getline(stream, crash.crash_date, ',');
        std::getline(stream, crash.crash_time, ',');
        std::getline(stream, crash.borough, ',');
        std::getline(stream, crash.zip_code, ',');
        std::getline(stream, crash.latitude, ',');
        std::getline(stream, crash.longitude, ',');
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

        insert(crash);
    }

    collisions.close();
    return table;
}

// Insert a crash record
void HashTable::insert(const Crash& data) {
    std::string key = data.location.empty() ? "0000" : data.location;
    size_t index = customHash(key);
    table[index].push_back(data);
}

// Search for records by location
std::list<Crash> HashTable::search(const std::string& location) const {
    std::string key = location.empty() ? "0000" : location;
    size_t index = customHash(key);
    return table[index];
}

// Display all data in the hash table
void HashTable::displayAll() const {
    for (size_t i = 0; i < TABLE_SIZE; ++i) {
        if (!table[i].empty()) {
            std::cout << "Index " << i << std::endl;
            for (const auto& crash_instance : table[i]) {
                std::cout << "  - " << crash_instance.crash_date << ", " << crash_instance.crash_time
                          << ", " << crash_instance.location << ", " << crash_instance.num_persons_injured
                          << " injured, " << crash_instance.num_persons_killed << " killed\n";
            }
        }
    }
}

void HashTable::displayCrashes(const std::string& location) const {
    auto result = search(location);

    if (!result.empty()) {
        std::cout << "Crashes at " << location << std::endl;

        for (const auto& crash_instance : result) {
            std::cout << "  - " << crash_instance.crash_date << ", " << crash_instance.crash_time
                << ", " << crash_instance.location << ", " << crash_instance.num_persons_injured
                << " injured, " << crash_instance.num_persons_killed << " killed\n";
        }
    }
}

void HashTable::displayCrashesByBorough(const std::string& borough, std::ostream& output) const {
    int count = 0;

    for (size_t i = 0; i < TABLE_SIZE; ++i) {
        if (!table[i].empty()) {
            for (const auto& crash_instance : table[i]) {
                if (crash_instance.borough == borough) {
                    count += 1;
                    output << count << ". " << crash_instance.crash_date << ", " << crash_instance.crash_time
                           << ", " << crash_instance.location << ", " << crash_instance.num_persons_injured
                           << " injured, " << crash_instance.num_persons_killed << " killed\n";
                }
            }
        }
    }

    if (count == 0) {
        output << "No crashes found for " << borough << ".\n";
    }
}

void HashTable::getTotalsByBorough(const std::string& borough) const {
    int total_accidents = 0;
    int total_injured = 0;
    int total_killed = 0;

    for (size_t i = 0; i < TABLE_SIZE; ++i) {
        if (!table[i].empty()) {
            for (const auto& crash_instance : table[i]) {
                if (borough == crash_instance.borough) {
                    total_accidents += 1;
                    try{
                        total_injured += std::stoi(crash_instance.num_persons_injured);
                    }   catch (const std::exception&) {
                        continue;
                        }
                    try{
                        total_killed += std::stoi(crash_instance.num_persons_killed);
                    }   catch (const std::exception&) {
                        continue;
                        }
                }
            }
        }
    }

    std::cout << "Total Accidents: " << total_accidents << std::endl;
    std::cout << "Total Injured: " << total_injured <<std::endl;
    std::cout << "Total Killed: " << total_killed<<std::endl;
}
