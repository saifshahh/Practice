#include <iostream>
using namespace std;

class Node{
    int data;
    Node *next;
    Node *prev;
    
    public:
    Node(int data) : data(data), next(NULL), prev(NULL) {}
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
            return;
        }
        
        newNode->next = head;
        newNode->prev = NULL;
        head->prev = newNode;
        head = newNode;
        
    }
    
    void append(int value){
        Node *newNode = new Node(value);
        
        if(!head){
            head = newNode;
            return;
        }
        
        Node *temp = head;
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
        newNode->next = NULL;
    }
    
    void insertBefore(int value, int target){
        Node *newNode = new Node(value);
        Node *temp = head;
        while(temp!=NULL && temp->next->data != target){
            temp = temp->next;
        }
        newNode->next = temp->next;
        newNode->prev = temp;
        temp->next = newNode;
        
    }
    
    void insertAfter(int value, int target){
        Node *newNode = new Node(value);
        Node *temp = head;
        while(temp!=NULL && temp->data != target){
            temp = temp->next;
        }
        newNode->next = temp->next;
        newNode->prev = temp;
        temp->next = newNode;
    }
    
    void reverse(){
        Node *current = head;
        Node *temp = NULL;
        while(current != NULL){
            temp = current->prev;
            current->prev = current->next;
            current->next = temp;
            current = current->prev;
        }
        head = temp->prev;
    }
    
    void traverse(){
        Node *temp = head;
        cout<<"NULL -> ";
        while(temp != NULL){
            cout<<temp->data<<" -> ";
            temp = temp->next;
        }
        cout<<"NULL";
    }
};

int main(){
    LinkedList l1;
    l1.append(1);
    l1.append(2);
    l1.append(3);
    l1.reverse();
    l1.traverse();
}
