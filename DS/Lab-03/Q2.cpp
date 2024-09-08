#include <iostream>
using namespace std;

class Node{
    int data;
    Node *next;

    public:
        Node(int data) : data(data) { next = nullptr; }
        friend class LinkedList;
};

class LinkedList
{
    Node *head;

public:
    LinkedList() : head(nullptr) {}
    LinkedList(Node *n) : head(n) {}

    void insertNodeAtFront(int val){
        Node *temp = new Node(val);
        if(head == nullptr){
            head = temp;
            return;
        }
        temp->next = head;
        head = temp;
    }

    void insertNodeAtEnd(int val){
        Node *temp = new Node(val);
        if(head == nullptr){
            head = temp;
            return;
        }

        Node *new_node = head;
        while (new_node->next != nullptr){
            new_node = new_node->next;
        }

        new_node->next = temp;
        temp->next = nullptr;
    }

    void reverseNode(){
        Node* current = head;
        Node* last = nullptr;

        while(current != nullptr){
            Node* new_node = current->next;
            current->next = last;
            last = current;
            current = new_node;
        }
        head = last;
    }

    void traversal() const {
        Node* new_node = head;
        while(new_node != nullptr){
            cout << new_node->data << " ";
            new_node = new_node->next;
        }
        cout << endl;
    }
};

int main(){
    LinkedList list;
    list.insertNodeAtFront(1);
    list.insertNodeAtEnd(2);
    list.insertNodeAtEnd(3);
    list.insertNodeAtEnd(4);
    list.traversal();
    list.reverseNode();
    cout<<"After Reversal: "<<endl;
    list.traversal();
}
