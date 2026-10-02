class DisjointSet {
    vector<int> parent;
public:
    vector<int> size;

    DisjointSet(int n) {
        parent.resize(n);
        size.resize(n, 1);
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

    void unionBySize(int u, int v) {
        int rootU = find(u);
        int rootV = find(v);
        if(rootU != rootV) {
            if(size[rootU] < size[rootV]) {
                parent[rootU] = rootV;
                size[rootV] += size[rootU];
            } else {
                parent[rootV] = rootU;
                size[rootU] += size[rootV];
            }
        }
    }
};

class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        DisjointSet ds(n * n);

        // Step 1: Connect all the 1's in the grid using Disjoint Set Union
        for(int row = 0; row < n; row++){
            for(int col = 0; col < n; col++){
                if(grid[row][col] == 0) continue;

                vector<int> delta = {-1, 0, 1, 0};
                for(int i = 0; i < 4; i++){
                    int newr = row + delta[i];
                    int newc = col + delta[(i + 1) % 4];

                    if(newr >= 0 && newr < n && newc >= 0 && newc < n
                    && grid[newr][newc] == 1){
                        int nodeNo = row * n + col;
                        int adjNodeNo = newr * n + newc;
                        ds.unionBySize(nodeNo, adjNodeNo);
                    }
                }
            }
        }

        // Step 2: Try to convert each 0 to 1 and calculate the size of the island formed
        int mx = 0;
        for(int row = 0; row < n; row++){
            for(int col = 0; col < n; col++){
                if(grid[row][col] == 1) continue;

                vector<int> delta = {-1, 0, 1, 0};
                set<int> components; // To store unique components connected to the 0 cell

                for(int i = 0; i < 4; i++){
                    int newr = row + delta[i];
                    int newc = col + delta[(i + 1) % 4];

                    if(newr >= 0 && newr < n && newc >= 0 && newc < n
                    && grid[newr][newc] == 1){
                        int adjNodeNo = newr * n + newc;
                        components.insert(ds.find(adjNodeNo));
                    }

                    // Now, components set contains all unique components connected to the 0 cell
                    int totalSize = 0;
                    for(auto it: components){
                        totalSize += ds.size[it];
                    }
                    mx = max(mx, totalSize + 1);
                }
            }
        }

        // Step 3: If there are no 0's in the grid, return the size of the largest island
        for(int cell = 0; cell < n * n; cell++){
            int root = ds.find(cell);
            mx = max(mx, ds.size[root]);
        }
        return mx;
    }
};