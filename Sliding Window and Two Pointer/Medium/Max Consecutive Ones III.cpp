// Time: O(2n)
class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int zeros=0;
        int ans=0;
        int left=0, right=0;
        while(right< nums.size()){
            if(nums[right]==0){
                zeros++;
            }
            while(zeros>k && left<=right){
                if(nums[left]==0){
                    zeros--;
                }
                left++;
            }
            ans = max(ans, right-left+1);
            right++;
        }
        return ans;    
    }
};

// Time: O(n)
class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int zeros=0;
        int maxlen=0;
        int left=0, right=0;

        while(right< nums.size()){
            if(nums[right]==0){
                zeros++;
            }

            if(zeros > k){
                if(nums[left]==0){
                    zeros--;
                }
                left++;
            }
            
            if(zeros <= k){
                maxlen = max(maxlen, right-left+1);
            }         
            right++;
        }
        return maxlen;    
    }
};