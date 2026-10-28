class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();

        int next0, next1, cur0, cur1;
        next0 = next1 = 0;

        for(int ind = n-1; ind >= 0; ind--){
            // Buy
            int take = -prices[ind] + next0;
            int skip = 0 + next1;
            cur1 = max(take, skip);

            // Sell
            take = prices[ind] - fee + next1;
            skip = 0 + next0;
            cur0 = max(take, skip);

            next1 = cur1;
            next0 = cur0;
        }
        return next1;
    }
};