// https://leetcode.com/problems/powx-n/description/

// Brute Force -> Time Complexity: O(n) and Space Complexity: O(1)
class Solution {
public:
    double myPow(double x, int n) {
        double ans = 1.0;
        for (int i = 1; i <= abs(n); i++) { 
            ans *= x;
        }
        return n < 0 ? 1 / ans : ans;
    }
};  

// Optimized Solution -> Time Complexity: O(log n) and Space Complexity: O(1)
class Solution {
public: 
    double myPow(double x, int n) {
        double ans = 1.0;
        long long nn = n; // To handle the case when n is INT_MIN
        if (nn < 0) {
            x = 1 / x;
            nn = -nn;
        }
         while(nn > 0){
            if(nn%2 == 0){ // If nn is even
                x = x*x;
                nn = nn/2;
            }
            else{ // If nn is odd
                ans = ans * x;
                nn = nn-1;
            }
        }
        return ans;
    }
};

// Recursive Solution -> Time Complexity: O(log n) and Space Complexity: O(log n)
class Solution {
    double f(double x, long long nn){
        if(nn == 0) return 1.0;
        if(nn == 1) return x;
        if(nn%2 == 0) return f(x*x, nn/2);
        return x*f(x, nn-1);
    }

public:
    double myPow(double x, int n) {
        long long nn = n; 
        if (nn < 0) {
            return f(1/x, -1*nn);
        }
        return f(x, nn);
    }
};