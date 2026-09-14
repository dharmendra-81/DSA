// Course Schedule: prerequisites[i] = [ai, bi] indicates that you must take course bi first if you want to take course ai.
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
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        for(auto& edge: prerequisites){
            int a = edge[0]; // dependent
            int b = edge[1]; // Prerequisite
            adj[b].push_back(a); // b -> a
        }
        
        vector<bool> vis(numCourses, false);
        vector<bool> pathVis(numCourses, false);
        
        for(int i = 0; i < numCourses; i++){
            if(!vis[i]){
                if(dfs(i, adj, vis, pathVis)) return false;
            }
        }
        return true;
    }
};

// Course Schedule II: Return the ordering of courses you should take to finish all courses.
class Solution {
    vector<int> topoSort(int V, vector<vector<int>>& adj) {    
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
        
        vector<int> topo;
        while(!q.empty()){
            int node = q.front(); q.pop();
            topo.push_back(node);
            
            for(auto it: adj[node]){
                indegree[it]--;
                if(indegree[it] == 0) q.push(it);
            }
        }
        
        if(topo.size() == V) return topo;
        return {};
    }

public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        for(auto& edge: prerequisites){
            int a = edge[0]; // dependent
            int b = edge[1]; // Prerequisite
            adj[b].push_back(a); // b -> a
        }
        return topoSort(numCourses, adj);
    }
};