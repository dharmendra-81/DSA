// sum = s1 + s2 , where s1 - s2 = diff

// Memoization
class Solution {
    vector<vector<bool>> isSubsetSum(vector<int>& arr, int sum) {
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

        return dp;
    }
    
  public:
    int minDifference(vector<int>& nums) {
        int n = nums.size();
        int sum = accumulate(nums.begin(), nums.end(), 0);
        
        vector<vector<bool>> dp = isSubsetSum(nums, sum);
        
        int ans = 1e9;
        for(int s1 = 0; s1 <= sum/2; s1++){
            if(dp[n-1][s1]){
                int s2 = sum - s1;
                ans = min(ans, abs(s2 - s1));
            }
        }
        return ans;
    }
};

// Space Optimization
class Solution {
    vector<bool> isSubsetSum(vector<int>& arr, int sum) {
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

        return prev;
    }
    
  public:
    int minDifference(vector<int>& nums) {
        int n = nums.size();
        int sum = accumulate(nums.begin(), nums.end(), 0);
        
        vector<bool> dp = isSubsetSum(nums, sum);
        
        int ans = 1e9;
        for(int s1 = 0; s1 <= sum/2; s1++){
            if(dp[s1]){
                int s2 = sum - s1;
                ans = min(ans, abs(s2 - s1));
            }
        }
        return ans;
    }
};
