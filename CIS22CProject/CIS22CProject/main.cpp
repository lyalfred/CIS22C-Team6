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

//For Display Graph Option
#define STATE_SUB_DFT   1		
#define STATE_SUB_BFT   2

int main() {

	HamiltonianCircuit<class LabelType> circuit;

	Input input;
	//Menu modules
	Menu::Initialize();
	Menu			menu_Main;
	MenuAdd			menu_Add;
	MenuRemove		menu_Remove;
	MenuUndo		menu_Undo;
	MenuDisplay		menu_Display;
	MenuSolve		menu_Solve;


		//Main globals
	int state = 0;			// 0 - splash page
							// 1 - main menu	
							// 2 - add menu
							// 3 - remove menu
							// 4 - undo menu
							// 5 - display menu
							// 6 - solve menu
	int prev_state = 0;

	int substate = 0;		// 0 - None
							// 1 - Depth First Search
							// 2 - Breadth First Search

	bool quit = false;

	while (!quit){

		//Prompt program splash

		// use switch/cases to cycle between menu states
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
				}
			case 2:		// case state add menu
				
				break;
			case 3:		// case state for remove menu
			
				break;
			case 4:		// case state for undo menu
			
				break;
			case 5:		// case state for display menu
			
				switch (substate) {
					case 1:	//DFS
					
						break;
					case 2:	// BFS

						break;
					}
				break;
			case 6:
				// menu option for solve menu

				break;			
		}
	}

	system("pause");
	return 0;
}