class Solution {
    vector<vector<int>> dp;  

public:
    int longestCommonSubsequence(const string &text1, const string &text2) {
        int n = text1.size();
        int m = text2.size();

        dp.assign(n + 1, vector<int>(m + 1, 0));

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (text1[i - 1] == text2[j - 1]) {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        return dp[n][m];
    }

    void printLCS(const string &s1, const string &s2) {
        int n = s1.size();
        int m = s2.size();

        int len = longestCommonSubsequence(s1, s2);  

        string ans(len, '#');  

        int ind = len - 1;
        int i = n, j = m;

        while (i > 0 && j > 0) {
            if (s1[i - 1] == s2[j - 1]) {
                ans[ind] = s1[i - 1];
                ind--;
                i--;
                j--;
            } else if (dp[i - 1][j] > dp[i][j - 1]) {
                i--;
            } else {
                j--;
            }
        }

        cout << ans << '\n';
    }
};


