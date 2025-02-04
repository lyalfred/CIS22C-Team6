#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <sstream>

#include "input.h"
#include "menu.h"
#include "HamiltonianCircuit.h"
#include "GraphInterface.h"	

using namespace std;

#define W_SPACER 30

#ifdef __GNUC__
#define PCLEAR "clear"
#else
#define PCLEAR "cls"
#endif
static string undostartPoint = "";
static string undoendPoint = "";
static int undoWeight = 0;
template <class Labeltype>
class Menu {

public:
	Input input;
	//static string undostartPoint = "";
	//	static string undoendPoint = "";
	//	static int undoWeight = 0;
	virtual void displayHeader();       //Top portion of our user interface display
	virtual void displayBody(HamiltonianCircuit<Labeltype>* theGraph);			// The raw menu content
};

template <class Labeltype>
class MenuRead : public Menu<Labeltype> {
public:
	void displayHeader();
	void displayBody(HamiltonianCircuit<Labeltype>* theGraph);
};

template <class Labeltype>
class MenuAdd : public Menu<Labeltype> {
public:
	void displayHeader();
	void displayBody(HamiltonianCircuit<Labeltype>* theGraph);
};

template <class Labeltype>
class MenuRemove : public Menu<Labeltype> {
public:
	void displayHeader();
	void displayBody(HamiltonianCircuit<Labeltype>* theGraph);
};

template <class Labeltype>
class MenuUndo : public Menu<Labeltype> {
public:
	void displayHeader();
	void displayBody(HamiltonianCircuit<Labeltype>* theGraph);
};

template <class Labeltype>
class MenuDisplay : public Menu<Labeltype> {
public:
	void displayHeader();
	void displayBody(HamiltonianCircuit<Labeltype>* theGraph);
	void displayHelper(string& label);
};

template <class Labeltype>
class MenuSolve : public Menu<Labeltype> {
public:
	void displayHeader();
	void displayBody(HamiltonianCircuit<Labeltype>* theGraph);
};

template <class Labeltype>
class MenuWrite : public Menu<Labeltype> {
public:
	void displayHeader();
	void displayBody(HamiltonianCircuit<Labeltype>* theGraph);
};

template <class Labeltype>
void Menu<Labeltype>::displayHeader() {
	system(PCLEAR);
	cout << "Hamiltonian Circuit :: Main Menu" << endl;
	cout << setfill('=') << setw(W_SPACER) << "" << "\n\n";
	cout << setfill(' ');
}

