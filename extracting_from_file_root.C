/*
ROOT Macro.		-->		[Opening ROOT-file and extract content]

ROOT-course 	--> 	Exercise 2 Day03:
-- 	Open the file 'example_code/day03/vertex.root'
--	Check the content
--	Write a macro opening the file, 
	getting the Objects and 
	draw them on different pads of a canvas
-- 	Save the canvas in a root file
--	Open the file and draw the canvas
*/

#include <iostream>

#include "TROOT.h"
#include "TRint.h"
#include "TFile.h"
#include "TCollection.h"				// Usuage of TIter
#include "TKey.h"
#include "TH1D.h"
#include "TH2F.h"
// better not compile, esp. ROOT 6 -> default compilation of example_code
// just produces errors, all needed includes are there

// Declaration of functions (except for main)
void open_checking_file();
void retrieving_objects_from_file(TCanvas*);
void save_canvas(TCanvas*);

// Definition of functions // main function
void extracting_from_file_root(){
	
	// List functions of macro
	open_checking_file();
	
	// Make canvas
	TCanvas* c = new TCanvas("canvas", "canvas", 900, 300);
	c->Divide(3);
	
	retrieving_objects_from_file(c);
	
	save_canvas(c);
}

void open_checking_file(){
	
	// Open file
	TFile file("./example_code/day03/vertex.root");
	
	// Get all important information via file's key list
	TIter next(file.GetListOfKeys());	// Initialize an iteration over list of keys
	TKey* key;							// Create pointer to key
	
	cout << " " << endl;
	cout << "================================================================" << endl;
	cout << "Keys (names) and Class (types) of the file's objects:" << endl;
	cout << " " << endl;
	while((key = static_cast <TKey*> (next()))){
		const char* name = key->GetName();
		const char* type = key->GetClassName();
		cout << Form("Key: %s, Type: %s", name, type) << endl;
	}
	cout << "================================================================" << endl;
	cout << " " << endl;
	file.Close();
}

void retrieving_objects_from_file(TCanvas* c){
	
	// Open file
	TFile file("./example_code/day03/vertex.root");
	
	// Getting names and types of all objects and cast back, draw
	TIter next(file.GetListOfKeys());	// Initialize an iteration over list of keys
	TKey* key;							// Create pointer to key
	Int_t counter = 1;
	while((key = static_cast <TKey*> (next()))){
		const char* name = key->GetName();
		const char* type = key->GetClassName();
		if(strcmp(type, "TH1D")){
			TH1D* hist_1D = static_cast <TH1D*> (file.Get(name));
			c->cd(counter);
			
			hist_1D->SetLineWidth(2);
			hist_1D->SetLineColor(kRed);
			hist_1D->SetFillColor(kGray);
			
			hist_1D->DrawCopy();
			gPad->SetTicks();
			gPad->RedrawAxis();
			gPad->Update();
			
			++counter;
		}
		else if(strcmp(type, "TH2F")){
			TH2F* hist_2D = static_cast <TH2F*> (file.Get(name));
			c->cd(counter);
			
			hist_2D->SetLineWidth(2);
			hist_2D->SetLineColor(kRed);
			hist_2D->SetFillColor(kGray);
			
			hist_2D->DrawCopy("colz");
			gPad->SetTicks();
			gPad->RedrawAxis();
			gPad->Update();
			
			++counter;
		}
		else continue;
	}
}

void save_canvas(TCanvas* c){
	cout << "Do you want to save the canvas now?" << endl;
	cout << "yes: y" << endl;
	cout << "no: n" << endl;
	
	char input;
	cin >> input;
	if(input == 'y'){
		c->SaveAs("~/ROOT/solutions/vertex_extracted.pdf");
		cout << "Saved file." << endl;
	}
	else if(input == 'n'){
		cout << "Quitting ..." << endl;
	}
	else{
		cout << "Error. Invalid token." << endl;
	}
}

