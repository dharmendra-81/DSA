class Solution {
public:
    bool isPowerOfTwo(int n) {
        // Negative numbers are not powers of two
        if(n <= 0) return false;
        if((n & (n-1)) == 0) return true;
        return false;
    }
};