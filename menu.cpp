#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;

#include "input.h"
#include "menu.h"
#include "HamiltonianCircuit.h"
#include "GraphInterface.h"

#define W_SPACER 30

#ifdef __GNUC__
#define PCLEAR "clear"
#else
#define PCLEAR "cls"
#endif

// Static globals
static string undostartPoint = "";
static string undoendPoint = "";
static int undoweight = 0;

// Static buffers

template <class Labeltype>
void Menu<Labeltype>::displayHeader() {
	system(PCLEAR);
	cout << "Hamiltonian Circuit :: Main Menu" << endl;
	cout << setfill('=') << setw(W_SPACER) << "" << "\n\n";
	cout << setfill(' ');
}

template <class Labeltype>
void Menu<Labeltype>::displayBody() {
	cout << "1. Add Module" << endl;
	cout << "2. Remove Module" << endl;
	cout << "3. Undo Module" << endl;
	cout << "4. Display Module" << endl;
	cout << "5. Solve Menu" << endl;
	cout << "6. Read Menu" << endl;
	cout << "7. Write Menu" << endl;
	cout << "8. Quit Option" << endl;

}

template <class Labeltype>
void Menu<Labeltype>::displayFooter() {
	cout << "\n" << setfill('=') << setw(W_SPACER) << "" << endl;
	cout << setfill(' ');
	cout << "De Anza CIS22C Spring 2015" << endl;
	cout << "Alfred Ly | Minh Le | Yeshwanth Babu" << endl;
	cout << " :: ";
}

// Read Menu Functions
template <class Labeltype>
void MenuRead<Labeltype>::displayHeader(){
	system(PCLEAR);
	cout << "HamiltonianCircuit :: Read Menu" << endl;
	cout << setfill('=') << setw(W_SPACER) << "" << "\n\n";
	cout << setfill(' ');
}

template <class Labeltype>
void MenuRead<Labeltype>::displayBody(HamiltonianCircuit& theGraph) {
	cout << "Read a graph from file" << endl;
	cout << "Press 1 to return to main menu" << endl;

//	Ask user the name of the file that contains the graph.
//	Open the file to read. Assign it to inFile.

	string filename, startLabel, endLabel, line, home;
	int weight;
	ifstream inFile;
	cout << "Enter the input filename: ";
	getline(cin, filename);
	if (ifs.open(filename.c_str())){

		while (getline(inFile, line))
		{
			int pos1 = line.find('-', 0);
			startLabel = line.substr(0, pos1 - 1);
			int pos2 = line.find('-', pos1 + 2);
			endLabel = line.substr(pos1 + 2, pos2 - pos1 + 3);
			string weightString = line.substr(pos2 + 2);
			weight = atoi(weightString.c_str());
			theGraph->add(startLabel, endLabel, weight);
		}

		//	Ask user for home vertex (Starting point). Store it in the string home.
		theGraph->setHome(home);
	}
	else {
		cout << "Invalid filename. Closing program." << endl;
		system("pause");
		return;
	}

}
// Add Menu Functions
template <class Labeltype>
void MenuAdd<Labeltype>::displayHeader(){
	system(PCLEAR);
	cout << "HamiltonianCircuit :: Add Menu" << endl;
	cout << setfill('=') << setw(W_SPACER) << "" << "\n\n";
	cout << setfill(' ');
}

template <class Labeltype>
void MenuAdd<Labeltype>::displayBody(HamiltonianCircuit& theGraph) {
	int weight;
	string startLabel, endLabel; 
	cout << "Add Menu Body Content" << endl;
	cout << "Press 1 to return to main menu" << endl;

	/*
	Ask user for the name of start and end vertex of the edge
	Store them in 2 strings: startLabel, endLable
	Ask user for the distance between them
	Store them in an int: weight
	theGraph.add(startLabel, endLabel, weight);
	*/
	cout << "Please input start vertex of edge" << endl;
	cin >> startLabel;
	cout << "Please input end vertex of edge" << endl;
	cin >> endLabel;
	cout << "What is the distance between the two vertexes?" << endl;
	cin >> weight;
	theGraph->add(startLabel, endLabel, weight);
  
}





// Remove Menu Functions
template <class Labeltype>
void MenuRemove<Labeltype>::displayHeader(){
	system(PCLEAR);
	cout << "HamiltonianCircuit :: Remove Menu" << endl;
	cout << setfill('=') << setw(W_SPACER) << "" << "\n\n";
	cout << setfill(' ');
}

