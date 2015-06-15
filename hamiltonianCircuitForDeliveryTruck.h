void hamitonianCircuit(Vertex s)
{
  Vertex startVertex = s, endVertex;
  notDoneVertices: the set of all vertices that are not visited, initially all vertices in the graph except s.
  doneVertices: the set of vertices that was visited.
  
  Add s to doneVertices.
  startVertex = s;
  
  while(notDoneVertices is not empty)
  {
    Find the edge that starts from startVertex and has the smallest value. 
    endVertex = the vertex at the other end of the edge;
    endVertex.setPrev(startVertex);
  
    startVertex = endVertex;
    Move endVertex from notDoneVertices to doneVertices;
  }
  
  s.setPrev(endVertex);
  
}
