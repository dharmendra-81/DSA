// https://www.geeksforgeeks.org/problems/power-set4302/1

// Bit Masking -> Time: O(n * 2^n) & Space: O(n * 2^n)
class Solution {
  public:
    vector<string> powerSet(string &s) {
        vector<string> ans;
        int total = 1<<s.size();  // 2^n
        for(int mask=0; mask<total; mask++){
            string curr = "";
            for(int i=0; i<s.size(); i++){
                if(mask & (1<<i) ){ // if the ith bit is set, include s[i] in the current subsequence
                    curr += s[i];
                }
            }
            ans.push_back(curr);
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};

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


