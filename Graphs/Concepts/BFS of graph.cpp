// Time: O(N + 2E) where N is the number of nodes and E is the number of edges in the graph
// Space: O(N) for the visited array and O(N) for the queue in the worst case
class Solution {
  public:
    vector<int> bfs(vector<vector<int>> &adj) {
        int n = adj.size();
        vector<bool> vis(n, false);
        vis[0] = true;
        
        queue<int> q;
        q.push(0);
        vector<int> bfs;
        
        while(!q.empty()){
            int node = q.front(); q.pop();
            bfs.push_back(node);
            
            for(auto it: adj[node]){
                if(!vis[it]){
                    vis[it] = true;
                    q.push(it);
                }
            }
        }
        return bfs;
    }
};