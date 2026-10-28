// Memoization
class Solution {
    int f(int row, int col, vector<vector<int>>& grid, vector<vector<int>> &dp) {
        int m = grid[0].size();

        if (col < 0 || col >= m) return 1e9;
        if (row == 0) return grid[row][col];

        if (dp[row][col] != -1) return dp[row][col];

        int up = grid[row][col] + f(row - 1, col, grid, dp);
        int dl = grid[row][col] + f(row - 1, col - 1, grid, dp);
        int dr = grid[row][col] + f(row - 1, col + 1, grid, dp);

        return dp[row][col] = min(up, min(dl, dr));
    }

public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();

        vector<vector<int>> dp(n, vector<int>(n, -1));

        int mn = 1e8;
        for(int col = 0; col < n; col++){
            mn = min(mn, f(n - 1, col, matrix, dp));
        }
        
        return mn;
    }
};

// Tabulation
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();

        vector<vector<int>> dp(n, vector<int>(n, 0));

        dp[0] = matrix[0];

        for(int row = 1; row < n; row++){
            for(int col = 0; col < n; col++){
                int up = matrix[row][col] + dp[row - 1][col];

                int dl =  matrix[row][col];
                if(col - 1 >= 0) dl += dp[row - 1][col - 1];
                else dl += 1e8;

                int dr =  matrix[row][col];
                if(col + 1 < n) dr += dp[row - 1][col + 1];
                else dr += 1e8;

                dp[row][col] =  min(up, min(dl, dr));
            }
        }

        int ans = *min_element(dp[n-1].begin(), dp[n-1].end());     
        return ans;
    }
};

// Space Optimization
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<int> prev(n, 0);

        prev = matrix[0];

        for(int row = 1; row < n; row++){
            vector<int> cur(n, 0);
            for(int col = 0; col < n; col++){
                int up = matrix[row][col] + prev[col];

                int dl =  matrix[row][col];
                if(col - 1 >= 0) dl += prev[col - 1];
                else dl += 1e8;

                int dr =  matrix[row][col];
                if(col + 1 < n) dr += prev[col + 1];
                else dr += 1e8;

                cur[col] =  min(up, min(dl, dr));
            }
            prev = cur;
        }

        int ans = *min_element(prev.begin(), prev.end());     
        return ans;
    }
};