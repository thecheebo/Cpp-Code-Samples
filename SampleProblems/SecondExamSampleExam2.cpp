1. a)

What was the “problem” with using path compression and union-by-height together?
That is, what difficulty does using the two techniques together present? Please be
specific. (The word “problem” is in quotes because we said it turned out that this
“problem” didn’t actually affect things too badly, even if it seems like it would.)

The problem was that path compression may change the heiggt of the tree, and making a
function to calculate the height of the tree is expensive.
   
   b)  If you have a complete tree of 17 nodes, how many nodes are on the deepest level?
   
   1
   2
   4
   8
   2 is the answer
   A complete binary tree is a binary tree in which every level, except possibly the last, 
   is completely filled, and all nodes are as far left as possible
   
   A full binary tree (sometimes proper binary tree or 2-tree) is a tree in which every 
   node other than the leaves has two children
   
   c) Insert the integers 1 through 6, in that order, into an AVL tree. Draw the resulting
tree. How many rotation operations, total, did you perform? Count a “double rotation”
operation as one rotation operation.


Check height of th RIGHT minus height of the left
AVL named after Adelson-Velsky and Landis

   o       o
  / \       \
 o   o       o
 mountain     \
               o  is a stick
               
 if the magnitude of the load factor is greater then 1 then it is no longer balanced
  deepest point is highest point.

Generic Left Rotation: (stick)  
  u  -----| beginning of the stick   
 / \      |   //u has a balance factor of 2
t   v   --| center of the stick
  /  \    |   // v has a balance factor of 1
 w    x  -| end of the stick
       \      // inserting y caused the imbalance
        y 
 shift to:
    v
   / \
  u   x
 / \   \
t   w   y

Generic Right-Left Rotation: (1 extra step) 
   u -----| beginning 
  / \     |   //u has a balance factor of 2
 t   v  --| center of 
    /     |   // v has a balance factor of -1
   w -----| end  
  / \         // adding anything to W causes the imbalance
 x   y
        shift to:
   u -----| beginning 
  / \     |   //u has a balance factor of 2
 t   w  --| center of 
    / \   |   // w has a balance factor of -1
   x   v--| end  
      /      // adding anything to W causes the imbalance
     y 
         shift to:
    w
   / \
  u   v
 / \ / \
t  x y

                     lowest point of imbal   -  balance fac of node in that direction
left rotation                2                          1
right rotation              -2                         -1
right-left rotation          2                         -1
left-right rotation         -2                          1
 
 (a) Explain why an in-order traversal on a binary search tree should produce the values of
the tree in lexigraphical order (i.e. numerical, alphabetical, or whatever the order is that
is appropriate for those values).
       
       The in-order traversal will always be lexigraphical because it recursively calls the
       lowest value, starting from the left and calls left,node,right which will always be
       in order, and then it recursively repeats this process, thus by its nature, will be 
       in lexigraphically order.
       
(b) In an AVL tree, why does storing the height of a subtree, in the root node of that subtree,
improve the efficiency of the AVL rebalancing work (versus not storing the height at all)? 
   
   Because any change to any node/insert or delete, can cause an balance somewhere, so instead
   of recalculating height which would take log(n) or o(n), time it only needs to be updated which is
   o(1) time although it takes o(n) adiditional space. 

(c) After performing a combine operation during B-Tree removal, why is it that we need to
check the parent for underflow? i.e. justify that such a combine operation could have
caused the parent to underflow

Combing a node merges two nodes into one, so where the parent used to have two nodes, 
it now has just one. Probably happens after a delete. So if the parent had the minimum number 
of children before, it hnow has one less then the minimum number of children, because
two o fhte children have been combined into one.
   
(d) Explain why we can implement a complete tree using an array – that is, explain why we
don’t lose information when we get rid of the pointers, i.e. explain why it is that, given
an array, we can always produce the corresponding complete tree.
   
   We can use an array for a complete tree, because a complete tree has all its leafs on 
   the same row or below and all to the left side of the last row.  So the rows would
   represent a level order traversal that can be implemented into a tree.
      
   Because of the way a complete tree is defined, every node is a complete tree.
     
(e) Explain the “repair case” of the Red-Black Tree removal algorithm (the “repair case”
was case 2b, where the node we labelled “x” had a black sibling and that black sibling
had a red child in the child position further from “x’). That is, explain what we do in
this case and justify that it fixes the problems we have without causing new ones.
      
      Red black trees
      -every node is red or black
      -root is always black
      -new insertions are always red-node goes from red to black immediately
      -every path from root-leaf has the same number of black nodes
      -no path can have two consecutive red nodes
      -nulls are considered black
      
      reblance:

     IF    [black aunt] LEFT OR RIGHT rotate : B.A.R   
                 ALWAYS 2 STEPS. ROTATE THEN CHANGE COLORS
               black     if left aunt is black, left rotate, if right aunt right orotate
                / \
             red   red 
         
     ELSE    [red aunt] colorflip: R.A.C
         
         After colorflip:
               red  (grandparent)
              /   \
           black  black
   
             3b
            / \
          1r   5r   color flip.
                 \
                  7r
            RAC
             3r
            /  \
           1b   5b
                 \ 
                  7r
             node msut be black
                         RAC
             3b
            /  \
           1b   5b
                 \ 
                  7r
                  
             insert 6     
                  
             3b
            /  \
           1b   5b
                / \ 
             nullb 7r
                 / 
                6r  
                  
           B.A.R - black aunt rotate
             3b
            /  \
           1b   6r
                / \ 
             5b    7r
             after rotate change colors
             3b
            /  \
           1b   6b
                / \ 
             5r    7r   = valid RBtree
           
           add 8
            
             3b
            /  \
           1b   6b
                / \ 
             5r    7r 
                     \
                     8 r  we have red aunt so we color flip
             3b
            /  \
           1b   6r
                / \ 
             5b    7b 
                     \
                     8 r  = valid RBtree
                     
           add 9
                  
             3b
            /  \
           1b   6r
                / \ 
             5b    7b 
                     \
                     8 r       
                       \
                       9 r   = rotate
             3b
            /  \
           1b   6r
                / \ 
             5b    8r 
                  /  \
                 7b   9 r   = make parent black and 2 kids red    
             
             3b
            /  \
           1b   6r
                / \ 
             5b    8b 
                  /  \
                 7r   9r
            
                  lets add 10
             3b
            /  \
           1b   6r
                / \ 
             5b    8r  = problem node
                  /  \
                 7b   9b 
                       \
                        10r 
             6b
            /  \
           3r   8r
          / \   / \ 
         1b 5b 7b  9b
                    \
                     10r 

