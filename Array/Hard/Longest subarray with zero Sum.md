###### Given an array containing both positive and negative integers, we have to find the length of the longest subarray with the sum of all elements equal to zero.
---
$$
O(N)
$$
```cpp
int maxLen(int A[], int n)
{
    // Map to store prefix sum and its earliest index
    unordered_map<int,int> mpp; 
    // Variable to store the maximum length found
    int maxi = 0;               
    // Variable to store the running prefix sum
    int sum = 0;               
    for(int i = 0; i < n; i++) {
        sum += A[i];
        // If sum is zero, subarray from 0 to i has sum zero
        if(sum == 0) {
            maxi = i + 1;
        }
        else {
            // If this sum has been seen before, subarray between previous index+1 and i has sum zero
            if(mpp.find(sum) != mpp.end()) {
                maxi = max(maxi, i - mpp[sum]);
            }
            else {
                // Store the index of the first occurrence of this sum
                mpp[sum] = i;
            }
        }
    }
    return maxi;
}
```