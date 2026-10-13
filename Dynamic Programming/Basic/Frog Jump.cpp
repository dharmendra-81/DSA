// Memoization
class Solution {
    int solve(int ind, vector<int> &dp, vector<int>& h){
        if(ind == 0) return 0;
        
        if(dp[ind] != -1) return dp[ind];
        
        int c1 = solve(ind-1, dp, h) + abs(h[ind] - h[ind-1]);
        int c2 = INT_MAX;
        if(ind > 1)
            c2 = solve(ind-2, dp, h) + abs(h[ind] - h[ind-2]);
            
        return dp[ind] = min(c1, c2);
    }

  public:
    int minCost(vector<int>& height) {
        int n = height.size();
        vector<int> dp(n+1, -1);
        
        return solve(n-1, dp, height);
    }
};

// Tabulation
class Solution {
  public:
    int minCost(vector<int>& height) {
        int n = height.size();
        
        vector<int> dp(n, 0);
        dp[0] = 0;
        
        for(int i = 1; i < n; i++){
            int step1 = dp[i-1] + abs(height[i] - height[i-1]);
            int step2 = INT_MAX;
            if(i > 1)
                step2 = dp[i-2] + abs(height[i] - height[i-2]);
            
            dp[i] = min(step1, step2);
        }
        return dp[n-1];
    }
};

// Space Optimization
class Solution {
  public:
    int minCost(vector<int>& height) {
        int n = height.size();
        
        int prev1 = 0;
        int prev2 = 0;
        
        for(int i = 1; i < n; i++){
            int step1 = prev1 + abs(height[i] - height[i-1]);
            int step2 = INT_MAX;
            if(i > 1)
                step2 = prev2 + abs(height[i] - height[i-2]);
            
            int cur = min(step1, step2);
            prev2 = prev1;
            prev1 = cur;
        }
        return prev1;
    }
};