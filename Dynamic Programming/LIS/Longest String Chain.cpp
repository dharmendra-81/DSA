class Solution {
    bool ispossible(string s1, string s2){
        if(s1.size()+1 != s2.size()) return false;
        int mismatches = 0;

        int i = 0, j = 0;
        while(j < s2.size()){
            if(i < s1.size() && s1[i] == s2[j]){
                i++;
                j++;
            }
            else{
                mismatches++;
                if (mismatches > 1) return false;
                j++;
            }
        }
        return true;
    }

public:
    int longestStrChain(vector<string>& words) {
        int n = words.size();
        vector<int> dp(n, 1);
        int len = 0;

        sort(words.begin(), words.end(), [](string &s1, string &s2){
            return s1.size() < s2.size();
        });

        for(int ind = 0; ind < n; ind++){
            for(int prev = 0; prev < ind; prev++){
                if(ispossible(words[prev], words[ind])){
                    dp[ind] = max(1 + dp[prev], dp[ind]);
                }
            }
            len = max(len, dp[ind]);
        }

        return len;
    }
};