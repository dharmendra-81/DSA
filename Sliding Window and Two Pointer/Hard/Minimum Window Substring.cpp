//  Brute Force
class Solution {
public:
    string minWindow(string s, string t) {
        int minlen = INT_MAX;
        int starting = -1;

        for(int i = 0; i < s.size(); i++){
            vector<int> hash(256, 0);
            int cnt = 0;
            for(int j = 0; j < t.size(); j++){
                hash[t[j]]++;
            }
            for(int j = i; j < s.size(); j++){
                if(hash[s[j]] > 0) cnt++;
                hash[s[j]]--;
                if(cnt == t.size()){
                    if(j-i+1 < minlen){
                        minlen = j-i+1;
                        starting = i;
                        break;
                    }
                }
            }
        }
        if(starting == -1) return "";
        return s.substr(starting, minlen);
    }
};

//  Optimal: O(m + 2n)
class Solution {
public:
    string minWindow(string s, string t) {
        int minlen = INT_MAX;
        int starting = -1;
        int cnt = 0;
        vector<int> hash(256, 0);
        int l = 0, r = 0;

        for(int i = 0; i < t.size(); i++){
            hash[t[i]]++;
        }

        while(r < s.size()){
            if(hash[s[r]] > 0) cnt++;
            hash[s[r]]--;

            while(cnt == t.size()){
                if(r-l+1 < minlen){
                    minlen = r-l+1;
                    starting = l;
                }
                hash[s[l]]++;
                if(hash[s[l]] > 0) cnt--;
                l++;
            }
            r++;
        }
        if(starting == -1) return "";
        return s.substr(starting, minlen);
    }
};