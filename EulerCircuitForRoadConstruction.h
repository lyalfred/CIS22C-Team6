bool EulerCircuit()
{
  V: set of all vertices
    //check if there is any vertex that has an odd number of edges
    bool found = false;
    
    for(int n = 0; (n < number of vertex)||; n++)
    {
      if(V[n] has an odd number of edges)
        found = true
    }
    
    //Since Euler circuit only exists when all of the vertices have an even number of edges,
    //if there is only one vertex that has an odd number of edges, return false
    if(found)
      return false
      
    Get one vertex from V, assign it to startVertex.
    stack S: a stack of vertices;
    while(startVertex has no unvisited neighbor && S is empty)
    {
      if(startVertex has no unvisited neighbor)
       Add startVertex to the set eCircuit;
      else
      {
        Add startVertex to stack S;
        Get one of startVertex neighbor, assign it to endVertex;
        Remove the edge (startVertex - endVertex)
        startVertex = endVertex;
      }
    }
    
      
    
}
