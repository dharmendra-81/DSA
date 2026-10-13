// Memoization (Top Down Approach)
class Solution {
    int f(int n, vector<int> &dp){
        if(n == 1) return 1;
        if(n == 2) return 2;

        if(dp[n] != -1) return dp[n];

        return dp[n] = f(n-1, dp) + f(n-2, dp);
    }

public:
    int climbStairs(int n) {
        vector<int> dp(n+1, -1);
        return f(n, dp);
    }
};

// Tabulation (Bottom Up Approach)
class Solution {
public:
    int climbStairs(int n) {
        vector<int> dp(n+1);
        dp[1] = 1;
        dp[2] = 2;
        for(int i = 3; i <= n; i++){
            dp[i] = dp[i-1] + dp[i-2];
        }
        return dp[n];
    }
};

// Space Optimization O(1)
class Solution {
public:
    int climbStairs(int n) {
        int prev2 = 1;
        int prev1 = 2;

        for(int i = 3; i <= n; i++){
            int curr = prev1 + prev2;
            prev2 = prev1;
            prev1 = curr;
        }
        return prev1;
    }
};