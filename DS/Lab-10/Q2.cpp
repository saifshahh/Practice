#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Heap{

    public:

    int arr[100];
    int size;

    Heap(){
        arr[0] = -1;
        size = 0;
    }

    void insertMinHeap(int val){ 
        size++;
        int index = size;
        arr[index] = val;

        while(index > 1){
            int parent = index / 2;

            if(arr[parent] > arr[index]){
                swap(arr[parent], arr[index]);
                index = parent;
            }
            else return;
        }
    }

    void deletion_minHeap(){
        if(size == 0){
            return;
        }
        if(size == 1){
            arr[size] = -1;
            --size;
            return;
        }
        arr[1] = arr[size];
        --size;

        int i = 1;
        while(i < size){
            int Li = 2 * i;
            int Ri = 2 * i + 1;

            if(Li < size && arr[i] > arr[Li]){
                swap(arr[i], arr[Li]);
                i = Li;
            }
            else if(Ri < size && arr[i] > arr[Ri]){
                swap(arr[i], arr[Ri]);
                i = Ri;
            }
            else return;
        }
    }

    int getMin(){
        if(size == 0) return -1;
        return arr[1];
    }

    void clear() { size = 0; }

    void print(){
        for (int i = 1; i <= size; i++){
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

void KLargestElements(int nums[], int k, int n){

    Heap h;
    for(int i = 0; i < k; i++) h.insertMinHeap(nums[i]);
    for(int i = k; i < n; i++){
        if(nums[i] > h.getMin()){                      
            h.deletion_minHeap();
            h.insertMinHeap(nums[i]);
        }
    }
    for (int i = 1; i <= h.size; i++) cout << h.arr[i] << " "; 
}

int main(){
    int nums[] = {7, 10, 4, 3, 20, 15};
    int k = 3;
    KLargestElements(nums, k, 6);
}
