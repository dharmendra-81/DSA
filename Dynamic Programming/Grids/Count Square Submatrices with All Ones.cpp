// Tabulation
class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        vector<vector<int>> dp(n, vector<int>(m, 0));

        for(int col = 0; col < m; col++) dp[0][col] = matrix[0][col];
        for(int row = 1; row < n; row++) dp[row][0] = matrix[row][0];
        
        for(int row = 1; row < n; row++){
            for(int col = 1; col < m; col++){
                if(matrix[row][col] == 0) dp[row][col] = 0;
                else{
                    dp[row][col] = 1 + min(dp[row-1][col-1], min(dp[row-1][col], dp[row][col-1]));
                }
            }
        }

        int sum = 0;
        for(int row = 0; row < n; row++){
            for(int col = 0; col < m; col++){
                sum += dp[row][col];
            }
        }
        return sum;
    }
};