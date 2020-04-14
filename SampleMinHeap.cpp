#include <vector>
#include <algorithm>
#include <iostream>
#include <stdlib.h>
#include <math.h>

// Class for minimum heap implementation

class minHeap {
private:




minHeap::minHeap(int capacity


// Insert newest key into the minHeap
void minHeap::insert(int key){

  //Make sure there is still space in the heap
  if (size ==capacity) {
    std::cout << "MIN HEAP IS FULL YO" << endl;
    return;
  }
  
  //Increase the new key at the end
  int index = size;  // This will be the index, as the size is always one index higher
  heap[index] = key;
  
  // Increase the amount of elements in the heap
  size++;
  
  // Maintain the min heap property.  Move the element UP until the index of key >= parent or root
  while(index != 0 && heap[parent(index)] > heap[index]) {
    swap(heap[index], heap[parent(index)]);
    index = parent(index);  // this line updates the index to parent so we may iteratively move up the parent key

//Recursive function to maintain structure
void minHeap::heapify(int index){
  // set intiial conditions
  int left_value = left(index);
  int right_value = right(index);
  int smallest = index;
  
  // Find the smallest element of the tree
  if( (left_value < size) && (heap[left_value] < heap[smallest])) {
    smallest = left_value;
  }
   if( (right_value < size) && (heap[right_value] < heap[smallest])) {
    smallest = right_value;
  }
  
  // if the smallest of left or right value, continue heapify
  if (smallest != i {
    swap(heap[i], heap[smallest]);
    heapify(smallest);
    }
  }


int minHeap::extractMin() {
  //Make sure heap is not empty
  if (size ==0) {
    std::cout << "EMPTY YO" << endl;
    return -1;
  }
  //check if there is only 1 element
  else if (size == 1){
  size--;
  return heap[0];
  }
  //normal extraction
  else {
    //store the root
    int temp_root = heap[0];
    
    //maintain heap shape and then order
    heap[0] = heap[size -1]; // Roort node is now the last node value
    size--;
    heapify(0);  try to maintain order and balance the root now.
    
    //return the previously stored min element
    
    rerturn temp_root;
  }
}
