#include <iostream>
#include <climits> // for INT_MIN and INT_MAX
using namespace std;

struct Item {
    int value;
    int priority;
};

Item pr[1000]; // Priority queue
int size_PQ = -1;


void enqueue(int value, int priority) {
    size_PQ++;
    pr[size_PQ].value = value;
    pr[size_PQ].priority = priority;
}




// Function to find the index of the element with the lowest priority (ascending)

int peekAscending() {
    int lowestPriority = INT_MAX;
    int ind = -1;

    for (int i = 0; i <= size_PQ; i++) {
        if (lowestPriority > pr[i].priority) {
            lowestPriority = pr[i].priority;
            ind = i;
        }
    }
    return ind;
}


// Function to find the index of the element with the highest priority (descending)

int peekDescending() {
    int highestPriority = INT_MIN;
    int ind = -1;

    for (int i = 0; i <= size_PQ; i++) {
        if (highestPriority < pr[i].priority) {
            highestPriority = pr[i].priority;
            ind = i;
        }
    }
    return ind;
}


// General dequeue function, takes a boolean flag for ascending or descending

void dequeue(bool ascending = true) {
    int ind = ascending ? peekAscending() : peekDescending();
    for (int i = ind; i < size_PQ; i++) {
        pr[i] = pr[i + 1];
    }
    size_PQ--;
}





int main() {
    enqueue(10, 2);
    enqueue(14, 4);
    enqueue(12, 3);
    enqueue(7, 1);

    // Ascending Priority Queue
    cout << "Ascending Order Priority Queue:" << endl;
    while (size_PQ >= 0) {
        cout << "Dequeued value: " << pr[peekAscending()].value << endl;
        dequeue(true);  // Passing true for ascending order
    }

    // Resetting queue for demonstration
    enqueue(10, 2);
    enqueue(14, 4);
    enqueue(12, 3);
    enqueue(7, 1);

    // Descending Priority Queue
    cout << "\nDescending Order Priority Queue:" << endl;
    while (size_PQ >= 0) {
        cout << "Dequeued value: " << pr[peekDescending()].value << endl;
        dequeue(false);  // Passing false for descending order
    }

    return 0;
}




 Implementing Priority Queue Using Arrays
Code 

#include <iostream>
using namespace std;

// Structure for priority queue elements
struct Item {
    int value;
    int priority;
};


// PriorityQueue class
class PriorityQueue {
private:


    Item pr[100000]; // Array to store elements
    int size_PrQ;    // Pointer to the last index



public:
    // Constructor to initialize the size

  PriorityQueue() : size_PrQ(-1) {}


    // Method to add an element to the priority queue

    void enqueue(int value, int priority) {
        size_PrQ++;
        pr[size_PrQ].value = value;
        pr[size_PrQ].priority = priority;
    }


    // Method to get the index of the element with the highest priority

    int peek() {
        int highestPriority = INT_MIN, ind = -1;
        for (int i = 0; i <= size_PrQ; i++) {
            if (highestPriority == pr[i].priority && ind > -1 && pr[ind].value < pr[i].value) {
                highestPriority = pr[i].priority;
                ind = i;
            } else if (highestPriority < pr[i].priority) {
                highestPriority = pr[i].priority;
                ind = i;
            }
        }
        return ind;
    }


    // Method to remove the element with the highest priority

    void dequeue() {
        int ind = peek();
        for (int i = ind; i < size_PrQ; i++) {
            pr[i] = pr[i + 1];
        }
        size_PrQ--;
    }



    // Method to check if the priority queue is empty
    bool isEmpty() {
        return size_PrQ == -1;
    }


    // Method to get the size of the priority queue

    int size() {
        return size_PrQ + 1;
    }



    // Method to get the value of the item with the highest priority

    int highestPriorityValue() {
        int ind = peek();
        return pr[ind].value;
    }


    // Method to get the priority of the item with the highest priority

    int highestPriority() {
        int ind = peek();
        return pr[ind].priority;
    }
};






int main() {
    PriorityQueue pq;
    pq.enqueue(10, 2);
    pq.enqueue(14, 4);
    pq.enqueue(16, 4);
    pq.enqueue(12, 3);

    cout << "Element with highest priority: " << pq.highestPriorityValue() << " (Priority: " << pq.highestPriority() << ")" << endl;
    pq.dequeue();
    cout << "Element with next highest priority after dequeue: " << pq.highestPriorityValue() << " (Priority: " << pq.highestPriority() << ")" << endl;

    return 0;
}





