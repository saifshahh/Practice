#include <iostream>
using namespace std;

class Node{

    public:
    int data;
    Node* next;

    Node(int data=0) : data(data), next(nullptr) {}
    ~Node(){
        next = nullptr;
    }
};

void LinkedListTraversal(Node *temp){
    while (temp != nullptr){
        cout << temp->data << endl;
        temp = temp->next;
    }
}

bool isFull(){
    Node* temp = new Node();
    if (temp == nullptr) return true;
    delete temp;
    return false;
}

bool isEmpty(Node* s){
    return (s == nullptr);
}

Node* push(Node* top, int x){
    if(isFull()) cout << "Stack Overflow!" << endl;  
    else{
        Node* temp = new Node(x);
        temp->next = top;
        top = temp;
    }
    return top;
}

Node* pop(Node* top){
    if(isEmpty(top)){
        cout<<"Stack Underflow!"<<endl;
    }
    else{
        Node* temp = top;
        top = top->next;
        delete temp;
    }
    return top;
}

int peek(Node* top, int pos){
    Node* temp = top;
    for(int i=0; i<pos-1 && temp != nullptr; i++) temp = temp->next;
    
    if(temp != nullptr){
        return temp->data;
    }
    return -1;
}

int StackTop(Node* top){
    return top->data;
}

int StackBottom(Node* top){
    Node* temp = top;
    while(temp->next != nullptr){
        temp = temp->next;
    }
    return temp->data;
}

int main(){

    Node* top = nullptr;
    top = push(top, 78);
    top = push(top, 7);
    top = push(top, 8);

    cout<<StackBottom(top)<<endl;
    cout<<StackTop(top);

    while (top != nullptr){
        Node* temp = top;
        top = top->next;
        delete temp;
    }
    return 0;
}
