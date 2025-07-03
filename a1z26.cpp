#include "a1z26.hpp"
#include "global.hpp"

#include <string>

void a1z26_encode(std::string code) {
  
  int current;
  int shift;
  int previous_was_a_letter = 0;

  for(int i=0; i < code.length(); i++) {
    

    current = code[i];

    // Upper case
    if(current >= MIN_UPPER && current <= MAX_UPPER) {
      shift = MIN_UPPER - 1;
    }
    
    // Lower case
    else if(current >= MIN_LOWER && current <= MAX_LOWER) {
      shift = MIN_LOWER - 1;
    }

    // Not a letter
    else {
      previous_was_a_letter = 0;
      std::cout << code[i];
      continue;
    }
    
    // If the code(not the variable) gets here, the current character is a letter
    // and if the last one was a letter (and not a blank space or something)
    // it prints a - before printing the letter
    
    if(previous_was_a_letter) {
      std::cout << "-";
    }

    std::cout << current - shift;
    previous_was_a_letter = 1;
  }

  std::cout << "\n";
}


void a1z26_decode(std::string code) {
  int number;
  
  while(!code.empty()) {
    
    // Checks if the current character is a number or not    
    if(code[0] >= 48 && code[0] <= 57) {
      // Try to take the first number of the string and cast it to int
      number = stoi(code);
    
      // Check if the number have 1 or 2 digits
      if(number < 10) {
        // Erase the first character of the string
        code.erase(0, 1);
      } else {
        // Erase the first two characters of the string
        code.erase(0, 2);
      }
      
      std::cout << ALPHABET[number - 1];
      
      // This is necessary because 1-2 -> ab, so the - must be ignored
      // if the previous case was a number
      if(!code.empty() && code[0] == '-') {
        code.erase(0, 1);
      }
    } else {
      std::cout << code[0];
      code.erase(0, 1);
    }
  }
  
  std::cout << "\n";
}

