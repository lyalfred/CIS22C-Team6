#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

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

