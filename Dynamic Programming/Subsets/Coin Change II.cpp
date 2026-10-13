// Memoization
class Solution {
        int f(int ind, int target, vector<int>& arr, vector<vector<int>> &dp){
        if(ind == 0){
            return target % arr[ind] == 0;
        }

        if(dp[ind][target] != -1) return dp[ind][target];

        int skip = f(ind-1, target, arr, dp);
        int take = 0;
        if(target >= arr[ind]) take = f(ind, target-arr[ind], arr, dp);

        return dp[ind][target] = take + skip;
    }

public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount+1, -1));

        return f(n-1, amount, coins, dp);
    }
};

// Tabulation
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount+1, 0));

        for(int sum = 0; sum <= amount; sum++){
            dp[0][sum] = sum % coins[0] == 0;
        }

        for(int ind = 1; ind < n; ind++){
            for(int sum = 0; sum <= amount; sum++){
               int skip = dp[ind-1][sum];
               int take = 0;
               if(sum >= coins[ind]) take = dp[ind][sum-coins[ind]]; 

               dp[ind][sum] = take + skip;
            }
        }

        return dp[n-1][amount];
    }
};

// Space Optimization
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        long long MOD = 1e10+7;
        int n = coins.size();
        vector<long long> prev(amount+1, 0);
        vector<long long> cur(amount+1, 0);

        for(int sum = 0; sum <= amount; sum++){
            prev[sum] = sum % coins[0] == 0;
        }

        for(int ind = 1; ind < n; ind++){
            for(int sum = 0; sum <= amount; sum++){
               long long skip = prev[sum];
               long long take = 0;
               if(sum >= coins[ind]) take = cur[sum-coins[ind]]; 

               cur[sum] = (take + skip) % MOD;
            }
            prev = cur;
        }

        return (int)prev[amount];
    }
};