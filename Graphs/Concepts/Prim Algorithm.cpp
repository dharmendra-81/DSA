/*
    Prim's Algorithm for finding Minimum Spanning Tree:
- It is a greedy algorithm that finds a minimum spanning tree for a weighted undirected graph.
- It starts with a single vertex and grows the spanning tree by adding the cheapest edge from the tree to a vertex not yet in the tree.
- The algorithm continues until all vertices are included in the spanning tree.
Time Complexity: O((V + E) log V)
   - V is the number of vertices and E is the number of edges in the graph.
Space Complexity: O(V + E) for the adjacency list, O(V) for the visited array, and O(V) for the priority queue.
*/

class Solution {
  public:
    int spanningTree(int V, vector<vector<int>>& edges) {
        vector<vector<pair<int, int>>> adj(V);
        for(auto &edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];
            adj[u].push_back({v, wt});
            adj[v].push_back({u, wt});
        }
        
        vector<bool> vis(V, false);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        
        pq.push({0, 0});
        int sum = 0;

        while(!pq.empty()){
            auto [d, node] = pq.top(); pq.pop();

            if(vis[node]) continue;
            
            vis[node] = true;
            sum += d;

            for(auto &it: adj[node]){
                auto [adjNode, w] = it;

                if(!vis[adjNode]){
                    pq.push({w, adjNode});
                }
            }
        }
        return sum;
    }
};