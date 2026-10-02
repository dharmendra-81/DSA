class Solution {
  public:
    vector<int> shortestPath(int V, vector<vector<int>> &edges, int src, int dest) {
        vector<vector<pair<int, int>>> adj(V + 1);
        for (auto &edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];
            adj[u].push_back({v, wt});
            adj[v].push_back({u, wt});
        }

        // Sort adjacency lists by neighbor node index ascending
        for (int i = 1; i <= V; ++i) {
            sort(adj[i].begin(), adj[i].end());
        }

        // Run Dijkstra starting from dest
        vector<int> dist(V + 1, INT_MAX);
        dist[dest] = 0;

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, dest});

        while (!pq.empty()) {
            auto [d, u] = pq.top(); 
            pq.pop();

            if (d > dist[u]) continue;

            for (auto &[v, wt] : adj[u]) {
                if (dist[u] + wt < dist[v]) {
                    dist[v] = dist[u] + wt;
                    pq.push({dist[v], v});
                }
            }
        }

        // Unreachable target
        if (dist[src] == INT_MAX) return {-1};

        // Reconstruct path greedily starting from src
        vector<int> path;
        int curr = src;
        path.push_back(curr);

        while (curr != dest) {
            for (auto &[next_node, wt] : adj[curr]) {
                if (dist[curr] == dist[next_node] + wt) {
                    path.push_back(next_node);
                    curr = next_node;
                    break; // Pick the smallest next_node (adj is sorted)
                }
            }
        }

        return path;
    }
};