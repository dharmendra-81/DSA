/*
Floyd-Warshall Algorithm:
- It is used to find the shortest paths between all pairs of vertices in a weighted graph.
- It can handle graphs with negative weight edges, but it cannot handle graphs with negative weight cycles.
- The algorithm works by considering all pairs of vertices and iteratively improving the shortest path between them by considering intermediate vertices.
- The algorithm uses a dynamic programming approach to build the solution.
Time Complexity: O(V^3), where V is the number of vertices in the graph.
*/
class Solution {
  public:
    void floydWarshall(vector<vector<int>> &dist) {
        int n = dist.size();
        const int INF = 1e8;

        // Convert -1 to infinity
        // for(int i = 0; i < n; i++) {
        //     for(int j = 0; j < n; j++) {
        //         if(i == j)
        //             dist[i][j] = 0;
        //         else if(dist[i][j] == -1)
        //             dist[i][j] = INF;
        //     }
        // }

        // Floyd-Warshall
        for(int k = 0; k < n; k++) {
            for(int i = 0; i < n; i++) {
                for(int j = 0; j < n; j++) {
                    if(dist[i][k] != INF && dist[k][j] != INF) {
                        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                    }
                }
            }
        }

        // Convert infinity back to -1
        // for(int i = 0; i < n; i++) {
        //     for(int j = 0; j < n; j++) {
        //         if(dist[i][j] == INF)
        //             dist[i][j] = -1;
        //     }
        // }
        
    }
};