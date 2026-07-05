class Solution {
    int xor1N(int N){
        if(N % 4 == 1) return 1;
        else if(N % 4 == 2) return N+1;
        else if(N % 4 == 3) return 0;
        else return N;
    }
    
  public:
    int findXOR(int l, int r) {
        return xor1N(l-1) ^ xor1N(r);
    }
};