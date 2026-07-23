class Solution {
    int subarraySumLessEqualK(vector<int>& nums, int k){
        if(k < 0) return 0;
        int left = 0, right = 0;
        int sum = 0, cnt = 0;

        while(right < nums.size()){
            sum += nums[right];
            while(sum > k){
                sum -= nums[left];
                left++;
            }
            cnt += right - left + 1;
            right++;
        }
        return cnt;
    }

    public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return subarraySumLessEqualK(nums, goal) - subarraySumLessEqualK(nums, goal-1);
    }
};

// Time: O(4n)