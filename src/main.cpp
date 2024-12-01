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

        std::cout << "Crash Date: " << (crashes2["(40.667202, -73.8665)"].crash_date) << std::endl;
        std::cout << "Crash Time: " << (crashes2["(40.667202, -73.8665)"].crash_time) << std::endl;
        std::cout << "Borough: " <<(crashes2["(40.667202, -73.8665)"].borough) << std::endl;


    }
    else {
        std::cerr << "No data present in file" << std::endl;
    }

    return 0;
}
