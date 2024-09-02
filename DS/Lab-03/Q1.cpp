#include <iostream>
using namespace std;

class Node{
    int data;
    Node* next;
    public:
    Node(int data): data(data), next(NULL) {}
    friend class LinkedList;
};

class LinkedList{
    public:
    Node* head;
    LinkedList(){
        head = NULL;
    }

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
        temp = new_node;
        return;
    }

    void insertBefore(int value, int newVal){
    	Node* new_node = new Node(newVal);
        if(!head){
            head = new_node;
            return;
        }
        Node* temp = head;
        bool flag = false
        while(temp->next != NULL){
        	if(temp->next->next->value == value){
        		flag = true;
        		break;
			}
            else temp = temp->next;	
		}
		if(flag){
			new_node->next= temp->next->next;
			temp->next=new_node;
		}
        else cout<<"\nThere is no such data"<<endl;
	}
    
    void insertAfter(int value, int newData){
		if(head!=NULL){
			Node* new_node = new Node(newData);
			Node* temp = head;
			while(temp->data!=value){
				temp = temp->next;
			}
			new_node->next = temp->next;
			temp->next = new_node; 
		}
		else cout<<"\nThere is no such data"<<endl;
	}
	
	void deleteHead(){
		if(head!=NULL){
			Node* temp = head;
			head = temp->next;
			delete temp;
			temp = NULL;
		}
		else cout<<"\nList is empty"<<endl;
	}

    void deleteLast(){
        if(head!=NULL){
            Node* temp = head;
            while(temp->next->next!=NULL){
                temp = temp->next;
            }
            Node* new_node = temp->next;
            temp->next = NULL;
            delete new_node;
            new_node = NULL;
        }
        else cout<<"\nList is empty"<<endl;
    }

    void deleteVal(int val){
        if(head){
            Node* temp = head;
            while(temp->next->value!=value){
                temp = temp->next;
            }
            Node* new_node = temp->next;
            temp->next = new_node->next;
            delete new_node;
        }
        else cout<<"\nThere is no such value"<<endl;
    }

    int nodeCounter(){
        int count;
        if(head){
            Node* temp = head;
            while(temp){
                temp = temp->next;
                count++
            }
        }
        return count;
    }

    void Display(){
        Node* temp = head;
        while(temp){
            cout<<temp->data<<"->"
            temp = temp->next;
        }
        cout<<"Null"<<endl;
    }
};

int main(){
    LinkedList list;
    cout<<"Inserting at head:"<<endl;
    list.insertHead(10);
    list.insertHead(20);
    list.insertHead(30);
    cout<<"List: ";
    list.Display();
    cout<<endl;

    cout<<"Inserting at tail:"<<endl;
    list.insertTail(40);
    cout<<"List: ";
    list.display();
    cout<<endl;

    cout<<"Inserting before value:"<<endl;
    list.insertBefore(25, 20);
    cout<<"List: ";
    list.display();
    cout<<endl;

    cout<<"Inserting after value:"<<endl;
    list.insertAfter(35, 30);
    cout<<"List: ";
    list.display(); 
    cout<<endl;

    cout<<"Deleting at head:"<<endl;
    list.deleteHead();
    cout<<"List: ";
    list.display(); 
    cout<<endl;

    cout<<"Deleting at tail:"<<endl;
    list.deleteLast();
    cout<<"List: ";
    list.display(); 
    cout<<endl;

    cout<<"Deleting node at certain value:"<<endl;
    list.deleteVal(25);
    cout<<"List: ";
    list.display(); 
    cout<<endl;

    cout<<"Number of nodes: "<<list.nodeCounter()<<endl;
}
