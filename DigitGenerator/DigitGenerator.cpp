//
// Created by мвидео on 22.01.2022.
//

#include "DigitGenerator.h"

std::string DigitGenerator::generate() {
    std::string allowedDigits = allowedChars();
    std::string result;

    /* Добавляем энтропии в генерацию случайных чисел */
    auto now = std::chrono::high_resolution_clock::now();
    std::mt19937 random_generator(now.time_since_epoch().count());

    for (int i = 0; i < length(); i++) {
        result += allowedDigits[random_generator() % allowedDigits.length()];
    }

    return result;
}

std::string DigitGenerator::allowedChars() {
    return "0123456789";
}

int DigitGenerator::length() {
    return _size;
}