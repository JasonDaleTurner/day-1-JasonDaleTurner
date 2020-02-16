#include <iostream>
#include <string>

//Function definition//
std::string transformChar( const char in_char ){
	
	/*
	A function to take alphanumeric input and convert to uppercase.

	Input is a char
	Return is transliterated string

	Digits are converted to text representations and
	non alphanumeric characters are ignored

	*/




	//Create an empty string to store the transliterated input in//
	std::string input_str{"\0"};

	//Test for possible digits and convert to alpha//

	if (isdigit(in_char)) {
			switch(in_char){
				case '0':
					input_str += "ZERO";
					break;
				case '1':
					input_str += "ONE";
					break;
				case '2':
					input_str += "TWO";
					break;
				case '3':
					input_str += "THREE";
					break;
				case '4':
					input_str += "FOUR";
					break;
				case '5':
					input_str += "FIVE";
					break;
				case '6':
					input_str += "SIX";
					break;
				case '7':
					input_str += "SEVEN";
					break;
				case '8':
					input_str += "EIGHT";
					break;
				case '9':
					input_str += "NINE";
					break;
				}			
			} else if (isalpha(in_char)){
					input_str += toupper(in_char);

			}
	return input_str;
}