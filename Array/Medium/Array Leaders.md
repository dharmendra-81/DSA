alias: Superior elements
You are given an array **`arr`** of positive integers. Your task is to find all the leaders in the array. An element is considered a leader if it is greater than or equal to all elements to its right. The rightmost element is always a leader.
**Input:** arr = [16, 17, 4, 3, 5, 2]
**Output:** [17, 5, 2]

---
```cpp
class Solution {
  public:
    vector<int> leaders(vector<int>& arr) {
        vector<int> ans;
        int max = INT_MIN;
        for (int i = arr.size() - 1; i >= 0; i--) {
            if (arr[i] >= max) {
                ans.push_back(arr[i]);
                max = arr[i];
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
```
