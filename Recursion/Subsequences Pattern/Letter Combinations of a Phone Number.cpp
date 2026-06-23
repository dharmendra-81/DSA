// https://leetcode.com/problems/letter-combinations-of-a-phone-number/description/

class Solution {
    void findCombination(int ind, string digits, string &s, string combos[],vector<string> &ans){
        if(ind == digits.size()){
            ans.push_back(s);
            return;
        }
        int digit = digits[ind] - '0';
        for(char ch: combos[digit]){
            s.push_back(ch);
            findCombination(ind+1, digits, s, combos, ans);
            s.pop_back();
        }
    }

public:
    vector<string> letterCombinations(string digits) {
        string combos[] = {
            "", "", "abc", "def",
            "ghi", "jkl", "mno",
            "pqrs", "tuv", "wxyz"
        };
        string s;
        vector<string> ans;
        findCombination(0, digits, s, combos, ans);
        return ans;
    }
};