// Memoization
class Solution {
    int f(int row, int col, vector<vector<int>> &dp) {
        if (row == 0 && col == 0) return 1;
        if (row < 0 || col < 0) return 0;

        if (dp[row][col] != -1) return dp[row][col];

        int up = f(row - 1, col, dp);
        int left = f(row, col - 1, dp);

        return dp[row][col] = up + left;
    }

public:
    int uniquePaths(int n, int m) {
        vector<vector<int>> dp(n, vector<int>(m, -1));
        
        return f(n - 1, m - 1, dp);
    }
};

// Tabulation
class Solution {
public:
    int uniquePaths(int n, int m) {
        vector<vector<int>> dp(n, vector<int>(m, 0));

        for(int row = 0; row < n; row++){
            for(int col = 0; col < m; col++){
                if(row == 0 && col == 0) dp[row][col] = 1;
                else{
                    int up = 0, left = 0;
                    if(row > 0) up = dp[row-1][col];
                    if(col > 0) left = dp[row][col-1];
                    dp[row][col] = up + left;
                }
            }
        }

        return dp[n-1][m-1];
    }
};

// Space Optimization
class Solution {
public:
    int uniquePaths(int n, int m) {
        vector<int> prev(m, 0);

        for(int row = 0; row < n; row++){
            vector<int> cur(m, 0);
            for(int col = 0; col < m; col++){
                if(row == 0 && col == 0) cur[col] = 1;
                else{
                    int up = 0, left = 0;
                    if(row > 0) up = prev[col];
                    if(col > 0) left = cur[col-1];
                    cur[col] = up + left;
                }
            }
            prev = cur;
        }

        return prev[m-1];
    }
};