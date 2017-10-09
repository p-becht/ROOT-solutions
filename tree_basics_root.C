/*
ROOT Macro.		-->		[Writing data to, store and draw from TTrees]

ROOT-course 	--> 	Exercise 1 Day04:
-- 	Write Data in 'example_code/day04/vertex.dat' to a TTree and save it
--	Draw the data from the tree using cuts
*/

#include <TROOT.h>
#include <TRint.h>
#include <TFile.h>
#include <TString.h>
#include <TTree.h>

#include <iostream>

// Declaring functions /////////////////////////////////////////////////////////////////////

void WriteDataToTree(TString, TString);

////////////////////////////////////////////////////////////////////////////////////////////

void tree_basics_root(){
	
	// Defining destination and source
	TString destination = "./solutions/tree_file.root";
	TString source = "./example_code/day04/vertex.dat";
	
	// Calling writer functions
	WriteDataToTree(destination, source);
	
}

// Defining functions //////////////////////////////////////////////////////////////////////

void WriteDataToTree(TString file_path, TString data_path){
	
	// Creating a file to store tree
	TFile* tree_file = new TFile(file_path.Data(), "recreate");
	cout << " " << endl;
	cout << "===================================================================" << endl;
	cout << "Created destination file with path:" << endl;
	cout << file_path.Data() << endl;
	cout << " " << endl;
	
	// Creating a tree to store the data
	TTree tree("tree", "Data Tree");
	cout << "Created TTree tree." << endl;
	cout << " " << endl;
	
	// Writing data (white space seperated) to the tree
	tree.ReadFile(data_path.Data(), "x/D : y/D : z/D");
	cout << "Read the following data file to tree:" << endl;
	cout << data_path.Data() << endl;
	cout << " " << endl;
	
	// Checking the tree's content
	tree.Print();
	cout << "===================================================================" << endl;
	cout << " " << endl;
	
	// Write tree to file
	tree.Write();
	
	// Close the file
	tree_file -> Close();
}

////////////////////////////////////////////////////////////////////////////////////////////

void DrawDataFromTree(){
	
}