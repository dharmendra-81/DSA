You are given a string s. Return the array of unique characters, sorted by highest to lowest occurring characters.  
If two or more characters have same frequency then arrange them in alphabetic order.
**only for llowercase letters.**

---
```cpp
class Solution {
    static bool comparator(pair<int, char>p1, pair<int,char>p2){
        if(p1.first > p2.first)
            return true;
        if(p1.first < p2.first)
            return false;
        return p1.second < p2.second;
    }

public:
    vector<char> frequencySort(string s) {
    pair<int, char> freq[26];
    for (int i = 0; i < 26; i++) {
        freq[i] = {0, i + 'a'};
    }

    for (char ch : s) {
        freq[ch - 'a'].first++;
    }

    sort(freq, freq + 26, comparator);

    vector<char> ans;
    for (int i = 0; i < 26; i++) {
        if (freq[i].first > 0) {
            ans.push_back(freq[i].second);  
        }
    }
    return ans;
}
};
O(n + k log k)
```
