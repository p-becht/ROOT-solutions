/*
ROOT Macro.		-->		[gStyle to change automatted legends]

ROOT-course 	--> 	Exercise 5 Day03:
-- 	Create histogram
--	Change information in the statistics box using gStyle->SetOptStat(...)
--	Take a former Fit
--	Use gStyle->SetOptFit(...) to display fit results
*/

#include <iostream>

void gStyle_root(){
	
	// histogram
	// define histogram to fill in random numbers
	Int_t no_of_bins = 100;
	TH1F* histo = new TH1F("Histogram", "Double Gaussian; Random Numbers; Counts",
						   no_of_bins, -10, 10);
	
	// defining two Gaussians with different mean and sigma
	TF1* gauss1 = new TF1("gauss1", "gaus", -10, 10);
	TF1* gauss2 = new TF1("gauss2", "gaus", -10, 10);
	
	// set parameters for the Gaussians
	gauss1->SetParameters(1.0, -4, 1.3);	// 'yield', 'mean', 'sigma'
	gauss2->SetParameters(1.0, 3, 2.5);
	
	// fill random values for both Gaussians in the histogram
	histo->FillRandom("gauss1", 20000);
	histo->FillRandom("gauss2", 10000);
	
	// Change Options via gStyle --> See class documentation of TStyle
	gStyle -> SetOptStat("neiMR");
	
	// Draw
	TCanvas* c = new TCanvas("c", "Solution Canvas", 1000, 500);
	
	c->Divide(2,1,0.05);
	c->cd(1);
	gPad->SetTicks();
	
	histo->SetLineWidth(1);
	histo->SetLineColor(kBlue);
	histo->SetMarkerStyle(33);
	histo->SetMarkerSize(1);
	histo->SetMarkerColor(kGray+2);
	histo->GetYaxis()->SetTitleOffset(1.7);
	
	histo -> DrawCopy("HIST");
	
	c->cd(2);
	
	// Taking former fit of the same histogram
	// defining the fit function
	TF1* fitfunc = new TF1("fitfunc", "gaus(0)+gaus(3)", -10, -10);	//parameter start ()
	
	// set initial parameter values
	Double_t yield1 = 100.;					// scaling factor, no information about it 
	Double_t yield2 = 100.;
	Double_t mean1 = -6;
	Double_t mean2 = 8;
	Double_t sigma1 = 0.3;
	Double_t sigma2 = 1;
	
	fitfunc->SetParameter(0, yield1);
	fitfunc->SetParameter(1, mean1);
	fitfunc->SetParameter(2, sigma1);
	fitfunc->SetParameter(3, yield2);
	fitfunc->SetParameter(4, mean2);
	fitfunc->SetParameter(5, sigma2);
	
	fitfunc->SetLineStyle(3);
	fitfunc->SetLineColor(kRed);
	fitfunc->SetLineWidth(2);
	
	// performing fit
	histo->DrawCopy("HIST");
	histo->Fit(fitfunc);
	
	// Display fit results with gStyle
	// Again see class documentation of TStyle
	gStyle -> SetOptFit(1111);
}