#include <iostream>
#include <vector>

class MinHeap {

	protected:
		std::vector<int> heap;

		//helper functions for imitation of tree
		int parent(int i)
		{
			return (i - 1) / 2;
		}

		int left(int i)
		{
			return (i * 2) + 1;
		}

		int right(int i)
		{
			return (i * 2) + 2;
		}

		void heapifyUp(int i)
		{
			//if node isn't the root and node's parent's value is bigger
			//that the node's value, the node needs to get up
			while (i != 0 && heap[parent(i)] > heap[i]) {
				std::swap(heap[i], heap[parent(i)]); //swap value of child and parent
				i = parent(i); //update the index for getting higher
			}
		}

		void heapifyDown(int i) //heapifing down
		{
			int smallest = i;
			int l = left(i);
			int r = right(i);

			//comparing two leaves with their parent to understand in which direction it needs to get down
			if (l < heap.size() && heap[l] < heap[smallest]) {
				smallest = l;
			}

			if (r < heap.size() && heap[r] < heap[smallest]) {
				smallest = r;
			}

			if (smallest != i) {
				std::swap(heap[i], heap[smallest]);
				//recursive call for getting to lower levels if there is a need
				heapifyDown(smallest);
			}
		}

	public:
	
		MinHeap(const std::vector<int>& rawArray)
		{
			heap = rawArray;
			buildMinHeap();
		}

		void buildMinHeap()
		{
			for (int i = (heap.size() / 2) - 1; i >= 0; --i) {
				heapifyDown(i);
			}
		}

		void insert(int value)
		{
			heap.push_back(value);
			int index = heap.size() - 1;
			heapifyUp(index);
		}

		int extractMin()
		{
			if (heap.empty()) {
				throw std::runtime_error("Heap is empty");
			}

			int min = heap[0]; //saving first element of heap that is the smallest
			heap[0] = heap.back(); //swapping last and first elements for later deleting the last one
			heap.pop_back();
			heapifyDown(0); //heapify down down the root, because it wasn't analysed before being there
			return min;
		}

		void printHeap()
		{
			for (int i : heap) {
				std::cout << i << " ";
			}

			std::cout << std::endl;
		}
};

// int main()
// {
// 	std::vector<int> rawArray = {4, 10, 3, 5, 1, 0, -9, 21};
// 	MinHeap minHeap(rawArray);

// 	std::cout << "Min Heap: ";
// 	minHeap.printHeap();

// 	minHeap.insert(2);
// 	std::cout << "After inserting 2: ";
// 	minHeap.printHeap();

// 	std::cout << "Extracted Min: " << minHeap.extractMin() << std::endl;
// 	std::cout << "Heap after extraction: ";
// 	minHeap.printHeap();
// }