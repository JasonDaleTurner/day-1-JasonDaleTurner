#ifndef MPAGSCIPHER_CIPHERMODE_HPP
#define MPAGSCIPHER_CIPHERMODE_HPP

#include <string>
/**
 * \file cipherMode.cpp
 * \brief Comment
 */


/**
 * \brief Should the cipher be used to encrypt or decrypt
 */
enum class cipherMode{
	encrypt, ///< Encrypt mode
	decrypt ///< Decrypt mode
};

#endif // MPAGSCIPHER_CIPHERMODE_HPP