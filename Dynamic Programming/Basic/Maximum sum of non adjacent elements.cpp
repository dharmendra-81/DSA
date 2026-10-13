// Memoization
class Solution {
    int f(int ind, vector<int>& nums, vector<int>& dp){
        if(ind < 0) return 0;
        if(ind == 0) return nums[0];

        if(dp[ind] != -1) return dp[ind];

        int pick = nums[ind] + f(ind-2, nums, dp);
        int notPick = 0 + f(ind-1, nums, dp);

        return dp[ind] = max(pick, notPick);
    }

public:
    int nonAdjacent(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, -1);

        return f(n-1, nums, dp);
    }
};

// Tabulation
class Solution {
public:
    int nonAdjacent(vector<int>& nums) {
        int n = nums.size();

        vector<int> dp(n);
        dp[0] = nums[0];

        for(int i = 1; i < n; i++){
            int pick = nums[i];
            if(i > 1) pick += dp[i-2];
            int notPick = 0 + dp[i-1];
            
            dp[i] = max(pick, notPick);

        }

        return dp[n-1];
    }
};

// Space Optimization
class Solution {
public:
    int nonAdjacent(vector<int>& nums) {
        int n = nums.size();

        int prev2 = 0;
        int prev1 = nums[0];

        for(int i = 1; i < n; i++){
            int pick = nums[i] + prev2;
            int notPick = 0 + prev1;
            
            int cur = max(pick, notPick);
            prev2 = prev1;
            prev1 = cur;

        }

        return prev1;
    }
};