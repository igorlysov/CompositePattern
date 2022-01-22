//
// Created by мвидео on 22.01.2022.
//

#include "SymbolGenerator.h"

std::string SymbolGenerator::generate() {
    std::string allowedSymbols = allowedChars();
    std::string result;

    /* Добавляем энтропии в генерацию случайных чисел */
    auto now = std::chrono::high_resolution_clock::now();
    std::mt19937 random_generator(now.time_since_epoch().count());

    for (int i = 0; i <= length(); i++) {
        result += allowedSymbols[random_generator() % allowedSymbols.length()];
    }

    return result;
}

std::string SymbolGenerator::allowedChars() {
    return "!@#$%^&*";
}

int SymbolGenerator::length() {
    return _size;
}