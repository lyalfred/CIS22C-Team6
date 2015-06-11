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

// Add Menu Functions
void MenuAdd::displayHeader(){
	system(PCLEAR);
	cout << "HamiltonianCircuit :: Add Menu" << endl;
	cout << setfill('=') << setw(W_SPACER) << "" << "\n\n";
	cout << setfill(' ');
}

void MenuAdd::displayBody(){
	cout << "Add Menu Body Content" << endl;
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
}
