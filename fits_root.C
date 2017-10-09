/*
ROOT Macro.		-->		[Fitting Double Gaussian]

ROOT-course 	--> 	Exercise 3 Day02:
-- 	Fill random numbers of two different Gaussians to one histogram
--	Fit histogramm with a sum of two Gaussians
*/

#include "number_to_Cstring.hpp"
#include <string>

void fits_root(){
	
	// define histogram to fill in random numbers
	Int_t no_of_bins = 100;
	TH1F* histo = new TH1F("Histogram", "Random numbers with Gaussian fit",
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
	
	// creare canvas for drawing
	TCanvas* c = new TCanvas("c", "Random numbers with Gaussian fit");
	gStyle->SetOptStat(0);					// remove automatted legend of hist
	
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
	
	// style
	histo->SetLineWidth(1);
	histo->SetLineColor(kBlue);
	histo->SetMarkerStyle(33);
	histo->SetMarkerSize(1);
	histo->SetMarkerColor(kGray+2);
	
	fitfunc->SetLineStyle(3);
	fitfunc->SetLineColor(kRed);
	fitfunc->SetLineWidth(2);
	
	// drawing histogram with errors
	histo->Draw("E");
	
	// performing fit 
	histo->Fit(fitfunc);
	// PrintFunctionParameters(fitfunc);
	
	// create a legend for the plot
	TLegend *legend = new TLegend(0.7, 0.7, 0.9, 0.9);	// right upper corner
	
	// create two columns in the legend
	legend->SetNColumns(2);								// writing lines!
	
	//first line
	legend->AddEntry(histo, "Random numbers", "p"); 	// p marker, f fill
	legend->AddEntry((TObject*)0, "", "");				// empty entry
	
	// second line
	legend->AddEntry(fitfunc, "Two Gaussians fit", "l");
	legend->AddEntry((TObject*)0, "", "");
	
	// third line
	legend->AddEntry((TObject*)0, "Entries", "");
	legend->AddEntry((TObject*)0, 
					Form("%i", static_cast<Int_t>(histo->GetEntries())), ""
					);
	
	// get fit parameters form associated function
	TF1* fit = histo->GetFunction("fitfunc");
	Float_t Chi2 = fit->GetChisquare();
	
	// fourth line
	legend->AddEntry((TObject*)0, "#Chi^{2}", "");
	legend->AddEntry((TObject*)0, Form("%f", fit->GetChisquare()), "");
	
	// fifth line
	legend->AddEntry((TObject*)0, "#Chi^{2}_{red}", "");
	legend->AddEntry((TObject*)0, Form("%f", Chi2/(no_of_bins-6)), "");
	// --> see again the definition of the Chi2red ... no_of_bins-fit_parameters-1?

	legend->Draw("SAME");
	
}

// NumberToCstring(fit->GetChisquare()) --> something went wrong with the number formats