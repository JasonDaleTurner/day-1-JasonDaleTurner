#include <iostream>
#include <vector>
#include <string>

#include "processCommandLine.hpp"
#include "cipherMode.hpp"

bool processCommandLine(
 	const std::vector<std::string>& args,
 	ProgramSettings& settings) {

	/*
	A function to parse command line arguments checking for options and flags
	and responding appropriately

	Input is a vector of strings which are the command line arguments separated
	by white space. Also takes reference to ProgramSettings structure to store 
	options and arguments.

	Return is a bool which indicates successful parsing.

	*/

	for (size_t i{0}; i < args.size(); i++){
		
		if (args.at(i) == "-h"){
			settings.helpRequested = 1;

		} else if (args.at(i) == "--help"){
			settings.helpRequested = 1;

		} else if (args.at(i) == "--version"){
			settings.versionRequested = 1;

		} else if (args.at(i) == "-i"){
			if (i+1 > args.size()-1 ){
				std::cout << "Input filename not provided" << std::endl;

			} else if (args.at(i+1)[0] == '-'){
				std::cout << "Input file not provided" << std::endl;

			} else {
				settings.input_filename = args.at(i+1);
			}
		} else if (args.at(i) == "-o"){
			if (i+1 > args.size()-1 ){
				std::cout << "Output filename not provided" << std::endl;
				return false;

			} else if (args.at(i+1)[0] == '-'){
				std::cout << "Outputfile file not provided" << std::endl;
				return false;

			} else {
				settings.output_filename = args.at(i+1);
			}
		} else if (args.at(i) == "-k"){
			if (i+1 > args.size()-1 ){
				std::cout << "Key value not provided" << std::endl;

			} else if (args.at(i+1)[0] == '-'){
				std::cout << "Key value not provided" << std::endl;

			} else {
				settings.key += stoi(args.at(i+1));
			}
		} else if (args.at(i) == "--encrypt"){
			settings.mode = cipherMode::encrypt;
		} else if (args.at(i) == "--decrypt"){
			settings.mode = cipherMode::decrypt;
		}

	}
return 1;
}