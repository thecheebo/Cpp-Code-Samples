(b) Using big-O notation, indicate the running time of breadth-first search on a graph with
V vertices and no edges.

O(V ).

  
  (d) Under what conditions would running breadth-first search on an undirected graph, result
in a breadth-first spanning forest of more than one tree, rather than a breadth-first
spanning tree? That is, what kinds of undirected graphs would result in that kind of
answer? Justify your answer.
  
  
If the undirected graph is NOT connected, then there will not be a path from the start
vertex, to every other vertex in the graph, and thus we will not be able to reach every
other vertex once we begin searching from our start vertex. This means once we finish
our first tree in the breadth-first search, there will still be unmarked vertices, meaning
we won’t have a single breadth-first spanning tree, but rather, will have to start one or
more additional trees to get those other vertices.
