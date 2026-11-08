// Brute Force : O(n^2)
class Solution {
public:
    string longestPrefix(string s) {
        int n = s.size();

        for(int i = n-1; i >= 1; i--){
            string prefix = s.substr(0, i);
            string suffix = s.substr(n-i);
            if(prefix == suffix) return prefix;
        }
        return "";
    }
};

// KMP : O(n)
class Solution {
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

public:
    string longestPrefix(string s) {
        int n = s.size();
        vector<int> lps = buildLPS(s);
        
        return s.substr(0, lps[n-1]);
    }
};
