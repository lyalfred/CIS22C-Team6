#pragma once

#include <string>
#include <iomanip>
//#include "HamiltonianCircuit.h"
//#include "LinkedGraph.h"

using namespace std;

class Menu {

protected:
	

public:
//	static void Initialize();
	virtual void displayHeader();       //Top portion of our user interface display
	virtual void displayBody();			// The raw menu content
	virtual void displayFooter(); 	   
};

class MenuRead : public Menu {
public:
	void displayHeader();
	void displayBody();
};

class MenuAdd : public Menu {
public:
	void displayHeader();
	void displayBody();
};

class MenuRemove : public Menu {
public:
	void displayHeader();
	void displayBody();
};

class MenuUndo : public Menu {
public:
	void displayHeader();
	void displayBody();
};

class MenuDisplay : public Menu {
public:
	void displayHeader();
	void displayBody();
};

class MenuSolve : public Menu {
public:
	void displayHeader();
	void displayBody();
};

class MenuWrite : public Menu {
public:
	void displayHeader();
	void displayBody();
};
