//
// Created by Vishakh Surendran on 12/1/2024.
//

#ifndef HASHTABLE_H
#define HASHTABLE_H
#include <iostream>
#include <vector>
#include <list>
#include <string>
#include "Crash.h"

class HashTable {
private:
    static constexpr int TABLE_SIZE = 2132400; // Size of the hash table
    std::vector<std::list<Crash>> table;

    // hash function
    static size_t customHash(const std::string& key) {
        unsigned long hash = 0;
        for (char ch : key) {
            hash = (hash * 31 + ch) % TABLE_SIZE;
        }
        return hash;
    }

public:
    HashTable();
    std::vector<std::list<Crash>> parseDataToTable();
    void insert(const Crash& data);
    std::list<Crash> search(const std::string& location) const;
    void display() const;
};

#endif //HASHTABLE_H
