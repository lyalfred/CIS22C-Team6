//  Created by Frank M. Carrano and Tim Henry.
//  Copyright (c) 2013 __Pearson Education__. All rights reserved.
//  Modified by C. Lee-Klawender

/** A simple class of edges.
(Conceptually this is similar to the class "Entry")
@file Edge.h */

#ifndef _EDGE
#define _EDGE

using namespace std;

template<class LabelType>
class Edge
{
private:
	LabelType endVertex; // Cannot be changed as doing so changes the edge
	int       edgeWeight;

public:
	Edge();
	Edge(const LabelType& end);
	Edge(const LabelType& end, int weight);

	LabelType getEndVertex() const;
	int getWeight() const;
	void setWeight(const int newWeight);
}; // end Edge

template<class LabelType>
Edge<LabelType>::
Edge() : endVertex(LabelType()), edgeWeight(0)
{
}  // end default constructor

template<class LabelType>
Edge<LabelType>::
Edge(const LabelType& end) : endVertex(end), edgeWeight(0)
{
}  // end constructor

template<class LabelType>
Edge<LabelType>::
Edge(const LabelType& end, int weight) : endVertex(end), edgeWeight(weight)
{
}  // end constructor

template<class LabelType>
LabelType Edge<LabelType>::getEndVertex() const
{
	return endVertex;
}  // end getEndVertex

template<class LabelType>
int Edge<LabelType>::getWeight() const
{
	return edgeWeight;
}  // end getWeight

template<class LabelType>
void Edge<LabelType>::setWeight(const int newWeight)
{
	edgeWeight = newWeight;;
}  // end setWeight



#endif
