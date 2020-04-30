(b) Using big-O notation, indicate the running time of breadth-first search on a graph with
V vertices and no edges.

   O(V).

  
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

  
  (c) When we implement breadth-first-search, it is important that we mark a vertex as “encountered” 
  before it is enqueued, rather than after it is dequeued. Explain why it is
important – i.e. explain why we couldn’t instead choose to mark a vertex “encountered”
after dequeueing it.
  
When we dequeue a vertex, we will proceed to inspect its neighbors. If one of those
neighbors is on the queue already, but not marked “encountered”, we would add it to
the queue a second time. And therefore, we would ultimately dequeue that neighbor
twice and process it twice. Marking vertices as “encountered” once we have first reached
them prevents us from adding a vertex to the queue multiple times, since every time we
reach that vertex after the first time we reach it, it will already have the “encountered”
flag set and we will therefore ignore that vertex.
