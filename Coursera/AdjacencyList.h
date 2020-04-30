Suppose you have a directed weighted graph of n vertices, where the vertex numbers are 1
through n, and the graph implementation is an adjacency list. The adjacency list is represented with an Array, indexed from 1 to n, of pointers to the following type:
class EdgeNode {
public:
int index; //index of target vertex
int weight; //weight of edge
EdgeNode* next; // ptr to next edge
};
We want to convert this graph to an undirected weighted graph, by adding for each existent
edge from u to v, the edge in the opposite direction, that is from v to u, with the same weight.
That is, if the directed version had:
5
U ---------------------------> V
the undirected vertion will have:
5
U ---------------------------> V
5
V ---------------------------> U
You can assume that, initially, if there is an edge <i, j> in the graph, there is not an
edge <j, i> of any weight. Write the function ConvertToUndirected, which receives as a
parameter an Array of EdgeNode pointers – i.e. our adjacency list, as described above – by
reference. The function will perform the conversion discussed above. Do not assume any edge
list is specifically sorted in any way.
void ConvertToUndirected(Array<EdgeNode*>& graph) {
// your code goes here
for (int i = 1; i <= graph.Size(); i++) {
EdgeNode* ptr = graph[i];
while (ptr != NULL) {
EdgeNode* travSearch = graph[ptr->index];
while ((travSearch != NULL) && (travSearch->index != i))
travSearch = travSearch->next;
if (travSearch == NULL) {
EdgeNode* temp = new EdgeNode();
temp->index = i;
temp->weight = ptr->weight;
temp->next = graph[ptr->index];
graph[ptr->index] = temp;
}
ptr = ptr->next;
}
}

  
  
  Ghost of Euler
  You have the following EdgeNode class:
class EdgeNode {
public:
int index; // index of target vertex
EdgeNode* next; // ptr to next edge
};
Furthermore, you have a variable of type Array<EdgeNode*> that is indexed from 1 to the
size of the array (given by the Size() method in the Array class). The array is an adjacency
list implementation of a graph, of the kind we first discussed in lecture; the vertices have
indices from 1 to Size().
You want to write a method numOddDegree which has one parameter, a reference to an
Array<EdgeNode*> as described above. You can assume this adjacency list represents an
undirected graph. You want to return the number of vertices with odd degree. (The degree
of a vertex in an undirected graph, is the number of edges which that vertex is an endpoint
for. So, you want to know how many vertices are endpoint to an odd number of edges.) You
can assume the graph has no self-loops (i.e. no vertex has an edge to itself.)
int numOddDegree(Array<EdgeNode*>& graph) {
// your code goes here
int numOdd = 0;
int currentVert = 1;
while (currentVert <= graph.Size()) {
EdgeNode* trav = graph[currentVert];
int numEdges = 0;
while (trav != NULL) {
trav = trav->next;
numEdges++;
}
if (numEdges % 2 == 1)
numOdd++;
currentVert++;
}
return numOdd;
}
