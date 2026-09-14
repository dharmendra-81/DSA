// Time Complexity: O(V + E) where V is the number of vertices and E is the number of edges in the graph.
// Space Complexity: O(V + E) for the adjacency list and O(V) for the indegree array and queue.
class Solution {
  public:
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        vector<vector<int>> adj(V);
        for(auto& edge: edges){
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
        }
        
        // Calculate indegree of each node
        vector<int> indegree(V, 0);
        for(int i = 0; i < V; i++){
            for(auto it: adj[i]){
                indegree[it]++;
            }
        }
        
        // Initialize queue with all nodes having indegree 0
        queue<int> q;
        for(int i = 0; i < V; i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }
        
        // Perform Kahn's algorithm for topological sorting
        vector<int> topo;
        while(!q.empty()){
            int node = q.front(); q.pop();
            topo.push_back(node);
            
            for(auto it: adj[node]){
                indegree[it]--;
                if(indegree[it] == 0) q.push(it);
            }
        }
        return topo;
    }
};