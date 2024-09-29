#include <iostream>

using namespace std;

class Node{
    int data;
    Node* next;

    public:
        Node(int data=0, Node* next = nullptr): data(data), next(next) {}
        friend class LinkedList;
};

class LinkedList{
    Node* head;

    Node* reverseHelper(Node* temp){
        if(!temp || !temp->next) return temp;

        Node* reversed = reverseHelper(temp->next);
        temp->next->next = temp;
        temp->next = nullptr;

        return reversed;
    }

    public:
        LinkedList() : head(nullptr) {}

        void insertAtFront(int data) {
            head = new Node(data, head);
        }

        void reverse() {
            head = reverseHelper(head);
        }

        void printList() {
            for(Node* temp = head; temp; temp = temp->next) {
                cout << temp->data << "->";
            }
            cout << "NULL" << endl;
        }
};

int main() {
    LinkedList l1;
    l1.insertAtFront(1);
    l1.insertAtFront(2);
    l1.insertAtFront(3);
    l1.insertAtFront(4);
    l1.insertAtFront(5);
    l1.insertAtFront(6);
    l1.insertAtFront(7);
    l1.insertAtFront(8);

    cout << "Before reversing" << endl;
    l1.printList();
    
    l1.reverse();
    cout << endl << "After reversing" << endl;
    l1.printList();
}
