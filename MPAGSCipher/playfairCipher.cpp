#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>

#include "playfairCipher.hpp"
#include "cipherMode.hpp"


//Class constructors
PlayfairCipher::PlayfairCipher(const std::string& key_value) {
	setKey(key_value);
}

void PlayfairCipher::setKey(const std::string& key_value){
	key_ = key_value;
	// Append the alphabet
	key_.append("ABCDEFGHIJKLMNOPQRSTUVWXYZ");

	// Make sure the key is upper case
	std::transform (key_.begin(), key_.end(), key_.begin(), ::toupper);
	
	// Remove non-alpha characters
	auto iter = std::remove(key_.begin(), key_.end(), [] (const char& let) {return !isalpha(let)});
	key_.erase(iter, key_.end());

	// Change J -> I
	std::transform (key_.begin(), key_.end(), key_.begin(), [] (const char& letChange) -> char {if(letChange == 'J'){return 'I'}});

	// Remove duplicated letters
	auto iter2 = std::remove(key_.begin(), key_.end(), [&] (const char& newLet) {
		if(encLets_.find(newLet) == std::string::npos){
		encLets_.append(newLet);
		return false;

		} else {
			return true;

		}
	
	});
	key_.erase(iter2, key_.end());


	// Store the coords of each letter


	// Store the playfair cipher key map
}

std::string PlayfairCipher::applyCipher(const std::string& inputText, const CipherMode cipherMode ) const{
	// Change J → I
	// If repeated chars in a digraph add an X or Q if XX
	// if the size of input is odd, add a trailing Z
	// Loop over the input in Digraphs
	//   - Find the coords in the grid for each digraph
	//   - Apply the rules to these coords to get 'new' coords
	//   - Find the letter associated with the new coords
	// return the textreturn input


}