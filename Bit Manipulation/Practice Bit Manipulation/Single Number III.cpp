class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        long long xorr = 0;
        for(int num: nums){
            xorr = xorr ^ num;
        }

        int rightmost = (xorr & (xorr-1)) ^ xorr;
        int b0 = 0, b1 = 0;
        for(int num: nums){
            if(rightmost & num) b1 = b1 ^ num;
            else b0 = b0 ^ num;
        }
        return {b1, b0};
    }
};
// Time : O(2n)