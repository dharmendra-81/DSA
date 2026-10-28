class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        int mx = 1;
        vector<int> dp(n, 1);
        vector<int> cnt(n, 1);
        
        for(int ind = 0; ind < n; ind++){
            for(int prev = 0; prev < ind; prev++){
                if(nums[prev] < nums[ind] && 1 + dp[prev] > dp[ind]){
                    dp[ind] = 1 + dp[prev];
                    cnt[ind] = cnt[prev];
                }
                else if(nums[prev] < nums[ind] && 1 + dp[prev] == dp[ind]){
                    cnt[ind] += cnt[prev];
                }
            }
            mx = max(mx, dp[ind]);
        }
        
        int ans = 0;
        for(int i = 0; i < n; i++){
            if(dp[i] == mx){
                ans += cnt[i];
            }
        }
        return ans;

    }
};