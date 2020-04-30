Question 1) Which of the following is the strongest valid statement made about AVL trees?

(b) They are height-balanced trees

Question 2) The AVL Tree balance property was that for any node, the two subtrees of that node
differed by at most 1 in height. Why not 0? That is, explain convincingly that requiring
each node to have two subtrees of equal height would be problematic.
  
  
Such a requirement simply isn’t possible to meet for many trees. For example, if you
have four values, one must be at the root, two values on one side of the root, and one
value on the other side of the root. The side with one node is a subtree of height 0; there
is no way to arrange the two nodes on the other side to form a subtree of height 0.
  
Question 3) 

  (c) Insert the integers 1 through 6, in that order, into an AVL tree. Draw the resulting
tree. How many rotation operations, total, did you perform? Count a “double rotation”
operation as one rotation operation.
3 rotations total

   4
  / \
 2   5
/ \   \
1 3    6
  
Question 4)
  
  In an AVL tree, why does storing the height of a subtree, in the root node of that subtree,
improve the efficiency of the AVL rebalancing work (versus not storing the height at all)?
  
  answer
We want to be able to recalculate the height of a node quickly, and yet, to calculate the
height of a node, we would need to find the heights of both subtrees, so that we could
compare the heights and do the appropriate arithmetic. If the height of every node is
stored in that node, then given a pointer to a node, learning the heights of that node’s
children is simply a matter of reading them from the child nodes – which is constant
time. But if we need to calculate the height of your node from scratch, then we will
need to make a recursive call on every descendant of that node, which could take as
long as linear time, rather than constant time. So, storing heights in nodes means that,
at each node, knowing the heights of subtrees (which we need for rebalancing) can be
accomplished in constant time, not linear time.
  
  
  
Question 5) 
void AVLTree::rotateLeft(AVLTreeNode * & node) {
// no need to check for conditions, as they are supposed
// to be checked before calling this function
AVLTreeNode* y = node;
node = node->right;
y->right = node->left;
node->left = y;
y->height = height(y);
}


You are given the AVLTreeNode class shown on page 8 of the exam. You want to write a
function doubleRight that has one parameter and returns nothing. The parameter will be
of type reference-to-pointer-to-AVLTreeNode. You can assume this parameter points to the
root of a subtree for which it is possible to perform a double right rotation. The function
should perform that rotation – including fixing the heights of whatever nodes will need their
heights fixed. You can assume all heights in all nodes, are correct prior to the double rotation
operation.

class AVLTreeNode { // needed for problem 1
public:
  int element;
  int height;
  AVLTreeNode* left;
  AVLTreeNode* right;
};


void doubleRight(AVLTreeNode * & ptr) {
// your code goes here
TreeNode* firstRot = ptr->left;
TreeNode* temp = firstRot->right;
firstRot->right = temp->left;
temp->left = firstRot;
firstRot = temp;
// fix height
ptr->left = temp->right;
temp->right = ptr;
ptr = temp;
// fix height

  QUESTOITOINT*%*&%(@*(#&%
  (b) Explain why it is that the rebalancing work performed by the AVL tree insert or remove
is at most O(lg n) on a tree of height O(lg n). Your answer should be detailed enough to
convince us you know what you are talking about. You don’t need to justify the steps
of the algorithm here – simply indicate what those steps are and their running times –
and indicate that those running times add up to what we claim they add up to.
    
As you return from the BST recursive calls (after doing BST insert or BST remove), at
each node there are three things that need doing:
i. Recalculate the height of the node, by reading the heights of the two children,
choosing the maximum of those two heights, and adding 1. Given a pointer to a node,
you can access the node’s children in constant time (ptr->left and ptr->right),
and since the height is stored in the node itself, once you have a pointer to a node
you can retrieve its height in constant time (ptr->left->height, for example).
So reading the heights of the two children is constant time, and the rest is just
arithmetic, which is also constant time.
ii. Recalculate the balance of the node – that, again, is just arithmetic on the heights
of the child nodes, and we’ve already established that arithmetic on the heights of
the child nodes can be done in constant time.
iii. If the balance is illegal, perform the appropriate rotation. Comparing the balance
from (2) to +2 or -2 is constant, decding what rotation to perform will be constant
(because you are just reading the heights of the children and grandchildren, all of
which are reachable in constant time), and each rotation is a constant time operation,
so no matter which one you do, rotation takes constant time.
All three of those steps are constant time, so we spend a total of constant time at this
node. Since we have O(lg n) levels to move upward through as we return from recursive
calls, the total work will be the number of levels multiplied by the time spend on each
level, which will be O(lg n) times O(1), or O(lg n)
