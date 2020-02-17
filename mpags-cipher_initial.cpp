//Standard library includes//
#include <iostream>
#include <string>
#include <vector>
#include <fstream>

//Our library headers
#include "TransformChar.hpp"
#include "processCommandLine.hpp"
#include "runCaesarCipher.hpp"

int main(int argc, char* argv[]) {

	//Declare variable used throughout and passed by reference to functions//
	std::string output_str{"\0"};
	std::string final_str{"\0"};
	char in_char{'\0'};

	std::string input_filename{"\0"};
	std::string output_filename{"\0"};
	bool helpRequested{0};
	bool versionRequested{0};
	bool proc_success{0};
	int key{0};
	bool encrypt{0};


	/*Read in the command line arguments and respond appropriately*/
	const std::vector<std::string> cmdLineArgs {argv, argv+argc};

	proc_success = processCommandLine(cmdLineArgs,
		helpRequested,
		versionRequested,
		input_filename,
		output_filename,
		key,
		encrypt);

	if (helpRequested == 1){
		std::cout << "You need help" << std::endl;

	} else if (versionRequested == 1) {
		std::cout << "mpags-cipher Version 0.1" << std::endl;
	} else if (proc_success == 0){ 
		std::cout << "Command line argument parsing fail" << std::endl;

	} else {

		/*
		Check if input file has been specified, and exists and can be accessed, if so read in and run through transformChar,
		if not default to std::cin	and add chars to string before moving on the checking output method.
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



		//Run the Caeser cipher. If key is == 0 then don't run cipher and return transliterated string

		if (key != 0){
			final_str = runCaesarCipher(output_str, key, encrypt);
		} else {
			final_str = output_str;
		}



		/*
		Check if output file has been specified and can be accessed. If so write output str (which has been transliterated)
		to file, if not print to std::cout.
		*/

		if (output_filename != "\0"){
			std::ofstream out_file{output_filename};
			bool ok_to_write = out_file.good();
			if((int) ok_to_write != 0){
				out_file << final_str;

			} else{
				std::cout << std::endl;
				std::cout << "Unable to write to output file, writing to stdout instead." << std::endl;
				std::cout << final_str << std::endl;

			}
		} else{
			std::cout << std::endl;
			std::cout << "Writing to stdout:" << std::endl;
			std::cout << final_str << std::endl;

		} 


	}

}
