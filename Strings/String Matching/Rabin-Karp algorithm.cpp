/* Rabin-Karp Algorithm for string matching 
The Rabin-Karp algorithm is a string searching algorithm that uses hashing to find any one of a set of pattern strings in a text. 
It is particularly useful for multiple pattern matching and can be more efficient than other algorithms in certain scenarios.
Time Complexity:
1. Average Case: O(n + m) where n is the length of the text and m is the length of the pattern.
2. Worst Case: O(n * m) due to hash collisions, but this is rare with a good hash function.
*/

class Solution {
public:
    vector<int> rabinKarp(string text, string pattern) {
        int n = text.size();
        int m = pattern.size();
        vector<int> ans;
        if (m == 0 || m > n) return ans;
        
        const int BASE = 256;
        const int MOD = 1000000007;
        long long patternHash = 0;
        long long windowHash = 0;
        long long power = 1; // BASE^(m-1) % MOD

        for (int i = 0; i < m - 1; i++) {
            power = (power * BASE) % MOD;
        }

        // initial hashes
        for (int i = 0; i < m; i++) {
            patternHash = (patternHash * BASE + (unsigned char)pattern[i]) % MOD;
            windowHash  = (windowHash  * BASE + (unsigned char)text[i])     % MOD;
        }

        for (int i = 0; i <= n - m; i++) {
            if (patternHash == windowHash) {
                if (text.substr(i, m) == pattern) {
                    ans.push_back(i);
                }
            }

            if (i < n - m) {
                // remove leftmost char
                windowHash = (windowHash - (unsigned char)text[i] * power % MOD + MOD) % MOD;
                // shift window: multiply by BASE
                windowHash = (windowHash * BASE + (unsigned char)text[i + m]) % MOD;
            }
        }
        return ans;
    }
};
