// Recursive + Memoization
class Solution {
    int f(int ind, int jumps, vector<int>& arr, vector<vector<int>> &dp){
        if(ind >= arr.size()-1) return jumps;

        if(dp[ind][jumps] != -1) return dp[ind][jumps];

        int mini = INT_MAX;
        for(int i = 1; i <= arr[ind]; i++){
            mini = min(mini, f(ind+i, jumps+1, arr, dp));
        }
        return dp[ind][jumps] = mini;
    }

public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));

        return f(0, 0, nums, dp);
    }
};

// Greedy Approach
class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        int jumps = 0;
        int l = 0, r = 0;

        while(r < n-1){
            int farthest = 0;

            for(int i = l; i <= r; i++){
                farthest = max(farthest, i + nums[i]);
            }
            
            l = r + 1;
            r = farthest;
            jumps++;
        }
        return jumps;
    }
};