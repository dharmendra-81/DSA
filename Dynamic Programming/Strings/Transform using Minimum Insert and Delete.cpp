class Solution {
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();

        vector<int> prev(m+1, 0);
        vector<int> cur(m+1, 0);

        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                if(text1[i-1] == text2[j-1]){
                    cur[j] = 1 + prev[j-1];
                }
                else{
                    cur[j] = max(prev[j], cur[j-1]);
                }
            }
            prev = cur;
        }
        return prev[m];
    }
    
  public:
    int minOperations(string &s1, string &s2) {
        int lcs = longestCommonSubsequence(s1, s2);
        int del = s1.size() - lcs;
        int ins = s2.size() - lcs;
        
        return del + ins;
    }
};