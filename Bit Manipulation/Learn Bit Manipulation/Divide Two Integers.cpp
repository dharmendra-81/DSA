// Time: O(logN)^2 
class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend == divisor) return 1;
        bool sign = true; //positive number
        if(dividend>=0 && divisor<0) sign = false;
        if(dividend<0 && divisor>0) sign = false;
        long long p = llabs((long long) dividend);
        long long q = llabs((long long) divisor);
        long long quotient = 0;
        while(p >= q){
            int cnt = 0;
            while(p >= (q << (cnt+1))){
                cnt++;
            }
            quotient += (1LL << cnt);
            p -= (q << cnt);
        }
        if(quotient >= (1LL<<31) && sign) return INT_MAX;
        if(quotient >= (1LL<<31) && !sign) return INT_MIN;
        return sign ? (int) quotient : (-1 *(int) quotient);
    }
};