#include<iostream>
using namespace std;

int main(){
    int* jaggedArray[5];

    for(int i=0; i<5; i++) jaggedArray[i] = new int[5];
    

    for(int i=0; i<5; i++){
        for(int j=0; j<5; j++){
            int n;
            cout<<"Enter the element ["<<i+1<<"]"<<"["<<j+1<<"]: ";
            cin>>n;
            jaggedArray[i][j] = n;
        }
    }
    

    for (int i=0; i<5; i++){
        
        int* Arr = new int[10];
        for(int j=0; j<5; j++) Arr[j] = jaggedArray[i][j];
        
        delete jaggedArray[i];
        jaggedArray[i] = Arr;
    }

    for(int i=0; i<5; ++i){
        for(int j=0; j<10; ++j){
            if(j >= 5) jaggedArray[i][j] = 0;
            cout << jaggedArray[i][j] << " ";
        }
        cout<<endl;
    }  
}
