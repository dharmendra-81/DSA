class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();

        //{difference, row, col}
        priority_queue< tuple<int, int, int>, 
        vector<tuple<int, int, int>>, 
        greater<tuple<int, int, int>>> pq;
        pq.push({0, 0, 0});

        vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
        dist[0][0] = 0;

        vector<int> delta = {-1, 0, 1, 0};

        while (!pq.empty()) {
            auto [diff, row, col] = pq.top();
            pq.pop();

            if(row == n-1 && col == m-1) return diff;

            for (int i = 0; i < 4; i++) {
                int nRow = row + delta[i];
                int nCol = col + delta[(i + 1) % 4];

                if (nRow >= 0 && nRow < n && nCol >= 0 && nCol < m) {
                    int newEffort = max(abs(heights[row][col] - heights[nRow][nCol]), diff);
                    if(newEffort < dist[nRow][nCol]){
                        dist[nRow][nCol] = newEffort;
                        pq.push({newEffort, nRow, nCol});
                    }
                }
            }
        }
        return 0;
    }
};