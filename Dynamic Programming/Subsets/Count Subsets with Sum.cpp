// Memoization
class Solution {
    int f(int ind, int target, vector<int>& arr, vector<vector<int>> &dp){
        if(ind == 0){
            if(target == 0 && arr[0] == 0) return 2;
            if(target == 0 || target == arr[0]) return 1;
            return 0;
        }

        if(dp[ind][target] != -1) return dp[ind][target];

        int skip = f(ind-1, target, arr, dp);
        int take = 0;
        if(target >= arr[ind]) take = f(ind-1, target-arr[ind], arr, dp);

        return dp[ind][target] = take + skip;
    }
    
  public:
    int perfectSum(vector<int>& arr, int target) {
        int n = arr.size();

        vector<vector<int>> dp(n, vector<int>(target+1, -1));

        return f(n-1, target, arr, dp);
    }
};

// Tabulation
class Solution {
  public:
    int perfectSum(vector<int>& arr, int target) {
        int n = arr.size();

        vector<vector<int>> dp(n, vector<int>(target+1, 0));

        if(arr[0] == 0) dp[0][0] = 2;
        else{
            dp[0][0] = 1;
            if(arr[0] <= target) dp[0][arr[0]] = 1;
        }

        for(int ind = 1; ind < n; ind++){
            for(int sum = 0; sum <= target; sum++){
               int skip = dp[ind-1][sum];
               int take = 0;
               if(sum >= arr[ind]) take = dp[ind-1][sum-arr[ind]]; 

               dp[ind][sum] = take + skip;
            }
        }

       return dp[n-1][target];
    }
};

// Space Optimization
class Solution {
  public:
    int perfectSum(vector<int>& arr, int target) {
        int n = arr.size();

        vector<int> dp(target + 1, 0);

        if(arr[0] == 0) dp[0] = 2;
        else{
            dp[0] = 1;
            if(arr[0] <= target) dp[arr[0]] = 1;
        }

        for(int ind = 1; ind < n; ind++){
            for(int sum = target; sum >= 0; sum--){
               int skip = dp[sum];
               int take = 0;
               if(sum >= arr[ind]) take = dp[sum-arr[ind]]; 

               dp[sum] = take + skip;
            }
        }

       return dp[target];
    }
};