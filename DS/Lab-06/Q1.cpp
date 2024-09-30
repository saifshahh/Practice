#include<iostream>
using namespace std;

class Stack{
    public:
    int Top = -1;
    int* arr;
    int size;
    Stack(int size): size(size){
        arr = new int[size];
    }
};

bool isEmpty(Stack* s){
    if(s->Top == -1) return true;
    return false;
}

bool isFull(Stack* s){
    if(s->Top == s->size-1) return true;
    return false;
}

void push(Stack* s,int val){
    if(isFull(s)) cout<<"Stack is full";
    else{
        s->Top++;
        s->arr[s->Top] = val;
    }
}

int pop(Stack* s){
    if(isEmpty(s)){
        cout<<"Stack Underflow\n";
        return -1;
    }
    int a = s->arr[s->Top];
    s->Top--;
    return a;
}

void seperation(Stack*s, Stack* e, Stack* o){
    if(isEmpty(s)) cout<<"Stack is Empty";
    for(int i = 0; i < s->size; i++){
        if(s->arr[s->Top] % 2 == 0){
            push(e,s->arr[s->Top]);
            s->Top--;
        }
        else{
            push(o,s->arr[s->Top]);
            s->Top--;
        }
    }
    
}

int main(){
    Stack* s1 = new Stack(6);
    Stack* even = new Stack(s1->size);
    Stack* odd = new Stack(s1->size);
    push(s1,1);
    push(s1,2);
    push(s1,3);
    push(s1,4);
    push(s1,5);
    push(s1,6);

    seperation(s1,even,odd);

    cout<<"Even Stack: \n";
    for (int i = 0; i <= even->Top; i++){
        cout<<even->arr[i]<<" ";
    }
    cout<<endl;

    cout<<"Odd Stack: \n";
    for (int i = 0; i <= odd->Top; i++){
        cout<<odd->arr[i]<<" ";
    } 
}
