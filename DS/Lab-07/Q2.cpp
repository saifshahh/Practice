#include <iostream>
#include <vector>
using namespace std;

class Runners{
    public:
    string name;
    int end_time;
    
    Runners(string name = "", int end_time = 0) : name(name), end_time(end_time) {}
};

void merge(Runners arr[], int left, int mid, int right){
    int n1 = mid - left + 1;
    int n2 = right - mid;
    
    Runners* Left = new Runners[n1];
    Runners* Right = new Runners[n2];
    
    for(int i = 0; i < n1; i++) Left[i] = arr[left+i];
    for(int j = 0; j < n2; j++) Right[j] = arr[mid + 1 + j];
    
    int i = 0;
    int j = 0;
    int k = left;
    
    while(i < n1 && j < n2){
        if(Left[i].end_time <= Right[j].end_time) arr[k++] = Left[i++]; 
        else arr[k++] = Right[j++];
    }
    
    while(i < n1) arr[k++] = Left[i++];  
    while(j < n2) arr[k++] = Right[j++];
        
    delete[] Left;
    delete[] Right;
}

void display(Runners arr[], int n){
    for(int i = 0; i < n; i++){
        cout << "Name: " << arr[i].name << " finish Time: " << arr[i].end_time << endl;
    }
}


void mergeSort(Runners arr[], int left, int right){
    if(left < right){
        int mid = (right - left)/2 + left;
        
        mergeSort(arr, left, mid);
        mergeSort(arr, mid+1, right);
        
        merge(arr, left, mid, right);
    }
}

int main(){
    Runners arr[10] = {
        Runners("Zara", 1),
        Runners("Sara", 5),
        Runners("Wara", 6),
        Runners("Haya", 8),
        Runners("Ali", 9),
        Runners("Minha", 7),
        Runners("Saad", 10),
        Runners("Maya", 12),
        Runners("Sana", 2),
        Runners("Hira", 4)
    };
    
    mergeSort(arr, 0, 9);
    
    display(arr, 10);
}
