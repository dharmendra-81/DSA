class Solution {
    void dfs(int row, int col, vector<vector<char>>& board, vector<vector<bool>> &vis){
        int n = board.size();
        int m = board[0].size();

        vis[row][col] = true;
        vector<int> delta = {-1, 0, 1, 0};

        for(int i = 0; i < 4; i++){
            int nRow = row + delta[i];
            int nCol = col + delta[(i + 1) % 4];

            if(nRow >= 0 && nRow < n && nCol >= 0 && nCol < m
            && board[nRow][nCol] == 'O' && !vis[nRow][nCol]){
                dfs(nRow, nCol, board, vis);
            }
        }
    }

public:
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        vector<vector<bool>> vis(n, vector<bool> (m,false));

        // Traverse first row and last row
        for(int j = 0; j < m; j++){
            if(!vis[0][j] && board[0][j] == 'O'){
                dfs(0, j, board, vis);
            }
            if(!vis[n-1][j] && board[n-1][j] == 'O'){
                dfs(n-1, j, board, vis);
            }
        }

        // Traverse first col and last col
        for(int i = 0; i < n; i++){
            if(!vis[i][0] && board[i][0] == 'O'){
                dfs(i, 0, board, vis);
            }
            if(!vis[i][m-1] && board[i][m-1] == 'O'){
                dfs(i, m-1, board, vis);
            }
        }

        for(int row = 0; row < n; row++){
            for(int col = 0; col < m; col++){
                if(!vis[row][col] && board[row][col] == 'O'){
                    board[row][col] = 'X';
                }
            }
        }
    }
};