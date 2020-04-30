
(a) (5 points) One problem with an array-based implementation of a stack is the resizing we
must do when the stack fills. A scheme for overcoming this drawback employs periodic
resizing of the array by some constant amount c. That is, when the array of size k fills,
we create a new array of size k + c and copy the elements from the original array into
the new one, maintaining the original order so that the stack is not corrupted. Give
a complete analysis of this scheme over a sequence of n push operations on the stack.
Assume that the stack is empty to start. Please report your answer as an average cost
per push.
  
Solution: over n pushes there are n/c copying events, and that in the ith copy event,
i · c data items are copied from the old full array to the new one. The following sum
reflects the total number of copies:

Over n pushes the average cost per push is thus O(n).
Rubric: 3 points for analysis, 2 points for correct answer. Two of three analysis points
were awarded for any answer in which the process was decomposed appropriately into
the number of copy events and the size of each, even if the values used were incorrect.
Forgetting to report the average was a 1 point penalty.
  
  (5 points) Suppose a queue is implemented as a singly-linked list with head and tail
pointers, and the back of the queue is at the head of the list (that is, enQueues occur at
the head of the list). What is the worst case running time of the best implementation
of a deQueue() operation?
Solution: in order to complete the deQueue operation and end with a tail pointer at
the last element in the list, we must first traverse the list to find the node BEFORE the
one we wish to delete. This is a linear time operation in the number of nodes in the list,
or O(n).
Rubric: 3 points for analysis, 2 points for correct answer. Any answer that assumed
the tail pointer could be moved back without traversing the list received a maximum of
2 points.
  
  (c) (5 points) Suppose a queue is implemented as a singly-linked list with head and tail
pointers, and the back of the queue is at the head of the list (as in the previous part
of the question). We want to implement a clearQueue() function that removes all the
data from the queue. What is the worst case running time of the best implementation
of a clearQueue() operation?
Solution: we can simply traverse the list, deleting elements as we go, for a total running
time of O(n), where n is the number of elements in the list.
Rubric: 3 points for analysis, 2 for correct answer. Note that an incorrect answer to
part 2 could result in a correct answer for this problem. Such responses received only
the 2 points for the correct answer, and no analysis points. Answers that called dequeue
repeatedly received 3 points if the analysis was correct.
