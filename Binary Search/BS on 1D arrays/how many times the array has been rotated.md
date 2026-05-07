 Given an integer array **arr** of size **N**, sorted in ascending order (**with distinct values**). Now the array is rotated between 1 to N times which is unknown. Find how many times the array has been rotated.

---
 
 **Observation**:
 *The number of rotations in an array is equal to the index(0-based index) of its minimum element.*
```cpp
int findKRotation(vector<int> &arr) {
    int low=0, high=arr.size()-1;
    int n=arr.size();
    while(low<=high){
        if(arr[low]<=arr[high]){ // already sorted
            return low;
        }
        int mid=(low+high)/2;
        int next=(mid+1)%n;
        int prev=(mid+n-1)%n;
        if(arr[mid]<=arr[next] && arr[mid]<=arr[prev]){ //mid is the minimum
            return mid;
        }
        else if(arr[mid]>=arr[low]){ // left part is sorted
            low=mid+1;
        }
        else{ // right part is sorted
            high=mid-1;
        }
    }
    return -1;
}
```