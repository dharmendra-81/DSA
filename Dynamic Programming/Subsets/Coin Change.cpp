// Memoization
class Solution {
    int f(int ind, int target, vector<int>& arr, vector<vector<int>> &dp){
        if(ind == 0){
            return target % arr[ind] == 0 ? target / arr[ind] : 1e9;
        }

        if(dp[ind][target] != -1) return dp[ind][target];

        int skip = 0 + f(ind-1, target, arr, dp);
        int take = 1e9;
        if(target >= arr[ind]) take = 1 + f(ind, target-arr[ind], arr, dp);

        return dp[ind][target] = min(take, skip);
    }

public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount+1, -1));

        int ans = f(n-1, amount, coins, dp);

        return ans < 1e9 ? ans : -1;
    }
};

// Tabulation
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount+1, 0));

        for(int sum = 0; sum <= amount; sum++){
            dp[0][sum] = sum % coins[0] == 0 ? sum / coins[0] : 1e9;
        }

        for(int ind = 1; ind < n; ind++){
            for(int sum = 0; sum <= amount; sum++){
               int skip = 0 + dp[ind-1][sum];
               int take = 1e9;
               if(sum >= coins[ind]) take = 1 + dp[ind][sum-coins[ind]]; 

               dp[ind][sum] = min(take, skip);
            }
        }

        int ans = dp[n-1][amount];
        return ans < 1e9 ? ans : -1;
    }
};

// Space Optimization
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();

        vector<int> prev(amount+1, 0);
        vector<int> cur(amount+1, 0);

        for(int sum = 0; sum <= amount; sum++){
            prev[sum] = sum % coins[0] == 0 ? sum / coins[0] : 1e9;
        }

        for(int ind = 1; ind < n; ind++){
            for(int sum = 0; sum <= amount; sum++){
               int skip = 0 + prev[sum];
               int take = 1e9;
               if(sum >= coins[ind]) take = 1 + cur[sum-coins[ind]]; 

               cur[sum] = min(take, skip);
            }
            prev = cur;
        }

        int ans = prev[amount];
        return ans < 1e9 ? ans : -1;
    }
};
