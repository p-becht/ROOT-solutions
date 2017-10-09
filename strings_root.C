/*
ROOT Macro.		-->		[Dealing with strings]

ROOT-course 	--> 	Exercise 4 Day03:
-- 	Create the string "/data/run2/histos/2016/09/15/"
--	Retrieve Day, Month, Year from it using tokenize
--	Change subdirectory "histos" in "graphs"
*/

void strings_root(){
	
	// Defining string
	TString path = "/data/run2/histos/2016/09/15/";
	cout << "Path: " << path << endl;
	
	// Tokenize the string 
	TObjArray* tokenized_string = path.Tokenize("/");
	
	// Extract date from string
	cout << "Day: " << tokenized_string -> At(5) -> GetName() << endl;
	cout << "Month: " << tokenized_string -> At(4) -> GetName() << endl;
	cout << "Year :" << tokenized_string -> At(3) -> GetName() << endl;
	
	// Replacing subdirectory
	path.ReplaceAll("histos", "graphs");
	cout << "New Path: " << path << endl;
}