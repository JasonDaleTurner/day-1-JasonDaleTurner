#include <iostream>
#include <string>
#include <vector>

#include "runCaesarCipher.hpp"

CaesarCipher::CaesarCipher(const int key_value) : key_{key_value}{}
CaesarCipher::CaesarCipher(const std::string key_value) : key_{stoi(key_value)}{}

void CaesarCipher::applyCipher(const std::string& inputText, const bool encryption){
	const size_t alphabetSize = alphabet_.size();
	const size_t truncatedKey {key_ % alphabetSize};

	if (encryption == true){
		std::cout << std::endl;
		std::cout << "Running Caeser encryption" << std::endl;
	} else {
		std::cout << std::endl;
		std::cout << "Running Caeser decryption" << std::endl;	
	}

  // Loop over the input text
  char processedChar {'x'};
  for ( const auto& origChar : inputText ) {

    // For each character in the input text, find the corresponding position in
    // the alphabet by using an indexed loop over the alphabet container
    for ( size_t i{0}; i < alphabetSize; ++i ) {

      if ( origChar == alphabet_[i] ) {

	// Apply the appropriate shift (depending on whether we're encrypting
	// or decrypting) and determine the new character
	// Can then break out of the loop over the alphabet
	if ( encryption ) {
	  processedChar = alphabet_[ (i + truncatedKey) % alphabetSize ];
	} else {
	  processedChar = alphabet_[ (i + alphabetSize - truncatedKey) % alphabetSize ];
	}
	break;
      }
    }

    // Add the new character to the output text
    outputText_ += processedChar;
  }
}