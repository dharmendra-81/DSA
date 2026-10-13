// Space Complexity: O(target)
class Solution {
    int findWays(vector<int>& arr, int target) {
        int n = arr.size();

        vector<int> prev(target+1, 0);

        if(arr[0] == 0) prev[0] = 2;
        else{
            prev[0] = 1;
            if(arr[0] <= target) prev[arr[0]] = 1;
        }

        for(int ind = 1; ind < n; ind++){
            vector<int> cur(target+1, 0);
            for(int sum = 0; sum <= target; sum++){
               int skip = prev[sum];
               int take = 0;
               if(sum >= arr[ind]) take = prev[sum-arr[ind]]; 

               cur[sum] = take + skip;
            }
            prev = cur;
        }

       return prev[target];       
    }

    int countPartitions(vector<int>& nums, int diff) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        
        if(sum-diff < 0 || (sum-diff)&1) return 0;
        
        return findWays(nums, (sum-diff)/2);
    }

public:
    int findTargetSumWays(vector<int>& nums, int target) {
        return countPartitions(nums, target);
    }
};