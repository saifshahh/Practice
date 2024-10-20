#include <iostream>
using namespace std;

class Node{
public:
    int data;
    Node* next;

    Node(int val) : data(val), next(nullptr) {}
};

class LinkedList {
private:
    Node* head;

    void swap(Node* a, Node* b){
        int temp = a->data;
        a->data = b->data;
        b->data = temp;
    }

    Node* getTail(Node* curr){
        while (curr != nullptr && curr->next != nullptr) {
            curr = curr->next;
        }
        return curr;
    }

    Node* partition(Node* head, Node* end, Node** Head, Node** End){
        Node* pivot = end;
        Node* prev = nullptr;
        Node* current = head;
        Node* tail = pivot;

        while(current != pivot){
            if(current->data < pivot->data){
                if(*Head == nullptr) *Head = current;
                prev = current;
                current = current->next;
            } 
            else{
                if(prev) prev->next = current->next;
                Node* temp = current->next;
                current->next = nullptr;
                tail->next = current;
                tail = current;
                current = temp;
            }
        }
        if(*Head == nullptr) *Head = pivot;  
        *End = tail;
        return pivot;
    }

    Node* quickSortRecur(Node* head, Node* end){
        if(!head || head == end) return head;
        Node* Head = nullptr;
        Node* End = nullptr;

        Node* pivot = partition(head, end, &Head, &End);
        if(Head != pivot){
            Node* temp = Head;
            while(temp->next != pivot){
                temp = temp->next;
            }
            temp->next = nullptr;
            Head = quickSortRecur(Head, temp);
            temp = getTail(Head);
            temp->next = pivot;
        }
        pivot->next = quickSortRecur(pivot->next, End);
        return Head;
    }

public:
    LinkedList() : head(nullptr) {}

    void push(int value){
        Node* newNode = new Node(value);
        newNode->next = head;
        head = newNode;
    }

    void quickSort(){
        head = quickSortRecur(head, getTail(head));
    }

    void traverse(){
        Node* temp = head;
        while(temp){
            cout << temp->data << "->";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};

int main(){
    LinkedList l1;
    l1.push(3);
    l1.push(5);
    l1.push(1);
    l1.push(9);
    l1.push(8);
    l1.push(7);
    l1.push(10);

    cout << "Linked List before sorting: ";
    l1.traverse();

    l1.quickSort();

    cout << "Linked List after sorting: ";
    l1.traverse();
}

