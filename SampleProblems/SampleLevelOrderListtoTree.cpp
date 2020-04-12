#include <iostream>
#include <queue>
using namespace std;
class ListNode {
  public:
    int element;
    ListNode* next;
};
class TreeNode {
  public:
    int element;
    TreeNode* left;
    TreeNode* right;
};

TreeNode* LevelOrderToTree(ListNode* head) {

if (head == NULL)
  return NULL;
else {
  // make root node and put it on queue
  queue<TreeNode*> Q;
  TreeNode* root = new TreeNode();
  root->element = head->element;
  Q.push(root);
  TreeNode* tempInTree; // this will point to whatever node
  
  // we are working with in tree
  ListNode* currentInList = head->next; // since we’ve used
  
  // head value already
  while (!Q.empty()) {
    tempInTree = Q.front();
    Q.pop();
    if (currentInList == NULL) { // no more children, this is a leaf
      tempInTree->left = NULL;
      tempInTree->right = NULL;
    }
    else { // we have children to add to our dequeued node
      
      // add left child
      tempInTree->left = new TreeNode();
      tempInTree->left->element = currentInList->element;
      Q.push(tempInTree->left);
      currentInList = currentInList->next;
      
      // add right child
      tempInTree->right = new TreeNode();
      tempInTree->right->element = currentInList->element;
      Q.push(tempInTree->right);
      currentInList = currentInList->next;
}}}}

int main() {
  
ListNode* h1 = new ListNode{15};

ListNode* h2 = new ListNode{25};
h1->next = h2;
ListNode* h3 = new ListNode{35};
h2->next = h3;
ListNode* h4 = new ListNode{45};
h3->next = h4;
ListNode* h5 = new ListNode{55};
h4->next = h5;
ListNode* h6 = new ListNode{65};
h5->next = h6;
ListNode* h7 = new ListNode{75};
h6->next = h7;
h7->next = nullptr;

LevelOrderToTree(h1);

  return 0;
}
