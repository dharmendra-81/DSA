// Time Complexity: O(V + E) where V is the number of vertices and E is the number of edges in the graph. We perform a topological sort which takes O(V + E) time, and then we relax the edges in topological order which also takes O(V + E) time.
// Space Complexity: O(V + E) for the adjacency list, O(V) for the
class Solution {
    void topoSort(int node, vector<vector<pair<int, int>>> &adj, vector<bool> &vis, stack<int> &st){
        vis[node] = true;

        for(auto it: adj[node]){
            int v = it.first;
            if(!vis[v]){
                topoSort(v, adj, vis, st);
            }
        }
        st.push(node);
    }
    
  public:
    vector<int> shortestPath(int V, vector<vector<int>>& edges) {
        // Create adjacency list with weights
        vector<vector<pair<int, int>>> adj(V);
        for(auto &edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];
            adj[u].push_back({v, wt});
        }
        
        vector<bool> vis(V, false);
        stack<int> st;
        
        // Perform topological sort
        for(int i = 0; i < V; i++){
            if(!vis[i]){
                topoSort(i, adj, vis, st);
            }
        }
        
        vector<int> dist(V, INT_MAX);
        dist[0] = 0;
        
        // Relax edges in topological order
        while(!st.empty()){
            int node = st.top(); st.pop();
            if(dist[node] == INT_MAX) continue;
            
            for(auto it: adj[node]){
                auto [v, wt] = it;
                if(dist[node] + wt < dist[v]){
                    dist[v] = dist[node] + wt;
                }
            }
        }
        
        // Replace INT_MAX with -1 for unreachable nodes
        for(int i = 0; i < V; i++) {
            if(dist[i] == INT_MAX) {
                dist[i] = -1;
            }
        }

        return dist;
    }
};
