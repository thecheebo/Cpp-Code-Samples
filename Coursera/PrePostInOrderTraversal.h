A post-order traversal of the following tree visits the nodes in which order?

       g
      / \
     c   h
    /\     \
   b  e      k
  /   /\     /\ 
 a    d f    i l
            /
           j
           
(a) G C B A E D F H K I J L
(b) A B C D E F G H I J K L
(c) A B D F E C J I L K H G <---
(d) All of these are valid post-order traversals.
(e) None of these is a valid post-order traversal.

 (a) Explain why an in-order traversal on a binary search tree should produce the values of
the tree in lexigraphical order (i.e. numerical, alphabetical, or whatever the order is that
is appropriate for those values).
       
An in-order traversal will process all the values in the left subtree of the root before
processing the root. Now, since the left subtree consists of all the values in the tree that
are less than the root, all the values less than the root will be processed before the root
itself. Likewise for the right subtree – an in-order traversal will process all the values in
the right subtree of the root, after the root is processed, and since all the values greater
than the root are in the right subtree, that means the root is processed prior to the
processing of any values greater than the root. So the root is guaranteed to be placed in
the correct order relative to its descendants. And since this process is recursive, every
node is guaranteed to be placed in the proper order relative to its descendants, and thus
all the values are in the proper order.
