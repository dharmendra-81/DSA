// https://leetcode.com/problems/generate-parentheses/description/

// Brute Force -> Time: O(2^(2n) * n) & Space: O(2^(2n) * n)
class Solution {
    bool isValid(string s) {
        int cnt = 0;
        for (char ch : s) {
            if (ch == '(') cnt++;
            else cnt--;
            if (cnt < 0) return false;
        }
        return cnt == 0;
    }

    void generateAll(string s, int n, vector<string>& ans) {

        if (s.length() == 2 * n) {
            if (isValid(s)) {
                ans.push_back(s);
            }
            return;
        }
        generateAll(s + '(', n, ans);
        generateAll(s + ')', n, ans);
    }

public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        generateAll("", n, result);
        return result;  
    }
};

// Backtracking -> Time: O(4^n / sqrt(n)) & Space: O(4^n / sqrt(n))
class Solution {
    void solve(int open, int close, int n, string s, vector<string> &ans){
        if(s.size() == 2*n){
            ans.push_back(s);
            return;
        }
        if(open < n) solve(open+1, close, n, s+"(", ans);
        if(close < open) solve(open, close+1, n, s+")", ans);
    }
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        solve(0, 0, n, "", ans);
        return ans;
    }
};