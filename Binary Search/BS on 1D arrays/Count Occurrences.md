You are given a sorted array containing N integers and a number X, you have to find the occurrences of X in the given array.

---
```cpp
int countOccurrence(vector<int>& nums, int target) {
        int ans;
        int first=firstOccurence(nums, target);
        int last=lastOccurence(nums, target);
        if(first==-1 || last==-1){
            return 0;
        }
        ans=last-first+1;
        return ans;
    }
```


