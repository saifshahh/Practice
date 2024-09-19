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
    LinkedList() : head(NULL) {}
    
    void insertHead(int value){
        Node *newNode = new Node(value);
        
        if(!head){
            head = newNode;
            newNode->next = head;
            return;
        }
        
        Node* temp = head;
        while(temp->next != head){
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = head;
        head = newNode;
    }
    
    void append(int value){
        Node *newNode = new Node(value);
        
        if(!head){
            head = newNode;
            newNode->next = head;
            return;
        }
        
        Node *temp = head;
        while(temp->next != head){
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = head;
    }
    
    
    void traverse(){
        Node *temp = head;
        do {
            cout<<temp->data<<" -> ";
            temp = temp->next;
        } while(temp != head);
        cout<<"NULL";
    }
};

int main(){
    LinkedList l1;
    l1.append(1);
    l1.append(2);
    l1.append(3);
    l1.traverse();
}
