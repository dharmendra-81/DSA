// Brute Force : O(n^2)
class Solution {
    bool isPaclindrome(string s, int n){
        int i = 0, j = n-1;
        while(i < j){
            if(s[i] != s[j]) return false;
            i++;
            j--;
        }
        return true;
    }
    
public:
    string shortestPalindrome(string s) {
        int n = s.size();
        int len = n;
        while(len > 0){
            if(isPaclindrome(s, len)) break;
            len--;
        }

        string remaining = s.substr(len);
        reverse(remaining.begin(), remaining.end());
        return remaining + s;  
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
    string shortestPalindrome(string s) {
        string rev = s;
        reverse(rev.begin(), rev.end());
        string temp = s + "#" + rev;

        vector<int> lps = buildLPS(temp);
        int len = lps.back();

        string remaining = s.substr(len);
        reverse(remaining.begin(), remaining.end());

        return remaining + s;  
    }
};