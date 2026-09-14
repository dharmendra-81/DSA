class Solution {
    void dfs(int row, int col, vector<vector<bool>> &vis, vector<vector<char>>& grid, vector<pair<int, int>> &temp, int row0, int col0){
        int n = grid.size();
        int m = grid[0].size();
        vis[row][col] = true;
        temp.push_back({row - row0, col - col0});

        vector<int> delta = {-1, 0, 1, 0};

        for(int i = 0; i < 4; i++){
            int nRow = row + delta[i];
            int nCol = col + delta[(i + 1) % 4];

            if(nRow >= 0 && nRow < n && nCol >= 0 && nCol < m
            && !vis[nRow][nCol]  && grid[nRow][nCol] == 'L'){
                dfs(nRow, nCol, vis, grid, temp, row0, col0);
            }
        }
    }

  public:
    int countDistinctIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<bool>> vis(n, vector<bool> (m, false));
        set<vector<pair<int, int>>> st;
        
        for(int row = 0; row < n; row++){
            for(int col = 0; col < m; col++){
                if(!vis[row][col] && grid[row][col] == 'L'){
                    vector<pair<int, int>> temp;
                    dfs(row, col, vis, grid, temp, row, col);
                    st.insert(temp);
                }
            }
        }
        return st.size();
    }
};
