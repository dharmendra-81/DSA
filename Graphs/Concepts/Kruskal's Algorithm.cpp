/*
 Kruskal's Algorithm:
 - It is a greedy algorithm used to find the Minimum Spanning Tree (MST) of a connected, undirected graph.
 - The algorithm works by sorting all the edges in the graph in non-decreasing order of their weights.
 - It then iterates through the sorted edges and adds an edge to the MST if it doesn't form a cycle with the edges already in the MST.
 - To detect cycles, it uses a Disjoint Set (Union-Find) data structure.
 Time Complexity: O(E log E), where E is the number of edges.
 */

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
    int kruskalsMST(int V, vector<vector<int>> &edges) {
        DisjointSet ds(V);

        sort(edges.begin(), edges.end(), [](const vector<int> &a, const vector<int> &b){
            return a[2] < b[2];
        });
        
        int sum = 0; 
        for(auto it: edges){
            int u = it[0];
            int v = it[1];
            int wt = it[2];
            
            if(ds.find(u) != ds.find(v)){
                sum += wt;
                ds.unionByRank(u, v);
            }
        }
        return sum;
    }
};