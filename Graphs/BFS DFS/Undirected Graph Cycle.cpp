// Detect cycle in an undirected graph using BFS
class Solution {
    bool detect(int src, vector<vector<int>> adj, vector<bool> &vis){
        vis[src] = true;
        queue<pair<int, int>> q;
        q.push({src, -1});
        
        while(!q.empty()){
            auto [node, parent] = q.front(); q.pop();
            
            for(auto it: adj[node]){
                if(!vis[it]){
                    vis[it] = true;
                    q.push({it, node});
                }
                else if(parent != it){
                    return true;
                }
            }
        }
        return false;
    }
    
  public:
    bool isCycle(int V, vector<vector<int>>& edges) {
        vector<vector<int>> adj(V);
        for(auto& edge: edges){
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        vector<bool> vis(V, false);
        
        for(int i = 0; i < V; i++){
            if(!vis[i]){
                if(detect(i, adj, vis)) return true;
            }
        }
        return false;
    }
};

// Detect cycle in an undirected graph using DFS
class Solution {
    bool dfs(int node, int parent, vector<vector<int>> &adj, vector<bool> &vis){
        vis[node] = true;
        
        for(int neighbor: adj[node]){
            if(!vis[neighbor]){
                if(dfs(neighbor, node, adj, vis)){
                    return true;                   
                }
            }
            else if (neighbor != parent) {
                return true;
            }
        }
        return false;
    }
    
  public:
    bool isCycle(int V, vector<vector<int>>& edges) {
        vector<vector<int>> adj(V);
        for(auto& edge: edges){
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        vector<bool> vis(V, false);
        
        for(int i = 0; i < V; i++){
            if(!vis[i]){
                if(dfs(i, -1, adj, vis)) return true;
            }
        }
        return false;
    }
};