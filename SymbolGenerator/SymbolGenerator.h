//
// Created by мвидео on 22.01.2022.
//

#ifndef COMPOSITE_SYMBOLGENERATOR_H
#define COMPOSITE_SYMBOLGENERATOR_H

#include "IPasswordGenerator.h"

class SymbolGenerator : public IPasswordGenerator {
private:
    int _size;
public:
    explicit SymbolGenerator(int size) : _size(size) {}
    std::string generate() override;
    std::string allowedChars() override;
    int length() override;
};


#endif //COMPOSITE_SYMBOLGENERATOR_H
