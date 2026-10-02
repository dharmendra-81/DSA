class DisjointSet {
    vector<int> parent, rank;
public:
    DisjointSet(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for(int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int find(int u) {
        if(parent[u] != u) {
            parent[u] = find(parent[u]); 
        }
        return parent[u];
    }

    void unionByRank(int u, int v) {
        int rootU = find(u);
        int rootV = find(v);
        if(rootU != rootV) {
            if(rank[rootU] < rank[rootV]) {
                parent[rootU] = rootV;
            } else if(rank[rootU] > rank[rootV]) {
                parent[rootV] = rootU;
            } else {
                parent[rootV] = rootU;
                rank[rootU]++;
            }
        }
    }
};

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        unordered_map<string, int> mp;
        DisjointSet ds(n);

        // 1) Build DSU connections based on common emails
        for(int i = 0; i < n; i++){
            for(int j = 1; j < (int)accounts[i].size(); j++){
                string &mail = accounts[i][j];
                if(!mp.contains(mail)){
                    mp[mail] = i;
                }
                else{
                    ds.unionByRank(i, mp[mail]);
                }
            }
        }

        // 2) Collect emails by their ultimate parent
        vector<vector<string>> emailsOfParent(n);
        for(auto &it: mp){
            const string &mail = it.first;
            int ind = it.second;
            int parent = ds.find(ind);
            emailsOfParent[parent].push_back(mail);
        }

        // 3) Build the result
        vector<vector<string>> ans;
        for(int i = 0; i < n; i++){
            if(emailsOfParent[i].empty()) continue;
            sort(emailsOfParent[i].begin(), emailsOfParent[i].end());

            vector<string> merged;
            merged.push_back(accounts[i][0]);
            for(auto it: emailsOfParent[i]){
               merged.push_back(it); 
            }
            ans.push_back(merged);
        }
        return ans;
    }
};