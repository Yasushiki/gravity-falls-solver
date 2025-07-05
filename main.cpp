#include <iostream>
#include <string>
#include <stdlib.h>

#include "caesar.hpp"
#include "a1z26.hpp"
#include "atbash.hpp"
#include "vigenere.hpp"

int main() {
  
  int cipher = 0;
  int type = 0;
  std::string code;
  
  system("clear");

  std::cout << "Enter the code: ";
  std::getline(std::cin, code);
  std::cout << "\n";
  
  while(type < 1 || type > 2) {
    system("clear");
    std::cout << "Code: " << code << "\n";
    std::cout << "Do you want to encode or decode?\n1 - encode\n2 - decode\n> ";
    std::cin >> type;
  }


  while(cipher < 1 || cipher > 4) {
    system("clear");
    std::cout << "Code: " << code << "\n" << (type == 1 ? "Encoding\n" : "Decoding\n");
    std::cout << "Choose a cipher.\n1 - Caesar\n2 - A1Z26\n3 - Atbash\n4 - Vigenère\n> ";
    std::cin >> cipher;
  }
  
  system("clear");

  switch(cipher) {
    // Caesar
    case 1:
      int shift;
      std::cout << "Enter the shift (if you don't know, use 0): ";
      std::cin >> shift;
      system("clear");
      if(!shift) {
        std::cout << "All the combinations:\n";
        generic_caesar(code);
      } else {
        if(type == 1) {
          std::cout << "Encoded with Caesar Cipher - shift " << shift << "\n";
          caesar_encode(code, shift);
        } else {
          std::cout << "Decoded with Caesar Cipher - shift " << shift << "\n";
          caesar_decode(code, shift);
        }
      }
      break;
    
    //A1Z26
    case 2:
      if(type == 1) {
        std::cout << "Encoded with A1Z26\n";
        a1z26_encode(code);
      } else {
        std::cout << "Decoded with A1Z26\n";
        a1z26_decode(code);
      }
      break;

    // Atbash
    case 3:
      std::cout << "Code: " << code << "\n" << "Atbash\n";
      atbash(code);
      break;

    // Vigenère
    case 4:
      std::string key;
      std::cout << "Enter the key: ";
      std::cin >> key;
      system("clear");
      if(type == 1) {
        std::cout << "Encoded with Vigenère Cipher - Key: " << key << "\n";
        vigenere_encode(code, key);
      } else {
        std::cout << "Decoded with Vigenère Cipher - Key: " << key << "\n";
        vigenere_decode(code, key);
      }
      break;
  }
   
  return 0;
}
