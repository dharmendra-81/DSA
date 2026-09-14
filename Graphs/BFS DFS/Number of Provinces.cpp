// Time: O(N^2) where N is the number of nodes in the graph
// Space: O(N) for the visited array and O(N) for the recursion stack in the worst case
class Solution {
    void dfs(int &node, vector<vector<int>>& adjMat, vector<bool> &vis){
        vis[node] = true;
        
        for(int nbr = 0; nbr < adjMat.size(); nbr++){
            if(adjMat[node][nbr] == 1 && !vis[nbr]){
                dfs(nbr, adjMat, vis);
            }
        }
    }

public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<bool> vis(n, false);
        int cnt = 0;

        for(int i = 0; i < n; i++){
            if(!vis[i]){
                cnt++;
                dfs(i, isConnected, vis);
            }
        }
        return cnt;
    }
};