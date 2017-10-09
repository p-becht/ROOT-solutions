/*
ROOT Macro.		-->		[Writing, reading histogram from file]

ROOT-course 	--> 	Exercise 1 Day03:
-- 	Create histogram Gaussian mean = 2, sigma = 0.2
--	Store it to file
--	Close file
--	Open file and check content
--	Create another histogram Gaussian mean = 3, sigma = 2.5
--	Store second histogram on it (without overwriting the other)
--	Open file and retrieve both histograms
--	Draw both on same Canvas using different line colors
--	create a Legend 
*/

#include<iostream>

void writing_reading_root(){
	cout << "first_gauss()" << endl;
	cout << "second_gauss()" << endl;
	cout << "retrieve_histograms_and_plot()" << endl;
}

void first_gauss(){
	
	// Creating first histogram
	TH1F* hist1 = new TH1F("hist1", "1^{st} Gaussian; Random Numbers; Counts",
		200, -3, 7
	);
	
	// Fill histogram
	TF1* Gauss = new TF1("Gauss", "gaus", -3, 7);
	Gauss->SetParameters(1, 2, 0.2);
	hist1->FillRandom("Gauss", 2000);
	
	// Create and open file
	TFile file("./solutions/file.root", "recreate");
	
	// Writing histogram to file
	hist1->Write();
	
	// Closing file
	file.Close();
}

void second_gauss(){
	
	// Creating second histogram
	TH1F* hist2 = new TH1F("hist2", "2^{nd} Gaussian; Random Numbers; Counts",
		200, -3, 7
	);
	
	// Fill histogram
	TF1* Gauss = new TF1("Gauss", "gaus", -3, 7);
	Gauss->SetParameters(1, 3, 2.5);
	hist2->FillRandom("Gauss", 2500);
	
	// Open file for writing, without overwriting
	TFile file("./solutions/file.root", "update");				// Option "read" is default
	
	// Writing hist2 to file
	hist2->Write();
	
	// Checking file content and close
	file.ls();
	file.Close();
}

void retrieve_histograms_and_plot(){
	
	// Open file for reading
	TFile file("./solutions/file.root", "read");
	
	// Cast back file content
	TH1F* hist1 = static_cast<TH1F*>(file.Get("hist1"));
	TH1F* hist2 = static_cast<TH1F*>(file.Get("hist2"));
	
	// Create Canvas for plotting
	TCanvas* c = new TCanvas("c", "Random Gaussians", 700, 500);
	gPad->SetTicks(); 								// Ticks for all four axes
	
	// Style
	hist1->SetLineWidth(2);
	hist1->SetLineColor(kRed);
	hist1->SetFillStyle(3001);
	hist1->SetFillColor(kRed-7);
	
	hist2->SetLineWidth(2);
	hist2->SetLineColor(kBlue);
	hist2->SetFillStyle(3001);
	hist2->SetFillColor(kBlue-7);
	
	// Create Legend
	TLegend* legend = new TLegend(0.7, 0.7, 0.9, 0.9);
	legend->AddEntry(hist1,"1^{st} Gaussian", "f");
	legend->AddEntry(hist2, "2^{nd} Gaussian", "f");
	
	// Draw everything
	gStyle->SetOptStat(false);
	hist1->SetTitle("1^{st} and 2^{nd} Gaussian histogram");
	hist1->DrawCopy();							// Copy always good, works more often
	hist2->DrawCopy("same");
	legend->Draw("same");
	gPad->Update();								// Somehow this does the job
												// May use it frequently
	file.Close();
} 