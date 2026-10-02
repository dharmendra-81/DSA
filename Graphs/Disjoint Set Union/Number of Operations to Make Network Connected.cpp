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
    int makeConnected(int n, vector<vector<int>>& connections) {
        DisjointSet ds(n);
        int extras = 0;

        for(auto it: connections){
            int u = it[0];
            int v = it[1];

            if(ds.find(u) == ds.find(v)){
                extras++;
            }else{
                ds.unionByRank(u, v);
            }
        }

        int connected = 0;
        for(int i = 0; i < n; i++){
            if(ds.parent[i] == i) connected++;
        }

        int ans = connected - 1;
        return extras >= ans ? ans : -1;
    }
};