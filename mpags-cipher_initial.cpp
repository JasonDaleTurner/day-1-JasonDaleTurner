#include <iostream>
#include <string>
#include <vector>

std::string transformChar( const char in_char ) {
	//Create an empty string to store the transliterated input in//
	std::string input_str{"\0"};

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

bool processCommandLine(
	const std::vector<std::string>& args,
	bool& helpRequested,
	bool& versionRequested,
	std::string& inputFileName,
	std::string& outputFileName){

}




int main(int argc, char* argv[]) {

	/*Read in the command line arguments and respond appropriately*/
	const std::vector<std::string> cmdLineArgs {argv, argv+argc};

	std::string input_file{"\0"};

	for (size_t i{0}; i < cmdLineArgs.size(); i++){
		
		if (cmdLineArgs.at(i) == "-h"){
			std::cout << "You need help" << std::endl;

		} else if (cmdLineArgs.at(i) == "--help"){
			std::cout << "You need help" << std::endl;

		} else if (cmdLineArgs.at(i) == "--version"){
			std::cout << "mpags-cipher Version 0.1" << std::endl;

		} else if (cmdLineArgs.at(i) == "-i"){
			if (i+1 > cmdLineArgs.size()-1 ){
				std::cout << "Input file not provided" << std::endl;

			} else if (cmdLineArgs.at(i+1)[0] == '-'){
				std::cout << "Input file not provided" << std::endl;

			} else {
				input_file += cmdLineArgs.at(i+1);
			}
		}
	}


	std::cout << "Type text and hit control + D when finished:" << std::endl;
	
	/*Open while loop to accept input and convert
	lowercase to upper, check for numerics and
	convert to strings, and append to the output string
	to send to stdout*/
	std::string output_str{"\0"};
	char in_char{'\0'};
	
	while(std::cin >> in_char){
		output_str += transformChar(in_char);


	}
std::cout <<  std::endl;
std::cout << output_str << std::endl;

}