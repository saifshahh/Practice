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

    void dequeue(){

        if(!head) cout<<"Queue is empty!"<<endl;

        Node* temp = head;
        head = head->next;
        delete temp;
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
