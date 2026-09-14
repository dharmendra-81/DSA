// Time: O(N*M) where N is the number of rows and M is the number of columns in the grid
// Space: O(N*M) for the visited array and O(N*M) for the queue in the worst case
class Solution {
    void bfs(int row, int col, vector<vector<bool>> &vis, vector<vector<char>>& grid){
        int n = grid.size();
        int m = grid[0].size();
        vis[row][col] = true;
        
        queue<pair<int, int>> q;
        q.push({row, col});
        
        while(!q.empty()){
            auto [row, col] = q.front(); q.pop();
            
            // Check all 8 possible directions (up, down, left, right, and the 4 diagonals)
            for(int delrow = -1; delrow <= 1; delrow++){
                for(int delcol = -1; delcol <= 1; delcol++){
                    int nRow = row + delrow;
                    int nCol = col + delcol;
                    
                    if(nRow >= 0 && nRow < n && nCol >= 0 && nCol < m 
                    && grid[nRow][nCol] == 'L' && !vis[nRow][nCol]){
                        vis[nRow][nCol] = true;
                        q.push({nRow, nCol});
                    }
                }
            }
        }
    }
    
  public:
    int countIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<bool>> vis(n, vector<bool> (m, false));
        int cnt = 0;
        
        for(int row = 0; row < n; row++){
            for(int col = 0; col < m; col++){
                if(!vis[row][col] && grid[row][col] == 'L'){
                    cnt++;
                    bfs(row, col, vis, grid);
                }
            }
        }
        return cnt;
    }
};