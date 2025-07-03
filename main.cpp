#include <iostream>

//#include "caesar.hpp"
#include "a1z26.hpp"

int main() {
  std::string code;
  
  std::cout << "Digite o código: ";  
  std::getline(std::cin, code);
  
 
  int option;
  std::cout << "Digite 1 para codificar e 2 para decodificar. ";
  std::cin >> option;
  
  if(option == 1) {
    std::cout << "\nCódigo codificado: \n";
    a1z26_encode(code);
    
  } else {
    std::cout << "\nCódigo decodificado: \n";
    a1z26_decode(code);
  }
  
  return 0;
}