(a) If you want to remove some value from a min-heap – not necessarily the minimum value,
just some random value from the heap – one way you could go about this would be to
decrease the priority of the value so that it rises to the top of the heap – i.e. decrease the
priority of the value so that it is the minimum value in the heap – and then perform a
DeleteMin operation. Assuming you already know where the value you want to remove
is located in the min-heap, what would be the order of growth of the running time of
the above removal procedure? Express your answer in big-O notation and justify your
answer.

   To decrease the priority of a value and percolate it to the top would potentially be the
same as the cost of insertion – i.e. the cost of swapping a value upward from the deepest
level of the heap to the root. That cost is O(lg V ). And a delete min is also O(lg V ).
So total, the cost of this operation will be O(lg V ).
  
   As you return from the BST recursive calls (after doing BST insert or BST remove), at
each node there are three things that need doing:
      i. Recalculate the height of the node, by reading the heights of the two children,
      choosing the maximum of those two heights, and adding 1. Given a pointer to a node,
      you can access the node’s children in constant time (ptr->left and ptr->right),
      and since the height is stored in the node itself, once you have a pointer to a node
      you can retrieve its height in constant time (ptr->left->height, for example).
      So reading the heights of the two children is constant time, and the rest is just
      arithmetic, which is also constant time.
         ii. Recalculate the balance of the node – that, again, is just arithmetic on the heights
         of the child nodes, and we’ve already established that arithmetic on the heights of
         the child nodes can be done in constant time.
            iii. If the balance is illegal, perform the appropriate rotation. Comparing the balance
            from (2) to +2 or -2 is constant, decding what rotation to perform will be constant
            (because you are just reading the heights of the children and grandchildren, all of
            which are reachable in constant time), and each rotation is a constant time operation,
            so no matter which one you do, rotation takes constant time.
All three of those steps are constant time, so we spend a total of constant time at this
node. Since we have O(lg n) levels to move upward through as we return from recursive
calls, the total work will be the number of levels multiplied by the time spend on each
level, which will be O(lg n) times O(1), or O(lg n).
   

You have the following two standard node classes (which are publicly accessible and not
encapsulated in another class):
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
Write a function LevelOrderToTree. The function should take as parameter a pointer to
a ListNode, which is the first element of a list that represents the level-order traversal of a
perfect binary tree. This function should reproduce the binary tree from the level-order listing
received as a parameter. That is, LevelOrderToTree should return a TreeNode pointer which
will be the root of a perfect binary tree such that, if a level-order traversal is run on it, it will
yield the same listing as the one received as parameter. If the parameter ListNode pointer
is NULL, the the returned TreeNode pointer should also be NULL.
You have one Queue available to you to use as a local variable, if you wish.
   

//std::queue<int> q;
// PARAMETER -- list node - points to 1st element of a list
// that list is a L-O traversal of a perfect binary tree
// FUNCTION -- reproduce THAT binary tree from L-O list
// RETURN -- return root to Perfect Binary tree, if L-O order run then returns the parameter
// NOTES -- If pointer fed is null, then return null
   
//      
      traverse through list, count size.   
     n^2-1 =3, 7, 15, 31, 63 etc..
     divide /2 int divide. = where binary node is. 
      for (i=0, i < binaryheadlocation; i++)
         heed->= head.next;
   1 ,2 ,3 , 4, 5, 6 ,7 
   
      
      
      
   TreeNode* LevelOrderToTree(ListNode* head) {
      1       
    2   3 
   4 5 6 7      
   if head= null
      return null
   Treenode rootnode = head;  //establish root node
   rootnode->element = head->element  //establish node data  = list data
   
   left node
   right node
   while head->next != null  // while list .next is not null (iterate)
       head = head->next  //head is now the next element
       Treenode* nextleftnode; //create a new left node.
       nextleftnode->element = head.element  //assign the next element into new node
       rootnode->left = nextleftnode;
      
       head = head->next  //head is now the next element
       Treenode* nextleftnode; //create a new right node.
       nextrightnode->element = head.element  //assign the next element into new node
          
       rootnode->right = nextrightnode;
       
      
       
   
       
   
                  
            
             
