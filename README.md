# Binary-Heaps-Priority-Queues implemenation on in C++

This repository contains implementations of binary heaps (Max Heap and Min Heap) and priority queues based on these heaps in C++. The heaps are implemented using vectors for efficient insertions, deletions, and heapify operations.

## Features for heaps
- **Insertion: `insert(int value)`**:  Insert a node while maintaining the balance of the tree.
- **Min/Max element extraction: `extractMax()`, `extractMin()`**: Extract minimum or maximum value of heap.
- **Printing: `printHeap()`**:  Prints the elements of the heap.
  
## Features for queues
The **PriorityQueue_MaxHeap** class extends the MaxHeap class and provides the following functionalities:
- `push(int value)`: Inserts a new value into the priority queue.
- `pop()`: Extracts the maximum value from the priority queue.

The **PriorityQueue_MinHeap** class extends the MinHeap class and provides the following functionalities:
- `push(int value)`: Inserts a new value into the priority queue.
- `pop()`: Extracts the minimum value from the priority queue.


**Project Structure**
-----------

- *MaxHeap.cpp*
- *MinHeap.cpp*
- *PriorityQueue.cpp*

  
`MaxHeap.cpp:` Contains the implementation of the Max Heap.

`MinHeap.cpp:` Contains the implementation of the Min Heap and a test main function.

`PriorityQueue.cpp:` Contains the implementation of priority queues based on both Max Heap and Min Heap and test main functions.
