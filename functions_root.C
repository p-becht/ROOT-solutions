/*
ROOT Macro.		-->		[Defining and drawing function with two Parameters]

ROOT-course 	--> 	Exercise 1 Day02:
-- define the function a_o x^a_1 sin(x)
-- draw the function for different parameter values
-- fix the values to a_0=3 and a_1=2
-- compute function value at x=2
-- compute derivative value at x=2
-- compute integral value in the range (0,1)
*/

void functions_root(){
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
	
	// compute function value at x=2
	cout << "For the fixed Parameters: a_0 = 3 and a_1 = 2 ..." << endl;
	cout << "The function value at x=2 is " << 
	functions[0]->Eval(2) << endl;
	
	// compute derivative value at x=2
	cout << "The value of the derivative at x=2 is " << 
	functions[0]->Derivative(2) << endl;
	
	// compute integral value in the range (0,1)
	cout << "The value of the integral in the interval (0,1) is " << 
	functions[0]->Integral(0,1) << endl;
	
	// create a legend for the plot
	TLegend *legend = new TLegend(0.7, 0.7, 0.9, 0.9);
	legend->AddEntry(functions[0], "a_{0}=3,   a_{1}=2", "l"); // p marker, f fill
	legend->AddEntry(functions[1], "a_{0}=2,   a_{1}=3", "l");
	legend->AddEntry(functions[2], "a_{0}=40, a_{1}=0", "l");
	legend->SetBorderSize(1);
	legend->Draw("SAME");
	gPad->RedrawAxis();
}
