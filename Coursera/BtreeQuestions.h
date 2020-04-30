MC5 (2.5pts)
Suppose an order m B-tree contains n items. In the worst-case, how many CPU operations
would be required to search the tree for a specific key?
(a) O(log2 n)
(b) O(logm n)
(c) O(m log2 n)
(d) O(m log2 m)
(e) O(m logm n) <-- 

QUESTION: Which one of the following is NOT a valid reason to choose the B-Tree representation over a standard AVL binary search tree?


B-Trees have better algorithmic "Big-O" run-time complexity for the find operation. *** FALSE***
B-Trees require fewer block read accesses for tree operations.
B-Trees run faster on large data sets than do AVL trees.
B-Trees work faster in networked cloud environments than do AVL trees.

Correct
While the B-Tree find operation runs in O(log_m n) time, the m ends up being a constant factor and O(log_m n) = O(lg n)
as a consequence of the big-O characterization of how run time increases as the number of data items (n) increases.


Which of the following statements is NOT true for a B-Tree of order m?

all true:
Each node can have at most one more child than key.
Any node that is not the root or a leaf holds at least half of the total number of keys allowed in a node.
All leaf nodes are at the same level of the B-Tree.



If a B-Tree is completely filled, meaning every node holds its maximum number of keys and all non-leaf nodes has
the maximum number of children, then what happens when an additional key is inserted into the B-Tree?


After searching for the leaf node where the new key should go, the leaf is split in half as two separate leaf nodes,
and then the middle value is thrown up to the layer above as an inserted key, and this insertion and rebalancing
repeats until a new root key rises to the top, which adds a layer to the tree.

