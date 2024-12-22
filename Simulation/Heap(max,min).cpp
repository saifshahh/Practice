#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Function to heapify a subtree rooted at index i (Max Heap)
void maxHeapify(vector<int>& arr, int n, int i) {
    int largest = i;  // Initialize largest as root
    int left = 2 * i + 1;  // Left child
    int right = 2 * i + 2;  // Right child

    if (left < n && arr[left] > arr[largest]) {
        largest = left;
    }

    if (right < n && arr[right] > arr[largest]) {
        largest = right;
    }

    if (largest != i) {
        swap(arr[i], arr[largest]);
        maxHeapify(arr, n, largest);
    }
}

// Function to build a Max Heap
void buildMaxHeap(vector<int>& arr) {
    int n = arr.size();
    for (int i = n / 2 - 1; i >= 0; i--) {
        maxHeapify(arr, n, i);
    }
}

// Function to heapify a subtree rooted at index i (Min Heap)
void minHeapify(vector<int>& arr, int n, int i) {
    int smallest = i;  // Initialize smallest as root
    int left = 2 * i + 1;  // Left child
    int right = 2 * i + 2;  // Right child

    if (left < n && arr[left] < arr[smallest]) {
        smallest = left;
    }

    if (right < n && arr[right] < arr[smallest]) {
        smallest = right;
    }

    if (smallest != i) {
        swap(arr[i], arr[smallest]);
        minHeapify(arr, n, smallest);
    }
}

// Function to build a Min Heap
void buildMinHeap(vector<int>& arr) {
    int n = arr.size();
    for (int i = n / 2 - 1; i >= 0; i--) {
        minHeapify(arr, n, i);
    }
}

// Function to print the array
void printArray(const vector<int>& arr) {
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;
}

int main() {
    vector<int> arr = {35, 12, 50, 22, 60, 3, 90, 25, 17, 70, 45};

    // Max Heap
    vector<int> maxHeap = arr;  // Copy the original array
    buildMaxHeap(maxHeap);
    cout << "Max Heap: ";
    printArray(maxHeap);

    // Min Heap
    vector<int> minHeap = arr;  // Copy the original array
    buildMinHeap(minHeap);
    cout << "Min Heap: ";
    printArray(minHeap);

    return 0;
}
