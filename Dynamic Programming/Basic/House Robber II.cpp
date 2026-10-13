// Time Complexity: O(n)
// Space Complexity: O(1)
class Solution {
    int nonAdjacent(int start, int n, vector<int>& nums) {
        int prev2 = 0;
        int prev1 = nums[start];

        for(int i = start+1; i < n; i++){
            int pick = nums[i] + prev2;
            int notPick = 0 + prev1;
            
            int cur = max(pick, notPick);
            prev2 = prev1;
            prev1 = cur;

        }

        return prev1;
    }

public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];

        int case1 = nonAdjacent(0, n - 1, nums);
        int case2 = nonAdjacent(1, n, nums);

        return max(case1, case2);
    }
};