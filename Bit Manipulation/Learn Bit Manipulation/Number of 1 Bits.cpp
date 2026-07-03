// Brute force approach
class Solution {
public:
    int hammingWeight(int n) {
        int cnt = 0;
        while(n > 1){
            if(n & 1) cnt++;
            n = n >> 1;
        }
        if(n == 1) cnt++;
        return cnt;
    }
};

// Another approach
class Solution {
public:
    int hammingWeight(int n) {
        int cnt = 0;
        while(n != 0){
            n = n & (n-1);
            cnt++;
        }
        return cnt;
    }
};