#include <iostream>
#include <string>
int main() {
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

	//Further practice with variables//
	int i_a{5};
	double dub_a{2.2};

	std::cout << i_a*dub_a << std::endl;

	//Divide double by int//
	std::cout << "Divide double by int" << std::endl;
	std::cout << dub_a/i_a << std::endl;
	//Divide int by double//
	std::cout << "Divide int by double" << std::endl;
	std::cout << i_a/dub_a << std::endl;
	//Divide int by int//
	std::cout << "Divide int by int" << std::endl;
	std::cout << i_a/a << std::endl;

	//Create char, assign to position in string and output//
	char let{'a'};
	msg[1]=let;
	std::cout << msg << std::endl;

	/*Exploring if declarations can be the result of operations
	on variables*/
	int add1{3};
	int add2{3};


	int test{add1 + add2};
	std::cout << test << std::endl;

}