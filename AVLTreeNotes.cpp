
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


resources:
https://www.cs.usfca.edu/~galles/visualization/AVLtree.html
 
