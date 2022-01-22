//
// Created by мвидео on 22.01.2022.
//

#include "LetterGenerator.h"

std::string LetterGenerator::generate() {
    std::string allowedLetters = allowedChars();
    std::string result;

    /* Добавляем энтропии в генерацию случайных чисел */
    auto now = std::chrono::high_resolution_clock::now();
    std::mt19937 random_generator(now.time_since_epoch().count());

    for (int i = 0; i < _sizes.first; i++) {
        result += allowedLetters[random_generator() % (allowedLetters.length() / 2)];
    }
    for (int i = 0; i < _sizes.second; i++) {
        result += allowedLetters[random_generator() % (allowedLetters.length() - allowedLetters.length() / 2) + allowedLetters.length() / 2];
    }

    std::shuffle(result.begin(), result.end(), random_generator);
    return result;
}

std::string LetterGenerator::allowedChars() {
    return "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSSTUVWXYZ";
}

int LetterGenerator::length() {
    return _sizes.first + _sizes.second;
}