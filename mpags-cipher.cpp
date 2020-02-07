#include <iostream>
#include <string>
int main()
{
	//This is a comment
	/*This is a 
	Multiline comment */
	std::cout << "Hello World!\n";

	/*Declare a variable, modify, and output to stdout
	for practice purposes*/
	int a{3};
	int c{0};

	c=a*2;
	std::cout << "Initial integer value: " << a << std::endl;
	std::cout << "Multiplied by 2: " << c << std::endl;

	/*Practice declaring double and output to stdout*/
	double d{2.2};
	std::cout << "Double value: " << d << std::endl;

	/*Practice initalising new integer with double
	and noting warning*/
	int e{d};
	std::cout << "Narrowed double: " << e << std::endl;

	/*Practice initisalising constant double*/
	const double c_dub{3.4};
	std::cout << "Constant double: " << c_dub << std::endl;

	/*Create a constant integer and attempt to edit*/
	int f{4};
	std::cout << "Initial integer value: " << f << std::endl;
	f += 1;
	std::cout << "Plus equals 1 to integer value: " << f << std::endl;

	//Practice with string types//
	std::string msg {"Hello"};
	std::cout << msg << std::endl;
}