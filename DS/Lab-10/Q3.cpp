#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Node{
    int data;
    Node* next;
    Node(int data) : data(data), next(nullptr) {}
};

struct Compare{
    bool operator()(Node* a, Node* b){
        return a->data > b->data; 
    }
};

Node* mergeKSortedLists(vector<Node*>& lists){
    priority_queue<Node*, vector<Node*>, Compare> minHeap;

    for(auto element : lists){
        if(element) minHeap.push(element);
    }

    Node* dummy = new Node(0);
    Node* current = dummy;

    while(!minHeap.empty()){
        Node* smallest = minHeap.top();
        minHeap.pop();

        current->next = smallest;
        current = current->next;
        if(smallest->next) minHeap.push(smallest->next);
    }

    return dummy->next;
}
Node* createList(const vector<int>& values){
    Node* dummy = new Node(0);
    Node* current = dummy;
    for(int data : values){
        current->next = new Node(data);
        current = current->next;
    }
    return dummy->next;
}

void printList(Node* head){
    while(head){
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main(){

    vector<Node*> lists = {
        createList({1, 4, 5}),
        createList({1, 3, 4}),
        createList({2, 6})
    };

    Node* mergedList = mergeKSortedLists(lists);
    cout << "Merged Sorted List: ";
    printList(mergedList);
}
