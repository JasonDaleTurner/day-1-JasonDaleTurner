#ifndef MPAGSCIPHER_RUNCAESARCIPHER_HPP
#define MPAGSCIPHER_RUNCAESARCIPHER_HPP

#include <string>
#include "cipherMode.hpp"

/**
*	CaesarCipher is a class for the encryption/decryption of a uppercase alphabetical string.
*	It has a key value which is set upon instantiation.
*	To use it run;
* \code{.cpp}
	CaesarCipher myCipher{key}
* \endcode
* The key value is an integer detaling the shift to apply using the cipher.
*/
class CaesarCipher {
public:

	explicit CaesarCipher(const int key_value);
	explicit CaesarCipher(const std::string key_value);

	void applyCipher(const std::string& inputText, const cipherMode& mode_select);

	std::string outputText_{'\0'};

private:
	int key_;
	const std::vector<char> alphabet_ = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
};


#endif // MPAGSCIPHER_RUNCAESARCIPHER_HPP