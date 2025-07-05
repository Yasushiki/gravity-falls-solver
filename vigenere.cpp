#include "vigenere.hpp"
#include "global.hpp"

#include <iostream>
#include <string>

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

void vigenere_encode(std::string code, std::string key) {
 
  int letter;
  int actual_shift;
  int j = 0;
  int shift;

  for(int i = 0; i < code.length(); i++) {

    letter = code[i];
    
    shift = key[j] - MIN_LOWER;

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
    
    j++;

    if(j >= key.length()) {
      j = 0;
    }
        
    code[i] = (char)(code[i] + (char)(actual_shift)); 

  }
  std::cout << code << "\n";

}

void vigenere_decode(std::string code, std::string key) {

  int letter;
  int actual_shift;
  int j = 0;
  int shift;

  for(int i = 0; i < code.length(); i++) {

    letter = code[i];
    
    shift = key[j] - MIN_LOWER;

    // Uppercase letter
    if(letter >= MIN_UPPER && letter <= MAX_UPPER) {
      actual_shift = correct_shift(letter, -shift, MIN_UPPER, MAX_UPPER);
      
    }
    
    // Lowercase letter
    else if(letter >= MIN_LOWER && letter <= MAX_LOWER) {
      actual_shift = correct_shift(letter, -shift, MIN_LOWER, MAX_LOWER);
    }
    
    // Is not a letter
    else {
      continue;
    }
    
    j++;

    if(j >= key.length()) {
      j = 0;
    }
        
    code[i] = (char)(code[i] + (char)(actual_shift)); 

  }
  std::cout << code << "\n";


}
