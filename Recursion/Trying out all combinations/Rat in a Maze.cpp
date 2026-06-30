class Solution {
    void solve(int i, int j, vector<vector<int>>& maze, string &path, vector<string> &ans){
        int n = maze.size();
        if(i<0 || j<0 || i>=n || j>=n || maze[i][j]==0){
            return;
        }
        if(i==n-1 && j==n-1){
            ans.push_back(path);
            return;
        }
        
        maze[i][j]=0;
        
        path.push_back('D');
        solve(i+1, j, maze, path, ans);
        path.pop_back();
        path.push_back('L');
        solve(i, j-1, maze, path, ans);
        path.pop_back();
        path.push_back('R');
        solve(i, j+1, maze, path, ans);
        path.pop_back();
        path.push_back('U');
        solve(i-1, j, maze, path, ans);
        path.pop_back();
        
        maze[i][j]=1;
    }
  public:
    vector<string> ratInMaze(vector<vector<int>>& maze) {
        // code here
        if(maze[0][0] == 0) return {};
        vector<string> ans;
        string path = "";
        solve(0, 0, maze, path, ans);
        return ans;
    }
};