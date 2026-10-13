// Time Complexity: O(n*k) where n is the number of stones and k is the maximum jump distance.
class Solution {
    int solve(int ind, int k, vector<int> &dp, vector<int>& h){
        if(ind == 0) return 0;
        
        if(dp[ind] != -1) return dp[ind];

        int minEnergy = INT_MAX;

        for(int j = 1; j <= k; j++){
            if(ind - j >= 0){
                int energy = solve(ind-j, k, dp, h) + abs(h[ind] - h[ind-j]);
                minEnergy = min(minEnergy, energy);
            }
        }
        
        return dp[ind] = minEnergy;
    }

public:
    int frogJump(vector<int>& heights, int k) {
        int n = heights.size();
        vector<int> dp(n, -1);
        
        return solve(n-1, k, dp, heights);
    }
};
