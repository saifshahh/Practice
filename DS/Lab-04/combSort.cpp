#include <iostream>
using namespace std;

void combSort(int arr[], int size){
    int gap = size;
    const float shrink_factor = 1.3;
    bool flag = true;
    while(gap>1 || flag){
        gap = static_cast<int>(gap/shrink_factor);
        if(gap<1) gap=1;
        flag = false;

        for(int i=0; i+gap<size; i++){
            if(arr[i]>arr[i+gap]){
                int temp = arr[i+gap];
                arr[i+gap] = arr[i];
                arr[i] = temp;
                flag = true;
            }
        }
    }
        
}

void display(int arr[], int size){
    for(int i=0; i<size; i++){
        cout<<" "<<arr[i];
    }
}

int main(){
    int size = 5;
    int arr[5] = {7,5,6,2,3};
    combSort(arr, size);
    display(arr,size);
}
