**Input Format:** N = 4, arr[] = {1,2,2,3}, x = 2
**Result:** 1
**Explanation:** Index 1 is the smallest index such that arr[1] >= x.

---
```cpp
int lowerBound(vector<int> arr, int n, int x){
    int low=0, high=n-1;
    int ans=-1;
    while(low<=high){
        int mid=(low+high)/2;   
        if(arr[mid]>=x){
            ans=mid;
            high=mid-1;
        }
        else{
            low=mid+1;
        }
    }
    return ans;
}
```
