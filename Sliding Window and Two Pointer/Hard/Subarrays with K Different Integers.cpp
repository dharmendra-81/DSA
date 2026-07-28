class Solution {
    int atMostKDistinct(vector<int>& nums, int k){
        if(k < 0) return 0;
        int l = 0, r = 0;
        int cnt = 0;
        unordered_map<int, int> mp;

        while(r < nums.size()){
            mp[nums[r]]++;
            while(mp.size() > k){
                mp[nums[l]]--;
                if(mp[nums[l]] == 0) mp.erase(nums[l]);
                l++;
            }
            cnt += r-l+1;
            r++;
        }
        return cnt;
    }

public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return atMostKDistinct(nums, k) - atMostKDistinct(nums, k-1);
    }
};

// Time : 2 x O(2n)