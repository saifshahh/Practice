#include <iostream>
using namespace std;

void insertionSort(int arr[], int size){
    for(int i=1; i<size; i++){
        int key = i;
        for(int j=i-1; j>=0; j--){
            if(arr[j] > arr[key]){
                int temp = arr[key];
                arr[key] = arr[j];
                arr[j] = temp;
                key--;
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
    insertionSort(arr, size);
    display(arr,size);
}
