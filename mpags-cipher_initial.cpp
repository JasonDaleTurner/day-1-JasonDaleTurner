//Standard library includes//
#include <iostream>
#include <string>
#include <vector>
#include <fstream>

//Our library headers
#include "transformChar.hpp"
#include "processCommandLine.hpp"
#include "runCaesarCipher.hpp"
#include "cipherMode.hpp"

int main(int argc, char* argv[]) {

	//Declare variables used throughout and passed by reference to functions//
	std::string output_str{""};
	std::string final_str{""};
	char in_char{'\0'};

	/*Read in the command line arguments and respond appropriately*/
	const std::vector<std::string> cmdLineArgs {argv, argv+argc};
	ProgramSettings progset{0, 0, "", "", 0, cipherMode::encrypt};

	bool proc_success{processCommandLine(cmdLineArgs,
		progset)};

	if (progset.helpRequested){
		std::cout << "You need help" << std::endl;

	} else if (progset.versionRequested) {
		std::cout << "mpags-cipher Version 0.1" << std::endl;
	} else if (proc_success == 0){ 
		std::cout << "Command line argument parsing fail" << std::endl;

	} else {

		/*
		Check if input file has been specified, and exists and can be accessed, if so read in and run through transformChar,
		if not default to std::cin	and add chars to string before moving on the checking output method.
		*/

		if (progset.input_filename != "\0"){
			std::ifstream in_file{progset.input_filename};
			if(in_file.good()){
				while(in_file>> in_char){
					output_str += transformChar(in_char);
				}
				in_file.close();
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
		CaesarCipher cipher{progset.key};


		if (progset.key){
			cipher.applyCipher(output_str, progset.mode);
			final_str = cipher.outputText_;
			// final_str = runCaesarCipher(output_str, progset.key, progset.encrypt);
		} else {
			std::cout <<  std::endl;
			std::cout << "Running with no encryption/decryption:"<< std::endl;
			final_str = output_str;
		}



		/*
		Check if output file has been specified and can be accessed. If so write output str (which has been transliterated)
		to file, if not print to std::cout.
		*/

		if (progset.output_filename != "\0"){
			std::ofstream out_file{progset.output_filename};
			if(out_file.good()){
				out_file << final_str << std::endl;
				out_file.close();

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
