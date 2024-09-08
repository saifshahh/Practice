#include <iostream>
using namespace std;

class Node{
    int data;
    Node* next;
    public:
        Node(int data): data(data),next(NULL) {}
        friend class LinkedList;
};

class LinkedList{
    public:
        Node* head;
        LinkedList() { head = NULL; }

    void insertHead(int data){
        Node* new_node = new Node(data);
        new_node->next = head;
        head = new_node;
    }

    void insertTail(int data){
        Node* new_node = new Node(data);
        if(!head){
            head = new_node;
            return;
        }
        Node* temp = head;
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = new_node;
    }

    void insertBefore(int value, int value2){
        Node* new_node = new Node(value2);

        if(head != NULL && head->data == value){
            insertHead(value2);
            return;
        }

        Node* temp = head;
        bool flag = false;

        while(temp != NULL && temp->next != NULL){
            if(temp->next->data == value){
                flag = true;
                break;
            }
            temp = temp->next;
        }

        if(flag){
            new_node->next = temp->next;
            temp->next = new_node;
        } 
        else cout << "\nThere is no such data" << endl;
    }

    void insertAfter(int value, int value2) {
        if(head != NULL){
            Node* temp = head;

            while (temp != NULL && temp->data != value) {
                temp = temp->next;
            }

            if(temp != NULL){
                Node* new_node = new Node(value2);
                new_node->next = temp->next;
                temp->next = new_node;
            } 
            else cout << "\nThere is no such data" << endl;
        } 
        else cout << "\nList is empty" << endl;
    }

    void deleteHead(){
        if(head != NULL){
            Node* temp = head;
            head = temp->next;
            delete temp;
        } 
        else cout << "\nList is empty" << endl;
    }

    void deleteLast(){
        if(head != NULL){
            if(head->next == NULL){
                delete head;
                head = NULL;
            } 
            else{
                Node* temp = head;
                while(temp->next->next != NULL){
                    temp = temp->next;
                }
                delete temp->next;
                temp->next = NULL;
            }
        } 
        else cout << "\nList is empty" << endl;
    }

    void deleteVal(int val){
        if(head != NULL){
            if(head->data == val){
                deleteHead();
                return;
            }
            Node* temp = head;
            while(temp->next != NULL && temp->next->data != val){
                temp = temp->next;
            }

            if(temp->next != NULL){
                Node* to_delete = temp->next;
                temp->next = to_delete->next;
                delete to_delete;
            } 
            else cout << "\nThere is no such value" << endl;
        } 
        else cout << "\nList is empty" << endl;
    }

    int nodeCounter(){
        int count = 0;
        Node* temp = head;
        while(temp != NULL){
            count++;
            temp = temp->next;
        }
        return count;
    }

    void Display(){
        Node* temp = head;
        while(temp != NULL){
            cout << temp->data << "->";
            temp = temp->next;
        }
        cout << "Null" << endl;
    }
};

int main(){
    
    LinkedList list;
    cout << "Inserting at head:" << endl;
    list.insertHead(10);
    list.insertHead(20);
    list.insertHead(30);
    cout << "List: ";
    list.Display();
    cout << endl;

    cout << "Inserting at tail:" << endl;
    list.insertTail(40);
    cout << "List: ";
    list.Display();
    cout << endl;

    cout << "Inserting before value:" << endl;
    list.insertBefore(20, 25);
    cout << "List: ";
    list.Display();
    cout << endl;

    cout << "Inserting after value:" << endl;
    list.insertAfter(30, 35);
    cout << "List: ";
    list.Display();
    cout << endl;

    cout << "Deleting at head:" << endl;
    list.deleteHead();
    cout << "List: ";
    list.Display();
    cout << endl;

    cout << "Deleting at tail:" << endl;
    list.deleteLast();
    cout << "List: ";
    list.Display();
    cout << endl;

    cout << "Deleting node with certain value:" << endl;
    list.deleteVal(25);
    cout << "List: ";
    list.Display();
    cout << endl;

    cout << "Number of nodes: " << list.nodeCounter() << endl;
}
