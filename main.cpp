#include <iostream>
#include "menu.h"
#include "HamiltonianCircuit.h"
#include "GraphInterface.h"
#include "input.h"
#include <windows.h>
#include <cstdlib>
using namespace std;

#ifdef __GNUC__
#define PCLEAR "clear"
#else
#define PCLEAR "cls"
#endif

// Program States
#define STATE_SPLASH    0
#define STATE_MAIN      1
#define STATE_ADD 	    2
#define STATE_REMOVE    3
#define STATE_UNDO      4
#define STATE_DISPLAY   5
#define STATE_SOLVE     6
#define STATE_READ		7
#define STATE_WRITE		8


int main() {

	HamiltonianCircuit<string> *circuit = new HamiltonianCircuit<string>();

	Input input;
	//Menu modules
	Menu<string>				menu_Main;
	MenuAdd<string>				menu_Add;
	MenuRemove<string>			menu_Remove;
	MenuUndo<string>			menu_Undo;
	MenuDisplay<string>			menu_Display;
	MenuSolve<string>			menu_Solve;
	MenuRead<string>			menu_Read;
	MenuWrite<string>			menu_Write;

		//Main globals
	int state = 0;			// 0 - splash page
							// 1 - main menu	
							// 2 - add menu
							// 3 - remove menu
							// 4 - undo menu
							// 5 - display menu
							// 6 - solve menu
							// 7 - read menu
							// 8 - write menu
							// 9 - quit option
							// 10- dance party!!!
	int prev_state = 0;

	int substate = 0;		// 0 - None
							// 1 - Depth First Search
							// 2 - Breadth First Search

	bool quit = false;

	while (!quit){

		//Prompt program splash
		switch (state) {
			case 0: //slash menu
				cout << "CIS 22C Team 6 Group Project: " << endl;
				cout << "Hamiltonian Circut" << endl;
				cout << "Press any key to continue..." << endl;
				menu_Main.displayFooter();

				input.getCh();  // wait for any key
				state = STATE_MAIN; // switch state to main menu
				break;
			case 1: // case state main menu
				menu_Main.displayHeader(); // display main menu header
				menu_Main.displayBody();   // display main menu body
				menu_Main.displayFooter(); // display main menu footer

				prev_state = 1; // set last state to main menu
				cout << "Input your choice" << endl;
				switch (input.getCh())	{	//switch input

					case 1: // add menu
						state = 2;
						break;
					case 2: //remove menu
						state = 3;
						break;
					case 3: //undo menu
						state = 4;
						break;
					case 4: //display menu
						state = 5;
						break;
					case 5: //solve menu
						state = 6;
						break;
					case 6:	//read menu
						state = 7;
						break;
					case 7:	//write party
						state = 8;
						break;
					case 8:	//quit option
						state = 9;
						break;
					case 9: // dance party
						state = 10;
						break;
				}
				break;
			case 2:		// case state add menu
				menu_Add.displayHeader();
				menu_Add.displayBody();

				prev_state = 2;		//set last state to add
				switch (input.getCh()){
					case 1:
						state = 1; //back to main menu
						break;
				}
				break;
			case 3:		// case state for remove menu
				menu_Remove.displayHeader();
				menu_Remove.displayBody(circuit);

				prev_state = 3;		//set last state to remove
				switch (input.getCh()){
					case 1:
						state = 1; //back to main menu
						break;
				}
				break;
			case 4:		// case state for undo menu
				menu_Undo.displayHeader();
				menu_Undo.displayBody(circuit);

				prev_state = 4;		//set last state to undo
				switch (input.getCh()){
					case 1:
						state = 1; //back to main menu
						break;
				}
				break;
			case 5:		// case state for display menu
				menu_Display.displayHeader();	
				menu_Display.displayBody(circuit);

				prev_state = 5;		//set last state to display
				switch (input.getCh()) {
					case 1: // main menu
						state  = 1;
						break;
					
				}
				break;
			case 6:			//case state for solve menu
				menu_Solve.displayHeader();
				menu_Solve.displayBody(circuit);
				
				prev_state = 6;		//set last state to solve
				switch (input.getCh()){
					case 1:
						state = 1; //back to main menu
						break;
				}
				break;
			case 7:
				menu_Read.displayHeader();
				menu_Read.displayBody(circuit);

				prev_state = 7;
				switch (input.getCh()){
					case 1:
						state = 1;	// back to main menu
						break;
				}
				break;
			case 8:
				menu_Write.displayHeader();
				menu_Read.displayBody(circuit);

				prev_state = 8;
				switch (input.getCh()){
					case 1:
						state = 1;  // back to main menu
						break;
				}
				break;
			case 9:			//quit quit
				quit = true;
				break;
			case 10:
				system(PCLEAR);
				menu_Main.displayHeader();
				cout << "ARE YOU READY? Y/N?" << endl;
				menu_Main.displayFooter();

				switch (input.getCh()) {
					case 'y':
					case 'Y':
						ShellExecute(NULL, "open", "http://corgiorgy.com", NULL, NULL, SW_SHOWNORMAL);
					case 'n':
					case 'N':
						state = prev_state;
				}

				break;
		}
	}
	return 0;
}
