// beginning
#pragma once

#include <string>
#include <iomanip>
using namespace std;

/*
include here
*/

class Menu {

protected:
	// data type classes here

public:
	static void Initialize();
	virtual void displayHeader();      //Top portion of our user interface display
	virtual void displayBody();		// The raw menu content
	virtual void displayFooter(); 	   //Bottom portion of user interface display
};

class MenuAdd : public Menu {
public:
	void displayHeader();
	void dispalyBody();

};

class MenuRemove : public Menu {
public:
	void displayHeader();
	void dispalyBody();
};

class MenuUndo : public Menu {
public:
	void displayHeader();
	void dispalyBody();
};

class MenuDisplay : public Menu {
public:
	void displayHeader();
	void dispalyBody();
};

class MenuSolve : public Menu {
public:
	void displayHeader();
	void dispalyBody();
};
