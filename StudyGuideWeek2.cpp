Week 1:

  

Pointers
Memory Leaks
Constructors
Deconstructors

Inheritance
Template



Week 2:
Arrays
Big O
Array/List Operations
Queue/Stack


BinaryTree Traversal Code:

*** PRE ORDER ***

void print(TreeNode *node){
    if (!node) return;
    std::cout << node->key << " ";
    print(node->left);
    print(node->right);
}

*** IN ORDER ***
void print(TreeNode *node){
    if (!node) return;
    print(node->left);
    std::cout << node->key << " ";
    print(node->right);
}

*** POST ORDER ***

void print(TreeNode *node){
    if (!node) return;
    print(node->left);
    print(node->right);
    std::cout << node->key << " ";
}

*** AVL TREES ***

5.Question 5
The code that ensures the balance of an AVL tree after node insertion or removal only checks if the height balance
factor is +2 or -2. What happens if the height balance factor of a node in an AVL tree after node insertion or
removal is greater that +2 or less than -2?

An AVL tree never has a node with a height balance factor greater than +2 or less than -2, even after a node insertion or removal.

Correct
Every node in an AVL tree has a height balance factor of -1, 0 or 1. Inserting a node can increase the height of a
subtree by only 1, and so can change the height balance factor of any node to no more than 2 or no less than -2.
Similarly, a node in a any binary search tree is removed by either by deleting a leaf node, shortening a chain of
nodes by removing a node with a single child, or replacing a node with its immediate ordered predecessor, and all
three of these operations change the height of a subtree by no greater than +1 or no less than -1.

Question 6
If, after inserting a new node into an AVL tree, you now have a node with a height balance factor of -2 with a child with a 
height balance factor of -1, which of the following operations should be performed?

RIGHT ROTATION

Since the parent and child height balance share the same sign, that means that there is a "stick" that needs to be rotated 
to form a "mountain." Since the shared sign of the height balance factors is negative, this means the left subtree is the 
cause of the imbalance and should be resolved by a right rotation.

8)
Which one of the following is NOT a valid reason to choose the B-Tree representation over a standard AVL binary search tree


B-Trees have better algorithmic "Big-O" run-time complexity for the find operation.  NOT VALID REASON


B-Trees require fewer block read accesses for tree operations.


B-Trees run faster on large data sets than do AVL trees.


B-Trees work faster in networked cloud environments than do AVL trees.

Correct
While the B-Tree find operation runs in O(log_m n) time, the m ends up being a constant factor and O(log_m n) = O(lg n) as a
consequence of the big-O characterization of how run time increases as the number of data items (n) increases.

Question 9

Which of the following statements is NOT true for a B-Tree of order m?


Each node can have at most one more child than key.


Any node that is not the root or a leaf holds at least half of the total number of keys allowed in a node.


All leaf nodes are at the same level of the B-Tree.


Each node can hold an ordered list of as many as m keys. FALSE must be M-1

Correct
This statement is indeed false. In an order-m B-tree, each tree node indeed holds multiple keys, but the number of
keys is limited to m-1.

10)
If a B-Tree is completely filled, meaning every node holds its maximum number of keys and all non-leaf nodes has the
maximum number of children, then what happens when an additional key is inserted into the B-Tree?


After searching for the leaf node where the new key should go, the leaf is split in half as two separate leaf nodes,
and then the middle value is thrown up to the layer above as an inserted key, and this insertion and rebalancing repeats
until a new root key rises to the top, which adds a layer to the tree.

B-Tree Properties
For a B-Tree of order M
1) all keyse within a node are in sorted node
2)Each node contains no more then m-1 Keys
3) each internal node has exactly one more child than key
(at most m children, so a B tree of order ms is like an M way tree)?"?? wtf is a m-way tree
a Root node can be a leaf or have [2 to M children.
-each non-root internal node has [ max ceiling m/2), to M] children
4. all leaves are on the same level.
5. Nice to have M value = odd

The  height of the Btree determines maximum number of seeks possible in serach Data,

And the height of the structure is Log m (n).  m is usually very high maybe 1001 or more

Therefore the number of seeks is no more than log m (n)

heap quiz
4)
How should one insert a new value into a heap to most efficiently maintain a balanced tree?


Maintain the heap as a complete tree and insert a new value at the one new node position that
keeps the tree as a complete tree. Then continually exchange the new value with the value of its 
parent until the new value is in node where it is greater than the value of its parent.

Correct
This is the best way to maintain a balanced heap, but requires back propagation to ensure the min-heap properly remains valid.

5)
The removeMin operation removes the root of a min-heap tree. Which of the following implements removeMin efficiently while 
maintaining a balanced min-heap tree.


Replace the root value with the value of the last leaf (rightmost node at the bottom level) of a complete binary tree, 
and delete the last leaf. Then repeatedly exchange this last-leaf value with the smaller of the values of its node's 
children until this last-leaf value is smaller than the values of its node's children, if any.

6.Question 6
How many nodes of a complete binary tree are leaf nodes?


About half.

Correct
Let n be the number of nodes in the complete binary tree. If the complete binary tree is also a perfect tree, then all
of the leaf nodes 
are at the bottom level, and there are exactly n/2 + 1/2 of them. (n is odd for a perfect binary tree.)

Now consider deleting these nodes one at a time in an order that keeps the tree complete. The first node you delete 
is the right child of a parent so it decreases n by one and decreases the number of leaf cells by one. The second node 
you delete will be that parent's left child, turning the parent into a new leaf node, so decreasing n by one but not 
decreasing the number of leaf nodes. As you continue removing leaf nodes from right to left on that bottom level, you
are reducing n by one but the number of leaf nodes by an average of 1/2 (by one for every right child and by zero for 
every left child).

Hence about half of a perfect binary tree's nodes are leaf nodes, and this continues as you delete any or all of the
nodes in the bottom level in a right-to-left order that keeps the binary tree complete.

8)
What is the run-time algorithmic complexity of calling heapifyDown on every non-leaf node in a complete tree of n nodes?

O(n)

Correct
The run-time of calling heapifyDown on a node is proportional to the height of the node. About half of the nodes are leaf
nodes, about a quarter have height 1, about an eighth have height 2, about a sixteenth have height 3, and so on. This
summation of heights converges to n, the number of nodes in the tree. Hence running heapifyDown on every non-leaf node
has a run-time complexity of O(n).

9)
Which of the following is the fastest way to build a heap of n items?


Create a complete tree of the items in any order, then call heapifyDown on every non-leaf node from the bottom of the 
tree up to the root.

