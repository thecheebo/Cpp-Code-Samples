Question:

(b) If you have a complete tree of 17 nodes, how many nodes are on the deepest level?
2

MC3 (2.5pts)
Suppose that we have numbers between 1 and 1000 in a binary search tree and we want to
search for the number 363. Which of the following sequences can not be the sequence of nodes
visited in the search?
(a) 2, 252, 401, 398, 330, 344, 397, 363
(b) 924, 220, 911, 244, 898, 258, 362, 363
(c) 2, 399, 387, 219, 266, 382, 381, 278, 363
(d) 925, 202, 911, 240, 912, 245, 363 < ---
(e) 935, 278, 347, 621, 399, 392, 358, 363

  
  IntTriple Verify(TreeNode* ptr) {
// we will use the other two variables of an IntTriple to hold
// the min and max of the tree
IntTriple returnVal;
if (ptr == NULL) {
returnVal.first = 1; // empty binary tree is a BST
returnVal.second = 0; // min of empty tree
returnVal.third = -1; // max of empty tree, it being < min
// signals it was empty tree
}
else {
IntTriple left, right;
left = Verify(ptr->left);
right = Verify(ptr->right);
returnVal.first = 1; // assume it’s a BST unless we find otherwise
returnVal.second = ptr->elem; // assume root value is min and max
returnVal.third = ptr->elem; // unless we find otherwise
if ((left.first == 0) || (right.first == 0))
returnVal.first = 0; // not BST if subtrees not BSTs
// if root < max of left subtree, or root > min of right subtree, not BST
if (((left.second <= left.third) && (left.third > ptr->element)) ||
((right.second <= right.third) && (ptr->element > right.second)))
returnVal.first = 0;
if (left.second <= left.third) { // if left subtree exists
if (left.second < returnVal.second) // if smaller min, save it
returnVal.second = left.second;
if (left.third > returnVal.third) // if bigger max, save it
returnVal.third = left.third;
}
if (right.second <= right.third) { // if right subtree exists
if (right.second < returnVal.second) // if smaller min, save it
returnVal.second = right.second;
if (right.third > returnVal.third) // if bigger max, save it
returnVal.third = right.third;
}
return returnVal;
}
}

*** QUESTION
Explain why we can implement a complete tree using an array – that is, explain why we
don’t lose information when we get rid of the pointers, i.e. explain why it is that, given
an array, we can always produce the corresponding complete tree.
  
Because of the way a complete tree is defined, the number of nodes defines the structure
– that is, every complete tree of N nodes, has those nodes in the same place as every
other complete tree of N nodes. And the array is just the level order traversal of the
complete tree. So, given an array with N elements, we know exactly what structure the
tree is supposed to have, and we know how that tree was traversed to produce the array,
meaning we know what array cells correspond to what nodes in the tree.
