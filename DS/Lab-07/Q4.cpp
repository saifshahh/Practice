#include <iostream>
#include <vector>
using namespace std;

int getMax(vector<int>& arr){
    int n = arr.size();
    int max = arr[0];
    for(int i = 1; i < n; i++)
        if(arr[i] > max) max = arr[i];
    return max;
};

void countSort(vector<int>& arr, int exp, bool flag){
    int n = arr.size();
    
    vector<int> output(n);
    vector<int> count(10, 0);
    
    for(int i = 0; i < n; i++) count[(arr[i] / exp) % 10] += 1;
    
    if(flag) for(int i = 1; i < 10; i++) count[i] += count[i-1];
    else for(int i = 8; i >= 0; i--) count[i] += count[i+1];
    
    for(int i = n-1; i >= 0 ; i--){
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10] -= 1;
    }
    for(int i = 0; i < n; i++) arr[i] = output[i];
};

void radixSort(vector<int>& arr, bool flag){
    int n = arr.size();
    int max = getMax(arr);
    
    for(int exp = 1; max / exp > 0; exp *= 10) countSort(arr, exp, flag);
};

int main() {
    vector<int> arr = {10, 7, 8, 9, 1, 5, 3};
    bool flag = true;
    radixSort(arr, flag);
    
    cout << "Ascending" << endl;
    for(int i = 0; i < arr.size(); i++) cout << arr[i] << " ";
    
    flag = false;
    radixSort(arr, flag);
    cout << "\nDescending" << endl; 
    for(int i = 0; i < arr.size(); i++) cout << arr[i] << " ";
}
