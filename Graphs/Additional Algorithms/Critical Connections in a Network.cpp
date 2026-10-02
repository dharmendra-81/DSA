/*
Critical Connections in a Network using Tarjan's Algorithm:
1. Perform a DFS traversal of the graph while maintaining discovery and low-link values for each node.
2. For each node, assign a discovery time and a low-link value. 
The low-link value represents the earliest visited vertex reachable from that node.
3. If the low-link value of a neighboring node > the discovery time of the current node, it indicates that the edge between them is a critical connection (bridge).
4. Store all such critical connections found during the DFS traversal.

Time Complexity: O(V + E), where V is the number of vertices and E is the number of edges in the graph.
Space Complexity: O(V) for the recursion stack and additional data
*/

class Solution {
    int timer;
    void dfs(int node, int parent, vector<bool> &vis,  vector<vector<int>> &adj, vector<int> &tin, vector<int> &low, vector<vector<int>> &bridges){
        vis[node] = true;
        tin[node] = low[node] = timer++;

        for(int it: adj[node]){
            // If the adjacent node is the parent, skip it to avoid trivial cycle
            if(it == parent) continue;
            
            if(!vis[it]){
                dfs(it, node, vis, adj, tin, low, bridges);
                low[node] = min(low[node], low[it]);
                // Bridge condition
                if(low[it] > tin[node]){
                    bridges.push_back({it, node});
                }
            }
            else{
                // back edge
                low[node] = min(low[node], tin[it]);
            }
        }
    }

public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>> adj(n);
        for(auto &edge : connections) {
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        timer = 0;
        vector<bool> vis(n, false);
        vector<int> tin(n), low(n);
        vector<vector<int>> bridges;

        for (int i = 0; i < n; ++i) {
            if (!vis[i]) {
                dfs(i, -1, vis, adj, tin, low, bridges);
            }
        }
        return bridges;
    }
};