(a) What is the order of growth of the running time of finding the complement of a graph
(the graph with the exact same vertices and the exact opposite set of edges), if you have
a graph implemented with an adjaceny matrix? Express your answer in big-O notation
and justify your answer. Assume your adjaceny matrix implementation does have a onedimensional
array of vertex information, and that your adjacency matrix itself does not
have any “edge info” records, but rather, merely tells you if an edge exists or not.


The complement of a graph implemented by an adjacency matrix, would be obtained
simply by ”removing” every edge that does exist and then ”adding” every edge that did
not exist. That is, you flip every 1 in the matrix to 0 and flip every cell that used to
be 0, to 1. Traversing the adjacency array to do this – or to copy the values into a
new adjacency array and then do this operation to that array – will take O(V
2) time.Copying the one-dimensional array of vertex information will take O(V ) time. Thus,
the total is O(V^2).

  
  
  
  2. [Vertices Nearby – 20 points].
You are given an adjacency matrix implementation of an unweighted, directed graph – the
graph has vertices labelled with indices 0 through n-1, and you are given the value n and a
two-dimensional array with n rows and n columns, both indexed from 0 through n-1. You
want to write a method that takes those two values (the integer n and an int** to the
two-dimensional array) and returns a 1 if the distance from any vertex to any other vertex is
always 2 or less, and returns a 0 if there is at least one vertex for which the minimum distance
to some other vertex is 3 or more. You are allowed to create additional one-dimensional arrays
if you need to.
int DistanceCheck(int** graph, int n) {
  // your code goes here
  int thereIsNotABadVertexYet = 1;
  int currVertex = 0;
  int* marks = new int[n];
  while ((thereIsNotABadVertexYet) && (currVert < n)) {
    for (int i = 0; i < n; i++)
      marks[i] = 0;
    marks[currVert] = 1;
    for (int i = 0; i < n; i++) {
    if (graph[currVert][i] == 1) {
      marks[i] = 1; // mark everything one away from currVert
        for (int j = 0; j < n; j++)
          if (graph[i][j] == 1)
            marks[j] = 1; // mark everything one away from what is
    // one away from currVert
    }
    }
    int i = 0;
    while ((thereIsNotABadVertexYet) && (i < n))
      if (marks[i] == 0)
       thereIsNotABadVertexYet = 0;
    else
    i++;
    }
    if (thereIsNotABadVertexYet == 1)
    currVert++;
}
delete[] marks;
return (currVert == n);
}
