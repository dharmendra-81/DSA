// https://leetcode.com/problems/subsets-ii/description/

class Solution {
    void findSubsets(int i, vector<int>& nums, vector<int> &ds, vector<vector<int>> &ans){
        ans.push_back(ds);
        for(int j = i; j < nums.size(); j++){
            if(j > i && nums[j] == nums[j-1]) continue;
            ds.push_back(nums[j]);
            findSubsets(j+1, nums, ds, ans);
            ds.pop_back();
        }
    }

public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> ds;
        sort(nums.begin(), nums.end());
        findSubsets(0, nums, ds, ans);
        return ans;
    }
};