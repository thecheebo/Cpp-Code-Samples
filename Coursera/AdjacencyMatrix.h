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