Implementing Priority Queue Using Linked List



#include <iostream>
using namespace std;

// Node structure for linked list
class Node {
public:
    int data;
    int priority;
    Node* next;

    Node(int d, int p) {
        data = d;
        priority = p;
        next = nullptr;
    }
};

class PriorityQueue {
private:
    Node* head;

public:
    // Constructor to initialize the empty queue
    PriorityQueue() {
        head = nullptr;
    }

    // Pushes a new element into the priority queue
    void push(int d, int p) {
        Node* temp = new Node(d, p);

        // If the list is empty or the new node has higher priority than the head
        if (head == nullptr || head->priority < p) {
            temp->next = head;
            head = temp;
        } else {
            // Traverse the list to find the appropriate position
            Node* start = head;
            while (start->next != nullptr && start->next->priority > p) {
                start = start->next;
            }
            temp->next = start->next;
            start->next = temp;
        }
    }

    // Peeks at the highest priority element
    int peek() {
        if (head != nullptr) {
            return head->data;
        }
        return -1;  // or some error value if empty
    }

    // Pops the highest priority element
    void pop() {
        if (head != nullptr) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }

    // Checks if the priority queue is empty
    bool isEmpty() {
        return head == nullptr;
    }

    // Destructor to clean up the queue
    ~PriorityQueue() {
        while (head != nullptr) {
            pop();
        }
    }
};




int main() {
    PriorityQueue pq;
    pq.push(4, 1);
    pq.push(5, 2);
    pq.push(6, 3);
    pq.push(7, 0);

    while (!pq.isEmpty()) {
        cout << " " << pq.peek();
        pq.pop();
    }

    return 0;
}







Implementing Priority Queue Using Heaps
(Max heap implementation)


#include <iostream>
#include <vector>
using namespace std;

class MaxQueue {
private:
    vector<int> heap;  // Vector to store the elements of the heap

    // Helper function to maintain the heap property (Max-Heap)
    void heapifyUp(int index) {
        // As long as the element is not at the root and is greater than its parent
        while (index > 0 && heap[index] > heap[(index - 1) / 2]) {
            swap(heap[index], heap[(index - 1) / 2]);
            index = (index - 1) / 2;  // Move up to the parent index
        }
    }

    // Helper function to maintain the heap property after removal (Max-Heap)
    void heapifyDown(int index) {
        int left = 2 * index + 1;
        int right = 2 * index + 2;
        int largest = index;

        // Find the largest among root, left child, and right child
        if (left < heap.size() && heap[left] > heap[largest]) {
            largest = left;
        }
        if (right < heap.size() && heap[right] > heap[largest]) {
            largest = right;
        }

        // Swap and continue heapifying down if necessary
        if (largest != index) {
            swap(heap[index], heap[largest]);
            heapifyDown(largest);
        }
    }

public:
    // Method to enqueue an element (insert into heap)
    void enqueue(int element) {
        heap.push_back(element);  // Add element to the end of the heap
        heapifyUp(heap.size() - 1);  // Move the element up to its correct position
    }

    // Method to dequeue an element (remove the root of the heap)
    void dequeue() {
        if (!heap.empty()) {
            swap(heap[0], heap[heap.size() - 1]);  // Swap root with the last element
            heap.pop_back();  // Remove the last element
            heapifyDown(0);   // Move the root down to its correct position
        }
    }

    // Method to peek at the root element (the max element)
    int peek() {
        if (!heap.empty()) {
            return heap[0];  // The root of the heap is the max element
        }
        return -1;  // Return -1 if the heap is empty
    }

    // Method to check if the queue is empty
    bool isEmpty() {
        return heap.empty();
    }
};


int main() {
    MaxQueue queue;
    
    // Enqueue elements
    queue.enqueue(10);
    queue.enqueue(20);
    queue.enqueue(15);

    // Peek at the front element (highest priority element)
    cout << queue.peek() << endl; // Output: 20

    // Dequeue the front element
    queue.dequeue();

    // Peek again after dequeue
    cout << queue.peek() << endl; // Output: 15

    return 0;
}






