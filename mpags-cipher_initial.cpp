//Standard library includes//
#include <iostream>
#include <string>
#include <vector>
#include <fstream>

//Our library headers
#include "TransformChar.hpp" 

/*ProcessCmdLine, pass list of cmdLinArg, 
then do the following:
pass
	reference to bool if help req,
	reference to bool if version req, 
	reference to placeholder string inputinput filename, 
	reference to placeholder string outputfilename.

In main add if statements to test for help or version book
and to then act appropriately before break from main. Also 
add false bools for help and version to pass reference
*/


int main(int argc, char* argv[]) {

	std::string output_str{"\0"};
	char in_char{'\0'};
	std::string input_filename{"\0"};
	std::string output_filename{"\0"};

	/*Read in the command line arguments and respond appropriately*/
	const std::vector<std::string> cmdLineArgs {argv, argv+argc};


	for (size_t i{0}; i < cmdLineArgs.size(); i++){
		
		if (cmdLineArgs.at(i) == "-h"){
			std::cout << "You need help" << std::endl;

		} else if (cmdLineArgs.at(i) == "--help"){
			std::cout << "You need help" << std::endl;

		} else if (cmdLineArgs.at(i) == "--version"){
			std::cout << "mpags-cipher Version 0.1" << std::endl;

		} else if (cmdLineArgs.at(i) == "-i"){
			if (i+1 > cmdLineArgs.size()-1 ){
				std::cout << "Input filename not provided" << std::endl;

			} else if (cmdLineArgs.at(i+1)[0] == '-'){
				std::cout << "Input file not provided" << std::endl;

			} else {
				input_filename += cmdLineArgs.at(i+1);
			}
		} else if (cmdLineArgs.at(i) == "-o"){
			if (i+1 > cmdLineArgs.size()-1 ){
				std::cout << "Output filename not provided" << std::endl;
				return false;

			} else if (cmdLineArgs.at(i+1)[0] == '-'){
				std::cout << "Outputfile file not provided" << std::endl;
				return false;

			} else {
				output_filename += cmdLineArgs.at(i+1);
			}
		}
	}


	/*Check if input file exists and can be accessed, if so read in and run through TransformChar,
	if not default to std::cin	and add chars to string before moving on the checking output method.

	Check if output file exists and can be accessed. If so write output str (which has been transliterated)
	to file, if not print to std::cout.

	*/

	if (input_filename != "\0"){
		std::ifstream in_file{input_filename};
		bool ok_to_read = in_file.good();
		if((int) ok_to_read != 0){
			while(in_file>> in_char){
				output_str += transformChar(in_char);
			}
		} else{
			std::cout << "Unable to read input file, reading from stdcin instead." << std::endl;
			while(std::cin >> in_char){
				output_str += transformChar(in_char);
			}
		}
	} else {
		std::cout << "Reading from stdout: " << std::endl;
		while(std::cin >> in_char){
				output_str += transformChar(in_char);
		}
	}



	if (output_filename != "\0"){
		std::ofstream out_file{output_filename};
		bool ok_to_write = out_file.good();
		if((int) ok_to_write != 0){
			out_file << output_str;

		} else{
			std::cout << std::endl;
			std::cout << "Unable to write to output file, writing to stdout instead." << std::endl;
			std::cout << output_str << std::endl;

		}
	} else{
			std::cout << std::endl;
			std::cout << "Writing to stdout:" << std::endl;
			std::cout << output_str << std::endl;

	} 
}
