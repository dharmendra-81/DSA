// using left shift operator
class Solution {
  public:
    bool checkKthBit(int n, int k) {
        if(n & (1 << k)) return true;
        return false;
    }
};

// using right shift operator
class Solution {
  public:
    bool checkKthBit(int n, int k) {
        if((n >> k) & 1) return true;
        return false;
    }
};