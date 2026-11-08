/* 
Z Algorithm for string matching
- The Z algorithm is a linear time string matching algorithm that computes the Z-array for a given string. 
- The Z-array is an array of integers where the value at each index represents the length of the longest substring starting from that index which is also a prefix of the string. 
- This algorithm can be used to find occurrences of a pattern in a text efficiently.
Time Complexity:
1. Average Case: O(n + m) where n is the length of the text and m is the length of the pattern.
2. Worst Case: O(n + m) as well
*/

class Solution {
public:
    vector<int> search(string text, string pattern) {
        string s = pattern + "$" + text;
        int n = s.size();
        vector<int> z(n, 0);

        int l = 0, r = 0;
        for (int i = 1; i < n; i++) {
            if (i <= r) {
                z[i] = min(r - i + 1, z[i - l]);
            }

            while (i + z[i] < n && s[z[i]] == s[i + z[i]]) {
                z[i]++;
            }

            if (i + z[i] - 1 > r) {
                l = i;
                r = i + z[i] - 1;
            }
        }

        // Find pattern occurrences
        vector<int> ans;
        int m = pattern.size();

        for (int i = m + 1; i < n; i++) {
            if (z[i] == m) {
                ans.push_back(i - m - 1);
            }
        }
        return ans;
    }
};