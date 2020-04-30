(d) In the red-black tree insertion algorithm, all the cases for handling a red-parent-with red-child conflict (
we’ll refer to this as a “red-red conflict”) assume that there is another
level above the red-red conflict – i.e. they assume that the upper red node in the red-red
conflict has a parent. We did not have any case to handle the situation where you have
a red node, and the parent of that node happens to be red, but that red parent node
has no parent itself. Explain convincingly why we do not need such a case.

If the node we are inspecting has a red parent but no grandparent, it means the parent
of the node we are inspecting is the root. And yet, since we work from the bottom
upward when rebalancing and recoloring the tree, if we are currently inspecting the level
below the root, it means we have not reached the root yet. Therefore, we could not have
colored the root red yet ourselves. And the root is black at the start of every insertion
operation. So the case described above simply cannot happen – if we hadn’t reached
the root yet, it would still be black for certain, so there can be no case where we are
inspecting a node and it has a red root for a parent


(e) Explain the “repair case” of the Red-Black Tree removal algorithm (the “repair case”
was case 2b, where the node we labelled “x” had a black sibling and that black sibling
had a red child in the child position further from “x’). That is, explain what we do in
this case and justify that it fixes the problems we have without causing new ones.
If the parent of X is black, and we perform a single rotation on the parent toward X,
and color the new subtree root (S below) and its two children (P and C below) black:
  P        S
/ \       / \
X  S       P   C
  / \      / \   \
   L C    X  L     R
      \
       R
Then we used to have one black node on the way to X, namely, P, but now we encounter
both S and P on the way to X. On the other hand, there are still two black nodes on the
way to L, two black nodes on the way to C’s left child, and two black nodes on the way
to R, since previously, P and S were black and C was red, and now, S and C are both
black. In other words, we add one black node to all paths containing X, but the paths
that do not contain X have the same number of black nodes as before.
Similarly if P is red - same rotation, but S becomes red and P and C (as before) become
black. The same analysis as above is true, but since S is red instead of black, all paths
have one fewer black node than they did in the above paragraph. Nevertheless, we have
added one black node to the paths through X, while not changing the black heights of
the paths that do not travel through X.
