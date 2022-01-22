//
// Created by мвидео on 22.01.2022.
//

#ifndef COMPOSITE_DIGITGENERATOR_H
#define COMPOSITE_DIGITGENERATOR_H

#include "IPasswordGenerator.h"

class DigitGenerator : public IPasswordGenerator {
private:
    int _size;
public:
    explicit DigitGenerator(int size) : _size(size) {}
    std::string generate() override;
    std::string allowedChars() override;
    int length() override;
};


#endif //COMPOSITE_DIGITGENERATOR_H
