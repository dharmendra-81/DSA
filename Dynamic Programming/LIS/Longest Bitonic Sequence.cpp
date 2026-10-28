class Solution {
  public:
    int longestBitonicSequence(int n, vector<int> &nums) {
        vector<int> dp1(n, 1), dp2(n, 1);
        int len = 0;

        for(int ind = 0; ind < n; ind++){
            for(int prev = 0; prev < ind; prev++){
                if(nums[prev] < nums[ind]){
                    dp1[ind] = max(1 + dp1[prev], dp1[ind]);
                }
            }
        }
        
        for(int ind = n-1; ind >= 0; ind--){
            for(int prev = n-1; prev > ind; prev--){
                if(nums[prev] < nums[ind]){
                    dp2[ind] = max(1 + dp2[prev], dp2[ind]);
                }
            }
        }
        
        for(int i = 0; i < n; i++){
            len = max(len, dp1[i]+dp2[i]-1);
        }

        return len;
    }
};

// If purely increasing or purely decreasing sequence is not considered bitonic
class Solution {
  public:
    int longestBitonicSequence(int n, vector<int> &nums) {
        vector<int> dp1(n, 1), dp2(n, 1);
        int len = 0;

        for(int ind = 0; ind < n; ind++){
            for(int prev = 0; prev < ind; prev++){
                if(nums[prev] < nums[ind]){
                    dp1[ind] = max(1 + dp1[prev], dp1[ind]);
                }
            }
        }
        
        for(int ind = n-1; ind >= 0; ind--){
            for(int prev = n-1; prev > ind; prev--){
                if(nums[prev] < nums[ind]){
                    dp2[ind] = max(1 + dp2[prev], dp2[ind]);
                }
            }
        }
        
        for(int i = 0; i < n; i++){
            if (dp1[i] > 1 && dp2[i] > 1) {  
                len = max(len, dp1[i] + dp2[i] - 1);
            }
        }

        return len;
    }
};
