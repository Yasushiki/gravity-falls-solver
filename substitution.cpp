#include "substitution.hpp"
#include "global.hpp"

#include <iostring>
#include <string>
#include <vector>

void substitute(std::string code, std::vector key) {
  
  int shift;
  int current;  
  
  for(int i = 0; i < code.length(); i++) {
    current = (int)code[i];
    
    // Upper case
    if(current >= MIN_UPPER && current <= MAX_UPPER) {
     shift = MIN_UPPER;
    }
    
    // Lower case
    else if(current >= MIN_LOWER && current <= MAX_LOWER) {
      shift = MIN_LOWER;
    }

    // Not a letter
    else {
      continue;
    }
    
    code[i] = key[char(current)-shift];
  } 
  
  std::cout << code << "\n";
}





