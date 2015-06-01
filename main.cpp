// beginning
#include <iostream>
#include <windows.h>
#include <cstdlib>
using namespate std;

/*
Include #include's here
*/

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
	// declare Classes Here

	//Menu modules
	Menu::Initialize();
	Menu
	MenuADD

	//Main globals
	int state = 0;		// 0 - splash page
						// 1 - main menu
						// 2 - add menu
						// 3 - remove menu
						// 4 - undo menu
						// 5 - display menu
						// 6 - solve menu
	int prev_state = 0;

	int substate = 0;	// 0 - None
						// 1 - Depth First Search
						// 2 - Breadth First Search

	bool quit = false;

	while(!quit){

	//Prompt program splash

		// use switch/cases to cycle between menu states
	switch(state)
		case 0: //slash menu
		case 1: // main menu
			switch(state)
				case 1: // add menu
					// set state to 2
				case 2: //remove menu
					// set state to 3
				case 3: //undo menu
					// set state to 4
				case 4: //display menu
					// set state to 5
				case 5: //solve menu
					// set state to 6
		case 2: 
			//menu option for add menu
		case 3: 
			// menu option for remove menu
		case 4:
			// menu option for undo menu
		case 5:
			// menu option for display menu
			switch(substate)
				case 1:
					// DFS
				case 2:
					// BFS
		case 6:
			// menu option for solve menu
		}
	}
}
