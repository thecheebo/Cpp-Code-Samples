You have the DSNode class shown on page 8 of the exam, as well as the Array class shown
on page 9 of the exam. You want to write a function makeTrees, which has one parameter,
an Array<int> named sets. This array will be indexed from 1 through sets.size(), representing a collection of disjoint sets implemented with union-by-size. You want to return a
value of type Array<DSNode*> (you are allowed to create this one new array in your function,
but no other additional new arrays besides that one), which will implement the exact same
collection of disjoint sets as the parameter array – only using actual uptree nodes rather than
simply array cells. Your returned array should be indexed from 1 through sets.size(), and
each cell should point to a DSNode containing that cell’s index as the node key. Those DSNode
objects should have their variables initialized in such a way that they exactly implement the
same uptrees represented by the parameter array (i.e. do not compress any paths).
