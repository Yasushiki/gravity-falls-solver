#include "caesar.hpp"
#include "global.hpp"

#include <iostream>

int correct_shift(int current, int shift, int min, int max) {
  if((current + shift) > max) {
    if((current + shift%26 - 26) < min) {
      return shift%26;
    }
    return shift%26-26;
  }
  
  if((current + shift) < min) {
    if((current + shift%26 + 26) > max) {
      return shift%26;
    }
    
    return shift%26+26;
  }
  
  return shift;
} 

void caesar_encode(std::string code, int shift) {

  int letter;
  int actual_shift;

  for(int i = 0; i < code.length(); i++) {

    letter = (int)code[i];

    // Uppercase letter
    if(letter >= MIN_UPPER && letter <= MAX_UPPER) {
      actual_shift = correct_shift(letter, shift, MIN_UPPER, MAX_UPPER);
      
    }
    
    // Lowercase letter
    else if(letter >= MIN_LOWER && letter <= MAX_LOWER) {
      actual_shift = correct_shift(letter, shift, MIN_LOWER, MAX_LOWER);
    }
    
    // Is not a letter
    else {
      continue;
    }
        
    code[i] = (char)(code[i] + (char)(actual_shift)); 
    

  }
  std::cout << code << "\n";
}

void caesar_decode(std::string code, int shift) {
  caesar_encode(code, -shift);
}

void generic_caesar(std::string code) {
  for(int i = 1; i < 26; i++) {
    caesar_encode(code, i);
  }
}
