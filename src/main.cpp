//
// Created by Vishakh Surendran on 11/6/2024.
//

#include <iostream>
#include <fstream>
#include <string>
#include "Crash.h"

int main() {
   
auto crashes2 = parseToMap();

    if (!crashes2.empty()) {
        std::cout << "Incident at :(40.667202, -73.8665)" << std::endl;

        search_Location("(40.667202, -73.8665)", crashes2);
        totals_borough("Queens", crashes2);

    }
    else {
        std::cerr << "No data present in file" << std::endl;
    }

    return 0;
}
