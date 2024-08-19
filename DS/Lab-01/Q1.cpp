#include <iostream>
using namespace std;

class BankAccount{
        int balance;
    public:
        BankAccount(){}
        BankAccount(BankAccount &account){
            balance = account.balance;
        }
        BankAccount(int balance):balance(balance){}
        void print(){
            cout<<balance<<endl;
        }
        void function(){
            balance-=200;
        }
        
};

int main(){
    BankAccount ac1;
    BankAccount ac2(1000);
    ac2.print();
    BankAccount ac3 = ac2;
    ac3.function();
    ac2.print();
    ac3.print();
    
}
