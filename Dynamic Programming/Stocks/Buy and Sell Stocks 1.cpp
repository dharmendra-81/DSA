// Previous Solution
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice = INT_MAX;
        int maxProfit = 0;
        for (int price : prices) {
            if (price < minPrice) {
                minPrice = price; // Update the minimum price
            } else {
                maxProfit = max(maxProfit, price - minPrice); // Calculate profit
            }
        }
        return maxProfit; 
    }
};

// DP solution
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mn = prices[0];
        int profit = 0;

        for(int i = 1; i < prices.size(); i++){
            int cost = prices[i] - mn;
            profit = max(profit, cost);
            mn = min(mn, prices[i]);
        }
        return profit;
    }
};

