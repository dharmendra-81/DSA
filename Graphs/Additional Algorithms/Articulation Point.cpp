/*
An articulation point (or cut vertex) in a graph is a vertex that, when removed along with its associated edges, increases the number of connected components in the graph. 
Algorithm to find articulation points in a graph using DFS and low-link values.
1. Perform a DFS traversal of the graph while maintaining discovery and low-link values for each node.
2. For each node, assign a discovery time and a low-link value.
3. If the low-link value of a neighboring node >= the discovery time of the current node, it indicates that the current node is an articulation point (except for the root node).
4. For the root node, if it has more than one child in the DFS tree, it is also an articulation point.
5. Store all such articulation points found during the DFS traversal.
Time Complexity: O(V + E), where V is the number of vertices and E is the number of edges in the graph.
Space Complexity: O(V) for the recursion stack and additional data
*/

class Solution {
    int timer;
    void dfs(int node, int parent, vector<bool> &vis,  vector<vector<int>> &adj, vector<int> &tin, vector<int> &low, vector<bool> &isArticulation){
        vis[node] = true;
        tin[node] = low[node] = timer++;
        int children = 0;

        for(int it: adj[node]){
            // If the adjacent node is the parent, skip it to avoid trivial cycle
            if(it == parent) continue;

            if(!vis[it]){
                children++;
                dfs(it, node, vis, adj, tin, low, isArticulation);
                low[node] = min(low[node], low[it]);
                
                // Articulation condition for non-root:
                if(low[it] >= tin[node] && parent != -1){
                    isArticulation[node] = true;
                }
            }
            else{
                // back edge
                low[node] = min(low[node], tin[it]);
            }
        }
        
         // Articulation condition for root:
         if(parent == -1 && children > 1){
             isArticulation[node] = true;
         }
    }
    
  public:
    vector<int> articulationPoints(int n, vector<vector<int>>& edges) {
    vector<vector<int>> adj(n);
        for(auto &edge : edges) {
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        timer = 0;
        vector<bool> vis(n, false);
        vector<bool> isArticulation(n, false);
        vector<int> tin(n), low(n);

        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                dfs(i, -1, vis, adj, tin, low, isArticulation);
            }
        }
        
        vector<int> ans;
        for(int i = 0; i < n; i++){
            if(isArticulation[i]){
                ans.push_back(i);
            }
        }
        
        if(ans.empty()) return {-1};
        return ans;
    }
};