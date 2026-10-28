// Memoization
class Solution {
    int f(int ind, int prev, vector<int>& arr, vector<vector<int>> &dp){
        if(ind == arr.size()) return 0;

        if(dp[ind][prev+1] != -1) return dp[ind][prev+1];

        int skip = 0 + f(ind+1, prev, arr, dp);
        int take = 0;
        if(prev == -1 || arr[ind] > arr[prev]) 
            take = 1 + f(ind+1, ind, arr, dp);

        return dp[ind][prev+1] = max(take, skip);
    }

public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();

        vector<vector<int>> dp(n, vector<int>(n+1, -1));

        return f(0, -1, nums, dp);
    }
};

// Tabulation
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n+1, vector<int>(n+1, 0));

        for(int ind = n-1; ind >= 0; ind--){
            for(int prev = ind-1; prev >= -1; prev--){
                int skip = 0 + dp[ind+1][prev+1];
                int take = 0;
                if(prev == -1 || nums[ind] > nums[prev]) 
                    take = 1 + dp[ind+1][ind+1];

                dp[ind][prev+1] = max(take, skip);
            }
        }

        return dp[0][0];
    }
};

// Space Optimization
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 1);
        int len = 0;

        for(int ind = 0; ind < n; ind++){
            for(int prev = 0; prev < ind; prev++){
                if(nums[prev] < nums[ind]){
                    dp[ind] = max(1 + dp[prev], dp[ind]);
                }
            }
            len = max(len, dp[ind]);
        }

        return len;
    }
};

// Binary Search (Optimal)
class Solution {
    int lowerBound(vector<int> arr, int x){
        int n = arr.size();
        int low = 0, high = n-1;
        int ans = -1;

        while(low<=high){
            int mid= (low+high) / 2;   
            if(arr[mid] >= x){
                ans = mid;
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return ans;
    }

public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();

        vector<int> temp;
        temp.push_back(nums[0]);

        for(int i = 1; i < n; i++){
            if(nums[i] > temp.back()){
                temp.push_back(nums[i]);
            }
            else{
                int ind = lowerBound(temp, nums[i]);
                temp[ind] = nums[i];
            }
        }

        return temp.size();
    }
};