/*
Tarjan's Algorithm for finding Strongly Connected Components:
1. Perform a DFS traversal of the graph and maintain a stack to keep track of the visited nodes.
2. For each node, assign a unique index and a low-link value. 
The low-link value represents the smallest index reachable from that node.
3. If a node's low-link value is equal to its index, it indicates the root of a strongly connected component.
4. Pop nodes from the stack until the root node is reached, forming a strongly connected component
5. Repeat the process for all unvisited nodes in the graph.

Time Complexity: O(V + E), where V is the number of vertices and E is the number of edges in the graph.
Space Complexity: O(V) for the stack and additional data structures
*/

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
    
    void dfs2(int node, vector<vector<int>>& adj, vector<bool> &vis){
        vis[node] = true;
        
        for(auto it: adj[node]){
            if(!vis[it]){
                dfs2(it, adj, vis);
            }
        }
    }
    
  public:
    int countSCC(int V, vector<vector<int>> &edges) {
        vector<vector<int>> adj(V);
        for(auto &edge : edges) {
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
        }
        
        stack<int> st;
        vector<bool> vis(V, false);
        
        // 1) First DFS to fill stack by finish time
        for(int i = 0; i < V; i++){
            if(!vis[i]){
                dfs(i, adj, vis, st);
            }
        }
        
        // 2) Build transpose graph
        vector<vector<int>> adjT(V);
        for(int i = 0; i < V; i++){
            for(auto it: adj[i]){
                adjT[it].push_back(i);
            }
        }
        
        // 3) Second DFS on transpose graph in stack order
        fill(vis.begin(), vis.end(), false);
        int scc = 0;
        while(!st.empty()){
            int node = st.top();
            st.pop();
            
            if(!vis[node]){
                dfs2(node, adjT, vis);
                scc++;
            }
        }
        return scc;
    }
};