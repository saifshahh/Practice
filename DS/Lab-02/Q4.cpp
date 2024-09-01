#include <iostream>
using namespace std;

int main() {
    
    int n = 4;
    int courses[n] = {3, 4, 2, 1};
    
    float* GPA[n];
    for(int i=0; i<n; i++) GPA[i] = new float[courses[i]];

    for(int i=0; i<n; i++){
        cout<<"Enter GPA for "<<courses[i] <<" core courses in Department "<<i+1<<":"<<endl;
        for(int j=0; j<courses[i]; j++){
            cout<<"Course "<<j+1<<": ";
            cin>>GPA[i][j];
        }
    }

    cout<<"\nDisplaying GPAs for each department:"<<endl;
    for (int i=0; i<n; i++){
        cout<<"Department "<<i+1<<" ("<<courses[i]<<" courses): ";
        for(int j=0; j<courses[i]; j++) cout<<GPA[i][j]<<" ";
        cout << endl;
    }

    for (int i=0; i<n; i++) delete[] GPA[i];
}
