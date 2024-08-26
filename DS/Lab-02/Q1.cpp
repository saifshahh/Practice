#include<iostream>
using namespace std;

int main(){
    int* jaggedArray[5];

    for (int i = 0; i < 5; i++)
    {
        jaggedArray[i] = new int[5];
    }

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            cout<<"Enter the element: ";
            int val;
            cin>>val;
            jaggedArray[i][j] = val;
        }
        
    }
    

    for (int i = 0; i < 5; i++)
    {
        int* newarr = new int[10];

        for (int j = 0; j < 5; j++)
        {
            newarr[j] = jaggedArray[i][j];
        }

        delete jaggedArray[i];

        jaggedArray[i] = newarr;
        
    }

    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 10; ++j) {
            if (j >= 5) {
                jaggedArray[i][j] = 0;
            }
            cout << jaggedArray[i][j] << " ";
        }
        cout << endl;
    }  
}
