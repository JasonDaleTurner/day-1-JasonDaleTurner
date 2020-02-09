#include <iostream>
#include <string>

int main() {
	//Create an empty string to store the transliterated input in//
	std::string input_str{"\0"};
	
	/*Open while loop to accept input and convert
	lowercase to upper, check for numerics and
	convert to strings, and append to the output string
	to send to stdout*/
	char in_char{'\0'};
	std::string zero{"ZERO"};
	while(std::cin >> in_char){
		if (isdigit(in_char)) {
			switch(in_char){
				case '0':
					input_str += zero;
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
	}
std::cout << input_str << std::endl;
}

