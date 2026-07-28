class Solution {
    int countAtMost(vector<int>& nums, int k){
        if(k < 0) return 0;
        int left = 0, right = 0;
        int cnt = 0;

        while(right < nums.size()){
            k -= nums[right] % 2;
            while(k < 0){
                k += nums[left] % 2;
                left++;
            }
            cnt += right - left + 1;
            right++;
        }
        return cnt;
    }

public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        return countAtMost(nums, k) - countAtMost(nums, k-1);
    }
};