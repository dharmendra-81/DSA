// Given an m x n binary matrix mat, return the distance of the nearest 0 for each cell.
class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        
        vector<vector<bool>> vis(n, vector<bool> (m,false));
        vector<vector<int>> dist(n, vector<int> (m,0));
        queue<pair< pair<int,int>, int>> q;
        vector<int> delta = {-1, 0, 1, 0};

        for(int row = 0; row < n; row++){
            for(int col = 0; col < m; col++){
                if(mat[row][col] == 0){ // If the cell is 0, we add it to the queue with distance 0
                    q.push({{row, col}, 0});
                    vis[row][col] = true;
                }
            }
        }

        while(!q.empty()){
            auto [coords, steps] = q.front(); q.pop();
            auto [row, col] = coords;
            dist[row][col] = steps;

            for(int i = 0; i < 4; i++){
                int nRow = row + delta[i];
                int nCol = col + delta[(i + 1) % 4];

                if(nRow >= 0 && nRow < n && nCol >= 0 && nCol < m
                && mat[nRow][nCol] == 1 && !vis[nRow][nCol]){
                    vis[nRow][nCol] = true;
                    q.push({{nRow, nCol}, steps+1});
                }
            }
        }
        return dist;
    }
};