// Using DFS approach: Time Complexity : O(N^2) , Space Complexity : O(N)
class Solution {
    void dfs(int &node, vector<vector<int>>& adjMat, vector<bool> &vis){
        vis[node] = true;
        
        for(int nbr = 0; nbr < adjMat.size(); nbr++){
            if(adjMat[node][nbr] == 1 && !vis[nbr]){
                dfs(nbr, adjMat, vis);
            }
        }
    }

public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<bool> vis(n, false);
        int cnt = 0;

        for(int i = 0; i < n; i++){
            if(!vis[i]){
                cnt++;
                dfs(i, isConnected, vis);
            }
        }
        return cnt;
    }
};

// Using Disjoint Set Union (DSU) or Union-Find approach: Time Complexity : O(N^2 * α(N)) , Space Complexity : O(N) 
class DisjointSet {
public:
    vector<int> parent, rank;
    DisjointSet(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for(int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int find(int u) {
        if(parent[u] != u) {
            parent[u] = find(parent[u]); 
        }
        return parent[u];
    }

    void unionByRank(int u, int v) {
        int rootU = find(u);
        int rootV = find(v);
        if(rootU != rootV) {
            if(rank[rootU] < rank[rootV]) {
                parent[rootU] = rootV;
            } else if(rank[rootU] > rank[rootV]) {
                parent[rootV] = rootU;
            } else {
                parent[rootV] = rootU;
                rank[rootU]++;
            }
        }
    }
};

class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        DisjointSet ds(n);

        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(isConnected[i][j] == 1){
                    ds.unionByRank(i, j); 
                }
            }
        }

        // Count the number of unique parents (provinces)
        int cnt = 0;
        for(int i = 0; i < n; i++){
            if(ds.parent[i] == i) cnt++;
        }
        return cnt;
    }
};