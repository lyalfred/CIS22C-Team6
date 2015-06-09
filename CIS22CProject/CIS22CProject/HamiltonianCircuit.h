# ifndef _HAMILTONIANCIRCUIT_H
# define _HAMILTONIANCIRCUIT_H

# include "LinkedGraph.h"
# include <vector>
# include <iostream>

using namespace std;


template <class LabelType>
class HamiltonianCircuit : public LinkedGraph <LabelType>
{
public:
	//Default constructor
	HamiltonianCircuit() :LinkedGraph<LabelType>() { hamiltonianWeight = 0; home = 0; }

	//Destructor
	~HamiltonianCircuit() {};

	// Return total weight of the Hamiltonian Circuit
	int getWeight() const { return hamiltonianWeight; }


	/*find and display the Hamiltonian Circuit from the start vertex
	@param: startLabel name of the start vertex (home) */
	void displayHamiltonianC(const LabelType& startLabel);


	// Save the Hamiltonian Circuit to file
	void saveHamiltonianC(ofstream &ofs);

private:
	/*find the Hamiltonian Circuit from a given vertex
	@param: startLabel  the label of the start vertex (home)
	@post: the queue hamiltonianC contains the Hamiltonian Circuit in order
	the int hamiltonianWeight stores the total weight of all the edges in Hamiltonian Circuit.
	@return: true if the vertex whose label is startLabel is in the graph.
	false if the vertex whose label is startLabel is not in the graph.
	*/
	bool findHamiltonianC(const LabelType& startLabel);

private:
	vector<Vertex<LabelType>*> hamiltonianC; // the vector contains Hamiltonian Circuit
	int hamiltonianWeight; //total weight of all the edges in Hamiltonian Circuit
	LabelType home; // Label of the home vertex (the starting point)
};

template <class LabelType>
void HamiltonianCircuit<LabelType>::saveHamiltonianC(ofstream &ofs)
{
	Vertex<LabelType>* start = 0, *end = 0;

	for (int n = 0; n < hamiltonianC.size() - 1; n++)
	{
		start = hamiltonianC[n];
		end = hamiltonianC[n + 1];
		int weight = start->getEdgeWeight(end->getLabel());

		ofs << start->getLabel() << " - " << end->getLabel() << "    " << weight << endl;
	}
	ofs << "----------------" << endl;
	ofs << "Total weight: " << hamiltonianWeight << endl;
}


template <class LabelType>
void HamiltonianCircuit<LabelType>::displayHamiltonianC(const LabelType& startLabel)
{
	if (findHamiltonianC(startLabel))
	{
		Vertex<LabelType>* start = 0, *end = 0;

		for (int n = 0; n < hamiltonianC.size() - 1; n++)
		{
			start = hamiltonianC[n];
			end = hamiltonianC[n + 1];
			int weight = start->getEdgeWeight(end->getLabel());

			cout << start->getLabel() << " - " << end->getLabel() << "    " << weight << endl;
		}

		cout << "----------------" << endl;
		cout << "Total weight: " << hamiltonianWeight << endl;
	}
	else
		cout << "Error: Could not find " << startLabel << endl;
}


template <class LabelType>
bool HamiltonianCircuit<LabelType>::findHamiltonianC(const LabelType& startLabel)
{
	if (!vertices.contains(startLabel))
		return false;


	hamiltonianWeight = 0;

	Vertex<LabelType> *start = vertices.getItem(startLabel),  //The vertex at one end of the edge, initiallize it to the start vertex 
		*end; // the vertex at the other end

	//Loop through all vertices of the graph
	for (int index = 0; index < vertices.getNumberOfItems(); index++)
	{
		start->visit(); //Mark start vertex as visit
		hamiltonianC.push_back(start); // Push start vertex to the circuit

		start->resetNeighbor(); //Reset the iterator of the neighbor list of the start vertex

		//Get the first neighbor
		LabelType neighborLabel = start->getNextNeighbor();
		Vertex<LabelType>* neighbor = vertices.getItem(neighborLabel);


		int tempWeight;
		if (!neighbor->isVisited()) //If the neighbor is not visited
			tempWeight = start->getEdgeWeight(neighborLabel); //Assign the weight of the edge 
		//between start and its first neighbor to tempWeight

		//Loop through all of the neighbor of start
		for (int n = 0; n < (start->getNumberOfNeighbors() - 1); n++)
		{
			neighborLabel = start->getNextNeighbor();
			neighbor = vertices.getItem(neighborLabel);
			if (!neighbor->isVisited()) //if the neighbor is not visited yet
			{
				if (tempWeight > start->getEdgeWeight(neighborLabel)) //if tempWeight > the edge between start and the neighbor
				{
					tempWeight = start->getEdgeWeight(neighborLabel); //assign the weight of the edge to tempWeight
					end = neighbor; // assign neighbor to end
				}

			}
		}

		hamiltonianWeight += tempWeight;  //Add tempWeight to the total weight of the circuit
		start = end; // Assign end vertex to start vertex to start another loop
	}

	hamiltonianC.push_back(vertices.getItem(startLabel));  //Push the starting point vertex to the vector again to finish the circuit.
	hamiltonianWeight += start->getEdgeWeight(startLabel); //Add the weight of edge between the end vertex and the starting point vertex to the total weight of the circuit

	return true;
}

# endif