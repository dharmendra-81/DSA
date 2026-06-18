// https://leetcode.com/problems/combination-sum/description/

// Backtracking / Recursion
class Solution {
    void findCombination(int i, int target, vector<int>& candidates,
    vector<int>& ds, vector<vector<int>>& ans){
        if(i == candidates.size()){
            if(target == 0) ans.push_back(ds);
            return;
        }
        if(candidates[i] <= target){
            ds.push_back(candidates[i]);
            findCombination(i, target-candidates[i], candidates, ds, ans);
            ds.pop_back();
        }
        findCombination(i+1, target, candidates, ds, ans);
    }

public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        int i = 0;
        vector<int> ds;
        findCombination(i, target, candidates, ds, ans);
        return ans;
    }
};