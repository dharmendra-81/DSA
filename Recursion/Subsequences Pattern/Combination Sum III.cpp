// https://leetcode.com/problems/combination-sum-iii/description/

class Solution {
    void findCombination(int num, int k, int target, vector<int> &ds, vector<vector<int>> &ans){
        if(target == 0 && ds.size() == k) {
            ans.push_back(ds);
            return;
        }
        if(num > 9 || target < 0) return;
        for(int i = num; i <= 9; i++){
            if(target < i) break;
            ds.push_back(i);
            findCombination(i+1, k, target-i, ds, ans);
            ds.pop_back();
        }
    }

public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> ds;
        findCombination(1, k, n, ds, ans);
        return ans;
    }
};