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
};

bool isFull(Queue *q){
    if (q->rear == q->size - 1) return true;
    return false;
}

bool isEmpty(Queue *q){
    if (q->rear == q->front) return true;
    return false;
}

void EnQueue(Queue *q, int value){
    if(isFull(q)) cout << "Queue Overflow." << endl;
    else{
        q->rear++;
        q->arr[q->rear] = value;
    }
}

void DeQueue(Queue *q){
    if(isEmpty(q)) cout << "Queue Underflow." << endl;
    else{
        q->front++;
        q->size--;
    }
}

void traversal(Queue *q){
    for(int i = q->front+1; i <= q->rear; i++) cout << q->arr[i] << "->"; 
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
