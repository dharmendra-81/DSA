class Solution {
    public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        int total = 1<<nums.size();  
        for(int mask=0; mask<total; mask++){
            vector<int> ds;
            for(int i=0; i<nums.size(); i++){
                if(mask & (1<<i) ){ // if the ith bit is set
                    ds.push_back(nums[i]);
                }
            }
            ans.push_back(ds);
        }
        return ans;
    }
};
// Time Complexity: O(n * 2^n) & Space Complexity: O(n * 2^n)