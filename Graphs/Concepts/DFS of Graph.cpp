// Time: O(N + 2E) where N is the number of nodes and E is the number of edges in the graph
// Space: O(N) for the visited array and O(N) for the recursion stack in the worst case
class Solution {
    void dfsTraversal(int &node, vector<vector<int>>& adj, vector<bool> &vis, vector<int> &dfs){
        vis[node] = true;
        dfs.push_back(node);
        
        for(auto it: adj[node]){
            if(!vis[it]){
                dfsTraversal(it, adj, vis, dfs);
            }
        }
    }
    
  public:
    vector<int> dfs(vector<vector<int>>& adj) {
        int n = adj.size();
        vector<bool> vis(n, false);

        int start = 0;
        vector<int> dfs;

        dfsTraversal(start, adj, vis, dfs);

        return dfs;
    }
};