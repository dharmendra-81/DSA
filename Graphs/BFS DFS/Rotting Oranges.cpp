// Time: O(N*M) where N is the number of rows and M is the number of columns in the grid
// Space: O(N*M) for the vis array and O(N*M) for the queue
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<bool>> vis(n, vector<bool> (m,false));
        queue<pair< pair<int,int>, int>> q;
        vector<int> delta = {-1, 0, 1, 0};
        int time = 0;
        int cntFresh = 0;

        for(int row = 0; row < n; row++){
            for(int col = 0; col < m; col++){
                if(grid[row][col] == 2){
                    q.push({{row, col}, 0});
                    vis[row][col] = true;
                }
                else if(grid[row][col] == 1) cntFresh++;
            }
        }

        if (cntFresh == 0) return 0;

        while(!q.empty()){
            auto [coords, t] = q.front(); q.pop();
            auto [row, col] = coords;
            time = max(time, t);

            for(int i = 0; i < 4; i++){
                int nRow = row + delta[i];
                int nCol = col + delta[(i + 1) % 4];

                if(nRow >= 0 && nRow < n && nCol >= 0 && nCol < m
                && grid[nRow][nCol] == 1 && !vis[nRow][nCol]){
                    vis[nRow][nCol] = true;
                    q.push({{nRow, nCol}, t+1});
                    cntFresh--;
                }
            }
        }

        return (cntFresh == 0) ? time : -1;
    }
};