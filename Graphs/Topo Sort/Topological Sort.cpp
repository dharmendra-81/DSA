class Solution {
    void dfs(int node, vector<vector<int>>& adj, vector<bool> &vis, stack<int> &st){
        vis[node] = true;
    
        for(auto it: adj[node]){
            if(!vis[it]){
                dfs(it, adj, vis, st);
            }
        }
        st.push(node);
    }
    
  public:
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        vector<vector<int>> adj(V);
        for(auto& edge: edges){
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
        }
        
        vector<bool> vis(V, false);
        stack<int> st;
        for(int i = 0; i < V; i++){
            if(!vis[i]){
                dfs(i, adj, vis, st);
            }
        }
        
        vector<int> topo;
        while(!st.empty()){
            topo.push_back(st.top());
            st.pop();
        }
        return topo;
    }
};