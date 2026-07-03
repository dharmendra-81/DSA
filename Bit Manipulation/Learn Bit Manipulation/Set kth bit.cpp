// Set the i-th bit
class Solution {
  public:
    int setKthBit(int N, int i) {
        return N | (1 << i);
    }
};

// Unset the i-th bit
class Solution {
  public:
    int unsetKthBit(int N, int i) {
        return N & ~(1 << i);
    }
};

// Toggle the i-th bit
class Solution {
  public:
    int toggleKthBit(int N, int i) {
        return N ^ (1 << i);
    }
};
