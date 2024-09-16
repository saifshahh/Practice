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
    Node* head;
    
    public:
    LinkedList() { head = NULL; }
    
    void insertHead(int value){
        Node* newNode = new Node(value);
        newNode->next = head;
        head = newNode;
    }
    
    void append(int value){
        Node *newNode = new Node(value);
        if(!head){
            head = newNode;
            return;
        }
        
        Node *temp = head;
        while(temp->next){
            temp = temp->next;
        }
        temp->next = newNode;
    }
    
    void insertBefore(int value, int target){
        Node *newNode = new Node(value);
        if(head!=NULL && head->data == target){
            newNode->next = head;
            head = newNode;
            return;
        }
        
        Node *temp = head;
        while(temp!=NULL && temp->next!=NULL){
            if(temp->next->data == target){
                newNode->next = temp->next;
                temp->next = newNode;
                return;
            }
            temp = temp->next;
        }
    }
    
    void insertAfter(int value, int target){
        Node *newNode = new Node(value);
        if(head){
           Node *temp = head;
           
           while(temp!=NULL && temp->data!=target){
               temp = temp->next;
           }
           if(temp){
               newNode->next = temp->next;
               temp->next = newNode;
           }
        }
    }
    
    void deleteHead(){
        if(head){
            Node *temp = head;
            head = temp->next;
            delete temp;
        }
    }
    
    void deleteLast(){
        if(head){
            if(head->next == NULL){
                delete head;
                head = NULL;
                return;
            }
        }
        Node *temp = head;
        while(temp->next->next){
            temp = temp->next;
        }
        delete temp->next;
        temp->next = NULL;
    }
    
    void deleteValue(int target){
        if(head){
            if(head->data == target){
                Node* temp = head;
                head = temp->next;
                delete temp;
                return;
            }
            else{
                Node *temp = head;
                while(temp->next!= NULL && temp->next->data!=target){
                    temp = temp->next;
                }
                if(temp){
                    Node *del = temp->next;
                    temp->next = del->next;
                    delete del;
                }
            }
        }
    }
    
    int count(){
        int count=0;
        if(head){
            Node *temp = head;
            while(temp!=NULL){
                temp = temp->next;
                count++;
            }
        }
        return count;
    }
    
    void Display(){
        Node *temp = head;
        while(temp!=NULL){
            cout<<temp->data<<"->";
            temp = temp->next;
        }
        cout<<"NULL";
    }
};

int main(){
    
    LinkedList l1;
    l1.insertHead(10);
    l1.insertHead(20);
    l1.insertHead(30);
    l1.Display();
    
    cout<<endl;
    l1.append(40);
    l1.Display();
    
    cout<<endl;
    l1.insertBefore(11, 40);
    l1.Display();
    
    cout<<endl;
    l1.insertAfter(12, 11);
    l1.Display();
    
    cout<<endl;
    l1.deleteHead();
    l1.Display();
    
    cout<<endl;
    l1.deleteLast();
    l1.Display();
    
    cout<<endl;
    l1.deleteValue(20);
    l1.Display();
    
    cout<<"\nThe total number of Nodes is "<<l1.count()<<".";

}
