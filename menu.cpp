#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

#include "menu.h"
//#include "HamiltonianCircuit.h"
//#include "GraphInterface.h"

#define W_SPACER 30

#ifdef __GNUC__
#define PCLEAR "clear"
#else
#define PCLEAR "cls"
#endif

// Static globals

// Static buffers

void Menu::displayHeader() {
	system(PCLEAR);
	cout << "Hamiltonian Circuit :: Main Menu" << endl;
	cout << setfill('=') << setw(W_SPACER) << "" << "\n\n";
	cout << setfill(' ');
}

void Menu::displayBody() {
	cout << "1. Add Module" << endl;
	cout << "2. Remove Module" << endl;
	cout << "3. Undo Module" << endl;
	cout << "4. Display Module" << endl;
	cout << "5. Solve Menu" << endl;
}

void Menu::displayFooter() {
	cout << "\n" << setfill('=') << setw(W_SPACER) << "" << endl;
	cout << setfill(' ');
	cout << "De Anza CIS22C Spring 2015" << endl;
	cout << "Alfred Ly | Minh Le | Yeshwanth Babu" << endl;
	cout << " :: ";
}

// Read Menu Functions
void MenuRead::displayHeader(){
	system(PCLEAR);
	cout << "HamiltonianCircuit :: Read Menu" << endl;
	cout << setfill('=') << setw(W_SPACER) << "" << "\n\n";
	cout << setfill(' ');
}

void MenuRead::displayBody(){
	cout << "Read a graph from file" << endl;
	cout << "Press 1 to return to main menu" << endl;
	
	/*
	Ask user the name of the file that contains the graph. 
	Store in the string: theFile
	theGraph.readFromFile(theFile);
	*/
}

// Add Menu Functions
void MenuAdd::displayHeader(){
	system(PCLEAR);
	cout << "HamiltonianCircuit :: Add Menu" << endl;
	cout << setfill('=') << setw(W_SPACER) << "" << "\n\n";
	cout << setfill(' ');
}

void MenuAdd::displayBody(){
	cout << "Add Menu Body Content" << endl;
	cout << "Press 1 to return to main menu" << endl;
	
	/*
	Ask user for the name of start and end vertex of the edge
	Store them in 2 strings: startLabel, endLable
	Ask user for the distance between them
	Store them in an int: weight
	theGraph.add(startLabel, endLabel, weight);
	*/
}





// Remove Menu Functions
void MenuRemove::displayHeader(){
	system(PCLEAR);
	cout << "HamiltonianCircuit :: Remove Menu" << endl;
	cout << setfill('=') << setw(W_SPACER) << "" << "\n\n";
	cout << setfill(' ');
}

void MenuRemove::displayBody(){
	cout << "Remove Menu Body Content" << endl;
	cout << "Press 1 to return to main menu" << endl;
}




// Undo Menu Functions
void MenuUndo::displayHeader(){
	system(PCLEAR);
	cout << "HamiltonianCircuit :: Undo Menu" << endl;
	cout << setfill('=') << setw(W_SPACER) << "" << "\n\n";
	cout << setfill(' ');
}

void MenuUndo::displayBody(){
	cout << "Undo Menu Body Content" << endl;
	cout << "Press 1 to return to main menu" << endl;
}




// Display Menu Functions
void MenuDisplay::displayHeader(){
	system(PCLEAR);
	cout << "HamiltonianCircuit :: Display Menu" << endl;
	cout << setfill('=') << setw(W_SPACER) << "" << "\n\n";
	cout << setfill(' ');
}

void MenuDisplay::displayBody(){
	cout << "Display Menu Body Content" << endl;
	cout << "Press 1 to return to main menu" << endl;
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




// Solve Menu Functions
void MenuSolve::displayHeader(){
	system(PCLEAR);
	cout << "HamiltonianCircuit :: Solve Menu" << endl;
	cout << setfill('=') << setw(W_SPACER) << "" << "\n\n";
	cout << setfill(' ');
}

void MenuSolve::displayBody(){
	cout << "Solve Menu Body Content" << endl;
	cout << "Press 1 to return to main menu" << endl;
	
	/*
	theGraph.displayHamiltonianC()
	
	*/
	
	
}

// Write Menu Functions
void MenuWrite::displayHeader(){
	system(PCLEAR);
	cout << "HamiltonianCircuit :: Write Menu" << endl;
	cout << setfill('=') << setw(W_SPACER) << "" << "\n\n";
	cout << setfill(' ');
}

void MenuWrite::displayBody(){
	cout << "Write a graph to file" << endl;
	cout << "Press 1 to return to main menu" << endl;
	
	/*
	Ask user for the name of the file . 
	Store in the string: theFile
	theGraph.writeToFile(theFile);
	*/
}
