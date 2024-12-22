#include <iostream>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = nullptr;
    }
};

// Queue class using linked list
class Queue {
private:
    Node* front; // Pointer to the front of the queue
    Node* rear;  // Pointer to the rear of the queue

public:
    // Constructor
    Queue() {
        front = rear = nullptr;
    }

    // Enqueue an element to the rear of the queue
    void enqueue(int value) {
        Node* newNode = new Node(value); // Create a new node
        if (isEmpty()) {
            front = rear = newNode; // If the queue is empty, both front and rear point to the new node
        } else {
            rear->next = newNode; // Link the new node at the end of the queue
            rear = newNode;       // Update the rear pointer
        }
        cout << value << " enqueued into the queue." << endl;
    }

    // Dequeue an element from the front of the queue
    void dequeue() {
        if (isEmpty()) {
            cout << "Queue underflow! Nothing to dequeue." << endl;
            return;
        }
        Node* temp = front;        // Save the front node
        front = front->next;      // Move the front pointer to the next node
        cout << temp->data << " dequeued from the queue." << endl;
        delete temp;              // Free memory

        // If the queue becomes empty, update rear to nullptr
        if (front == nullptr) {
            rear = nullptr;
        }
    }

    // Peek the front element of the queue
    int peek() {
        if (isEmpty()) {
            cout << "Queue is empty. Nothing to peek." << endl;
            return -1; // Return an invalid value
        }
        return front->data; // Return the data of the front node
    }

    // Check if the queue is empty
    bool isEmpty() {
        return front == nullptr;
    }

    // Display the queue
    void display() {
        if (isEmpty()) {
            cout << "Queue is empty." << endl;
            return;
        }
        Node* temp = front;
        cout << "Queue: ";
        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    // Destructor to clean up memory
    ~Queue() {
        while (!isEmpty()) {
            dequeue();
        }
    }
};

int main() {
    Queue queue;

    queue.enqueue(10);
    queue.enqueue(20);
    queue.enqueue(30);

    queue.display();

    cout << "Front element is: " << queue.peek() << endl;

    queue.dequeue();
    queue.display();

    queue.dequeue();
    queue.dequeue();
    queue.dequeue(); // Trying to dequeue from an empty queue

    return 0;
}
