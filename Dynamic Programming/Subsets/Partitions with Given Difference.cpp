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
    
    int findWays(vector<int>& arr, int target) {
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(target+1, -1));
        return f(n-1, target, arr, dp);
    }
    
  public:
    int countPartitions(vector<int>& nums, int diff) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        
        if(sum-diff < 0 || (sum-diff)&1) return 0;
        
        return findWays(nums, (sum-diff)/2);
    }
};

// Tabulation
class Solution {
    int findWays(vector<int>& arr, int target) {
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
    
  public:
    int countPartitions(vector<int>& nums, int diff) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        
        if(sum-diff < 0 || (sum-diff)&1) return 0;
        
        return findWays(nums, (sum-diff)/2);
    }
};

// Space Optimized
class Solution {
    int findWays(vector<int>& arr, int target) {
        int n = arr.size();

        vector<int> prev(target+1, 0);

        if(arr[0] == 0) prev[0] = 2;
        else{
            prev[0] = 1;
            if(arr[0] <= target) prev[arr[0]] = 1;
        }

        for(int ind = 1; ind < n; ind++){
            vector<int> cur(target+1, 0);
            for(int sum = 0; sum <= target; sum++){
               int skip = prev[sum];
               int take = 0;
               if(sum >= arr[ind]) take = prev[sum-arr[ind]]; 

               cur[sum] = take + skip;
            }
            prev = cur;
        }

       return prev[target];       
    }
    
  public:
    int countPartitions(vector<int>& nums, int diff) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        
        if(sum-diff < 0 || (sum-diff)&1) return 0;
        
        return findWays(nums, (sum-diff)/2);
    }
};