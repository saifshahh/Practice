// Queue: Array Implementation
#include <iostream>
using namespace std;

class Queue{

    public:
    int *arr;
    int size;
    int front;
    int rear;

    Queue(int size) : size(size){
        front = -1;
        rear = -1;
        arr = new int[size];
    }
    
    ~Queue(){
        delete[] arr;
    }
};

bool isFull(Queue *q){
    // if (q->rear == q->size - 1) return true;
    // return false; 
    // We need to check for circular condition to fix the problem when we enqueue after dequeing
    return (q->rear+1) % (q->size) == q->front;
}

bool isEmpty(Queue *q){
    // if (q->rear == q->front) return true;
    // return false;
    return q->front == -1;
}

void EnQueue(Queue *q, int value){
    if(isFull(q)) cout << "Queue Overflow." << endl;
    else{
        // q->rear++;
        // q->arr[q->rear] = value;
        if(isEmpty(q)) q->front = 0;
        q->rear = (q->rear + 1) % q->size;
        q->arr[q->rear] = value;
    }
}

void DeQueue(Queue *q){
    if(isEmpty(q)) cout << "Queue Underflow." << endl;
    else{
        // q->front++;
        if(q->front == q->rear){ 
            q->front = -1;
            q->rear = -1;
        } 
        else q->front = (q->front + 1) % q->size;
    }
}

void traversal(Queue *q){
    int i = q->front;
    while (true) {
        cout<<q->arr[i]<<"->";
        if(i == q->rear) break;
        i = (i+1) % q->size; 
    }
    cout<<"End"<<endl;
}

int main(){
    Queue *q1 = new Queue(10);

    cout << "10 Passengers in Queue: \n";
    EnQueue(q1, 1);
    EnQueue(q1, 2);
    EnQueue(q1, 3);
    EnQueue(q1, 4);
    EnQueue(q1, 5);
    EnQueue(q1, 6);
    EnQueue(q1, 7);
    EnQueue(q1, 8);
    EnQueue(q1, 9);
    EnQueue(q1, 10);
    traversal(q1);

    cout << "5 Passengers left the Queue: \n";
    DeQueue(q1);
    DeQueue(q1);
    DeQueue(q1);
    DeQueue(q1);
    DeQueue(q1);
    traversal(q1);

    cout << "5 Passengers joined the Queue: \n";
    EnQueue(q1, 1);
    EnQueue(q1, 2);
    EnQueue(q1, 3);
    EnQueue(q1, 4);
    EnQueue(q1, 5);
    traversal(q1);
}



// Queue : Linked List Implementation
#include<iostream>
using namespace std;

class Queue{
public:
    int data;
    Queue* next;
};

Queue* front = NULL;
Queue* rear = NULL;

void traverse(Queue *q){
    while(q != nullptr){
        cout << q->data << "->";
        q = q->next;
    }
    cout<<"End"<<endl;
}

void EnQueue(int value){
    Queue* q = new Queue();
    if(q == nullptr) cout<<"Queue Overflow."<<endl;
    else{
        q->data = value;
        q->next = nullptr;
        if(rear == nullptr){
            front = q;
            rear = q;
        }
        else{
            rear->next = q;
            rear = q;
        }
    }
}

void DeQueue(){
    Queue* q = front;
    if(front == nullptr) cout<<"Queue Underflow."<<endl;
    else{
        front = front->next;
        delete(q);
    }
}

int main(){

    cout<<"10 Passengers entered the Queue: \n";
    EnQueue(1);
    EnQueue(2);
    EnQueue(3);
    EnQueue(4);
    EnQueue(5);
    EnQueue(6);
    EnQueue(7);
    EnQueue(8);
    EnQueue(9);
    EnQueue(10);
    traverse(front);

    cout<<"5 Passengers left the Queue: \n";
    DeQueue();
    DeQueue();
    DeQueue();
    DeQueue();
    DeQueue();
    traverse(front);

    cout<<"5 Passengers entered the Queue: \n";
    EnQueue(1);
    EnQueue(2);
    EnQueue(3);
    EnQueue(4);
    EnQueue(5);
    traverse(front);
}
