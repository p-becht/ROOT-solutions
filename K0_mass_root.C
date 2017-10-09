/*
ROOT Macro.		-->		[Fitting K0 mass]

ROOT-course 	--> 	Exercise 4 Day02:
-- 	Draw K0 mass by running the predefined macro example_code/drawK0mass.C
--	Fit the data with the sum of two functions (background and peak)
*/

void K0_mass_root(){

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
   TF1 fit("fit", "gaus(0)+[3]*pow(x,[4])", 0.35,0.65);
   
   fit.SetLineColor(kRed);
   fit.SetLineWidth(2);
   
// Set initial parameters
   Double_t peak_yield = 1000;
   Double_t mean = 0.5;
   Double_t sigma = 0.01;
   Double_t bg_amplitude = 10;
   Double_t bg_slope = -2;
   
   fit.SetParameter(0, peak_yield);
   fit.SetParameter(1, mean);
   fit.SetParameter(2, sigma);
   fit.SetParameter(3, bg_amplitude);
   fit.SetParameter(4, bg_slope);
   
// Perform the Fit
   K0mass->Fit(&fit);
   gPad->SetTicks(); // Ticks for all four axes
   TF1* fit1 = K0mass->GetFunction("fit");
   
// create a legend for the plot
	TLegend *legend = new TLegend(0.6, 0.7, 0.9, 0.9);	// right upper corner
	legend->AddEntry(K0mass, "Data", "lf"); 	// p marker, f fill
	legend->AddEntry(fit1, "Gaussian fit + background", "l");
	
	gStyle->SetLegendFont(72);
	gStyle->SetLegendTextSize(0.03);
	legend->SetEntrySeparation(0);       		// not functioning as supposed
	
	legend->Draw("SAME");
}