#include <iostream>
using namespace std;

class Node{
    int data;
    Node *next;

    public:
        Node(int data) : data(data), next(NULL) {}
        friend class LinkedList;
};

class LinkedList{
    Node *head;

    public:
        LinkedList() : head(nullptr) {}
        LinkedList(Node *n) : head(n) {}

    void insertNodeAtFront(int val){
        Node *new_node = new Node(val);
        if(head == nullptr){
            head = new_node;
            return;
        }
        new_node->next = head;
        head = new_node;
    }

    void insertNodeAtEnd(int val){
        Node *new_node = new Node(val);
        if(head == nullptr){
            head = new_node;
            return;
        }

        Node *temp = head;
        while (temp->next != nullptr){
            temp = temp->next;
        }

        temp->next = new_node;
        new_node->next = nullptr;
    }

    void checker(){

        if(head == nullptr || head->next == nullptr){
            return;
        }

        Node *p1 = head;

        while(p1 != nullptr){
            Node *p2 = p1->next;

            while(p2 != nullptr){
                if(p1->data % 2 != 0 && p2->data % 2 == 0){
                    int new_node = p1->data;
                    p1->data = p2->data;
                    p2->data = new_node;
                }
                p2 = p2->next;
            }
            p1 = p1->next;
        }
    }

    void traversal() const {
        Node* temp = head;
        while(temp != nullptr){
            cout << temp->data << " ";
            temp = temp->next;
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
    list.insertNodeAtEnd(5);
    list.insertNodeAtEnd(6);
    
    list.traversal();
    list.checker();
    cout << "After Arrangement: " << endl;
    list.traversal();
}
