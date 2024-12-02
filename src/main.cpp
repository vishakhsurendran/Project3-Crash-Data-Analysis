//
// Created by Vishakh Surendran on 11/6/2024.
//

#include <iostream>
#include <fstream>
#include <string>
#include "Crash.h"
#include "HashTable.h"

int main() {
   
    // auto crashes2 = parseToMap();
    auto crashes3 = new HashTable();
    crashes3->parseDataToTable();

    /*
    if (!crashes2.empty()) {
        std::cout << "Incident at :(40.667202, -73.8665)" << std::endl;

        search_Location("(40.667202, -73.8665)", crashes2);
        totals_borough("Queens", crashes2);

    }
    else {
        std::cerr << "No data present in file" << std::endl;
    }
    */

    crashes3->displayCrashes("(40.667202, -73.8665)");

    crashes3->getTotalsByBorough("BROOKLYN");
    return 0;
}
