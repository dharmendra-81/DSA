// Memoization
class Solution {
    int f(int ind, int transaction, vector<int>& prices, vector<vector<int>> &dp){
        if(ind == prices.size() || transaction == 0) return 0; 

        if(dp[ind][transaction] != -1) return dp[ind][transaction];

        if(transaction % 2 == 0){
            int take = -prices[ind] + f(ind+1, transaction-1, prices, dp);
            int skip = 0 + f(ind+1, transaction, prices, dp);

            return dp[ind][transaction] = max(take, skip);
        }

        int take = prices[ind] + f(ind+1, transaction-1, prices, dp);
        int skip = 0 + f(ind+1, transaction, prices, dp);

        return dp[ind][transaction] = max(take, skip);
    }

public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();

        vector<vector<int>> dp(n, vector<int> (k*2 + 1, -1));
        return f(0, 2 * k, prices, dp);
    }
};

// Tabulation
class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();

        vector<vector<int>> dp(n+1, vector<int> (2*k + 1, 0));
        for(int ind = n-1; ind >= 0; ind--){
            for(int transaction = 1; transaction < 2*k + 1; transaction++){
                if(transaction % 2 == 0){
                    int take = -prices[ind] + dp[ind+1][transaction-1];
                    int skip = 0 + dp[ind+1][transaction];

                    dp[ind][transaction] = max(take, skip);
                }
                else{
                    int take = prices[ind] + dp[ind+1][transaction-1];
                    int skip = 0 + dp[ind+1][transaction];

                    dp[ind][transaction] = max(take, skip);
                }
            }
        }
        return dp[0][2*k];
    }
};