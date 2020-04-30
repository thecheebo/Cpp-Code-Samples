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


***  Question ***
If a B-Tree is completely filled, meaning every node holds its maximum number of keys and all non-leaf nodes has
the maximum number of children, then what happens when an additional key is inserted into the B-Tree?


***  Answer ***
After searching for the leaf node where the new key should go, the leaf is split in half as two separate leaf nodes,
and then the middle value is thrown up to the layer above as an inserted key, and this insertion and rebalancing
repeats until a new root key rises to the top, which adds a layer to the tree.
  
  
  
***  Question ***

  (e) Explain convincingly that for a B-Tree of order b (remember, we said the order, b, would
always be an odd number), splitting a B-tree node during an insertion must always leave
an extra index value that could be moved into the parent of the split node.
  ***  Answer ***
The maximum number of children a B-tree node is allowed to have is b children, and you
always have one fewer indices than children. So, if the node is overflowing, it means you
have b+1 children and thus b indices. When you split that, half the children go to each
half, so each half gets (b+1)/2 children, and since you always have one fewer indices
than children, each half should also have ((b+1)/2)-1 indices. But, if each half has
((b+1)/2)-1 indices, the two halves together have (((b+1)/2)-1) + (((b+1)/2)-1)
indices, which equals b-1 indices. Yet, our node before the split had b indices. So, we
know there is an index left over that was not placed in either of the two halves of the
split.
  
  
  *** QUESTION ***
  
  (c) After performing a combine operation during B-Tree removal, why is it that we need to
check the parent for underflow? i.e. justify that such a combine operation could have
caused the parent to underflow.
  
Combining a node merges two nodes into one...so where the parent used to have two
nodes, it now has just one. So if the parent had the minumum number of children before,
it now has one less than the minimum number of children, because two of those children
have been combined into one.

