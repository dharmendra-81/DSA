// Memoization
class Solution {
    int f(int ind, int capacity, vector<int> &val, vector<int> &wt,  vector<vector<int>> &dp){
        if(ind == 0){
            return (capacity / wt[0]) * val[0];
        }

        if(dp[ind][capacity] != -1) return dp[ind][capacity];

        int skip = 0 + f(ind-1, capacity, val, wt, dp);
        int take = 0;
        if(capacity >= wt[ind]) take = val[ind] + f(ind, capacity-wt[ind], val, wt, dp);

        return dp[ind][capacity] = max(take, skip);
    }
    
  public:
    int knapSack(vector<int>& val, vector<int>& wt, int capacity) {
        int n = val.size();

        vector<vector<int>> dp(n, vector<int>(capacity+1, -1));

        return f(n-1, capacity, val, wt, dp);
    }
};

// Tabulation
class Solution {
  public:
    int knapSack(vector<int>& val, vector<int>& wt, int capacity)  {
        int n = val.size();

        vector<vector<int>> dp(n, vector<int>(capacity+1, 0));

        for(int w = wt[0]; w <= capacity; w++){
            dp[0][w] = (w / wt[0]) * val[0];
        }

        for(int ind = 1; ind < n; ind++){
            for(int w = 1; w <= capacity; w++){
                int skip = 0 + dp[ind-1][w];
                int take = 0;
                if(w >= wt[ind]) take = val[ind] + dp[ind][w-wt[ind]];

                dp[ind][w] = max(take, skip);
            }
        }

        return dp[n-1][capacity];
    }
};

// Space Optimization
class Solution {
  public:
    int knapSack(vector<int>& val, vector<int>& wt, int capacity)  {
        int n = val.size();

        vector<int> prev(capacity+1, 0);

        for(int w = wt[0]; w <= capacity; w++){
            prev[w] = (w / wt[0]) * val[0];
        }

        for(int ind = 1; ind < n; ind++){
            for(int w = wt[ind]; w <= capacity; w++) {
                int skip = 0 + prev[w];
                int take = val[ind] + prev[w-wt[ind]];

                prev[w] = max(take, skip);
            }
        }

        return prev[capacity];
    }
};

