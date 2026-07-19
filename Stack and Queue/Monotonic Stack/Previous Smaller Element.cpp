class Solution {
  public:
    vector<int> prevSmaller(vector<int>& arr) {
        vector<int> pse(arr.size());
        stack<int> st;
        
        for(int i = 0; i < arr.size(); i++){
            while(!st.empty() && st.top() >= arr[i]){
                st.pop();
            }
            
            pse[i] = st.empty() ? -1 : st.top();
            st.push(arr[i]);
        }
        return pse;
    }
};