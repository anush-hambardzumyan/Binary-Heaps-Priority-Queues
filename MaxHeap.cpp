#include <iostream>
#include <vector>

class MaxHeap {
protected:
    std::vector<int> heap;

    // Helper functions for tree imitation
    int parent(int i) { return (i - 1) / 2; }
    int left(int i) { return (i * 2) + 1; }
    int right(int i) { return (i * 2) + 2; }

    void heapifyDown(int i) 
    {
        int largest = i;
        int l = left(i);
        int r = right(i);

        if (l < heap.size() && heap[l] > heap[largest]) {
            largest = l;
        }
        if (r < heap.size() && heap[r] > heap[largest]) {
            largest = r;
        }
        if (largest != i) {
            std::swap(heap[i], heap[largest]);
            heapifyDown(largest);
        }
    }

    void heapifyUp(int i) {
        while (i != 0 && heap[parent(i)] < heap[i]) 
        {
            std::swap(heap[i], heap[parent(i)]);
            i = parent(i);
        }
    }

public:
    MaxHeap() {}

    MaxHeap(const std::vector<int>& rawArray) 
    {
        for (int i : rawArray) {
            insert(i);
        }
    }

    void insert(int value) 
    {
        heap.push_back(value);
        heapifyUp(heap.size() - 1);
    }

    int extractMax() {
        if (heap.empty()) {
            throw std::runtime_error("Heap is empty");
        }
        int max = heap[0];
        heap[0] = heap.back();
        heap.pop_back();
        heapifyDown(0);
        return max;
    }

    void printHeap() {
        for (int i : heap) {
            std::cout << i << " ";
        }
        std::cout << std::endl;
    }
};

// int main() {
//     std::vector<int> rawArray = {4, 10, 3, 5, 1, 0, -9, 21};
//     MaxHeap maxHeap(rawArray);

//     std::cout << "Max Heap: ";
//     maxHeap.printHeap();

//     maxHeap.insert(2);
//     std::cout << "After inserting 2: ";
//     maxHeap.printHeap();

//     std::cout << "Extracted Max: " << maxHeap.extractMax() << std::endl;
//     std::cout << "Heap after extraction: ";
//     maxHeap.printHeap();
// }
