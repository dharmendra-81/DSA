// Using BFS to check if the graph is bipartite or not
class Solution {
    bool check(int start, vector<vector<int>>& adj, vector<int> &color){
        int n = adj.size();   
        queue<int> q;
        q.push(start);
        
        while(!q.empty()){
            int node = q.front(); q.pop();
            
            for(auto it: adj[node]){
                if(color[it] == -1){
                    color[it] = !color[node];
                    q.push(it);
                }
                else if(color[it] == color[node]){
                    return false;
                }
            }
        }
        return true;
    }
    
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n, -1);

        for(int i = 0; i < n; i++){
            if(color[i] == -1){
                if(!check(i, graph, color)) return false;
            }
        }
        return true;
    }
};

// Using DFS to check if the graph is bipartite or not
class Solution {
    bool dfs(int node, int col, vector<vector<int>>& adj, vector<int> &color){
        color[node] = col;
        
        for(auto it: adj[node]){
            if(color[it] == -1){
                if(!dfs(it, !col, adj, color)) return false;
            }
            else if(color[it] == color[node]){
                return false;
            }
        }
        return true;
    }

public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n, -1);

        for(int i = 0; i < n; i++){
            if(color[i] == -1){
                if(!dfs(i, 0, graph, color)) return false;
            }
        }
        return true;
    }
};