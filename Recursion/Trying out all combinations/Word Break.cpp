// Recursion/ Memoization/ Hash Table
// O(N3)
class Solution {
    bool solve(int ind, string &s, unordered_set<string> &dict, vector<int> &dp){
        if(ind == s.size()) return true;
        if(dp[ind] != -1) return dp[ind];
        string temp = "";
        for(int i = ind; i < s.size(); i++){
            temp += s[i];
            if(dict.find(temp) != dict.end()){
                if(solve(i+1, s, dict, dp)) return dp[ind] = true; 
            }
        }
        return dp[ind] = false;
    }

public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        vector<int> dp(s.size(), -1);
        return solve(0, s, dict, dp);
    }
};