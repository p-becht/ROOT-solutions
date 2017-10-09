/*
ROOT Macro.		-->		[Randomly filling, adding, normalizing histograms]

ROOT-course 	--> 	Exercise 2 Day02:
-- 	Fill histogram random with 10,000 uniformly distributed values
	between -5 and 5 in 50 bins
--	Fill other histogram random with 1,000 Gaussian distributed values
	between -5 and 5 in 50 bins
--	Add the histograms with coorect Error propagation
--	Normalize the sum-histogram to 1
--	Draw the histogram with Errors (Option "E")
*/

void histograms_root(){
	
	// defining new histogram with uniform distribution
	TH1F* uniform = new TH1F("uniform", "Uniform Histogram", 50, -5, 5);
	
	// defining new histogram with Gauss distribution
	TH1F* gauss = new TH1F("gauss", "Gaussian Histogram", 50, -5, 5);
	
	// Fill 10000 values to uniform acccording to predefined function 'pol0'
	uniform->FillRandom("pol0", 10000);
	
	// Fill 1000 values to gauss acccording to predefined function 'gaus'
	gauss->FillRandom("gaus", 1000);
	
	// defining histogram for the sum of both
	TH1F* sumhist = new TH1F("sumhist", "Sum of both", 50, -5, 5);
	
	// calling Sumw2 for correct error propagation
	uniform->Sumw2();
	gauss->Sumw2();
	
	// adding the two histograms
	sumhist->Add(uniform, gauss);
	
	// normalize sumhist to unity
	sumhist->Scale(1.0/sumhist->GetEntries());	// Divide every bin by number of entries
	
	// style
	uniform->SetLineColor(kBlack);
	uniform->SetLineWidth(1);
	uniform->SetFillStyle(3006);
	uniform->SetFillColor(kRed);
	
	gauss->SetLineColor(kBlack);
	gauss->SetLineWidth(1);
	gauss->SetFillStyle(3003);
	gauss->SetFillColor(kBlue);
	
	sumhist->SetLineColor(kBlack);
	sumhist->SetLineWidth(1);
	sumhist->SetFillStyle(3012);
	sumhist->SetFillColor(kMagenta+2);
	
	// defining new canvas for drawing
	TCanvas* c = new TCanvas("c", "A few Histograms");
	c->Divide(2, 2);
	
	c->cd(1);
	uniform->Draw("HIST");						// Draw without Errors "HIST"
	
	c->cd(2);
	gauss->Draw("HIST");
	
	c->cd(3);
	sumhist->Draw("E");							// Draw with Errors
	
	// checking the errors
	c->cd(4);
	TPaveText* text = new TPaveText(0.1, 0.1, 0.9, 0.9);
	
	text->SetBorderSize(1);
	text->SetFillColor(kWhite);
	
	text->SetTextSize(0.06);
	text->AddText(Form("Some Error Values:"));
	text->SetTextSize(0.04);
	text->AddText(Form("Bin No. 10, Error Value : %f", sumhist->GetBinError(10)));
	text->AddText(Form("Bin No. 20, Error Value : %f", sumhist->GetBinError(20)));
	text->AddText(Form("Bin No. 30, Error Value : %f", sumhist->GetBinError(30)));
	text->AddText(Form("Bin No. 40, Error Value : %f", sumhist->GetBinError(40)));
	
	text->Draw();
	
}