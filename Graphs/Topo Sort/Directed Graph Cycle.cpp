// Using DFS to detect cycle in a directed graph
class Solution {
    bool dfs(int &node, vector<vector<int>>& adj, vector<bool> &vis, vector<bool> &pathVis){
        vis[node] = true;
        pathVis[node] = true;

        for(auto it: adj[node]){
            if(!vis[it]){
                if(dfs(it, adj, vis, pathVis)) return true;
            }
            else if(pathVis[it]) return true;
        }
        pathVis[node] = false;
        return false;
    }
    
  public:
    bool isCyclic(int V, vector<vector<int>> &edges) {
        vector<vector<int>> adj(V);
        for(auto& edge: edges){
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
        }
        
        vector<bool> vis(V, false);
        vector<bool> pathVis(V, false);
        
        for(int i = 0; i < V; i++){
            if(!vis[i]){
                if(dfs(i, adj, vis, pathVis)) return true;
            }
        }
        return false;
    }
};

// Using Kahn's Algorithm to detect cycle in a directed graph
class Solution {
  public:
    bool isCyclic(int V, vector<vector<int>> &edges) {
        vector<vector<int>> adj(V);
        for(auto& edge: edges){
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
        }
        
        vector<int> indegree(V, 0);
        for(int i = 0; i < V; i++){
            for(auto it: adj[i]){
                indegree[it]++;
            }
        }

        queue<int> q;
        for(int i = 0; i < V; i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }

        int cnt = 0;
        while(!q.empty()){
            int node = q.front(); q.pop();
            cnt++;

            for(auto it: adj[node]){
                indegree[it]--;
                if(indegree[it] == 0) q.push(it);
            }
        }
        return cnt == V ? false : true;
    }
};