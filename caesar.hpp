#pragma once

#include <string>

int correct_shift(int current, int shift, int min, int max);

void caesar_encode(std::string code, int shift);
void caesar_decode(std::string code, int shift);

void generic_caesar(std::string code);
