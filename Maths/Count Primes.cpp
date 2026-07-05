// Given an integer n, return the number of prime numbers that are strictly less than n

// Sieve of Eratosthenes : Time Complexity: O(n log log n), Space Complexity: O(n)
class Solution {
public:
    int countPrimes(int n) {
        if(n <= 2) return 0;
        vector<bool> prime(n, true);
        prime[0] = prime[1] = false;

        for(int i = 2; i*i < n; i++){
            if(prime[i]){
                for(int j = i*i; j < n; j += i){
                    prime[j] = false;
                }
            }
        }

        int cnt = 0;
        for(int i = 2; i < n; i++){
            if(prime[i]) cnt++;
        }
        return cnt;
    }
};