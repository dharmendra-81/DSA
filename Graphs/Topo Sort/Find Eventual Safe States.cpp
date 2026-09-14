// Using DFS to find eventual safe states in a directed graph
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
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<bool> vis(n, false);
        vector<bool> pathVis(n, false);
        vector<int> safeNodes;
        
        for(int i = 0; i < n; i++){
            if(!vis[i]){
                dfs(i, graph, vis, pathVis);
            }
        }
        
        for(int i = 0; i < n; i++){
            if(!pathVis[i]){
                safeNodes.push_back(i);
            }
        }
        return safeNodes;
    }
};

// Using Topological Sort to find eventual safe states in a directed graph
class Solution {
    vector<int> topoSort(int V, vector<vector<int>>& adj, vector<int> &indegree) {    
        queue<int> q;
        for(int i = 0; i < V; i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }
        
        vector<int> topo;
        while(!q.empty()){
            int node = q.front(); q.pop();
            topo.push_back(node);
            
            for(auto it: adj[node]){
                indegree[it]--;
                if(indegree[it] == 0) q.push(it);
            }
        }
        
        sort(topo.begin(), topo.end());
        return topo;
    }
    
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<int>> adjRev(n);
        vector<int> indegree(n, 0);
        
        for(int i = 0; i < n; i++){
            for(auto it: graph[i]){
                adjRev[it].push_back(i);
                indegree[i]++;
            }
        }
        return topoSort(n, adjRev, indegree);
    }
};