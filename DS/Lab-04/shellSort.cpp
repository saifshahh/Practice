#include <iostream>
using namespace std;

void shellSort(int arr[], int size){
    int gap = size/2;
    while(gap>0){
        for(int i=gap; i<size; i++){
            int key = arr[i];
            int j = i;
            while(j>=gap && arr[j-gap]>key){
                arr[j] = arr[j-gap];
                j-=gap;
            }
            arr[j] = key;
        }
        gap /= 2;
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
    shellSort(arr, size);
    display(arr,size);
}
