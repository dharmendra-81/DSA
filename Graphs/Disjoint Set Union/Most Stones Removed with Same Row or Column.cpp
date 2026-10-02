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
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        int mxr = 0;
        int mxc = 0;

        // Find the maximum row and column indices to size the Disjoint Set Union structure
        for(auto it: stones){
            mxr = max(mxr, it[0]);
            mxc = max(mxc, it[1]);
        }

        // Node mapping:
        // rows:      0 ... maxRow
        // columns:   maxRow+1 ... maxRow+1 + maxCol
        unordered_map<int, int> mp;
        DisjointSet ds(mxr + mxc + 2);

        // Union rows and columns for each stone
        for(auto it: stones){
            int nodeRow = it[0]; // Row node
            int nodeCol = it[1] + mxr + 1; // Column node (offset by maxRow + 1)

            ds.unionByRank(nodeRow, nodeCol);
            mp[nodeRow] = 1;
            mp[nodeCol] = 1;
        }

        // Count the number of unique connected components 
        int cnt = 0;
        for(auto [k, v]: mp){
            if(ds.find(k) == k){
                cnt++;
            }
        }
        return n - cnt;
    }
};