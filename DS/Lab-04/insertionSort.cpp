#include <iostream>
using namespace std;

void insertionSort(int arr[], int size){
    for(int i=0; i<size-1; i++){   
        int minIndex = i;
        for(int j=i+1; j<size; j++){
            if(arr[j] < arr[minIndex]){
                minIndex = j;
            }
        }
        if(minIndex != i){
            int temp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = temp;
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
