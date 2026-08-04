class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>> ans;
        priority_queue<pair<int, vector<int>>> pq;

        for(auto point: points){
            int sqdist = point[0]*point[0] + point[1]*point[1];
            pq.push({sqdist, point});
            if(pq.size() > k) pq.pop();
        }

        while(!pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};