4. [Breadth-First Spanning Tree – 15 points].
You are given the following class:
class TreeNode {
public:
int vertexNumber;
list<TreeNode*> subtrees; // initially an empty list; the function
// push_back(item) will add item to
// end of list
};
In addition, you are given an adjacency matrix implementation of an unweighted, undirected,
connected graph – such a graph, when you run breadth-first search on it, would produce
a single spanning tree, rather than a spanning forest, no matter which vertex you start
at. In this adjacency matrix implementation, the graph has vertices labelled with indices 0
through n-1, and you are given the value n and a two-dimensional array with n rows and n
columns, both indexed from 0 through n-1. (In C++, a two-dimensional array is accessed
via expressions such as arr[i][j] where arr is of type int**.) You want to write a method
that takes those two values – the array and the n – as parameters, and returns a pointer
to the root of the breadth-first-spanning-tree of the graph. You are allowed to use as many
Queues as you like, as well as being allowed to create other one-dimensional arrays as well.
TreeNode* BreadthFirstSpanningTree(int** graph, int n) {
// your code goes here
SOLUTION ON NEXT PAGE

TreeNode* BreadthFirstSpanningTree(int** graph, int n) {
Queue<TreeNode*> nodes;
int marks[n];
for (int i = 0; i < n; i++)
marks[i] = 0;
TreeNode* root = new TreeNode();
// we will take 0 as our start vertex
root->vertexNumber = 0;
nodes.Enqueue(root);
marks[0] = 1;
while (!Q.IsEmpty()) {
TreeNode* temp = Q.Dequeue();
int index = temp->vertexNumber;
for (int col = 0; col < n; col++) {
if graph[index][col] == 1) {
if (marks[col] == 0) {
TreeNode* latest = new TreeNode();
latest->vertexNumber = col;
nodes.Enqueue(latest);
marks[col] = 1;
(temp->subtrees).push_back(latest);
}
}
}
}
return root;
}
