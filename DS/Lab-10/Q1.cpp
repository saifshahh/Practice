#include <iostream>
using namespace std;

class Heap{

    public:

    int arr[100];
    int size;

    Heap(){
        arr[0] = -1;
        size = 0;
    }

    void insertMax(int value){
        size++;
        int index = size;
        arr[index] = value;

        while(index > 1){
            int parent = index / 2;

            if(arr[parent] < arr[index]){
                swap(arr[parent], arr[index]);
                index = parent;
            } 
            else return;
        }
    }

    void deletion_Max(){
        if(size == 0) return;

        arr[1] = arr[size];
        size--;

        int index = 1;
        while(index <= size){
            int left = 2 * index;
            int right = 2 * index + 1;
            int largest = index;

            if(left <= size && arr[left] > arr[largest]) largest = left;      
            if(right <= size && arr[right] > arr[largest]) largest = right;
            if(largest != index){
                swap(arr[index], arr[largest]);
                index = largest;
            } 
            else break;
        }
    }

    int getMax(){
        if(size == 0) return -1;
        return arr[1];
    }
    void clear() { size = 0; }
};

void SlidingWindow(int arr[], int k, int n){
    Heap h;
    int result[n - k + 1];

    for(int i = 0; i <= n-k; i++){
        h.clear();
        for(int j = i; j < i + k; j++) h.insertMax(arr[j]);
        result[i] = h.getMax();
    }
    for(int i = 0; i < n - k + 1; i++) cout << result[i] << " ";
    cout << endl;
}

int main(){
    int nums[] = {1, 3, -1, -3, 5, 3, 6, 7};
    int k = 3;
    SlidingWindow(nums, k, 8);
}
