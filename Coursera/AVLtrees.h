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
