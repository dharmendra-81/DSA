// Memoization
class Solution {
    int f(int i, int j, vector<int> &arr, vector<vector<int>> &dp){
        if(i > j) return 0;

        if(dp[i][j] != -1) return dp[i][j];

        int mn = 1e9;
        for(int ind = i; ind <= j; ind++){
            int cost = arr[j+1] - arr[i-1]
                + f(i, ind-1, arr, dp) + f(ind+1, j, arr, dp);
            mn = min(mn, cost);
        }
        return dp[i][j] = mn;
    }

public:
    int minCost(int n, vector<int>& cuts) {
        int c = cuts.size();
        vector<vector<int>> dp(c+1, vector<int>(c+1, -1));

        cuts.push_back(n);
        cuts.insert(cuts.begin(), 0);
        sort(cuts.begin(), cuts.end());

        return f(1, c, cuts, dp);
    }
};

// Tabulation
class Solution {
public:
    int minCost(int n, vector<int>& cuts) {
        int c = cuts.size();
        vector<vector<int>> dp(c+2, vector<int>(c+2, 0));

        cuts.push_back(n);
        cuts.insert(cuts.begin(), 0);
        sort(cuts.begin(), cuts.end());

        for(int i = c; i >= 1; i--){
            for(int j = 1; j <= c; j++){
                if(i > j) continue;
                int mn = 1e9;
                for(int ind = i; ind <= j; ind++){
                    int cost = cuts[j+1] - cuts[i-1]
                        + dp[i][ind-1] + dp[ind+1][j];
                    mn = min(mn, cost);
                }
                dp[i][j] = mn;
            }
        }

        return dp[1][c];
    }
};