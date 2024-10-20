#include <iostream>
#include <vector>
using namespace std;

class Node{
    public:
    string name;
    int data;
    Node* next;
    
    Node(string name = "", int data = 0, Node* next = nullptr) : name(name), data(data), next(next) {}
};

class Records{
    public:
    Node* head;
    
    Records() : head(nullptr){}
    
    void add(string name, int data){
        Node* newNode = new Node(name, data);
        
        if(!head){
            head = newNode;
            return;
        }    
        
        Node* temp = head;
        while(temp->next != nullptr){
            temp = temp->next;
        }
        temp->next = newNode;
    }
    
    void print(){
        Node* temp = head;
        
        while(temp != nullptr){
            cout << temp->name << "  " << temp->data << endl;
            temp = temp->next;
        }
    }
    
    int getMax(){
        Node* temp = head;
        int max = head->data;
        
        while(temp != nullptr){
            if(max < temp->data) max = temp->data;  
            temp = temp->next;
        }
        return max;
    }
    
    Node* countSort(Node* head, int exp){
        Node* count[10] = {nullptr};
        Node* tails[10] = {nullptr};
        
        Node* temp = head;
        while(temp != nullptr){
            int digit = (temp->data / exp) % 10; 
            if(count[digit] == nullptr) count[digit] = tails[digit] = temp;
            else{
                tails[digit]->next = temp;
                tails[digit] = temp;
            }
            temp = temp->next;
        }
        
        Node* newHead = nullptr;
        Node* newTail = nullptr;
        
        for(int i =0; i < 10; i++){
            if(count[i] != nullptr){
                if(newHead == nullptr){
                    newHead = count[i];
                    newTail = tails[i];
                }else{
                    newTail->next = count[i];
                    newTail = tails[i];
                }
            }
        }
        newTail->next = nullptr;
        return newHead;
    }
    
    void radixSort(){
        if(!head || !head->next) return;      
        int max = getMax();
        for(int exp = 1; max / exp > 0; exp *= 10){
            head = countSort(head, exp);
        }
    } 
};

int main(){
    Records r1;
    r1.add("Ayan",90);
    r1.add("Ali",60);
    r1.add("Sara", 70);
    r1.add("Zara", 50);
    r1.add("Jeena", 40);
    
    cout << "Before Sorting: \n";
    r1.print();
    cout << endl << endl;
    
    r1.radixSort();
    cout << "After Sorting: \n";
    r1.print();
}
