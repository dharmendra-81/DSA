// Memoization
class Solution {
    int f(int ind, bool canBuy, int cap, vector<int>& prices, vector<vector<vector<int>>> &dp){
        if(cap == 0) return 0;
        if(ind == prices.size()) return 0; 

        if(dp[ind][canBuy][cap] != -1) return dp[ind][canBuy][cap];

        int profit = 0;
        if(canBuy){
            int take = -prices[ind] + f(ind+1, false, cap, prices, dp);
            int skip = 0 + f(ind+1, true, cap, prices, dp);

            profit = max(take, skip);
        }
        else{
            int take = prices[ind] + f(ind+1, true, cap-1, prices, dp);
            int skip = 0 + f(ind+1, false, cap, prices, dp);

            profit = max(take, skip);
        }
        return dp[ind][canBuy][cap] = profit;
    }

public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int k = 2;
        vector<vector<vector<int>>> dp(n, vector<vector<int>> (2, vector<int>(k+1, -1)));

        return f(0, true, k, prices, dp);
    }
};

// Tabulation
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int k = 2;
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>> (2, vector<int>(k+1, 0)));

        for(int ind = n-1; ind >= 0; ind--){
            for(int canBuy = 0; canBuy <= 1; canBuy++){
                for(int cap = 1; cap <= k; cap++){
                    if(canBuy){
                        int take = -prices[ind] + dp[ind+1][0][cap];
                        int skip = 0 + dp[ind+1][1][cap];

                        dp[ind][canBuy][cap] = max(take, skip);
                    }
                    else{
                        int take = prices[ind] + dp[ind+1][1][cap-1];
                        int skip = 0 + dp[ind+1][0][cap];

                        dp[ind][canBuy][cap] = max(take, skip);
                    }
                }
            }
        }
        return dp[0][1][k];
    }
};

// Space Optimization
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int k = 2;
        vector<vector<int>> cur(2, vector<int>(k+1, 0));
        vector<vector<int>> next(2, vector<int>(k+1, 0));

        for(int ind = n-1; ind >= 0; ind--){
            for(int canBuy = 0; canBuy <= 1; canBuy++){
                for(int cap = 1; cap <= k; cap++){
                    if(canBuy){
                        int take = -prices[ind] + next[0][cap];
                        int skip = 0 + next[1][cap];

                        cur[canBuy][cap] = max(take, skip);
                    }
                    else{
                        int take = prices[ind] + next[1][cap-1];
                        int skip = 0 + next[0][cap];

                        cur[canBuy][cap] = max(take, skip);
                    }
                }
                next = cur;
            }
        }
        return next[1][k];
    }
};
