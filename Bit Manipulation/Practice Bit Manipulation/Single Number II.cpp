// Time Complexity: O(32*n) 
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;
       for(int i = 0; i < 32; i++){
        int cnt = 0;
        for(int num: nums){
            if(num & (1u << i)) cnt++;
        }
        if(cnt%3 == 1){
            ans = ans | (1u << i);
        } 
       } 
       return ans;
    }
};

// Time Complexity: O(nlogn)
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        for(int i = 1; i < nums.size(); i += 3){
            if(nums[i] != nums[i-1]) return nums[i-1];
        }
        return nums.back();
    }
};

// Concept of buckets => Time Complexity: O(n)
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ones = 0, twos = 0;

        for(int num: nums){
            ones = (ones ^ num) & ~twos;
            twos = (twos ^ num) & ~ones;
        }
        return ones;
    }
};