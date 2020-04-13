(a) What two data structures are used to implement Kruskal’s Algorithm?

A heap and disjoint sets. (disjoint sets made out of heap).
  
(b) Using big-O notation, indicate the running time of breadth-first search on a graph with
V vertices and no edges.

  O(V), checks each Vertice each time. no edges so no additional time needed.
  
(c) Draw a directed graph that does not have a legal topological sort.
  
  a topical sort is connected. this is not connected.
  
 A ----> B
/|\         |
 |          |
 |__________|

  Algos-
  (a) Under what conditions will Dijkstra’s Algorithm be more efficiently implemented using
a heap than with a table, if your graph is implemented using an adjacency list? Justify
your answer.

SPARSE OR NOT

  Dijkstra's Algo is more efficiently implmented using a heap, then with a table, if the graph has fewer edges
  or is considered sparce. then a heap is better, it improves time to search ofr a new vertex, processing 
  neigbbhors is expensive, if a nieghbors distance is changed you have to percolate the vertex upward in a heap lg(v) time.
  
   The more edges we have, the more neighbor updates we potentially have, and thus the more times we
run the part of the heap implementation that is more expensive than the corresponding
table implementation of the operation. With enough edges, this cost makes the overall
cost more expensive than the table implementation, despite the faster search time

    For sparse graphs, we don’t have quite so many edges, so the improved search time outweighs
the worsened update costs.
  
    b) Justify the correctness of the depth-first-search version of our topological sort algorithm.
You don’t need to justify the correctness of depth-first search – just explain why our use
of it to perform topological sort must assign numbers to the vertices in such a way that
the vertices are numbered in topological-sort order

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
  
  (c) In Prim’s Algorithm, we said you choose an edge at each step, from among all edges
that go from set S to set N. What do these two sets represent, and why would it be a
problem to pick an edge that goes between two vertices in S?

  set Vseen and set Vunseen
  
  it is a problem to take two items from a set because then they are both seen already
  and that means you've created a cylcle
 
  (d) Under what conditions would running breadth-first search on an undirected graph, result
in a breadth-first spanning forest of more than one tree, rather than a breadth-first
spanning tree? That is, what kinds of undirected graphs would result in that kind of
answer? Justify your answer.
  If graph is not conneceted then you have a forest of more then one tree.
  once we finished the first BFS then you have unmarked vertices., you have to start new trees.
  
  
  make a matrix  VxV
  step vs vertices.
  
 (a) What is the order of growth of the running time of finding the complement of a graph
(the graph with the exact same vertices and the exact opposite set of edges), if you have
a graph implemented with an adjaceny matrix? Express your answer in big-O notation
and justify your answer. Assume your adjaceny matrix implementation does have a one- dimensional 
array of vertex information, and that your adjacency matrix itself does not
have any “edge info” records, but rather, merely tells you if an edge exists or not. 
  
  Vertex
     does edge exist (bool)
  
  
  so you have VxV so v^2 to traverse through the matrix and flip every 0 to 1 and 1 to 0
  
  
  
(b) What is the order of growth of the running time of depth-first search on a graph with V
vertices and E edges? Express your answer in big-O notation and justify your answer.

  Each call to depth-first search:
• marks a vertex as “encountered”
• performs constant-time work on each neighbor of that vertex (checking the neighbor
to see if it has been marked )
• performs constant-time work on all unmarked neighbors (starting up a depth-firstsearch 
stackframe for that vertex neighbor, and eventually returning from that call)
  
And, since you only call depth-first-search on unmarked neighbors,
you make one callto depth-first-search for every vertex. 
 
  So, there is constant-time marking work for eachvertex, or O(V ) total.
    
    There is constant-time work inspecting a neighbor and possibly
starting (and later returning from) a depth-first-search call, for each neighbor, or, O(E)
total 
(since the total number of neighbors equals the total number of targets of departing
edges equals the total number of edges).
    
    Thus, the running time is O(V + E).
    
    
4. [Breadth-First Spanning Tree – 15 points].
You are given the following class:
class TreeNode {
  public:
  int vertexNumber;
  list<TreeNode*> subtrees; // initially an empty list; the function
    // push_back(item) will add item to
    // end of list
  };
In addition, you are given an adjacency matrix implementation of an unweighted, undirected,
connected graph – such a graph, when you run breadth-first search on it, would produce
a single spanning tree, rather than a spanning forest, no matter which vertex you start
at. In this adjacency matrix implementation, the graph has vertices labelled with indices 0
through n-1, and you are given the value n and a two-dimensional array with n rows and n
columns, both indexed from 0 through n-1. (In C++, a two-dimensional array is accessed
via expressions such as arr[i][j] where arr is of type int**.) You want to write a method
that takes those two values – the array and the n – as parameters, and returns a pointer
to the root of the breadth-first-spanning-tree of the graph. You are allowed to use as many
Queues as you like, as well as being allowed to create other one-dimensional arrays as well.

  
class TreeNode {
  public:
  int vertexNumber;
  list<TreeNode*> subtrees;
  };
TreeNode* BreadthFirstSpanningTree(int** graph, int n) {    
  Queue<TreeNode*> nodes;
  list of where we are 0 to n
  make new node root
  set root to be zero, any
  add root to stack
  move up mark to 1
  while (!nodesqueue.empty())) {
    dequeue first node and set it as temp
    set the index as temp vertex number of index
      for col 0
        for col index if
 
    
  
  
5. [Converting to undirected - 15 points].
Suppose you have a directed weighted graph of n vertices, where the vertex numbers are 1
through n, and the graph implementation is an adjacency list. The adjacency list is represented with an Array, indexed from 1 to n, of pointers to the following type:
class EdgeNode {
public:
int index; //index of target vertex
int weight; //weight of edge
EdgeNode* next; // ptr to next edge
};
         
  void ConvertToUndirected(Array<EdgeNode*>& graph) {
  
