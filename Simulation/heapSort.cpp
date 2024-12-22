#include <iostream>
#include <vector>
using namespace std;

// Function to heapify a subtree rooted at index i
void heapify(vector<int>& arr, int n, int i) {
    int largest = i;  // Initialize largest as root
    int left = 2 * i + 1;  // Left child
    int right = 2 * i + 2;  // Right child

    // If left child is larger than root
    if (left < n && arr[left] > arr[largest]) {
        largest = left;
    }

    // If right child is larger than largest so far
    if (right < n && arr[right] > arr[largest]) {
        largest = right;
    }

    // If largest is not root, swap and continue heapifying
    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);  // Recursive call
    }
}

// Function to build a max heap from an unsorted array
void buildMaxHeap(vector<int>& arr) {
    int n = arr.size();
    // Start from the last non-leaf node and heapify each node
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }
}

// Function to implement heap sort
void heapSort(vector<int>& arr) {
    int n = arr.size();
    
    // Build a max heap
    buildMaxHeap(arr);

    // One by one extract elements from the heap
    for (int i = n - 1; i > 0; i--) {
        // Move current root to the end
        swap(arr[0], arr[i]);

        // Call heapify on the reduced heap
        heapify(arr, i, 0);
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
    vector<int> arr = {12, 11, 13, 5, 6, 7};

    cout << "Original array: ";
    printArray(arr);

    // Build max heap
    buildMaxHeap(arr);
    cout << "Max heap: ";
    printArray(arr);

    // Apply heap sort
    heapSort(arr);

    cout << "Sorted array: ";
    printArray(arr);

    return 0;
}
