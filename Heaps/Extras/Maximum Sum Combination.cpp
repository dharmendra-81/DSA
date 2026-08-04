//  Time: O(nlogn + mlogm + klogk), where n and m are the sizes of the two arrays, and k is the number of pairs to return.
class Solution {
  public:
    vector<int> topKSumPairs(vector<int>& a, vector<int>& b, int k) {
        sort(a.begin(), a.end(), greater<int>());
        sort(b.begin(), b.end(), greater<int>());
        
        priority_queue<tuple<int, int, int>> pq;
        set<pair<int, int>> visited;
        vector<int> ans;
        pq.push({a[0]+b[0], 0, 0});
        visited.insert({0, 0});
        
        while(!pq.empty() && k--){
            auto [sum, i, j] = pq.top();
            pq.pop();
            ans.push_back(sum);
            
            if(i+1 < a.size() && visited.find({i+1, j})==visited.end()){
                pq.push({a[i+1]+b[j], i+1, j});
                visited.insert({i+1, j});
            }
            if(j+1 < b.size() && visited.find({i, j+1})==visited.end()){
                pq.push({a[i]+b[j+1], i, j+1});
                visited.insert({i, j+1});
            }
        }
        return ans;
    }
};