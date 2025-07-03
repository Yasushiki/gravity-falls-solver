#include "atbash.hpp"
#include "global.hpp"

#include <iostream>
#include <string>

// A -> Z
// B -> Y
// ...
// Z -> A

void atbash(std::string code) {

  for(int i = 0; i < code.length(); i++) {
    
    if(code[i] >= MIN_UPPER && code[i] <= MAX_UPPER) {
      code[i] = REVERSE_ALPHABET[code[i] - MIN_UPPER]; 
    }
    else if(code[i] >= MIN_LOWER && code[i] <= MAX_LOWER) {
      code[i] = REVERSE_ALPHABET_LOWER[code[i] - MIN_LOWER];
    }
    else {
      continue;
    }
  }
  std::cout << code << "\n";
}
