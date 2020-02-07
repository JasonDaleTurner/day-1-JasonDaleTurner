#include <iostream>
#include <string>

int main() {
	//Create an empty string to store the transliterated input in//
	std::string input_str{'\0'};
	
	//Open while loop to accept input and convert//
	char in_char{'x'};
	while(std::cin >> in_char){
		if (isdigit(in_char)) {
			switch(in_char){
				case 0:
					input_str.append("ZERO");
					break;
				case 1:
					input_str.append("ONE");
					break;
				case 2:
					input_str.append("TWO");
					break;
				case 3:
					input_str.append("THREE");
					break;
				case 4:
					input_str.append("FOUR");
					break;
				case 5:
					input_str.append("FIVE");
					break;
				case 6:
					input_str.append("SIX");
					break;
				case 7:
					input_str.append("SEVEN");
					break;
				case 8:
					input_str.append("EIGHT");
					break;
				case 9:
					input_str.append("NINE");
					break;
		} 
		else if (isalpha(in_char)){
			input_str.append(toupper(in_char));
		} 

		}
	}
	std::cout << input_str << std::endl;
}

