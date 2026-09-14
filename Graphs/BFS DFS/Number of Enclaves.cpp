class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<int> delta = {-1, 0, 1, 0};
        vector<vector<bool>> vis(n, vector<bool> (m,false));
        queue<pair<int,int>> q;


        // Traverse first row and last row
        for(int j = 0; j < m; j++){
            if(grid[0][j] == 1){
                q.push({0, j});
                vis[0][j] = true;
            }
            if(grid[n-1][j] == 1){
                q.push({n-1, j});
                vis[n-1][j] = true;
            }
        }

        // Traverse first col and last col
        for(int i = 0; i < n; i++){
            if(grid[i][0] == 1){
                q.push({i, 0});
                vis[i][0] = true;
            }
            if(grid[i][m-1] == 1){
                q.push({i, m-1});
                vis[i][m-1] = true;
            }
        }

        while(!q.empty()){
            auto [row, col] = q.front(); q.pop();
            
            for(int i = 0; i < 4; i++){
                int nRow = row + delta[i];
                int nCol = col + delta[(i + 1) % 4];

                if(nRow >= 0 && nRow < n && nCol >= 0 && nCol < m
                && grid[nRow][nCol] == 1 && !vis[nRow][nCol]){
                    vis[nRow][nCol] = true;
                    q.push({nRow, nCol});
                }
            }
        }

        int cnt = 0;
        for(int row = 0; row < n; row++){
            for(int col = 0; col < m; col++){
                if(!vis[row][col] && grid[row][col] == 1){
                    cnt++;
                }
            }
        }
        return cnt;
    }
};