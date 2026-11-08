// Recursion 
class Solution {
    bool solve(const string &s, int ind, int cnt, vector<vector<int>> &dp) {
        if (cnt < 0) return false;
        if (ind == s.size()) return cnt == 0;

        if (dp[ind][cnt] != -1) return dp[ind][cnt];

        bool ans = false;
        if (s[ind] == '(') {
            ans = solve(s, ind + 1, cnt + 1, dp);
        } else if (s[ind] == ')') {
            ans = solve(s, ind + 1, cnt - 1, dp);
        } else { 
            ans = solve(s, ind + 1, cnt + 1, dp) ||
                  solve(s, ind + 1, cnt - 1, dp) ||
                  solve(s, ind + 1, cnt,     dp);
        }

        dp[ind][cnt] = ans ? 1 : 0;
        return ans;
    }

public:
    bool checkValidString(string s) {
        int n = s.size();
        vector<vector<int>> dp(n+1, vector<int>(n+1, -1));

        return solve(s, 0, 0, dp);
    }
};

// Greedy
class Solution {
public:
    bool checkValidString(string s) {
        int mn = 0, mx = 0;

        for(char ch: s){
            if(ch == '('){
                mn++;
                mx++;
            }
            else if(ch == ')'){
                mn--;
                mx--;
            }
            else{
                mn--;
                mx++;
            }

            if(mn < 0) mn = 0; // we can ignore the negative value of mn because we can treat '*' as '('
            if(mx < 0) return false; // if mx < 0, it means we have more ')' than '(' and '*' combined, so it's invalid
        }
        
        return mn == 0; // if mn == 0, it means we can balance all '(' with ')' and '*' treated as ')'
    }
};
