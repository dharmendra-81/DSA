//  Two-pointer forward/backward scan: O(n×(n+m))
class Solution {
  public:
    string minWindow(string& s1, string& s2) {
        int minlen = INT_MAX;
        int start = -1;
        int end = INT_MAX;
        int i = 0;
        
        while(i < s1.size()){
            if(s1[i] == s2[0]){
                int j = i, k = 0;
                //  Forward scan
                while(j < s1.size() && k < s2.size()){
                    if(s1[j] == s2[k]) k++;
                    j++;
                }
                //  Backward scan
                if(k == s2.size()){
                    end = j - 1;
                    k = s2.size() - 1;
                    j = end;
                
                    while(k >= 0){
                        if(s1[j] == s2[k]) k--;
                        j--;
                    }
                
                    j++;
                
                    if(end - j + 1 < minlen){
                        minlen = end - j + 1;
                        start = j;
                    }
                
                    i = j;
                }
            }
            i++;
        }
        return start == -1 ? "" : s1.substr(start, minlen);
    }
};
