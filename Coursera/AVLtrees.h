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
