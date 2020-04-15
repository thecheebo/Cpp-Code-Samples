class HashTable {
  private:
    Array<pair<int, int> > table;
  public:
    // public function declarations
};

//what i know 
// array index 0 to table size minus 1. first value in each pair holds 0 if cell is empty, 1 if valid, -1 if deleted
//2nd value holds key value in this cell (if cell is a valid cell)
// write assignment operator for this class, write dfefintiion and assume declaration occured in the public function declarations above section.




(b) Consider the following code:
  Foo theObject;
    cout << theObject(6, 9) << endl;

Write a class Foo – specifically, write a function object class – so that in the code above,
theObject(6, 9) produces: the sum of the two arguments. In general, the function call
theObject(x, y) should return the sum of x and y.
  
  
  
  2. [Analysis – 40 points].
(a) You have an red-black tree composed of n nodes that each have three pointers. Each
node points not only to its two children, but to its parent as well. (The root’s parent
pointer, points to NULL, since the root does not have a parent.
You have a pointer to the node in the red-black tree containing the minimum value in the
tree. You want to travel from the minimum node to the root of the tree, printing each
value you encounter along the way, and then travel from the root to the node containing
the AVL tree’s maximum value, again printing each value you encounter along the way.
Express the order of growth of the worst-case running time of this procedure, in Big-O
notation, and explain convincingly why your answer is correct.
                                                                      
                                                                      

                                                                      
(b) The algorithm known as heapsort was briefly mentioned in lecture once. The algorithm
sorts n integers by putting them all into a heap, and then calling DeleteMin repeatedly,
thus pulling the integers out of the heap, in order from lowest to highest. Express
the order of growth of the worst-case running time of heapsort, in Big-O notation, and
explain convincingly why your answer is correct.
                                                                      
                                                                      
