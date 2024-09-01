#include <iostream>
using namespace std;

int main(){
    
    int array1[10][10];
    int array2[10][10];
    int result[10][10];
    int size;
    int element;

    cout<<"Enter the size of the arrays: ";
    cin>>size;

    cout<<"Input for array 1: "<<endl;
    for (int i=0; i<size; i++){
        for(int j=0; j<size; j++){
            cout<<"Enter the element ["<<i+1<<"]"<<"["<<j+1<<"]: ";
            cin >> element;
            array1[i][j] = element;
        }
    }

    cout<<"Input for array 2: "<<endl;
    for (int i=0; i<size; i++){
        for (int j=0; j<size; j++){
            cout<<"Enter the element ["<<i+1<<"]"<<"["<<j+1<<"]: ";
            cin >> element;
            array2[i][j] = element;
        }
    }

    for (int i=0; i<size; i++){
        for (int j=0; j<size; j++) result[i][j] = array1[i][j] * array2[i][j];
    }

    for (int i=0; i<size; i++){
        for(int j=0; j<size; j++) cout << result[i][j] << " ";
        cout<<endl;
    }
}
