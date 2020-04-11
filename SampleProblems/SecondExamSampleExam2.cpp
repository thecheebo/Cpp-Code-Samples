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
                  
                  
            
             
