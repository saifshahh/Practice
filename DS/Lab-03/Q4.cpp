#include <iostream>
using namespace std;

class Node{
    int data;
    Node *prev;
    Node *next;

    public:
        Node(int data) : data(data){
        prev = nullptr;
        next = nullptr;
    }
    friend class DoublyList;
};

class DoublyList{
    Node *head;

    public:
        DoublyList() : head(nullptr) {}
        DoublyList(Node *n) : head(n) {}

    void insertHead(int val){
        Node *new_node = new Node(val);

        if(head == nullptr){
            head = new_node;
            return;
        }

        new_node->prev = nullptr;
        new_node->next = head;
        head->prev = new_node;
        head = new_node;
    }

    void insertLast(int val){
        Node *new_node = new Node(val);
        Node *temp = head;

        if(head == nullptr){
            insertHead(val);
            return;
        }

        while(temp->next != nullptr){
            temp = temp->next;
        }

        temp->next = new_node;
        new_node->prev = temp;
        new_node->next = nullptr;
    }

    void insertBefore(int value, int val){
        Node *new_node = new Node(val);
        Node *temp = head;

        while(temp->next->data != value){
            temp = temp->next;
        }
        new_node->next = temp->next;
        new_node->prev = temp;
        temp->next = new_node;
    }

    void insertAfter(int value, int val){
        Node *new_node = new Node(val);
        Node *temp = head;

        while(temp->data != value){
            temp = temp->next;
        }
        new_node->next = temp->next;
        new_node->prev = temp;
        temp->next = new_node;
    }

    void deleteHead(){
        if(head == nullptr) return;
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    void deleteLast(){
        if (head == nullptr) return;

        Node* p1 = head;
        Node* p2 = head->next;
        while (p2->next != nullptr){
            p1 = p1->next;
            p2 = p2->next;
        }
        p1->next = nullptr;
        delete p2;
    }

    void deleteVal(int val){
        if(head == nullptr) return;

        Node* p1 = head;
        Node* p2 = head->next;

        while (p2->data != val){
            p1 = p1->next;
            p2 = p2->next;
        }
        p1->next = p2->next;
        delete p2;
    }

    void traversal(){
        Node *temp = head;

        while (temp != nullptr){
            cout << temp->data << "->";
            temp = temp->next;
        }
        cout << "NULL";
    }
};

int main(){
    DoublyList list;
    list.insertHead(1);
    list.insertLast(2);
    list.insertLast(3);
    list.insertBefore(3, 4);
    list.insertAfter(2,5);
    list.traversal();
    list.deleteHead();

    cout<<"\n\nTraversal after deleting first Node: "<<endl;
    list.traversal();
    list.deleteLast();

    cout<<"\n\nTraversal after deleting last Node: "<<endl;
    list.traversal();
    list.deleteVal(5);

    cout<<"\n\nTraversal after deleting Specific Node: "<<endl;
    list.traversal();
}
