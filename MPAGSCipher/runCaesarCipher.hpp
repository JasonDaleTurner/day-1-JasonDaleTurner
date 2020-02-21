#ifndef MPAGSCIPHER_RUNCAESARCIPHER_HPP
#define MPAGSCIPHER_RUNCAESARCIPHER_HPP

#include <string>


class CaesarCipher {
public:
	explicit CaesarCipher(const int key_value);

	explicit CaesarCipher(const std::string key_value);

	void applyCipher(const std::string& inputText, const bool encryption);

	std::string outputText_{'\0'};

private:
	int key_;
	const std::vector<char> alphabet_ = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
};

//Apply Caesar cipher to input string//
std::string runCaesarCipher(const std::string& inputText,
 const int key, 
 const bool encrypt);

#endif // MPAGSCIPHER_RUNCAESARCIPHER_HPP