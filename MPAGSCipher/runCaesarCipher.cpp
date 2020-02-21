#include <iostream>
#include <string>
#include <vector>

#include "runCaesarCipher.hpp"

std::string runCaesarCipher(const std::string& inputText,
 const size_t key, 
 const bool encrypt){

/*
A function to apply the Caesar Cipher to the transliterated input

Takes a string input by reference, a key which indicates how far to shift the values,
and a bool which indicates if the string should be encrypted (+ve shift) or 
decrypted (-ve shift).

Returns the modified string

*/


 // Create the alphabet container and output string
	std::vector<char> alphabet = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
	const size_t alphabetSize = alphabet.size();
	const size_t truncatedKey {key % alphabetSize};
	std::string outputText{'\0'};

	if (encrypt == true){
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

      if ( origChar == alphabet[i] ) {

	// Apply the appropriate shift (depending on whether we're encrypting
	// or decrypting) and determine the new character
	// Can then break out of the loop over the alphabet
	if ( encrypt ) {
	  processedChar = alphabet[ (i + truncatedKey) % alphabetSize ];
	} else {
	  processedChar = alphabet[ (i + alphabetSize - truncatedKey) % alphabetSize ];
	}
	break;
      }
    }

    // Add the new character to the output text
    outputText += processedChar;
  }

  return outputText;
}
