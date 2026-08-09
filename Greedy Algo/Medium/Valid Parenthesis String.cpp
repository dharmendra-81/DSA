// Recursion (TLE)
class Solution {
    bool f(string s, int ind, int cnt){
        if(cnt < 0) return false;
        if(ind == s.size()) return cnt == 0;
        if(s[ind] == '(') return f(s, ind+1, cnt+1);
        if(s[ind] == ')') return f(s, ind+1, cnt-1);
        return f(s, ind+1, cnt+1) || f(s, ind+1, cnt-1) || f(s, ind+1, cnt);
    }

public:
    bool checkValidString(string s) {
        return f(s, 0, 0);
    }
};