template <class Labeltype>
void Menu<Labeltype>::displayBody(HamiltonianCircuit<Labeltype>* theGraph) {
	cout << "1. Add Module" << endl;
	cout << "2. Remove Module" << endl;
	cout << "3. Undo Module" << endl;
	cout << "4. Display Module" << endl;
	cout << "5. Solve Menu" << endl;
	cout << "6. Read Menu" << endl;
	cout << "7. Write Menu" << endl;
	cout << "8. Quit Option" << endl;
	cout << "9. Dance Party" << endl;
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
void MenuRead<Labeltype>::displayBody(HamiltonianCircuit<Labeltype>* theGraph) {
	cout << "Read a graph from file" << endl;

	//	Ask user the name of the file that contains the graph.
	//	Open the file to read. Assign it to inFile.

	string filename, startLabel, endLabel, line, home;
	int weight;
	ifstream inFile;
	cout << "Enter the input filename: ";
	cin.ignore(cin.rdbuf()->in_avail());
	getline(cin, filename);
	inFile.open(filename.c_str());
	if (inFile.is_open()){

		while (getline(inFile, line))
		{
			int pos1 = line.find('-', 0);
			startLabel = line.substr(0, pos1 - 1);
			int pos2 = line.find('-', pos1 + 2);
			endLabel = line.substr(pos1 + 2, pos2 - pos1 - 3);
			string weightString = line.substr(pos2 + 2);
			stringstream ss(weightString);
			ss >> weight;
			theGraph->LinkedGraph<string>::add(startLabel, endLabel, weight);
		}

		//	Ask user for home vertex (Starting point). Store it in the string home.
		cout << "Enter your home point: ";
		cin.ignore(cin.rdbuf()->in_avail());
		getline(cin, home);
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
void MenuAdd<Labeltype>::displayBody(HamiltonianCircuit<Labeltype>* theGraph) {
	int weight;
	string startLabel, endLabel;
	cout << "Add Menu Body Content" << endl;


	/*
	Ask user for the name of start and end vertex of the edge
	Store them in 2 strings: startLabel, endLable
	Ask user for the distance between them
	Store them in an int: weight
	theGraph.add(startLabel, endLabel, weight);
	*/
	cout << "Please input start vertex of edge" << endl;
	cin.ignore(cin.rdbuf()->in_avail());
	getline(cin, startLabel);
	//	cin >> startLabel;
	cout << "Please input end vertex of edge" << endl;
	cin.ignore(cin.rdbuf()->in_avail());
	getline(cin, endLabel);
	//	cin >> endLabel;
	cout << "What is the distance between the two vertexes?" << endl;
	cin >> weight;
	theGraph->add(startLabel, endLabel, weight);
	return;
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
void MenuRemove<Labeltype>::displayBody(HamiltonianCircuit<Labeltype>* theGraph){
	string startPoint, endPoint;
	//static string undostartPoint;
	//static string undoendPoint;
	//static int undoWeight;
	cout << "Remove Menu Body Content" << endl;

	/*
	+	Prompt user for startPoint and endPoint from where the edge has to be removed.
	+	Local static variable UndostartPoint = startPoint
	+	Local static variable UndoendPoint = endPoint
	+	Local static variable UndoWeight = theGraph.getWeight(startPoint, endPoint)
	+	Local static boolean undoBool = false
	+	theGraph.remove(startPoint,endPoint);
	+	*/
	cout << "Please enter the startPoint from where the edge has to be removed. "<< endl;
	cin.ignore(cin.rdbuf()->in_avail());
	getline(cin, startPoint);
	cout << "Please enter the corresponding endPoint" << endl;
	getline(cin, endPoint);
	undostartPoint = startPoint;
	undoendPoint = endPoint;
	undoWeight = theGraph->getEdgeWeight(startPoint, endPoint);
	theGraph->remove(startPoint, endPoint);

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
void MenuUndo<Labeltype>::displayBody(HamiltonianCircuit<Labeltype>* theGraph){
	cout << "Undo Menu Body Content" << endl;
	cout << "Undoing recently removed edge..." << endl;
	theGraph->add(undostartPoint, undoendPoint, undoWeight);
	cout << "Recently removed edge was added" << endl;

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
void MenuDisplay<Labeltype>::displayBody(HamiltonianCircuit<Labeltype>* theGraph){

	cout << "Display Menu Body Content" << endl;
	cout << "Press 1 for Depth First Traversal" << endl;
	cout << "Press 2 for Breadth First Traversal" << endl;
	cout << "Press 3 to return to main menu" << endl;

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
void MenuSolve<Labeltype>::displayBody(HamiltonianCircuit<Labeltype>* theGraph){
	string theFile;
	cout << "Solve Menu Body Content" << endl;
	/*
	theGraph.displayHamiltonianC()
	*/
	theGraph->displayHamiltonianC();
	cout << "Please enter the name of the file you wish to save to" << endl;
	cin.ignore(cin.rdbuf()->in_avail());
	getline(cin, theFile);
	ofstream ofs(theFile);
	theGraph->saveHamiltonianC(ofs);
	ofs.close();
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
void MenuWrite<Labeltype>::displayBody(HamiltonianCircuit<Labeltype>* theGraph){
	string theFile;
	cout << "Write a graph to file" << endl;

	
//	Ask user for the name of the file .
	
	cout << "Please enter the name of the file you wish to save to" << endl;
	cin.ignore(cin.rdbuf()->in_avail());
	getline(cin, theFile);
	ofstream ofs(theFile);
	theGraph->saveToFileH(ofs);
	ofs.close();
}
