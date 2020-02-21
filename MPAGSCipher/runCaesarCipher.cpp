#include <iostream>
#include <string>
#include <vector>

#include "runCaesarCipher.hpp"
#include "cipherMode.hpp"



//Class constructors
CaesarCipher::CaesarCipher(const int key_value) : key_{key_value}{}
CaesarCipher::CaesarCipher(const std::string key_value) : key_{stoi(key_value)}{}

/*Class method to apply the Caeser cipher to a string passed to the class

Takes an input uppercase alphabetical string and applies Caeser cipher encryption/decryption
to the string according to the key value initialised during class instantiation.
Stores string as class member outputText_

*/

void CaesarCipher::applyCipher(const std::string& inputText, const cipherMode& mode_select){
	const size_t alphabetSize = alphabet_.size();
	const size_t truncatedKey {key_ % alphabetSize};

	if (mode_select == cipherMode::encrypt){
		std::cout << std::endl;
		std::cout << "Running Caeser encryption" << std::endl;
	} else if (mode_select == cipherMode::decrypt){
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
	if ( mode_select == cipherMode::encrypt ) {
	  processedChar = alphabet_[ (i + truncatedKey) % alphabetSize ];
	} else if (mode_select == cipherMode::decrypt){
	  processedChar = alphabet_[ (i + alphabetSize - truncatedKey) % alphabetSize ];
	}
	break;
      }
    }

    // Add the new character to the output text
    outputText_ += processedChar;
  }
}