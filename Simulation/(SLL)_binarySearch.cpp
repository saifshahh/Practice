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
    
    Node* binarySearch(int target){
        Node *start = head;
        Node *end = NULL;
        int size = getSize();
        
        for(int i=0; i<size; ++i){
            Node *middle = getMiddle(start,end);
            if(middle->data == target) return middle;
            else if(middle->data < target) start = middle->next;
            else end = middle;
            if(start == end) break;
        }
        return NULL;  
    }
    
    int getSize(){
        int count = 0;
        Node *temp = head;
        while(temp!=NULL){
            temp = temp->next;
            count++;
        }
        return count;
    }
    
    Node* getMiddle(Node *start, Node* end){
        Node *slow = start;
        Node *fast = start;
        
        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    
    void traverse(){
        Node *temp = head;
        while(temp != NULL){
            cout<<temp->data<<"->";
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
    l1.append(4);
    
    Node *found = l1.binarySearch(3);
    cout<<"Target found at Node "<<found<<" in the list.";
}
