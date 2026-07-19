/*
Intuition:
-> For each bar, we need to find the left and right boundaries where the bars are smaller than the current bar.
-> We can use a stack to keep track of the indices of the bars in increasing order of their heights.
-> When we encounter a bar with a smaller height, we can pop the stack and calculate the area for the popped bar.
-> Formula: area = element x (NSE index - PSE index - 1)
*/

class Solution {
public:
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
};

// Time : O(N) & Space: O(N)