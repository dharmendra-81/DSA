/*
Dijkstra's Algorithm is a popular algorithm used to find the shortest path from a source node to all other nodes in a weighted graph. 
It works for graphs with non-negative weights and can be implemented using different data structures.
Time Complexity:
1. Using a Min-Heap (Priority Queue): O((V + E) log V)
   - V is the number of vertices and E is the number of edges in the graph.
2. Using a Set (Balanced BST): O((V + E) log V)
Space Complexity: O(V + E) for the adjacency list, O(V) for the distance array, and O(V) for the priority queue or set.
*/

// Using Priority Queue(min heap) 
class Solution {
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        // Create adjacency list with weights for undirected graph
        vector<vector<pair<int, int>>> adj(V);
        for(auto &edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];
            adj[u].push_back({v, wt});
            adj[v].push_back({u, wt});
        }
        
        vector<int> dist(V, INT_MAX);
        dist[src] = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, src});
        
        while(!pq.empty()){
            auto [d, node] = pq.top(); pq.pop();
            
            if (d > dist[node]) continue;
            
            for(auto &it: adj[node]){
                auto [adjNode, w] = it;
                
                if(d + w < dist[adjNode]){
                    dist[adjNode] = d + w;
                    pq.push({dist[adjNode], adjNode});
                }
            }
        }
        return dist;
    }
};

// Using Set (Balanced BST)
class Solution {
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        vector<vector<pair<int, int>>> adj(V);
        for(auto &edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];
            adj[u].push_back({v, wt});
            adj[v].push_back({u, wt});
        }
        
        vector<int> dist(V, INT_MAX);
        dist[src] = 0;
        set<pair<int, int>> s;
        s.insert({0, src});
        
        while(!s.empty()){
            auto [d, node] = *(s.begin());
            s.erase(*(s.begin()));
            
            if (d > dist[node]) continue;
            
            for(auto &it: adj[node]){
                auto [adjNode, w] = it;
                
                if(d + w < dist[adjNode]){
                    // If the distance to adjNode is already in the set, remove it
                    if(dist[adjNode] != INT_MAX){
                        s.erase({dist[adjNode], adjNode});
                    }

                    dist[adjNode] = d + w;
                    s.insert({dist[adjNode], adjNode});
                }
            }
        }
        return dist;
    }
};
