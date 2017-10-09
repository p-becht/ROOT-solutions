/*
ROOT Macro.		-->		[Collection of Graphs and Histograms]

ROOT-course 	--> 	Exercise 3 Day03:
-- 	Create several histograms, e.g. 3
--	Create several graphs, e.g. 3
--	Fill histograms in one collection class and graphs to another
--	Save both collections in one ROOT-file using 'kSingleKey'
--	Browse the file
*/

#include <iostream>
#include <cmath>
// Skip other include statements (not intended to compile)

using namespace std;

// Daclarations
void open_checking_file(const char*);

void collections_root(){
	
	// Creating several histograms:
	// Histogram 1:
	TH1F* hist1 = new TH1F("hist1", "Gaussian Histogram; Random Numbers; Counts",
						   200, -5, 5);
	TF1* Gaussian = new TF1("Gaussian",
							"gaus",
							-5, 5);
	Gaussian -> SetParameters(3, 2, 1.2);
	hist1 -> FillRandom("Gaussian", 1000);
	hist1 -> SetLineWidth(1);
	hist1 -> SetLineColor(kBlue);
	hist1 -> SetFillStyle(3001);
	hist1 -> SetFillColor(kAzure);
	
	// hist1 -> Draw();
	
	// Histogram 2:
	TH1F* hist2 = new TH1F("hist2", "Gaussian + 'exp. background'; Random Numbers; Counts",
						   200, 0, 50);
	TF1* Gaussian_bg = new TF1("Gaussian_bg", 
							   "gaus(0)+[3]*pow(TMath::E(),([4]*(x-[5])))",
							   -10, 60);
	Gaussian_bg -> SetParameters(2, 27, 1, 3, -0.04, 1);
	hist2 -> FillRandom("Gaussian_bg", 10000);
	hist2 -> SetLineWidth(1);
	hist2 -> SetLineColor(kRed);
	hist2 -> SetFillStyle(3001);
	hist2 -> SetFillColor(kRed-9);
	
	// hist2 -> Draw();
	
	//Histogram 3:
	TH2F* hist3 = new TH2F("hist3", "2D-Histogram; x-Random; y-Random; Counts",
		100, -5, 5, 100, -10, 10);
	TF2* SinGauss = new TF2("SinGauss", "x*sin([0]*x)*TMath::Gaus(y, [1], [2])");
	SinGauss -> SetParameters(3.254, -2, 4);
	hist3 -> FillRandom("SinGauss", 30000);
	
	// hist3 -> Draw("surf2");
	
	// Creating several graphs:
	// Graph 1:
	TGraphErrors* graph1 = new TGraphErrors;
	graph1 -> SetName("Exponential");			// Objects need names!
	graph1 -> SetTitle("Exponential Decay; x; y");
	for(Int_t i = 0; i < 50; ++i){
		graph1 -> SetPoint(i, 2*i, 100*pow(TMath::E(),-0.07*i)+pow(-1, i));
		graph1 -> SetPointError(i, 1, 1);
	}
	
	// graph1 -> Draw("ap");
	
	// Graph 2:
	TGraphErrors* graph2 = new TGraphErrors;
	graph2 -> SetName("Linear");
	graph2 -> SetTitle("Linear Graph; x; y");
	for(Int_t i = 0; i < 100; ++i){
		graph2 -> SetPoint(i, i, i);
		graph2 -> SetPointError(i, 1, 1);
	}
	
	// graph2 -> Draw("alp");
	
		// Graph 3:
	TGraphErrors* graph3 = new TGraphErrors;
	graph3 -> SetName("Interference");
	graph3 -> SetTitle("Interference Pattern; x; Intensity");
	Int_t counter = 0;
	for(Int_t i = -10; i < 10; ++i){
		if(i != 0){
			graph3 -> SetPoint(counter, i, 12*pow(sin(i),2)/abs(i));
			graph3 -> SetPointError(counter, 0.3, 0.3);
			++counter;
		}
		else continue;
	}
	
	// graph3 -> Draw("ap");
	
	// Fill histograms in one collection (List):
	TList histogram_list;
	histogram_list.Add(hist1);
	histogram_list.Add(hist2);
	histogram_list.Add(hist3);
	
	// Fill Graphs in another collection (Array):
	TObjArray graph_array;
	graph_array.Add(graph1);
	graph_array.Add(graph2);
	graph_array.Add(graph3);
	
	// Save Collections in ROOT-file
	TFile file("~/ROOT/solutions/histograms_and_graphs.root", "recreate");
	histogram_list.Write("histograms", TObject::kSingleKey);
	graph_array.Write("graphs", TObject::kSingleKey);
	file.Close();
	
	open_checking_file("~/ROOT/solutions/histograms_and_graphs.root");
}

// How to deal with collections see Day03 in the slides of the tutorial!
// Considering retrieving objects, etc.


////////////////////////////////////////////////////////////////////////////////////////////
void open_checking_file(const char* path){
	
	// Open file
	TFile file(path);
	
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

/*
gStyle->SetOptStat(0);
gPad->SetTicks();
gPad->RedrawAxis();
gPad->Update();
*/