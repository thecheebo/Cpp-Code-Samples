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
