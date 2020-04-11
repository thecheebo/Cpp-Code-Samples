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
 
 
 
