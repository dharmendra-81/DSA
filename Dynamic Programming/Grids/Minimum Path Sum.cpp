// Memoization
class Solution {
    int f(int row, int col, vector<vector<int>>& grid, vector<vector<int>> &dp) {
        if (row < 0 || col < 0) return 1e9;
        if (row == 0 && col == 0) return grid[row][col];

        if (dp[row][col] != -1) return dp[row][col];

        int up = grid[row][col] + f(row - 1, col, grid, dp);
        int left = grid[row][col] + f(row, col - 1, grid, dp);

        return dp[row][col] = min(up, left);
    }

public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> dp(n, vector<int>(m, -1));
        
        return f(n - 1, m - 1, grid, dp);
    }
};

// Tabulation
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> dp(n, vector<int>(m, 0));

        for(int row = 0; row < n; row++){
            for(int col = 0; col < m; col++){
                if(row == 0 && col == 0) dp[row][col] = grid[row][col];
                else{
                    int up = grid[row][col];
                    int left = grid[row][col];

                    if(row > 0) up += dp[row-1][col];
                    else up += 1e9;

                    if(col > 0) left += dp[row][col-1];
                    else left += 1e9;

                    dp[row][col] = min(up, left);
                }
            }
        }

        return dp[n-1][m-1];
    }
};

// Space Optimization
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<int> prev(m, 0);

        for(int row = 0; row < n; row++){
            vector<int> cur(m, 0);
            for(int col = 0; col < m; col++){
                if(row == 0 && col == 0) cur[col] = grid[row][col];
                else{
                    int up = grid[row][col];
                    int left = grid[row][col];

                    if(row > 0) up += prev[col];
                    else up += 1e9;

                    if(col > 0) left += cur[col-1];
                    else left += 1e9;

                    cur[col] = min(up, left);
                }
            }
            prev = cur;
        }

        return prev[m-1];
    }
};
