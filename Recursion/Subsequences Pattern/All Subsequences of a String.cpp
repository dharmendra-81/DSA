// https://www.geeksforgeeks.org/problems/power-set4302/1

// Recursion/Backtracking -> Time: O(n * 2^n) & Space: O(n * 2^n)
class Solution {
    void solve(int i, string &curr, string &s, vector<string> &ans){
        if(i == s.size()){
            ans.push_back(curr);
            return;
        }    
        curr.push_back(s[i]);
        solve(i+1, curr, s, ans);
        curr.pop_back();
        solve(i+1, curr, s, ans);
    }
    
  public:
    vector<string> powerSet(string &s) {
        vector<string> ans;
        string curr="";
        solve(0, curr, s, ans);
        sort(ans.begin(), ans.end());
        return ans;
    }
};


