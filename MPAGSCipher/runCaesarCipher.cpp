#include <iostream>
#include <string>

std::string runCaesarCipher(const std::string& inputText,
 const size_t key, 
 const bool encrypt){
 // Create the alphabet container and output string
	std::string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	const int alpha_len = 25;
	std::string outputText{'\0'};

 // Loop over the input text
	for(size_t i{0}; i < inputText.size(); ++i){
		char input_char = inputText[i];

		// For each character find the corresponding position in the alphabet
		int found = alphabet.find(input_char);

		// Apply the shift (+ve or –ve depending on encrypt/decrypt)
		// to the position, handling correctly potential wrap-around
		// Determine the new character and add it to the output string
		if (encrypt == true) {
			if (found + key > alpha_len) {
				int index = ((found+key) % (alpha_len));
				outputText += alphabet[index];
			} else {
				int index = found+key;
				outputText += alphabet[index];
			}

		} else if (encrypt == false) {
			if (found - key < unsigned int a{0}) {
				signed int new_key = found - key;
				int index = (alpha_len) + new_key;
				outputText += alphabet[index];
			} else {
				int index = found - key;
				outputText += alphabet[index];
			}

		}

	}

// Finally (after the loop), return the output string
return outputText;

}
