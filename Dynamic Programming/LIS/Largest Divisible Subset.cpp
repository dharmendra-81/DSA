class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        int mx = 1, last = 0;
        
        vector<int> dp(n, 1);
        vector<int> hash(n);
        vector<int> lds;

        sort(nums.begin(), nums.end());
        
        for(int ind = 0; ind < n; ind++){
            hash[ind] = ind;
            for(int prev = 0; prev < ind; prev++){
                if(nums[ind] % nums[prev] == 0 && 1 + dp[prev] > dp[ind]){
                    dp[ind] = 1 + dp[prev];
                    hash[ind] = prev;
                }
            }
            
            if(dp[ind] > mx){
                mx = dp[ind];
                last = ind;
            }
        }
        
        lds.push_back(nums[last]);
        while(hash[last] != last){
            last = hash[last];
            lds.push_back(nums[last]);
        }
        reverse(lds.begin(), lds.end());

        return lds;
    }
};