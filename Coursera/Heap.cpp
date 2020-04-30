In an array-based implementation of a Heap, the right-child of the right-child of the node at
index i, if it exists, can be found at what array location?

(a) 4i + 3
  
(b) You have a min-heap of n values. You have a function IncreasePriority(int i, int
addition) which will take the value at index i, and increase its priority value by adding
the value addition to it. Now that the priority of this value has been increased, you
might not have a legal min-heap any longer, so you need to then do the minimum work
necessary to repair the min-heap. IncreaseKey does all that. What is the worst-case
running time of IncreaseKey? Express your answer in Big-O notation and explain
convincingly why your answer is correct.
If the priority value within a min-heap nodes increases, it will still be greater than its
parent – since it was already greater than its parent (due to the whole structure being
a legal min-heap prior to the IncreasePriority operation) and it’s just gotten bigger.
However, before the operaton, the value was smaller than its children, and now there is
a possibility is is larger than its children. In fact, if we consider the subtree that this
node is a root of, this node used to be the smallest node in that subtree, by definition,
and yet now it is potentially not the smallest value anymore.
So we have a situation where there is a complete tree (the subtree rooted at this node)
where everything is partially ordered except for possibly the root value. This is no
different than the stage of DeleteMin right after writing your last value into the first
cell. i.e., to summarize all this up, the IncreasePriory operation requires nothing more
than taking the increased priorty value and percolating it downward in the same way
you would do for DeleteMin or BuildHeap. And since the heap has height O(log n), this
operation is at most O(log n).
  
  QUESTION &&&***
  If you want to remove some value from a min-heap – not necessarily the minimum value,
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
