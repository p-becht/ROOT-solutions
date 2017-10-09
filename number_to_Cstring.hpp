/*
Header:
-->	Number to String
*/

#include <string>
#include <sstream>


// overload function to enable all common number types


// for Double
const char* NumberToCstring(double const number){
	
	std::string cppstring;
	std::ostringstream string_out;			// declaring output stream

	string_out << number;					// filling stream content with number
	cppstring = string_out.str();			// giving stream content to string_output
	
	cppstring = cppstring + "\0";
	
	// creating char array of string length +1
	char cstring[cppstring.length()];
	
	for(int i = 0; i < cppstring.length(); ++i){
		cstring[i] = cppstring[i];			// writing string content to array
	}
	
	const char* cstringp = cstring;

	return cstringp;							// return number value
}

// something is wrong with the number format
// --> read again the chapter for "functions and arrays" in "C++ Programmierung"