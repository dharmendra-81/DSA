Given a string `s`, return _the longest_ in `s`.

---
```cpp
class Solution {
    int expandFromCenter(const string &s, int left, int right){
        while(left>=0 && right<s.length() && s[left]==s[right]){
            left--;
            right++;
        }
        return right-left-1;
    }

public:
    string longestPalindrome(string s) {
        int start=0, end=0;
        for(int center=0; center<s.length(); center++){
            int lenOdd = expandFromCenter(s, center, center);
            int lenEven = expandFromCenter(s, center, center+1);
            int maxLen = max(lenOdd, lenEven);
            if(maxLen > end-start){
                start = center - (maxLen-1)/2;
                end = center + (maxLen/2);
            }
        }
        return s.substr(start, end-start+1);
    }
};
O(N^2)
```
