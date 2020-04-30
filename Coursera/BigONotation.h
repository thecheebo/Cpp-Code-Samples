You want to create a two-dimensional sparse array. That is, you want an interface that lets
you pass in a “row” index and “column” index and, using those indices, gives you the unique
value associated with that pair of indices. However, behind the scenes, we will not necessarily
implement this with a two-dimensional array.
Specifically, we are deciding between two possible implementations. One of our options is a
linked list whose nodes each hold a row index and an array of integers. In this case, to look
up a value, we first search the linked list for the desired row, and then, given the array at
that linked list node, use our column index as the array index we want – the value in that
cell is what we are looking for.
The second option is a red-black tree whose nodes each hold a row index and an AVL tree.
Searching the red-black tree for the row index will give us the relevant AVL tree. The AVL
tree will hold two indices in each node – a column index and the value associated with that
column for the given row we looked up in the red-black tree. So to obtain our value, we then
search the AVL tree for the column index.
If our goal is to have the fastest worst-case time we can for obtaining a value, given the value’s
row and colum, then which of these two implementations is preferable? Justify your answer
convincingly. You can assume any running time we have stated in class about linked lists,
arrays, red-black trees, or AVL trees.

THE ANSWER: For our first option, array lookup is done by searching the linked list for a
row value (this would be O(n)) and then once we find it, access the array there to get the
column we want (which would be O(1)). So, we have O(n) + O(1) = O(n).
Our second option is to search a red-black tree for a row value (this would be O(log n)) and
then once we find it, access the AVL tree there and search it to get the column we want (this
would also be O(log n)). So we have O(log n) + O(log n) = O(log n).
So the second way is the better of the two, since in order to find the value you need to acces
*both* structures, and that total time will be better in the second implementation.
