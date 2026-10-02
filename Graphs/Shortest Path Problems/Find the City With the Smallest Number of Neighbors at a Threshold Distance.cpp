// Using Floyd Warshall Algorithm
class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));

        for(int i = 0; i < n; i++) {
            dist[i][i] = 0;
        }

        for(auto it : edges) {
            int u = it[0];
            int v = it[1];
            int wt = it[2];

            dist[u][v] = wt;
            dist[v][u] = wt;
        }

        for(int k = 0; k < n; k++) {
            for(int i = 0; i < n; i++) {
                for(int j = 0; j < n; j++) {
                    if(dist[i][k] != INT_MAX && dist[k][j] != INT_MAX) {
                        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                    }
                }
            }
        }

        int cntCity = n;
        int cityNo = -1;

        for(int city = 0; city < n; city++){
            int cnt = 0;
            for(int adjCity = 0;adjCity < n; adjCity++){
                if(dist[city][adjCity] <= distanceThreshold){
                    cnt++;
                }
            }

            if(cnt <= cntCity){
                cntCity = cnt;
                cityNo = city;
            }
        }
        return cityNo;
    }
};

// Using Dijkstra's Algorithm
class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<int> num(n, 0); //number of cities reachable from city i within the distance threshold

        vector<vector<pair<int, int>>> adj(n);
        for(auto &edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];
            adj[u].push_back({v, wt});
            adj[v].push_back({u, wt});
        }

        for(int i = 0; i < n; i++){
            priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
            vector<int> dist(n, INT_MAX);
            dist[i] = 0;
            pq.push({0, i});
        
            while(!pq.empty()){
                auto [d, node] = pq.top(); pq.pop();
                
                if(d > dist[node]) continue;
                if (d >=  distanceThreshold) continue;
                
                for(auto &[adjNode, w]: adj[node]){
                    if(d + w < dist[adjNode]){
                        dist[adjNode] = d + w;
                        pq.push({dist[adjNode], adjNode});
                    }
                }
            }

            int cnt = 0;
            for(int j = 0; j < n; j++){
                if(dist[j] <= distanceThreshold) cnt++;
            }
            num[i] = cnt;
        }

        int mini = *min_element(num.begin(), num.end());
        for(int i = n-1; i >= 0; i--){
            if(num[i] == mini) return i;
        }
        return -1;
    }
};