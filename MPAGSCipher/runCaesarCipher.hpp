#ifndef MPAGSCIPHER_RUNCAESARCIPHER_HPP
#define MPAGSCIPHER_RUNCAESARCIPHER_HPP

#include <string>
#include "cipherMode.hpp"

/**
*	CaesarCipher is a class for the encryption/decryption of a uppercase alphabetical string.
*	It has a key value which is set upon instantiation.
*	To use it 
*/
class CaesarCipher {
public:
	/**
	*	Create a new instance of CaesarCipher with a specific key value
	*	\param key_value is the key
	*/
	explicit CaesarCipher(const int key_value);
	explicit CaesarCipher(const std::string key_value);
	
	/**
	*	Run the encryption/decryption on an input string
	*	\param inputText is the input string
	*	\param encryption is a bool to indicate encryption (true) or decryption (false)
	*	\return Nothing is returned, encrypted string stored in \param outputText
	*/
	void applyCipher(const std::string& inputText, const cipherMode& mode_select);

	std::string outputText_{'\0'};

private:
	int key_;
	const std::vector<char> alphabet_ = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
};


#endif // MPAGSCIPHER_RUNCAESARCIPHER_HPP