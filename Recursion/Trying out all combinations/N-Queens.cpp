// Time : O(N! * N) without hashing
class Solution {
    bool isSafe(int row, int col, vector<string> &board, int n){
        int r = row; //Horizontal checking
        int c = col;
        while(c>=0){
            if(board[r][c] == 'Q') return false;
            c--;
        }

        r = row; //Upper Diagonal checking
        c = col;
        while(c>=0 && r>=0){
            if(board[r][c] == 'Q') return false;
            c--;
            r--;
        }

        r = row; //Lower Diagonal checking
        c = col;
        while(c>=0 && r<n){
            if(board[r][c] == 'Q') return false;
            c--;
            r++;
        }

        return true;
    }

    void solve(int col, vector<string> &board, vector<vector<string>> &ans, int n){
        if(col == n){
            ans.push_back(board);
            return;
        }
        for(int row=0; row<n; row++){
            if(isSafe(row, col, board, n)){
                board[row][col] = 'Q';
                solve(col+1, board, ans, n);
                board[row][col] = '.';
            }
        }
    }

public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n, string(n, '.'));
        solve(0, board, ans, n);
        return ans;
    }
};

// Time : O(N! * N) with hashing
class Solution {
    void solve(int col, vector<string> &board, vector<vector<string>> &ans,
    vector<int> &leftRow, vector<int> &lowerDiag, vector<int> &upperDiag, int n){
        if(col == n){
            ans.push_back(board);
            return;
        }
        for(int row=0; row<n; row++){
            if(leftRow[row] == 0
            && lowerDiag[row + col] == 0
            && upperDiag[n-1 + col - row] == 0){
                board[row][col] = 'Q';
                leftRow[row] = 1;
                lowerDiag[row + col] = 1;
                upperDiag[n-1 + col - row] = 1;
                solve(col+1, board, ans, leftRow, lowerDiag, upperDiag, n);        
                board[row][col] = '.';
                leftRow[row] = 0;
                lowerDiag[row + col] = 0;
                upperDiag[n-1 + col - row] = 0;
            }
        }
    }

public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n, string(n, '.'));
        vector<int> leftRow(n, 0);
        vector<int> lowerDiag(2*n-1, 0);
        vector<int> upperDiag(2*n-1, 0);
        solve(0, board, ans, leftRow, lowerDiag, upperDiag, n);
        return ans;
    }
};