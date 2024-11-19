//
// Created by Vishakh Surendran on 11/6/2024.
//


#include <iostream>
#include <fstream>
#include <string>
#include "Crash.h"

int main() {
    auto crashes = parseData();

    if (!crashes.empty()) {
        std::cout << "Incident 15554: " << std::endl;
        std::cout << "Crash Date: " << (crashes[15555].crash_date) << std::endl;
        std::cout << "Crash Time: " << (crashes[15555].crash_time) << std::endl;
        std::cout << "Borough: " << (crashes[15555].borough) << std::endl;

        std::cout << "Incident 8: " << std::endl;
        std::cout << "Crash Date: " << (crashes[7].crash_date) << std::endl;
        std::cout << "Crash Time: " << (crashes[7].crash_time) << std::endl;
        std::cout << "Borough: " << (crashes[7].borough) << std::endl;
    }
    else {
        std::cerr << "Not enough data in file" << std::endl;
    }

    return 0;
}
