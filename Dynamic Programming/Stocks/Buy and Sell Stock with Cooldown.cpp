// Memoization
class Solution {
    int f(int ind, bool canBuy, vector<int>& prices, vector<vector<int>> &dp){
        if(ind >= prices.size()) return 0; 

        if(dp[ind][canBuy] != -1) return dp[ind][canBuy];

        int profit = 0;
        if(canBuy){
            int take = -prices[ind] + f(ind+1, false, prices, dp);
            int skip = 0 + f(ind+1, true, prices, dp);

            profit = max(take, skip);
        }
        else{
            int take = prices[ind] + f(ind+2, true, prices, dp);
            int skip = 0 + f(ind+1, false, prices, dp);

            profit = max(take, skip);
        }
        return dp[ind][canBuy] = profit;
    }
    
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();

        vector<vector<int>> dp(n, vector<int> (2, -1));
        return f(0, true, prices, dp);
    }
};

// Tabulation
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();

        vector<vector<int>> dp(n+2, vector<int> (2, 0));

        for(int ind = n-1; ind >= 0; ind--){
            for(int canBuy = 0; canBuy <= 1; canBuy++){
                int profit = 0;
                if(canBuy){
                    int take = -prices[ind] + dp[ind+1][0];
                    int skip = 0 + dp[ind+1][1];

                    profit = max(take, skip);
                }
                else{
                    int take = prices[ind] + dp[ind+2][1];
                    int skip = 0 + dp[ind+1][0];

                    profit = max(take, skip);
                }
                dp[ind][canBuy] = profit;
            }
        }
        return dp[0][1];
    }
};

// Space Optimization
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();

        vector<int> cur(2, 0);
        vector<int> front1(2, 0);
        vector<int> front2(2, 0);

        for(int ind = n-1; ind >= 0; ind--){
            // Buy
            int take = -prices[ind] + front1[0];
            int skip = 0 + front1[1];
            cur[1] = max(take, skip);

            // Not Buy
            take = prices[ind] + front2[1];
            skip = 0 + front1[0];
            cur[0] = max(take, skip);

            front2 = front1;
            front1 = cur;
        }
        return cur[1];
    }
};