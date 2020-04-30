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
