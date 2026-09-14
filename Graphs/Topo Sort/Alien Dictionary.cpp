class Solution {
    vector<int> topoSort(int V, vector<vector<int>>& adj) {    
        vector<int> indegree(V, 0);
        for(int i = 0; i < V; i++){
            for(auto it: adj[i]){
                indegree[it]++;
            }
        }

        queue<int> q;
        for(int i = 0; i < V; i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }

        vector<int> topo;
        while(!q.empty()){
            int node = q.front(); q.pop();
            topo.push_back(node);

            for(auto it: adj[node]){
                indegree[it]--;
                if(indegree[it] == 0) q.push(it);
            }
        }

        return topo;
    }
    
  public:
    string findOrder(vector<string> &words) {
        int V = 26;
        int n = words.size();
        
        vector<vector<int>> adj(V);
        for(int i = 0; i < n-1; i++){
            string s1 = words[i];
            string s2 = words[i+1];
            int len = min(s1.size(), s2.size());
            bool isPrefix = true;
            
            for(int j = 0; j < len; j++){
                if(s1[j] != s2[j]){
                    adj[s1[j] - 'a'].push_back(s2[j]-'a');
                    isPrefix = false;
                    break;
                }
            }
            
            if (isPrefix && s1.size() > s2.size()) {
                return ""; // Invalid order
            }
        }
        
        vector<int> topo = topoSort(V, adj);
        string ans;
        for(auto it: topo){
            ans.push_back(char(it + 'a'));
        }
        return ans;
    }
    
};