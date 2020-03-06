#ifndef MPAGSCIPHER_CIPHERTYPE_HPP
#define MPAGSCIPHER_CIPHERTYPE_HPP

#include <string>
/**
 * \file cipherMode.cpp
 * \brief Comment
 */


/**
 * \brief Should the cipher be used to encrypt or decrypt
 */
enum class cipherType{
	caeser, ///< Caeser Cipher mode
	playfair ///< PlayfairCipher mode
};

#endif // MPAGSCIPHER_CIPHERTYPE_HPP