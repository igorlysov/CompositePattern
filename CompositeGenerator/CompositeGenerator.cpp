//
// Created by мвидео on 22.01.2022.
//

#include "CompositeGenerator.h"

CompositeGenerator::~CompositeGenerator() {
    for (auto child : _children) {
        delete child;
    }
}

std::string CompositeGenerator::generate() {
    std::string result;
    int minLength = 0;

    /* Добавляем энтропии в генерацию случайных чисел */
    auto now = std::chrono::high_resolution_clock::now();
    std::mt19937 random_generator(now.time_since_epoch().count());

    for (auto child : _children) {
        result += child->generate();
        minLength += child->length();
    }

    std::string allowed = this->allowedChars();

    while (minLength < this->length()) {
        result += allowed[random_generator() % allowed.length()];
        minLength += 1;
    }

    if (minLength > this->_size) {
        std::cout << "Your length is invalid. Here is a password of minimum possible length:" << std::endl;
    }

    std::shuffle(result.begin(), result.end(), random_generator);
    return result;
}

void CompositeGenerator::add(IPasswordGenerator* generator) {
    _children.insert(generator);
}

void CompositeGenerator::remove(IPasswordGenerator* generator) {
    _children.erase(generator);
}

std::string CompositeGenerator::allowedChars() {
    std::string allowed;
    for (auto child : _children) {
        allowed += child->allowedChars();
    }
    return allowed;
}

int CompositeGenerator::length() {
    return _size;
}


