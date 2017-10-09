/*
ROOT Macro.		-->		[Draw 2D Histogram with two Options]

ROOT-course 	--> 	Exercise 5 Day02:
-- 	Define 2D histogram
-- 	Draw with option 'colz'
-- 	Draw with option 'surf2'
*/

void histogram_2D_root(){
	
	// Defining 2D histogram
	TH2F* hist2d = new TH2F("hist2d", "2D-Histogram; x-values; y-values; entries",
		100, -5, 5, 100, -10, 10
	);
	
	// Define 2D function to randomly fill histogramm
	TF2* func2d = new TF2("func2d", "TMath::Gaus(x,0,2) * TMath::Gaus(y,-2,4)");
	
	// Randomly fill the histogram
	hist2d->FillRandom("func2d", 100000);
	
	// Create canvas
	TCanvas* c = new TCanvas("c", "Canvas for 2D histograms", 1000, 500);
	c->Divide(2);
	
	// Draw histogram with the two options to canvas
	c->cd(1);
	hist2d->DrawCopy("colz");
	
	c->cd(2);
	hist2d->Draw("surf2");
	
	// More style required:
	// Margins of titles, Color scheme, etc.
	// In principle it worked!
} 