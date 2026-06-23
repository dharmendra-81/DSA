// https://leetcode.com/problems/combination-sum-ii/description/

// Backtracking/ Sorting/ Recursion -> O(2^n) time complexity, O(n) space complexity
class Solution {
    void findCombination(int ind, int target, vector<int>& arr,vector<int>& ds, vector<vector<int>> &ans){
        if(target == 0) {
            ans.push_back(ds);
            return;
        }
        for(int i = ind; i < arr.size(); i++){
            if((i > ind) &&  (arr[i] == arr[i-1])) continue;
            if(arr[i] > target) break;
            ds.push_back(arr[i]);
            findCombination(i+1, target-arr[i], arr, ds, ans);
            ds.pop_back();
        }
    }

public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> ds;
        sort(candidates.begin(), candidates.end());
        findCombination(0, target, candidates, ds, ans);
        return ans;
    }
};