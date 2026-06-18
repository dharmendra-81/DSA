// https://leetcode.com/problems/count-good-numbers/description/

// Recursion with fast exponentiation -> Time: O(log n) and Space: O(log n) 
class Solution {
public:
    const long long MOD = 1e9 + 7;

    long long power(long long x, long long n){
        if(n==0) return 1;
        if(n==1) return x%MOD;
        if(n & 1) return (x*power(x, n-1))%MOD; // if n is odd
        return power((x*x)%MOD, n>>1); // n>>1 means n/2
    }

    int countGoodNumbers(long long n) {
        long long even = (n + 1) / 2; 
        long long odd = n / 2;        

        return (power(5, even) * power(4, odd)) % MOD;
    }
};

// Iterative fast exponentiation -> Time: O(log n) and Space: O(1)
class Solution {
public:
    const long long MOD = 1e9 + 7;

    long long power(long long x, long long n){
        long long ans = 1;
        while(n){
            if(n & 1){
                ans = (ans*x)%MOD;
            }
            x = (x*x)%MOD;
            n = n>>1;
        }
        return ans;
    }

    int countGoodNumbers(long long n) {
        long long even = (n + 1) / 2; 
        long long odd = n / 2;        

        return (power(5, even) * power(4, odd)) % MOD;
    }
};