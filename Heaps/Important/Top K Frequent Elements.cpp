class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> ans;

        for(int num: nums){
            mp[num]++;
        }

        for(auto it = mp.begin(); it != mp.end(); it++){
            pq.push({it->second, it->first});
            if(pq.size() > k) pq.pop();
        }

        while(!pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
        }

        return ans;
    }
};