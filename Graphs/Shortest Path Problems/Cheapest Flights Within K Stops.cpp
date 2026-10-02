class Solution {
    public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int, int>>> adj(n);
        for(auto &edge : flights) {
            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];
            adj[u].push_back({v, wt});
        }

        queue< tuple<int, int, int> > q;
        q.push({0, src, 0});

        vector<int> dist(n, INT_MAX);
        dist[src] = 0;

        while (!q.empty()) {
            auto [stops, node, cost] = q.front();
            q.pop();

            if(stops > k) continue;

            for(auto it: adj[node]){
                auto [adjNode, d] = it;

                if(cost + d < dist[adjNode] && stops <= k){
                    dist[adjNode] = cost + d;
                    q.push({stops+1, adjNode, cost+d});
                }                
            }
        }

        if(dist[dst] == INT_MAX) return -1;
        return dist[dst];
    }
};