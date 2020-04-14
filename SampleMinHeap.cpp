#include <vector>
#include <algorithm>
#include <iostream>
#include <stdlib.h>
#include <math.h>

// Class for minimum heap implementation

class minHeap {
private:
  // current size of the heap
  int size;
  // max size of heap
  int capacity;
  // store elements as a vector
  std::vector<int> heap;
  // return the parent index
  int parent(int i){return (i-1) /2;}
  // return the left child index
  int left(int i){return 2 * i + 1;}
  // return the right child index
  int right(int i){return 2 * i + 2;}

public:
  // Constructor
  minHeap(int capacity);
  
  // Functions
  
  // Insert a key into the min heap
  void insert(int k);
  // extracts the minimum element
  int extractMin();
  // recursively heapify a sub-tree
  void heapify(int index);
  // print the heap
  void printHeap();
};

//Constructor that sets the heap size and capacity
minHeap::minHeap(int capacity) {
  size = 0;
  this->capacity = capacity;
  heap.resize(capacity);
}

// Insert newest key into the minHeap
void minHeap::insert(int key){

  //Make sure there is still space in the heap
  if (size ==capacity) {
    std::cout << "MIN HEAP IS FULL YO" << std::endl;
    return;
  }
  
  //Increase the new key at the end
  int index = size;  // This will be the index, as the size is always one index higher
  heap[index] = key;
  
  // Increase the amount of elements in the heap
  size++;
  
  // Maintain the min heap property.  Move the element UP until the index of key >= parent or root
  while(index != 0 && heap[parent(index)] > heap[index]) {
    std::swap(heap[index], heap[parent(index)]);
    index = parent(index);  // this line updates the index to parent so we may iteratively move up the parent key
  }
}  
  
  
  
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
  if (smallest != index) {
    std::swap(heap[index], heap[smallest]);
    heapify(smallest);
    }
  }
// Print the heap in a pretty format

int minHeap::extractMin() {
  //Make sure heap is not empty
  if (size ==0) {
    std::cout << "EMPTY YO" << std::endl;
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
    heapify(0);  // try to maintain order and balance the root now.
    
    //return the previously stored min element
    
    return temp_root;
  }
}

// Print the heap in a pretty format
void minHeap::printHeap(){
  int power = 0;
  int value = 1;
  for(int i = 0; i<size; i++) {
    if(i == value){
      std::cout <<std::endl;
      power+=1;
      value +=(1 <<power);
    }
    std::cout << heap[i] << " ";
  }
  std::cout <<std::endl;
}



int main() {
  // number of elements for our min heap
  int N = 15;
  
  //declare a heap with space for 10 elements
  minHeap heap(N);
  
  // insert N random numbers
  for(int i = 0; i<N; i++) {
    std::cout <<"Inserting element " << i+ 1 << std::endl;
    heap.insert(rand() %100);
    heap.printHeap();
      std::cout <<std::endl;
      
      
      

  }
    heap.extractMin();
  heap.printHeap();

  return 0;
}
