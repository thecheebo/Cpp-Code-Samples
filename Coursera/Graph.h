(c) Draw a directed graph that does not have a legal topological sort.
There are many. Here is the simplest one:
A ----> B
/|\ |
| |
|________|
The presence of a cycle means that there is no topological sort. Please note that the
absence of edges means there is a topological sort – in fact, in a graph with no edges,
every possible ordering of the vertices is a topological sort, since no ordering places a
target before its source.
