// Time: O(N*M) where N is the number of rows and M is the number of columns in the image
// Space: O(N*M) for the ans array and O(N*M) for the recursion
class Solution {
    void dfs(vector<vector<int>>& image, int row, int col, 
        vector<vector<int>>& ans, int initColor, int newColor){
        ans[row][col] = newColor;

        int n = image.size();
        int m = image[0].size();

        vector<int> delta = {-1, 0, 1, 0};

        for(int i = 0; i < 4; i++){
            int nRow = row + delta[i];
            int nCol = col + delta[(i + 1) % 4];

            if(nRow >= 0 && nRow < n && nCol >= 0 && nCol < m
            && image[nRow][nCol] == initColor && ans[nRow][nCol] != newColor){
                dfs(image, nRow, nCol, ans, initColor, newColor);
            }
        }
    }

public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int initColor = image[sr][sc];
        vector<vector<int>> ans = image;

        if (initColor == color) {
            return ans; 
        }

        dfs(image, sr, sc, ans, initColor, color);
        return ans;
    }
};