template <class Labeltype>
void MenuRemove<Labeltype>::displayBody(HamiltonianCircuit& theGraph){
	string startPoint, endPoint;
	static string undostartPoint;
	static string undoendPoint;
	static int undoWeight;
	cout << "Remove Menu Body Content" << endl;
	cout << "Press 1 to return to main menu" << endl;
	/*
	+	Prompt user for startPoint and endPoint from where the edge has to be removed.
	+	Local static variable UndostartPoint = startPoint
	+	Local static variable UndoendPoint = endPoint
	+	Local static variable UndoWeight = theGraph.getWeight(startPoint, endPoint)
	+	Local static boolean undoBool = false
	+	theGraph.remove(startPoint,endPoint);
	+	*/
	cout << "Please enter the startPoint and endPoint from where the edge has to be removed" << endl;
	cin >> startPoint >> endPoint;
	undostartPoint = startPoint;
	undoendPoint = endPoint;
	undoWeight = theGraph->getEdgeWeight(startPoint, endPoint);
	theGraph->remove(startLabel, endLabel, weight);

}




// Undo Menu Functions
template <class Labeltype>
void MenuUndo<Labeltype>::displayHeader(){
	system(PCLEAR);
	cout << "HamiltonianCircuit :: Undo Menu" << endl;
	cout << setfill('=') << setw(W_SPACER) << "" << "\n\n";
	cout << setfill(' ');
}

template <class Labeltype>
void MenuUndo<Labeltype>::displayBody(HamiltonianCircuit& theGraph){
	cout << "Undo Menu Body Content" << endl;
	cout << "Undoing recently removed edge..." << endl;
	theGraph->add(undostartPoint, undoendPoint, undoWeight);
	cout << "Recently removed edge was added";
	cout << "Press 1 to return to main menu" << endl;
}




// Display Menu Functions
template <class Labeltype>
void MenuDisplay<Labeltype>::displayHeader(){
	system(PCLEAR);
	cout << "HamiltonianCircuit :: Display Menu" << endl;
	cout << setfill('=') << setw(W_SPACER) << "" << "\n\n";
	cout << setfill(' ');
}

template <class Labeltype>
void MenuDisplay<Labeltype>::displayBody(HamiltonianCircuit& theGraph){

	cout << "Display Menu Body Content" << endl;
	cout << "Press 1 for Depth First Traversal" << endl;
	cout << "Press 2 for Breadth First Traversal" << endl;
	cout << "Press 3 to return to main menu" << endl;
	switch (input.getCh()){
	case 1:
		theGraph->depthFirstTraversalH(displayHelper);
		break;
	case 2:
		theGraph->breadthFirstTraversalH(displayHelper);
		break;

	}
	/*
	Write another helper function like this:
	displayHelper(LabelType& label)
	{
	cout << label << " ";
	}

	then call it from here like this:
	theGraph.depthFirstTraversalH(displayHelper) or
	theGraph.breadthFirstTraversalH(displayHelper)
	*/

}

template <class Labeltype>
void MenuDisplay<Labeltype>::displayHelper(const Labeltype& label)
{
	cout << label << " ";
}


// Solve Menu Functions
template <class Labeltype>
void MenuSolve<Labeltype>::displayHeader(){
	system(PCLEAR);
	cout << "HamiltonianCircuit :: Solve Menu" << endl;
	cout << setfill('=') << setw(W_SPACER) << "" << "\n\n";
	cout << setfill(' ');
}

template <class Labeltype>
void MenuSolve<Labeltype>::displayBody(HamiltonianCircuit& theGraph){
	cout << "Solve Menu Body Content" << endl;
	cout << "Press 1 to return to main menu" << endl;

	/*
	theGraph.displayHamiltonianC()

	*/
	theGraph->displayHamiltonianC();


}

// Write Menu Functions
template <class Labeltype>
void MenuWrite<Labeltype>::displayHeader(){
	system(PCLEAR);
	cout << "HamiltonianCircuit :: Write Menu" << endl;
	cout << setfill('=') << setw(W_SPACER) << "" << "\n\n";
	cout << setfill(' ');
}

template <class Labeltype>
void MenuWrite<Labeltype>::displayBody(HamiltonianCircuit& theGraph){
	string theFile;
	cout << "Write a graph to file" << endl;
	cout << "Press 1 to return to main menu" << endl;

	/*
	Ask user for the name of the file .
	Store in the string: theFile
	ofstream ofs(theFile);
	theGraph.saveToFileH(theFile);
	ofs.close();
	*/
	cout << "Please enter the name of the file" << endl;
	cin >> theFile;
	ofstream ofs(theFile);
	theGraph->saveToFileH(ofs);
	ofs.close();
}
