class Solution {
    void solve(int ind, long long res, long long prev, string path, const string &num, int target, vector<string> &ans){
        if(ind == num.size()){
            if(res == target) ans.push_back(path);
            return;
        }
        long long curr = 0;
        for(int i = ind; i < num.size(); i++){
            if(i > ind && num[ind] == '0') break;
            
            curr = curr*10 + (num[i] - '0');
            string currStr = num.substr(ind, i-ind+1);
            
            if(ind == 0){
                solve(i+1, curr, curr, currStr, num, target, ans);
            }
            else{
                solve(i+1, res + curr, curr, path + "+" + currStr,
                num, target, ans);
                solve(i+1, res - curr, -curr, path + "-" + currStr,
                num, target, ans);
                solve(i+1, res - prev + (prev * curr), prev * curr, 
                path + "*" + currStr, num, target, ans);
            }
        }
    }

public:
    vector<string> addOperators(string num, int target) {
        vector<string> ans;
        solve(0, 0, 0, "", num, target, ans);
        return ans;
    }
};
// Time : O(4^n) 
//where n is the length of the string num. This is because for each digit, we have 4 choices: add '+', add '-', add '*', or concatenate the digit to the previous number.