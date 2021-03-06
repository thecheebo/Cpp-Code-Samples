(b) Assume you have a disjoint set structure. Furthermore, assume you are NOT using
path compression. Justify the use of the union-by-size smart-union algorithm, rather
than the union-by-height smart-union algorithm. That is, why wouldn’t you always use
union-by-height in these circumstances? What advantage does union-by-size give you
that can make it worth using?

If we call the tree that gets pointed to, “A”, and refer to the tree whose root node is
changed to point to “A”, via the label “B”, then any union will necessarily increase the
depth of every node in “B” by 1, since now those nodes go through an extra edge – the
new pointer from B’s former root, to A – en route to their new root, A. By pointing the
smaller sized tree to the larger sized tree, you increase the depth of fewer nodes than if
you had done things the other way around. That is, union-by-size keeps the expected
depth of a node as small as possible, by always choosing to increase the depth of fewer
nodes rather than more nodes.

QUESTION!!
  
  What was the “problem” with using path compression and union-by-height together?
That is, what difficulty does using the two techniques together present? Please be
specific. (The word “problem” is in quotes because we said it turned out that this
“problem” didn’t actually affect things too badly, even if it seems like it would.)
  
Path compression (potentially) changes the height of the tree, due to (potentially) 
  shortening a path that was (potentially) the deepest path in the tree. In that case, the height
stored at the root would become incorrect, as neither path compression nor union-byheight
has any provision for recalculating the correct height in such a circumstance (and
adding one would make either algorithm far too expensive, time-wise).
