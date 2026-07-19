class Solution {
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        int maxArea = 0;

        for(int i = 0; i < heights.size(); i++){
            while(!st.empty() && heights[i] < heights[st.top()]){
                int bar = heights[st.top()];
                st.pop();
                int nse = i;
                int pse = st.empty() ? -1 : st.top();
                int area = bar * (nse - pse - 1);
                maxArea = max(maxArea, area);
            }

            st.push(i);
        }

        while(!st.empty()){
            int nse = heights.size();
            int bar = heights[st.top()];
            st.pop();
            int pse = st.empty() ? -1 : st.top();
            int area = bar * (nse - pse - 1);
            maxArea = max(maxArea, area);
        }

        return maxArea;
    }

public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int maxArea = 0;
        vector<int> heights(matrix[0].size(), 0);

        for(int i = 0; i < matrix.size(); i++){
            for(int j = 0; j < matrix[0].size(); j++){
                if(matrix[i][j] == '1'){
                    heights[j]++;
                }
                else{
                    heights[j] = 0;
                }
            }

            int area = largestRectangleArea(heights);
            maxArea = max(maxArea, area);
        }

        return maxArea;
    }
};

// Time : O(N*M) & Space: O(M)