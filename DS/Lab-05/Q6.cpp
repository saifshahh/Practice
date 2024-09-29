#include<iostream>
using namespace std;

int Fibonacci(int num, int a=1, int b=1, int count=2){
    if(count == num) return a;
    int temp = a;
    a = a + b;
    b = temp;
    return Fibonacci(num,a,b,count+1);
}

int main(){
    cout<<Fibonacci(6);
}
