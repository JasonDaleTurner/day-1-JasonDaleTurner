#include <iostream>
#include <vector>
#include <string>

bool processCommandLine(
 	const std::vector<std::string>& args,
 	bool& helpRequested, //If help requested then provide help and return false to break from main //
 	bool& versionRequested,//If help requested then provide help and return false to break from main //
 	std::string& input_filename,
 	std::string& output_filename) {

	/*
	A function to parse command line arguments checking for options and flags
	and responding appropriately

	Input is a vector of strings which are the command line arguments separated
	by white space. Also takes references to bools for help and version requests
	that are declared in main and also input_filename and output_filename declared
	in main.

	Output is a bool which indicates successful parsing.

	*/

	for (size_t i{0}; i < args.size(); i++){
		
		if (args.at(i) == "-h"){
			helpRequested = 1;

		} else if (args.at(i) == "--help"){
			helpRequested = 1;

		} else if (args.at(i) == "--version"){
			versionRequested = 1;

		} else if (args.at(i) == "-i"){
			if (i+1 > args.size()-1 ){
				std::cout << "Input filename not provided" << std::endl;

			} else if (args.at(i+1)[0] == '-'){
				std::cout << "Input file not provided" << std::endl;

			} else {
				input_filename += args.at(i+1);
			}
		} else if (args.at(i) == "-o"){
			if (i+1 > args.size()-1 ){
				std::cout << "Output filename not provided" << std::endl;
				return false;

			} else if (args.at(i+1)[0] == '-'){
				std::cout << "Outputfile file not provided" << std::endl;
				return false;

			} else {
				output_filename += args.at(i+1);
			}
		}
	}
return 1;
}