(b) Justify the correctness of the depth-first-search version of our topological sort algorithm.

You don’t need to justify the correctness of depth-first search – just explain why our use
of it to perform topological sort must assign numbers to the vertices in such a way that
the vertices are numbered in topological-sort order.

Our algorithm assigned integers from 1...V in reverse order – that is, V was assigned
first, then V-1, and so on. In addition, our modification of depth-first search assigned a
number to a vertex only after all the neighbors had been explored with depth-first-search
(and thus numbered, since you number a vertex before returning from the depth-firstsearch 
call on that vertex). So, we know that for any vertex, its neighbors all get
numbers before that vertex gets a number. And since we number in reverse order, that
must mean the neighbors of a vertex always get higher numbers than the vertex itself,
since the higher numbers get assigned first and the neighbors receive numbers first. And,
the definition of topological sort is that every vertex appears before its neighbors in the
ordering – so we are done, since now every vertex has a lower number than its neighbors.

  (b) What is the order of growth of the running time of depth-first search on a graph with V
vertices and E edges? Express your answer in big-O notation and justify your answer.
  
Each call to depth-first search:
• marks a vertex as “encountered”
• performs constant-time work on each neighbor of that vertex (checking the neighbor
to see if it has been marked )
• performs constant-time work on all unmarked neighbors (starting up a depth-firstsearch stackframe for that vertex neighbor, and eventually returning from that call)
And, since you only call depth-first-search on unmarked neighbors, you make one call
to depth-first-search for every vertex. So, there is constant-time marking work for each
vertex, or O(V ) total. There is constant-time work inspecting a neighbor and possibly
starting (and later returning from) a depth-first-search call, for each neighbor, or, O(E)
total (since the total number of neighbors equals the total number of targets of departing
edges equals the total number of edges). Thus, the running time is O(V + E).
