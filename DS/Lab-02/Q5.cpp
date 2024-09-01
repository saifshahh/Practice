#include <iostream>
using namespace std;

int main(){
    
    int size, row;
    string name;
    cout<<"Enter the number of rows: "; cin>>size;
    string* seats[size];
    int count[size];

    for(int i=0; i<size; i++){
        cout<<"Enter the number of seats in row "<<i+1<<": ";
        cin>>row;
        count[i]=row;
        seats[i]=new string[row];

        for(int j=0; j<row; j++){
            cout<<"Enter the name of person on seat "<<j+1<<": ";
            cin>>name;
            seats[i][j] = name;
        }
    }

    cout<<"\nSeating Arrangement:"<<endl;
    for(int i=0; i<size; i++){
        cout<<"Row "<<i+1<<": ";
        for(int j=0; j<count[i]; j++) cout<<seats[i][j]<<" ";
        cout << endl;
    }

    for(int i=0; i<size; i++) delete[] seats[i];
}
