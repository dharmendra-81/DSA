/* 
KMP Algorithm for string matching
- The KMP (Knuth-Morris-Pratt) algorithm is a linear time string matching algorithm that uses the concept of a Longest Proper Prefix which is also Suffix (LPS) array.
- The LPS array is used to skip characters in the text when a mismatch occurs, thus avoiding unnecessary comparisons.
Time Complexity:
1. Average Case: O(n + m) where n is the length of the text and m is the length of the pattern.
2. Worst Case: O(n + m) as well
*/

class Solution {
public:
    vector<int> buildLPS(string pattern) {
        int m = pattern.size();
        vector<int> lps(m, 0);
        int len = 0;
        int i = 1;

        while (i < m) {
            if (pattern[i] == pattern[len]) {
                len++;
                lps[i] = len;
                i++;
            }
            else {
                if (len != 0) {
                    len = lps[len - 1];
                }
                else {
                    lps[i] = 0;
                    i++;
                }
            }
        }
        return lps;
    }

    vector<int> search(string text, string pattern) {
        int n = text.size();
        int m = pattern.size();
        vector<int> ans;

        if (m == 0 || m > n) return ans;

        vector<int> lps = buildLPS(pattern);
        int i = 0;  // Text pointer
        int j = 0;  // Pattern pointer

        while (i < n) {
            if (text[i] == pattern[j]) {
                i++;
                j++;
            }
            if (j == m) {
                ans.push_back(i - j);
                j = lps[j - 1];
            }
            else if (i < n && text[i] != pattern[j]) {
                if (j != 0) {
                    j = lps[j - 1];
                }
                else {
                    i++;
                }
            }
        }

        return ans;
    }
};