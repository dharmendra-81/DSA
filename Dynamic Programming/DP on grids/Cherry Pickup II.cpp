// Memoization
class Solution {
    int f(int row, int col1, int col2, vector<vector<int>>& grid, vector<vector<vector<int>>> &dp) {
        int n = grid.size();
        int m = grid[0].size();

        if (col1 < 0 || col1 >= m || col2 < 0 || col2 >= m) return -1e8;
        if (row == n-1){
            if(col1 == col2) return grid[row][col1];
            return grid[row][col1] + grid[row][col2];
        }

        if (dp[row][col1][col2] != -1) return dp[row][col1][col2];

        int mx = 0;
        for(int dj1 = -1; dj1 <= 1; dj1++){
            for(int dj2 = -1; dj2 <= 1; dj2++){
                int value;

                if(col1 == col2){
                    value = grid[row][col1];
                }
                else{
                    value = grid[row][col1] + grid[row][col2];
                }

                value += f(row+1, col1+dj1, col2+dj2,  grid, dp); 
                mx = max(mx, value);
            }
        }

        return dp[row][col1][col2] = mx;
    }

public:
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int> (m, -1)));
        
        return f(0, 0, m-1, grid, dp);
    }
};

// Tabulation
class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int> (m, 0)));

        for(int col1 = 0; col1 < m; col1++){
            for(int col2 = 0; col2 < m; col2++){
                if(col1 == col2) dp[n-1][col1][col2] = grid[n-1][col1];
                else dp[n-1][col1][col2] = grid[n-1][col1] + grid[n-1][col2];
            }
        }

        for(int row = n-2; row >= 0; row--){
            for(int col1 = 0; col1 < m; col1++){
                for(int col2 = 0; col2 < m; col2++){
                    int mx = -1e8;
                    for(int dj1 = -1; dj1 <= 1; dj1++){
                        for(int dj2 = -1; dj2 <= 1; dj2++){
                            int value;

                            if(col1 == col2) value = grid[row][col1];
                            else value = grid[row][col1] + grid[row][col2];

                            if(col1+dj1>=0 && col1+dj1<m && col2+dj2>=0 && col2+dj2<m) value += dp[row+1][col1+dj1][col2+dj2];
                            else value += -1e8;

                            mx = max(mx, value);
                        }
                    }
                    dp[row][col1][col2] = mx;
                }
            }
        }
        return dp[0][0][m-1];
    }
};

// Space Optimization
class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> front(m, vector<int> (m, 0));

        for(int col1 = 0; col1 < m; col1++){
            for(int col2 = 0; col2 < m; col2++){
                if(col1 == col2) front[col1][col2] = grid[n-1][col1];
                else front[col1][col2] = grid[n-1][col1] + grid[n-1][col2];
            }
        }

        for(int row = n-2; row >= 0; row--){
            vector<vector<int>> cur(m, vector<int> (m, 0));
            for(int col1 = 0; col1 < m; col1++){
                for(int col2 = 0; col2 < m; col2++){
                    int mx = -1e8;
                    for(int dj1 = -1; dj1 <= 1; dj1++){
                        for(int dj2 = -1; dj2 <= 1; dj2++){
                            int value;

                            if(col1 == col2) value = grid[row][col1];
                            else value = grid[row][col1] + grid[row][col2];

                            if(col1+dj1>=0 && col1+dj1<m && col2+dj2>=0 && col2+dj2<m) 
                                value += front[col1+dj1][col2+dj2];
                            else value += -1e8;

                            mx = max(mx, value);
                        }
                    }
                   cur[col1][col2] = mx;
                }
            }
            front = cur;
        }
        return front[0][m-1];
    }
};