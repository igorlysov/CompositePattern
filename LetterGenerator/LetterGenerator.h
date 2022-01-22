//
// Created by мвидео on 22.01.2022.
//

#ifndef COMPOSITE_LETTERGENERATOR_H
#define COMPOSITE_LETTERGENERATOR_H

#include "IPasswordGenerator.h"

class LetterGenerator : public IPasswordGenerator {
private:
    std::pair<int, int> _sizes;
public:
    explicit LetterGenerator(int lowerSize, int upperSize) : _sizes(lowerSize, upperSize) {}
    std::string generate() override;
    std::string allowedChars() override;
    int length() override;
};


#endif //COMPOSITE_LETTERGENERATOR_H
