#include <iostream>
using namespace std;

class Stack{
    int i = 0;

    public:
    int size;
    int top;
    int* arr;

    Stack(int size){
        this->size = size;
        this->top = -1;
        this->arr = new int[size];
    }

    ~Stack(){
        delete[] arr;
    }
};

int isEmpty(Stack* ptr){
    if(ptr->top == -1) return 1; 
    else return 0; 
}

int isFull(Stack* ptr){
    if(ptr->top == ptr->size - 1) return 1;
    else return 0;
}

void push(Stack* ptr, int value){
    if(isFull(ptr)) cout<<"Stack Overflow\n";
    else{
        ptr->top++;
        ptr->arr[ptr->top] = value;
    }
}

int pop(Stack* ptr){
    if(isEmpty(ptr)){
        cout<<"Stack Underflow\n";
        return -1;
    }
    else{
        int value = ptr->arr[ptr->top];
        ptr->top--;
        return value;
    }
}

int peek(Stack* ptr, int i){
    if(ptr->top-i+1 < 0){
        cout<<"Not a valid position";
        return -1;
    }
    else return ptr->arr[ptr->top-i+1];
}

int stackTop(Stack* ptr){
    return ptr->arr[ptr->top];
}

int stackBottom(Stack* ptr){
    return ptr->arr[0];
}

int main() {
    Stack* s1 = new Stack(10);

    cout<<isEmpty(s1)<<endl;
    cout<<isFull(s1)<<endl;
    push(s1,30);
    push(s1,2);
    push(s1,31);
    push(s1,35);
    push(s1,38);
    push(s1,37);
    push(s1,24);
    push(s1,5);
    push(s1,6);
    push(s1,10);
    cout<<isFull(s1)<<endl;
    cout<<isEmpty(s1)<<endl;
    cout<<pop(s1)<<endl;
    
    for (int i = 1; i <= s1->top+1; i++){
        cout<<"The value at position "<<i<<" is: "<<peek(s1,i)<<endl;
    }
    
    cout<<stackTop(s1)<<endl;
    cout<<stackBottom(s1)<<endl;
    delete s1; 

}
