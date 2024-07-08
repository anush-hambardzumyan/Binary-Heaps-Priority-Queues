#include "MinHeap.cpp"
#include "MaxHeap.cpp"

class PriorityQueue_MinHeap : public MinHeap {
	public:
		PriorityQueue_MinHeap(const std::vector<int>& existingHeap) : MinHeap(existingHeap)
		{
			// Build min heap from existing heap
			for (int i = (heap.size() - 1) / 2; i >= 0; --i) {
				heapifyDown(i);
			}
		}

		void push(int value)
		{
			this -> insert(value);
		}

		int pop()
		{
			return this -> extractMin();
		}
};


class PriorityQueue_MaxHeap : public MaxHeap 
{
	public:
		PriorityQueue_MaxHeap(const std::vector<int>& existingHeap) : MaxHeap(existingHeap) 
		{
			// Build max heap from existing heap
			for (int i = (heap.size() - 1) / 2; i >= 0; --i) {
				heapifyDown(i);
			}
		}

		void push(int value) 
		{
			this -> insert(value);
		}

		int pop() 
		{
			return this -> extractMax();
		}
};



int main()
{
	PriorityQueue_MinHeap minheap({1, 7, 3, -5, 6});
	std::cout << "Priority Queue(MinHeap): ";
	minheap.printHeap();

	minheap.pop();
	minheap.printHeap();

	minheap.push(2);
	std::cout << "After pushing 2: ";
	minheap.printHeap();


	std::cout << "Popped Element: " << minheap.pop() << std::endl;
	std::cout << "Queue after popping min element: ";
	minheap.printHeap();


	PriorityQueue_MaxHeap maxheap({1, 7, 3, -5, 6});
    std::cout << "Priority Queue(MaxHeap): ";
    maxheap.printHeap();

    maxheap.pop();
    maxheap.printHeap();

    maxheap.push(2);
    std::cout << "After pushing 2: ";
    maxheap.printHeap();

    std::cout << "Popped Element: " << maxheap.pop() << std::endl;
    std::cout << "Queue after popping max element: ";
    maxheap.printHeap();

}