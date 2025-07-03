#include <iostream>

//#include "caesar.hpp"
//#include "a1z26.hpp"
#include "atbash.hpp"


int main() {
  std::string code;
  
  std::cout << "Digite o código: ";  
  std::getline(std::cin, code);
  
 
//  int option;
//  std::cout << "Digite 1 para codificar e 2 para decodificar. ";
//  std::cin >> option;
  
//  if(option == 1) {
      std::cout << "\nCódigo (de)codificado: \n";
      atbash(code);
    
//  } else {
//    std::cout << "\nCódigo decodificado: \n";
//    atbash_decode(code);
//  }
  
  return 0;
}
