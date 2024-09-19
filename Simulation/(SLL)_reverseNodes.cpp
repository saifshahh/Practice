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
    }
    
    void reverse(){
        Node *prev = NULL;
        Node *next = NULL;
        Node *current = head;
        
        while(current != NULL){
            next = current->next;
            current->next = prev;
            
            prev = current;
            current = next;
        }
        head = prev;
    }
    
    void traverse(){
        Node *temp = head;
        while(temp != NULL){
            cout<<temp->data<<" ";
            temp = temp->next;
        }
        cout<<"NULL";
    }
};

int main(){
    LinkedList l1;
    l1.append(1);
    l1.append(2);
    l1.reverse();
    l1.traverse();
}
