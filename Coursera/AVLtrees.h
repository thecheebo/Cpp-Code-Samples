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
