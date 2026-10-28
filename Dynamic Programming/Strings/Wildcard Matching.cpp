// Memoization
class Solution {
    bool f(int i, int j, const string &s1, const string &s2, vector<vector<int>> &dp){
        if(i < 0 && j < 0) return true; 
        if(i < 0 && j >= 0) return false; 
        if(j < 0 && i >= 0){
            for(int it = 0; it <= i; it++){
                if(s1[it] != '*') return false;
            }
            return true;
        }

        if(dp[i][j] != -1) return dp[i][j];

        if(s1[i] == s2[j] || s1[i] == '?') return dp[i][j] = f(i-1, j-1, s1, s2, dp);

        if(s1[i] == '*') return dp[i][j] = f(i-1, j, s1, s2, dp) || f(i, j-1, s1, s2, dp);
        return dp[i][j] = false;
    }

public:
    bool isMatch(string s, string p) {
        int n = p.size();
        int m = s.size();

        vector<vector<int>> dp(n, vector<int> (m, -1));
        return f(n-1, m-1, p, s, dp);
    }
};

// Tabulation
class Solution {
public:
    bool isMatch(string s, string p) {
        int n = p.size();
        int m = s.size();

        vector<vector<bool>> dp(n+1, vector<bool> (m+1, false));

        dp[0][0] = true;

        for(int i = 1; i <= n; i++){
            dp[i][0] = dp[i-1][0] && (p[i-1] == '*');
        }

        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                if(p[i-1] == s[j-1] || p[i-1] == '?'){
                    dp[i][j] = dp[i-1][j-1];
                }
                else if(p[i-1] == '*'){
                    dp[i][j] = dp[i-1][j] || dp[i][j-1];
                }
                else{
                    dp[i][j] = false;
                }
            }
        }
        return dp[n][m];
    }
};

// Space Optimization
class Solution {
public:
    bool isMatch(string s, string p) {
        int n = p.size();
        int m = s.size();

        vector<bool> prev(m+1, false);
        prev[0] = true;

        for(int i = 1; i <= n; i++){
            vector<bool> cur(m+1, false);
            cur[0] = prev[0] && p[i-1] == '*';
            
            for(int j = 1; j <= m; j++){
                if(p[i-1] == s[j-1] || p[i-1] == '?'){
                    cur[j] = prev[j-1];
                }
                else if(p[i-1] == '*'){
                    cur[j] = prev[j] || cur[j-1];
                }
                else{
                    cur[j] = false;
                }
            }
            prev = cur;
        }
        return prev[m];
    }
};
