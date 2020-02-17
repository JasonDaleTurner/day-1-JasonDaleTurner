#ifndef MPAGSCIPHER_RUNCAESARCIPHER_HPP
#define MPAGSCIPHER_RUNCAESARCIPHER_HPP

#include "runCaesarCipher.hpp"
#include <string>

//Apply Caesar cipher to input string//
std::string runCaesarCipher(const std::string& inputText,
 const size_t key, 
 const bool encrypt);

#endif // MPAGSCIPHER_RUNCAESARCIPHER_HPP