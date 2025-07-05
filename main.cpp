#include <iostream>
#include <string>

//#include "caesar.hpp"
//#include "a1z26.hpp"
//#include "atbash.hpp"
#include "vigenere.hpp"

int main() {
  std::string code;
  std::string key;

  std::cout << "Digite o código: ";  
  std::getline(std::cin, code);
  

  std::cout << "Digite a chave: ";
  std::cin >> key;
 
//  int option;
//  std::cout << "Digite 1 para codificar e 2 para decodificar. ";
//  std::cin >> option;
  
//  if(option == 1) {
      std::cout << "\nCódigo decodificado: \n";
      vigenere_decode(code, key);
    
//  } else {
//    std::cout << "\nCódigo decodificado: \n";
//    atbash_decode(code);
//  }
  
  return 0;
}
