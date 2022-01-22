//
// Created by мвидео on 22.01.2022.
//

#ifndef COMPOSITE_COMPOSITEGENERATOR_H
#define COMPOSITE_COMPOSITEGENERATOR_H

#include "IPasswordGenerator.h"

class CompositeGenerator : public IPasswordGenerator {
private:
    /* Множество, так как нам ни к чему повторения */
    std::set<IPasswordGenerator*> _children;
    int _size;
public:
    explicit CompositeGenerator(int size) : _size(size), _children() {}
    ~CompositeGenerator();
    std::string generate() override;
    std::string allowedChars() override;
    int length() override;
    void add(IPasswordGenerator*) override;
    void remove(IPasswordGenerator*) override;
};


#endif //COMPOSITE_COMPOSITEGENERATOR_H
