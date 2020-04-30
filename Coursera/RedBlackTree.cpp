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
