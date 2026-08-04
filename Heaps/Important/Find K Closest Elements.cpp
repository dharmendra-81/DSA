class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        priority_queue<pair<int, int>> pq;
        vector<int> ans;
        
        for(int num: arr){
            pair<int, int> p(abs(num - x), num);
            pq.push(p);
            if(pq.size() > k) pq.pop();
        }

        while(!pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        
        sort(ans.begin(), ans.end());
        return ans;
    }
};