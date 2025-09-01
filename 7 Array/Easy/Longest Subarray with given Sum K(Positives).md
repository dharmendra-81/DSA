Given an array and a sum k, we need to print the length of the longest subarray that sums to k.
Example 1:
Input Format: N = 3, k = 5, array[] = {2,3,5}
Result: 2
Explanation: The longest subarray with sum 5 is {2, 3}. And its length is 2.

Example 2:
Input Format: N = 5, k = 10, array[] = {2,3,5,1,9}
Result: 3
Explanation: The longest subarray with sum 10 is {2, 3, 5}. And its length is 3.

---
```cpp
class TakeuForward {
public:
    int getLongestSubarray(vector<int>& a, long long k)  {
       int left=0, right=0;
       long long sum = a[0];
       int maxLen=0;
       while(right < a.size()) {
        while(sum > k && left<= right){
            sum -= a[left];
            left++;
        }
        if(sum == k){
            maxLen=max(maxLen, right-left+1);
        }
        right++;
        if(right < a.size() ){
            sum += a[right];
        }
    }
    return maxLen;
    }
};
```
