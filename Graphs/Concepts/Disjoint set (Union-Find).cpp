/* 
Disjoint Set (Union-Find) Implementation
- This implementation uses path compression and union by rank to optimize the operations.
- The `find` function returns the representative of the set containing the element `u`.
- The `unionByRank` function merges two sets based on their ranks.
- The `unionBySize` function merges two sets based on their sizes.
Time Complexity: O(α(n)) for both find and union operations, where α is the inverse Ackermann function.
 */

class DisjointSet {
    vector<int> parent, rank, size;
public:
    DisjointSet(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        size.resize(n, 1);
        for(int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int find(int u) {
        if(parent[u] != u) {
            parent[u] = find(parent[u]); // Path compression
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

    // void unionBySize(int u, int v) {
    //     int rootU = find(u);
    //     int rootV = find(v);
    //     if(rootU != rootV) {
    //         if(size[rootU] < size[rootV]) {
    //             parent[rootU] = rootV;
    //             size[rootV] += size[rootU];
    //         } else {
    //             parent[rootV] = rootU;
    //             size[rootU] += size[rootV];
    //         }
    //     }
    // }
};

// GFG problem
class DisjointSet {
    vector<int> parent;
public:
    DisjointSet(int n) {
        // We'll use 1-based indexing: parent[1..n]
        parent.resize(n + 1);
        for (int i = 1; i <= n; i++) {
            parent[i] = i;
        }
    }

    int find(int u) {
        if (parent[u] != u) {
            parent[u] = find(parent[u]);  // path compression
        }
        return parent[u];
    }

    // Merge group of x into group of z:
    // representative of z becomes representative of the merged group
    void unionXZ(int x, int z) {
        int rootX = find(x);
        int rootZ = find(z);
        if (rootX != rootZ) {
            parent[rootX] = rootZ; // attach root of x under root of z
        }
    }
};


class Solution {
  public:
    vector<int> DSU(int n, vector<vector<int>>& queries) {
        DisjointSet ds(n);
        vector<int> ans;
        
        for(auto &q: queries){
            if(q[0] == 1){
                int x = q[1];
                int z = q[2];
                ds.unionXZ(x, z);
            }
            else if(q[0] == 2){
                int x = q[1];
                int rep = ds.find(x);
                ans.push_back(rep);
            }
        }
        return ans;
    }
};