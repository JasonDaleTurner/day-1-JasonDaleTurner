#ifndef MPAGSCIPHER_PLAYFAIRCIPHER_HPP
#define MPAGSCIPHER_PLAYFAIRCIPHER_HPP

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include "cipherMode.hpp"

/**
*	PlayfairCipher is a class for the encryption/decryption of a uppercase alphabetical string.
*	It has a key value which is set using the setKey function.
*	To use it run;
* \code{.cpp}
	PlayfairCipher myCipher{};
* \endcode
* The key should be a string.
*/
class PlayfairCipher {
public:

	explicit PlayfairCipher(const std::string& key_value);

	void applyCipher(const std::string& inputText, const cipherMode& mode_select);

	void setKey(const std::string& key_value);

	std::string outputText_{'\0'};
	

private:
	std::string key_;
	std::string encLets_{""};
	
	using Str2IntMap = std::map<std::pair, std::string>
	Str2IntMap encMap_{};
	Str2IntMap decMap_{};


};

#endif // MPAGSCIPHER_PLAYFAIRCIPHER_HPP