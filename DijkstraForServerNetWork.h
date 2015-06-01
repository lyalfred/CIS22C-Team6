void Dijkstra(Vertex s)
{
	dist: array of distances from the source to each vertex
	prev : array of pointers to preceding vertices
	V: array of vertices of the graph

	i : loop index
	F : list of finished vertices
	U : list of unfinished vertices
			

	/* Initialization: set every distance to INFINITY (MAX_DISTANCE) until we discover a path */

	for (i = 0; i < (size of V) - 1; i++)
	{
		dist[i] = MAX_DISTANCE
		prev[i] = NULL
	}
	
	/* The distance from the source to the source is defined to be zero */
	dist[s] = 0


	while (size of U != 0)
	{
		pick the vertex, v, in U with the shortest path to s
		add v to F
		for each edge of v, (v1, v2)
		{
			if (dist[v1] + length(v1, v2) < dist[v2])
			{
				dist[v2] = dist[v1] + length(v1, v2)
				prev[v2] = v1
			}
				
		}
			
		delete v from U
					

	}
		  
		   

}
