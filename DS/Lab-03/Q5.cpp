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

class DoublyList
{
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

    void insertTail(int val){
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

    void traversal(){
        Node *temp = head;

        while(temp != nullptr){
            cout << temp->data << "->";
            temp = temp->next;
        }
        cout << "NULL";
    }

    void sorting(){
        Node *p1 = head;
        while(p1 != nullptr){
            Node *p2 = p1->next;
            while (p2 != nullptr){
                if(p1->data > p2->data){
                    int temp = p1->data;
                    p1->data = p2->data;
                    p2->data = temp;
                }
                p2 = p2->next;
            }
            p1 = p1->next;
        }
    }

    void removeDup(){
        Node *p1 = head;
        while (p1 != nullptr){
            Node *p2 = p1->next;
            while (p2 != nullptr){
                if (p1->data == p2->data){
                    p1->next = p2->next;
                    p2->next->prev = p1;
                }
                p2 = p2->next;
            }
            p1 = p1->next;
        }
    }
};

int main()
{
    DoublyList D_List;
    D_List.insertHead(4);
    D_List.insertTail(3);
    D_List.insertTail(3);
    D_List.insertTail(1);
    D_List.insertTail(2);
    D_List.insertTail(2);
    
    D_List.traversal();
    D_List.sorting();
    cout << "\n\nAfter sorting: " << endl;
    D_List.traversal();
    D_List.removeDup();
    cout << "\n\nAfter removing duplicates: " << endl;
    D_List.traversal();
}
