/*
Program.		-->		[Calculating mean and standard deviation of given numbers]

ROOT-course 	--> 	Exercise 1 Day01:
Program that reads in numbers of type  (double) and
calculates/returns the mean and standard deviation (sigma) of the numbers.

To be compiled with g++ mean_sigma.cpp -o mean_sigma -Wall
*/

#include <iostream>								// for in- and output
#include <cmath>								// for math operations, e.g. sqrt
#include <string>								// enables using string
#include <sstream>								// enables conversion from string to numbers

using namespace std;							// using the std namespace globally

// declaring functions
double StringToDouble(string number_string);	// converts a number in string to "real" double
int CountNumbers(string number_string);			// gets the quantity of numbers
void StringToArray(string number_string, double* array, int array_length);	// get numbers in array
void CalcMeanSigma(double* array, int array_length, double &mean, double &sigma, double &err_mean);
string DoubleToString(double &number);

//defining functions
double StringToDouble(string number_string){

	double double_out;							// declaring output variable
	istringstream string_in;					// declaring input stream

	string_in.str(number_string);				// filling stream content with number_string
	string_in >> double_out;					// giving stream content to double_out

	return double_out;							// return number value
}

int CountNumbers(string number_string){

	int counter = 0;							// declaring counter variable

	for(int i = 0; abs(i) < number_string.length(); ++i){	// loop over number string

		if(number_string[i] == '\n'){			// count quantity of '\n' characters = quantity of numbers
			++counter;
		}
		else{ continue; }
	}

	return counter;
}

void StringToArray(string number_string, double* array, int array_length){

	int position_start = 0;						// declare first position Variable
	int position_end = 0;						// declare second position variable
	string single_number;						// declare string for a single double number


	for(int i = 0; i <= abs(array_length - 1); ++i){			// loop over entire array_length/#numbers

		// find iteratively position of next linebreak '\n'
		position_end = number_string.find('\n', position_start);

		// extract single number from number_string
		single_number = number_string.substr(position_start, position_end - position_start);

		// convert single number to double and write to array
		array[i] = StringToDouble(single_number);

		//set new start position
		position_start = position_end + 1;
	}
}

void CalcMeanSigma(double* array, int array_length, double &mean, double &sigma, double &err_mean){

	// calculating mean and sigma
	mean = 0;							// initialising mean
	sigma = 0;						// initialising sigma

	for(int i = 0; i < array_length; ++i){
		mean += array[i];
	}

	cout << "The sum of the numbers is: " << mean << endl;
	cout << " " << endl;
	mean /= array_length;

	for(int i = 0; i < array_length; ++i){
		sigma += (array[i] - mean) * (array[i] - mean);
	}

	if(array_length == 1){
		sigma = 0;
	}
	else if(array_length == 0){
		mean = 0;
		cout << "Nothing to calculate. Quitting ..." << endl;
	}
	else{
		sigma = sqrt(sigma / (array_length-1));
	}
	err_mean = sigma / sqrt(array_length);
}

string DoubleToString(double &number){

	string string_output;
	std::ostringstream string_out;					// declaring output stream

	string_out << number;							// filling stream content with number
	string_output = string_out.str();	// giving stream content to string_output

	return string_output;							// return number value
}

///////////////////////////////////////////////////////////////////////////////
int main(){

	// Description
	cout << "welcome to Mean-Sigma-Calculator!" << endl;
	cout << " " << endl;
	cout << "This is a programm to calculate the mean and" << endl;
	cout << "the standard deviation (Sigma) of some entered values." << endl;
	cout << " " << endl;
	cout << "Do you wish to continue?" << endl;
	cout << "(yes: y or no: n)" << endl;

	// reading input numbers
	string input;								// declaring "empty" input string

	for( ; ; ){
		getline(cin, input);
		if(input == "y" || input == "Y"){
			cout << " "	<< endl;
			break;
		}
		else if(input == "n" || input == "N"){
			cout << " " << endl;
			cout << "Quitting programm ..." << endl;
			return 0;
		}
		else{
			cout << " "	<< endl;
			cout << "Error. Invalid token." << endl;
			continue;
		}
	}

	string numbers = " ";						// declaring "empty" number string

	for( ; ; ){									// endless for loop for continuous reading
		cout << "Please enter a number or c to continue:" << endl;
		getline(cin, input);					// read number and put it on input

		if(input == "c" || input == "C"){
			break;
		}
		else if(input == ""){					// skip empty insertations
			continue;
		}
		else{
		input = input + "\n";					// add linebreak after inserted number
		numbers.insert(							// append numbers
			(numbers.length() - 1),
			input
		);
		}
	}

	numbers = numbers.erase(numbers.find(' ', 0), 1);			// erase white space in numbers

	int quantity;								// declare quantity variable for quantity of numbers
	quantity = CountNumbers(numbers);			// assign #numbers to quantity

	cout << " " << endl;
	cout << "You entered the following " << quantity << " numbers:" << endl;
	cout << numbers << endl;
	//end of input section

	// writing numbers to array
	double number_array[quantity];				// declare number_array of size #numbers
	StringToArray(numbers, number_array, quantity);

	// calculating mean
	double mean;
	double sigma;
	double err_mean;
	CalcMeanSigma(number_array, quantity, mean, sigma, err_mean);

	//display results

	string mean_string;
	string err_mean_string;
	string sigma_string;
	string space;
	string hline;

	mean_string = "|  Mean = " + DoubleToString(mean) + "|";
	err_mean_string = "|  Error = " + DoubleToString(err_mean) + "|";
	sigma_string = "|  Sigma = " + DoubleToString(sigma) + "|";
	space = "|                       |";
	hline = "-------------------------";

	for(int i = mean_string.length(); abs(i) < space.length(); ++i){
		mean_string.insert(abs(mean_string.length() - 1), " ");
	}
	for(int i = err_mean_string.length(); abs(i) < space.length(); ++i){
		err_mean_string.insert(abs(err_mean_string.length() - 1), " ");
	}
	for(int i = sigma_string.length(); abs(i) < space.length(); ++i){
		sigma_string.insert(abs(sigma_string.length() - 1), " ");
	}

	cout << hline << endl;
	cout << space << endl;
	cout << mean_string << endl;
	cout << err_mean_string << endl;
	cout << space << endl;
	cout << sigma_string << endl;
	cout << space << endl;
	cout << hline << endl;


	return 0;
}
