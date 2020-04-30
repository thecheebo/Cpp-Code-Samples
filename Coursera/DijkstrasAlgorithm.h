(a) Under what conditions will Dijkstra’s Algorithm be more efficiently implemented using
a heap than with a table, if your graph is implemented using an adjacency list? Justify
your answer.
If your graph implemented with an adjacency list is sparse (i.e. has relatively few edges
out of the number of edges it could have, for that number of vertices), then the heap
implementation will be better. The heap implementation improves the time to search
for a new vertex, but processing each neighbor of a given vertex is more expensive, since
now, if the neighbor’s distance is changed, you don’t just change a table entry (O(1)), but
you also must (potentially) percolate the vertex upward in a heap (O(lg V ), to reflect its
lowered priority (i.e. lowered distance, since distance equals priority). The more edges
we have, the more neighbor updates we potentially have, and thus the more times we
run the part of the heap implementation that is more expensive than the corresponding
table implementation of the operation. With enough edges, this cost makes the overall
cost more expensive than the table implementation, despite the faster search time. For
sparse graphs, we don’t have quite so many edges, so the improved search time outweighs
the worsened update costs.


 (e) For the given graph, run Dijkstra’s algorithm, indicating in the table below the distances
at each vertex at the end of each step (dv), and whether or not the vertex has been marked
known yet at the end of each step (kv). The initialization has already been done for you.
A B C D E F G
A 0 8 3 0 0 0 0
B 0 0 0 0 0 16 18
C 0 3 0 0 0 0 20
D 0 0 0 0 0 0 19
E 5 0 12 2 0 0 0
F 0 0 0 0 0 0 0
G 0 0 0 0 0 10 0
V dv kv dv kv dv kv dv kv dv kv dv kv dv kv dv kv
A ∞ 0 5 0 5 0 5 1 5 1 5 1 5 1 5 1
B ∞ 0 ∞ 0 ∞ 0 13 0 11 0 11 1 11 1 11 1
C ∞ 0 12 0 12 0 8 0 8 1 8 1 8 1 8 1
D ∞ 0 2 0 2 1 2 1 2 1 2 1 2 1 2 1
E 0 0 0 1 0 1 0 1 0 1 0 1 0 1 0 1
F ∞ 0 ∞ 0 ∞ 0 ∞ 0 ∞ 0 27 0 27 0 27 1
G ∞ 0 ∞ 0 21 0 21 0 21 0 21 0 21 1 21 1
- Start Step 1 Step 2 Step 3 Step 4 Step 5 Step 6 Step 7
