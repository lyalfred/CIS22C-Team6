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
	HamiltonianCircuit() :LinkedGraph<LabelType>() { hamiltonianWeight = 0; home = LabelType(); }

	//Destructor
	~HamiltonianCircuit() {};

	// Return total weight of the Hamiltonian Circuit
	int getHamWeight() const { return hamiltonianWeight; }

	//Mutator for home
	void setHome(LabelType h) { home = h; }


	/*find and display the Hamiltonian Circuit from the start vertex
	@param: startLabel name of the start vertex (home)
	@return true if the graph is completed and the HamiltonianCircuit is found*/
	bool displayHamiltonianC();

	// Save the Hamiltonian Circuit to file
	void saveHamiltonianC(ofstream &ofs);


	//Traversal functions
	void depthFirstTraversalH(void visit(LabelType&));
	void breadthFirstTraversalH(void visit(LabelType&));

	//Save to file
	bool saveToFileH(ofstream &ofs);

	//Return true if the vertex with label label exists
	bool existVertex(LabelType& label) { return (this->vertices).contains(label); }

	//Return true if the graph is the completed graph, false otherwise
	bool isCompleted() const { return this->getNumEdges() == (this->getNumVertices())*(this->getNumVertices() - 1) / 2; }

	//Overwrite add function, used to check the variable home and add value to home if
	// user uses add function for an empty graph whose home has not been set yet.
	bool add(LabelType& start, LabelType& end, int edgeWeight);

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
bool HamiltonianCircuit<LabelType>::add(LabelType& start, LabelType& end, int edgeWeight)
{
	bool status;

	status = this->LinkedGraph<LabelType>::add(start, end, edgeWeight);

	if (this->getNumVertices() == 2)
	{
		cout << "Enter your home point: ";
		getline(cin, home);
	}

	return status;
}

template <class LabelType>
void HamiltonianCircuit<LabelType>::breadthFirstTraversalH(void visit(LabelType&))
{
	if (this->getNumVertices() != 0)
	{
		this->breadthFirstTraversal(home, visit);
	}
	else
		cout << "Error: The graph is empty\n";
}

template <class LabelType>
void HamiltonianCircuit<LabelType>::depthFirstTraversalH(void visit(LabelType&))
{
	if (this->getNumVertices() != 0)
	{
		this->depthFirstTraversal(home, visit);
	}
	else
		cout << "Error: The graph is empty\n";
}


template <class LabelType>
bool HamiltonianCircuit<LabelType>::saveToFileH(ofstream &ofs)
{
	bool status;

	if (isCompleted())
	{
		status = this->saveToFile(home, ofs);
	}
	else
	{
		cout << "Error: Missing " << ((this->getNumVertices())*(this->getNumVertices() - 1) / 2) - this->getNumEdges()
			<< " connections. \nThe graph is not completed. \nCould not save to file.\n\n";

		status = false;
	}

	return status;
}

template <class LabelType>
void HamiltonianCircuit<LabelType>::saveHamiltonianC(ofstream &ofs)
{
	Vertex<LabelType>* start = 0, *end = 0;

	for (int n = 0; n < (int)hamiltonianC.size() - 1; n++)
	{
		start = hamiltonianC[n];
		end = hamiltonianC[n + 1];
		int weight = start->getEdgeWeight(end->getLabel());

		ofs << start->getLabel() << " - " << end->getLabel() << " - " << weight << endl;
	}
	ofs << "----------------" << endl;
	ofs << "Total weight: " << hamiltonianWeight << endl;
	
}


template <class LabelType>
bool HamiltonianCircuit<LabelType>::displayHamiltonianC()
{
	if (this->getNumVertices() == 0)
	{
		cout << "Error: the graph is empty\n\n";
		return false;
	}

	if (findHamiltonianC(home))
	{
		Vertex<LabelType>* start = 0, *end = 0;

		for (int n = 0; n < (int)hamiltonianC.size() - 1; n++)
		{
			start = hamiltonianC[n];
			end = hamiltonianC[n + 1];
			int weight = start->getEdgeWeight(end->getLabel());

			cout << start->getLabel() << " - " << end->getLabel() << "    " << weight << endl;
		}

		cout << "----------------" << endl;
		cout << "Total weight: " << hamiltonianWeight << endl;

		return true;
	}
	else
		return false;
}


template <class LabelType>
bool HamiltonianCircuit<LabelType>::findHamiltonianC(const LabelType& startLabel)
{
	if (!vertices.contains(startLabel))
		return false;

	if (!isCompleted())
	{
		cout << "Error: Missing " << ((this->getNumVertices())*(this->getNumVertices() - 1) / 2) - this->getNumEdges()
			<< " connections. \nThe graph is not completed. \nCan not find the circuit.\n\n";
		return false;
	}

	hamiltonianWeight = 0;
	this->unvisitVertices();


	Vertex<LabelType> *start = vertices.getItem(startLabel),  //The vertex at one end of the edge, initiallize it to the start vertex 
		*end = vertices.getItem(startLabel); // the vertex at the other end

	

	//Loop through all vertices of the graph
	for (int index = 0; index < vertices.getNumberOfItems() - 1; index++)
	{
		start->visit(); //Mark start vertex as visit
		hamiltonianC.push_back(start); // Push start vertex to the circuit

		start->resetNeighbor(); //Reset the iterator of the neighbor list of the start vertex

		//Get the first neighbor
		LabelType neighborLabel = start->getNextNeighbor();
		Vertex<LabelType>* neighbor = vertices.getItem(neighborLabel);

		int tempWeight = 10000000;

		if (!neighbor->isVisited()) //If the neighbor is not visited
		{
			tempWeight = start->getEdgeWeight(neighborLabel); //Assign the weight of the edge 
			//between start and its first neighbor to tempWeight
			end = neighbor;
		}


		//Loop through all of the neighbor of start
		for (int n = 0; n < start->getNumberOfNeighbors(); n++)
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

	//Push the last one to the vector and add its weight to the total weight
	hamiltonianC.push_back(start);

	hamiltonianC.push_back(vertices.getItem(startLabel));  //Push the starting point vertex to the vector again to finish the circuit.
	hamiltonianWeight += start->getEdgeWeight(startLabel); //Add the weight of edge between the end vertex and the starting point vertex to the total weight of the circuit

	return true;
}

# endif
