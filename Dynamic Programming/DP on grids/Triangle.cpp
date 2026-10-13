// Memoization
class Solution {
    int f(int row, int col, vector<vector<int>>& triangle, vector<vector<int>> &dp) {
        if (row == triangle.size()-1) return triangle[row][col];

        if (dp[row][col] != -1) return dp[row][col];

        int down = triangle[row][col] + f(row + 1, col, triangle, dp);
        int diag = triangle[row][col] + f(row + 1, col + 1, triangle, dp);

        return dp[row][col] = min(down, diag);
    }

public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        int m = triangle[n-1].size();

        vector<vector<int>> dp(n, vector<int>(m, -1));
        
        return f(0, 0, triangle, dp); // we start from fixed point
    }
};

// Tabulation
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));

        // fill the last row of dp with the last row of triangle
        dp[n-1] = triangle[n-1];

        for(int row = n-2; row >= 0; row--){
            for(int col = row; col >= 0; col--){
                int down = triangle[row][col] + dp[row+1][col];
                int diag = triangle[row][col] + dp[row+1][col+1];

                dp[row][col] = min(down, diag);
            }
        }

        return dp[0][0];
    }
};

// Space Optimization
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<int> front(n, 0);

        front = triangle[n-1];

        for(int row = n-2; row >= 0; row--){
            vector<int> cur(n, 0);
            for(int col = row; col >= 0; col--){
                int down = triangle[row][col] + front[col];
                int diag = triangle[row][col] + front[col+1];

                cur[col] = min(down, diag);
            }
            front = cur;
        }

        return front[0];
    }
};