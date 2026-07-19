/*
Intuition:
The problem is to find the maximum value in each sliding window of size k in an array.
To solve this problem efficiently, we can use a deque  to keep track of the indices of the elements in the current window. 
The deque will store indices in such a way that the maximum element's index is always at the front of the deque. 
As we slide the window, we will remove indices that are out of the current window 
and also remove indices of elements that are smaller than the current element since they will not be needed for future windows.
*/

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        deque<int> dq;

        for(int i = 0; i < nums.size(); i++){
            // Remove indices that are out of the current window
            if(!dq.empty() && dq.front() <= i-k){
                dq.pop_front();
            }

            // Remove indices of elements that are smaller than the current element
            while(!dq.empty() && nums[dq.back()] <= nums[i]){
                dq.pop_back();
            }

            dq.push_back(i);

            if(i >= k-1) ans.push_back(nums[dq.front()]);
        }

        return ans;
    }
};

// Time : O(2n) & Space : O(k)