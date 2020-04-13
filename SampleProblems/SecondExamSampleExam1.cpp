1. a) 
You are given a BinarySearchTree class whose insert method inserts its parameter
into the binary search tree, using the usual algorithm. Express, using big-O notation,
the order of growth of the worst-case running time of the following code, as n increases.
Justify your answer.
BinarySearchTree bst; // creates an empty binary search tree
for (int i = 1; i <= n; i++) // this is the n we are talking about above
bst.insert(i);

If the Numbers of N are from sorted order from infinite to 0, then the worse case running time is O(n^2). The numbers would need to traverse 
down essentially a linked list if every number was less then the one before. 


b) (b) You have a min-heap of n values. You have a function IncreasePriority(int i, int
addition) which will take the value at index i, and increase its priority value by adding
the value addition to it. Now that the priority of this value has been increased, you
might not have a legal min-heap any longer, so you need to then do the minimum work
necessary to repair the min-heap. IncreaseKey does all that. What is the worst-case
running time of IncreaseKey? Express your answer in Big-O notation and explain
convincingly why your answer is correct.

what is worst running time of increasekey?

By nature of a min-heap, it would be Log(n) as you would buble down based off of the height, work like delete min or buildheap


