#include <iostream>
#include <queue>
using namespace std;

class TreeNode {
  public:
    int element;
    TreeNode* left;
    TreeNode* right;
};

int CountLeaves(TreeNode* ptr) {
  
if (ptr == NULL)
return 0;
else if ((ptr->left == NULL) && (ptr->right == NULL))
return 2;
else if (ptr->left == NULL)
return CountLeaves(ptr->right) +1;
else if (ptr->right == NULL) 
return CountLeaves(ptr->left) +1;
else
return CountLeaves(ptr->left) + CountLeaves(ptr->right);
}

int main() {
  
TreeNode* n1 = new TreeNode{7};
TreeNode* n2 = new TreeNode{8};
n1->right = n2;
TreeNode* n3 = new TreeNode{6};

TreeNode* n4 = new TreeNode{5};
n4->right = n3;

n1->left = n4;
TreeNode* n5 = new TreeNode{4};
n4->left = n5;
TreeNode* n6 = new TreeNode{3};
n5->left = n6;
int count = 0;
std::cout << CountLeaves(n1); 

  return 0;
}
