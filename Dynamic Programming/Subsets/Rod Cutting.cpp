// Memoization
class Solution {
    int f(int ind, int len, vector<int>& arr, vector<vector<int>> &dp){
        if(ind == 0) return len * arr[0];

        if(dp[ind][len] != -1) return dp[ind][len];

        int skip = f(ind-1, len, arr, dp);
        int take = -1e9;
        if((ind + 1) <= len) take = arr[ind] + f(ind, len - (ind + 1), arr, dp);

        return dp[ind][len] = max(take, skip);
    }
    
  public:
    int cutRod(vector<int> &price) {
        int n = price.size();

       vector<vector<int>> dp(n, vector<int>(n+1, -1));

       return f(n-1, n, price, dp);
    }
};

// Tabulation
class Solution {
  public:
    int cutRod(vector<int> &price) {
        int n = price.size(); 
        vector<vector<int>> dp(n, vector<int>(n+1, 0));
        
        for(int len = 0; len <= n; len++){
            dp[0][len] = len * price[0];
        }

        for(int ind = 1; ind < n; ind++){
            for(int len = 0; len <= n; len++){
               int skip = 0 + dp[ind-1][len];
               int take = -1e9;
               if((ind + 1) <= len) take = price[ind] + dp[ind][len - (ind + 1)];
               
               dp[ind][len] = max(take, skip);
            }
        }
        return dp[n-1][n];
    }
};

// Space Optimization
class Solution {
  public:
    int cutRod(vector<int> &price) {
        int n = price.size(); 
        vector<int> prev(n+1, 0);
        
        for(int len = 0; len <= n; len++){
            prev[len] = len * price[0];
        }

        for(int ind = 1; ind < n; ind++){
            for(int len = 0; len <= n; len++){
               int skip = 0 + prev[len];
               int take = -1e9;
               if((ind + 1) <= len) take = price[ind] + prev[len - (ind + 1)];
               
               prev[len] = max(take, skip);
            }
        }
        return prev[n];
    }
};