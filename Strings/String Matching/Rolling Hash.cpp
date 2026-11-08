/*
Rolling Hash is a string hashing technique that allows efficient computation of hash values for substrings of a given string. 
It is particularly useful for string matching problems, such as finding all occurrences of a pattern in a text, checking if two substrings are equal, and finding the longest duplicate substring.
Time Complexity:
1. Preprocessing: O(n) for computing prefix hashes and powers.
2. Hash Calculation: O(1) for each substring hash retrieval.
*/

class RollingHash {
    const long long BASE = 31;
    const long long MOD = 1e9 + 7;
    vector<long long> prefix, power;

public:
    RollingHash(string s) {
        int n = s.size();
        prefix.resize(n + 1, 0);
        power.resize(n + 1, 1);

        for (int i = 0; i < n; i++) {
            int value = s[i] - 'a' + 1;
            prefix[i + 1] = (prefix[i] * BASE + value) % MOD;
            power[i + 1] = (power[i] * BASE) % MOD;
        }
    }

    // Returns hash of substring [l, r)
    long long getHash(int l, int r) {
        long long ans = (prefix[r] - prefix[l] * power[r - l] % MOD + MOD) % MOD;
        return ans;
    }
};

class Solution {
public:
    // 1. Find all occurrences of pattern in text
    vector<int> searchPattern(string text, string pattern) {
        vector<int> result;
        int n = text.size();
        int m = pattern.size();

        if (m == 0 || m > n) return result;

        RollingHash textHash(text);
        RollingHash patternHash(pattern);
        long long target = patternHash.getHash(0, m);

        for (int i = 0; i + m <= n; i++) {
            long long current = textHash.getHash(i, i + m);

            if (current == target && text.compare(i, m, pattern) == 0) {
                result.push_back(i);
            }
        }

        return result;
    }

    // 2. Check if two substrings are equal
    bool areEqual(string s, int l1, int r1, int l2, int r2) {
        // Both substrings must have equal lengths
        if (r1 - l1 != r2 - l2) return false;

        RollingHash rh(s);
        long long h1 = rh.getHash(l1, r1);
        long long h2 = rh.getHash(l2, r2);
        // Verify actual characters to avoid collision
        return h1 == h2 && s.compare(l1, r1 - l1, s, l2, r2 - l2) == 0;
    }

    // Checks if a duplicate of given length exists, Returns its starting index, otherwise -1
    int checkDuplicate(string &s, int len, RollingHash &rh) {
        unordered_map<long long, vector<int>> seen;
        int n = s.size();

        for (int i = 0; i + len <= n; i++) {
            long long hash = rh.getHash(i, i + len);
            // Check previously seen substrings with same hash
            if (seen.count(hash)) {
                for (int prev : seen[hash]) {
                    // Verify actual substring to avoid collision
                    if (s.compare(prev, len, s, i, len) == 0) return i;
                }
            }
            seen[hash].push_back(i);
        }
        return -1;
    }

    // 3. Finds longest duplicate substring
    string longestDuplicate(string s) {
        int n = s.size();
        if (n < 2) return "";
        RollingHash rh(s);
        int low = 1;
        int high = n - 1;
        int bestStart = -1;
        int bestLength = 0;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            int start = checkDuplicate(s, mid, rh);
            if (start != -1) {
                // Duplicate exists, save answer
                bestStart = start;
                bestLength = mid;
                // Try finding a longer duplicate
                low = mid + 1;
            }
            else {
                // No duplicate, try shorter length
                high = mid - 1;
            }
        }
        if (bestStart == -1) return "";
        return s.substr(bestStart, bestLength);
    }
};
