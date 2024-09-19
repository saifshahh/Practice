int binarySearch(int arr[], int size, int target){
    int low = 0;
    int high = size-1;
    
    while(low<=high && arr[low]<=target && arr[high]>=target){
        int mid = low + ((target - arr[low]) * (high - low)) / (arr[high] - arr[low]);
        if(arr[mid] == target) return mid;
        else if(arr[mid] < target) low = mid+1;
        else high = mid-1;
    }
    return -1;
}
