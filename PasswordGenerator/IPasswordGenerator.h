//
// Created by мвидео on 22.01.2022.
//

#ifndef COMPOSITE_IPASSWORDGENERATOR_H
#define COMPOSITE_IPASSWORDGENERATOR_H

#include <string>
#include <random>
#include <utility>
#include <algorithm>
#include <set>
#include <chrono>
#include <iostream>

class IPasswordGenerator {
public:
    virtual std::string generate() = 0;
    virtual std::string allowedChars() = 0;
    virtual int length() = 0;
    virtual void add(IPasswordGenerator*) {};
    virtual void remove(IPasswordGenerator*) {};
};


#endif //COMPOSITE_IPASSWORDGENERATOR_H
