int kDistinctChars(int k, string &s) {
    if (k == 0 || s.empty()) return 0;
    int l = 0, r = 0;
    int maxlen = 0;
    unordered_map<char, int> mp;

    while(r < s.size()){
        mp[s[r]]++;
        while(mp.size() > k){
            mp[s[l]]--;
            if(mp[s[l]] == 0) mp.erase(s[l]);
            l++;
        }
        maxlen = max(maxlen, r-l+1);
        r++;
    }
    return maxlen;
}

// Time : O(2n) + O(log 256)