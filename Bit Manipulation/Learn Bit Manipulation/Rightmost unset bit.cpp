// Set the rightmost unset bit
class Solution {
    public:
      int setRightmostUnsetBit(int N) {
        return N | (N + 1);
      }
};

// Unset the rightmost unset bit
class Solution {
    public:
      int unsetRightmostUnsetBit(int N) {
        return N & (N + 1);
      }
};