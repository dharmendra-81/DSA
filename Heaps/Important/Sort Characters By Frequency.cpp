class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> mp;
        priority_queue<pair<int, char>> pq;
        string ans;

        for(char ch : s){
            mp[ch]++;
        }

        for(const auto& [key, value] : mp){
            pq.push({value, key});
        }

        while(!pq.empty()){
            auto [freq, ch] = pq.top();
            pq.pop();
            ans.append(freq, ch);
        }
        
        return ans;
    }
};