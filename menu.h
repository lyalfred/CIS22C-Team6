#pragma once

#include <string>
#include <iomanip>
#include "HamiltonianCircuit.h"
#include "LInkedGraph.h"
#include "input.h"

using namespace std;

template <class Labeltype>
class Menu {

public:
	Input input;
	virtual void displayHeader();       //Top portion of our user interface display
	virtual void displayBody();			// The raw menu content
	virtual void displayFooter();
};

template <class Labeltype>
class MenuRead : public Menu<Labeltype> {
public:
	void displayHeader();
	void displayBody(HamiltonianCircuit& theGraph);
};

template <class Labeltype>
class MenuAdd : public Menu<Labeltype> {
public:
	void displayHeader();
	void displayBody(HamiltonianCircuit& theGraph);
};

template <class Labeltype>
class MenuRemove : public Menu<Labeltype> {
public:
	void displayHeader();
	void displayBody(HamiltonianCircuit& theGraph);
};

template <class Labeltype>
class MenuUndo : public Menu<Labeltype> {
public:
	void displayHeader();
	void displayBody(HamiltonianCircuit& theGraph);
};

template <class Labeltype>
class MenuDisplay : public Menu<Labeltype> {
public:
	void displayHeader();
	void displayBody(HamiltonianCircuit& theGraph);
	void displayHelper(const Labeltype& label);
};

template <class Labeltype>
class MenuSolve : public Menu<Labeltype> {
public:
	void displayHeader();
	void displayBody(HamiltonianCircuit& theGraph);
};

template <class Labeltype>
class MenuWrite : public Menu<Labeltype> {
public:
	void displayHeader();
	void displayBody(HamiltonianCircuit& theGraph);
};
