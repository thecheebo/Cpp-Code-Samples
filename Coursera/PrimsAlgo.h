(c) In Prim’s Algorithm, we said you choose an edge at each step, from among all edges
that go from set S to set N. What do these two sets represent, and why would it be a
problem to pick an edge that goes between two vertices in S?

Set S is the set of all vertices that have been added to the tree; set N is the set of all
vertices not yet added to the tree. If we chose an edge between two vertices in S, that
means we are connecting two vertices that are both already in the tree – that is, we are
connecting two vertices that are both already connected to each other. This means we
are connecting them a second way – which means we have created a cycle.
