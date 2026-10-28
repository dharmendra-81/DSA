// Memoization
class Solution {
    int f(int i, int j, string s1, string s2, vector<vector<int>> &dp){
        if(j < 0) return 1;
        if(i < 0) return 0;

        if(dp[i][j] != -1) return dp[i][j];

        if(s1[i] == s2[j]) return dp[i][j] = f(i-1, j-1, s1, s2, dp) + f(i-1, j, s1, s2, dp);
        return dp[i][j] = f(i-1, j, s1, s2, dp);
    }
    
public:
    int numDistinct(string s, string t) {
        int n = s.size();
        int m = t.size();

        vector<vector<int>> dp(n, vector<int> (m, -1));
        return f(n-1, m-1, s, t, dp);
    }
};

// Tabulation
class Solution {
public:
    int numDistinct(string s, string t) {
        const int MOD = 1e9 + 7;
        int n = s.size();
        int m = t.size();

        vector<vector<int>> dp(n+1, vector<int> (m+1, 0));

        for(int i = 0; i <= n; i++) dp[i][0] = 1;

        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                if(s[i-1] == t[j-1]){
                    dp[i][j] = (dp[i-1][j-1] + dp[i-1][j]) % MOD;
                }
                else{
                    dp[i][j] = dp[i-1][j] % MOD;
                }
            }
        }
        return dp[n][m];
    }
};

// Space Optimization
class Solution {
public:
    int numDistinct(string s, string t) {
        const int MOD = 1e9 + 7;
        int n = s.size();
        int m = t.size();

        vector<int> prev(m+1, 0);
        vector<int> cur(m+1, 0);

        prev[0] = cur[0] = 1;

        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                if(s[i-1] == t[j-1]){
                    cur[j] = (prev[j-1] + prev[j]) % MOD;
                }
                else{
                    cur[j] = prev[j] % MOD;
                }
            }
            prev = cur;
        }
        return prev[m];
    }
};

// 1D Space Optimization
class Solution {
public:
    int numDistinct(string s, string t) {
        const int MOD = 1e9 + 7;
        int n = s.size();
        int m = t.size();

        vector<int> prev(m+1, 0);
        prev[0] = 1;

        for(int i = 1; i <= n; i++){
            for(int j = m; j >= 1; j--){
                if(s[i-1] == t[j-1]){
                    prev[j] = (prev[j-1] + prev[j]) % MOD;
                }
            }
        }
        return prev[m];
    }
};