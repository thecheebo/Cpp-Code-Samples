(a) What two data structures are used to implement Kruskal’s Algorithm?
Heaps and Disjoint Sets

(d) Explain cycle detection for Kruskal’s algorithm. That is, explain why disjoint sets are
used for this part of the algorithm (i.e. explain what the equivalence relation is that
we are trying to model with our disjoint sets structure), and explain how the disjoint
sets structure gets used to figure out whether to accept or reject an edge that is being
considered.
  
The equivalence relation we are trying to model is “two vertices are in the same connected
component of the MST we are in the midddle of building”. Certainly every vertex is
in the same connected component as itself, and if A and B are in the same connected
component, then it means B and A are as well. Futhermore, by the very defintion of
connection, if A and B are in the same connected component and B and C are, then A
and C must be. So we have reflexivity, symmetry, and transitivity.
  
As a result, we can use the disjoint set structure to determine if two vertices are in the
same connected component – if they are in the same set, they are in the same connected
component, and if they are in different sets, then they are in different connected components.
  Every time we add an edge between two connected components, we are merging
them into one connected component, and likewise we should union the disjoint sets that
represent them. And, if an edge is going to be added between two vertices that are
already conected (i.e. already in the same connected component), that would be a cycle,
so saying “these two vertices are in the same connected component” (which is saying
“these two vertices are in the same set”) is the same as saying “these two vertices are
already connected” which is the same as saying, “there would be a cycle created if these
two vertices are connected again, by putting an edge between them”.
