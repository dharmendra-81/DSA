class Solution {
    public:
      int removeLastSetBit(int N) {
        return N & (N - 1);
      }
};