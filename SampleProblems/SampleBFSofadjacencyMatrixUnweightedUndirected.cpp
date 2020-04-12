#include <iostream>;
#include <queue>;
#include <list>;
#include <list>;


class TreeNode {
  public:
  int vertexNumber;
  std::list<TreeNode*> subtrees;
  };


TreeNode* BreadthFirstSpanningTree(int** graph, int n) {
  std::queue<TreeNode*> Q;

  int mark_as_seen_list[n];
    for (int i = 0; i < n; i++){
      mark_as_seen_list[i] = 0;}
    TreeNode* root = new TreeNode();
      
    // we will take 0 as our start vertex
    root->vertexNumber = 0;
    Q.push(root);
    std::cout << "Putting a pointer to the Root in the Queue.\n";
    mark_as_seen_list[0] = 1;
    while (!Q.empty()) {
      TreeNode* temp = Q.front();
      std::cout <<"Taking out first pointer in the Queue. Which is: " 
        << Q.front()->vertexNumber << std:: endl;
      Q.pop();
        
          int index = temp->vertexNumber;
          for (int col = 0; col < n; col++) {
            if (graph[index][col] == 1) {
              
              if (mark_as_seen_list[col] == 0) {
                TreeNode* latest = new TreeNode();
                latest->vertexNumber = col;
                Q.push(latest);
                
                mark_as_seen_list[col] = 1;
                (temp->subtrees).push_back(latest);
                std::cout <<"Adding this vertex: " << latest->vertexNumber << " to vertex seen list on: "<< temp->vertexNumber << std:: endl;
          }
        }
      }
    }
    return root;
  }

int main() {
  
  
int** two_d = new int*[5]; // allocate 200 bytes of memory
for (int i = 0; i <5; i++)
    two_d[i] = new int[5];

two_d[0][0] = 0;
two_d[0][1] = 1;
two_d[0][2] = 1;
two_d[0][3] = 0;
two_d[0][4] = 0;

two_d[1][0] = 1;
two_d[1][1] = 0;
two_d[1][2] = 0;
two_d[1][3] = 1;
two_d[1][4] = 0;

two_d[2][0] = 1;
two_d[2][1] = 0;
two_d[2][2] = 0;
two_d[2][3] = 0;
two_d[2][4] = 1;

two_d[3][0] = 1;
two_d[3][1] = 0;
two_d[3][2] = 0;
two_d[3][3] = 0;
two_d[3][4] = 1;

two_d[4][0] = 0;
two_d[4][1] = 0;
two_d[4][2] = 1;
two_d[4][3] = 1;
two_d[4][4] = 0;

//{1,0,0,1,0}, {1,0,0,0,1}, {1,0,0,0,1}, {0,0,1,1,0}};

BreadthFirstSpanningTree(two_d, 5);
  return 0;
}
