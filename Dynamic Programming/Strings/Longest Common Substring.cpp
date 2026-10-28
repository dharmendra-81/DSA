// Tabulation
class Solution {
  public:
    int longCommSubstr(string& text1, string& text2) {
        int n = text1.size();
        int m = text2.size();

        vector<vector<int>> dp(n+1, vector<int> (m+1, 0));
        int ans = 0;

        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                if(text1[i-1] == text2[j-1]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                    ans = max(ans,  dp[i][j]);
                }
            }
        }
        return ans;
    }
};

// Space Optimization
class Solution {
  public:
    int longCommSubstr(string& text1, string& text2) {
        int n = text1.size();
        int m = text2.size();

        vector<int> prev(m+1, 0);
        vector<int> cur(m+1, 0);
        int ans = 0;

        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                if(text1[i-1] == text2[j-1]){
                    cur[j] = 1 + prev[j-1];
                    ans = max(ans,  cur[j]);
                }
                else{
                    cur[j] = 0;
                }
            }
            prev = cur;
        }
        return ans;
    }
};