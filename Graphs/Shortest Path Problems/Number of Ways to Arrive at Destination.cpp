class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        const int MOD = 1e9 + 7;
        
        vector<vector<pair<int, int>>> adj(n);
        for(auto &edge : roads) {
            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];
            adj[u].push_back({v, wt});
            adj[v].push_back({u, wt});
        }

        priority_queue<pair<long long, int>, 
        vector<pair<long long, int>>, 
        greater<pair<long long, int>>> pq; 
        pq.push({0, 0});

        vector<long long> dist(n, LLONG_MAX);
        dist[0] = 0;

        vector<int> ways(n, 0);
        ways[0] = 1;

        while(!pq.empty()){
            auto [d, node] = pq.top();
            pq.pop();

            // If the current distance is greater than the recorded distance, skip processing
            if(d > dist[node]) continue;

            for(auto it: adj[node]){
                auto [adjNode, w] = it;

                // If a shorter path to adjNode is found, update the distance and ways
                if(d + w < dist[adjNode]){
                    dist[adjNode] = d + w;
                    pq.push({dist[adjNode], adjNode});
                    ways[adjNode] = ways[node];
                }
                // If another shortest path to adjNode is found, increment the ways 
                else if(d + w == dist[adjNode]){
                    ways[adjNode] = (ways[adjNode] + ways[node]) % MOD;
                }
            }
        }
        return ways[n-1] % MOD;
    }
};