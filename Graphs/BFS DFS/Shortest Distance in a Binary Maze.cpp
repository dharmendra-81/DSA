// using BFS to find the shortest path in a binary maze
class Solution {
public:
    int shortestPath(vector<vector<int>> &grid, vector<int> &src, vector<int> &dest) {
        int n = grid.size();
        int m = grid[0].size();

        if (grid[src[0]][src[1]] == 0 || grid[dest[0]][dest[1]] == 0) {
            return -1;
        }

        vector<int> deltaRow = {-1, 0, 1, 0};
        vector<int> deltaCol = {0, 1, 0, -1};

        vector<vector<bool>> vis(n, vector<bool>(m, false));
        vis[src[0]][src[1]] = true;

        // Queue: {row, col, distance}
        queue<tuple<int, int, int>> q;
        q.push({src[0], src[1], 0});

        while (!q.empty()) {
            auto [r, c, dist] = q.front();
            q.pop();

            if (r == dest[0] && c == dest[1]) {
                return dist;
            }

            for (int i = 0; i < 4; i++) {
                int nr = r + deltaRow[i];
                int nc = c + deltaCol[i];

                if (nr >= 0 && nr < n && nc >= 0 && nc < m && !vis[nr][nc] && grid[nr][nc] == 1) {
                    vis[nr][nc] = true;
                    q.push({nr, nc, dist + 1});
                }
            }
        }

        return -1;
    }
};

// using Dijkstra's algorithm to find the shortest path in a binary maze
class Solution {
public:
    int shortestPath(vector<vector<int>> &grid, vector<int> &src, vector<int> &dest) {
        int n = grid.size();
        int m = grid[0].size();
        
        if (grid[src[0]][src[1]] == 0 || grid[dest[0]][dest[1]] == 0) {
            return -1;
        }

        if (src[0] == dest[0] && src[1] == dest[1]) {
            return 0;
        }

        vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
        dist[src[0]][src[1]] = 0;

        queue<tuple<int, int, int>> q;
        q.push({src[0], src[1], 0});

        vector<int> delta = {-1, 0, 1, 0};

        while (!q.empty()) {
            auto [row, col, d] = q.front();
            q.pop();

            for (int i = 0; i < 4; i++) {
                int nRow = row + delta[i];
                int nCol = col + delta[(i + 1) % 4];

                if (nRow >= 0 && nRow < n && nCol >= 0 && nCol < m && grid[nRow][nCol] == 1) {
                    if (d + 1 < dist[nRow][nCol]) {
                        if (nRow == dest[0] && nCol == dest[1]) {
                            return d + 1;
                        }
                        dist[nRow][nCol] = d + 1;
                        q.push({nRow, nCol, d + 1});

                    }
                }
            }
        }
        return -1;
    }
};
