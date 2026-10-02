/*
Bellman-Ford Algorithm:
- It is used to find the shortest path from a single source vertex to all other vertices in a weighted graph.
- It can handle graphs with negative weight edges, unlike Dijkstra's algorithm.
- The algorithm works by relaxing all the edges V-1 times, where V is the number of vertices in the graph.
- After V-1 iterations, if we can still relax any edge, it indicates the presence of a negative weight cycle in the graph.
Time Complexity: O(V * E), where V is the number of vertices and E is the number of edges.
*/
class Solution {
  public:
    vector<int> bellmanFord(int V, vector<vector<int>>& edges, int src) {
        vector<int> dist(V, 1e8);
        dist[src] = 0;
        
        // Relax all edges V-1 times
        for(int i = 0; i < V-1; i++){
            for(auto it: edges){
                int u = it[0];
                int v = it[1];
                int wt = it[2];
                
                if(dist[u] != 1e8 && dist[u] + wt < dist[v]){
                    dist[v] = dist[u] + wt;
                }
            }
        }
        
        // Check for negative weight cycle
        for(auto it: edges){
            int u = it[0];
            int v = it[1];
            int wt = it[2];
            
            if(dist[u] != 1e8 && dist[u] + wt < dist[v]){
               return {-1};
            }
        }
        return dist;
    }
};
