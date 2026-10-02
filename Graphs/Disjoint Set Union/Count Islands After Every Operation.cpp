class DisjointSet {
    vector<int> parent, rank;
public:
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
    vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators) {
        DisjointSet ds(n * m);
        vector<int> ans;
        vector<vector<bool>> vis(n, vector<bool> (m, false));

        int cnt = 0;
        for(auto it: operators){
            int row = it[0];
            int col = it[1];
            
            if(vis[row][col]){
                ans.push_back(cnt);
                continue;
            }
            
            vis[row][col] = true;
            cnt++;
            
            vector<int> delta = {-1, 0, 1, 0};
            for(int i = 0; i < 4; i++){
                int newr = row + delta[i];
                int newc = col + delta[(i + 1) % 4];

                if(newr >= 0 && newr < n && newc >= 0 && newc < m
                && vis[newr][newc]){
                    int nodeNo = row * m + col;
                    int adjNodeNo = newr * m + newc;
                    
                    if(ds.find(nodeNo) != ds.find(adjNodeNo)){
                        cnt--;
                        ds.unionByRank(nodeNo, adjNodeNo);
                    }
                }
            }
        }
        return ans;
    }
};