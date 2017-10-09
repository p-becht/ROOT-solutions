/*
ROOT Macro.		-->		[Canvases]

ROOT-course 	--> 	Exercise 6 Day02:
-- 	Create a Canvas with 6 Pads and fill it with different stuff
*/

void canvas_root(){
	
	// Creating a big canvas and deviding it
	TCanvas* c = new TCanvas("c", "myCanvas", 3000, 2000); // Width, Height in pixels
	
	// Deviding Canvas
	c->Divide(3,2);
	
	// Fill the Pads with previous Graphs
	c->cd(1);
	// create a 2D histogram
	TH2F *h2f = new TH2F("h2f","2D Gaussian Histogram;x-values;y-values;entries",100,-2,4,100,-1,1);
	//a 2D gaussian
	TF2 f2d("f2d","100*TMath::Gaus(x,1,1) * TMath::Gaus(y,0,0.2)");
	//fill the histogram
	h2f->FillRandom("f2d",100000);
	
	// axis
	TAxis *xaxis1 = h2f->GetXaxis();
	TAxis *yaxis1 = h2f->GetYaxis();
	TAxis *zaxis1 = h2f->GetZaxis();
	xaxis1->SetTitleOffset(1.5);
	yaxis1->SetTitleOffset(2);
	zaxis1->SetTitleOffset(1.5);
	
	// Draw
	h2f->DrawCopy("surf2");
	
	c->cd(2);
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
	TLegend *legend = new TLegend(0.5, 0.7, 0.9, 0.9);	// right upper corner
	
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
	legend->AddEntry((TObject*)0, Form("%f", Chi2/(no_of_bins-6-1)), "");
	// --> see again the definition of the Chi2red ... no_of_bins-fit_parameters-1?

	legend->Draw("SAME");
	
	c->cd(3);
	
	// Draw the histogram of K0 mass
   TH1F *K0mass = new TH1F("K0mass","K_{0}-mass",100,0.35,0.65);
   K0mass->SetBinContent(1,307);
   K0mass->SetBinContent(2,267);
   K0mass->SetBinContent(3,249);
   K0mass->SetBinContent(4,231);
   K0mass->SetBinContent(5,245);
   K0mass->SetBinContent(6,237);
   K0mass->SetBinContent(7,209);
   K0mass->SetBinContent(8,212);
   K0mass->SetBinContent(9,188);
   K0mass->SetBinContent(10,209);
   K0mass->SetBinContent(11,197);
   K0mass->SetBinContent(12,196);
   K0mass->SetBinContent(13,162);
   K0mass->SetBinContent(14,202);
   K0mass->SetBinContent(15,186);
   K0mass->SetBinContent(16,159);
   K0mass->SetBinContent(17,155);
   K0mass->SetBinContent(18,158);
   K0mass->SetBinContent(19,142);
   K0mass->SetBinContent(20,148);
   K0mass->SetBinContent(21,150);
   K0mass->SetBinContent(22,135);
   K0mass->SetBinContent(23,134);
   K0mass->SetBinContent(24,111);
   K0mass->SetBinContent(25,125);
   K0mass->SetBinContent(26,117);
   K0mass->SetBinContent(27,123);
   K0mass->SetBinContent(28,115);
   K0mass->SetBinContent(29,130);
   K0mass->SetBinContent(30,106);
   K0mass->SetBinContent(31,101);
   K0mass->SetBinContent(32,112);
   K0mass->SetBinContent(33,95);
   K0mass->SetBinContent(34,105);
   K0mass->SetBinContent(35,102);
   K0mass->SetBinContent(36,104);
   K0mass->SetBinContent(37,97);
   K0mass->SetBinContent(38,84);
   K0mass->SetBinContent(39,82);
   K0mass->SetBinContent(40,82);
   K0mass->SetBinContent(41,99);
   K0mass->SetBinContent(42,88);
   K0mass->SetBinContent(43,100);
   K0mass->SetBinContent(44,105);
   K0mass->SetBinContent(45,118);
   K0mass->SetBinContent(46,225);
   K0mass->SetBinContent(47,464);
   K0mass->SetBinContent(48,857);
   K0mass->SetBinContent(49,1205);
   K0mass->SetBinContent(50,1177);
   K0mass->SetBinContent(51,878);
   K0mass->SetBinContent(52,477);
   K0mass->SetBinContent(53,198);
   K0mass->SetBinContent(54,118);
   K0mass->SetBinContent(55,62);
   K0mass->SetBinContent(56,69);
   K0mass->SetBinContent(57,59);
   K0mass->SetBinContent(58,73);
   K0mass->SetBinContent(59,68);
   K0mass->SetBinContent(60,69);
   K0mass->SetBinContent(61,53);
   K0mass->SetBinContent(62,66);
   K0mass->SetBinContent(63,62);
   K0mass->SetBinContent(64,61);
   K0mass->SetBinContent(65,60);
   K0mass->SetBinContent(66,60);
   K0mass->SetBinContent(67,56);
   K0mass->SetBinContent(68,55);
   K0mass->SetBinContent(69,53);
   K0mass->SetBinContent(70,72);
   K0mass->SetBinContent(71,48);
   K0mass->SetBinContent(72,57);
   K0mass->SetBinContent(73,48);
   K0mass->SetBinContent(74,43);
   K0mass->SetBinContent(75,57);
   K0mass->SetBinContent(76,42);
   K0mass->SetBinContent(77,76);
   K0mass->SetBinContent(78,51);
   K0mass->SetBinContent(79,62);
   K0mass->SetBinContent(80,46);
   K0mass->SetBinContent(81,68);
   K0mass->SetBinContent(82,63);
   K0mass->SetBinContent(83,42);
   K0mass->SetBinContent(84,53);
   K0mass->SetBinContent(85,46);
   K0mass->SetBinContent(86,53);
   K0mass->SetBinContent(87,62);
   K0mass->SetBinContent(88,56);
   K0mass->SetBinContent(89,53);
   K0mass->SetBinContent(90,47);
   K0mass->SetBinContent(91,46);
   K0mass->SetBinContent(92,70);
   K0mass->SetBinContent(93,59);
   K0mass->SetBinContent(94,59);
   K0mass->SetBinContent(95,58);
   K0mass->SetBinContent(96,57);
   K0mass->SetBinContent(97,57);
   K0mass->SetBinContent(98,48);
   K0mass->SetBinContent(99,49);
   K0mass->SetBinContent(100,48);
   K0mass->SetEntries(15000);
   K0mass->GetXaxis()->SetTitle("m [GeV/c]");

// Style
   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#000099");
   K0mass->SetLineColor(ci);
   K0mass->SetFillColor(kAzure+6);
   
   K0mass->GetXaxis()->SetLabelFont(42);
   K0mass->GetXaxis()->SetLabelSize(0.035);
   K0mass->GetXaxis()->SetTitleSize(0.035);
   K0mass->GetXaxis()->SetTitleFont(42);
   K0mass->GetYaxis()->SetLabelFont(42);
   K0mass->GetYaxis()->SetLabelSize(0.035);
   K0mass->GetYaxis()->SetTitleSize(0.035);
   K0mass->GetYaxis()->SetTitleFont(42);
   K0mass->GetZaxis()->SetLabelFont(42);
   K0mass->GetZaxis()->SetLabelSize(0.035);
   K0mass->GetZaxis()->SetTitleSize(0.035);
   K0mass->GetZaxis()->SetTitleFont(42);
   
   K0mass->Draw("");
   gStyle->SetOptStat(0);					// remove automatted legend of hist

// Define a fit function
   // Gaussian fit for the peak and powerlaw for the (combinatorial) background
   TF1 fit2("fit2", "gaus(0)+[3]*pow(x,[4])", 0.35,0.65);
   
   fit2.SetLineColor(kRed);
   fit2.SetLineWidth(2);
   
// Set initial parameters
   Double_t peak_yield = 1000;
   Double_t mean = 0.5;
   Double_t sigma = 0.01;
   Double_t bg_amplitude = 10;
   Double_t bg_slope = -2;
   
   fit2.SetParameter(0, peak_yield);
   fit2.SetParameter(1, mean);
   fit2.SetParameter(2, sigma);
   fit2.SetParameter(3, bg_amplitude);
   fit2.SetParameter(4, bg_slope);
   
// Perform the Fit
   K0mass->Fit(&fit2);
   gPad->SetTicks(); // Ticks for all four axes
   TF1* fit1 = K0mass->GetFunction("fit2");
   
// create a legend for the plot
	TLegend *legen = new TLegend(0.52, 0.7, 0.9, 0.9);	// right upper corner
	legen->AddEntry(K0mass, "Data", "lf"); 	// p marker, f fill
	legen->AddEntry(fit1, "Gaussian fit + background", "l");
	
	gStyle->SetLegendFont(72);
	gStyle->SetLegendTextSize(0.03);
	legend->SetEntrySeparation(0);       		// not functioning as supposed
	
	legen->Draw("SAME");
	
	c->cd(4);
	
	// define function:
	// 1 dimensional --> class: TF1
	// note: TF1() returns a pointer
	// argument: ("name", "definition", double xmin, double xmax)
	
	// Declaring an array of 3 functions
	TF1* functions[3];
	
	// Defining the first function
	functions[0] = new TF1("f", "[0]*pow(x,[1)*sin(x)", -5, 5);
	
	// Set properties of the first function
	functions[0]->SetLineColor(kBlack);
	functions[0]->SetTitle("A Function with 2 Parameters");
	functions[0]->SetParameters(3,2);
	functions[0]->SetLineWidth(3);
	
	// Set properties of the axis
	TAxis *xaxis = functions[0]->GetXaxis();
	TAxis *yaxis = functions[0]->GetYaxis();
	
	xaxis->SetLabelSize(0.03);				// etc., see documentation of class
	yaxis->SetLabelSize(0.03);
	
	xaxis->SetTitle("x");
	yaxis->SetTitle("a_{0} x^{a_{1}} sin(x)");
	
	xaxis->SetTitleSize(0.045);
	yaxis->SetTitleSize(0.045);
	
	xaxis->SetTitleOffset(0.7);
	yaxis->SetTitleOffset(0.7);
	
	// Draw the first function
	functions[0]->Draw();
	
	// Loop over the rest of the function array, set new properties for the function
	for(Int_t i = 1; i < 3; ++i){
		functions[i] = new TF1("f", "[0]*pow(x,[1)*sin(x)", -5, 5);
		switch(i){
			case 1: functions[i]->SetLineColor(kRed);
					functions[i]->SetParameters(2,3);
					break;
			case 2: functions[i]->SetLineColor(kBlue);
					functions[i]->SetParameters(40,0);
					break;
		}
		
		// Draw the functions in the same canvas as the first one
		functions[i]->Draw("SAME");
	}
	
	// create a legend for the plot
	TLegend *lege = new TLegend(0.7, 0.7, 0.9, 0.9);
	lege->AddEntry(functions[0], "a_{0}=3,   a_{1}=2", "l"); // p marker, f fill
	lege->AddEntry(functions[1], "a_{0}=2,   a_{1}=3", "l");
	lege->AddEntry(functions[2], "a_{0}=40, a_{1}=0", "l");
	lege->SetBorderSize(1);
	lege->Draw("SAME");
	gPad->RedrawAxis();
	
	c->cd(5);
	
	// defining new histogram with uniform distribution
	TH1F* uniform = new TH1F("uniform", "Uniform Histogram", 50, -5, 5);
	
	// defining new histogram with Gauss distribution
	TH1F* gauss = new TH1F("gauss", "Gaussian Histogram", 50, -5, 5);
	
	// Fill 10000 values to uniform acccording to predefined function 'pol0'
	uniform->FillRandom("pol0", 10000);
	
	// Fill 1000 values to gauss acccording to predefined function 'gaus'
	gauss->FillRandom("gaus", 1000);
	
	// defining histogram for the sum of both
	TH1F* sumhist = new TH1F("sumhist", "Sum of Gaussian + Uniform normalized to unity", 50, -5, 5);
	
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
	
	gauss->Draw("HIST");
	
	c->cd(6);
	sumhist->Draw("E");							// Draw with Errors
}
	
void SaveCanvas(){
	// saving the canvas to file
	//c->SaveAs("~/ROOT/solutions/canvas6.pdf");
	
	// --> Save Canvas in new ROOT Prompt does the right formatting!
}