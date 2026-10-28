// Memoization
class Solution {
    bool isPalindrome(string &s, int start, int end){
        while(start <= end){
            if(s[start] != s[end]) return false;
            start++;
            end--;
        }
        return true;
    }

    int f(int i, string &s, vector<int> &dp){
        if(i == s.size()) return 0;

        if(dp[i] != -1) return dp[i];

        int mn = INT_MAX;
        for(int j = i; j < s.size(); j++){
            if(isPalindrome(s, i, j)){
                int parts = 1 + f(j+1, s, dp);
                mn = min(mn, parts);
            }
        }
        return dp[i] = mn;
    }

public:
    int minCut(string s) {
        int n = s.size();
        vector<int> dp(n, -1);

        return f(0, s, dp) - 1;
    }
};

// Tabulation
class Solution {
    bool isPalindrome(string &s, int start, int end){
        while(start <= end){
            if(s[start] != s[end]) return false;
            start++;
            end--;
        }
        return true;
    }

public:
    int minCut(string s) {
        int n = s.size();
        vector<int> dp(n+1, 0);

        for(int i = n-1; i >= 0; i--){
            int mn = INT_MAX;

            for(int j = i; j < n; j++){
                if(isPalindrome(s, i, j)){
                    int parts = 1 + dp[j+1];
                    mn = min(mn, parts);
                }
            }
            dp[i] = mn;
        }

        return dp[0] - 1;
    }
};