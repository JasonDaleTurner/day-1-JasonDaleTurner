#ifndef MPAGSCIPHER_PROCESSCOMMANDLINE_HPP
#define MPAGSCIPHER_PROCESSCOMMANDLINE_HPP

#include <string>
#include <vector>
#include "cipherMode.hpp"
#include "cipherType.hpp"

//Declare new structure to simplify parsing command line
struct ProgramSettings
{
	bool helpRequested;
	bool versionRequested;
 	std::string input_filename;
 	std::string output_filename;
 	std::string key;
 	cipherMode mode;
 	cipherType type;
};


//Parse command line arguments
bool processCommandLine(
 	const std::vector<std::string>& args,
 	ProgramSettings& settings);

#endif // MPAGSCIPHER_PROCESSCOMMANDLINE_HPP