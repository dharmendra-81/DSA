// Two Pointers Approach: 
class Solution {
public:
    string countAndSay(int n) {
        string s = "1";
        for(int k = 2; k <= n; k++){
            string temp;
            int i = 0;

            while(i < s.size()){
                int j = i;
                while(j < s.size() && s[j] == s[i]) j++;
                int cnt = j - i;
                temp += to_string(cnt);
                temp += s[i];
                i = j;
            }
            s = temp;
        }
        return s;
    }
};