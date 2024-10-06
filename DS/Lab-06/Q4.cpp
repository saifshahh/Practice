#include <iostream>
#include <stack>
using namespace std;

class Queue {
private:
    stack<int> s1, s2;

public:
    void EnQueue(int x){
        s1.push(x);
    }

    int DeQueue(){
        if(s2.empty()){
            if(s1.empty()){
                cout << "Queue is empty!" << endl;
                exit(0);
            }
            while(!s1.empty()){
                s2.push(s1.top());
                s1.pop();
            }
        }
        int top = s2.top();
        s2.pop();
        return top;
    }

    bool isEmpty(){
        return s1.empty() && s2.empty();
    }

    int front(){
        if(s2.empty()){
            if(s1.empty()) {
                cout << "Queue is empty!" << endl;
                exit(0);
            }
            while(!s1.empty()){
                s2.push(s1.top());
                s1.pop();
            }
        }
        return s2.top();
    }
};

int main(){
    Queue q1;
    q1.EnQueue(1);
    q1.EnQueue(2);
    q1.EnQueue(3);

    cout << "Dequeued: " << q1.DeQueue() << endl;
    cout << "Dequeued: " << q1.DeQueue() << endl;
    q1.EnQueue(4);

    cout << "Front: " << q1.front() << endl;      
    cout << "Dequeued: " << q1.DeQueue() << endl; 
    cout << "Dequeued: " << q1.DeQueue() << endl; 
}
