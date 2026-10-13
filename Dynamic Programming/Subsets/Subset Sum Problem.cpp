// Recursion
class Solution {
    bool f(int ind, int target, vector<int>& arr){
        if(target == 0) return true;
        if(ind == 0) return arr[ind] == target;
        
        bool skip = f(ind-1, target, arr);
        bool take = false;
        if(target >= arr[ind]) take = f(ind-1, target-arr[ind], arr);
        
        return take | skip;
    }
    
  public:
    bool isSubsetSum(vector<int>& arr, int sum) {
        int n = arr.size();
        
        return f(n-1, sum, arr);
    }
};

// Memoization
class Solution {
    bool f(int ind, int target, vector<int>& arr, vector<vector<int>> &dp){
        if(target == 0) return true;
        if(ind == 0) return arr[ind] == target;
        
        if(dp[ind][target] != -1) return dp[ind][target];
        
        bool skip = f(ind-1, target, arr, dp);
        bool take = false;
        if(target >= arr[ind]) take = f(ind-1, target-arr[ind], arr, dp);
        
        return dp[ind][target] = take || skip;
    }
    
  public:
    bool isSubsetSum(vector<int>& arr, int sum) {
        int n = arr.size();
        
        vector<vector<int>> dp(n, vector<int>(sum+1, -1));
        
        return f(n-1, sum, arr, dp);
    }
};

// Tabulation
class Solution {
  public:
    bool isSubsetSum(vector<int>& arr, int sum) {
        int n = arr.size();
        
        vector<vector<bool>> dp(n, vector<bool>(sum+1, false));
        
        for(int ind = 0; ind < n; ind++) dp[ind][0] = true;
        if(arr[0] <= sum) dp[0][arr[0]] = true;
        
         for(int ind = 1; ind < n; ind++){
             for(int target = 1; target <= sum; target++){
                bool skip = dp[ind-1][target];
                bool take = false;
                if(target >= arr[ind]) take = dp[ind-1][target-arr[ind]]; 
                
                dp[ind][target] = take || skip;
             }
         }
        
        return dp[n-1][sum];
    }
};

// Space Optimization
class Solution {
  public:
    bool isSubsetSum(vector<int>& arr, int sum) {
        int n = arr.size();
        
        vector<bool> prev(sum+1, false);
        vector<bool> cur(sum+1, false);
        
        prev[0] = cur[0] = true;
        if(arr[0] <= sum) prev[arr[0]] = true;
        
         for(int ind = 1; ind < n; ind++){
             for(int target = 1; target <= sum; target++){
                bool skip = prev[target];
                bool take = false;
                if(target >= arr[ind]) take = prev[target-arr[ind]]; 
                
                cur[target] = take || skip;
             }
             prev = cur;
         }
        
        return prev[sum];
    }
};