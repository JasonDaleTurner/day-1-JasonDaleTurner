#ifndef MPAGSCIPHER_PROCESSCOMMANDLINE_HPP
#define MPAGSCIPHER_PROCESSCOMMANDLINE_HPP

#include "processCommandLine.hpp"

//Parse command line arguments//
bool processCommandLine(
 	const std::vector<std::string>& args,
 	bool& helpRequested,
 	bool& versionRequested,
 	std::string& input_filename,
 	std::string& output_filename);

#endif // MPAGSCIPHER_PROCESSCOMMANDLINE_HPP