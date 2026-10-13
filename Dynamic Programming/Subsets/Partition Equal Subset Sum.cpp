// sum = s1 + s2 , where s1 = s2
// sum = 2 * s1 => s1 = sum / 2
// So the problem reduces to finding a subset with sum = sum / 2

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

    bool isSubsetSum(vector<int>& arr, int sum) {
        int n = arr.size();
        
        vector<vector<int>> dp(n, vector<int>(sum+1, -1));
        
        return f(n-1, sum, arr, dp);
    }

public:
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if(sum & 1) return false;
        return isSubsetSum(nums, sum/2);
    }
};

// Space Optimization
class Solution {
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

public:
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);

        if(sum & 1) return false;

        return isSubsetSum(nums, sum/2);
    }
};