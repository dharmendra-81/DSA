class Solution {
public:
    int minBitFlips(int start, int goal) {
        int xorr = start ^ goal;
        // no of set bits;
        int ans = 0;
        while(xorr){
            xorr = xorr & (xorr - 1);
            ans++;
        }
        return ans;
    }
};