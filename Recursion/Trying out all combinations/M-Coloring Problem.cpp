// Time: 0(m^n) 
class Solution {
    bool isSafe(int node, vector<int> &color, vector<vector<int>> &adj, int N, int col){
        for(int nbr: adj[node]){
            if(color[nbr] == col) return false;
        }
        return true;
    }
    
    bool solve(int node, vector<int> &color, vector<vector<int>> &adj, int m, int N){
        if(node == N) return true;
        for(int i = 1; i <= m; i++){
            if(isSafe(node, color, adj, N, i)){
                color[node] = i;
                if(solve(node+1, color, adj, m, N)) return true;
                color[node] = 0;
            }
        }
        return false;
    }
    
  public:
    bool graphColoring(int v, vector<vector<int>> &edges, int m) {
        vector<int> color(v, 0);
        vector<vector<int>> adj(v);

        for(auto &edge : edges){
            int u = edge[0];
            int w = edge[1];
        
            adj[u].push_back(w);
            adj[w].push_back(u);
        }
        return solve(0, color, adj, m, v);
    }
};