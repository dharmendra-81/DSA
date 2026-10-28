// Memoization
class Solution {
    int f(int i, int j, string s1, string s2, vector<vector<int>> &dp){
        if(i < 0) return j+1; // j+1 insertions in s1
        if(j < 0) return i+1; // i+1 deletions in s1 -> empty str

        if(dp[i][j] != -1) return dp[i][j];

        if(s1[i] == s2[j]) return dp[i][j] = 0 + f(i-1, j-1, s1, s2, dp);

        int ins = 1 + f(i, j-1, s1, s2, dp);
        int del = 1 + f(i-1, j, s1, s2, dp);
        int rep = 1 + f(i-1, j-1, s1, s2, dp);
        return dp[i][j] = min(ins, min(del, rep));
    }

public:
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();

        vector<vector<int>> dp(n, vector<int> (m, -1));
        return f(n-1, m-1, word1, word2, dp);
    }
};

// Tabulation
class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();

        vector<vector<int>> dp(n+1, vector<int> (m+1, 0));

        for(int i = 0; i <= n; i++) dp[i][0] = i;
        for(int j = 0; j <= m; j++) dp[0][j] = j;

        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                if(word1[i-1] == word2[j-1]){
                    dp[i][j] = dp[i-1][j-1];
                }
                else{
                    int ins = 1 + dp[i][j-1];
                    int del = 1 + dp[i-1][j];
                    int rep = 1 + dp[i-1][j-1];
                    dp[i][j] = min(ins, min(del, rep));
                }
            }
        }
        return dp[n][m];
    }
};

// Space Optimization
class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();

        vector<int> prev(m+1, 0);
        vector<int> cur(m+1, 0);

        for(int j = 0; j <= m; j++) prev[j] = j;

        for(int i = 1; i <= n; i++){
            cur[0] = i;
            for(int j = 1; j <= m; j++){
                if(word1[i-1] == word2[j-1]){
                    cur[j] = prev[j-1];
                }
                else{
                    int ins = 1 + cur[j-1];
                    int del = 1 + prev[j];
                    int rep = 1 + prev[j-1];
                    cur[j] = min(ins, min(del, rep));
                }
            }
            prev = cur;
        }
        return prev[m];
    }
};